
generate_bin_name(BIN)

koll_add_test(
    TEST_NAME
        ${BIN}
    PRIVATE
        DeletegatingConstructor.cc
        ../main.cc
    DEPENDENCIES
        gtest
        timer
)