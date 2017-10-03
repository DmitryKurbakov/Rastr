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
//https://github.com/DmitryKurbakov/Rastr

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
		actionshandlers = gcnew ActionsHandlers(this->pictureBox, Color::Black, backgroundColor);	//init controller;
		backgroundColor = pictureBox->BackColor;
	}


private: System::Windows::Forms::GroupBox^  objectsGroupBox;
private: System::Windows::Forms::RadioButton^  ellipseRadioButton;
private: System::Windows::Forms::RadioButton^  circleRadioButton;
private: System::Windows::Forms::RadioButton^  lineRadioButton;
private: ActionsHandlers^ actionshandlers;


private: System::Windows::Forms::GroupBox^  pictureGroupBox;
private: System::Windows::Forms::PictureBox^  pictureBox;
private: System::Windows::Forms::GroupBox^  settingsGroupBox;
private: System::Windows::Forms::Button^  objectsFromFileButton;


private: System::Windows::Forms::Button^  randomButton;
private: System::Windows::Forms::RadioButton^  LineFillingRadioButton;
private: System::Windows::Forms::RadioButton^  PolygonFillingRadioButton;
private: System::Windows::Forms::ColorDialog^  colorDialog;
private: System::Windows::Forms::MenuStrip^  menuStrip;

private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
private: System::Windows::Forms::GroupBox^  colorGroupBox;
private: System::Windows::Forms::Button^  colorButton;
private: System::Windows::Forms::RadioButton^  ClippingRadioButton;
private: System::Windows::Forms::ComboBox^  clippingComboBox;

private: System::Windows::Forms::Button^  clearButton;
private: System::Windows::Forms::Button^  backgroundColorButton;





