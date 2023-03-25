include(CMakeParseArguments)

function(print array prefix)
	foreach(v ${array})
		message("${prefix}_${v}\n")
	endforeach()
endfunction()

function(test_func_args)
	set(options IS_BOOLEAN1 IS_BOOLEAN2) #args those set as true
	set(oneValueArgs ARG1 ARG2)   #args those take one value
	set(multiArgs PUBLIC PRIVATE) #args those take multiple value
  cmake_parse_arguments(test_arg "${options}" "${oneValueArgs}" "${multiArgs}" ${ARGN})
endfunction()

#[[ function(koll_add_lib)
	set(options "")
	set(oneValueArgs LIB_NAME)
	set(multiArgs PUBLIC PRIVATE)
	cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiArgs}" ${ARGN})
	add_library(${ARG_LIB_NAME} SHARED)
	message("library name is [${ARG_LIB_NAME}]")
	target_sources(${ARG_LIB_NAME} PRIVATE ${ARG_PRIVATE})
	target_sources(${ARG_LIB_NAME} PUBLIC ${ARG_PUBLIC})
	target_include_directories(${ARG_LIB_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
endfunction() ]]

function(koll_add_lib)
	set(options "")
	set(oneValueArgs LIB_NAME)
	set(multiArgs PUBLIC PRIVATE)
	cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiArgs}" ${ARGN})
	add_library(${ARG_LIB_NAME} SHARED)
	message("library name is [${ARG_LIB_NAME}]")

	#The PRIVATE and PUBLIC keywords specify where those corresponding sources should be used.
	#PRIVATE simply means those sources should only be added to myLib ,
	#whereas PUBLIC means those sources should be added to myLib and to any target that links to myLib
	target_sources(${ARG_LIB_NAME} PRIVATE ${ARG_PRIVATE} PUBLIC ${ARG_PUBLIC})

	#[[PRIVATE: The includes can only be used by the helpers-library itself.
	   PUBLIC: The includes can be used by the helpers-library itself and any target 
	           that uses the helpers-library, e.g. via target_link_libraries
			   (MainApplication PUBLIC libhelpers).
       INTERFACE: The includes can't be used by the helpers-library, only by targets that 
	              use the helpers-library.]]
	target_include_directories(${ARG_LIB_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
endfunction()

function(generate_bin_name bin_name)
	string(FIND  ${CMAKE_CURRENT_SOURCE_DIR} "/" POS REVERSE)
	math(EXPR POS "${POS}+1")
	string(SUBSTRING ${CMAKE_CURRENT_SOURCE_DIR} ${POS} -1 DIR_NAME)
	set(${bin_name} ${DIR_NAME} PARENT_SCOPE)
endfunction()