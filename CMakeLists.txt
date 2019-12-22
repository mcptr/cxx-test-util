cmake_minimum_required(VERSION 3.13)

project(cxx-test-util)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic -Winit-self -pipe -O2 -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

set(CXXTESTUTIL_SOURCES
  src/util.cxx
  src/util_options.cxx
  )

include_directories(src)
add_library(cxxtestutil MODULE ${CXXTESTUTIL_SOURCES})
target_link_libraries(cxxtestutil PRIVATE boost_program_options)

install(TARGETS cxxtestutil LIBRARY DESTINATION lib COMPONENT cxxtestutil)
