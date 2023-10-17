koll_add_test(
    TEST_NAME
        UNIT_TEST_EXE_NAME
    PRIVATE
        main.cc
        SmartPointer.cc
        Lambda.cc
        DeletegatingConstructor.cc
        jemalloc/jemallocTS.cc
        lock/lock_guard.cc
    DEPENDENCIES
        gtest
        koll
        jemalloc
)

add_subdirectory(atomic)