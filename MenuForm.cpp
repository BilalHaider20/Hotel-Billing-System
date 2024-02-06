#include "MenuForm.h"
#include "MenuManager.h"

using namespace System;
using namespace System::Windows::Forms;
namespace billingSystemGUI
{
	System::Void MenuForm::button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	System::Void MenuForm::MenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
		displayMenu();
	}
}
