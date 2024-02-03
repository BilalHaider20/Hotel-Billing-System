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
	public ref class RemoveItems : public System::Windows::Forms::Form
	{
	public:
		Hotel* hotel;
		RemoveItems(void)
		{
			InitializeComponent();
		}
		RemoveItems(Hotel* hotel)
		{
			InitializeComponent();
			this->hotel = hotel;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RemoveItems()
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
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
			this->button1->Click += gcnew System::EventHandler(this, &RemoveItems::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(30, 76);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(356, 28);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->TextChanged += gcnew System::EventHandler(this, &RemoveItems::comboBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Enabled = false;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(85, 197);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(235, 40);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Remove";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &RemoveItems::button2_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->Enabled = false;
			this->comboBox2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(30, 148);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(356, 28);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->TextChanged += gcnew System::EventHandler(this, &RemoveItems::comboBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(30, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Select Category";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Enabled = false;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(30, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Select Item";
			// 
			// RemoveItems
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(420, 446);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"RemoveItems";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Remove Items";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &RemoveItems::RemoveItems_FormClosing);
			this->Load += gcnew System::EventHandler(this, &RemoveItems::RemoveItems_Load);
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


#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void RemoveItems_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void comboBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void RemoveItems_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {

		//Application::Exit();
	}
	};
}
