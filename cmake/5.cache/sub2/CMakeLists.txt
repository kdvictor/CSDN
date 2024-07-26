cmake_minimum_required(VERSION 3.21)
project(sub2)

#测试：子目录可以获取父目录中定义的普通变量
message("var_main in sub2 = ${var_main}")

#测试：父目录不能获取子目录中定义的普通变量
set(var_sub2 "var_sub2")

#测试：父级目录可以获取子目录中的cache变量
set(var_cache_sub2 "var cache sub2" CACHE STRING "cache sub2 docstring")