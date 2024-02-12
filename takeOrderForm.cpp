#include "takeOrderForm.h"
#include "MyForm.h"
#include "menuManager.h"


using namespace System;
using namespace System::Windows::Forms;

namespace billingSystemGUI
{
	System::Void takeOrderForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	System::Void takeOrderForm::takeOrderForm_Load(System::Object^ sender, System::EventArgs^ e) {
		AddCategoriesToComboBox();
		displayMenu();
	}

	System::Void takeOrderForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ categ = comboBox1->Text;
		int categIndex = comboBox1->SelectedIndex + 1;
		int prodIndex = comboBox2->SelectedIndex + 1;
		double quantity = Convert::ToDouble(textBox1->Text);
		hotel->addItemsToCart(categIndex, prodIndex,quantity);
		MessageBox::Show("Item Added to Cart Successfully!", "Message");
		button2->Enabled = false;
		textBox1->Enabled = false;
		textBox1->Text ="";
		label4->Enabled = false;
		comboBox2->Items->Clear();
		AddItemsToComboBox(categ);
	}

	System::Void takeOrderForm::comboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		button2->Enabled = false;
		if (comboBox1->Text != "") {
			comboBox2->Enabled = true;
			label2->Enabled = true;
			comboBox2->Items->Clear();
			AddItemsToComboBox(comboBox1->Text);
		}
	}
	System::Void takeOrderForm::comboBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (comboBox2->Text != "" && comboBox2->Items->Count != 0)
		{
			textBox1->Enabled = true;
			label4->Enabled = true;
		}
		else
		{
			label4->Enabled = false;
			textBox1->Enabled = false;
		}
	}

	System::Void takeOrderForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text != "")
			button2->Enabled = true;
		else
			button2->Enabled = false;
	}

}

