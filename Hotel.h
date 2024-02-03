#include <iostream>
#include <stack>
#include <string>
#include <conio.h>
#include <fstream>

#include "Menu.h"
#include "order.h"
#include "productsList.h"


class Hotel
{
private:
	string HISTORY = "history";
	string name;
	stack<Order> orderStack;
	int invoiceNumber = 10000;
	menu menu1;
	double totalSales = 0;
	int totalProductsSold = 0;

public:
	Hotel()
	{
		name = "-";
	}

	Hotel(string name)
	{
		this->name = name;
	}

	menu getMenu() {
		return menu1;
	}

	void saveHistory()
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
			ProductsList* p = new ProductsList();
			p = currentOrder.GetPurchasedItems();
			string prods = "";

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

			outputFile << name << " " << invNumber << " " << bill << " " << totalItems << " " << totalSales << " " << totalProductsSold << " " << prods << " " << invoiceNumber << " " << dateTime << " " << endl;
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

		while (inputFile >> name >> invNumber >> bill >> totalItems >> totalSales >> totalProductsSold >> prods >> invoiceNumber >> dateTime)
		{
			this->totalSales = totalSales;
			this->totalProductsSold = totalProductsSold;
			this->invoiceNumber = invoiceNumber;
			string tempWord;
			for (char& c : name)
				if (c == '_')
					c = ' ';
			for (char& c : dateTime)
				if (c == '_')
					c = ' ';

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
			orderStack.push(Order(name, invNumber, bill, totalItems, productsPurchased, dateTime));
		}

		inputFile.close();
	}

	double GenerateBill(ProductsList* cart)
	{
		Node<Product>* temp = cart->getHead();
		double bill = 0;

		while (temp != nullptr)
		{
			bill += temp->getData().getProduct_price();
			temp = temp->getNextPtr();
		}

		return bill;
	}

	void BillingHistory()
	{
		system("cls");
		cout << "\t\tFri-Chicks\n";
		cout << "............ Billing History ...........\n\n";
		stack<Order> tempStack = orderStack;

		if (tempStack.empty())
		{
			cout << "No billing history available." << endl;
			pressToContinue();
			return;
		}

		while (!tempStack.empty())
		{
			Order currentOrder = tempStack.top();
			currentOrder.print2();
			tempStack.pop();
		}
		pressToContinue();
	}

	void TakeOrder()
	{
		system("cls");
		cout << "\t\tFri-Chicks\n";
		cout << ".............. Place Order .............\n\n";
		if (menu1.get_CategoriesList()->getSize() == 0)
		{
			cout << "Menu is Empty!\nPlease add Categories and items in the menu." << endl;
			pressToContinue();
			return;
		}

		ProductsList* cart = new ProductsList();
		ProductsList* temp = NULL;

		cout << "\nCustomer Name: ";
		cin.ignore();
		string name;
		getline(cin, name);

		while (true)
		{
			menu1.Display_menu();

			cout << "========================================================\n\n";

			cout << "Hi " << name << "! What do you want to order? \n(Enter \"x\" when done) " << endl;

			cout << "\n\nSelect Category:\n\n";

			Node<ProductsList*>* curr = menu1.get_CategoriesList()->getHead();

			for (int i = 1; i <= menu1.get_CategoriesList()->getSize(); i++)
			{
				cout << i << ". " << curr->getData()->getCategory() << endl;
				curr = curr->getNextPtr();
			}

			cout << "\nEnter the corresponding number: ";
			string input;
			cin >> input;

			if (input == "x" || input == "X")
				break;
			int c = stoi(input);
			if (c > menu1.get_CategoriesList()->getSize() || c < 1)
			{
				cout << "\nInvalid Input\n";
				pressToContinue();
				continue;
			}

			temp = menu1.get_CategoriesList()->get_Category(c);

			while (true)
			{
				system("CLS");
				cout << "\t\tFri-Chicks\n";
				cout << ".............. Place Order .............\n\n";

				temp->print();
				cout << "--------------------------------------------" << endl;
				cout << "Enter the serial number to add to Cart (Enter \"x\" when done): ";
				string input;
				cin >> input;
				if (input == "x" || input == "X")
					break;
				int c = stoi(input);
				if (c > temp->getSize() || c < 1)
				{
					cout << "Invalid input!\nPlease enter a correct serial number" << endl;
					pressToContinue();
					continue;
				}

				Product p = temp->getProduct(c);
				cart->addProduct(p);
				cout << "\n"
					<< p.getProduct_name() << " Added to Cart Successfully\n";
				pressToContinue();
			}
		}
		if (cart->getSize() == 0)
		{
			cout << "\nYou Haven't Placed Any Order\n";
			delete cart;
			pressToContinue();
			return;
		}
		double bill = GenerateBill(cart);
		Order newOrder(name, ++invoiceNumber, bill, cart);
		orderStack.push(newOrder);
		newOrder.print();
		Compute_Total_Sales();
		saveHistory();
		pressToContinue();

		delete cart;
		return;
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

	void View_Total_Sales()
	{
		system("cls");
		cout << "\t\tFri-Chi cks\n";
		cout << "............... Total Sales ..............\n\n";
		cout << "Total Sales: Rs." << totalSales << endl;
		cout << "Total Number of Products Sold: " << totalProductsSold << endl;
		pressToContinue();
	}

	void refreshData() {
		menu1.loadData();
		loadHistory();
	}

	void exit() {
		delete menu1.get_CategoriesList();
	}

	void loadExistingData() {
		menu1.loadData();
		loadHistory();
	}

	/*
	void MenuManager()
	{
		while (true)
		{
			system("cls");
			cout << "\t\tFri-Chicks\n";
			cout << "............ Menu Management ...........\n\n";

			cout << "1. See Menu \n2. Add Category \n3. Delete Category \n4. Add New Items in Menu \n5. Delete Items from Menu \n6. Go Back" << endl;
			cout << "\nEnter the corresponding number: ";
			char input;
			cin >> input;

			switch (input)
			{
			case '1':
				menu1.Display_menu();
				pressToContinue();
				break;
			case '2':
				menu1.add_Category();
				break;
			case '3':
				menu1.delete_Category();
				break;
			case '4':
				menu1.AddItem();
				break;
			case '5':
				menu1.deleteItem();
				break;
			case '6':
				return;
			default:
				break;
			}
		}
	}
	*/
	/*
	void MainMenu()
	{

		while (true)
		{
			//system("cls");
			cout << "\t\tFri-Chicks\n";
			cout << "........................................\n\n";

			cout << "1. Manage Menu \n2. Take Orders \n3. Billing History \n4. Total Sales \n5. Refresh Data \n6. Exit" << endl;
			cout << "\nEnter the corresponding number: ";

			char input;
			cin >> input;

			switch (input)
			{
			case '1':
				MenuManager();
				break;
			case '2':
				TakeOrder();
				break;
			case '3':
				BillingHistory();
				break;
			case '4':
				View_Total_Sales();
				break;
			case '5':
				refreshData();
				break;
			case '6':
				delete menu1.get_CategoriesList();
				return;
			default:
				break;
			}
		}
	}
	*/

	void pressToContinue()
	{
		cout << "\n\nPress any key to continue...\n\n";
		cin.ignore();
	}
};
