#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <ctime>
#include <chrono>
#include "productsList.h"
#include "msclr/marshal_cppstd.h"

#include <sstream> 
#include <iomanip>
#include <vector>
using namespace std;
using namespace System;

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
		this->totalItems = get_Quantities_size();
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



	std::string getCurrentDateTime() {
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::stringstream ss;
		tm timeinfo;
		localtime_s(&timeinfo, &now); // Use localtime_s instead of localtime
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
	int get_Quantities_size()
	{
		int sum = 0;
		for (double i : quantities)
			sum = sum + static_cast<int>(i);
		return sum;
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
		return this->totalItems;
	}

	string getDateTime() const
	{
		return dateTime;
	}

	string print2()
	{
		String^ Bill = getBill().ToString();
		string bill = msclr::interop::marshal_as<string>(Bill);
		string output;
		output = "\r\n------------------------------------------------------------------\r\n";
		output += "  Customer Name: " + getCustomerName() + "\r\n";
		output += "\r\n  Invoice Number: " + to_string(getInvoiceNumber()) + "\r\n";
		output += "  Date and Time: " + dateTime + "\r\n\r\n";
		output += "  Items Purchased:\r\n";
		for (int i = 1; i <= PurchasedItems->getSize(); i++) {
			int quantityIndex = i - 1; 
			output += " " + to_string(i) + "-";
			output += " " + PurchasedItems->getProduct(i).getProduct_name() + "   ";
			output += to_string(quantities[quantityIndex]) + "\r\n";
		}
		output += "\r\n  Total Items: " + to_string(this->get_Quantities_size()) + "\r\n";
		output += "  Total Bill: Rs. " + bill + "\r\n\r\n";
		output += " ----------------------------------------------------------------\r\n";
		return output;
	}
};

#endif // ORDER_H
