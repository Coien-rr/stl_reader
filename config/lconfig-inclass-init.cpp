//test in-class initialization of static const integral members
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class testClass{
public:
	static const int _datai = 5;
	static const long _datal = 3L;
	static  char _datac = 'c';
};
int main()
{
	cout << testClass<int>:: _datai << endl;
	cout << testClass<int>::_datal << endl;
	cout << testClass<int>::_datac << endl;
	//tesClass<T>无论怎么修改T值不变，因为采用了静态常量这种方式进行声明。
	//静态常量这种方式，是在类内声明且有初始值时采用的。
}