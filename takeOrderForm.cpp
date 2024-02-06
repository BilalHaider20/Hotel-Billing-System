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
	}

	System::Void takeOrderForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ categ = comboBox1->Text;
		int categIndex = comboBox1->SelectedIndex + 1;
		int prodIndex = comboBox2->SelectedIndex + 1;
		hotel->addItemsToCart(categIndex, prodIndex);
		MessageBox::Show("Item Added to Cart Successfully!", "Message");

		button2->Enabled = false;
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
			button2->Enabled = true;
		else
			button2->Enabled = false;
	}

}

