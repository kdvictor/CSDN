cmake_minimum_required(VERSION 3.20)
project(sub_global)

#测试：父目录可以拿到子目录中定义的全局属性
set_property(GLOBAL PROPERTY sub_global_property "sub global property")
