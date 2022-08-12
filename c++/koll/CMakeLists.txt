generate_bin_name(LIB_NAME)
message("library name is [${LIB_NAME}]")

koll_add_lib(
LIB_NAME
    koll
PRIVATE
  Test.cpp)