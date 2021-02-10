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
	std::cout << "insert middle\n";
	list->insert(500,(int)(list->getLength()/2));
	list->print();
	system("pause");

	std::cout << "insert first\n";
	list->insert(500, 0);
	list->print();
	system("pause");

	std::cout << "insert last\n";
	list->insert(500, list->getLength()+1);
	list->print();
	system("pause");

	//sort
	std::cout << "sorted list\n";
	list->sort();
	list->print();
	system("pause");

	//iteratior
	std::cout << "what index of the list do you want to return\n";
	std::cin >> num;
	auto iter = list->begin();
	if (list->getData(iter, num))
		std::cout << *iter << " is at the index of " << num << std::endl;
	else
		std::cout << "out of bounds\n";
	system("pause");
	delete list;
}

