cmake_minimum_required(VERSION 3.20)
project(list)

#在cmake中存储的所有值都是字符串
message("-----------list-----------")
set(src "a" "b" "c")
message("src list: ${src}")

message("-----------使用;追加-----------")
set(src "a" "b" "c" "d;e")
message("new list: ${src}")

#LENGTH:获取list长度
message("----------LENGTH------------")
list(LENGTH src length) #取得src的长度并放入length变量
message("src length: ${length}")

#APPEND:追加list
message("----------APPEND------------")
list(APPEND src "append1;append2")#在src尾部追加append1和append2
list(LENGTH src appnd_length)
message("append list: ${src}")
message("append list length = ${appnd_length}")

#GET:访问list元素
#可以通过0，1，2 / -1，-2，-3的形式访问
message("----------GET------------")
list(GET src 0 var) #访问list第0个元素并存入变量var
message("src at 0: ${var}")
list(GET src -1 var) #访问list倒数第一个元素并存入变量var
message("src at -1: ${var}")

#JOIN:拼接list
message("----------JOIN------------")
list(JOIN src "|" var)
message("join src: ${var}") #使用|拼接所有元素，并存入var变量中
list(JOIN src "" var)
message("join src: ${var}") #去掉拼接符，并存入var变量中

#SUBLIST:取出其中部分数组
message("----------SUBLIST------------")
list(SUBLIST src 0 3 var)#取出src [0,3) 位置的元素存入var
message("sublist src: ${var}")

#FIND:查找匹配
message("----------FIND------------")
list(APPEND src "find1")
message("src: ${src}")
list(FIND src "find1" var) #在src中查找"find1的位置"，并放入var变量
message("find src: ${var}")
list(FIND src "find2" var) #在src中查找"find2的位置"，找不到返回-1
message("find src: ${var}")

#INSERT:插入节点
message("----------INSERT------------")
list(INSERT src 1 "insert1") #在src中1的位置插入"insert1"
message("insert src: ${src}")

#REMOVE_AT 删除节点
message("----------RENOVE_AT------------")
list(REMOVE_AT src 1) #删除src中位置为1的元素
message("remove_at src: ${src}")

#修改节点只能通过先删除在插入的形式修改节点
message("----------修改节点------------")
list(REMOVE_AT src 1)
list(INSERT src 1 "b1")
message("src: ${src}")

#POP_BACK: 后端出队
message("----------POP_BACK------------")
list(POP_BACK src var) #后端出队并放入var中
message("pop_back: ${var}")

#POP_FRONT: 后端出队
message("----------POP_FRONT------------")
list(POP_FRONT src var) #前端出队并放入var中
message("pop_front: ${var}")

#REMOVE_DUPLICATES:去掉重复元素
message("----------REMOVE_DUPLICATES------------")
set(rsrc "y;x;a;b;c;d;b;a;z;f;dp1;dp1")
message("rsrc: ${rsrc}")
list(REMOVE_DUPLICATES rsrc)
message("remove_duplicates rsrc: ${rsrc}")

#SORT:排序
message("----------SORT------------")
set(src "3;23;122;156;157;1;5;7")
list(SORT src) #默认是字符串排序
message("sort src: ${src}")

list(SORT src COMPARE NATURAL)#自然数排序
message("natural sort src: ${src}")