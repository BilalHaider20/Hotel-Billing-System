#include "billingHistoryForm.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
namespace billingSystemGUI
{
	System::Void billingHistoryForm::button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	System::Void billingHistoryForm::billingHistoryForm_Load(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = gcnew String(hotel->BillingHistory().c_str());
		label5->Text = hotel->Get_Total_Products_sold().ToString();
		label6->Text = "Rs."+ (hotel->get_Total_Sales()).ToString();
	}
}

