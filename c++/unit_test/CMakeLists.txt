koll_add_test(
    TEST_NAME
        UNIT_TEST_EXE_NAME
    PRIVATE
        main.cc
        lock/lock_guard.cc
    DEPENDENCIES
        gtest
        koll
        
)

add_subdirectory(apis)
add_subdirectory(ktimer_mgr)
add_subdirectory(std)
add_subdirectory(data_structure)
add_subdirectory(cpp_features)