#include "neon_types.h"

namespace neon {

template <typename T, int SZ>
SIMD<T,SZ> vabd(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_signed<T>::value,
SIMD<T,SZ>>::type vabs(SIMD<T,SZ> const& v0);

template <typename T, int SZ>
SIMD<T,SZ> vadd(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

//template <typename T, int SZ>
//SIMD<T,SZ> vbsl(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value,
SIMD<typename mask_type<T>::type,SZ>>::type vcage(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value,
SIMD<typename mask_type<T>::type,SZ>>::type vcagt(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value,
SIMD<typename mask_type<T>::type,SZ>>::type vcale(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value,
SIMD<typename mask_type<T>::type,SZ>>::type vcalt(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T, int SZ>
SIMD<typename mask_type<T>::type,SZ> vceq(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vceq(T const& v0, T const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vceq(T const& v0, T const& v1);

template <typename T, int SZ>
SIMD<typename mask_type<T>::type,SZ> vceqz(SIMD<T,SZ> const& v0);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vceqz(T const& v0);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vceqz(T const& v0);

template <typename T, int SZ>
SIMD<typename mask_type<T>::type,SZ> vcge(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcge(T const& v0, T const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcge(T const& v0, T const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_signed<T>::value,
SIMD<typename mask_type<T>::type,SZ>>::type vcgez(SIMD<T,SZ> const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcgez(T const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcgez(T const& v0);

template <typename T, int SZ>
SIMD<typename mask_type<T>::type,SZ> vcgt(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcgt(T const& v0, T const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcgt(T const& v0, T const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_signed<T>::value,
SIMD<typename mask_type<T>::type,SZ>>::type vcgtz(SIMD<T,SZ> const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcgtz(T const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcgtz(T const& v0);

template <typename T, int SZ>
SIMD<typename mask_type<T>::type,SZ> vcle(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcle(T const& v0, T const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcle(T const& v0, T const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_signed<T>::value,
SIMD<typename mask_type<T>::type,SZ>>::type vclez(SIMD<T,SZ> const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vclez(T const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vclez(T const& v0);

template <typename T, int SZ>
SIMD<typename mask_type<T>::type,SZ> vclt(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vclt(T const& v0, T const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vclt(T const& v0, T const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_signed<T>::value,
SIMD<typename mask_type<T>::type,SZ>>::type vcltz(SIMD<T,SZ> const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcltz(T const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcltz(T const& v0);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value, 
SIMD<T,SZ>>::type vdiv(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T, int SZ>
SIMD<T,SZ> vdup(T v);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value, 
SIMD<T,SZ>>::type vfma(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1, SIMD<T,SZ> const& v2);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value, 
SIMD<T,SZ>>::type vfma(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1, T v2);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value, 
SIMD<T,SZ>>::type vfms(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1, SIMD<T,SZ> const& v2);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value, 
SIMD<T,SZ>>::type vfms(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1, T v2);

template <typename T>
SIMD64<T> vget_high(SIMD128<T> const& v);

template <typename T>
SIMD64<T> vget_low(SIMD128<T> const& v);

template <typename T, int SZ>
SIMD<T,SZ> vhadd(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename T, int SZ>
SIMD<T,SZ> vhsub(SIMD<T,SZ> const& v0, SIMD<T,SZ> const& v1);

template <typename SIMDT>
SIMDT vld1(typename SIMDT::base_type const* m);

template <typename SIMDT>
SIMDT vld1_dup(typename SIMDT::base_type const* m);

template <typename SIMDT>
std::array<SIMDT, 2> vld1_x2(typename SIMDT::base_type const* m);

template <typename SIMDT>
std::array<SIMDT, 3> vld1_x3(typename SIMDT::base_type const* m);

template <typename SIMDT>
std::array<SIMDT, 4> vld1_x4(typename SIMDT::base_type const* m);

} // namespace neon

#include "neon.inl"
