koll_add_test(
    TEST_NAME
        UNIT_TEST_EXE_NAME
    PRIVATE
        main.cc
        SmartPointer.cc
        Lambda.cc
        DeletegatingConstructor.cc
        jemalloc/jemallocTS.cc
    DEPENDENCIES
        gtest
        koll
        jemalloc
)

add_subdirectory(lock)
add_subdirectory(atomic)