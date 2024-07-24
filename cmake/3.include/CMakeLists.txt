cmake_minimum_required(VERSION 3.20)
project(include)

#相当于把cmake/test_include.cmake中的代码复制到这里，可以引用 多次
include("cmake/test_include.cmake")

#当文件不存在时，如果不加OPTIONAL,会报错
include("cmake/1.cmake" OPTIONAL)

#将返回值赋给ret
include("cmake/2.cmake" OPTIONAL RESULT_VARIABLE ret)
message("ret = ${ret}") #NOTFOUND

include("cmake/test_include.cmake" OPTIONAL RESULT_VARIABLE ret)
message("ret = ${ret}") #文件绝对路径