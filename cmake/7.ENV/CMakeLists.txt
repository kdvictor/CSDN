cmake_minimum_required(VERSION 3.20)
project(env)

#设置环境变量只影响当前cmake进程，不会影响后续构建和测试的环节

#1. 环境变量是全局的，不缓存，和全局属性基本类似，访问更简单
set(ENV{myenv} "my env")
message("myenv = $ENV{myenv}")

#父目录可以访问子目录种定义的ENV变量
add_subdirectory(sub1)
message("in main sub1_env = $ENV{sub1_env}")


#2.可以访问系统的环境变量
message("kokkos_DIR = $ENV{kokkos_DIR}")