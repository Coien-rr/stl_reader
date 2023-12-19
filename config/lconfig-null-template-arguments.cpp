//test __STL_NULL_TMPL_ARGS in <stl_config.h>
#include "stdafx.h"
#include <iostream>
#include<cstddef>

using namespace std;

class alloc {
};

template <class T, class Alloc = alloc, size_t BufSiz = 0>
class deque {
public:
	deque() { cout << "deque" << ' '; }
};

template<class T,class Sequence = deque<T>>
class stack {
	//这样可以
	friend bool operator == <T>(const stack<T>&, const stack<T>&);
	friend bool operator < <T>(const stack<T>&, const stack<T>&);
	
	// 这样也可以
	//friend bool operator == <T>(const stack&, const stack&);
	//friend bool operator < <T>(const stack&, const stack&);

	// 这样也可以
	//friend bool operator == <> (const stack&, const stack&);
	//friend bool operator <  <>(const stack&, const stack&);

	//not ok
	//friend bool operator == (const stack&, const stack&);
	//friend bool operator < (const stack&, const stack&);

public:
	stack() { cout << "stack" << endl; }
private:
	Sequence c;
};

template <class T,class Sequence>
bool operator == (const stack<T, Sequence>& x,
	const stack<T, Sequence>& y) {
	return cout << "operator==" << '\t';
}
template <class T, class Sequence>
bool operator < (const stack<T, Sequence>& x,
	const stack<T, Sequence>& y) {
	return cout << "operator<" << '\t';
}

int main()
{
	stack<int> x;
	stack<int> y;

	cout << (x == y) << endl;
	cout << (x < y) << endl;
	
	stack<char> y1;
}


//我并没有成功运行上述程序，原因很显然，两个operator函数并未真正的返回了一个bool值，而且这里缺少一些数据成员供给比较，
//当然也可以直接比较int类型，但是需参照lconfig11.cpp中的内容，方可运行。