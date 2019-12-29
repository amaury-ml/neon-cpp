
#pragma once
#include <arm_neon.h>
#include <cstddef>
#include <type_traits>

namespace neon {
template <typename T, int SZ>
struct neon_type {};

template <>
struct neon_type<int8_t, 8>
{
    using type = int8x8_t;
};

template <>
struct neon_type<int8_t, 16>
{
    using type = int8x16_t;
};

template <>
struct neon_type<uint8_t, 8>
{
    using type = uint8x8_t;
};

template <>
struct neon_type<uint8_t, 16>
{
    using type = uint8x16_t;
};

template <>
struct neon_type<int16_t, 4>
{
    using type = int16x4_t;
};

template <>
struct neon_type<int16_t, 8>
{
    using type = int16x8_t;
};

template <>
struct neon_type<uint16_t, 4>
{
    using type = uint16x4_t;
};

template <>
struct neon_type<uint16_t, 8>
{
    using type = uint16x8_t;
};

template <>
struct neon_type<int32_t, 2>
{
    using type = int32x2_t;
};

template <>
struct neon_type<int32_t, 4>
{
    using type = int32x4_t;
};

template <>
struct neon_type<uint32_t, 2>
{
    using type = uint32x2_t;
};

template <>
struct neon_type<uint32_t, 4>
{
    using type = uint32x4_t;
};

template <>
struct neon_type<uint64_t, 1>
{
    using type = uint64x1_t;
};

template <>
struct neon_type<uint64_t, 2>
{
    using type = uint64x2_t;
};

template <>
struct neon_type<float, 2>
{
    using type = float32x2_t;
};

template <>
struct neon_type<float16_t, 4>
{
    using type = float16x4_t;
};

template <>
struct neon_type<float16_t, 8>
{
    using type = float16x8_t;
};

template <>
struct neon_type<float, 4>
{
    using type = float32x4_t;
};

template <>
struct neon_type<double, 1>
{
    using type = float64x1_t;
};

template <>
struct neon_type<double, 2>
{
    using type = float64x2_t;
};


template <typename T, int SZ>
struct SIMD {
    using type = typename neon_type<T, (SZ/8)/sizeof(T)>::type;
    static constexpr int size = (SZ/8)/sizeof(T);
};

template <typename T> 
using SIMD64 = SIMD<T, 64>;

template <typename T> 
using SIMD128 = SIMD<T, 128>;

static_assert(SIMD64<double>::size == 1, "unexpected size for SIMD64<double>::size");
static_assert(sizeof(SIMD64<double>::type) == 8, "unexpected size for SIMD64<double>::type");

template <typename T>
struct mask_type {
    using type = typename std::make_unsigned<T>::type;
};

template <>
struct mask_type<float> {
    using type = uint32_t;
};

template <>
struct mask_type<double> {
    using type = uint64_t;
};

} // namespace neon