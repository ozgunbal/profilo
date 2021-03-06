# Copyright (c) Facebook, Inc. and its affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

cmake_minimum_required(VERSION 3.6.0)
project(fbjni CXX)

set(FBJNI_COMPILE_OPTIONS
  -Wall
  -std=c++11
  -fno-omit-frame-pointer
  -fexceptions
  -frtti
  -ffunction-sections
  -O3
  -DNDEBUG
)

file(GLOB fbjni_SOURCES
  cxx/fbjni/*.cpp
  cxx/fbjni/detail/*.cpp
  cxx/lyra/*.cpp
)

add_library(fbjni SHARED ${fbjni_SOURCES})

target_compile_options(fbjni PRIVATE ${FBJNI_COMPILE_OPTIONS})

target_include_directories(fbjni PUBLIC
  cxx
)

if (NOT ANDROID_ABI)
  if (NOT JAVA_HOME)
    message(FATAL_ERROR
      "fbjni requires JAVA_HOME to be defined for non-Android builds.")
  endif()
  target_include_directories(fbjni PUBLIC ${JAVA_HOME}/include)
  if (CMAKE_SYSTEM_NAME STREQUAL Linux)
    target_include_directories(fbjni PUBLIC ${JAVA_HOME}/include/linux)
  endif()
  if (CMAKE_SYSTEM_NAME STREQUAL Darwin)
    target_include_directories(fbjni PUBLIC ${JAVA_HOME}/include/darwin)
  endif()

  enable_testing()
  add_subdirectory(test/jni)

  find_library(GTEST_LIB gtest)
  if(NOT GTEST_LIB)
    # Download and unpack googletest at configure time
    configure_file(googletest-CMakeLists.txt.in googletest-download/CMakeLists.txt)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
      RESULT_VARIABLE result
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
    if(result)
      message(FATAL_ERROR "CMake step for googletest failed: ${result}")
    endif()
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
      RESULT_VARIABLE result
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
    if(result)
      message(FATAL_ERROR "Build step for googletest failed: ${result}")
    endif()

    # Add googletest directly to our build. This defines
    # the gtest and gtest_main targets.
    add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                    ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                    EXCLUDE_FROM_ALL)
  endif()
endif()

if (ANDROID_ABI)
  target_link_libraries(fbjni
    android
    log
  )
endif()

