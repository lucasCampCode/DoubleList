#pragma once
template<typename T>
struct Node
{
public:
	T m_data;
	Node<T>* m_next;
	Node<T>* m_prvious;
};
