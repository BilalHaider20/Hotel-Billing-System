#include "Cart.h"
#include "menuManager.h"
#include "takeOrderform.h"
#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;
namespace billingSystemGUI

{
	System::Void Cart::Cart_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	System::Void Cart::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		takeOrderForm^ takeOrder = gcnew takeOrderForm(hotel);
		takeOrder->ShowDialog();

	}
	System::Void Cart::button2_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	System::Void Cart::button3_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	System::Void Cart::button4_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	System::Void Cart::button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
}

