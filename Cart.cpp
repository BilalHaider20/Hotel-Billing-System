#include "Cart.h"
#include "menuManager.h"
#include "takeOrderform.h"
#include "MyForm.h"
#include "msclr/marshal_cppstd.h"


using namespace System;
using namespace System::Windows::Forms;
namespace billingSystemGUI

{
	System::Void Cart::Cart_Load(System::Object^ sender, System::EventArgs^ e) {
		hotel->takeOrder();
		label3->Text = "Rs. 0";
		customerName = "N/A";
		label5->Text = customerName;
		hotel->emptyCart(); //clear previous data
	}

	System::Void Cart::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		takeOrderForm^ takeOrder = gcnew takeOrderForm(hotel);
		takeOrder->ShowDialog();
		loadCart();
		label3->Text = "Rs. " + hotel->GenerateBill().ToString();
		button2->Enabled = false;
	}

	System::Void Cart::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int prodIndex = listView1->SelectedIndices[0] + 1;
		hotel->removeItemsFromCart(prodIndex);
		loadCart();
		label3->Text = "Rs. " + hotel->GenerateBill().ToString();
		MessageBox::Show("Item Removed from Cart Successfully!", "Message");
		button2->Enabled = false;
	}

	System::Void Cart::button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (hotel->getCart()->getSize() == 0) {
			MessageBox::Show("Cart is already empty!", "Message");
		}
		else {
			hotel->emptyCart();
			loadCart();
			label3->Text = "Rs. " + hotel->GenerateBill().ToString();
			MessageBox::Show("Successfully Emptied the Cart!", "Message");
			button2->Enabled = false;
		}
	}

	System::Void Cart::button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (hotel->getCart()->getSize() == 0) {
			MessageBox::Show("Select some items first before placing order", "Message");
		}
		else {
			string name = msclr::interop::marshal_as<string>(customerName->ToString());
			hotel->placeOrder(name);
			MessageBox::Show("Your order has been placed!", "Message");
			textBox1->Text = "";
			loadCart();
			label5->Text = customerName;
			label3->Text = "Rs. " + hotel->GenerateBill().ToString();
			button2->Enabled = false;
		}
	}

	System::Void Cart::button6_Click(System::Object^ sender, System::EventArgs^ e) {
		hotel->emptyCart();
		this->Close();
	}
	System::Void Cart::listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (listView1->SelectedIndices->Count > 0) {
			button2->Enabled = true;
		}
		else
		{
			button2->Enabled = false;
		}
	}
}

