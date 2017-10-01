#pragma once

namespace sem1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ClippingForm
	/// </summary>
	public ref class ClippingForm : public System::Windows::Forms::Form
	{
	public:
		ClippingForm(void)
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
		~ClippingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  pictureGroupBox;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->pictureGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureGroupBox
			// 
			this->pictureGroupBox->Controls->Add(this->pictureBox);
			this->pictureGroupBox->Location = System::Drawing::Point(12, 12);
			this->pictureGroupBox->Name = L"pictureGroupBox";
			this->pictureGroupBox->Size = System::Drawing::Size(465, 389);
			this->pictureGroupBox->TabIndex = 0;
			this->pictureGroupBox->TabStop = false;
			this->pictureGroupBox->Text = L"Picture";
			// 
			// pictureBox
			// 
			this->pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox->Location = System::Drawing::Point(6, 19);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(453, 364);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			// 
			// ClippingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(489, 413);
			this->Controls->Add(this->pictureGroupBox);
			this->Name = L"ClippingForm";
			this->pictureGroupBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
