
generate_bin_name(BIN)

koll_add_test(
    TEST_NAME
        ${BIN}
    PRIVATE
        remove.cc
        sort.cc
        function.cc
        bind.cc
        count.cc
        count_if.cc
        find.cc
        ../main.cc
    DEPENDENCIES
        gtest
        koll
)