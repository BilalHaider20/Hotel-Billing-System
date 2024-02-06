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
	}
}

