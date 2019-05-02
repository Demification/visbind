#pragma once
#include "../sys/pixbit.h"
#include "../sys/allocator.h"
#include "../sys/test.h"
#include "../sys/imgpart.h"
#include "../sys/convolution.h"
#include "support.h"

namespace visbind {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class TestImgCmpForm : public System::Windows::Forms::Form
	{
#pragma region Windows Form Designer generated code
	public:
		TestImgCmpForm(void)
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
		~TestImgCmpForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// TestImgCmpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(288, 268);
			this->Name = L"TestImgCmpForm";
			this->Text = L"TestImgCmpForm";
			this->Shown += gcnew System::EventHandler(this, &TestImgCmpForm::TestImgCmpForm_Shown);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: System::Void Run() {
		ShowDialog();
	}
	private: System::Void TestImgCmpForm_Shown(System::Object^  sender, System::EventArgs^  e) {
		Application::DoEvents();
		test.calibrate();

		pixbit::bitmap tsimg;
		pixbit::bmpcmp tsbmpcmp;

		tsimg.initAndLoad(IDB_BITMAP2);
		
		tsbmpcmp.init(tsimg.width, tsimg.height);
		tsbmpcmp.load8bpp(&tsimg);
		tsbmpcmp.load8bppgrey();

		imgpart ic3x3s1;
		ic3x3s1.init(edge2d::edge3x3, edge2d_step::x1, (int)tsbmpcmp.max_width, (int)tsbmpcmp.max_height);
		ic3x3s1.preload(tsbmpcmp.grey8bpp);
		ic3x3s1.load();

		convolution<edge2d::edge3x3> cn3x3;
		cn3x3.addLineAll2(false, false);
		cn3x3.makemp();

		//------------------------------------------------------------------------------------------------------------------------------------
		
		int n = ic3x3s1.nx * ic3x3s1.ny * ic3x3s1.edge * ic3x3s1.edge;
		byte* b = (byte*)ic3x3s1.buffer.get0ptr();

		int result[9];

		test.start();
		for (int i = 0; i < n; i+=9)
		{
			memset(result, 0, 9 * sizeof(int));
			cn3x3.comp(&b[i], result);
		}
		test.stop();

		//------------------------------------------------------------------------------------------------------------------------------------

		ic3x3s1.destroy();
		tsbmpcmp.destroy();
		tsimg.destroy();
	}
	};
}
