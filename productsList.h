#ifndef PRODUCTSLIST_H
#define PRODUCTSLIST_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Node.h"
#include "Product.h"
using namespace std;

class ProductsList
{
private:
	string category;
	Node<Product>* head;
	Node<Product>* tail;
	int size = 0;

public:
	Node<Product>* getHead()
	{
		return head;
	}

	ProductsList()
	{
		category = "-";
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	ProductsList(string category)
	{
		this->category = category;
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	~ProductsList()
	{
		while (head != nullptr)
		{
			Node<Product>* temp = head;
			head = head->getNextPtr();
			delete temp;
			temp = nullptr;
		}
		tail = nullptr;
	}

	int getSize() const
	{
		return size;
	}

	string getCategory()
	{
		return category;
	}

	Product getProduct(int index)
	{
		if (index == 1)
			return head->getData();

		Node<Product>* curr = head;
		for (int i = 1; i < index; i++)
		{
			curr = curr->getNextPtr();
		}
		return curr->getData();
	}
	Product getProduct(string prod)
	{
		Node<Product>* curr = head;
		while (curr != nullptr)
		{
			if (curr->getData().getProduct_name() == prod)
			{
				return curr->getData();
			}
			curr = curr->getNextPtr();
		}

		return Product();
	}
	void addProduct(string name, double price)
	{
		Node<Product>* N = new Node<Product>(Product(name, price));
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

	void addProduct(Product p)
	{
		Node<Product>* N = new Node<Product>(p);
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

	bool deleteProduct(int ind)
	{
		if (size == 0 || ind < 1 || ind > size)
			return false;

		if (ind == 1)
		{
			Node<Product>* current = head;
			head = head->getNextPtr();
			delete current;
			size--;
			if (size == 0)
				tail = nullptr;
			return true;
		}

		Node<Product>* current = head;
		Node<Product>* previous;

		for (int i = 1; i < ind; i++)
		{
			previous = current;
			current = current->getNextPtr();
		}
		previous->setNextPtr(current->getNextPtr());
		if (current == tail)
			tail = previous;
		delete current;
		size--;
		return true;
	}

	string print()
	{
		Node<Product>* curr = head;



		string output;
		output = "\r\n---------------------------------------------------\r\n "
			+ category + "\r\n---------------------------------------------------\r\n";
		output + "Sr.     " + "Product Name                  " + "Price\r\n";
		output + "---------------------------------------------------\r\n";

		int i = 1;
		while (curr != nullptr)
		{
			output += to_string(i) + "     "
				+ curr->getData().getProduct_name() + "                         Rs. " + to_string(curr->getData().getProduct_price()) + "\r\n";

			curr = curr->getNextPtr();
			i++;
		}

		output + "\r\n\r\n\r\n";
		return output;
	}
};

#endif // PRODUCTSLIST_H
