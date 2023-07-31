add_executable(UNIT_TEST_EXE_NAME "")

target_sources(UNIT_TEST_EXE_NAME
    PRIVATE 
        main.cc
        SmartPointer.cc
        Lambda.cc)
target_link_libraries(UNIT_TEST_EXE_NAME PUBLIC koll gtest)

enable_testing()
add_test(NAME UNIT_TEST_EXE_NAME COMMAND UNIT_TEST_EXE_NAME )

add_subdirectory(lock)
add_subdirectory(atomic)