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
// -----------------------------------------------------------------------------
// matrix_base.h
// -----------------------------------------------------------------------------
//
#ifndef SLAB_MATRIX_MATRIX_BASE_H_
#define SLAB_MATRIX_MATRIX_BASE_H_

#include <cstddef>
#include "slab/matrix/matrix_slice.h"
#include "slab/matrix/support.h"

template<typename T, std::size_t N>
class MatrixBase {
 public:
  static constexpr std::size_t order_ = N;
  using value_type = T;

  MatrixBase() = default;
  MatrixBase(MatrixBase &&) = default;
  MatrixBase &operator=(MatrixBase &&) = default;
  MatrixBase(MatrixBase const &) = default;
  MatrixBase &operator=(MatrixBase const &) = default;

  // number of dimensions
  static constexpr std::size_t order() { return order_; }
  // #elements in the nth dimension
  std::size_t extent(std::size_t n) const { assert(n < order_); return desc_.extents[n]; }
  // the slice defining subscripting
  const MatrixSlice<N> &descriptor() const { return desc_; }

  virtual T *data() = 0;
  virtual const T *data() const = 0;

 private:
  MatrixSlice<N> desc_;
};


#endif // SLAB_MATRIX_MATRIX_BASE_H_
