#pragma once
#include "Nodes.h"
#include <memory>

template<typename Type>
class List {

public:

	using Val = Type;
	using Iter = Iterator<Val>;

	List() {

		tail = alloc.allocate(1);
		alloc.construct(tail);
		
		head = alloc.allocate(1);
		alloc.construct(head, tail);

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

	Iter begin() {

		return Iter(head->get_element());

	}
	Iter end() {

		return Iter(tail);

	}
	Iter get_head() {

		return Iter(head);

	}

	bool is_empty() {

		return head->get_element() == tail;

	}
	void insert_after(Val value, Iter element) {

		Node_Ptr new_node = alloc.allocate(1);
		alloc.construct(new_node, value, element.get_raw()->get_element());

		element.get_raw()->get_element() = new_node;
		
	}
	void remove_after(Iter element) {

		Node_Ptr new_next = (element.get_raw()->get_element())->get_element();
		
		destroy_elem(element.get_raw()->get_element());
		
		element.get_raw()->get_element() = new_next;

	}

	void test() {

		Node_Ptr temp = head->get_element();

		while (temp != tail) {

			std::cout << "Node Data: " << temp->get_data() << std::endl;
			temp = temp->get_element();

		}

	}

private:
	
	using Node_Val = Singly_Node<Val>;
	using Node_Ptr = Node_Val*;

	void destroy_elem(Node_Ptr element) {

		alloc.destroy(element);
		alloc.deallocate(element, 1);

	}

	Node_Ptr head;
	Node_Ptr tail;
	std::allocator<Node_Val> alloc;

};