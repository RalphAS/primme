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
 *   NOTE: THIS FILE IS AUTOMATICALLY GENERATED. PLEASE DON'T MODIFY
 ******************************************************************************/


#ifndef blaslapack_H
#define blaslapack_H
void Num_copy_sprimme(PRIMME_INT n, float *x, int incx, float *y, int incy,
                      primme_context ctx);
void Num_gemm_sprimme(const char *transa, const char *transb, int m, int n,
      int k, float alpha, float *a, int lda, float *b, int ldb, float beta,
      float *c, int ldc, primme_context ctx);
void Num_gemm_dhd_sprimme(const char *transa, const char *transb, int m, int n,
      int k, float alpha, float *a, int lda, float *b, int ldb, float beta,
      float *c, int ldc, primme_context ctx);
void Num_hemm_sprimme(const char *side, const char *uplo, int m, int n,
      float alpha, float *a, int lda, float *b, int ldb, float beta,
      float *c, int ldc);
void Num_trmm_sprimme(const char *side, const char *uplo,
      const char *transa, const char *diag, int m, int n, float alpha,
      float *a, int lda, float *b, int ldb, primme_context ctx);
void Num_gemv_sprimme(const char *transa, PRIMME_INT m, int n, float alpha,
      float *a, int lda, float *x, int incx, float beta, float *y,
      int incy, primme_context ctx);
void Num_gemv_ddh_sprimme(const char *transa, PRIMME_INT m, int n, float alpha,
      float *a, int lda, float *x, int incx, float beta, float *y,
      int incy, primme_context ctx);
void Num_gemv_dhd_sprimme(const char *transa, PRIMME_INT m, int n, float alpha,
      float *a, int lda, float *x, int incx, float beta, float *y,
      int incy, primme_context ctx);
void Num_hemv_sprimme(const char *uplo, int n, float alpha,
   float *a, int lda, float *x, int incx, float beta,
   float *y, int incy);
void Num_axpy_sprimme(PRIMME_INT n, float alpha, float *x, int incx,
   float *y, int incy, primme_context ctx);
float Num_dot_sprimme(PRIMME_INT n, float *x, int incx, float *y, int incy,
                       primme_context ctx);
void Num_larnv_sprimme(int idist, PRIMME_INT *iseed, PRIMME_INT length,
      float *x, primme_context ctx);
void Num_scal_sprimme(PRIMME_INT n, float alpha, float *x, int incx, primme_context ctx);
void Num_swap_sprimme(PRIMME_INT n, float *x, int incx, float *y, int incy, primme_context ctx);
int Num_heev_sprimme(const char *jobz, const char *uplo, int n, float *a,
      int lda, float *w, primme_context ctx);
int Num_hegv_sprimme(const char *jobz, const char *uplo, int n, float *a,
      int lda, float *b0, int ldb0, float *w, primme_context ctx);
int Num_gesvd_sprimme(const char *jobu, const char *jobvt, int m, int n,
      float *a, int lda, float *s, float *u, int ldu, float *vt, int ldvt,
      primme_context ctx);
void Num_hetrf_sprimme(const char *uplo, int n, float *a, int lda, int *ipivot,
   float *work, int ldwork, int *info);
void Num_hetrs_sprimme(const char *uplo, int n, int nrhs, float *a,
      int lda, int *ipivot, float *b, int ldb, int *info);
void Num_trsm_sprimme(const char *side, const char *uplo, const char *transa,
      const char *diag, int m, int n, float alpha, float *a, int lda,
      float *b, int ldb);
void Num_copy_cprimme(PRIMME_INT n, PRIMME_COMPLEX_FLOAT *x, int incx, PRIMME_COMPLEX_FLOAT *y, int incy,
                      primme_context ctx);
void Num_gemm_cprimme(const char *transa, const char *transb, int m, int n,
      int k, PRIMME_COMPLEX_FLOAT alpha, PRIMME_COMPLEX_FLOAT *a, int lda, PRIMME_COMPLEX_FLOAT *b, int ldb, PRIMME_COMPLEX_FLOAT beta,
      PRIMME_COMPLEX_FLOAT *c, int ldc, primme_context ctx);
