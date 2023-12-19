//本例测试仿函式用于for_each()的情形
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class print
{
public:
	void operator()(const T& elem)
	{
		cout << elem <<' ';
	}
};

int main()
{
	int ia[6] = { 0,1,2,3,4,5 };
	vector<int> iv(ia, ia + 6);

	for_each(iv.begin(), iv.end(), print<int>());
	//print<int>()被描述为一个产生[function template具现体]print<int>的一个暂时物件
	//但是我 个人认为这个暂时物件其实和函数没什么区别，print<int> 类型  () 函数
}