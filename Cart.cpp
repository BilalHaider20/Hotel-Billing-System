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
		label5->Text = "N/A";
		label3->Text = "Rs. 0";
	}

	System::Void Cart::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		takeOrderForm^ takeOrder = gcnew takeOrderForm(hotel);
		takeOrder->ShowDialog();
		listBox1->Items->Clear();
		loadCart();
		label3->Text = "Rs. " + hotel->GenerateBill().ToString();
		button2->Enabled = false;
	}

	System::Void Cart::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int prodIndex = listBox1->SelectedIndex + 1;
		hotel->removeItemsFromCart(prodIndex);
		MessageBox::Show("Item Removed from Cart Successfully!", "Message");
		listBox1->Items->Clear();
		loadCart();
		label3->Text = "Rs. " + hotel->GenerateBill().ToString();
		button2->Enabled = false;
	}

	System::Void Cart::button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (hotel->getCart()->getSize() == 0) {
			MessageBox::Show("Cart is already empty!", "Message");
		}
		else {
			hotel->emptyCart();
			MessageBox::Show("Successfully Emptied the Cart!", "Message");
			listBox1->Items->Clear();
			loadCart();
			label3->Text = "Rs. " + hotel->GenerateBill().ToString();
			button2->Enabled = false;
		}
	}

	System::Void Cart::button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (hotel->getCart()->getSize() == 0) {
			MessageBox::Show("Select some items first before placing order", "Message");
		}
		else {
			String^ Name = customerName;
			string name = msclr::interop::marshal_as<string>(Name);
			hotel->placeOrder(name);
			MessageBox::Show("Your order has been placed!", "Message");
			textBox1->Text = "";
			listBox1->Items->Clear();
			loadCart();
			label5->Text = customerName;
			label3->Text = "Rs. " + hotel->GenerateBill().ToString();
			button2->Enabled = false;
		}
	}

	System::Void Cart::button6_Click(System::Object^ sender, System::EventArgs^ e) {
		hotel->emptyCart();
		delete hotel->getCart();
		this->Close();
	}
	System::Void Cart::listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (listBox1->SelectedIndex != -1) {
			button2->Enabled = true;
		}
		else
		{
			button2->Enabled = false;
		}
	}
}

