cmake_minimum_required(VERSION 3.20)
project(string)

#截取字符串"begin test cmake string end"中的子字符串"test cmake string"

set(str "begin test cmake string end")
set(sub_str1 "begin") #查找字符串begin的位置
set(sub_str2 "end") #查找字符串end的位置
string(FIND ${str} ${sub_str1} pos1) #在str中查找begin的位置并存入pos1中
string(FIND ${str} ${sub_str2} pos2) #在str中查找end的位置并存入pos1中
message("FIND ${sub_str1} POS ${pos1}")
message("FIND ${sub_str2} POS ${pos2}")

string(LENGTH ${sub_str1} length_str1) #获取字符串begin的长度
math(EXPR pos1 "${pos1} + ${length_str1}") #将begin的位置加上begin的长度即为字串的起始位置
math(EXPR sub_length "${pos2} - ${pos1}") #求子字符串的长度
string(SUBSTRING ${str} ${pos1} ${sub_length} substr) #提取子字符串存入substr
message("substr: [${substr}]") #加[]是为了看字符串前后有没有空格

string(STRIP ${substr} substr) #去掉空格
message("substr: [${substr}]")

string(TOUPPER ${substr} substr) #转大写
message("substr: [${substr}]")

string(APPEND substr " append001 " " append002 ") #追加字符串
message("substr: [${substr}]")

string(REPLACE "append" "REPLACE" replacestr ${substr}) #替换字符串
message("replacestr: [${replacestr}]")

string(REGEX MATCH "[A-Z]+[0-9]+" regexstr ${replacestr})#正则表达式匹配字符串
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

