#include <iostream>
#include <conio.h>
#include "categories.h"
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

class menu
{
private:
	string MENU = "menu_data";
	Categories* categoriesList = new Categories;

public:
	menu() {}
	void saveData()
	{
		ofstream outputFile(MENU);

		if (!outputFile.is_open())
		{
			return;
		}

		for (int i = 1; i <= categoriesList->getSize(); i++)
		{
			ProductsList* temp = categoriesList->get_Category(i);
			for (int j = 1; j <= temp->getSize(); j++)
			{
				string categ = temp->getCategory();
				string name = temp->getProduct(j).getProduct_name();
				for (int m = 0; m < categ.size(); m++)
				{
					if (categ[m] == ' ')
						categ[m] = '_';
				}
				for (int n = 0; n < name.size(); n++)
				{
					if (name[n] == ' ')
						name[n] = '_';
				}
				outputFile << categ << " " << name << " " << temp->getProduct(j).getProduct_price() << " " << endl;
			}
		}
		outputFile.close();
	}

	void loadData()
	{
		string categName;
		string prodName;
		int prodPrice;
		ifstream inputFile(MENU);
		categoriesList->emptyMenu();

		if (!inputFile.is_open())
		{
			return;
		}

		while (inputFile >> categName >> prodName >> prodPrice)
		{
			for (char& c : categName)
			{
				if (c == '_')
					c = ' ';
				c = toupper(c);
			}
			for (char& c : prodName)
			{
				if (c == '_')
					c = ' ';
			}

			if (!categoriesList->categoryExists(categName))
			{
				categoriesList->addCategory(categName);
			}

			ProductsList* temp = categoriesList->get_Category(categName);

			temp->addProduct(prodName, prodPrice);
		}

		inputFile.close();
		inputFile.clear();
	}

	void add_Category(string category)
	{
		for (char& c : category)
		{
			c = toupper(c);
		}
		categoriesList->addCategory(category);
		saveData();
	}

	void delete_Category(int ind)
	{
		categoriesList->deleteCategory(ind);
		saveData();

	}

	Categories* get_CategoriesList()
	{
		return categoriesList;
	}

	void AddItem(int categInd, string ItemName, double price)
	{
		ProductsList* temp;
		temp = categoriesList->get_Category(categInd);
		temp->addProduct(ItemName, price);
		saveData();
	}

	void deleteItem(string categ, int ind)
	{
		ProductsList* temp;
		temp = categoriesList->get_Category(categ);
		temp->deleteProduct(ind);
		saveData();
	}

	string Display_menu()
	{
		if (categoriesList->getSize() == 0)
		{
			return "\r\nMenu is empty";
		}
		return categoriesList->Print();

	}
};