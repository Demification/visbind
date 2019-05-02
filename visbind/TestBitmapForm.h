#pragma once
#include "resource.h"
#include "../sys/pixbit.h"
#include <Windows.h>
#include "support.h"

namespace visbind {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class TestBitmapForm : public System::Windows::Forms::Form
	{
#pragma region Windows Form Designer generated code
	public:
		TestBitmapForm(void)
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
		~TestBitmapForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>



		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(270, 154);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(12, 172);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(270, 154);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(288, 172);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(270, 154);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(564, 172);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(270, 154);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(355, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &TestBitmapForm::timer1_Tick);
			// 
			// TestBitmapForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 333);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"TestBitmapForm";
			this->Text = L"TestBitmapForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TestBitmapForm::TestBitmapForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &TestBitmapForm::TestBitmapForm_Load);
			this->Shown += gcnew System::EventHandler(this, &TestBitmapForm::TestBitmapForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	public: System::Void Run() {
		ShowDialog();
	}

	private: pixbit::bitmap *tsimg;
	private: pixbit::bmpcmp *tsbmpcmp;
	private: System::Void TestBitmapForm_Load(System::Object^  sender, System::EventArgs^  e) {
		tsimg = new pixbit::bitmap;
		tsimg->initAndLoad(IDB_BITMAP1);
		pictureBox1->Image = support::copyArgbArrayToBitmapArgb(tsimg->get0ptr(), tsimg->max_width, tsimg->max_height);
	}
	private: System::Void TestBitmapForm_Shown(System::Object^  sender, System::EventArgs^  e) {
		tsbmpcmp = new pixbit::bmpcmp;
		tsbmpcmp->init(tsimg->width, tsimg->height);
		tsbmpcmp->load8bpp(tsimg);
		
		//tsbmpcmp->load8bppgrey();

		pictureBox2->Image = support::copy8bppArrayToBitmapArgb(tsbmpcmp->b8bpp, tsimg->width, tsimg->height, 0);
		pictureBox3->Image = support::copy8bppArrayToBitmapArgb(tsbmpcmp->g8bpp, tsimg->width, tsimg->height, 1);
		pictureBox4->Image = support::copy8bppArrayToBitmapArgb(tsbmpcmp->r8bpp, tsimg->width, tsimg->height, 2);
	}
	private: System::String^ textLabel;
	private: System::Void setLabelText(){
		label1->Text = textLabel;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		POINT p;
		COLORREF color;
		HDC hDC;
	
		hDC = GetDC(NULL);
		GetCursorPos(&p);
		color = GetPixel(hDC, p.x, p.y);

		byte red = GetRValue(color);
		byte green = GetGValue(color);
		byte blue = GetBValue(color);

		textLabel = red.ToString() + L":" + green.ToString() + L":" + blue.ToString();
		if(timer1->Enabled)this->Invoke(gcnew Action(this, &TestBitmapForm::setLabelText));
		ReleaseDC(GetDesktopWindow(), hDC);
	}
	private: System::Void TestBitmapForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		timer1->Stop();
		delete timer1;
		Application::DoEvents();
	}
	};
}
