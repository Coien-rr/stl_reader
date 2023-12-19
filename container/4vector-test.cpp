#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int  main()
{
	int i;
	vector<int> iv(2, 9);
	cout << "size = " << iv.size() << endl;					//2
	cout << "capacity=  " << iv.capacity() << endl;	//2

	iv.push_back(1);
	cout << "size= " << iv.size() << endl;					//3
	cout << "capacity= " << iv.capacity() << endl;		//3

	iv.push_back(2);
	cout << "size= " << iv.size() << endl;					//4
	cout << "capacity= " << iv.capacity() << endl;		//4

	iv.push_back(3);
	cout << "size= " << iv.size() << endl;					//5
	cout << "capacity= " << iv.capacity() << endl;		//6

	iv.push_back(4);
	cout << "size= " << iv.size() << endl;					//6
	cout << "capacity= " << iv.capacity() << endl;		//6

	for (i=0;i<iv.size();++i)
	{
		cout << iv[i] << ' ';
	}																					//9 9 1 2 3 4
	cout << endl;

	iv.push_back(5);

	cout << "size= " << iv.size() << endl;					//7
	cout << "capacity= " << iv.capacity() << endl;		//9
	for (i=0;i<iv.size();++i)
	{
		cout << iv[i] << ' ';
	}
	cout << endl;																//9 9 1 2 3 4 5

	iv.pop_back();
	iv.pop_back();
	cout << "size= " << iv.size() << endl;					//5
	cout << "capacity= " << iv.capacity() << endl;		//9

	iv.pop_back();
	cout << "size= " << iv.size() << endl;					//4
	cout << "capacity= " << iv.capacity() << endl;		//9

	vector<int>::iterator ivite = find(iv.begin(), iv.end(), 1);
	if (ivite!=iv.end())
	{
		iv.erase(ivite);
	}
		
	cout << "size=" << iv.size() << endl;						//3
	cout << "capacity=" << iv.capacity() << endl;		//9
	for (i = 0;i<iv.size();++i)
	{
		cout << iv[i] << ' ';
	}
	cout << endl;
	auto ite = find(iv.begin(), iv.end(), 2);
	if (ite != iv.end()) iv.insert(ite, 3, 7);

	cout << "size=" << iv.size() << endl;						//6
	cout << "capacity=" << iv.capacity() << endl;		//9
	for (int i = 0; i < iv.size();++i)
	{
		cout << iv[i] << ' ';
	}																					//9 9 7 7 7 2
	cout << endl;

	iv.clear();
	cout << "size=" << iv.size() << endl;						//0
	cout << "capacity=" << iv.capacity() << endl;		//9

}
//原书说的是当vector空间不够的时候，拓展为原来的一倍。
//也许是标准换了吧，我的想法和这个程序的结果一样，是增加当前的一半。