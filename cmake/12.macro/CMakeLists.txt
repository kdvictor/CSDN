cmake_minimum_required(VERSION 3.20)
project(macro)

#macro 大小写不敏感
macro(my_macro)
	set(RET 1)
	message("RET = ${RET}")
endmacro()

my_macro()
MY_macro()

#固定参数传递
macro(foo_fixed arg1 arg2)
	message("arg1 = ${arg1} arg2 = ${arg2}")
	if(${arg1}) #宏参数不是变量，不能用于逻辑运算，需要加${}
		message("arg1 is true!")
	endif()
endmacro()

foo_fixed(1 "test")

#变参
macro(foo_var)
	message("argc = ${ARGC}")

	foreach(var IN ITEMS ${ARGN})
		message("var = ${var}")
	endforeach()

	message("ARGV0 = ${ARGV0}")
endmacro()

foo_var("var1" "var2" "var3")

#属性式参数
macro(my_parse)
	message("ARGN = ${ARGN}")
	cmake_parse_arguments(
		"MY" #前缀
		"LOG;FILE" #option类型，可选项
		"BIN;LIB" #单值
		"TARGETS" #多值
		${ARGN} #参数数组
	)

	#变量名加前缀
	message("MY_LOG = ${MY_LOG}")
	message("MY_FILE = ${MY_FILE}")
	message("MY_BIN = ${MY_BIN}")
	message("MY_LIB = ${MY_LIB}")
	message("MY_TARGETS = ${MY_TARGETS}")
	#MY_UNPARSED_ARGUMENTS：类型传递错误
	message("MY_UNPARSED_ARGUMENTS = ${MY_UNPARSED_ARGUMENTS}")
	#MY_KEYWORDS_MISSING_VALUES: 未传递值
	message("MY_KEYWORDS_MISSING_VALUES = ${MY_KEYWORDS_MISSING_VALUES}")
endmacro()

my_parse(LOG FILE
BIN "bin"
TARGETS "TAR1" "TAR2"
LIB "lib")

#错误传递
my_parse(LOG FILE
BIN "bin1" "bin2" #应为单值，这里传的多值
TARGETS "TAR1" "TAR2"
LIB "lib")