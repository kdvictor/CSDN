cmake_minimum_required(VERSION 3.20)
project(math)

#支持+，-，*，/，%，&，^,~,<<,>>
#结果必须是64位有符号数
set(exp "2*(5+6)") #表达式
math(EXPR out ${exp}) #将表达式的值计算并赋值给out
message("${exp} = ${out}")

#输出分为十进制和十六进制

#十进制输出格式
math(EXPR out ${exp} OUTPUT_FORMAT DECIMAL)
message("DECIMAL ${exp} = ${out}")

#十六进制输出格式
math(EXPR out ${exp} OUTPUT_FORMAT HEXADECIMAL)
message("HEXADECIMAL ${exp} = ${out}")


