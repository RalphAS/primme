/*******************************************************************************
 * Copyright (c) 2017, College of William & Mary
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the College of William & Mary nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COLLEGE OF WILLIAM & MARY BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * PRIMME: https://github.com/primme/primme
 * Contact: Andreas Stathopoulos, a n d r e a s _at_ c s . w m . e d u
 *******************************************************************************
 * File: magma_wrapper.c
 *
 * Purpose - This file contains mostly C wrapper routines for
 *           calling MAGMA functions
 *
 ******************************************************************************/

#include <stdlib.h>   /* free */
#include <string.h>   /* memmove */
#include <assert.h>
#include <math.h>
#include "template.h"
#include "blaslapack.h"
#include "auxiliary.h"
#include "magma_wrapper.h"

#ifdef USE_MAGMA

#if defined(MAGMA_ILP64) || defined(MKL_ILP64)
#  include <stdint.h>
#  include <inttypes.h>
#  define MAGMA_INT_MAX INT64_MAX
#else
#  include <limits.h>
#  define MAGMA_INT_MAX INT_MAX
#endif


#ifdef USE_DOUBLE_MAGMA
#  define MAGMA_FUNCTION(S,C,D,Z) CONCAT(magma_,D)
#elif defined(USE_DOUBLECOMPLEX_MAGMA)
#  define MAGMA_FUNCTION(S,C,D,Z) CONCAT(magma_,Z)
#elif defined(USE_FLOAT_MAGMA)
#  define MAGMA_FUNCTION(S,C,D,Z) CONCAT(magma_,S)
#elif defined(USE_FLOATCOMPLEX_MAGMA)
#  define MAGMA_FUNCTION(S,C,D,Z) CONCAT(magma_,C)
#endif

#define XMALLOC   MAGMA_FUNCTION(smalloc, cmalloc, dmalloc, zmalloc)
#define XSETVECTOR MAGMA_FUNCTION(ssetvector, csetvector, dsetvector, zsetvector)
#define XGETVECTOR MAGMA_FUNCTION(sgetvector, cgetvector, dgetvector, zgetvector)
#define XSETMATRIX MAGMA_FUNCTION(ssetmatrix, csetmatrix, dsetmatrix, zsetmatrix)
#define XCOPYMATRIX MAGMA_FUNCTION(scopymatrix, ccopymatrix, dcopymatrix, zcopymatrix)

#define XCOPY     MAGMA_FUNCTION(scopy , ccopy , dcopy , zcopy )   
#define XGEMM     MAGMA_FUNCTION(sgemm , cgemm , dgemm , zgemm )
#define XGEMV     MAGMA_FUNCTION(sgemv , cgemv , dgemv , zgemv )
#define XAXPY     MAGMA_FUNCTION(saxpy , caxpy , daxpy , zaxpy )
#define XDOT      MAGMA_FUNCTION(sdot  , cdotc , ddot  , zdotc )
#define XSCAL     MAGMA_FUNCTION(sscal , cscal , dscal , zscal )

// TEMP!!!!!
#define PRIMME_BLASINT magma_int_t
#define PRIMME_BLASINT_MAX MAGMA_INT_MAX

/******************************************************************************
 * Function Num_malloc - Allocate a vector of scalars
 *
 * PARAMETERS
 * ---------------------------
 * n           The number of elements
 * v           returned pointer
 * 
 ******************************************************************************/

TEMPLATE_PLEASE
int Num_malloc_Sprimme(PRIMME_INT n, SCALAR **x, primme_context ctx) {
   (void)ctx;

   if (n <= 0) {
      *x = NULL;
      return 0;
   }
   return XMALLOC((MAGMA_SCALAR **)x, n) == MAGMA_SUCCESS
              ? 0
              : PRIMME_MALLOC_FAILURE;
}

/******************************************************************************
 * Function Num_free - Free allocated a vector of scalars
 *
 * PARAMETERS
 * ---------------------------
 * v           allocated pointer
 * 
 ******************************************************************************/

TEMPLATE_PLEASE
int Num_free_Sprimme(SCALAR *x, primme_context ctx) {

   return magma_free(x) == MAGMA_SUCCESS ? 0 : PRIMME_MALLOC_FAILURE;
}

/*******************************************************************************
 * Subroutine Num_copy_Sprimme - y(0:n*incy-1:incy) = x(0:n*incx-1:incx)
 ******************************************************************************/
 
