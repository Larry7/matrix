//
// Copyright 2018 The StatsLabs Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/// @file lapack_interface.h
/// @brief LAPACK interface

#ifndef SLAB_MATRIX_LAPACK_INTERFACE_H_
#define SLAB_MATRIX_LAPACK_INTERFACE_H_

#include "slab/matrix/matrix.h"
#include "slab/matrix/traits.h"

template<typename T>
int lapack_getrf(Matrix<T, 2> &a, Matrix<int, 1> &ipiv) {

  int info = 0;

  const int m = a.rows();
  const int n = a.cols();

  //assert(ipiv.size() >= std::max(1, std::min(m, n)));
  ipiv.clear();
  ipiv = Matrix<int, 1>(std::max(1, std::min(m, n)));

  const int lda = n;

  if (is_double<T>::value) {
    info = LAPACKE_dgetrf(
        LAPACK_ROW_MAJOR,
        m,
        n,
        (double *) a.data(),
        lda,
        ipiv.data()
    );
  } else if (is_float<T>::value) {
    info = LAPACKE_sgetrf(
        LAPACK_ROW_MAJOR,
        m,
        n,
        (float *) a.data(),
        lda,
        ipiv.data()
    );
  }

  return info;
}

#endif // SLAB_MATRIX_LAPACK_INTERFACE_H_
