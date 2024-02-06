#pragma once

#include <Windows.h>
#include "MyForm.h"
#include "msclr/marshal_cppstd.h"

namespace billingSystemGUI {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for menuManager
	/// </summary>
	/// 
	public ref class Cart : public System::Windows::Forms::Form
	{
	public:
		Hotel* hotel;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ListView^ listView1;

	private: System::Windows::Forms::Label^ label6;
	public:
		Cart()
		{
			InitializeComponent();
		}

		Cart(Hotel* hotel)
		{
			InitializeComponent();
			this->hotel = hotel;
		}
		String^ customerName;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Cart()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;




	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button3->Font = (gcnew System::Drawing::Font(L"Verdana", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(54, 227);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(312, 40);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Empty Cart";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Cart::button3_Click);
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(54, 143);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(312, 36);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add Items to Cart";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Cart::button1_Click);
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Enabled = false;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(54, 185);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(312, 36);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Remove Items from Cart";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Cart::button2_Click);
			// 
			// button6
			// 
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button6->Font = (gcnew System::Drawing::Font(L"Verdana", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(54, 319);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(312, 40);
			this->button6->TabIndex = 4;
			this->button6->Text = L"Back";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Cart::button6_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(516, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 22);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Cart:";
			// 
			// button4
			// 
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button4->Font = (gcnew System::Drawing::Font(L"Verdana", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(54, 273);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(312, 40);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Place Order";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Cart::button4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(515, 395);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Total Bill: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(659, 395);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 20);
			this->label3->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(50, 59);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(141, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Customer Name: ";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(54, 84);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(312, 27);
			this->textBox1->TabIndex = 11;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Cart::textBox1_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(659, 373);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 20);
			this->label5->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(515, 373);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(141, 20);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Customer Name: ";
			// 
			// listView1
			// 
			this->listView1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->listView1->FullRowSelect = true;
			this->listView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listView1->HideSelection = false;
			this->listView1->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->listView1->Location = System::Drawing::Point(519, 69);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(334, 297);
			this->listView1->TabIndex = 14;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &Cart::listView1_SelectedIndexChanged);
			// 
			// Cart
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(901, 446);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Cart";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Place order";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Cart::Cart_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Cart::Cart_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void loadCart() {
			listView1->Items->Clear();


			listView1->Columns->Add("Product", 210);
			listView1->Columns->Add("Price", 100);


			for (int i = 1; i <= hotel->getCart()->getSize(); i++) {
				String^ itemName = gcnew String(hotel->getCart()->getProduct(i).getProduct_name().c_str());
				String^ itemPrice = "Rs. " + hotel->getCart()->getProduct(i).getProduct_price().ToString();

				ListViewItem^ item = gcnew ListViewItem(itemName);
				item->SubItems->Add(itemPrice);
				listView1->Items->Add(item);
			}
		}
#pragma endregion

	private: System::Void Cart_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		customerName = textBox1->Text;
		if (textBox1->Text == " ")
			textBox1->Text = "";
		if (customerName == "")
			customerName = "N/A";
		label5->Text = customerName;
	}
	private: System::Void Cart_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		hotel->emptyCart();
		delete hotel->getCart();
	}
	};
}
