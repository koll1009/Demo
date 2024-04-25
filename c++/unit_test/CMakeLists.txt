koll_add_test(
    TEST_NAME
        UNIT_TEST_EXE_NAME
    PRIVATE
        main.cc
        lock/lock_guard.cc
        univeral_ref.cc
    DEPENDENCIES
        gtest
        koll
        
)

add_subdirectory(atomic)
add_subdirectory(jemalloc)
add_subdirectory(lambda)
add_subdirectory(smart_pointer)
add_subdirectory(ktimer_mgr)
add_subdirectory(std)