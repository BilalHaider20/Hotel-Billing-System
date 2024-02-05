#include "remCategForm.h"
#include "menuManager.h"
using namespace System;
using namespace System::Windows::Forms;
namespace billingSystemGUI
{
	System::Void remCategForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	System::Void remCategForm::remCategForm_Load(System::Object^ sender, System::EventArgs^ e) {
		AddItemsToComboBox();
	}

	System::Void remCategForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {

		int selectedCategoryIndex = comboBox1->SelectedIndex + 1;
		hotel->getMenu().delete_Category(selectedCategoryIndex);
		MessageBox::Show("Category Removed Successfully!", "Message");
		comboBox1->Items->Clear();
		button2->Enabled = false;
		AddItemsToComboBox();
	}
	System::Void remCategForm::comboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->Text != "")
		{
			button2->Enabled = true;
		}
		else
			button2->Enabled = false;


	}

}