void Num_gemm_dhd_cprimme(const char *transa, const char *transb, int m, int n,
      int k, PRIMME_COMPLEX_FLOAT alpha, PRIMME_COMPLEX_FLOAT *a, int lda, PRIMME_COMPLEX_FLOAT *b, int ldb, PRIMME_COMPLEX_FLOAT beta,
      PRIMME_COMPLEX_FLOAT *c, int ldc, primme_context ctx);
void Num_hemm_cprimme(const char *side, const char *uplo, int m, int n,
      PRIMME_COMPLEX_FLOAT alpha, PRIMME_COMPLEX_FLOAT *a, int lda, PRIMME_COMPLEX_FLOAT *b, int ldb, PRIMME_COMPLEX_FLOAT beta,
      PRIMME_COMPLEX_FLOAT *c, int ldc);
void Num_trmm_cprimme(const char *side, const char *uplo,
      const char *transa, const char *diag, int m, int n, PRIMME_COMPLEX_FLOAT alpha,
      PRIMME_COMPLEX_FLOAT *a, int lda, PRIMME_COMPLEX_FLOAT *b, int ldb, primme_context ctx);
void Num_gemv_cprimme(const char *transa, PRIMME_INT m, int n, PRIMME_COMPLEX_FLOAT alpha,
      PRIMME_COMPLEX_FLOAT *a, int lda, PRIMME_COMPLEX_FLOAT *x, int incx, PRIMME_COMPLEX_FLOAT beta, PRIMME_COMPLEX_FLOAT *y,
      int incy, primme_context ctx);
void Num_gemv_ddh_cprimme(const char *transa, PRIMME_INT m, int n, PRIMME_COMPLEX_FLOAT alpha,
      PRIMME_COMPLEX_FLOAT *a, int lda, PRIMME_COMPLEX_FLOAT *x, int incx, PRIMME_COMPLEX_FLOAT beta, PRIMME_COMPLEX_FLOAT *y,
      int incy, primme_context ctx);
void Num_gemv_dhd_cprimme(const char *transa, PRIMME_INT m, int n, PRIMME_COMPLEX_FLOAT alpha,
      PRIMME_COMPLEX_FLOAT *a, int lda, PRIMME_COMPLEX_FLOAT *x, int incx, PRIMME_COMPLEX_FLOAT beta, PRIMME_COMPLEX_FLOAT *y,
      int incy, primme_context ctx);
void Num_hemv_cprimme(const char *uplo, int n, PRIMME_COMPLEX_FLOAT alpha,
   PRIMME_COMPLEX_FLOAT *a, int lda, PRIMME_COMPLEX_FLOAT *x, int incx, PRIMME_COMPLEX_FLOAT beta,
   PRIMME_COMPLEX_FLOAT *y, int incy);
void Num_axpy_cprimme(PRIMME_INT n, PRIMME_COMPLEX_FLOAT alpha, PRIMME_COMPLEX_FLOAT *x, int incx,
   PRIMME_COMPLEX_FLOAT *y, int incy, primme_context ctx);
PRIMME_COMPLEX_FLOAT Num_dot_cprimme(PRIMME_INT n, PRIMME_COMPLEX_FLOAT *x, int incx, PRIMME_COMPLEX_FLOAT *y, int incy,
                       primme_context ctx);
void Num_larnv_cprimme(int idist, PRIMME_INT *iseed, PRIMME_INT length,
      PRIMME_COMPLEX_FLOAT *x, primme_context ctx);
void Num_scal_cprimme(PRIMME_INT n, PRIMME_COMPLEX_FLOAT alpha, PRIMME_COMPLEX_FLOAT *x, int incx, primme_context ctx);
void Num_swap_cprimme(PRIMME_INT n, PRIMME_COMPLEX_FLOAT *x, int incx, PRIMME_COMPLEX_FLOAT *y, int incy, primme_context ctx);
int Num_heev_cprimme(const char *jobz, const char *uplo, int n, PRIMME_COMPLEX_FLOAT *a,
      int lda, float *w, primme_context ctx);