private: Color backgroundColor;
	

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
		this->clippingComboBox = (gcnew System::Windows::Forms::ComboBox());
		this->ClippingRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->PolygonFillingRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->ellipseRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->LineFillingRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->circleRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->lineRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->pictureGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
		this->settingsGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->objectsFromFileButton = (gcnew System::Windows::Forms::Button());
		this->randomButton = (gcnew System::Windows::Forms::Button());
		this->colorDialog = (gcnew System::Windows::Forms::ColorDialog());
		this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
		this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->colorGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->backgroundColorButton = (gcnew System::Windows::Forms::Button());
		this->colorButton = (gcnew System::Windows::Forms::Button());
		this->objectsGroupBox->SuspendLayout();
		this->pictureGroupBox->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
		this->settingsGroupBox->SuspendLayout();
		this->menuStrip->SuspendLayout();
		this->colorGroupBox->SuspendLayout();
		this->SuspendLayout();
		// 
		// clearButton
		// 
		this->clearButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->clearButton->Location = System::Drawing::Point(12, 472);
		this->clearButton->Name = L"clearButton";
		this->clearButton->Size = System::Drawing::Size(76, 30);
		this->clearButton->TabIndex = 3;
		this->clearButton->Text = L"Очистить";
		this->clearButton->UseVisualStyleBackColor = true;
		this->clearButton->Click += gcnew System::EventHandler(this, &MyForm::clearButton_Click);
		// 
		// objectsGroupBox
		// 
		this->objectsGroupBox->Controls->Add(this->clippingComboBox);
		this->objectsGroupBox->Controls->Add(this->ClippingRadioButton);
		this->objectsGroupBox->Controls->Add(this->PolygonFillingRadioButton);
		this->objectsGroupBox->Controls->Add(this->ellipseRadioButton);
		this->objectsGroupBox->Controls->Add(this->LineFillingRadioButton);
		this->objectsGroupBox->Controls->Add(this->circleRadioButton);
		this->objectsGroupBox->Controls->Add(this->lineRadioButton);
		this->objectsGroupBox->Location = System::Drawing::Point(12, 31);
		this->objectsGroupBox->Name = L"objectsGroupBox";
		this->objectsGroupBox->Size = System::Drawing::Size(160, 191);
		this->objectsGroupBox->TabIndex = 4;
		this->objectsGroupBox->TabStop = false;
		this->objectsGroupBox->Text = L"Инструменты";
		// 
		// clippingComboBox
		// 
		this->clippingComboBox->Enabled = false;
		this->clippingComboBox->FormattingEnabled = true;
		this->clippingComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
			L"Окно и отрезки целиком", L"Разным цветом",
				L"Окно и видимые части отрезков"
		});
		this->clippingComboBox->Location = System::Drawing::Point(20, 157);
		this->clippingComboBox->Name = L"clippingComboBox";
		this->clippingComboBox->Size = System::Drawing::Size(126, 21);
		this->clippingComboBox->TabIndex = 6;
		this->clippingComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::OnSelectedIndexChanged);
		this->clippingComboBox->SelectedIndex = 0;
		// 
		// ClippingRadioButton
		// 
		this->ClippingRadioButton->AutoSize = true;
		this->ClippingRadioButton->Location = System::Drawing::Point(9, 134);
		this->ClippingRadioButton->Name = L"ClippingRadioButton";
		this->ClippingRadioButton->Size = System::Drawing::Size(79, 17);
		this->ClippingRadioButton->TabIndex = 5;
		this->ClippingRadioButton->Text = L"Отсечение";
		this->ClippingRadioButton->UseVisualStyleBackColor = true;
		this->ClippingRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::OnClippingCheckedChanged);
		// 
		// PolygonFillingRadioButton
		// 
		this->PolygonFillingRadioButton->AutoSize = true;
		this->PolygonFillingRadioButton->Location = System::Drawing::Point(10, 111);
		this->PolygonFillingRadioButton->Name = L"PolygonFillingRadioButton";
		this->PolygonFillingRadioButton->Size = System::Drawing::Size(136, 17);
		this->PolygonFillingRadioButton->TabIndex = 4;
		this->PolygonFillingRadioButton->Text = L"Заполнение полигона";
		this->PolygonFillingRadioButton->UseVisualStyleBackColor = true;
		this->PolygonFillingRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::OnCheckedChanged);
		// 
		// ellipseRadioButton
		// 
		this->ellipseRadioButton->AutoSize = true;
		this->ellipseRadioButton->Location = System::Drawing::Point(10, 65);
		this->ellipseRadioButton->Name = L"ellipseRadioButton";
		this->ellipseRadioButton->Size = System::Drawing::Size(62, 17);
		this->ellipseRadioButton->TabIndex = 2;
		this->ellipseRadioButton->Text = L"Эллипс";
		this->ellipseRadioButton->UseVisualStyleBackColor = true;
		this->ellipseRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::OnCheckedChanged);
		// 
		// LineFillingRadioButton
		// 
		this->LineFillingRadioButton->AutoSize = true;
		this->LineFillingRadioButton->Location = System::Drawing::Point(10, 88);
		this->LineFillingRadioButton->Name = L"LineFillingRadioButton";
		this->LineFillingRadioButton->Size = System::Drawing::Size(148, 17);
		this->LineFillingRadioButton->TabIndex = 3;
		this->LineFillingRadioButton->Text = L"Построчное заполнение";
		this->LineFillingRadioButton->UseVisualStyleBackColor = true;
		this->LineFillingRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::OnCheckedChanged);
		// 
		// circleRadioButton
		// 
		this->circleRadioButton->AutoSize = true;
		this->circleRadioButton->Location = System::Drawing::Point(10, 42);
		this->circleRadioButton->Name = L"circleRadioButton";
		this->circleRadioButton->Size = System::Drawing::Size(87, 17);
		this->circleRadioButton->TabIndex = 1;
		this->circleRadioButton->Text = L"Окружность";
		this->circleRadioButton->UseVisualStyleBackColor = true;
		this->circleRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::OnCheckedChanged);
		// 
		// lineRadioButton
		// 
		this->lineRadioButton->AutoSize = true;
		this->lineRadioButton->Checked = true;
		this->lineRadioButton->Location = System::Drawing::Point(10, 19);
		this->lineRadioButton->Name = L"lineRadioButton";
		this->lineRadioButton->Size = System::Drawing::Size(65, 17);
		this->lineRadioButton->TabIndex = 0;
		this->lineRadioButton->TabStop = true;
		this->lineRadioButton->Text = L"Прямая";
		this->lineRadioButton->UseVisualStyleBackColor = true;
		this->lineRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::OnCheckedChanged);
		// 
		// pictureGroupBox
		// 
		this->pictureGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			| System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->pictureGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
		this->pictureGroupBox->Controls->Add(this->pictureBox);
		this->pictureGroupBox->Location = System::Drawing::Point(176, 31);
		this->pictureGroupBox->Name = L"pictureGroupBox";
		this->pictureGroupBox->Size = System::Drawing::Size(696, 477);
		this->pictureGroupBox->TabIndex = 6;
		this->pictureGroupBox->TabStop = false;
		this->pictureGroupBox->Text = L"Изображение";
		// 
		// pictureBox
		// 
		this->pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			| System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->pictureBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
		this->pictureBox->Location = System::Drawing::Point(6, 19);
		this->pictureBox->Name = L"pictureBox";
		this->pictureBox->Size = System::Drawing::Size(684, 452);
		this->pictureBox->TabIndex = 0;
		this->pictureBox->TabStop = false;
		this->pictureBox->Click += gcnew System::EventHandler(this, &MyForm::pictureBox_Click);
		// 
		// settingsGroupBox
		// 
		this->settingsGroupBox->Controls->Add(this->objectsFromFileButton);
		this->settingsGroupBox->Controls->Add(this->randomButton);
		this->settingsGroupBox->Location = System::Drawing::Point(12, 324);
		this->settingsGroupBox->Name = L"settingsGroupBox";
		this->settingsGroupBox->Size = System::Drawing::Size(158, 77);
		this->settingsGroupBox->TabIndex = 7;
		this->settingsGroupBox->TabStop = false;
		this->settingsGroupBox->Text = L"Опции";
		// 
		// objectsFromFileButton
		// 
		this->objectsFromFileButton->Location = System::Drawing::Point(10, 48);
		this->objectsFromFileButton->Name = L"objectsFromFileButton";
		this->objectsFromFileButton->Size = System::Drawing::Size(101, 23);
		this->objectsFromFileButton->TabIndex = 1;
		this->objectsFromFileButton->Text = L"Из файла";
		this->objectsFromFileButton->UseVisualStyleBackColor = true;
		this->objectsFromFileButton->Click += gcnew System::EventHandler(this, &MyForm::objectsFromFileButton_Click);
		// 
		// randomButton
		// 
		this->randomButton->Location = System::Drawing::Point(10, 19);
		this->randomButton->Name = L"randomButton";
		this->randomButton->Size = System::Drawing::Size(101, 23);
		this->randomButton->TabIndex = 0;
		this->randomButton->Text = L"Случайные";
		this->randomButton->UseVisualStyleBackColor = true;
		this->randomButton->Click += gcnew System::EventHandler(this, &MyForm::randomButton_Click);
		// 
		// menuStrip
		// 
		this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
		this->menuStrip->Location = System::Drawing::Point(0, 0);
		this->menuStrip->Name = L"menuStrip";
		this->menuStrip->Size = System::Drawing::Size(884, 24);
		this->menuStrip->TabIndex = 8;
		this->menuStrip->Text = L"menuStrip1";
		// 
		// aboutToolStripMenuItem
		// 
		this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
		this->aboutToolStripMenuItem->Size = System::Drawing::Size(94, 20);
		this->aboutToolStripMenuItem->Text = L"О программе";
		this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
		// 
		// colorGroupBox
		// 
		this->colorGroupBox->Controls->Add(this->backgroundColorButton);
		this->colorGroupBox->Controls->Add(this->colorButton);
		this->colorGroupBox->Location = System::Drawing::Point(12, 228);
		this->colorGroupBox->Name = L"colorGroupBox";
		this->colorGroupBox->Size = System::Drawing::Size(160, 90);
		this->colorGroupBox->TabIndex = 2;
		this->colorGroupBox->TabStop = false;
		this->colorGroupBox->Text = L"Цвет";
		// 
		// backgroundColorButton
		// 
		this->backgroundColorButton->Location = System::Drawing::Point(8, 49);
		this->backgroundColorButton->Name = L"backgroundColorButton";
		this->backgroundColorButton->Size = System::Drawing::Size(104, 23);
		this->backgroundColorButton->TabIndex = 1;
		this->backgroundColorButton->Text = L"Фон";
		this->backgroundColorButton->UseVisualStyleBackColor = true;
		this->backgroundColorButton->Click += gcnew System::EventHandler(this, &MyForm::backgroundColorButton_Click);
		// 
		// colorButton
		// 
		this->colorButton->Location = System::Drawing::Point(7, 20);
		this->colorButton->Name = L"colorButton";
		this->colorButton->Size = System::Drawing::Size(104, 23);
		this->colorButton->TabIndex = 0;
		this->colorButton->Text = L"Объект";
		this->colorButton->UseVisualStyleBackColor = true;
		this->colorButton->Click += gcnew System::EventHandler(this, &MyForm::colorButton_Click);
		// 
		// MyForm
		// 
		this->ClientSize = System::Drawing::Size(884, 520);
		this->Controls->Add(this->colorGroupBox);
		this->Controls->Add(this->settingsGroupBox);
		this->Controls->Add(this->pictureGroupBox);
		this->Controls->Add(this->objectsGroupBox);
		this->Controls->Add(this->clearButton);
		this->Controls->Add(this->menuStrip);
		this->Location = System::Drawing::Point(52, 42);
		this->MainMenuStrip = this->menuStrip;
		this->Name = L"MyForm";
		this->objectsGroupBox->ResumeLayout(false);
		this->objectsGroupBox->PerformLayout();
		this->pictureGroupBox->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
		this->settingsGroupBox->ResumeLayout(false);
		this->menuStrip->ResumeLayout(false);
		this->menuStrip->PerformLayout();
		this->colorGroupBox->ResumeLayout(false);
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion

