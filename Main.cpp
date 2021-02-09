#include <iostream>
#include "List.h"

int main()
{
	srand(time(NULL));
	List<int>* list = new List<int>();
	//test for pushBack function
	for (int i = 0; i < 10; i++)
		list->pushBack(rand() % 10);
	list->print();
	system("pause");
	//test pushFront fuction
	for (int i = 0; i < 10; i++)
		list->pushFront(rand() % 10);
	list->print();

	//test remove function
	int num;
	std::cout << "Number to remove\n";
	std::cin >> num;
	if (list->remove(num))
		std::cout << "succefully removed \n";
	else
		std::cout << "failed\n";
	list->print();
	system("pause");
	//test popFront function
	std::cout << "popFront \n";
	list->popFront();
	list->print();
	system("pause");
	//test popBack function
	std::cout << "popBack \n";
	list->popBack();
	list->print();
	system("pause");
	//test insert function
	std::cout << "insert \n";
	list->insert(500,(int)(list->getLength()/2));
	list->print();
	system("pause");
}

