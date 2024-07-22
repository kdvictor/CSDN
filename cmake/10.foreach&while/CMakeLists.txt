cmake_minimum_required(VERSION 3.20)
project(foreach_while)

#RANGE：遍历范围
foreach(var RANGE 5) #遍历0-5的数字
	message("var = ${var}")
endforeach()

#RANGE:指定范围遍历
foreach(var RANGE 3 9)#遍历3-9中间的数字
	message("var = ${var}")
endforeach()

#RANGE:按步长遍历
foreach(var RANGE 1 36 3)#以3为步长遍历1-36之间的数字
	message("var = ${var}")
endforeach()

#数组操作:IN LISTS
set(src "a;b;c;d;e")
foreach(var IN LISTS src)
	message("var = ${var}")
endforeach()

#数组操作:IN ITEMS
set(src "a;b;c;d;e")
foreach(var IN ITEMS ${src}) #IN ITEMS必须加${}
	message("var = ${var}")
endforeach()

#遍历多个list
set(A "1;2;3;4;5")
set(B "a;b;c;d;e")
foreach(var IN LISTS A B) #先遍历第一个，后遍历第二个
	message("var = ${var}")
endforeach()

#同时遍历多个lists：IN ZIP_LISTS
set(A "1;2;3;4;5")
set(B "a;b;c;d;e")
foreach(var IN ZIP_LISTS A B) #用一个变量名表示，则对应变量加下标_0,_1等
	message("var_0 = ${var_0} var_1 = ${var_1}")
endforeach()

foreach(var1 var2 IN ZIP_LISTS A B) #用多个变量名分别表示
	message("var1 = ${var1} var2 = ${var2}")
endforeach()

#continue,break
foreach(var RANGE 20)
	math(EXPR re "${var} % 3") #将var除以3的余数存入re
	if(NOT re) #可以被3整除
		message("var = ${var}")
		continue()#退出本次循环
	endif()
	if(var GREATER 11)
		break() #大于11退出整个循环
	endif()
endforeach()

#while
set(var 1)
while(var)
	math(EXPR var "${var} + 1")
	math(EXPR re "${var} % 10")
	message("var = ${var}")
	message("re = ${re}")

	if(re) #非10的倍数结束本次循环
		continue()
	endif()

	if(var GREATER 20)
		set(var 0)
	endif()

endwhile()