#include "MyForm.h"
#include "menuManager.h"
#include "MenuForm.h"
#include "AddCategoryForm.h"
#include "Cart.h"

using namespace System;
using namespace billingSystemGUI;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Hotel* hotel = new Hotel("Fri-Chicks");
	hotel->loadExistingData();
	MyForm form(hotel);
	Application::Run(% form);

}

namespace billingSystemGUI
{
	System::Void MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	System::Void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		menuManager^ menuManageForm = gcnew menuManager(hotel);
		menuManageForm->ShowDialog();
	}

	System::Void MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Cart^ cart = gcnew Cart(hotel);
		cart->ShowDialog();
	}

	System::Void MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	System::Void MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	System::Void MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e) {
		hotel->refreshData();
		MessageBox::Show("Data Loaded Successfully!", "Message");
	}
	System::Void MyForm::button6_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
}


