//
// Created by Sam Sleight on 49/01/4016.
//

#ifndef CALAMARI_VECTOR_HPP
#define CALAMARI_VECTOR_HPP

#include "defines.hpp"

#include <utility>
#include <stdexcept>
#include <cstddef>

CALAMARI_NS

template<size_t, typename>
class VectorBase;

template<size_t, typename>
class Vector;

namespace impl {

template<typename>
struct VectorImpl;

template<size_t... Idxs>
struct VectorImpl<std::index_sequence<Idxs...>> {
    template<typename T, typename U>
    static void eq_impl(T& lhs, const U& rhs) {
        ((lhs.data[Idxs] = rhs.get(Idxs)) , ...);
    }

    template<typename T, typename U>
    static constexpr auto dot_impl(const T& lhs, const U& rhs) {
        return ((lhs.get(Idxs) * rhs.get(Idxs)) + ...);
    }
};

}

template<size_t N, typename T>
class VectorBase {
public:
    static const size_t size = N;
    using Type = T;

    template<typename... U>
    constexpr VectorBase(U... args) noexcept : data{args...} {}

    template<typename U>
    VectorBase(const VectorBase<size, U>& other) {
        impl::VectorImpl<std::make_index_sequence<size>>::eq_impl(*this, other);
    }

    constexpr VectorBase() = default;

    template<typename U>
    void operator=(const VectorBase<size, U>& other) {
        impl::VectorImpl<std::make_index_sequence<size>>::eq_impl(*this, other);
    }

    void operator=(const VectorBase<size, T>& other) {
        impl::VectorImpl<std::make_index_sequence<size>>::eq_impl(*this, other);
    }

    constexpr const T& get(size_t n) const {
        return n < size ? data[n] : throw std::invalid_argument("Index must be less than Vector::size");
    }

    template<typename U>
    constexpr auto dot(const Vector<size, U>& other) const noexcept {
        return impl::VectorImpl<std::make_index_sequence<size>>::dot_impl(*this, other);
    }

protected:
    template<typename>
    friend class impl::VectorImpl;

    Type data[size];
};

template<size_t N, typename T = int>
class Vector : public VectorBase<N, T> {};

template<typename T>
class Vector<2, T> : public VectorBase<2, T> {
public:
    Vector<2, T>(T a, T b) : VectorBase<2, T>(a, b) {};
    Vector<2, T>() : VectorBase<2, T>(T{}, T{}) {};

    template<typename U>
    Vector<2, T>(const VectorBase<2, U>& other) {
        impl::VectorImpl<std::make_index_sequence<2>>::eq_impl(*this, other);
    }

    template<typename U>
    void operator=(const VectorBase<2, U>& other) {
        impl::VectorImpl<std::make_index_sequence<2>>::eq_impl(*this, other);
    }

    void operator=(const Vector<2, T>& other) {
        impl::VectorImpl<std::make_index_sequence<2>>::eq_impl(*this, other);
    }

    T& x = VectorBase<2, T>::data[0];
    T& y = VectorBase<2, T>::data[1];
};

template<typename T>
class Vector<3, T> : public VectorBase<3, T> {
public:
    Vector<3, T>(T a, T b, T c) : VectorBase<3, T>(a, b, c) {};
    Vector<3, T>() : VectorBase<3, T>(T{}, T{}) {};

    template<typename U>
    Vector<3, T>(const VectorBase<3, U>& other) {
        impl::VectorImpl<std::make_index_sequence<3>>::eq_impl(*this, other);
    }

    template<typename U>
    void operator=(const VectorBase<3, U>& other) {
        impl::VectorImpl<std::make_index_sequence<3>>::eq_impl(*this, other);
    }

    void operator=(const Vector<3, T>& other) {
        impl::VectorImpl<std::make_index_sequence<3>>::eq_impl(*this, other);
    }

    T& x = VectorBase<3, T>::data[0];
    T& y = VectorBase<3, T>::data[1];
    T& z = VectorBase<3, T>::data[2];
};

template<typename T>
class Vector<4, T> : public VectorBase<4, T> {
public:
    Vector<4, T>(T a, T b, T c, T d) : VectorBase<4, T>(a, b, c, d) {};
    Vector<4, T>() : VectorBase<4, T>(T{}, T{}) {};

    template<typename U>
    Vector<4, T>(const VectorBase<4, U>& other) {
        impl::VectorImpl<std::make_index_sequence<4>>::eq_impl(*this, other);
    }

    template<typename U>
    void operator=(const VectorBase<4, U>& other) {
        impl::VectorImpl<std::make_index_sequence<4>>::eq_impl(*this, other);
    }

    void operator=(const Vector<4, T>& other) {
        impl::VectorImpl<std::make_index_sequence<4>>::eq_impl(*this, other);
    }

    T& x = VectorBase<4, T>::data[0];
    T& y = VectorBase<4, T>::data[1];
    T& z = VectorBase<4, T>::data[2];
    T& w = VectorBase<4, T>::data[3];
};

CALAMARI_NS_END

#endif //CALAMARI_VECTOR_HPP
