#pragma once
#include "MyForm.h"
#include "msclr/marshal_cppstd.h"

namespace billingSystemGUI {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class takeOrderForm : public System::Windows::Forms::Form
	{
	public:
		Hotel* hotel;
		takeOrderForm(void)
		{
			InitializeComponent();
		}
		takeOrderForm(Hotel* hotel)
		{
			InitializeComponent();
			this->hotel = hotel;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~takeOrderForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ComboBox^ comboBox2;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Label^ label3;








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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(85, 376);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(235, 40);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &takeOrderForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(30, 86);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(356, 28);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->TextChanged += gcnew System::EventHandler(this, &takeOrderForm::comboBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Enabled = false;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(85, 207);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(235, 40);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Add to Cart";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &takeOrderForm::button2_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->Enabled = false;
			this->comboBox2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(30, 158);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(356, 28);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->TextChanged += gcnew System::EventHandler(this, &takeOrderForm::comboBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Enabled = false;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(30, 132);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Select Item";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(30, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Select Category";
			// 
			// listView1
			// 
			this->listView1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->listView1->FullRowSelect = true;
			this->listView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listView1->HideSelection = false;
			this->listView1->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->listView1->Location = System::Drawing::Point(532, 86);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(334, 307);
			this->listView1->TabIndex = 9;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(530, 59);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 22);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Menu: ";
			// 
			// takeOrderForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(901, 446);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"takeOrderForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Add Items to Cart";
			this->Load += gcnew System::EventHandler(this, &takeOrderForm::takeOrderForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void AddCategoriesToComboBox() {
			for (int i = 1; i <= hotel->getMenu().get_CategoriesList()->getSize(); i++) {
				string item = hotel->getMenu().get_CategoriesList()->get_Category(i)->getCategory();
				System::String^ ITEM = msclr::interop::marshal_as<System::String^>(item);
				comboBox1->Items->Add(ITEM);
			}
		}

		void AddItemsToComboBox(String^ category) {
			string categ = msclr::interop::marshal_as<string>(category);
			ProductsList* Category = hotel->getMenu().get_CategoriesList()->get_Category(categ);

			for (int i = 1; i <= Category->getSize(); i++) {
				string item = Category->getProduct(i).getProduct_name();
				System::String^ ITEM = msclr::interop::marshal_as<System::String^>(item);
				comboBox2->Items->Add(ITEM);
			}
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
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void takeOrderForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);


	};
}
