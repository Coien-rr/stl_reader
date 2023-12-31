#include "stdafx.h"
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int i;
	list<int> ilist;
	cout << "size=" << ilist.size() << endl;

	ilist.push_back(0);
	ilist.push_back(1);
	ilist.push_back(2);
	ilist.push_back(3);
	ilist.push_back(4);
	cout << "size=" << ilist.size() << endl;

	list<int>::iterator ite;
	for (ite = ilist.begin();ite!=ilist.end();++ite)
	{
		cout << *ite << ' ';
	}
	cout << endl;

	ite = find(ilist.begin(), ilist.end(), 3);
	if (ite != ilist.end())
		ilist.insert(ite, 99);
	
	cout << "size=" << ilist.size() << endl;
	cout << *ite << endl;

	for (ite = ilist.begin(); ite != ilist.end(); ++ite)
		cout << *ite << ' ';
	cout << endl;

	ite = find(ilist.begin(), ilist.end(), 1);
	if (ite!=ilist.end())
	{
		cout << *(ilist.erase(ite)) << endl;
	}
	for (ite = ilist.begin();ite!=ilist.end();++ite)
	{
		cout << *ite << ' ';
	}
	cout << endl;

}
