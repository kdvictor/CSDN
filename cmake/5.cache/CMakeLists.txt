cmake_minimum_required(VERSION 3.21)
project(cache)


#cache: 缓存变量，会缓存起来，全局性质
#普通变量的作用域在于自身和子模块
#主要类型：BOOL FILEPATH PATH STRING INTERNAL(不会开放给用户) 
#docstring：鼠标提示说明
#FORCE：强制修改缓存变量

#set(变量名 变量值 CACHE 变量类型 鼠标提示说明)
set(cache_var1 "cache_var1" CACHE STRING "cache docstring")
message("cache_var1 = ${cache_var1}")
#一般修改无法修改cache变量
set(cache_var1 "cache_var2" CACHE STRING "cache docstring")
message("cache_var1 = ${cache_var1}")
#强制修改缓存变量FORCE
set(cache_var1 "cache_force" CACHE STRING "cache docstring" FORCE)
message("cache_var1 = ${cache_var1}")


#父目录与子目录之间的关系

#子目录可以获取父目录中定义的普通变量
set(var_main "var main")
add_subdirectory(sub1)
add_subdirectory(sub2)

#父目录不能获取子目录中定义的普通变量
message("var_sub1 in main = ${var_sub1}")
message("var_sub2 in main = ${var_sub2}")

#父级目录可以获取子目录中的cache变量
message("var_cache_sub1 in main = ${var_cache_sub1}")
message("var_cache_sub2 in main = ${var_cache_sub2}")


#使用optional替代BOOL类型的cache变量
#set(var_cache_bool TRUE CACHE BOOL "var cache bool") 等同于下面的语句
option(var_cache_bool "var cache bool" ON)
message("var_cache_bool = ${var_cache_bool}")

#覆盖策略
#CMP0126(3.21版本才支持)
#cmake_policy(SET CMP0126 NEW) NEW不会删除同名普通变量，OLD会删除普通变量
#$CACHE(var_)直接查找缓存变量
set(var_ "var normal")
cmake_policy(SET CMP0126 OLD) #默认是new
set(var_ "var cache" CACHE STRING "var docstring")
message("var_ = ${var_}")
message("var_ = $CACHE{var_}")

#通过命令行-D传递缓存变量：
#camke -S . -B out -D PARA1=para1_value



