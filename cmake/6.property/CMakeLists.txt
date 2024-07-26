cmake_minimum_required(VERSION 3.20)
project(property)

#属性分为4种
#全局属性
#文件属性
#文件夹属性
#目标属性

#1.全局属性
#全局属性的作用域也是全局，和cache不同的是，property不会缓存
set_property(GLOBAL PROPERTY test_global "test global value")
get_property(var GLOBAL PROPERTY test_global) #取出全局属性test_global存入var变量
message("var = ${var}")

#父目录可以拿到子目录中定义的全局属性
add_subdirectory(sub_global)
get_property(var GLOBAL PROPERTY sub_global_property)
message("in main sub_global_property = ${var}")

#使用APPEND进行属性拼接,结果是属性数组
set_property(GLOBAL APPEND PROPERTY append_property "append1")
set_property(GLOBAL APPEND PROPERTY append_property "append2")
get_property(var GLOBAL PROPERTY append_property)
message("var = ${var}") #可以使用foreach IN LISTS 遍历

#APPEND_STRING拼接是单纯的字符串拼接，其结果不是属性数组
set_property(GLOBAL APPEND_STRING PROPERTY append_string_property "append string 1")
set_property(GLOBAL APPEND_STRING PROPERTY append_string_property "append string 2")
get_property(var GLOBAL PROPERTY append_string_property)
message("var = ${var}")

#SET: 看属性是否被赋值,无论其值是否为空
set_property(GLOBAL PROPERTY test_set "test set")
get_property(var GLOBAL PROPERTY test_set SET)
message("var = ${var}")
if(var)
	message("test_set is set!")
else()
	message("test_set is not set!")
endif()

#DEFINED：看属性是否定义，无论是否有值。只有在调用define_property之后才为1
define_property(GLOBAL PROPERTY test_defined BRIEF_DOCS "brief" FULL_DOCS "full")
get_property(var GLOBAL PROPERTY test_defined DEFINED)
if(var)
	message("test_defined is defined!")
else()
	message("test_defined is not defined!")
endif()
#获取概要说明
get_property(var GLOBAL PROPERTY test_defined BRIEF_DOCS)
message("brief docs = ${var}")


#2.目录属性
set_property(DIRECTORY . PROPERTY dir_property "dir property")
get_property(var DIRECTORY . PROPERTY dir_property)
message("var = ${var}")

#父目录可以拿到子目录中定义的文件夹属性
add_subdirectory(sub_directory)
get_property(var DIRECTORY sub_directory PROPERTY sub_directory_property)
message("var = ${var}")

#3. 文件属性
set_property(SOURCE ./main.cpp PROPERTY test_source "test source")
get_property(var SOURCE ./main.cpp PROPERTY test_source)
message("var = ${var}")

#4. 生成可执行文件测试
#通过文件属性给C++传递变量
#预置属性 COMPILE_DEFINITIONS
set_property(SOURCE ./main.cpp PROPERTY COMPILE_DEFINITIONS "PARA1=\"test source\"") #注意=两边不能写空格
add_executable(${PROJECT_NAME} ./main.cpp)

#5. 目标属性
set_property(TARGET ${PROJECT_NAME} PROPERTY test_target "test_target")
get_property(var TARGET ${PROJECT_NAME} PROPERTY test_target)
message("var = ${var}")

#通过目标属性给C++传递变量
set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_DEFINITIONS "PARA2=\"test target\"")

#追加设置
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS "PARA3=\"test append target\"")


#打印属性CMakePrintHelpers
include(CMakePrintHelpers)
cmake_print_properties(TARGETS ${PROJECT_NAME} PROPERTIES test_target)
cmake_print_properties(DIRECTORIES . PROPERTIES dir_property)




















