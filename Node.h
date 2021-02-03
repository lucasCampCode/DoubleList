#pragma once
template<typename T>
struct Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* previous;
};
