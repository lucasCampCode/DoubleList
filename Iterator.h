#pragma once
template<typename T>
class Iterator
{
public:
	Iterator<T>();
	Iterator<T>(Node<T>* node);
	Iterator<T> operator ++();
	Iterator<T> operator --();
	const bool operator ==(const Iterator<T>& iter);
	const bool operator !=(const Iterator<T>& iter);
	T operator *();
private:
	Node<T>* m_current;
}; 

template<typename T>
inline Iterator<T>::Iterator()
{

}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	return Iterator<T>(m_current->next);
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	return Iterator<T>(m_current->previous);
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return m_current == iter;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return m_current != iter;
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return m_current->data;
}
