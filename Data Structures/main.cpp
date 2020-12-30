#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <crtdbg.h>
#include "Structures/Linked List.h"

using namespace std;

int main() {

	//List<int> l;
	//List<string> l2;
	//cout << l.is_empty();	


	string s = "abc";

	list<string> v;
	v.push_back(s);

	s.~basic_string();

	cout << *v.begin();


	/*
	int a = 5;
	int b = 10;

	allocator<Test<int>> alloc;

	Test<int>* node_1 = alloc.allocate(1);;
	Test<int>* node_2 =	alloc.allocate(1);;

	node_1->get_data() = &a;
	node_1->get_element() = node_2;

	node_2->get_data() = &b;
	node_2->get_element() = nullptr;

	cout << *((node_1->get_element())->get_data());

	alloc.destroy(node_1);
	alloc.destroy(node_2);

	alloc.deallocate(node_1, 1);
	alloc.deallocate(node_2, 1);
	*/


#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	//cout << "print" << endl;

}