#include "AddCategoryForm.h"
#include "menuManager.h"
using namespace System;
using namespace System::Windows::Forms;
namespace billingSystemGUI
{
	System::Void AddCategoryForm::button6_Click(System::Object^ sender, System::EventArgs^ e) {
		menuManager^ menumanage = gcnew menuManager(hotel);
		menumanage->Show();
		this->Close();
	}
	System::Void AddCategoryForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ input = textBox1->Text;
		string inp = msclr::interop::marshal_as<string>(input);
		hotel->getMenu().add_Category(inp);
		MessageBox::Show("Category Added Successfully!", "Message");
		textBox1->Text = "";
	}
	System::Void AddCategoryForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == " ") {
			textBox1->Text = "";
		}
		if (textBox1->Text != "")
					button2->Enabled = true;
		else
					button2->Enabled = false;


	}
}
