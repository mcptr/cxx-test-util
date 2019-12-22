find_library(LIB_BOOST_PO boost_program_options)
link_libraries(
  cxxtestutil
  ${LIB_BOOST_PO})


add_executable(basic.bin basic.cpp)
target_link_libraries(basic.bin INTERFACE cxxtestutil)
set_target_properties(basic.bin PROPERTIES IMPORTED_LOCATION cxxtestutil)
