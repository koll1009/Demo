generate_bin_name(LIB_NAME)
message("library name is [${LIB_NAME}]")

add_library(${LIB_NAME} SHARED)
target_sources(${LIB_NAME} PRIVATE Test.cpp)
message("build interface [$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>]")
target_include_directories(${LIB_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)