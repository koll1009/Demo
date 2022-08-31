add_executable(STD_UNIT_TEST "")
target_sources(STD_UNIT_TEST 
    PRIVATE 
        main.cc
        SmartPointer.cc
        Lambda.cc)
target_link_libraries(STD_UNIT_TEST PUBLIC koll gtest)