int Num_hegv_cprimme(const char *jobz, const char *uplo, int n, PRIMME_COMPLEX_FLOAT *a,
      int lda, PRIMME_COMPLEX_FLOAT *b0, int ldb0, float *w, primme_context ctx);
int Num_gesvd_cprimme(const char *jobu, const char *jobvt, int m, int n,
      PRIMME_COMPLEX_FLOAT *a, int lda, float *s, PRIMME_COMPLEX_FLOAT *u, int ldu, PRIMME_COMPLEX_FLOAT *vt, int ldvt,
      primme_context ctx);
void Num_hetrf_cprimme(const char *uplo, int n, PRIMME_COMPLEX_FLOAT *a, int lda, int *ipivot,
   PRIMME_COMPLEX_FLOAT *work, int ldwork, int *info);
void Num_hetrs_cprimme(const char *uplo, int n, int nrhs, PRIMME_COMPLEX_FLOAT *a,
      int lda, int *ipivot, PRIMME_COMPLEX_FLOAT *b, int ldb, int *info);
void Num_trsm_cprimme(const char *side, const char *uplo, const char *transa,
      const char *diag, int m, int n, PRIMME_COMPLEX_FLOAT alpha, PRIMME_COMPLEX_FLOAT *a, int lda,
      PRIMME_COMPLEX_FLOAT *b, int ldb);
#if !defined(CHECK_TEMPLATE) && !defined(Num_copy_Sprimme)
#  define Num_copy_Sprimme CONCAT(Num_copy_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_copy_Rprimme)
#  define Num_copy_Rprimme CONCAT(Num_copy_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_copy_SHprimme)
#  define Num_copy_SHprimme CONCAT(Num_copy_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_copy_RHprimme)
#  define Num_copy_RHprimme CONCAT(Num_copy_,HOST_REAL_SUF)
#endif
void Num_copy_dprimme(PRIMME_INT n, double *x, int incx, double *y, int incy,
                      primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemm_Sprimme)
#  define Num_gemm_Sprimme CONCAT(Num_gemm_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemm_Rprimme)
#  define Num_gemm_Rprimme CONCAT(Num_gemm_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemm_SHprimme)
#  define Num_gemm_SHprimme CONCAT(Num_gemm_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemm_RHprimme)
#  define Num_gemm_RHprimme CONCAT(Num_gemm_,HOST_REAL_SUF)
#endif
void Num_gemm_dprimme(const char *transa, const char *transb, int m, int n,
      int k, double alpha, double *a, int lda, double *b, int ldb, double beta,
      double *c, int ldc, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemm_dhd_Sprimme)
#  define Num_gemm_dhd_Sprimme CONCAT(Num_gemm_dhd_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemm_dhd_Rprimme)
#  define Num_gemm_dhd_Rprimme CONCAT(Num_gemm_dhd_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemm_dhd_SHprimme)
#  define Num_gemm_dhd_SHprimme CONCAT(Num_gemm_dhd_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemm_dhd_RHprimme)
#  define Num_gemm_dhd_RHprimme CONCAT(Num_gemm_dhd_,HOST_REAL_SUF)
#endif
void Num_gemm_dhd_dprimme(const char *transa, const char *transb, int m, int n,
      int k, double alpha, double *a, int lda, double *b, int ldb, double beta,
      double *c, int ldc, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_hemm_Sprimme)
#  define Num_hemm_Sprimme CONCAT(Num_hemm_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hemm_Rprimme)
#  define Num_hemm_Rprimme CONCAT(Num_hemm_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hemm_SHprimme)
#  define Num_hemm_SHprimme CONCAT(Num_hemm_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hemm_RHprimme)
#  define Num_hemm_RHprimme CONCAT(Num_hemm_,HOST_REAL_SUF)
#endif
void Num_hemm_dprimme(const char *side, const char *uplo, int m, int n,
      double alpha, double *a, int lda, double *b, int ldb, double beta,
      double *c, int ldc);
