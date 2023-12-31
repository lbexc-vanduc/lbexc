#ifndef LBExC_FloatingPoint_H_
#define LBExC_FloatingPoint_H_
#include <LBExC_Config.H>

#ifdef __cplusplus
#include <type_traits>
#include <cinttypes>
#include <climits>
#endif

#if (INT_MAX == LONG_MAX)
typedef          long long lbexc_long;  // NOLINT(modernize-use-using) // so that this can be a C header
typedef unsigned long long lbexc_ulong; // NOLINT(modernize-use-using)
#else
typedef          long lbexc_long;       // NOLINT(modernize-use-using)
typedef unsigned long lbexc_ulong;      // NOLINT(modernize-use-using)
#endif

typedef          double lbexc_double;

#ifdef __cplusplus
namespace lbexc {
    using Long = lbexc_long;
    using ULong = lbexc_ulong;

    using Real = lbexc_double;
}
#endif

#endif
