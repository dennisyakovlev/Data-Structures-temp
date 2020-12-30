#pragma once
#include <type_traits>
#include <iostream>

template<typename Elem>
class Test {

public:

	using Data_Val = typename Elem::Val;
	using Elem_Ptr = Elem*;

	Test(Elem& elem) : node(elem) {}

	Data_Val& operator*() {
	}


private:

	Elem_Ptr node;

};

template<typename Type, typename Node_Type = void>
struct Node {
	
	using Val = Type;
	using Node_Ptr = typename std::conditional<std::is_void<Node_Type>::value, Node<Type>*, Node_Type*>::type;

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

template<typename Type, typename Node_Prev = void, typename Node_Next = void>
struct Doubly_Node {

public:

	using Val = Type;
	using Prev_Ptr = typename std::conditional<std::is_void<Node_Prev>::value, Doubly_Node<Type>*, Node_Prev*>::type;
	using Next_Ptr = typename std::conditional<std::is_void<Node_Next>::value, Doubly_Node<Type>*, Node_Next*>::type;

	Doubly_Node() : next_elem(nullptr), prev_elem(nullptr) {}
	Doubly_Node(const Val& value, Prev_Ptr prev_ptr, Next_Ptr next_ptr) : data(value), next_elem(prev_ptr), prev_elem(next_ptr) {}

	Val& get_data() {

		return data;

	}
	Next_Ptr& get_next() {

		return next_elem;

	}
	Prev_Ptr& get_prev() {

		return prev_elem;

	}

private:

	Val data;
	Prev_Ptr prev_elem;
	Next_Ptr next_elem;

};
