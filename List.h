#pragma once
#include "Node.h"
#include "Iterator.h"
#include <iostream>
template<typename T>
class List
{
public:
	List<T>();
	List<T>(List<T>& list);
	~List();
	void destroy();
	Iterator<T> begin();
	Iterator<T> end();
	bool contains(const T& object);
	const void pushFront(const T& value);
	const void pushBack(const T& value);
	bool insert(const T& value, int index);
	bool remove(const T& value);
	const void print();
	void initilize();
	const bool isEmpty();
	bool getData(Iterator<T>& iter, int index);
	const int getLength();
	const List<T>& operator = (const List<T>& otherList);
	void sort();

private:
	Node<T> m_first;
	Node<T> m_last;
	int m_nodeCount;
};