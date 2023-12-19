//test __STL_TEMPLATE_NULL in <stl_config.h>
#include "stdafx.h"
#include <iostream>

using namespace std;



template<class Key> struct hash {
	void operator()() { cout << "hash<T>" << endl; }
};

template<> struct hash<char> {
	void operator()() { cout << "hash<char>" << endl; }
};

template<> struct hash<unsigned char> {
	void operator()() { cout << "hash<unsigned char>" << endl; }
};

int main()
{
	hash<long> t1;
	hash<char> t2;
	hash<unsigned char>t3;

	t1();	
	t2();
	t3();
}

//此程序只适用于gcc和vc6，因为没有要求explicit speciization