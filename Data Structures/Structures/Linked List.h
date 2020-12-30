#pragma once
#include "Nodes.h"
#include <iostream>
#include <memory>

//Forward Iterator
template<typename Type>
class List {

public:

	using Val = typename Type;
	using Node_Val = typename Node<Type>;
	using Node_Ptr = typename Node<Type>*;

	List() {

		head = alloc.allocate(1);
		tail = alloc.allocate(1);
		
		head->get_element() = tail;
	
	}
	template<typename Iter>
	List(Iter begin, Iter end) {



	}
	~List() {

		Node_Ptr next = head->get_element();

		alloc.destroy(head);
		alloc.deallocate(head, 1);

		Node_Ptr temp;
		while (next != tail) {

			temp = next->get_element();
			destroy_elem(next);
			next = temp;

		}

		alloc.destroy(tail);
		alloc.deallocate(tail, 1);

	}

	Node_Ptr& begin() {

		return head->get_element();

	}
	Node_Ptr& end() {

		return tail;

	}
	Node_Ptr& get_head() {

		return head;

	}
	bool is_empty()	{ 
		
		return head->get_element() == tail;

	}
	void insert_after(Val value, Node_Ptr element) {

		Node_Ptr new_node = alloc.allocate(1);

		new_node->get_data() = value;
		new_node->get_element() = element->get_element();
		element->get_element() = new_node;

	}
	void remove_after(Node_Ptr element) {

		Node_Ptr new_next = (element->get_element())->get_element();
		destroy_elem(element->get_element());
		element->get_element() = new_next;

	}


	void test() {

		Node_Ptr temp = head->get_element();

		while (temp != tail) {

			std::cout << "Node Data: " << temp->get_data() << std::endl;
			temp = temp->get_element();

		}

	}

private:

	void destroy_elem(Node_Ptr element) {

		alloc.destroy(element);
		alloc.deallocate(element, 1);

	}

	Node_Ptr head;
	Node_Ptr tail;
	std::allocator<Node_Val> alloc;

};