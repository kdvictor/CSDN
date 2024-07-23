cmake_minimum_required(VERSION 3.20)
project(message)

#注释
# 第一种注释

#[[
	第二种注释
	第二种注释
	第二种注释
	第二种注释
]]

#message指定日志级别
message(WARNING "warning") #会打印行号
message(NOTICE "none or notice")
message(STATUS "status") #前面会加--

#设置显示级别：cmake -S . -B out --log-level=VERBOSE
#可以重定向到log文件：cmake -S . -B out --log-level=VERBOSE>log.txt
message(VERBOSE "verbose") #用户想看的详细信息, 默认不显示

message(DEBUG "debug") #开发人员调试信息，默认不开放给用户，前面会加--

message(TRACE "trace") #开发人员跟踪调试信息，默认不开放给用户，前面会加--

message(SEND_ERROR "send error") #send error发生时cmake跳过继续执行
message("after send error!")

message(FATAL_ERROR "fatal error") #fatal error发生时，cmake停止执行
message("after fatal error!")