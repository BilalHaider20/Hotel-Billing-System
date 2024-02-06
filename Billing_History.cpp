#include "Billing_History.h"
#include "Hotel.h"

using namespace System;
using namespace System::Windows::Forms;
namespace billingSystemGUI
{
	System::Void Billing_History::button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	System::Void Billing_History::MenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (hotel != nullptr)
			menuLabel->Text = gcnew String((hotel->BillingHistory()).c_str());
	}
}
