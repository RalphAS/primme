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


#ifndef ortho_H
#define ortho_H
int ortho_sprimme(float *V, PRIMME_INT ldV, float *R, int ldR, int b1, int b2,
                  float *locked, PRIMME_INT ldLocked, int numLocked,
                  PRIMME_INT nLocal, PRIMME_INT *iseed, primme_context ctx);
int Bortho_local_sprimme(float *V, int ldV, float *R,
      int ldR, int b1, int b2, float *locked, int ldLocked,
      int numLocked, PRIMME_INT nLocal, float *B, int ldB, PRIMME_INT *iseed,
      primme_context ctx);
int ortho_single_iteration_sprimme(float *Q, PRIMME_INT mQ, PRIMME_INT nQ,
      PRIMME_INT ldQ, float *X, int *inX, int nX, PRIMME_INT ldX,
      float *overlaps, float *norms, primme_context ctx);
int ortho_cprimme(PRIMME_COMPLEX_FLOAT *V, PRIMME_INT ldV, PRIMME_COMPLEX_FLOAT *R, int ldR, int b1, int b2,
                  PRIMME_COMPLEX_FLOAT *locked, PRIMME_INT ldLocked, int numLocked,
                  PRIMME_INT nLocal, PRIMME_INT *iseed, primme_context ctx);
int Bortho_local_cprimme(PRIMME_COMPLEX_FLOAT *V, int ldV, PRIMME_COMPLEX_FLOAT *R,
      int ldR, int b1, int b2, PRIMME_COMPLEX_FLOAT *locked, int ldLocked,
      int numLocked, PRIMME_INT nLocal, PRIMME_COMPLEX_FLOAT *B, int ldB, PRIMME_INT *iseed,
      primme_context ctx);
