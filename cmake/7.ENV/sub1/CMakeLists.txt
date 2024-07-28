cmake_minimum_required(VERSION 3.20)

#测试：父目录可以访问子目录种定义的ENV变量
set(ENV{sub1_env} "sub1 env")