//测试class template之内可否再有template(members)
//test __STL_MEMBER_TEMPLATES in <stl_config.h>
#include "stdafx.h"
#include <iostream>

using namespace std;

class alloc {
};

template <class T,class Alloc= alloc>
class vector
{
public:
	typedef T value_type;
	typedef value_type* iterator;

	template<class I>
	void insert(iterator position, I first, I last)
	{
		cout << "insert()" << endl;
	}
};

int main()
{
	int ia[5] = { 0,1,2,3,4 };

	cout << *ia << endl;
	cout << *(ia + 4) << endl;

	vector<int> x;
	vector<int>::iterator ite = NULL;//原文并未加NULL，不能使用未初始化的局部变量
	x.insert(ite, ia, ia + 4);//原文是5是c++98和c++11的标准问题吗？又或者是作者想去强调一下即使填入超出范围的参数也会构造
	return 1;
}


