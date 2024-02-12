#include <iostream>
#include <stack>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>
#include "Menu.h"
#include "order.h"
#include "productsList.h"


class Hotel
{
private:
	string HISTORY = "history";
	string name;
	stack<Order> orderStack;
	ProductsList* cart;
	vector <double> quantities;
	int invoiceNumber = 10001;
	menu menu1;
	double totalSales = 0;
	int totalProductsSold = 0;

public:
	Hotel()
	{
		name = "-";
	}

	~Hotel()
	{
		while (!orderStack.empty())
		{
			Order currentOrder = orderStack.top();
			orderStack.pop();
		}
		quantities.clear();
	}

	Hotel(string name)
	{
		this->name = name;
	}

	menu getMenu() {
		return menu1;
	}
	int Get_Total_Products_sold() const
	{
		return this->totalProductsSold;
	}
	double get_Total_Sales()
	{
		return this->totalSales;
	}
	void saveHistory() const
	{
		ofstream outputFile(HISTORY);

		if (!outputFile.is_open())
		{
			//	cerr << "\nError opening file!" << endl;
			return;
		}
		stack<Order> tempStack = orderStack;
		while (!tempStack.empty())
		{
			Order currentOrder = tempStack.top();
			double bill = currentOrder.getBill();
			string name = currentOrder.getCustomerName();
			int invNumber = currentOrder.getInvoiceNumber();
			int totalItems = currentOrder.getTotalItems();
			string dateTime = currentOrder.getDateTime();
			string quantity = "";
			ProductsList* p = new ProductsList();
			p = currentOrder.GetPurchasedItems();
			string prods = "";
			for each (double Q in currentOrder.get_Quantities())
			{
				quantity += to_string(Q)+ "#";
			}
			Node<Product>* curr = p->getHead();
			while (curr != NULL)
			{
				string Pname = curr->getData().getProduct_name();
				for (char& c : Pname)
					if (c == ' ')
						c = '_';

				prods += (Pname + "*" + to_string(curr->getData().getProduct_price()) + "-");
				curr = curr->getNextPtr();
			}

			for (char& c : name)
			{
				if (c == ' ')
					c = '_';
			}
			for (char& c : dateTime)
			{
				if (c == ' ')
					c = '_';
			}

			outputFile << name << " " << invNumber << " " << bill << " " << totalItems << " " << totalSales << " " << totalProductsSold << " " << prods << " "<< quantity <<" " << dateTime << " " << endl;
			tempStack.pop();
		}
		outputFile.close();
	}

	void loadHistory()
	{
		string name;
		string prodName;
		string tempPrice;
		double prodPrice;
		int invNumber;
		string dateTime;
		double bill;
		int totalItems;
		string prods;
		ProductsList* productsPurchased = new ProductsList();
		string Q = "";
		ifstream inputFile(HISTORY);

		if (!inputFile.is_open())
		{
			//cerr << "\nError opening file for reading." << endl;
			return;
		}

		while (!orderStack.empty())
		{
			orderStack.pop();
		}

		while (inputFile >> name >> invNumber >> bill >> totalItems >> totalSales >> totalProductsSold >> prods >> Q >> dateTime)
		{
			this->totalSales = totalSales;
			this->totalProductsSold = totalProductsSold;
			this->invoiceNumber = invNumber;
			string tempWord;
			string tempQuantity;
			for (char& c : name)
				if (c == '_')
					c = ' ';
			for (char& c : dateTime)
				if (c == '_')
					c = ' ';
			for (char c : Q)
			{
				if (c != '#')
				{
					tempQuantity += c;
				}
				else
				{
					quantities.push_back(stod(tempQuantity));
					tempQuantity = "";
				}

			}
			for (char c : prods)
			{
				if (c != '-' && c != '*')
				{
					tempWord += c;
				}
				else
				{
					if (!tempWord.empty())
					{
						if (c == '*')
						{
							prodName = tempWord;
							for (char& c : prodName)
								if (c == '_')
									c = ' ';
						}
						else if (c == '-')
						{
							prodPrice = std::stod(tempWord);
							productsPurchased->addProduct(prodName, prodPrice);
						}
						tempWord.clear();
					}
				}
			}
			orderStack.push(Order(name, invNumber, bill, totalItems, productsPurchased, dateTime,quantities));
		}

		inputFile.close();
	}

	stack<Order> get_Order_Stack()
	{
		return this->orderStack;
	}


	string BillingHistory()
	{
		string output = "";
		stack<Order> tempStack = orderStack;
		if (tempStack.empty())
		{
			return "No billing history available.";
		}

		while (!tempStack.empty())
		{
			Order currentOrder = tempStack.top();
			output += currentOrder.print2();
			tempStack.pop();
		}
		return output;
	}


	ProductsList* getCart() {
		return cart;
	}

	void takeOrder() {
		cart = new ProductsList();
	}

	void addItemsToCart(int categIndex, int prodIndex,double quantity)
	{
		ProductsList* temp = NULL;
		temp = menu1.get_CategoriesList()->get_Category(categIndex);
		Product p = temp->getProduct(prodIndex);
		quantities.push_back(quantity);
		cart->addProduct(p);
	}

	void removeItemsFromCart(int ind) {
		cart->deleteProduct(ind);
	}

	void placeOrder(string customerName) {
		double bill = GenerateBill();
		Order newOrder(customerName, ++invoiceNumber, bill, cart,quantities);
		orderStack.push(newOrder);
		Compute_Total_Sales();
		saveHistory();
		emptyCart();
	}

	void emptyCart() {
		cart->emptyList();
		quantities.clear();
	}

	double GenerateBill()
	{
		Node<Product>* temp = cart->getHead();
		double bill = 0;
		int i = 0;
		while (temp != nullptr)
		{	
			bill += temp->getData().getProduct_price()*quantities[i];
			temp = temp->getNextPtr();
			i++;
		}
		
		return bill;
	}

	void Compute_Total_Sales()
	{
		stack<Order> tempStack = orderStack;
		double totalsales = 0;
		int totalpsold = 0;
		while (!tempStack.empty())
		{
			Order obj = tempStack.top();
			totalsales += obj.getBill();
			totalpsold += obj.getTotalItems();
			tempStack.pop();
		}
		totalSales = totalsales;
		totalProductsSold = totalpsold;
	}


	void refreshData() {
		menu1.loadData();
		loadHistory();
	}

	void exit() {
		menu1.get_CategoriesList()->emptyMenu();
	}

	void loadExistingData() {
		menu1.loadData();
		loadHistory();
	}
};
