find_library(LIB_CXXTEST_UTIL
  cxxtestutil
  PATHS ${CMAKE_CURRENT_BINARY_DIR}/../../lib)

find_library(LIB_BOOST_PO boost_program_options)
link_libraries(
  ${LIB_CXXTEST_UTIL}
  ${LIB_BOOST_PO})

add_executable(basic.bin basic.cpp)