private: System::Void pictureBox_Click(System::Object^  sender, System::EventArgs^  e) {

	backgroundColorButton->Enabled = false;

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
	if (LineFillingRadioButton->Checked)
	{
		actionshandlers->LineFillingAreaPictureBoxOnClickHandler(cursor_point);
	}
	if (PolygonFillingRadioButton->Checked)
	{
		actionshandlers->PolygonFillingAreaPictureBoxOnClickHandler(cursor_point);
	}
	if (ClippingRadioButton->Checked)
	{
		actionshandlers->ClippingHandler(cursor_point, clippingComboBox->SelectedIndex);
	}

	delete cursor_point;
}
	private: System::Void clearButton_Click(System::Object^  sender, System::EventArgs^  e) {

		pictureBox->BackColor = Color::White;
		backgroundColor = Color::White;
		backgroundColorButton->Enabled = true;
		delete pictureBox->Image;
		delete actionshandlers;

		actionshandlers = gcnew ActionsHandlers(pictureBox, Color::Black, backgroundColor);
	}
	private: System::Void randomButton_Click(System::Object^  sender, System::EventArgs^  e) {

		if (ClippingRadioButton->Checked)
		{
			actionshandlers->onClippingComboBoxChange();
		}

		backgroundColorButton->Enabled = false;
		actionshandlers->RandomButtonClickHandler();

	}
	private: System::Void objectsFromFileButton_Click(System::Object^  sender, System::EventArgs^  e) {

		if (ClippingRadioButton->Checked)
		{
			actionshandlers->onClippingComboBoxChange();
		}

		backgroundColorButton->Enabled = false;
		actionshandlers->getObjectsFormFileClickHandler();
	}

