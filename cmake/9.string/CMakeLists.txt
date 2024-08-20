cmake_minimum_required(VERSION 3.20)
project(string)

#查找字符串的位置
set(str "begin test cmake string end")
#要查找的字符串
set(sub_str1 "begin")
set(sub_str2 "end")
#在str1中查找sub_str的位置并存入pos中,位置从0开始
string(FIND ${str} ${sub_str1} pos1)
string(FIND ${str} ${sub_str2} pos2)
message("FIND ${sub_str1} POS ${pos1}")
message("FIND ${sub_str2} POS ${pos2}")

#获取字符串长度
string(LENGTH ${sub_str1} length_str1)
math(EXPR pos1 "${pos1} + ${length_str1}")
math(EXPR sub_length "${pos2} - ${pos1}")
string(SUBSTRING ${str} ${pos1} ${sub_length} substr)
message("substr: [${substr}]")
#去掉空格
string(STRIP ${substr} substr)
message("substr: [${substr}]")

#转大写
string(TOUPPER ${substr} substr)
message("substr: [${substr}]")

#追加
string(APPEND substr " append001 " " append002 ")
message("substr: [${substr}]")

#替换
string(REPLACE "append" "REPLACE" replacestr ${substr})
message("replacestr: [${replacestr}]")

#正则表达式匹配
string(REGEX MATCH "[A-Z]+[0-9]+" regexstr ${replacestr})
message("regexstr: [${regexstr}]")

#JSON操作
set(tjson [=[
{
	"webs":{
		"web":[
			{
				"name":"cmake",
				"url:":"cmake.org.cn"
			},
			{
				"name":"ffmpeg",
				"url":"ffmpeg.club"
			}
		]
	}
}
]=])

#访问webs->web[0]->name
string(JSON var ERROR_VARIABLE evar GET ${tjson} webs web 0 name)
message("webs->web[0].name = ${var}")

#访问webs->web[1]->url
string(JSON var ERROR_VARIABLE evar GET ${tjson} webs web 1 url)
message("webs->web[1].url = ${var}")

#读取json数组长度
string(JSON web_count ERROR_VARIABLE evar LENGTH ${tjson} webs web)
message("webs->web length = ${web_count} ")

#json的增加,修改和删除
string(JSON out_json  ERROR_VARIABLE evar SET ${tjson} webs web 2 [=[			{
				"name":"cpp",
				"url":"cppds.com"
			}]=])
message("out_json =${out_json}")

string(JSON modify_json  ERROR_VARIABLE evar SET ${tjson} webs web 1 [=[{
				"name":"ffmpeg_modify",
				"url":"cppds.com_modify"
			}]=])
message("modify_json =${modify_json}")

string(JSON remove_json  ERROR_VARIABLE evar REMOVE ${tjson} webs web 0)
message("remove_json =${remove_json}")