#if !defined(CHECK_TEMPLATE) && !defined(Num_trmm_Sprimme)
#  define Num_trmm_Sprimme CONCAT(Num_trmm_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_trmm_Rprimme)
#  define Num_trmm_Rprimme CONCAT(Num_trmm_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_trmm_SHprimme)
#  define Num_trmm_SHprimme CONCAT(Num_trmm_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_trmm_RHprimme)
#  define Num_trmm_RHprimme CONCAT(Num_trmm_,HOST_REAL_SUF)
#endif
void Num_trmm_dprimme(const char *side, const char *uplo,
      const char *transa, const char *diag, int m, int n, double alpha,
      double *a, int lda, double *b, int ldb, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_Sprimme)
#  define Num_gemv_Sprimme CONCAT(Num_gemv_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_Rprimme)
#  define Num_gemv_Rprimme CONCAT(Num_gemv_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_SHprimme)
#  define Num_gemv_SHprimme CONCAT(Num_gemv_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_RHprimme)
#  define Num_gemv_RHprimme CONCAT(Num_gemv_,HOST_REAL_SUF)
#endif
void Num_gemv_dprimme(const char *transa, PRIMME_INT m, int n, double alpha,
      double *a, int lda, double *x, int incx, double beta, double *y,
      int incy, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_ddh_Sprimme)
#  define Num_gemv_ddh_Sprimme CONCAT(Num_gemv_ddh_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_ddh_Rprimme)
#  define Num_gemv_ddh_Rprimme CONCAT(Num_gemv_ddh_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_ddh_SHprimme)
#  define Num_gemv_ddh_SHprimme CONCAT(Num_gemv_ddh_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_ddh_RHprimme)
#  define Num_gemv_ddh_RHprimme CONCAT(Num_gemv_ddh_,HOST_REAL_SUF)
#endif
void Num_gemv_ddh_dprimme(const char *transa, PRIMME_INT m, int n, double alpha,
      double *a, int lda, double *x, int incx, double beta, double *y,
      int incy, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_dhd_Sprimme)
#  define Num_gemv_dhd_Sprimme CONCAT(Num_gemv_dhd_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_dhd_Rprimme)
#  define Num_gemv_dhd_Rprimme CONCAT(Num_gemv_dhd_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_dhd_SHprimme)
#  define Num_gemv_dhd_SHprimme CONCAT(Num_gemv_dhd_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gemv_dhd_RHprimme)
#  define Num_gemv_dhd_RHprimme CONCAT(Num_gemv_dhd_,HOST_REAL_SUF)
#endif
void Num_gemv_dhd_dprimme(const char *transa, PRIMME_INT m, int n, double alpha,
      double *a, int lda, double *x, int incx, double beta, double *y,
      int incy, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_hemv_Sprimme)
#  define Num_hemv_Sprimme CONCAT(Num_hemv_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hemv_Rprimme)
#  define Num_hemv_Rprimme CONCAT(Num_hemv_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hemv_SHprimme)
#  define Num_hemv_SHprimme CONCAT(Num_hemv_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hemv_RHprimme)
#  define Num_hemv_RHprimme CONCAT(Num_hemv_,HOST_REAL_SUF)
#endif
void Num_hemv_dprimme(const char *uplo, int n, double alpha,
   double *a, int lda, double *x, int incx, double beta,
   double *y, int incy);
#if !defined(CHECK_TEMPLATE) && !defined(Num_axpy_Sprimme)
#  define Num_axpy_Sprimme CONCAT(Num_axpy_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_axpy_Rprimme)
#  define Num_axpy_Rprimme CONCAT(Num_axpy_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_axpy_SHprimme)
#  define Num_axpy_SHprimme CONCAT(Num_axpy_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_axpy_RHprimme)
#  define Num_axpy_RHprimme CONCAT(Num_axpy_,HOST_REAL_SUF)
#endif
void Num_axpy_dprimme(PRIMME_INT n, double alpha, double *x, int incx,
   double *y, int incy, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_dot_Sprimme)
