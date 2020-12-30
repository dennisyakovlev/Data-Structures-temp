#pragma once
#include <memory>

template<typename Type>
struct Node {
	
	using Val = Type;
	using Node_Ptr = Node*;

public:

	Node() : element(nullptr) {}
	Node(Node_Ptr node) : element(node) {}
	Node(Val value, Node_Ptr node) : data(value), element(node) {}

	Val& get_data() { return data; }
	Node_Ptr& get_element() { return element; }

private:

	Val data;
	Node_Ptr element;

};

//Add two template args if you want different nodes
template<typename Type>
struct Doubly_Node {

public:

	using Val = Type;
	using Node_Ptr = Doubly_Node*;

	Doubly_Node() : next_elem(nullptr), prev_elem(nullptr) {}
	Doubly_Node(const Val& value, Node_Ptr prev_ptr, Node_Ptr next_ptr) : data(value), next_elem(prev_ptr), prev_elem(next_ptr) {}

	Val& get_data() {

		return data;

	}

	Node_Ptr& get_next() {

		return next_elem;

	}
	Node_Ptr& get_prev() {

		return prev_elem;

	}

private:

	Val data;
	Node_Ptr next_elem;
	Node_Ptr prev_elem;

};