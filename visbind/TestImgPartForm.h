#pragma once
#include "../sys/pixbit.h"
#include "../sys/allocator.h"
#include "../sys/test.h"
#include "..//sys/imgpart.h"
#include "..//sys/convolution.h"

#include "support.h"
#include "resource.h"

namespace visbind {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class TestImgPartForm : public System::Windows::Forms::Form
	{
#pragma region Windows Form Designer generated code
	public:
		TestImgPartForm(void)
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
		~TestImgPartForm()
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
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;



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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(8, 9);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(240, 135);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(252, 9);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(240, 135);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(8, 150);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(322, 279);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(336, 150);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(322, 279);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(664, 150);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(322, 279);
			this->pictureBox5->TabIndex = 4;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(8, 435);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(322, 279);
			this->pictureBox6->TabIndex = 5;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(336, 435);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(322, 279);
			this->pictureBox7->TabIndex = 6;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Location = System::Drawing::Point(664, 435);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(322, 279);
			this->pictureBox8->TabIndex = 7;
			this->pictureBox8->TabStop = false;
			// 
			// TestImgPartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(997, 699);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"TestImgPartForm";
			this->Text = L"TestImgPartForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &TestImgPartForm::TestImgPartForm_FormClosed);
			this->Shown += gcnew System::EventHandler(this, &TestImgPartForm::TestImgPartForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: pixbit::bitmap *tsimg;
			 pixbit::bmpcmp *tsbmpcmp;

			 const int tic_w = 240;
			 const int tic_h = 135;
			
				
	public: System::Void Run() {
		ShowDialog();
	}
	private: System::Void TestImgPartForm_Shown(System::Object^  sender, System::EventArgs^  e) {
		pictureBox1->Width = tic_w;
		pictureBox1->Height = tic_h;

		tsimg = new pixbit::bitmap;
		tsbmpcmp = new pixbit::bmpcmp;

		tsimg->initAndLoad(IDB_BITMAP1);
		pictureBox1->Image = support::ResizeImage(support::copyArgbArrayToBitmapArgb(tsimg->get0ptr(), tsimg->max_width, tsimg->max_height), tic_w, tic_h);
		pictureBox1->Update();
		Application::DoEvents();

		tsimg->destroy();
		tsimg->init(pictureBox1->Width, pictureBox1->Height);
		tsimg->load((HWND)pictureBox1->Handle.ToPointer(), 0, 0, pictureBox1->Width, pictureBox1->Height);
		
		tsbmpcmp->init(tsimg->width, tsimg->height);
		tsbmpcmp->load8bpp(tsimg);
		tsbmpcmp->load8bppgrey();

		pictureBox2->Image = support::copyGrey8bppArrayToBitmapArgb(tsbmpcmp->grey8bpp, tic_w, tic_h);
		pictureBox2->Update();
		Application::DoEvents();

		tsimg->clear(); //random crush
		tsimg->load((HWND)pictureBox2->Handle.ToPointer(), 0, 0, tic_w, tic_h);

		tsbmpcmp->destroy();
		tsbmpcmp->init(tsimg->width, tsimg->height);
		tsbmpcmp->load8bpp(tsimg);
		tsbmpcmp->load8bppgrey();

		imgpart ic3x3s1;
		ic3x3s1.init(edge2d::edge3x3, edge2d_step::x1, (int)tsbmpcmp->max_width, (int)tsbmpcmp->max_height);
		ic3x3s1.preload(tsbmpcmp->grey8bpp);
		ic3x3s1.load();
		ic3x3s1.print((HWND)pictureBox3->Handle.ToPointer());
		ic3x3s1.destroy();

		imgpart ic3x3s2;
		ic3x3s2.init(edge2d::edge3x3, edge2d_step::x2, (int)tsbmpcmp->max_width, (int)tsbmpcmp->max_height);
		ic3x3s2.preload(tsbmpcmp->grey8bpp);
		ic3x3s2.load();
		ic3x3s2.print((HWND)pictureBox4->Handle.ToPointer());
		ic3x3s2.destroy();

		imgpart ic3x3s3;
		ic3x3s3.init(edge2d::edge3x3, edge2d_step::x3, (int)tsbmpcmp->max_width, (int)tsbmpcmp->max_height);
		ic3x3s3.preload(tsbmpcmp->grey8bpp);
		ic3x3s3.load();
		ic3x3s3.print((HWND)pictureBox5->Handle.ToPointer());
		ic3x3s3.destroy();

		imgpart ic5x5s1;
		ic5x5s1.init(edge2d::edge5x5, edge2d_step::x1, (int)tsbmpcmp->max_width, (int)tsbmpcmp->max_height);
		ic5x5s1.preload(tsbmpcmp->grey8bpp);
		ic5x5s1.load();
		ic5x5s1.print((HWND)pictureBox6->Handle.ToPointer());
		ic5x5s1.destroy();

		imgpart ic5x5s2;
		ic5x5s2.init(edge2d::edge5x5, edge2d_step::x3, (int)tsbmpcmp->max_width, (int)tsbmpcmp->max_height);
		ic5x5s2.preload(tsbmpcmp->grey8bpp);
		ic5x5s2.load();
		ic5x5s2.print((HWND)pictureBox7->Handle.ToPointer());
		ic5x5s2.destroy();

		imgpart ic5x5s3;
		ic5x5s3.init(edge2d::edge5x5, edge2d_step::x5, (int)tsbmpcmp->max_width, (int)tsbmpcmp->max_height);
		ic5x5s3.preload(tsbmpcmp->grey8bpp);
		ic5x5s3.load();
		ic5x5s3.print((HWND)pictureBox8->Handle.ToPointer());
		ic5x5s3.destroy();

	}

	private: System::Void TestImgPartForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	if (tsimg)
	{
		tsimg->destroy();
		delete tsimg;
	}
	if (tsbmpcmp)
	{
		tsbmpcmp->destroy();
		delete tsbmpcmp;
	}


	}
	};
}