#  define Num_dot_Sprimme CONCAT(Num_dot_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_dot_Rprimme)
#  define Num_dot_Rprimme CONCAT(Num_dot_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_dot_SHprimme)
#  define Num_dot_SHprimme CONCAT(Num_dot_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_dot_RHprimme)
#  define Num_dot_RHprimme CONCAT(Num_dot_,HOST_REAL_SUF)
#endif
double Num_dot_dprimme(PRIMME_INT n, double *x, int incx, double *y, int incy,
                       primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_larnv_Sprimme)
#  define Num_larnv_Sprimme CONCAT(Num_larnv_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_larnv_Rprimme)
#  define Num_larnv_Rprimme CONCAT(Num_larnv_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_larnv_SHprimme)
#  define Num_larnv_SHprimme CONCAT(Num_larnv_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_larnv_RHprimme)
#  define Num_larnv_RHprimme CONCAT(Num_larnv_,HOST_REAL_SUF)
#endif
void Num_larnv_dprimme(int idist, PRIMME_INT *iseed, PRIMME_INT length,
      double *x, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_scal_Sprimme)
#  define Num_scal_Sprimme CONCAT(Num_scal_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_scal_Rprimme)
#  define Num_scal_Rprimme CONCAT(Num_scal_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_scal_SHprimme)
#  define Num_scal_SHprimme CONCAT(Num_scal_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_scal_RHprimme)
#  define Num_scal_RHprimme CONCAT(Num_scal_,HOST_REAL_SUF)
#endif
void Num_scal_dprimme(PRIMME_INT n, double alpha, double *x, int incx, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_swap_Sprimme)
#  define Num_swap_Sprimme CONCAT(Num_swap_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_swap_Rprimme)
#  define Num_swap_Rprimme CONCAT(Num_swap_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_swap_SHprimme)
#  define Num_swap_SHprimme CONCAT(Num_swap_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_swap_RHprimme)
#  define Num_swap_RHprimme CONCAT(Num_swap_,HOST_REAL_SUF)
#endif
void Num_swap_dprimme(PRIMME_INT n, double *x, int incx, double *y, int incy, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_heev_Sprimme)
#  define Num_heev_Sprimme CONCAT(Num_heev_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_heev_Rprimme)
#  define Num_heev_Rprimme CONCAT(Num_heev_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_heev_SHprimme)
#  define Num_heev_SHprimme CONCAT(Num_heev_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_heev_RHprimme)
#  define Num_heev_RHprimme CONCAT(Num_heev_,HOST_REAL_SUF)
#endif
int Num_heev_dprimme(const char *jobz, const char *uplo, int n, double *a,
      int lda, double *w, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_hegv_Sprimme)
#  define Num_hegv_Sprimme CONCAT(Num_hegv_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hegv_Rprimme)
#  define Num_hegv_Rprimme CONCAT(Num_hegv_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hegv_SHprimme)
#  define Num_hegv_SHprimme CONCAT(Num_hegv_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hegv_RHprimme)
#  define Num_hegv_RHprimme CONCAT(Num_hegv_,HOST_REAL_SUF)
#endif
int Num_hegv_dprimme(const char *jobz, const char *uplo, int n, double *a,
      int lda, double *b0, int ldb0, double *w, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_gesvd_Sprimme)
#  define Num_gesvd_Sprimme CONCAT(Num_gesvd_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gesvd_Rprimme)
#  define Num_gesvd_Rprimme CONCAT(Num_gesvd_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gesvd_SHprimme)
#  define Num_gesvd_SHprimme CONCAT(Num_gesvd_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_gesvd_RHprimme)
#  define Num_gesvd_RHprimme CONCAT(Num_gesvd_,HOST_REAL_SUF)
#endif
int Num_gesvd_dprimme(const char *jobu, const char *jobvt, int m, int n,
      double *a, int lda, double *s, double *u, int ldu, double *vt, int ldvt,
      primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Num_hetrf_Sprimme)
