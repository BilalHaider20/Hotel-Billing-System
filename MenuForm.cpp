#include "MenuForm.h"
#include "MenuManager.h"

using namespace System;
using namespace System::Windows::Forms;
namespace billingSystemGUI
{
	System::Void MenuForm::button6_Click(System::Object^ sender, System::EventArgs^ e) {
		menuManager^ menumanage = gcnew menuManager(hotel);
		menumanage->Show();
		this->Close();
	}
	System::Void MenuForm::MenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (hotel != nullptr)
			menuLabel->Text = gcnew String((hotel->getMenu().Display_menu()).c_str());
	}
}
