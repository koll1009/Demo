
generate_bin_name(BIN)

koll_add_test(
    TEST_NAME
        ${BIN}
    PRIVATE
        ../main.cc
        variant.cc
    DEPENDENCIES
        gtest
        koll
)