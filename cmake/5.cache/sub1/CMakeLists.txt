cmake_minimum_required(VERSION 3.21)
project(sub1)

#测试：子目录可以获取父目录中定义的普通变量
message("var_main in sub1 = ${var_main}")

#测试：父目录不能获取子目录中定义的普通变量
set(var_sub1 "var_sub1")

#测试：父级目录可以获取子目录中的cache变量
set(var_cache_sub1 "var cache sub1" CACHE STRING "cache sub1 docstring")