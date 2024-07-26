cmake_minimum_required(VERSION 3.20)
project(sub_directory)

#测试：父目录可以拿到子目录中定义的文件夹属性
set_property(DIRECTORY . PROPERTY sub_directory_property "sub directory property")