#include "menuManager.h"
#include "MyForm.h"
#include "MenuForm.h"
#include "AddCategoryForm.h"
#include "remCategForm.h"
#include "RemoveItems.h"
#include "AddItems.h"

using namespace System;
using namespace System::Windows::Forms;
namespace billingSystemGUI
{
	class Hotel;
	System::Void menuManager::menuManager_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	System::Void menuManager::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MenuForm^ menuform = gcnew MenuForm(hotel);
		menuform->Show();
		this->Hide();
	}
	System::Void menuManager::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		AddCategoryForm^ categform = gcnew AddCategoryForm(hotel);
		categform->Show();
		this->Hide();
	}
	System::Void menuManager::button3_Click(System::Object^ sender, System::EventArgs^ e) {
		remCategForm^ remcategform = gcnew remCategForm(hotel);
		remcategform->Show();
		this->Hide();

	}
	System::Void menuManager::button4_Click(System::Object^ sender, System::EventArgs^ e) {
		AddItems^ additems = gcnew AddItems(hotel);
		additems->Show();
		this->Hide();
	}

	System::Void menuManager::button5_Click(System::Object^ sender, System::EventArgs^ e) {
		RemoveItems^ removeitems = gcnew RemoveItems(hotel);
		removeitems->Show();
		this->Hide();
	}

	System::Void menuManager::button6_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ mainForm = gcnew MyForm(hotel);
		mainForm->Show();
		this->Close();
	}
}
