#pragma once
#include "Iterator.h"

template<typename T>
class List
{
public:
	List<T>();
	List<T>(List<T>& list);
	~List<T>();
	void destroy();
	Iterator<T> begin();
	Iterator<T> end();
	bool contains(const T& object);
	void pushFront(const T& value);
	void pushBack(const T& value);
	bool popFront();
	bool popBack();
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
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount;
};

template<typename T>
inline List<T>::List()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
	
}

template<typename T>
inline List<T>::List(List<T>& list)
{
	m_first = list->m_first;
	m_last = list->m_last;
	m_nodeCount = list->m_nodeCount;
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
	Node<T>* node = m_first;
	while (node != nullptr) 
	{
		if (node->data == value)
			return true;
		node = node->next;
	}
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T>* node = new Node<T>();
	node->data = value;
	node->next = m_first;
	if (isEmpty())
		m_last = node;
	else
		m_first->previous = node;
	m_first = node;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	Node<T>* node = new Node<T>();
	node->data = value;
	node->previous = m_last;
	if (isEmpty())
		m_first = node;
	else
		m_last->next = node;
	m_last = node;
}

template<typename T>
inline bool List<T>::popFront()
{
	if (isEmpty())
		return false;

	auto node = m_first;
	m_first->next->previous = m_first->previous;
	m_first = m_first->next;
	delete node;
	return true;
}

template<typename T>
inline bool List<T>::popBack()
{
	if (isEmpty())
		return false;
	auto node = m_last;
	m_last->previous->next = m_last->next;
	m_last = m_last->previous;
	delete node;
	return true;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	return false;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	Node<T>* node = m_first;
	if (isEmpty() || !contains(value))
		return false;
	while (node != nullptr)
	{
		if(node->data == value)
		{
			if (node->previous == nullptr)
				m_first = node->next;
			else
				node->previous->next = node->next;
			if (node->next == nullptr)
				m_last = node->previous;
			else
				node->next->previous = node->previous;
			delete node;
			node = m_first;
		}
		node = node->next;
	}
	return true;
}

template<typename T>
inline void List<T>::print() const
{
	auto node = m_first;
	while (node != nullptr)
	{
		std::cout << node->data << ", ";
		node = node->next;
	}
	std::cout << std::endl;
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
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{

}

template<typename T>
inline void List<T>::sort()
{
}
