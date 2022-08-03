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