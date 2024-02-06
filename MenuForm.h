#pragma once
#include "menuManager.h"
namespace billingSystemGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		Hotel* hotel;
		MenuForm(void)
		{
			InitializeComponent();
		}
		MenuForm(Hotel* hotel)
		{
			InitializeComponent();
			this->hotel = hotel;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button6;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListView^ listView1;











	protected:


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
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// button6
			// 
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button6->Font = (gcnew System::Drawing::Font(L"Verdana", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(43, 374);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(334, 40);
			this->button6->TabIndex = 1;
			this->button6->Text = L"Back";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MenuForm::button6_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(41, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 22);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Menu: ";
			// 
			// listView1
			// 
			this->listView1->FullRowSelect = true;
			this->listView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listView1->HideSelection = false;
			this->listView1->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->listView1->Location = System::Drawing::Point(43, 45);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(334, 307);
			this->listView1->TabIndex = 5;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// MenuForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(420, 446);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button6);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MenuForm::MenuForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void displayMenu()
		{
			Categories* categoriesList = hotel->getMenu().get_CategoriesList();
			listView1->Items->Clear();
			listView1->Groups->Clear();

			listView1->Columns->Add("Product", 210);
			listView1->Columns->Add("Price", 100);

			for (int i = 1; i <= categoriesList->getSize(); i++)
			{
				ProductsList* temp = categoriesList->get_Category(i);

				ListViewGroup^ group = gcnew ListViewGroup();
				group->Header = gcnew String(temp->getCategory().c_str());
				listView1->Groups->Add(group);

				for (int j = 1; j <= temp->getSize(); j++)
				{
					String^ product = gcnew String(temp->getProduct(j).getProduct_name().c_str());
					String^ price = "Rs. " + temp->getProduct(j).getProduct_price().ToString();

					ListViewItem^ item = gcnew ListViewItem(product);
					item->SubItems->Add(price);
					item->Group = group;
					listView1->Items->Add(item);
				}
			}
		}

#pragma endregion
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MenuForm_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void MenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	}

	};
}