TEMPLATE_PLEASE
void Num_copy_Sprimme(PRIMME_INT n, SCALAR *x, int incx, SCALAR *y, int incy,
                      primme_context ctx) {

  PRIMME_BLASINT ln = n;
  PRIMME_BLASINT lincx = incx;
  PRIMME_BLASINT lincy = incy;

  while (n > 0) {
    ln = (PRIMME_BLASINT)min(n, PRIMME_BLASINT_MAX - 1);
    XCOPY(ln, (MAGMA_SCALAR *)x, lincx, (MAGMA_SCALAR *)y, lincy,
          *(magma_queue_t *)ctx.queue);
    n -= (PRIMME_INT)ln;
    x += ln;
    y += ln;
  }
}

/*******************************************************************************
 * Subroutine Num_gemm_Sprimme - C = op(A)*op(B), with C size m x n
 * NOTE: A, B and C are in device
 ******************************************************************************/

TEMPLATE_PLEASE
void Num_gemm_Sprimme(const char *transa, const char *transb, int m, int n,
      int k, SCALAR alpha, SCALAR *a, int lda, SCALAR *b, int ldb, SCALAR beta,
      SCALAR *c, int ldc, primme_context ctx) {

   PRIMME_BLASINT lm = m;
   PRIMME_BLASINT ln = n;
   PRIMME_BLASINT lk = k;
   PRIMME_BLASINT llda = lda;
   PRIMME_BLASINT lldb = ldb;
   PRIMME_BLASINT lldc = ldc;

   /* Zero dimension matrix may cause problems */
   if (m == 0 || n == 0) return;

   /* Quick exit */
   if (k == 0) {
      if (ABS(beta) == 0.0) {
         Num_zero_matrix_Sprimme(c, m, n, ldc, ctx);
      }
      else {
         int i;
         for (i=0; i<n; i++) {
            Num_scal_Sprimme(m, beta, &c[ldc*i], 1, ctx);
         }
      }
      return;
   }
   if (n == 1) {
      PRIMME_INT mA; int nA;
      if (*transa == 'n' || *transa == 'N') mA = m, nA = k;
      else mA = k, nA = m;
      int incb = ((*transb == 'n' || *transb == 'N') ? 1 : ldb);
      Num_gemv_Sprimme(transa, mA, nA, alpha, a, lda, b, incb, beta, c, 1, ctx);
      return;
   }

   XGEMM(magma_trans_cont(*transa), magma_trans_const(*transb), lm, ln, lk,
         *(MAGMA_SCALAR *)&alpha, (MAGMA_SCALAR *)a, llda, (MAGMA_SCALAR *)b,
         lldb, *(MAGMA_SCALAR *)&beta, (MAGMA_SCALAR *)c, lldc,
         *(magma_queue_t *)ctx.queue);
}


/*******************************************************************************
 * Subroutine Num_gemm_dhd_Sprimme - C = op(A)*op(B), with C size m x n
 * NOTE: A and C are hosted on device and B is hosted on cpu
 ******************************************************************************/

TEMPLATE_PLEASE
void Num_gemm_dhd_Sprimme(const char *transa, const char *transb, int m, int n,
      int k, SCALAR alpha, SCALAR *a, int lda, SCALAR *b, int ldb, SCALAR beta,
      SCALAR *c, int ldc, primme_context ctx) {

   int mb = *transb == 'N' ? k : n;
   int nb = *transb == 'N' ? n : k;

   SCALAR *b_dev; /* copy of b on device */
   Num_malloc_Sprimme(mb*nb, &b_dev, ctx);
   XSETMATRIX(mb, nb, b, ldb, b_dev, nb, *(magma_queue_t *)ctx.queue);
   Num_gemm_Sprimme(transa, transb, m, n, k, alpha, a, lda, b_dev, nb, beta, c,
                    ldc, ctx);
   Num_free_Sprimme(b_dev, ctx);
}

/*******************************************************************************
 * Subroutine Num_gemv_Sprimme - y = alpha*A*x + beta*y, with A size m x n
 * NOTE: A, x and y are in device
 ******************************************************************************/

