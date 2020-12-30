#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <iterator>
#include <crtdbg.h>
#include "Structures/Linked List.h"

using namespace std;

int main() {



	/*
	List<int> l;

	l.insert_after(40, l.get_head());
	l.insert_after(30, l.get_head());
	l.insert_after(20, l.get_head());
	l.insert_after(10, l.get_head());
	//l.test();
	//cout << endl;
	//l.remove_after(l.get_head());
	//l.test();

	List<int>::Node_Ptr b = l.begin();


	cout << (++*b).get_data();
	*/


	List<int> l;

	l.insert_after(40, l.get_head());
	l.insert_after(30, l.get_head());
	l.insert_after(20, l.get_head());
	l.insert_after(10, l.get_head());

	cout << (++(l.begin()));

	/*
	list<int> l2;
	l2.erase(l2.begin());
	l2.push_back(10);
	l2.push_back(20);
	l2.push_back(30);
	l2.push_back(40);

	cout << *( ++(l2.begin()) );
	*/
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

}