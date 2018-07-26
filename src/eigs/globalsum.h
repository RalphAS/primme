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


#ifndef globalsum_H
#define globalsum_H
int globalSum_sprimme(float *sendBuf, float *recvBuf, int count,
   primme_context ctx);
int globalSum_cprimme(PRIMME_COMPLEX_FLOAT *sendBuf, PRIMME_COMPLEX_FLOAT *recvBuf, int count,
   primme_context ctx);
#if !defined(CHECK_TEMPLATE) && !defined(globalSum_Sprimme)
#  define globalSum_Sprimme CONCAT(globalSum_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(globalSum_Rprimme)
#  define globalSum_Rprimme CONCAT(globalSum_,REAL_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(globalSum_SHprimme)
#  define globalSum_SHprimme CONCAT(globalSum_,HOST_SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(globalSum_RHprimme)
#  define globalSum_RHprimme CONCAT(globalSum_,HOST_REAL_SUF)
#endif
int globalSum_dprimme(double *sendBuf, double *recvBuf, int count,
   primme_context ctx);
int globalSum_zprimme(PRIMME_COMPLEX_DOUBLE *sendBuf, PRIMME_COMPLEX_DOUBLE *recvBuf, int count,
   primme_context ctx);
#endif
