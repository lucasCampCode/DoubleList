#pragma once
#include "Iterator.h"

template<typename T>
class List
{
public:
	List<T>() { initilize(); };
	List<T>(List<T>& list);
	~List<T>() { destroy(); };
	void initilize();
	bool isEmpty();
	void print();
	int getLength();
	void destroy();
	T front() const;
	T back() const;
	bool contains(const T& object) const;
	void pushFront(const T& value);
	void pushBack(const T& value);
	bool popFront();
	bool popBack();
	bool insert(const T& value, int index);
	bool remove(const T& value);
	bool getData(Iterator<T>& iter, int index);
	void sort();
	List<T>& operator= (List<T>& otherList);
	Iterator<T> begin() const;
	Iterator<T> end() const;

private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount;
	void copyList(const List<T>& other);
};
/// <summary>
/// removes every node in the list
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
inline void List<T>::destroy()
{
	while(!isEmpty())//while list is not empty 
	{
		popBack();//remove last item
	}
}
/// <summary>
/// returns the data at the begining of the list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
inline T List<T>::front() const
{
	return m_first->data;//gets the data of the frist item in the list
}
/// <summary>
/// returns the data at the end of the list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
inline T List<T>::back() const
{
	return m_last->data;//returns the data of the last item in the list
}
/// <summary>
/// returns the first pointer in the list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_first);//returns the beginning of the list
}
/// <summary>
/// returns the last pointer in the list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_last->next);//returns the end of the list
}
/// <summary>
/// checks to see if the value given exist in the list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="value"></param>
/// <returns></returns>
template<typename T>
inline bool List<T>::contains(const T& value) const
{

	for (Iterator<T> iter = begin(); iter != end(); iter++)//iterates till the end of the list
		if (*iter == value)//if a value is the same as the iterator current value then return true
			return true;
	return false;
}
/// <summary>
/// adds a new node to the front of the list and and stores the value given
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="value"></param>
template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T>* node = new Node<T>();
	//sets node value
	node->data = value;
	if (isEmpty())
	{//if nothing in the list sets the first and last node to node;
		m_first = node;
		m_last = node;
		m_nodeCount++;
		return;

	}
	//sets nodes next to first
	node->next = m_first;
	//sets first node previous to node
	m_first->previous = node;
	//now changes to first to node
	m_first = node;
	m_nodeCount++;
}
/// <summary>
/// adds a new node to the end of the list and it stores the value given
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="value"></param>
template<typename T>
inline void List<T>::pushBack(const T& value)
{
	Node<T>* node = new Node<T>();//creates a new node
	//sets node value
	node->data = value;
	if (isEmpty())
	{//if nothing in the list sets the first and last node to node;
		m_first = node;
		m_last = node;
		m_nodeCount++;
		return;
	}
	//sets nodes previous to last
	node->previous = m_last;
	//sets last nodes next to node
	m_last->next = node;
	//now changes to last to node
	m_last = node;
	m_nodeCount++;//increments nodecount
}
/// <summary>
/// remove the first item on the list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
inline bool List<T>::popFront()
{
	if (isEmpty())//checks to see if the list is empty
		return false;

	Node<T>* node = m_first;//sets a node for refrence before moving first to the next node
	if(m_first->next != nullptr)//if next node is node dont set next node previous to this nodes previous
		m_first->next->previous = m_first->previous;
	m_first = m_first->next;//moves the first node to the next node
	delete node;//deletes the forgoten node
	m_nodeCount--;//decrements node count
	return true;
}
/// <summary>
/// remove the last item in the list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
inline bool List<T>::popBack()
{
	if (isEmpty())//checks to see if the list is empty
		return false;

	Node<T>* node = m_last;//sets a node for refrence before moving last to the previous node
	if(m_last->previous != nullptr)//if next node is node dont set next node previous to this nodes previous
		m_last->previous->next = m_last->next;
	m_last = m_last->previous;//moves the first node to the next node
	delete node;//deletes the forgoten node
	m_nodeCount--;//decrements node count
	return true;
}
/// <summary>
/// inserts a new node at the given index
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="value"></param>
/// <param name="index"></param>
/// <returns></returns>
template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	if (index < 0)
		return false;
	else if (index > getLength())//if input is greater than list length pushes the node to the end of the list
	{
		pushBack(value);
		return true;
	}
	Node<T>* node = new Node<T>();//creates a new node and adds its value
	node->data = value;
	Node<T>* iter = m_first;//node tied to the first part of the list
	for (int i = 0; i < index - 1; i++)//iterates till the spesified node is desierd
		iter = iter->next;
	node->next = iter;//sets the new nodes next to be the the list index node
	node->previous = iter->previous;//sets the new nodes previous to the list node index
	iter->previous = node;//set the list index previous node to the new node
	if (node->previous == nullptr)//if previous node is not found sets the first node to new node
		m_first = node;
	else
		node->previous->next = node;//else the node previous next node is set to the new node 
	m_nodeCount++;//increments the node count
	return true;
}
/// <summary>
/// removes all nodes with the same value inputed
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="value"></param>
/// <returns></returns>
template<typename T>
inline bool List<T>::remove(const T& value)
{
	Node<T>* node = m_first;
	if (isEmpty() || !contains(value))//check to see if the list is empty or if the value input is in the list
		return false;
	while (node != nullptr)// loop untill node reaches the end
	{
		if(node->data == value)//if nodes data equals the value input delete node
		{
			if (node->previous == nullptr)//if node previous is null set first to the node next
				m_first = node->next;
			else
				node->previous->next = node->next;//else set the nodes previous next to nodes next

			if (node->next == nullptr)//if node next is null set last to be nodes previous
				m_last = node->previous;
			else
				node->next->previous = node->previous;//else set node next previous to node previous
			delete node;//delete node when done;
			node = m_first;//set node back to first to continue loop
			m_nodeCount--;//decrement evertime a node is deleted
		}
		else
			node = node->next;//if a node data does not equal value input goto the next node
	}
	return true;
}
/// <summary>
/// prints all the items in the list
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
inline void List<T>::print()
{
	for (Iterator<T> iter = begin(); iter != end(); iter++) {//while iterator hasent reached the end increment and print value
		std::cout << *iter << ", ";
	}
	std::cout << std::endl;
}
/// <summary>
/// initilaizes the list with nullptr and a node count of 0
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
inline void List<T>::initilize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}
/// <summary>
/// checks to see if the the list is empty
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
inline bool List<T>::isEmpty()
{
	return m_nodeCount == 0;
}
/// <summary>
/// return a refrenced iterator at a given index
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="iter"></param>
/// <param name="index"></param>
/// <returns></returns>
template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	if (isEmpty() || index < 0 || index > getLength())
		return false;
	for (int i = 0; i < index - 1; i++)
		iter++;
	return true;
}
/// <summary>
/// returns the length of the list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
inline int List<T>::getLength()
{
	return m_nodeCount;
}

template<typename T>
inline List<T>& List<T>::operator=(List<T>& otherList)
{
	destroy();//removes old list
	copyList(otherList);//replaces with a new list
}
/// <summary>
/// simple bubble sort exchanging values not addresses
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
inline void List<T>::sort()
{
	for (int i = 0; i < getLength(); i++)
	{
		Node<T>* node = m_last;//every loop reset the node to the last point on the list
		for (int j = getLength() - 1; j > i; j--)
		{
			if (node->data < node->previous->data)//checks to see if the node data is less than previous nodes data
			{//swap data
				T temp = node->data;
				node->data = node->previous->data;
				node->previous->data = temp;
			}
			node = node->previous;//decrements down the list untill reaching the end
		}
	}
}
/// <summary>
/// copys the list nodes to incriment through
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="other"></param>
template<typename T>
inline void List<T>::copyList(const List<T>& other)
{
	m_first = other.m_first;
	m_last = other.m_last;
	m_nodeCount = other.m_nodeCount;
}