private: System::Void colorButton_Click(System::Object^  sender, System::EventArgs^  e) {

	if (colorDialog->ShowDialog() == ::System::Windows::Forms::DialogResult::OK)
	{
		actionshandlers->SetColor(colorDialog->Color);
	}
}
		 void OnCheckedChanged(System::Object ^sender, System::EventArgs ^e);
		 void OnSelectedIndexChanged(System::Object ^sender, System::EventArgs ^e);
		 void OnClippingCheckedChanged(System::Object ^sender, System::EventArgs ^e);
private: System::Void backgroundColorButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (colorDialog->ShowDialog() == ::System::Windows::Forms::DialogResult::OK)
	{
		pictureBox->BackColor = colorDialog->Color;
		actionshandlers->backgroundColor = colorDialog->Color;
	}
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Семинар 2. Заливка, отсечение\nКурбаков Дмитрий Сергеевич, БПИ143\nНа панели Инструменты представлена реализация необходимых объектов для рисования. После выбора инструмента необходимо совершить серию нажатий на панеле Изображение\nVisual Studio 2017");
}
};


void MyForm::OnCheckedChanged(System::Object ^sender, System::EventArgs ^e)
{
	clippingComboBox->Enabled = false;
	actionshandlers->OnCheckedChange();
}


void MyForm::OnSelectedIndexChanged(System::Object ^sender, System::EventArgs ^e)
{
	if (ClippingRadioButton->Checked)
	{
		actionshandlers->ClippingHandler(actionshandlers->point0, clippingComboBox->SelectedIndex);
	}	
}


void MyForm::OnClippingCheckedChanged(System::Object ^sender, System::EventArgs ^e)
{
	if (ClippingRadioButton->Checked)
	{
		clippingComboBox->Enabled = true;
	}	
	else
	{
		actionshandlers->onClippingComboBoxChange();
	}
}
