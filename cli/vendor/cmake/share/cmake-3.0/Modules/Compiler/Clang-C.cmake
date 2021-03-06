include(Compiler/Clang)
__compiler_clang(C)

cmake_policy(GET CMP0025 appleClangPolicy)
if(WIN32 OR (APPLE AND NOT appleClangPolicy STREQUAL NEW))
  return()
endif()

if(NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.4)
  set(CMAKE_C90_STANDARD_COMPILE_OPTION "-std=c90")
  set(CMAKE_C90_EXTENSION_COMPILE_OPTION "-std=gnu90")

  set(CMAKE_C99_STANDARD_COMPILE_OPTION "-std=c99")
  set(CMAKE_C99_EXTENSION_COMPILE_OPTION "-std=gnu99")

  set(CMAKE_C11_STANDARD_COMPILE_OPTION "-std=c11")
  set(CMAKE_C11_EXTENSION_COMPILE_OPTION "-std=gnu11")
endif()

set(CMAKE_C_STANDARD_DEFAULT 90)

macro(cmake_record_c_compile_features)
  macro(_get_clang_features std_version list)
    record_compiler_features(C "-std=${std_version}" ${list})
  endmacro()

  if (UNIX AND NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.4)
    _get_clang_features(c11 CMAKE_C11_COMPILE_FEATURES)
    if (_result EQUAL 0)
      _get_clang_features(c99 CMAKE_C99_COMPILE_FEATURES)
    endif()
    if (_result EQUAL 0)
      _get_clang_features(c90 CMAKE_C90_COMPILE_FEATURES)
    endif()
  else()
    set(_result 0)
  endif()
endmacro()
