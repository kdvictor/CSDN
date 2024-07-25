cmake_minimum_required(VERSION 3.20)
project(if)

#ON YES TRUE Y 或者非零数为真，其余为假
if(0)
	message("0 is ture!")
else()
	message("0 is false!")
endif()

if(123.1)
	message("123.1 is ture!")
else()
	message("123.1 is false!")
endif()

if(-NOTFOUND)
	message("-NOTFOUND is ture!")
else()
	message("-NOTFOUND is false!")
endif()

#未定义变量为false
if(var_not_def)
	message("var_not_def is ture!")
else()
	message("var_not_def is false!")
endif()

#字符串如果不是常量真，那么字符串就不是真
if("3.2")
	message("string \"3.2\" is true")
else()
	message("string \"3.2\" is false")
endif()

if("0")
	message("string \"0\" is true")
else()
	message("string \"0\" is false")
endif()

if("test")
	message("string \"test\" is true")
else()
	message("string \"test\" is false")
endif()

#逻辑运算符
#NOT AND OR
set(var1 OFF)
if(NOT var1)
	message("NOT var1 is true!")
else()
	message("NOT var1 is false!")
endif()

if(TRUE AND ON)
	message("TRUE AND ON is true!")
else()
	message("TRUE AND ON is false!")
endif()

if(OFF OR TRUE)
	message("OFF OR TRUE is true!")
else()
	message("OFF OR TRUE is false!")
endif()

if(TRUE AND (OFF AND 1))
	message("TRUE AND (OFF AND 1) is true!")
else()
	message("TRUE AND (OFF AND 1) is false!")
endif()

#一元判断
#EXISTS: 判断文件或者文件夹是否存在
#COMMAND: 判断命令是否可用
#DEFINED: 判断变量是否定义
if(EXISTS "./test.txt")
	message("./test.txt is exists!")
else()
	message("./test.txt is not exists!")
endif()

if(COMMAND find_package)
	message("find_package command can use!")
else()
	message("find_package command can not use!")
endif()

set(var OFF)
if(DEFINED var)
	message("var is defined!")
else()
	message("var is not defined!")
endif()


#二元判断
#EQUAL LESS LESSEQUAL GREATER GREATER_EQUAL
#STREQUAL ... 字符串按字典顺序
#VERSION_EQUAL ...  版本号判断
#MATCHS 支持正则表达式
set(VAR1 123)
set(VAR2 "test")

if(VAR1 EQUAL "123")
	message("VAR1 EQUAL \"123\"")
else()
	message("VAR1 NOT EQUAL \"123\"")
endif()

if(VAR2 STREQUAL "test1")
	message("VAR2 EQUAL \"test1\"")
else()
	message("VAR2 NOT EQUAL \"test1\"")
endif()

set(STR1 "abcd1234")
if(STR1 MATCHES "[a-z]+$")
	message("${STR1} MATCHES \"[a-z]+$\"")
else()
	message("${STR1} NOT MATCHES \"[a-z]+$\"")
endif()












