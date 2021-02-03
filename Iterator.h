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
