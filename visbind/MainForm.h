#pragma once
#include "TestBitmapForm.h"
#include "TestImgPartForm.h"
#include "TestConvolutionForm.h"
#include "TestImgCmpForm.h"

namespace visbind {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Reflection;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
#pragma region Windows Form Designer generated code
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	protected:

	protected:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 24);
			this->button1->TabIndex = 0;
			this->button1->Text = L"test bmpcmp class";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 42);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 24);
			this->button2->TabIndex = 1;
			this->button2->Text = L"test imgpart";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 72);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(108, 24);
			this->button3->TabIndex = 2;
			this->button3->Text = L"test convolution";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 102);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(108, 24);
			this->button4->TabIndex = 3;
			this->button4->Text = L"test img cmp";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(127, 141);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"test bitmap";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	
		
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {	
		(gcnew Threading::Thread(gcnew Threading::ThreadStart(gcnew TestBitmapForm, &TestBitmapForm::Run)))->Start();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		(gcnew Threading::Thread(gcnew Threading::ThreadStart(gcnew TestImgPartForm, &TestImgPartForm::Run)))->Start();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		(gcnew Threading::Thread(gcnew Threading::ThreadStart(gcnew TestConvolutionForm, &TestConvolutionForm::Run)))->Start();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		(gcnew Threading::Thread(gcnew Threading::ThreadStart(gcnew TestImgCmpForm, &TestImgCmpForm::Run)))->Start();
	}

	};
}
