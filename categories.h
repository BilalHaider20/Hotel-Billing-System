#ifndef CATEGORIES_H
#define CATEGORIES_H

#include <iostream>
#include "Node.h"
#include "productsList.h"
using namespace std;

class Categories
{
private:
	int size;
	Node<ProductsList*>* head;
	Node<ProductsList*>* tail;

public:

	Node<ProductsList*>* getHead()
	{
		return head;
	}

	Categories()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	~Categories()
	{
		emptyMenu();
		head = nullptr;
		tail = nullptr;
	}

	void emptyMenu()
	{
		while (head != nullptr)
		{
			Node<ProductsList*>* temp = head;
			head = head->getNextPtr();
			if (temp->getData() != nullptr)
			{
				delete temp->getData();
			}
			delete temp;
			size--;
		}
		tail = nullptr;
	}

	int getSize() const
	{
		return size;
	}

	ProductsList* get_Category(int index)
	{
		if (index == 1)
			return head->getData();

		Node<ProductsList*>* curr = head;
		for (int i = 1; i < index; i++)
		{
			curr = curr->getNextPtr();
		}
		return curr->getData();
	}

	ProductsList* get_Category(string c)
	{
		Node<ProductsList*>* curr = head;
		while (curr != nullptr)
		{
			if (curr->getData()->getCategory() == c)
			{
				return curr->getData();
			}
			curr = curr->getNextPtr();
		}
		return nullptr;
	}

	void addCategory(string category)
	{
		ProductsList* p = new ProductsList(category);
		Node<ProductsList*>* N = new Node<ProductsList*>(p);
		if (head == NULL)
		{
			N->setNextPtr(nullptr);
			head = N;
			tail = N;
			size++;
			return;
		}

		tail->setNextPtr(N);
		tail = tail->getNextPtr();
		size++;
		return;
	}

	bool deleteCategory(int ind)
	{
		if (size == 0 || ind > size)
			return false;

		if ((size == 1) && (ind == 1))
		{
			Node<ProductsList*>* curr = head;
			head = nullptr;
			tail = nullptr;
			delete curr;
			size--;
			return true;
		}

		if (size > 1 && ind == 1)
		{
			Node<ProductsList*>* curr = head;
			head = curr->getNextPtr();
			size--;
			delete curr;
			return true;
		}

		Node<ProductsList*>* current = head;
		Node<ProductsList*>* previous = nullptr;
		for (int i = 1; i < ind; i++)
		{
			previous = current;
			current = current->getNextPtr();
		}

		previous->setNextPtr(current->getNextPtr());
		size--;
		delete current;
		return true;
	}

	bool categoryExists(string category)
	{
		Node<ProductsList*>* curr = head;
		while (curr != nullptr)
		{
			if (curr->getData()->getCategory() == category)
			{
				return true;
			}
			curr = curr->getNextPtr();
		}
		return false;
	}

	string Print()
	{
		string output;
		Node<ProductsList*>* curr = head;
		while (curr != nullptr)
		{
			output += curr->getData()->print();
			curr = curr->getNextPtr();
		}
		return output;
	}
};

#endif // CATEGORIES_H
