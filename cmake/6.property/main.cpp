#include <iostream>
using namespace std;

int main()
{
#ifdef PARA1
	cout << "测试通过设置文件属性COMPILE_DEFINITIONS给C++传递值" << endl;
	cout << "PARA1 = " << PARA1 << endl;
#endif

#ifdef PARA2
	cout << "测试通过设置目标属性COMPILE_DEFINITIONS给C++传递值" << endl;
	cout << "PARA2 = " << PARA2 << endl;
#endif

#ifdef PARA3
	cout << "测试通过设置目标追加属性给C++传递值" << endl;
	cout << "PARA3 = " << PARA3 << endl;
#endif

	return 0;
}
