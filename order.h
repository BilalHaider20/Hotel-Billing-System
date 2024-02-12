#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <ctime>
#include <chrono>
#include "productsList.h"
#include <sstream> 
#include <iomanip>
#include <vector>
using namespace std;

class Order
{
private:
	string customerName;
	int invoiceNumber;
	ProductsList* PurchasedItems;
	vector<double> quantities;
	double bill;
	int totalItems;
	string dateTime;

public:
	Order(string customerName, int inv, double bill, ProductsList* PurchasedItems, vector<double> quantities)
	{
		this->customerName = customerName;
		this->invoiceNumber = inv;
		this->bill = bill;
		this->PurchasedItems = PurchasedItems;
		this->totalItems = PurchasedItems->getSize();
		this->quantities = quantities;
		this->dateTime = getCurrentDateTime();
	}

	Order(string customerName, int inv, double bill, int totalItems, ProductsList* PurchasedItems, string dateTime, vector<double> quantities)
	{
		this->customerName = customerName;
		this->invoiceNumber = inv;
		this->bill = bill;
		this->PurchasedItems = PurchasedItems;
		this->totalItems = totalItems;
		this->quantities = quantities;
		this->dateTime = dateTime;
	}


	string getCurrentDateTime() {
		auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
		stringstream ss;
		tm timeinfo = *localtime(&now);
		char buffer[80];
		strftime(buffer, sizeof(buffer), "%m-%d-%Y %H:%M", &timeinfo); 
		ss << buffer;
		return ss.str();
	}
	vector<double> get_Quantities()
	{
		return this->quantities;
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

	string print2()
	{
		string output;
		output = "\r\n----------------------------------------------------------\r\n";
		output += "Customer Name: " + getCustomerName() + "\r\n";
		output += "Invoice Number: " + to_string(getInvoiceNumber()) + "\r\n";
		output += "Date and Time: " + dateTime;

		output += "\r\nTotal Items Purchased: " + to_string(getTotalItems()) + "\r\n";
		ostringstream oss;
		oss << fixed << setprecision(1) << getBill();
		output += "Total Bill: Rs." + oss.str() + "\r\n";
		output += "----------------------------------------------------------\r\n";
		return output;
	}
};

#endif // ORDER_H
