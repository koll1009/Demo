add_executable(SMART_POINTER_TEST "")
target_sources(SMART_POINTER_TEST PRIVATE SmartPointer.cc)
target_link_libraries(SMART_POINTER_TEST PUBLIC koll)