TEMPLATE_PLEASE
void Num_gemv_Sprimme(const char *transa, PRIMME_INT m, int n, SCALAR alpha,
      SCALAR *a, int lda, SCALAR *x, int incx, SCALAR beta, SCALAR *y,
      int incy, primme_context ctx) {

   PRIMME_BLASINT lm = m;
   PRIMME_BLASINT ln = n;
   PRIMME_BLASINT llda = lda;
   PRIMME_BLASINT lincx = incx;
   PRIMME_BLASINT lincy = incy;

   /* Zero dimension matrix may cause problems */
   if (n == 0) return;

   /* Quick exit */
   if (m == 0) {
      if (ABS(beta) == 0.0) {
         Num_zero_matrix_Sprimme(y, 1, n, incy, ctx);
      }
      else {
         int i;
         for (i=0; i<n; i++) {
            Num_scal_Sprimme(n, beta, y, incy, ctx);
         }
      }
      return;
   }

   while(m > 0) {
      lm = (PRIMME_BLASINT)min(m, PRIMME_BLASINT_MAX-1);
      XGEMV(magma_trans_const(*transa), lm, ln, *(MAGMA_SCALAR *)&alpha,
            (MAGMA_SCALAR *)a, llda, (MAGMA_SCALAR *)x, lincx,
            *(MAGMA_SCALAR *)&beta, (MAGMA_SCALAR *)y, lincy,
            *(magma_queue_t *)ctx.queue);
      m -= (PRIMME_INT)lm;
      a += lm;
      if (transa[0] == 'n' || transa[0] == 'N') {
         y += lm;
      }
      else {
         x += lm;
         beta = 1.0;
      }
   }
}

/*******************************************************************************
 * Subroutine Num_gemv_ddh_Sprimme - y = alpha*A*x + beta*y, with A size m x n
 * NOTE: A and x are in device and y is in host
 ******************************************************************************/

TEMPLATE_PLEASE
void Num_gemv_ddh_Sprimme(const char *transa, PRIMME_INT m, int n, SCALAR alpha,
      SCALAR *a, int lda, SCALAR *x, int incx, SCALAR beta, SCALAR *y,
      int incy, primme_context ctx) {

   int my = *transa == 'N' ? m : n;

   SCALAR *y_dev; /* copy of y on device */
   Num_malloc_Sprimme(my, &y_dev, ctx);
   if (ABS(beta) != 0)
     XSETVECTOR(my, y, incy, y_dev, 1, *(magma_queue_t *)ctx.queue);
   Num_gemv_Sprimme(transa, m, n, alpha, a, lda, x, incx, beta, y_dev, 1, ctx);
   XGETVECTOR(ny, y_dev, 1, y, incy, *(magma_queue_t *)ctx.queue);
}

/*******************************************************************************
 * Subroutine Num_gemv_dhd_Sprimme - y = alpha*A*x + beta*y, with A size m x n
 * NOTE: A and y are in device and x is in host
 ******************************************************************************/

TEMPLATE_PLEASE
void Num_gemv_dhd_Sprimme(const char *transa, PRIMME_INT m, int n, SCALAR alpha,
      SCALAR *a, int lda, SCALAR *x, int incx, SCALAR beta, SCALAR *y,
      int incy, primme_context ctx) {

   int mx = *transa == 'N' ? n : m;

   SCALAR *x_dev; /* copy of x on device */
   Num_malloc_Sprimme(mx, &x_dev, ctx);
   XSETVECTOR(mx, x, incx, x_dev, 1, *(magma_queue_t *)ctx.queue);
   Num_gemv_Sprimme(transa, m, n, alpha, a, lda, x_dev, 1, beta, y, incy, ctx);
}

/*******************************************************************************
 * Subroutine Num_axpy_Sprimme - y += alpha*x
 ******************************************************************************/

TEMPLATE_PLEASE
void Num_axpy_Sprimme(PRIMME_INT n, SCALAR alpha, SCALAR *x, int incx, 
   SCALAR *y, int incy, primme_context ctx) {

   PRIMME_BLASINT ln = n;
   PRIMME_BLASINT lincx = incx;
   PRIMME_BLASINT lincy = incy;

   while(n > 0) {
      ln = (PRIMME_BLASINT)min(n, PRIMME_BLASINT_MAX-1);
      XAXPY(ln, *(MAGMA_SCALAR *)&alpha, (MAGMA_SCALAR *)x, lincx,
            (MAGMA_SCALAR *)y, lincy, *(magma_queue_t *)ctx.queue);
      n -= (PRIMME_INT)ln;
      x += ln;
      y += ln;
   }
}

