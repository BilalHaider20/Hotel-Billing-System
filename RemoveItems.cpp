#include "RemoveItems.h"
#include "MyForm.h"
#include "menuManager.h"
using namespace System;
using namespace System::Windows::Forms;
namespace billingSystemGUI
{
	System::Void RemoveItems::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	System::Void RemoveItems::RemoveItems_Load(System::Object^ sender, System::EventArgs^ e) {
		AddCategoriesToComboBox();

	}

	System::Void RemoveItems::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ categ = comboBox1->Text;
		string category = msclr::interop::marshal_as<string>(categ);
		int index = comboBox2->SelectedIndex + 1;
		hotel->getMenu().deleteItem(category, index);
		MessageBox::Show("Item Removed Successfully!", "Message");
		comboBox2->Items->Clear();
		AddItemsToComboBox(categ);
	}

	System::Void RemoveItems::comboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		button2->Enabled = false;
		if (comboBox1->Text != "") {
			comboBox2->Enabled = true;
			label2->Enabled = true;
			comboBox2->Items->Clear();
			AddItemsToComboBox(comboBox1->Text);
		}
	}
	System::Void RemoveItems::comboBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (comboBox2->Text != "" && comboBox2->Items->Count != 0)
			button2->Enabled = true;
		else
			button2->Enabled = false;
	}

}


