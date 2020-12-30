#pragma once

template<typename Type>
struct Node {

public:

	using Val = Type;    using const_Val = const Val;
	using Ptr = Type*;

	Node(): elem(nullptr) {}
	Node(const Val& value, Ptr pointer) : data(value), elem(pointer) {}

	Val& get_data() { return data; }
	const_Val& get_data() const { return data; }
	
	Ptr get_elem() { return elem; }
	Ptr get_elem() const { return elem; }

private:

	Val data;
	Ptr elem;

};

template<typename Type>
class List {

public:

	using Val = Type;           using const_Val = const Type;
	using Iter = Type*;			using const_Iter = const const_Val*;

	List();
	List(const List&);
	~List();

private:



};