set(UNIT_TEST_EXE_NAME ktest)
add_executable(${UNIT_TEST_EXE_NAME} "")

target_sources(${UNIT_TEST_EXE_NAME} 
    PRIVATE 
        main.cc
        SmartPointer.cc
        Lambda.cc)
target_link_libraries(${UNIT_TEST_EXE_NAME} PUBLIC koll gtest)

add_subdirectory(lock)