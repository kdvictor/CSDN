#include <iostream>
using namespace std;

int main()
{
#ifdef PARA1
	cout << "����ͨ�������ļ�����COMPILE_DEFINITIONS��C++����ֵ" << endl;
	cout << "PARA1 = " << PARA1 << endl;
#endif

#ifdef PARA2
	cout << "����ͨ������Ŀ������COMPILE_DEFINITIONS��C++����ֵ" << endl;
	cout << "PARA2 = " << PARA2 << endl;
#endif

#ifdef PARA3
	cout << "����ͨ������Ŀ��׷�����Ը�C++����ֵ" << endl;
	cout << "PARA3 = " << PARA3 << endl;
#endif

	return 0;
}
