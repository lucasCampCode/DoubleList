#pragma once
#include "Node.h"
template<typename T>
class Iterator
{
public:
	Iterator<T>() {};
	Iterator<T>(Node<T>* node);
	Iterator<T>& operator ++(T);
	Iterator<T>& operator --(T);
	const bool operator ==(const Iterator<T>& iter);
	const bool operator !=(const Iterator<T>& iter);
	T operator *();
private:
	Node<T>* m_current;
}; 
/// <summary>
/// sets the iterator current node to a node given
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"></param>
template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node;
}
/// <summary>
/// increments through the list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name=""></param>
/// <returns></returns>
template<typename T>
inline Iterator<T>& Iterator<T>::operator++(T)
{
	m_current = m_current->next;
	return *this;
}
/// <summary>
/// decrements through the list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name=""></param>
/// <returns></returns>
template<typename T>
inline Iterator<T>& Iterator<T>::operator--(T)
{
	m_current = m_current->previous;
	return *this;
}
/// <summary>
/// returns if one iterators address is the same as anothers iterators address
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="iter"></param>
/// <returns></returns>
template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return m_current == iter.m_current;
}
/// <summary>
/// returns if one iterators address is not the same as anothers iterators address
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="iter"></param>
/// <returns></returns>
template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return m_current != iter.m_current;
}
/// <summary>
/// returns the data the iterator is holding
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
inline T Iterator<T>::operator*()
{
	return m_current->data;
}
