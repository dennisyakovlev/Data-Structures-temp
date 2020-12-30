#pragma once
#include <memory>

template<typename Type>
struct Node {
	
	using Val = Type;
	using Node_Ptr = Node*;

public:

	Node() {
	
		allocate();
	
	}
	Node(const Val& value) {

		allocate();
		data = &value;

	}
	~Node() {

		alloc.destroy(data);
		alloc.deallocate(data, 1);

	}

	void set_data_new(const Val& value) {

		construct(value);

	}

	Val& get_data() { return data; }
	Node_Ptr& get_element() { return element; }

private:

	inline void allocate() {

		data = alloc.allocate(1);

	}
	void construct(const Val& value) {

		alloc.construct(data, value);

	}


	Val data;
	Node_Ptr element;
	std::allocator<Val> alloc;

};

template<typename Type>
struct Doubly_Node {

public:

	using Val = Type;
	using const_Val = const Val;

	using Ptr = Doubly_Node*;

	Doubly_Node() : next_elem(nullptr), prev_elem(nullptr) {}
	//shoud be a node not a pointer
	Doubly_Node(Ptr prev_ptr, Ptr next_ptr) : next_elem(prev_ptr), prev_elem(next_ptr) {}
	Doubly_Node(const Val& value, Ptr prev_ptr, Ptr next_ptr) : data(value), next_elem(prev_ptr), prev_elem(next_ptr) {}

	Val& get_data() {

		return data;

	}
	const_Val& get_data() const {

		return data;

	}

	Ptr get_next() {

		return next_elem;

	}
	Ptr get_next() const {

		return next_elem;

	}
	Ptr get_prev() {

		return prev_elem;

	}
	Ptr get_prev() const {

		return prev_elem;

	}

private:

	Val data;
	Ptr next_elem;
	Ptr prev_elem;

};