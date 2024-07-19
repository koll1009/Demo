
generate_bin_name(BIN)

koll_add_test(
    TEST_NAME
        ${BIN}
    PRIVATE
        ../main.cc
        digit_seperator.cc
        binary_literal.cc
        constexpr.cc
        variable_template.cc
        attributes/deprecated.cc
        unique_ptr.cc
        chrono.cc
        tuple.cc
        Lambda.cc
    DEPENDENCIES
        gtest
        koll
)