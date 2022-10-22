#ifndef VECTOR_ARITHMETIC__VISIBILITY_CONTROL_H_
#define VECTOR_ARITHMETIC__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define VECTOR_ARITHMETIC_EXPORT __attribute__ ((dllexport))
    #define VECTOR_ARITHMETIC_IMPORT __attribute__ ((dllimport))
  #else
    #define VECTOR_ARITHMETIC_EXPORT __declspec(dllexport)
    #define VECTOR_ARITHMETIC_IMPORT __declspec(dllimport)
  #endif
  #ifdef VECTOR_ARITHMETIC_BUILDING_LIBRARY
    #define VECTOR_ARITHMETIC_PUBLIC VECTOR_ARITHMETIC_EXPORT
  #else
    #define VECTOR_ARITHMETIC_PUBLIC VECTOR_ARITHMETIC_IMPORT
  #endif
  #define VECTOR_ARITHMETIC_PUBLIC_TYPE VECTOR_ARITHMETIC_PUBLIC
  #define VECTOR_ARITHMETIC_LOCAL
#else
  #define VECTOR_ARITHMETIC_EXPORT __attribute__ ((visibility("default")))
  #define VECTOR_ARITHMETIC_IMPORT
  #if __GNUC__ >= 4
    #define VECTOR_ARITHMETIC_PUBLIC __attribute__ ((visibility("default")))
    #define VECTOR_ARITHMETIC_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define VECTOR_ARITHMETIC_PUBLIC
    #define VECTOR_ARITHMETIC_LOCAL
  #endif
  #define VECTOR_ARITHMETIC_PUBLIC_TYPE
#endif

#endif  // VECTOR_ARITHMETIC__VISIBILITY_CONTROL_H_
