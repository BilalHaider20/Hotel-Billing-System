#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <ctime>
#include <chrono>
#include "productsList.h"
#include "msclr/marshal_cppstd.h"

using namespace std;
using namespace System;

class Order
{
private:
	string customerName;
	int invoiceNumber;
	ProductsList* PurchasedItems;
	double bill;
	int totalItems;
	string dateTime;

public:
	Order(string customerName, int inv, double bill, ProductsList* PurchasedItems)
	{
		this->customerName = customerName;
		this->invoiceNumber = inv;
		this->bill = bill;
		this->PurchasedItems = PurchasedItems;
		this->totalItems = PurchasedItems->getSize();
		auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
		string tempDateTime = ctime(&now);
		if (!tempDateTime.empty())
		{
			dateTime = tempDateTime.substr(0, tempDateTime.size() - 1);
		}
	}

	Order(string customerName, int inv, double bill, int totalItems, ProductsList* PurchasedItems, string dateTime)
	{
		this->customerName = customerName;
		this->invoiceNumber = inv;
		this->bill = bill;
		this->PurchasedItems = PurchasedItems;
		this->totalItems = totalItems;
		this->dateTime = dateTime;
	}



	string getCustomerName() const
	{
		return customerName;
	}

	int getInvoiceNumber() const
	{
		return invoiceNumber;
	}

	ProductsList* GetPurchasedItems() const
	{
		return PurchasedItems;
	}

	double getBill() const
	{
		return bill;
	}

	int getTotalItems() const
	{
		return totalItems;
	}

	string getDateTime() const
	{
		return dateTime;
	}

	void Print_Orders()
	{
		system("CLS");
		cout << "\t\tFri-Chicks\n";
		cout << "................. Invoice ................\n\n";
		cout << "------------------------------------------\n";
		cout << "\nInvoice Number: " << getInvoiceNumber() << endl;
		cout << "Customer Name: " << getCustomerName() << endl;
		cout << "Date and Time: " << dateTime;

		cout << "\n\nItems Purchased\n";
		ProductsList* purchasedItems = GetPurchasedItems();

		cout << "------------------------------------------\n";
		cout << left << setw(5) << "Sr." << setw(25) << "Name"
			<< "Price" << endl;
		cout << "------------------------------------------\n";

		for (int i = 1; i <= purchasedItems->getSize(); ++i)
		{
			Product product = purchasedItems->getProduct(i);
			cout << setw(5) << i << setw(25) << product.getProduct_name() << "Rs. " << product.getProduct_price() << endl;
		}
		cout << "------------------------------------------\n";

		cout << setw(30) << "Total Bill:"
			<< "Rs. " << getBill() << endl;
		cout << setw(30) << "Total Items Purchased: " << getTotalItems() << endl;
		cout << "------------------------------------------\n";
	}

	string print2()
	{
		String^ Bill = getBill().ToString();
		string bill = msclr::interop::marshal_as<string>(Bill);
		string output;
		//output = "\r\n------------------------------------------------------------------\r\n";
		output += "\r\n  Invoice Number: " + to_string(getInvoiceNumber()) + "\r\n";
		output += "  Customer Name: " + getCustomerName() + "\r\n";
		output += "  Date and Time: " + dateTime + "\r\n\r\n";
		output += "  Items Purchased: \r\n";
		for (int i = 1; i <= PurchasedItems->getSize(); i++) {
			output += "     " + PurchasedItems->getProduct(i).getProduct_name() + "\r\n";
		}
		output += "\r\n  Total Items: " + to_string(getTotalItems()) + "\r\n";
		output += "  Total Bill: Rs." + bill + "\r\n\r\n";
		output += " -----------------------------------------------------------------\r\n";
		return output;
	}
};

#endif // ORDER_H
