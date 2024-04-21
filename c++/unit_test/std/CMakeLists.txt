
generate_bin_name(BIN)
string(CONCAT BIN ${BIN} "_unit_test")

koll_add_test(
    TEST_NAME
        ${BIN}
    PRIVATE
        stdTS.cc
        ../main.cc
    DEPENDENCIES
        gtest
        koll
)