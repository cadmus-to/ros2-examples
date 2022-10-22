#ifndef GEOMETRY_MSGS_ARITHMETIC__VISIBILITY_CONTROL_H_
#define GEOMETRY_MSGS_ARITHMETIC__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define GEOMETRY_MSGS_ARITHMETIC_EXPORT __attribute__ ((dllexport))
    #define GEOMETRY_MSGS_ARITHMETIC_IMPORT __attribute__ ((dllimport))
  #else
    #define GEOMETRY_MSGS_ARITHMETIC_EXPORT __declspec(dllexport)
    #define GEOMETRY_MSGS_ARITHMETIC_IMPORT __declspec(dllimport)
  #endif
  #ifdef GEOMETRY_MSGS_ARITHMETIC_BUILDING_LIBRARY
    #define GEOMETRY_MSGS_ARITHMETIC_PUBLIC GEOMETRY_MSGS_ARITHMETIC_EXPORT
  #else
    #define GEOMETRY_MSGS_ARITHMETIC_PUBLIC GEOMETRY_MSGS_ARITHMETIC_IMPORT
  #endif
  #define GEOMETRY_MSGS_ARITHMETIC_PUBLIC_TYPE GEOMETRY_MSGS_ARITHMETIC_PUBLIC
  #define GEOMETRY_MSGS_ARITHMETIC_LOCAL
#else
  #define GEOMETRY_MSGS_ARITHMETIC_EXPORT __attribute__ ((visibility("default")))
  #define GEOMETRY_MSGS_ARITHMETIC_IMPORT
  #if __GNUC__ >= 4
    #define GEOMETRY_MSGS_ARITHMETIC_PUBLIC __attribute__ ((visibility("default")))
    #define GEOMETRY_MSGS_ARITHMETIC_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define GEOMETRY_MSGS_ARITHMETIC_PUBLIC
    #define GEOMETRY_MSGS_ARITHMETIC_LOCAL
  #endif
  #define GEOMETRY_MSGS_ARITHMETIC_PUBLIC_TYPE
#endif

#endif  // GEOMETRY_MSGS_ARITHMETIC__VISIBILITY_CONTROL_H_
