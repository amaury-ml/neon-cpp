#include "neon_types.h"

namespace neon {

template <typename T, int SZ>
typename SIMD<T,SZ>::type vabd(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_signed<T>::value,
typename SIMD<T,SZ>::type>::type vabs(typename SIMD<T,SZ>::type const& v0);

template <typename T, int SZ>
typename SIMD<T,SZ>::type vadd(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

//template <typename T, int SZ>
//typename SIMD<T,SZ>::type vbsl(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value,
typename SIMD<typename mask_type<T>::type,SZ>::type>::type vcage(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value,
typename SIMD<typename mask_type<T>::type,SZ>::type>::type vcagt(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value,
typename SIMD<typename mask_type<T>::type,SZ>::type>::type vcale(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value,
typename SIMD<typename mask_type<T>::type,SZ>::type>::type vcalt(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T, int SZ>
typename SIMD<typename mask_type<T>::type,SZ>::type vceq(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vceq(T const& v0, T const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vceq(T const& v0, T const& v1);

template <typename T, int SZ>
typename SIMD<typename mask_type<T>::type,SZ>::type vceqz(typename SIMD<T,SZ>::type const& v0);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vceqz(T const& v0);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vceqz(T const& v0);

template <typename T, int SZ>
typename SIMD<typename mask_type<T>::type,SZ>::type vcge(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcge(T const& v0, T const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcge(T const& v0, T const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_signed<T>::value,
typename SIMD<typename mask_type<T>::type,SZ>::type>::type vcgez(typename SIMD<T,SZ>::type const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcgez(T const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcgez(T const& v0);

template <typename T, int SZ>
typename SIMD<typename mask_type<T>::type,SZ>::type vcgt(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcgt(T const& v0, T const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcgt(T const& v0, T const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_signed<T>::value,
typename SIMD<typename mask_type<T>::type,SZ>::type>::type vcgtz(typename SIMD<T,SZ>::type const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcgtz(T const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcgtz(T const& v0);

template <typename T, int SZ>
typename SIMD<typename mask_type<T>::type,SZ>::type vcle(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcle(T const& v0, T const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcle(T const& v0, T const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_signed<T>::value,
typename SIMD<typename mask_type<T>::type,SZ>::type>::type vclez(typename SIMD<T,SZ>::type const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vclez(T const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vclez(T const& v0);

template <typename T, int SZ>
typename SIMD<typename mask_type<T>::type,SZ>::type vclt(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vclt(T const& v0, T const& v1);

template <typename T>
typename std::enable_if<(std::is_integral<T>::value || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vclt(T const& v0, T const& v1);

template <typename T, int SZ>
typename std::enable_if<std::is_signed<T>::value,
typename SIMD<typename mask_type<T>::type,SZ>::type>::type vcltz(typename SIMD<T,SZ>::type const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 8, // 64bit int or double only input
typename mask_type<T>::type>::type vcltz(T const& v0);

template <typename T>
typename std::enable_if<((std::is_signed<T>::value && std::is_integral<T>::value) || std::is_floating_point<T>::value) && sizeof(T)== 4, // 64bit int or double only input
typename mask_type<T>::type>::type vcltz(T const& v0);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value, 
typename SIMD<T,SZ>::type>::type vdiv(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1);

template <typename T, int SZ>
typename SIMD<T,SZ>::type vdup(T v);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value, 
typename SIMD<T,SZ>::type>::type vfma(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1, typename SIMD<T,SZ>::type const& v2);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value, 
typename SIMD<T,SZ>::type>::type vfma(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1, T v2);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value, 
typename SIMD<T,SZ>::type>::type vfms(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1, typename SIMD<T,SZ>::type const& v2);

template <typename T, int SZ>
typename std::enable_if<std::is_floating_point<T>::value, 
typename SIMD<T,SZ>::type>::type vfms(typename SIMD<T,SZ>::type const& v0, typename SIMD<T,SZ>::type const& v1, T v2);



//#include "neon.inl"

} // namespace neon