int ortho_single_iteration_cprimme(PRIMME_COMPLEX_FLOAT *Q, PRIMME_INT mQ, PRIMME_INT nQ,
      PRIMME_INT ldQ, PRIMME_COMPLEX_FLOAT *X, int *inX, int nX, PRIMME_INT ldX,
      float *overlaps, float *norms, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(ortho_Sprimme)
#  define ortho_Sprimme CONCAT(ortho_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(ortho_Rprimme)
#  define ortho_Rprimme CONCAT(ortho_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(ortho_SHprimme)
#  define ortho_SHprimme CONCAT(ortho_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(ortho_RHprimme)
#  define ortho_RHprimme CONCAT(ortho_,HOST_REAL_SUF)
#endif
int ortho_dprimme(double *V, PRIMME_INT ldV, double *R, int ldR, int b1, int b2,
                  double *locked, PRIMME_INT ldLocked, int numLocked,
                  PRIMME_INT nLocal, PRIMME_INT *iseed, primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(Bortho_local_Sprimme)
#  define Bortho_local_Sprimme CONCAT(Bortho_local_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Bortho_local_Rprimme)
#  define Bortho_local_Rprimme CONCAT(Bortho_local_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Bortho_local_SHprimme)
#  define Bortho_local_SHprimme CONCAT(Bortho_local_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Bortho_local_RHprimme)
#  define Bortho_local_RHprimme CONCAT(Bortho_local_,HOST_REAL_SUF)
#endif
int Bortho_local_dprimme(double *V, int ldV, double *R,
      int ldR, int b1, int b2, double *locked, int ldLocked,
      int numLocked, PRIMME_INT nLocal, double *B, int ldB, PRIMME_INT *iseed,
      primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(ortho_single_iteration_Sprimme)
#  define ortho_single_iteration_Sprimme CONCAT(ortho_single_iteration_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(ortho_single_iteration_Rprimme)
#  define ortho_single_iteration_Rprimme CONCAT(ortho_single_iteration_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(ortho_single_iteration_SHprimme)
#  define ortho_single_iteration_SHprimme CONCAT(ortho_single_iteration_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(ortho_single_iteration_RHprimme)
#  define ortho_single_iteration_RHprimme CONCAT(ortho_single_iteration_,HOST_REAL_SUF)
#endif
int ortho_single_iteration_dprimme(double *Q, PRIMME_INT mQ, PRIMME_INT nQ,
      PRIMME_INT ldQ, double *X, int *inX, int nX, PRIMME_INT ldX,
      double *overlaps, double *norms, primme_context ctx);
int ortho_zprimme(PRIMME_COMPLEX_DOUBLE *V, PRIMME_INT ldV, PRIMME_COMPLEX_DOUBLE *R, int ldR, int b1, int b2,
                  PRIMME_COMPLEX_DOUBLE *locked, PRIMME_INT ldLocked, int numLocked,
                  PRIMME_INT nLocal, PRIMME_INT *iseed, primme_context ctx);
int Bortho_local_zprimme(PRIMME_COMPLEX_DOUBLE *V, int ldV, PRIMME_COMPLEX_DOUBLE *R,
      int ldR, int b1, int b2, PRIMME_COMPLEX_DOUBLE *locked, int ldLocked,
      int numLocked, PRIMME_INT nLocal, PRIMME_COMPLEX_DOUBLE *B, int ldB, PRIMME_INT *iseed,
      primme_context ctx);
int ortho_single_iteration_zprimme(PRIMME_COMPLEX_DOUBLE *Q, PRIMME_INT mQ, PRIMME_INT nQ,
      PRIMME_INT ldQ, PRIMME_COMPLEX_DOUBLE *X, int *inX, int nX, PRIMME_INT ldX,
      double *overlaps, double *norms, primme_context ctx);
int ortho_smagmaprimme(magma_float *V, PRIMME_INT ldV, magma_float *R, int ldR, int b1, int b2,
                  magma_float *locked, PRIMME_INT ldLocked, int numLocked,
                  PRIMME_INT nLocal, PRIMME_INT *iseed, primme_context ctx);
int ortho_single_iteration_smagmaprimme(magma_float *Q, PRIMME_INT mQ, PRIMME_INT nQ,
      PRIMME_INT ldQ, magma_float *X, int *inX, int nX, PRIMME_INT ldX,
      magma_float *overlaps, magma_float *norms, primme_context ctx);
int ortho_cmagmaprimme(magma_complex_float *V, PRIMME_INT ldV, magma_complex_float *R, int ldR, int b1, int b2,
                  magma_complex_float *locked, PRIMME_INT ldLocked, int numLocked,
                  PRIMME_INT nLocal, PRIMME_INT *iseed, primme_context ctx);
int ortho_single_iteration_cmagmaprimme(magma_complex_float *Q, PRIMME_INT mQ, PRIMME_INT nQ,
      PRIMME_INT ldQ, magma_complex_float *X, int *inX, int nX, PRIMME_INT ldX,
      magma_float *overlaps, magma_float *norms, primme_context ctx);
int ortho_dmagmaprimme(magma_double *V, PRIMME_INT ldV, magma_double *R, int ldR, int b1, int b2,
                  magma_double *locked, PRIMME_INT ldLocked, int numLocked,
                  PRIMME_INT nLocal, PRIMME_INT *iseed, primme_context ctx);
int ortho_single_iteration_dmagmaprimme(magma_double *Q, PRIMME_INT mQ, PRIMME_INT nQ,
      PRIMME_INT ldQ, magma_double *X, int *inX, int nX, PRIMME_INT ldX,
      magma_double *overlaps, magma_double *norms, primme_context ctx);
int ortho_zmagmaprimme(magma_complex_double *V, PRIMME_INT ldV, magma_complex_double *R, int ldR, int b1, int b2,
                  magma_complex_double *locked, PRIMME_INT ldLocked, int numLocked,
                  PRIMME_INT nLocal, PRIMME_INT *iseed, primme_context ctx);
int ortho_single_iteration_zmagmaprimme(magma_complex_double *Q, PRIMME_INT mQ, PRIMME_INT nQ,
      PRIMME_INT ldQ, magma_complex_double *X, int *inX, int nX, PRIMME_INT ldX,
      magma_double *overlaps, magma_double *norms, primme_context ctx);
#endif
