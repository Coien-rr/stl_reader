#include "stdafx.h"
#include<iostream>  

using namespace std;
template<class T>
class Change {
public:
	typedef T* pointer;
	T* a(T&z)
	{
		auto value = z;
		cout << value;
		cout << &z;
		return (pointer)&z;
	}
	
};

int main()
{
	int number = 5;
	
	Change<int> test;
	test.a(number);

}