#  define Num_hetrf_Sprimme CONCAT(Num_hetrf_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hetrf_Rprimme)
#  define Num_hetrf_Rprimme CONCAT(Num_hetrf_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hetrf_SHprimme)
#  define Num_hetrf_SHprimme CONCAT(Num_hetrf_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hetrf_RHprimme)
#  define Num_hetrf_RHprimme CONCAT(Num_hetrf_,HOST_REAL_SUF)
#endif
void Num_hetrf_dprimme(const char *uplo, int n, double *a, int lda, int *ipivot,
   double *work, int ldwork, int *info);
#if !defined(CHECK_TEMPLATE) && !defined(Num_hetrs_Sprimme)
#  define Num_hetrs_Sprimme CONCAT(Num_hetrs_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hetrs_Rprimme)
#  define Num_hetrs_Rprimme CONCAT(Num_hetrs_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hetrs_SHprimme)
#  define Num_hetrs_SHprimme CONCAT(Num_hetrs_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_hetrs_RHprimme)
#  define Num_hetrs_RHprimme CONCAT(Num_hetrs_,HOST_REAL_SUF)
#endif
void Num_hetrs_dprimme(const char *uplo, int n, int nrhs, double *a,
      int lda, int *ipivot, double *b, int ldb, int *info);
#if !defined(CHECK_TEMPLATE) && !defined(Num_trsm_Sprimme)
#  define Num_trsm_Sprimme CONCAT(Num_trsm_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_trsm_Rprimme)
#  define Num_trsm_Rprimme CONCAT(Num_trsm_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_trsm_SHprimme)
#  define Num_trsm_SHprimme CONCAT(Num_trsm_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_trsm_RHprimme)
#  define Num_trsm_RHprimme CONCAT(Num_trsm_,HOST_REAL_SUF)
#endif
void Num_trsm_dprimme(const char *side, const char *uplo, const char *transa,
      const char *diag, int m, int n, double alpha, double *a, int lda,
      double *b, int ldb);
void Num_copy_zprimme(PRIMME_INT n, PRIMME_COMPLEX_DOUBLE *x, int incx, PRIMME_COMPLEX_DOUBLE *y, int incy,
                      primme_context ctx);
void Num_gemm_zprimme(const char *transa, const char *transb, int m, int n,
      int k, PRIMME_COMPLEX_DOUBLE alpha, PRIMME_COMPLEX_DOUBLE *a, int lda, PRIMME_COMPLEX_DOUBLE *b, int ldb, PRIMME_COMPLEX_DOUBLE beta,
      PRIMME_COMPLEX_DOUBLE *c, int ldc, primme_context ctx);
void Num_gemm_dhd_zprimme(const char *transa, const char *transb, int m, int n,
      int k, PRIMME_COMPLEX_DOUBLE alpha, PRIMME_COMPLEX_DOUBLE *a, int lda, PRIMME_COMPLEX_DOUBLE *b, int ldb, PRIMME_COMPLEX_DOUBLE beta,
      PRIMME_COMPLEX_DOUBLE *c, int ldc, primme_context ctx);
void Num_hemm_zprimme(const char *side, const char *uplo, int m, int n,
      PRIMME_COMPLEX_DOUBLE alpha, PRIMME_COMPLEX_DOUBLE *a, int lda, PRIMME_COMPLEX_DOUBLE *b, int ldb, PRIMME_COMPLEX_DOUBLE beta,
      PRIMME_COMPLEX_DOUBLE *c, int ldc);
void Num_trmm_zprimme(const char *side, const char *uplo,
      const char *transa, const char *diag, int m, int n, PRIMME_COMPLEX_DOUBLE alpha,
      PRIMME_COMPLEX_DOUBLE *a, int lda, PRIMME_COMPLEX_DOUBLE *b, int ldb, primme_context ctx);
void Num_gemv_zprimme(const char *transa, PRIMME_INT m, int n, PRIMME_COMPLEX_DOUBLE alpha,
      PRIMME_COMPLEX_DOUBLE *a, int lda, PRIMME_COMPLEX_DOUBLE *x, int incx, PRIMME_COMPLEX_DOUBLE beta, PRIMME_COMPLEX_DOUBLE *y,
      int incy, primme_context ctx);
