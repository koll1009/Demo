generate_bin_name(BIN)

koll_add_test(
    TEST_NAME
        ${BIN}
    PRIVATE
        ../main.cc
        atomic/gcc_sync_apis.cc
        atomic/gcc_atomic_apis.cc
        atomic/cpp_atomic.cc
        jemalloc/jemallocTS.cc
        get_long_opt.cc
    DEPENDENCIES
        jemalloc
        gtest
    INCLUDE_LINK_DIRECTORIES
        ../../../3pp/jemalloc/lib
)