//	Курбаков Дмитрий
//	БПИ143
//	16.09
//	Проект 1. Алгоритмы Брезенхема
//	
//	Visual Studio 2017
//	Microsoft Windows 10
//	i7-7700, gtx-1070, 8gb RAM
//
//	Реализация прямой
//	Реализация окружности
//	Реализация эллипса
//	Управление мышью
//
//https://github.com/DmitryKurbakov/Bresenham

#include "ActionsHandlers.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Сводка для MyForm
/// </summary>
public ref class MyForm : public System::Windows::Forms::Form
{


public:
	MyForm(void)
	{
		InitializeComponent();
		actionshandlers = gcnew ActionsHandlers(this->pictureBox);	//init controller;
	}


private: System::Windows::Forms::GroupBox^  objectsGroupBox;
private: System::Windows::Forms::RadioButton^  ellipseRadioButton;
private: System::Windows::Forms::RadioButton^  circleRadioButton;
private: System::Windows::Forms::RadioButton^  lineRadioButton;
private: ActionsHandlers^ actionshandlers;


private: System::Windows::Forms::GroupBox^  pictureGroupBox;
private: System::Windows::Forms::PictureBox^  pictureBox;

private: System::Windows::Forms::Button^  clearButton;
//private:
	

protected:
	~MyForm()
	{
		if (components)
		{
			delete components;
		}
	}

private:

	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

	void InitializeComponent(void)
	{
		this->clearButton = (gcnew System::Windows::Forms::Button());
		this->objectsGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->ellipseRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->circleRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->lineRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->pictureGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
		this->objectsGroupBox->SuspendLayout();
		this->pictureGroupBox->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
		this->SuspendLayout();
		// 
		// clearButton
		// 
		this->clearButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->clearButton->Location = System::Drawing::Point(12, 368);
		this->clearButton->Name = L"clearButton";
		this->clearButton->Size = System::Drawing::Size(76, 30);
		this->clearButton->TabIndex = 3;
		this->clearButton->Text = L"Clear";
		this->clearButton->UseVisualStyleBackColor = true;
		this->clearButton->Click += gcnew System::EventHandler(this, &MyForm::clearButton_Click);
		// 
		// objectsGroupBox
		// 
		this->objectsGroupBox->Controls->Add(this->ellipseRadioButton);
		this->objectsGroupBox->Controls->Add(this->circleRadioButton);
		this->objectsGroupBox->Controls->Add(this->lineRadioButton);
		this->objectsGroupBox->Location = System::Drawing::Point(12, 12);
		this->objectsGroupBox->Name = L"objectsGroupBox";
		this->objectsGroupBox->Size = System::Drawing::Size(97, 89);
		this->objectsGroupBox->TabIndex = 4;
		this->objectsGroupBox->TabStop = false;
		this->objectsGroupBox->Text = L"Object";
		// 
		// ellipseRadioButton
		// 
		this->ellipseRadioButton->AutoSize = true;
		this->ellipseRadioButton->Location = System::Drawing::Point(10, 65);
		this->ellipseRadioButton->Name = L"ellipseRadioButton";
		this->ellipseRadioButton->Size = System::Drawing::Size(55, 17);
		this->ellipseRadioButton->TabIndex = 2;
		this->ellipseRadioButton->Text = L"Ellipse";
		this->ellipseRadioButton->UseVisualStyleBackColor = true;
		// 
		// circleRadioButton
		// 
		this->circleRadioButton->AutoSize = true;
		this->circleRadioButton->Location = System::Drawing::Point(10, 42);
		this->circleRadioButton->Name = L"circleRadioButton";
		this->circleRadioButton->Size = System::Drawing::Size(51, 17);
		this->circleRadioButton->TabIndex = 1;
		this->circleRadioButton->Text = L"Circle";
		this->circleRadioButton->UseVisualStyleBackColor = true;
		// 
		// lineRadioButton
		// 
		this->lineRadioButton->AutoSize = true;
		this->lineRadioButton->Checked = true;
		this->lineRadioButton->Location = System::Drawing::Point(10, 19);
		this->lineRadioButton->Name = L"lineRadioButton";
		this->lineRadioButton->Size = System::Drawing::Size(45, 17);
		this->lineRadioButton->TabIndex = 0;
		this->lineRadioButton->TabStop = true;
		this->lineRadioButton->Text = L"Line";
		this->lineRadioButton->UseVisualStyleBackColor = true;
		// 
		// pictureGroupBox
		// 
		this->pictureGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			| System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->pictureGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
		this->pictureGroupBox->Controls->Add(this->pictureBox);
		this->pictureGroupBox->Location = System::Drawing::Point(115, 12);
		this->pictureGroupBox->Name = L"pictureGroupBox";
		this->pictureGroupBox->Size = System::Drawing::Size(754, 383);
		this->pictureGroupBox->TabIndex = 6;
		this->pictureGroupBox->TabStop = false;
		this->pictureGroupBox->Text = L"Picture";
		// 
		// pictureBox
		// 
		this->pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			| System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->pictureBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
		this->pictureBox->Location = System::Drawing::Point(6, 19);
		this->pictureBox->Name = L"pictureBox";
		this->pictureBox->Size = System::Drawing::Size(742, 358);
		this->pictureBox->TabIndex = 0;
		this->pictureBox->TabStop = false;
		this->pictureBox->Click += gcnew System::EventHandler(this, &MyForm::pictureBox_Click);
		// 
		// MyForm
		// 
		this->ClientSize = System::Drawing::Size(884, 410);
		this->Controls->Add(this->pictureGroupBox);
		this->Controls->Add(this->objectsGroupBox);
		this->Controls->Add(this->clearButton);
		this->Location = System::Drawing::Point(52, 42);
		this->Name = L"MyForm";
		this->objectsGroupBox->ResumeLayout(false);
		this->objectsGroupBox->PerformLayout();
		this->pictureGroupBox->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
		this->ResumeLayout(false);

	}
#pragma endregion

private: System::Void pictureBox_Click(System::Object^  sender, System::EventArgs^  e) {

	Point^ cursor_point = pictureBox->PointToClient(System::Windows::Forms::Cursor::Position);

	if (lineRadioButton->Checked)
	{
		actionshandlers->LinePictureBoxOnClickHandler(cursor_point);
	}
	if (circleRadioButton->Checked)
	{
		actionshandlers->CirclePictureBoxOnClickHandler(cursor_point);
	}
	if (ellipseRadioButton->Checked)
	{
		actionshandlers->EllipsePictureBoxOnClickHandler(cursor_point);
	}

	delete cursor_point;
}
private: System::Void clearButton_Click(System::Object^  sender, System::EventArgs^  e) {
	delete pictureBox->Image;
	delete actionshandlers;

	actionshandlers = gcnew ActionsHandlers(pictureBox);
}
};
