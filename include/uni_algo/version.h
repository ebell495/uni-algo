/* C++ Standard Library wrapper for Unicode Algorithms Implementation.
 * License: Public Domain or MIT - choose whatever you want.
 * See LICENSE.md */

#ifndef UNI_ALGO_VERSION_H_UAIH
#define UNI_ALGO_VERSION_H_UAIH

#include "impl/impl_cpp_lib_version.h"
#include "impl/impl_unicode_version.h"

namespace una::version {

class library_v
{
public:
    const int major = (UNI_ALGO_CPP_LIB_VERSION / 1000000);
    const int minor = (UNI_ALGO_CPP_LIB_VERSION / 1000 % 1000);
    const int patch = (UNI_ALGO_CPP_LIB_VERSION % 1000);

    constexpr library_v() noexcept = default;
    constexpr library_v(int ma, int mi, int pa) noexcept : major{ma}, minor{mi}, patch{pa} {}
    friend constexpr bool operator==(const library_v& x, const library_v& y) noexcept
    {
        return x.major == y.major &&
               x.minor == y.minor &&
               x.patch == y.patch;
    }
    friend constexpr bool operator!=(const library_v& x, const library_v& y) noexcept { return !(x == y); }
    friend constexpr bool operator<(const library_v& x, const library_v& y) noexcept
    {
        return x.major != y.major ? x.major < y.major :
               x.minor != y.minor ? x.minor < y.minor :
               x.patch != y.patch ? x.patch < y.patch : false;
    }
    friend constexpr bool operator>(const library_v& x, const library_v& y) noexcept { return y < x; }
    friend constexpr bool operator<=(const library_v& x, const library_v& y) noexcept { return !(x > y); }
    friend constexpr bool operator>=(const library_v& x, const library_v& y) noexcept { return !(x < y); }
};

class unicode_v
{
public:
    const int major = (UNI_ALGO_UNICODE_VERSION / 1000000);
    const int minor = (UNI_ALGO_UNICODE_VERSION / 1000 % 1000);
    const int update = (UNI_ALGO_UNICODE_VERSION % 1000);

    constexpr unicode_v() noexcept = default;
    constexpr unicode_v(int ma, int mi, int up) noexcept : major{ma}, minor{mi}, update{up} {}
    friend constexpr bool operator==(const unicode_v& x, const unicode_v& y) noexcept
    {
        return x.major == y.major &&
               x.minor == y.minor &&
               x.update == y.update;
    }
    friend constexpr bool operator!=(const unicode_v& x, const unicode_v& y) noexcept { return !(x == y); }
    friend constexpr bool operator<(const unicode_v& x, const unicode_v& y) noexcept
    {
        return x.major != y.major ? x.major < y.major :
               x.minor != y.minor ? x.minor < y.minor :
               x.update != y.update ? x.update < y.update : false;
    }
    friend constexpr bool operator>(const unicode_v& x, const unicode_v& y) noexcept { return y < x; }
    friend constexpr bool operator<=(const unicode_v& x, const unicode_v& y) noexcept { return !(x > y); }
    friend constexpr bool operator>=(const unicode_v& x, const unicode_v& y) noexcept { return !(x < y); }
};

inline constexpr library_v library; // Library version
inline constexpr unicode_v unicode; // Unicode version

} // namespace una::version

#endif // UNI_ALGO_VERSION_H_UAIH
