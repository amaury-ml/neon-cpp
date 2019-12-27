#pragma once
#include <arm_neon.h>

namespace neon {
template <typename T, int SZ>
struct neon_type {
};



template <>
struct neon_type<float,4>
{
    using type = float32x4_t;
};

template <>
struct neon_type<uint32_t,4>
{
    using type = uint32x4_t;
};

template <>
struct neon_type<int32_t,4>
{
    using type = int32x4_t;
};

template <>
struct neon_type<double,2>
{
    using type = float64x2_t;
};



} // namespace neon