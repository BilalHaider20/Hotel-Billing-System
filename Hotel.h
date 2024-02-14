#include <iostream>
#include <stack>
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <algorithm>
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
	void saveHistory() const {
	ofstream outputFile(HISTORY);

	if (!outputFile.is_open()) {
		//	cerr << "\nError opening file!" << endl;
		return;
	}

	stack<Order> tempStack = orderStack;
	while (!tempStack.empty()) {
		Order currentOrder = tempStack.top();
		double bill = currentOrder.getBill();
		string name = currentOrder.getCustomerName();
		int invNumber = currentOrder.getInvoiceNumber();
		int totalItems = currentOrder.getTotalItems();
		string dateTime = currentOrder.getDateTime();
		string quantity = "";
		vector<double> quantities = currentOrder.get_Quantities();
		ProductsList* p = currentOrder.GetPurchasedItems();
		string prods = "";

		// Serialize quantities with one zero after decimal point
		for (double Q : quantities) {
			string formattedQuantity = to_string(Q);
			size_t decimalPointPos = formattedQuantity.find('.');
			if (decimalPointPos != string::npos && formattedQuantity.size() - decimalPointPos > 2) {
				formattedQuantity = formattedQuantity.substr(0, decimalPointPos + 2);
			}
			quantity += formattedQuantity + "#";
		}

		Node<Product>* curr = p->getHead();
		while (curr != nullptr) {
			string Pname = curr->getData().getProduct_name();
			for (char& c : Pname) {
				if (c == ' ') {
					c = '_';
				}
			}

			prods += (Pname + "*" + to_string(curr->getData().getProduct_price()) + "-");
			curr = curr->getNextPtr();
		}

		// Replace spaces with underscores in name and dateTime
		replace(name.begin(), name.end(), ' ', '_');
		replace(dateTime.begin(), dateTime.end(), ' ', '_');

		outputFile << name << " " << invNumber << " " << fixed << setprecision(1) << bill << " " << totalItems << " " << totalSales << " " << totalProductsSold << " " << prods << " " << quantity << " " << dateTime << endl;

		tempStack.pop();
	}

	outputFile.close();
}



	void loadHistory()
	{
		string name, prods, dateTime;
		double bill;
		int invNumber, totalItems;

		string tempQ;
		ifstream inputFile(HISTORY);

		if (!inputFile.is_open())
		{
			return;
		}

		// Clear the existing order stack
		while (!orderStack.empty())
		{
			orderStack.pop();
		}

		while (inputFile >> name >> invNumber >> bill >> totalItems >> totalSales >> totalProductsSold >> prods >> tempQ >> dateTime)
		{
			// Replace underscores with spaces in name and dateTime
			replace(name.begin(), name.end(), '_', ' ');
			replace(dateTime.begin(), dateTime.end(), '_', ' ');

			vector<double> quantities;
			stringstream qStream(tempQ);
			string qStr;
			while (getline(qStream, qStr, '#'))
			{
				quantities.push_back(stod(qStr));
			}

			// Replace underscores with spaces in product names
			replace(prods.begin(), prods.end(), '_', ' ');

			// Create a new ProductsList for purchased items
			ProductsList* productsPurchased = new ProductsList();

			// Parse the products string
			stringstream prodStream(prods);
			string productInfo;
			while (getline(prodStream, productInfo, '-'))
			{
				stringstream prodInfoStream(productInfo);
				string productName, tempPrice;

				getline(prodInfoStream, productName, '*');
				getline(prodInfoStream, tempPrice, '*');

				replace(productName.begin(), productName.end(), '_', ' ');

				double productPrice = stod(tempPrice);

				productsPurchased->addProduct(productName, productPrice);
			}

			// Push the order onto the order stack
			orderStack.push(Order(name, invNumber, bill, totalItems, productsPurchased, dateTime, quantities));
		}

		inputFile.close();
	}


	stack<Order> get_Order_Stack()
	{
		return this->orderStack;
	}
	
	vector<double> get_Quantities()
	{
		return this->quantities;
	}
	double get_Quantities(int i)
	{
		return this->quantities[i];
	}
	string BillingHistory()
	{
		loadHistory();
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
		int quantityIndex = ind - 1;
		if (quantityIndex >= 0 && quantityIndex < quantities.size()) {
			quantities.erase(quantities.begin() + quantityIndex);
		}
		else {
			// Handle invalid index or empty quantities vector
		}
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
		if(!quantities.empty())
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
		double totalSales = 0;
		int totalProductsSold = 0;

		while (!tempStack.empty()) {
			Order obj = tempStack.top();
			totalSales += obj.getBill();
			totalProductsSold += obj.getTotalItems();
			tempStack.pop();
		}

		this->totalSales = totalSales;
		this->totalProductsSold = totalProductsSold;
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