/*******************************************************************************
 * Subroutine Num_dot_Sprimme - y'*x
 ******************************************************************************/

TEMPLATE_PLEASE
SCALAR Num_dot_Sprimme(PRIMME_INT n, SCALAR *x, int incx, SCALAR *y, int incy,
                       primme_context ctx) {

  PRIMME_BLASINT ln = n;
  PRIMME_BLASINT lincx = incx;
  PRIMME_BLASINT lincy = incy;
  SCALAR r = 0.0;

  while (n > 0) {
    ln = (PRIMME_BLASINT)min(n, PRIMME_BLASINT_MAX - 1);
    MAGMA_SCALAR r0 = XDOT(ln, (MAGMA_SCALAR *)x, lincx, (MAGMA_SCALAR *)y,
                           lincy, *(magma_queue_t *)ctx.queue);
    r += *(SCALAR *)&r0;
    n -= (PRIMME_INT)ln;
    x += ln;
    y += ln;
  }

  return r;
}

/*******************************************************************************
 * Subroutine Num_scal_Sprimme - x(0:n*incx-1:incx) *= alpha
 ******************************************************************************/
 
TEMPLATE_PLEASE
void Num_scal_Sprimme(PRIMME_INT n, SCALAR alpha, SCALAR *x, int incx,
                      primme_context ctx) {

  PRIMME_BLASINT ln = n;
  PRIMME_BLASINT lincx = incx;

  while (n > 0) {
    ln = (PRIMME_BLASINT)min(n, PRIMME_BLASINT_MAX - 1);
    XSCAL(ln, *(MAGMA_SCALAR *)&alpha, (MAGMA_SCALAR *)x, lincx,
          *(magma_queue_t *)ctx.queue);
    n -= (PRIMME_INT)ln;
    x += ln;
  }
}

/*******************************************************************************
 * Subroutine Num_larnv_Sprimme - x(0:n*incy-1:incy) = rand(0:n-1)
 ******************************************************************************/

TEMPLATE_PLEASE
int Num_larnv_Sprimme(int idist, PRIMME_INT *iseed, PRIMME_INT length,
      SCALAR *x, primme_context ctx) {

   SCALAR *x_host;
   CHKERR(Num_malloc_RHSprimme(length, &x_host));
   CHKERR(Num_larnv_Sprimme(idist, iseed, length, x_host, ctx));
   magma_setvector(length, sizeof(SCALAR), x_host, 1, x, 1,
                   *(magma_queue_t *)ctx.queue);
   CHKERR(Num_free_RHSprimme(x_host));
}

/******************************************************************************
 * Function Num_copy_matrix - Copy the matrix x into y
 *
 * PARAMETERS
 * ---------------------------
 * x           The source matrix
 * m           The number of rows of x
 * n           The number of columns of x
 * ldx         The leading dimension of x
 * y           On output y = x
 * ldy         The leading dimension of y
 *
 * NOTE: x and y *can* overlap
 *
 ******************************************************************************/

TEMPLATE_PLEASE
void Num_copy_matrix_Sprimme(SCALAR *x, PRIMME_INT m, PRIMME_INT n,
                             PRIMME_INT ldx, SCALAR *y, PRIMME_INT ldy,
                             primme_context ctx) {

  PRIMME_INT i, j;

  assert(m == 0 || n == 0 || (ldx >= m && ldy >= m));

  /* Do nothing if x and y are the same matrix */
  if (x == y && ldx == ldy)
    return;

   XCOPYMATRIX(m, n, (MAGMA_SCALAR*)x, ldx, (MAGMA_SCALAR*)y, ldy, *(magma_queue_t *)ctx.queue);
}

/******************************************************************************
 * Function Num_zero_matrix - Zero the matrix
 *
 * PARAMETERS
 * ---------------------------
 * x           The matrix
 * m           The number of rows of x
 * n           The number of columns of x
 * ldx         The leading dimension of x
 *
 ******************************************************************************/

TEMPLATE_PLEASE
void Num_zero_matrix_Sprimme(SCALAR *x, PRIMME_INT m, PRIMME_INT n,
      PRIMME_INT ldx, primme_context ctx) {
  (void)ctx;

   PRIMME_INT i,j;

   for (i=0; i<n; i++) {
      Num_scal_Sprimme(m, 0.0, &x[i*ldx], 1, ctx);
   }
} 

#endif /* USE_MAGMA */
