#include "AddItems.h"
#include "MyForm.h"
#include "menuManager.h"
using namespace System;
using namespace System::Windows::Forms;
namespace billingSystemGUI
{
	System::Void AddItems::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	System::Void AddItems::AddItems_Load(System::Object^ sender, System::EventArgs^ e) {
		AddCategoriesToComboBox();

	}

	System::Void AddItems::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int categInd = comboBox1->SelectedIndex + 1;
		String^ Item = textBox1->Text;
		string item = msclr::interop::marshal_as<string>(Item);
		double price = Convert::ToDouble(textBox2->Text);
		hotel->getMenu().AddItem(categInd, item, price);
		MessageBox::Show("Item Added Successfully!", "Message");
		textBox1->Text = "";
		textBox2->Text = "";
	}

	System::Void AddItems::comboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		button2->Enabled = false;
		if (comboBox1->Text != "") {
			textBox1->Enabled = true;
			label2->Enabled = true;
		}
	}

	System::Void AddItems::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == " ") {
			textBox1->Text = "";
		}
		if (textBox1->Text != "")
		{
			textBox2->Enabled = true;
			label3->Enabled = true;
		}
		else
		{
			label3->Enabled = false;
			textBox2->Enabled = false;
		}
	}

	System::Void AddItems::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->Text == " ") {
			textBox2->Text = "";
		}
		if (textBox2->Text != "")
			button2->Enabled = true;
		else
			button2->Enabled = false;
	}


}