void Num_gemv_ddh_zprimme(const char *transa, PRIMME_INT m, int n, PRIMME_COMPLEX_DOUBLE alpha,
      PRIMME_COMPLEX_DOUBLE *a, int lda, PRIMME_COMPLEX_DOUBLE *x, int incx, PRIMME_COMPLEX_DOUBLE beta, PRIMME_COMPLEX_DOUBLE *y,
      int incy, primme_context ctx);
void Num_gemv_dhd_zprimme(const char *transa, PRIMME_INT m, int n, PRIMME_COMPLEX_DOUBLE alpha,
      PRIMME_COMPLEX_DOUBLE *a, int lda, PRIMME_COMPLEX_DOUBLE *x, int incx, PRIMME_COMPLEX_DOUBLE beta, PRIMME_COMPLEX_DOUBLE *y,
      int incy, primme_context ctx);
void Num_hemv_zprimme(const char *uplo, int n, PRIMME_COMPLEX_DOUBLE alpha,
   PRIMME_COMPLEX_DOUBLE *a, int lda, PRIMME_COMPLEX_DOUBLE *x, int incx, PRIMME_COMPLEX_DOUBLE beta,
   PRIMME_COMPLEX_DOUBLE *y, int incy);
void Num_axpy_zprimme(PRIMME_INT n, PRIMME_COMPLEX_DOUBLE alpha, PRIMME_COMPLEX_DOUBLE *x, int incx,
   PRIMME_COMPLEX_DOUBLE *y, int incy, primme_context ctx);
PRIMME_COMPLEX_DOUBLE Num_dot_zprimme(PRIMME_INT n, PRIMME_COMPLEX_DOUBLE *x, int incx, PRIMME_COMPLEX_DOUBLE *y, int incy,
                       primme_context ctx);
void Num_larnv_zprimme(int idist, PRIMME_INT *iseed, PRIMME_INT length,
      PRIMME_COMPLEX_DOUBLE *x, primme_context ctx);
void Num_scal_zprimme(PRIMME_INT n, PRIMME_COMPLEX_DOUBLE alpha, PRIMME_COMPLEX_DOUBLE *x, int incx, primme_context ctx);
void Num_swap_zprimme(PRIMME_INT n, PRIMME_COMPLEX_DOUBLE *x, int incx, PRIMME_COMPLEX_DOUBLE *y, int incy, primme_context ctx);
int Num_heev_zprimme(const char *jobz, const char *uplo, int n, PRIMME_COMPLEX_DOUBLE *a,
      int lda, double *w, primme_context ctx);
int Num_hegv_zprimme(const char *jobz, const char *uplo, int n, PRIMME_COMPLEX_DOUBLE *a,
      int lda, PRIMME_COMPLEX_DOUBLE *b0, int ldb0, double *w, primme_context ctx);
int Num_gesvd_zprimme(const char *jobu, const char *jobvt, int m, int n,
      PRIMME_COMPLEX_DOUBLE *a, int lda, double *s, PRIMME_COMPLEX_DOUBLE *u, int ldu, PRIMME_COMPLEX_DOUBLE *vt, int ldvt,
      primme_context ctx);
void Num_hetrf_zprimme(const char *uplo, int n, PRIMME_COMPLEX_DOUBLE *a, int lda, int *ipivot,
   PRIMME_COMPLEX_DOUBLE *work, int ldwork, int *info);
void Num_hetrs_zprimme(const char *uplo, int n, int nrhs, PRIMME_COMPLEX_DOUBLE *a,
      int lda, int *ipivot, PRIMME_COMPLEX_DOUBLE *b, int ldb, int *info);
void Num_trsm_zprimme(const char *side, const char *uplo, const char *transa,
      const char *diag, int m, int n, PRIMME_COMPLEX_DOUBLE alpha, PRIMME_COMPLEX_DOUBLE *a, int lda,
      PRIMME_COMPLEX_DOUBLE *b, int ldb);
#endif
