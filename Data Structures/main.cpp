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

	//List<int> l;
	//List<string> l2;
	//cout << l.is_empty();	

	List<int> l;


	l.insert_after(40, l.get_head());
	l.insert_after(30, l.get_head());
	l.insert_after(20, l.get_head());
	l.insert_after(10, l.get_head());
	l.test();
	cout << endl;
	l.remove_after(l.get_head());
	l.test();
	
	/*
	vector<int> v{ 1,2,3,4,5 };
	vector<int>::iterator b = v.begin();
	advance(b, 2);
	*/



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