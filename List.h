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
	void pushFront(const T& value);
	void pushBack(const T& value);
	bool insert(const T& value, int index);
	bool remove(const T& value);
	void print() const;
	void initilize();
	bool isEmpty() const;
	bool getData(Iterator<T>& iter, int index);
	int getLength() const;
	const List<T>& operator = (const List<T>& otherList);
	void sort();

private:
	Node<T> m_first;
	Node<T> m_last;
	int m_nodeCount;
};

template<typename T>
inline List<T>::List()
{
}

template<typename T>
inline List<T>::List(List<T>& list)
{

}

template<typename T>
inline List<T>::~List()
{
	
}

template<typename T>
inline void List<T>::destroy()
{

}

template<typename T>
inline Iterator<T> List<T>::begin()
{
	return Iterator<T>(m_first);
}

template<typename T>
inline Iterator<T> List<T>::end()
{
	return Iterator<T>(m_last);
}

template<typename T>
inline bool List<T>::contains(const T& value)
{
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T> node = new Node<T>();
	node.data = value;
	node.next = m_first;
	if (isEmpty())
		m_last = node;
	m_first = node;
	return void();
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	Node<T> node = new Node<T>();
	node.data = value;
	node.previous = m_last;
	if (isEmpty())
		m_first = node;
	m_last = node;
	return void();
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	Iterator<T> iter = begin();
	Node<T> newNode = new Node<T>();
	newNode.data = value;
	if (index < 0 || index > getLength())
		return false;
	for (int i = 0; i < index; i++) 
	{
		iter++;
	}
	newNode.next = iter.m_current->next;
	newNode.previous = iter.m_current;
	iter.m_current->next = newNode;
	newNode.next->previous = newNode;
	return true;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	Iterator<T> iter = begin();
	if (!contains(value))
		return false;
	while (iter != end())
	{
		if (iter.m_current->data == value)
		{
			iter.m_current->previous->next = iter.m_current->next;
			iter.m_current->next->previous = iter.m_current->previous;
			delete iter.m_current;
		}
		iter++
	}
	return false;
}

template<typename T>
inline void List<T>::print() const
{
}



template<typename T>
inline void List<T>::initilize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	if (m_first == nullptr && m_last == nullptr)
		return true;
	return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{

	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	Iterator<T> iter = begin();
	int num = 0;
	while(iter.m_current->next != nullptr)
	{
		iter++;
		num++;
	}
	return num;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	// TODO: insert return statement here
}

template<typename T>
inline void List<T>::sort()
{
}
