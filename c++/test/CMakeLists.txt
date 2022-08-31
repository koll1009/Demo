generate_bin_name(BINARY_NAME)
message("generate binary name [${BINARY_NAME}]")
aux_source_directory(. SRCS)
add_executable(${BINARY_NAME} "")
target_sources(${BINARY_NAME} PRIVATE ${SRCS})
target_link_libraries(${BINARY_NAME} PUBLIC koll gtest)

#[[ install(TARGETS ${BINARY_NAME}
        EXPORT MyLibTargets 
        LIBRARY DESTINATION lib  # 动态库安装路径
        ARCHIVE DESTINATION lib  # 静态库安装路径
        RUNTIME DESTINATION bin  # 可执行文件安装路径
        PUBLIC_HEADER DESTINATION include  # 头文件安装路径
        ) ]]
#add_executable(${Bin} ${SRCS})