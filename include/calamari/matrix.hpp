//
// Created by Sam Sleight on 31/01/2016.
//

#ifndef CALAMARI_MATRIX_HPP
#define CALAMARI_MATRIX_HPP

#include "defines.hpp"
#include "vector.hpp"

#include <utility>
#include <stdexcept>
#include <cstddef>

CALAMARI_NS

class Renderer;

template<size_t, size_t, typename>
class Matrix;

namespace impl {

template<typename, typename>
struct mat_idx_impl;

template<size_t, size_t, size_t, typename, typename>
struct mat_pair_impl;

template<size_t rows, size_t cols, typename T, size_t... Idxs>
struct mat_idx_impl<Matrix<rows, cols, T>, std::index_sequence<Idxs...>> {
    static constexpr Vector<cols, T> row(const Matrix<rows, cols, T>& mat, size_t n) {
        return calamari::Vector<cols, T>(mat.get((cols * n) + Idxs)...);
    };

    static constexpr Vector<rows, T> col(const Matrix<rows, cols, T>& mat, size_t n) {
        return calamari::Vector<rows, T>(mat.get((cols * Idxs) + n)...);
    };
};

template<size_t N, size_t M, size_t P, typename T, size_t... IdxsX, size_t... IdxsY>
struct mat_pair_impl<N, M, P, T, std::pair<std::index_sequence<IdxsX...>, std::index_sequence<IdxsY...>>> {
    template<typename U>
    static constexpr Matrix<N, P, decltype(T() * U())> mul(const Matrix<N, M, T>& lhs, const Matrix<M, P, U>& rhs) {
        return calamari::Matrix<N, P, decltype(T() * U())>(lhs.row(IdxsX).dot(rhs.col(IdxsY))...);
    }
};

template<size_t max, size_t x, size_t y, typename IdxsX, typename IdxsY>
struct make_mul_idxs_impl;

template<size_t max, size_t x, size_t y, size_t... IdxsX, size_t... IdxsY>
struct make_mul_idxs_impl<max, x, y, std::index_sequence<IdxsX...>, std::index_sequence<IdxsY...>> {
    using result = typename make_mul_idxs_impl<max, x, y - 1, std::index_sequence<x, IdxsX...>, std::index_sequence<y, IdxsY...>>::result;
};

template<size_t max, size_t x, size_t... IdxsX, size_t... IdxsY>
struct make_mul_idxs_impl<max, x, 0, std::index_sequence<IdxsX...>, std::index_sequence<IdxsY...>> {
    using result = typename make_mul_idxs_impl<max, x - 1, max, std::index_sequence<x, IdxsX...>, std::index_sequence<0, IdxsY...>>::result;
};

template<size_t max, size_t... IdxsX, size_t... IdxsY>
struct make_mul_idxs_impl<max, 0, 0, std::index_sequence<IdxsX...>, std::index_sequence<IdxsY...>> {
    using result = std::pair<std::index_sequence<0, IdxsX...>, std::index_sequence<0, IdxsY...>>;
};

template<size_t n>
using make_mul_idxs = typename make_mul_idxs_impl<n - 1, n - 1, n - 1, std::index_sequence<>, std::index_sequence<>>::result;

}

template<size_t N, size_t M, typename T = int>
class Matrix {
public:
    static const size_t rows = N;
    static const size_t cols = M;

    using Type = T;

    using row_idx_impl = impl::mat_idx_impl<Matrix<rows, cols, Type>, std::make_index_sequence<rows>>;
    using col_idx_impl = impl::mat_idx_impl<Matrix<rows, cols, Type>, std::make_index_sequence<cols>>;

    template<typename... U>
    constexpr Matrix(U... args) noexcept : data{(T)args...} {};

    constexpr const Type& get(size_t n) const {
        return n < (rows * cols) ? data[n] : throw std::invalid_argument("Index must be less than Matrix::(rows * cols)");
    };

    constexpr Vector<cols, Type> row(size_t n) const {
        return n < rows ? col_idx_impl::row(*this, n) : throw std::invalid_argument("Row index must be less than Matrix::Rows");
    };

    constexpr Vector<rows, Type> col(size_t n) const {
        return n < cols ? row_idx_impl::col(*this, n) : throw std::invalid_argument("Col index must be less than Matrix::Cols");
    };

    template<size_t P, typename U>
    constexpr Matrix<rows, P, T> operator*(const Matrix<cols, P, U>& other) const {
        using Idxs = impl::make_mul_idxs<P>;
        return impl::mat_pair_impl<rows, cols, P, Type, Idxs>::mul(*this, other);
    };

private:
    friend class Renderer;

    T data[rows * cols];
};

CALAMARI_NS_END

#endif //CALAMARI_MATRIX_HPP
