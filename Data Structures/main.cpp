#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <string>
#include <crtdbg.h>
#include "Structures/Linked List.h"

using namespace std;

int main() {

	List<string> l;

	l.insert_after("jkl", l.get_head());
	l.insert_after("ghi", l.get_head());
	l.insert_after("def", l.get_head());
	l.insert_after("abc", l.get_head());
	l.remove_after(++++l.get_head());

	for (List<string>::Iter i = l.begin(); i != l.end(); ++i)
		cout << *i << endl;

#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

}