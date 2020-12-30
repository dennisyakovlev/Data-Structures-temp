#pragma once
#include "Nodes.h"
#include <iostream>
#include <memory>

template<typename Type>
class List {

public:

	using Node_Val = typename Node<Type>;
	using Node_Ptr = typename Node<Type>*;
	using Val = typename Type;

	//List() : head(&tail), tail() {}
	List()  {

		head = alloc.allocate(1);
		tail = alloc.allocate(1);

		head->get_element() = tail;
		tail->get_element() = nullptr;

	}
	template<typename Iter>
	List(Iter begin, Iter end) {

		head = alloc.allocate(1);

		Node_Ptr temp_head = head;
		while (begin != end) {
			Node_Ptr node = alloc.allocate(1);
			temp_head->get_element() = node;
			temp_head->get_data() = *begin;
			begin++;
			
			temp_head = temp_head->get_element();

		}
		tail = alloc.allocate(1);
		tail->get_element() = nullptr;
	}
	List(const List&);
	~List() {
	
		Node_Ptr next = head->get_element();
		while (head != tail) {
			remove_element(head);
			head = next;
			next = next->get_element();

		}
		remove_element(tail);

	}

	bool is_empty()	const { 
		
		return head->get_element() == tail;

	}
	void add(const Val& value, Node_Ptr element) {
	
		

	}

private:

	void remove_element(Node_Ptr elem) {

		alloc.destroy(elem);
		alloc.deallocate(elem, 1);

	}

	Node_Ptr head;
	Node_Ptr tail;
	std::allocator<Node_Val> alloc;

};