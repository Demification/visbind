#pragma once
#include "../sys/convolution.h"
#include "support.h"

namespace visbind {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ TestConvolutionForm
	/// </summary>
	public ref class TestConvolutionForm : public System::Windows::Forms::Form
	{
	public:
		TestConvolutionForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
#pragma region Windows Form Designer generated code
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~TestConvolutionForm()
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
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::Windows::Forms::PictureBox^  pictureBox11;
	private: System::Windows::Forms::PictureBox^  pictureBox12;
	private: System::Windows::Forms::PictureBox^  pictureBox13;
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
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(94, 89);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(12, 107);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(839, 25);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;

			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(12, 133);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(839, 25);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(12, 159);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(839, 25);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(12, 206);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(839, 25);
			this->pictureBox5->TabIndex = 4;
			this->pictureBox5->TabStop = false;

			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(12, 233);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(839, 25);
			this->pictureBox6->TabIndex = 5;
			this->pictureBox6->TabStop = false;

			// 
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(12, 261);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(839, 25);
			this->pictureBox7->TabIndex = 6;
			this->pictureBox7->TabStop = false;

			// 
			// pictureBox8
			// 
			this->pictureBox8->Location = System::Drawing::Point(12, 308);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(839, 25);
			this->pictureBox8->TabIndex = 7;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Location = System::Drawing::Point(12, 335);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(839, 25);
			this->pictureBox9->TabIndex = 8;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Location = System::Drawing::Point(12, 362);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(839, 25);
			this->pictureBox10->TabIndex = 9;
			this->pictureBox10->TabStop = false;

			// 
			// pictureBox11
			// 
			this->pictureBox11->Location = System::Drawing::Point(12, 406);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(839, 25);
			this->pictureBox11->TabIndex = 10;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->Location = System::Drawing::Point(12, 434);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(839, 25);
			this->pictureBox12->TabIndex = 11;
			this->pictureBox12->TabStop = false;
			// 
			// pictureBox13
			// 
			this->pictureBox13->Location = System::Drawing::Point(12, 462);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(839, 25);
			this->pictureBox13->TabIndex = 12;
			this->pictureBox13->TabStop = false;
			// 
			// TestConvolutionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(461, 499);
			this->Controls->Add(this->pictureBox13);
			this->Controls->Add(this->pictureBox12);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"TestConvolutionForm";
			this->Text = L"TestConvolutionForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TestConvolutionForm::TestConvolutionForm_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &TestConvolutionForm::TestConvolutionForm_Shown);
			this->Click += gcnew System::EventHandler(this, &TestConvolutionForm::TestConvolutionForm_Click);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &TestConvolutionForm::TestConvolutionForm_MouseMove);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: System::Void Run() {
		ShowDialog();
	}

	private: System::Void TestConvolutionForm_Shown(System::Object^  sender, System::EventArgs^  e) {
		Application::DoEvents();

		{
			convolution<edge2d::edge3x3> cn3x3;
			cn3x3.addLineAll2(true, true);
			cn3x3.paint((HWND)pictureBox2->Handle.ToPointer());

			convolution<edge2d::edge5x5> cn5x5;
			cn5x5.addLineAll2(true, true);
			cn5x5.paint((HWND)pictureBox3->Handle.ToPointer());

			convolution<edge2d::edge7x7> cn7x7;
			cn7x7.addLineAll2(true, true);
			cn7x7.paint((HWND)pictureBox4->Handle.ToPointer());
		}

		{
			convolution<edge2d::edge3x3> cn3x3;
			cn3x3.addLineAll2(false, true);
			cn3x3.paint((HWND)pictureBox5->Handle.ToPointer());

			convolution<edge2d::edge5x5> cn5x5;
			cn5x5.addLineAll2(false, true);
			cn5x5.paint((HWND)pictureBox6->Handle.ToPointer());

			convolution<edge2d::edge7x7> cn7x7;
			cn7x7.addLineAll2(false, true);
			cn7x7.paint((HWND)pictureBox7->Handle.ToPointer());
		}

		{
			convolution<edge2d::edge3x3> cn3x3;
			cn3x3.addLineAll(false, true);
			cn3x3.paint((HWND)pictureBox8->Handle.ToPointer());

			convolution<edge2d::edge5x5> cn5x5;
			cn5x5.addLineAll(false, true);
			cn5x5.paint((HWND)pictureBox9->Handle.ToPointer());

			convolution<edge2d::edge7x7> cn7x7;
			cn7x7.addLineAll(false, true);
			cn7x7.paint((HWND)pictureBox10->Handle.ToPointer());
		}

		{
			convolution<edge2d::edge3x3> cn3x3;
			cn3x3.addLineAll(true, true);
			cn3x3.paint((HWND)pictureBox11->Handle.ToPointer());

			convolution<edge2d::edge5x5> cn5x5;
			cn5x5.addLineAll(true, true);
			cn5x5.paint((HWND)pictureBox12->Handle.ToPointer());

			convolution<edge2d::edge7x7> cn7x7;
			cn7x7.addLineAll(true, true);
			cn7x7.paint((HWND)pictureBox13->Handle.ToPointer());
		}

	}
	private: System::Void TestConvolutionForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	}
	private: System::Void TestConvolutionForm_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void TestConvolutionForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		POINT p;
		GetCursorPos(&p);

		auto r = System::Drawing::Rectangle(p.x, p.y, pictureBox1->Width, pictureBox1->Height);
		auto bmp = gcnew System::Drawing::Bitmap(r.Width, r.Height, Imaging::PixelFormat::Format32bppRgb);
		auto g = System::Drawing::Graphics::FromImage(bmp);
		g->InterpolationMode = Drawing2D::InterpolationMode::Bicubic;
		g->CopyFromScreen(r.Left, r.Top, 0, 0, bmp->Size, CopyPixelOperation::SourceCopy);

		//----------------------------------------------------------------------
		int width = pictureBox1->Width * 14;
		int height = pictureBox1->Height * 14;
		auto destRect = Drawing::Rectangle(0, 0, width, height);
		auto destImage = gcnew Drawing::Bitmap(width, height);
		Graphics^ graphics = Graphics::FromImage(destImage);
		graphics->InterpolationMode = Drawing2D::InterpolationMode::NearestNeighbor;
		graphics->DrawImage(bmp, destRect, 0, 0, bmp->Width, bmp->Height, GraphicsUnit::Pixel);
		//-------------------------------------------------------------------------

		pictureBox1->Image = destImage;
	}
	};
}
