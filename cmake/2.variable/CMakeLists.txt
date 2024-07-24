cmake_minimum_required(VERSION 3.20)
project(variable)

#普通变量
set(var1 "var1")
message("var1 in string = ${var1}") #可以写在"里面"
message("var1 = " ${var1}) #可以写在""外面
message("\${var1} = ${var1}") #转义

unset(var1) #取消变量
message("\${var1} = ${var1}")

#变量的嵌套使用
set(var1 "var1 value")
set(var2 "var1")
message("\${var2} = ${${var2}}")

#CMAKE内置变量
#改变行为的变量
set(BUILD_SHARED_LIBS OFF) #编译静态库


#描述系统的变量
message("MSVC = ${MSVC}")
message("WIN32 = ${WIN32}")
message("UNIX = ${UNIX}")
message("CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")

#其他变量
#传递变量给C++
add_definitions(-Dvariable1) #传递variable1给C++
