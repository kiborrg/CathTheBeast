#pragma once

#include "Objects.h"

namespace CathTheBeast {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//Необходимые переменные
	int HuntersKol = 0; //Количество охотников
	int TrapsKol = 0; //Количество ловушек
	int VerticalCellsKol = 0; //Количество клеток по вертикали
	int HorizontalCellsKol = 0; //Количество клеток по горизонтали

	int CellsHeight; //Высота ячейки
	int CellsWidth; //Ширина ячейки

	bool GameStarted = false; //Игра началась
	
	Trap** Traps; //Массив ловушек
	Hunter** Hunters; //Массив охотников
	Beast* Beasts; //Зверь

	int** tmpMas; //Массив всех занятых координат для отслеживания

	bool MouseClicked = false; //Проверка на клик мыши по клетке поля
	int XMouseClicked = -1; //Получение координаты X клика мыши
	int YMouseClicked = -1; //Получение координаты Y клика мыши

	int** AcceptCells; //Массив доступных клеток вокруг выбранной
	int AcceptCellsKol = 0; //Количество доступных клеток
	int HunterNum = -1; //Индекс охотника, выбранного для перемещения

	int Difficulty = -1;//Сложность: -1 - легко, 1 - сложно

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  Start_label;
	protected:
	private: System::Windows::Forms::Label^  Hunters_label;
	private: System::Windows::Forms::TextBox^  Hunters_textBox;
	private: System::Windows::Forms::Label^  Traps_label;
	private: System::Windows::Forms::TextBox^  Traps_textBox;
	private: System::Windows::Forms::Panel^  Start_panel;

	private: System::Windows::Forms::Button^  StartGame_button;
	private: System::Windows::Forms::TextBox^  HorizontalCells_textBox;

	private: System::Windows::Forms::Label^  HorizontalCells_label;

	private: System::Windows::Forms::TextBox^  VerticalCells_textBox;

	private: System::Windows::Forms::Label^  VerticalCells_label;

	private: System::Windows::Forms::Label^  Cells_label;

	private: System::Windows::Forms::Panel^  Game_panel;
	private: System::Windows::Forms::PictureBox^  GameField_pictureBox;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::ToolStripButton^  MainMenu_toolStripButton;
	private: System::Windows::Forms::ToolStripButton^  Replay_toolStripButton;
	private: System::Windows::Forms::ToolStripButton^  Settings_toolStripButton;
	private: System::Windows::Forms::ToolStripButton^  Info_toolStripButton;
	private: System::Windows::Forms::Panel^  Settings_panel;
	private: System::Windows::Forms::Label^  Settings_label;
	private: System::Windows::Forms::GroupBox^  Difficulty_groupBox;
	private: System::Windows::Forms::RadioButton^  Hard_radioButton;
	private: System::Windows::Forms::RadioButton^  Easy_radioButton;
	private: System::Windows::Forms::Button^  CancelSettings_button;
	private: System::Windows::Forms::Button^  SaveSettings_button;
	private: System::Windows::Forms::Panel^  Manual_panel;
	private: System::Windows::Forms::Button^  CloseManual_button;
	private: System::Windows::Forms::RichTextBox^  Manual_richTextBox;




	private: System::ComponentModel::IContainer^  components;


	protected:

	protected:



	protected:





	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->Start_label = (gcnew System::Windows::Forms::Label());
			this->Hunters_label = (gcnew System::Windows::Forms::Label());
			this->Hunters_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Traps_label = (gcnew System::Windows::Forms::Label());
			this->Traps_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Start_panel = (gcnew System::Windows::Forms::Panel());
			this->HorizontalCells_textBox = (gcnew System::Windows::Forms::TextBox());
			this->HorizontalCells_label = (gcnew System::Windows::Forms::Label());
			this->VerticalCells_textBox = (gcnew System::Windows::Forms::TextBox());
			this->VerticalCells_label = (gcnew System::Windows::Forms::Label());
			this->Cells_label = (gcnew System::Windows::Forms::Label());
			this->StartGame_button = (gcnew System::Windows::Forms::Button());
			this->Game_panel = (gcnew System::Windows::Forms::Panel());
			this->GameField_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->MainMenu_toolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->Replay_toolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->Settings_toolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->Info_toolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Settings_panel = (gcnew System::Windows::Forms::Panel());
			this->CancelSettings_button = (gcnew System::Windows::Forms::Button());
			this->SaveSettings_button = (gcnew System::Windows::Forms::Button());
			this->Difficulty_groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->Hard_radioButton = (gcnew System::Windows::Forms::RadioButton());
			this->Easy_radioButton = (gcnew System::Windows::Forms::RadioButton());
			this->Settings_label = (gcnew System::Windows::Forms::Label());
			this->Manual_panel = (gcnew System::Windows::Forms::Panel());
			this->CloseManual_button = (gcnew System::Windows::Forms::Button());
			this->Manual_richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->Start_panel->SuspendLayout();
			this->Game_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GameField_pictureBox))->BeginInit();
			this->toolStrip1->SuspendLayout();
			this->Settings_panel->SuspendLayout();
			this->Difficulty_groupBox->SuspendLayout();
			this->Manual_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// Start_label
			// 
			this->Start_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Start_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Start_label->Location = System::Drawing::Point(264, 54);
			this->Start_label->Name = L"Start_label";
			this->Start_label->Size = System::Drawing::Size(307, 30);
			this->Start_label->TabIndex = 0;
			this->Start_label->Text = L"Введите начальные данные";
			this->Start_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Hunters_label
			// 
			this->Hunters_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Hunters_label->AutoSize = true;
			this->Hunters_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Hunters_label->Location = System::Drawing::Point(265, 183);
			this->Hunters_label->Name = L"Hunters_label";
			this->Hunters_label->Size = System::Drawing::Size(197, 21);
			this->Hunters_label->TabIndex = 1;
			this->Hunters_label->Text = L"Количество охотников:";
			// 
			// Hunters_textBox
			// 
			this->Hunters_textBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Hunters_textBox->Location = System::Drawing::Point(482, 185);
			this->Hunters_textBox->Name = L"Hunters_textBox";
			this->Hunters_textBox->Size = System::Drawing::Size(89, 20);
			this->Hunters_textBox->TabIndex = 2;
			this->Hunters_textBox->Text = L"0";
			// 
			// Traps_label
			// 
			this->Traps_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Traps_label->AutoSize = true;
			this->Traps_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Traps_label->Location = System::Drawing::Point(265, 230);
			this->Traps_label->Name = L"Traps_label";
			this->Traps_label->Size = System::Drawing::Size(181, 21);
			this->Traps_label->TabIndex = 3;
			this->Traps_label->Text = L"Количество ловушек:";
			// 
			// Traps_textBox
			// 
			this->Traps_textBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Traps_textBox->Location = System::Drawing::Point(482, 232);
			this->Traps_textBox->Name = L"Traps_textBox";
			this->Traps_textBox->Size = System::Drawing::Size(89, 20);
			this->Traps_textBox->TabIndex = 4;
			this->Traps_textBox->Text = L"0";
			// 
			// Start_panel
			// 
			this->Start_panel->Controls->Add(this->HorizontalCells_textBox);
			this->Start_panel->Controls->Add(this->HorizontalCells_label);
			this->Start_panel->Controls->Add(this->VerticalCells_textBox);
			this->Start_panel->Controls->Add(this->VerticalCells_label);
			this->Start_panel->Controls->Add(this->Cells_label);
			this->Start_panel->Controls->Add(this->StartGame_button);
			this->Start_panel->Controls->Add(this->Start_label);
			this->Start_panel->Controls->Add(this->Traps_textBox);
			this->Start_panel->Controls->Add(this->Hunters_label);
			this->Start_panel->Controls->Add(this->Traps_label);
			this->Start_panel->Controls->Add(this->Hunters_textBox);
			this->Start_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Start_panel->Location = System::Drawing::Point(0, 0);
			this->Start_panel->Name = L"Start_panel";
			this->Start_panel->Size = System::Drawing::Size(819, 463);
			this->Start_panel->TabIndex = 5;
			// 
			// HorizontalCells_textBox
			// 
			this->HorizontalCells_textBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HorizontalCells_textBox->Location = System::Drawing::Point(540, 139);
			this->HorizontalCells_textBox->Name = L"HorizontalCells_textBox";
			this->HorizontalCells_textBox->Size = System::Drawing::Size(31, 20);
			this->HorizontalCells_textBox->TabIndex = 16;
			this->HorizontalCells_textBox->Text = L"0";
			// 
			// HorizontalCells_label
			// 
			this->HorizontalCells_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HorizontalCells_label->AutoSize = true;
			this->HorizontalCells_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->HorizontalCells_label->Location = System::Drawing::Point(419, 139);
			this->HorizontalCells_label->Name = L"HorizontalCells_label";
			this->HorizontalCells_label->Size = System::Drawing::Size(115, 21);
			this->HorizontalCells_label->TabIndex = 15;
			this->HorizontalCells_label->Text = L"горизонтали:";
			// 
			// VerticalCells_textBox
			// 
			this->VerticalCells_textBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->VerticalCells_textBox->Location = System::Drawing::Point(366, 141);
			this->VerticalCells_textBox->Name = L"VerticalCells_textBox";
			this->VerticalCells_textBox->Size = System::Drawing::Size(31, 20);
			this->VerticalCells_textBox->TabIndex = 14;
			this->VerticalCells_textBox->Text = L"0";
			// 
			// VerticalCells_label
			// 
			this->VerticalCells_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->VerticalCells_label->AutoSize = true;
			this->VerticalCells_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->VerticalCells_label->Location = System::Drawing::Point(265, 139);
			this->VerticalCells_label->Name = L"VerticalCells_label";
			this->VerticalCells_label->Size = System::Drawing::Size(95, 21);
			this->VerticalCells_label->TabIndex = 13;
			this->VerticalCells_label->Text = L"вертикали:";
			// 
			// Cells_label
			// 
			this->Cells_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Cells_label->AutoSize = true;
			this->Cells_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Cells_label->Location = System::Drawing::Point(327, 96);
			this->Cells_label->Name = L"Cells_label";
			this->Cells_label->Size = System::Drawing::Size(188, 21);
			this->Cells_label->TabIndex = 12;
			this->Cells_label->Text = L"Количество клеток по";
			// 
			// StartGame_button
			// 
			this->StartGame_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StartGame_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StartGame_button->Location = System::Drawing::Point(269, 289);
			this->StartGame_button->Name = L"StartGame_button";
			this->StartGame_button->Size = System::Drawing::Size(302, 52);
			this->StartGame_button->TabIndex = 5;
			this->StartGame_button->Text = L"Начать игру";
			this->StartGame_button->UseVisualStyleBackColor = true;
			this->StartGame_button->Click += gcnew System::EventHandler(this, &MainForm::StartGame_button_Click);
			// 
			// Game_panel
			// 
			this->Game_panel->Controls->Add(this->GameField_pictureBox);
			this->Game_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Game_panel->Location = System::Drawing::Point(0, 0);
			this->Game_panel->Name = L"Game_panel";
			this->Game_panel->Size = System::Drawing::Size(819, 463);
			this->Game_panel->TabIndex = 7;
			this->Game_panel->Visible = false;
			// 
			// GameField_pictureBox
			// 
			this->GameField_pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GameField_pictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->GameField_pictureBox->Location = System::Drawing::Point(210, 31);
			this->GameField_pictureBox->Name = L"GameField_pictureBox";
			this->GameField_pictureBox->Size = System::Drawing::Size(400, 400);
			this->GameField_pictureBox->TabIndex = 0;
			this->GameField_pictureBox->TabStop = false;
			this->GameField_pictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::GameField_pictureBox_Paint);
			this->GameField_pictureBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::GameField_pictureBox_MouseClick);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->MainMenu_toolStripButton,
					this->Replay_toolStripButton, this->Settings_toolStripButton, this->Info_toolStripButton
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(819, 25);
			this->toolStrip1->TabIndex = 8;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// MainMenu_toolStripButton
			// 
			this->MainMenu_toolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->MainMenu_toolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MainMenu_toolStripButton.Image")));
			this->MainMenu_toolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->MainMenu_toolStripButton->Name = L"MainMenu_toolStripButton";
			this->MainMenu_toolStripButton->Size = System::Drawing::Size(91, 22);
			this->MainMenu_toolStripButton->Text = L"Главное меню";
			this->MainMenu_toolStripButton->Click += gcnew System::EventHandler(this, &MainForm::MainMenu_toolStripButton_Click);
			// 
			// Replay_toolStripButton
			// 
			this->Replay_toolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Replay_toolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Replay_toolStripButton.Image")));
			this->Replay_toolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Replay_toolStripButton->Name = L"Replay_toolStripButton";
			this->Replay_toolStripButton->Size = System::Drawing::Size(91, 22);
			this->Replay_toolStripButton->Text = L"Начать заново";
			this->Replay_toolStripButton->Click += gcnew System::EventHandler(this, &MainForm::Replay_toolStripButton_Click);
			// 
			// Settings_toolStripButton
			// 
			this->Settings_toolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Settings_toolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Settings_toolStripButton.Image")));
			this->Settings_toolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Settings_toolStripButton->Name = L"Settings_toolStripButton";
			this->Settings_toolStripButton->Size = System::Drawing::Size(71, 22);
			this->Settings_toolStripButton->Text = L"Настройки";
			this->Settings_toolStripButton->Click += gcnew System::EventHandler(this, &MainForm::Settings_toolStripButton_Click);
			// 
			// Info_toolStripButton
			// 
			this->Info_toolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Info_toolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Info_toolStripButton.Image")));
			this->Info_toolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Info_toolStripButton->Name = L"Info_toolStripButton";
			this->Info_toolStripButton->Size = System::Drawing::Size(57, 22);
			this->Info_toolStripButton->Text = L"Справка";
			this->Info_toolStripButton->Click += gcnew System::EventHandler(this, &MainForm::Info_toolStripButton_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// Settings_panel
			// 
			this->Settings_panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Settings_panel->Controls->Add(this->CancelSettings_button);
			this->Settings_panel->Controls->Add(this->SaveSettings_button);
			this->Settings_panel->Controls->Add(this->Difficulty_groupBox);
			this->Settings_panel->Controls->Add(this->Settings_label);
			this->Settings_panel->Location = System::Drawing::Point(258, 54);
			this->Settings_panel->Name = L"Settings_panel";
			this->Settings_panel->Size = System::Drawing::Size(313, 287);
			this->Settings_panel->TabIndex = 9;
			this->Settings_panel->Visible = false;
			// 
			// CancelSettings_button
			// 
			this->CancelSettings_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CancelSettings_button->Location = System::Drawing::Point(157, 206);
			this->CancelSettings_button->Name = L"CancelSettings_button";
			this->CancelSettings_button->Size = System::Drawing::Size(100, 32);
			this->CancelSettings_button->TabIndex = 3;
			this->CancelSettings_button->Text = L"Отмена";
			this->CancelSettings_button->UseVisualStyleBackColor = true;
			this->CancelSettings_button->Click += gcnew System::EventHandler(this, &MainForm::CancelSettings_button_Click);
			// 
			// SaveSettings_button
			// 
			this->SaveSettings_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SaveSettings_button->Location = System::Drawing::Point(57, 206);
			this->SaveSettings_button->Name = L"SaveSettings_button";
			this->SaveSettings_button->Size = System::Drawing::Size(100, 32);
			this->SaveSettings_button->TabIndex = 2;
			this->SaveSettings_button->Text = L"Сохранить";
			this->SaveSettings_button->UseVisualStyleBackColor = true;
			this->SaveSettings_button->Click += gcnew System::EventHandler(this, &MainForm::SaveSettings_button_Click);
			// 
			// Difficulty_groupBox
			// 
			this->Difficulty_groupBox->Controls->Add(this->Hard_radioButton);
			this->Difficulty_groupBox->Controls->Add(this->Easy_radioButton);
			this->Difficulty_groupBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Difficulty_groupBox->Location = System::Drawing::Point(57, 85);
			this->Difficulty_groupBox->Name = L"Difficulty_groupBox";
			this->Difficulty_groupBox->Size = System::Drawing::Size(200, 100);
			this->Difficulty_groupBox->TabIndex = 1;
			this->Difficulty_groupBox->TabStop = false;
			this->Difficulty_groupBox->Text = L"Сложность";
			// 
			// Hard_radioButton
			// 
			this->Hard_radioButton->AutoSize = true;
			this->Hard_radioButton->Location = System::Drawing::Point(7, 55);
			this->Hard_radioButton->Name = L"Hard_radioButton";
			this->Hard_radioButton->Size = System::Drawing::Size(93, 25);
			this->Hard_radioButton->TabIndex = 1;
			this->Hard_radioButton->Text = L"Сложно";
			this->Hard_radioButton->UseVisualStyleBackColor = true;
			this->Hard_radioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::Hard_radioButton_CheckedChanged);
			// 
			// Easy_radioButton
			// 
			this->Easy_radioButton->AutoSize = true;
			this->Easy_radioButton->Checked = true;
			this->Easy_radioButton->Location = System::Drawing::Point(7, 24);
			this->Easy_radioButton->Name = L"Easy_radioButton";
			this->Easy_radioButton->Size = System::Drawing::Size(75, 25);
			this->Easy_radioButton->TabIndex = 0;
			this->Easy_radioButton->TabStop = true;
			this->Easy_radioButton->Text = L"Легко";
			this->Easy_radioButton->UseVisualStyleBackColor = true;
			this->Easy_radioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::Easy_radioButton_CheckedChanged);
			// 
			// Settings_label
			// 
			this->Settings_label->AutoSize = true;
			this->Settings_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Settings_label->Location = System::Drawing::Point(89, 30);
			this->Settings_label->Name = L"Settings_label";
			this->Settings_label->Size = System::Drawing::Size(138, 31);
			this->Settings_label->TabIndex = 0;
			this->Settings_label->Text = L"Настройки";
			// 
			// Manual_panel
			// 
			this->Manual_panel->Controls->Add(this->CloseManual_button);
			this->Manual_panel->Controls->Add(this->Manual_richTextBox);
			this->Manual_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Manual_panel->Location = System::Drawing::Point(0, 25);
			this->Manual_panel->Name = L"Manual_panel";
			this->Manual_panel->Size = System::Drawing::Size(819, 438);
			this->Manual_panel->TabIndex = 11;
			this->Manual_panel->Visible = false;
			// 
			// CloseManual_button
			// 
			this->CloseManual_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->CloseManual_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CloseManual_button->Location = System::Drawing::Point(331, 403);
			this->CloseManual_button->Name = L"CloseManual_button";
			this->CloseManual_button->Size = System::Drawing::Size(184, 32);
			this->CloseManual_button->TabIndex = 1;
			this->CloseManual_button->Text = L"Закрыть";
			this->CloseManual_button->UseVisualStyleBackColor = true;
			this->CloseManual_button->Click += gcnew System::EventHandler(this, &MainForm::CloseManual_button_Click);
			// 
			// Manual_richTextBox
			// 
			this->Manual_richTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Manual_richTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Manual_richTextBox->Location = System::Drawing::Point(0, 0);
			this->Manual_richTextBox->Name = L"Manual_richTextBox";
			this->Manual_richTextBox->Size = System::Drawing::Size(819, 397);
			this->Manual_richTextBox->TabIndex = 0;
			this->Manual_richTextBox->Text = resources->GetString(L"Manual_richTextBox.Text");
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(819, 463);
			this->Controls->Add(this->Manual_panel);
			this->Controls->Add(this->Settings_panel);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->Game_panel);
			this->Controls->Add(this->Start_panel);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Загони зверя в ловушку";
			this->MaximumSizeChanged += gcnew System::EventHandler(this, &MainForm::MainForm_MaximumSizeChanged);
			this->MinimumSizeChanged += gcnew System::EventHandler(this, &MainForm::MainForm_MinimumSizeChanged);
			this->Start_panel->ResumeLayout(false);
			this->Start_panel->PerformLayout();
			this->Game_panel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GameField_pictureBox))->EndInit();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->Settings_panel->ResumeLayout(false);
			this->Settings_panel->PerformLayout();
			this->Difficulty_groupBox->ResumeLayout(false);
			this->Difficulty_groupBox->PerformLayout();
			this->Manual_panel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		private: System::Void StartGame_button_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			HuntersKol = System::Convert::ToInt32(Hunters_textBox->Text);
			TrapsKol = System::Convert::ToInt32(Traps_textBox->Text);
			VerticalCellsKol = System::Convert::ToInt32(VerticalCells_textBox->Text);
			HorizontalCellsKol = System::Convert::ToInt32(HorizontalCells_textBox->Text);
		
			if ((HuntersKol < 2) && (TrapsKol < 1) && (VerticalCellsKol == 0) && (HorizontalCellsKol == 0))
				MessageBox::Show("Неверные исходные данные");
			else if ((HuntersKol < 2) && (TrapsKol < 1))
				MessageBox::Show("Недостаточно охотников и ловушек");
			else if (((VerticalCellsKol == 0) && (HorizontalCellsKol == 0)) || ((VerticalCellsKol == 0) || (HorizontalCellsKol == 0)))
				MessageBox::Show("Неправильная размерность игрового поля");
			else if (TrapsKol < 1)
				MessageBox::Show("Недостаточно ловушек");
			else if (HuntersKol < 2)
				MessageBox::Show("Недостаточно охотников");
			else if ((VerticalCellsKol * HorizontalCellsKol) < (HuntersKol + TrapsKol + 1))
				MessageBox::Show("Слишком маленькое игровое поле");
			else if ((VerticalCellsKol * HorizontalCellsKol) > 625)
				MessageBox::Show("Слишком большое игровое поле");
			else
			{
				Start_panel->Visible = false;
				GameStarted = true;
				timer1->Enabled = true;

				bool test = false;
				do
				{
					CreateObjects(HuntersKol, Hunters, TrapsKol, Traps, Beasts, VerticalCellsKol, HorizontalCellsKol, tmpMas);
					test = GenerationTest();
				} while (test == false);

				GameField_pictureBox->Refresh();

				Game_panel->Visible = true;
			}
		}
	
		private: System::Void GameField_pictureBox_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
		{
			if (!GameStarted)
				return;
		
			CellsHeight = GameField_pictureBox->Size.Height / VerticalCellsKol; //Вычисление высоты ячейки
			CellsWidth = GameField_pictureBox->Size.Width / HorizontalCellsKol; //Вычисление ширины ячейки
			for (int i = 0; i < HorizontalCellsKol; i++) //Вырисовка сетки
			{
				for (int j = 0; j < VerticalCellsKol; j++)
				{
					e->Graphics->DrawRectangle(Pens::Black, i * CellsWidth, j * CellsHeight, CellsWidth, CellsHeight);
				}
			}

			Image ^img = Image::FromFile(IO::Directory::GetCurrentDirectory() + "\\Resources\\Beast.bmp");
			

			//Вырисовка зверя
			DrawObject(e, img, CellsWidth, CellsHeight, Beasts->GetX(), Beasts->GetY());

			img = Image::FromFile(IO::Directory::GetCurrentDirectory() + "\\Resources\\Trap.bmp");
			//Вырисовка ловушек
			for (int i = 0; i < TrapsKol; i++)
				DrawObject(e, img, CellsWidth, CellsHeight, Traps[i]->GetX(), Traps[i]->GetY());

			img = Image::FromFile(IO::Directory::GetCurrentDirectory() + "\\Resources\\Hunter.bmp");
			//Вырисовка охотника
			for (int i = 0; i < HuntersKol; i++)
				DrawObject(e, img, CellsWidth, CellsHeight, Hunters[i]->GetX(), Hunters[i]->GetY());

			//Если нажата клавиша мыши, то подсветить клетки вокруг, если свободны
			if (MouseClicked)
			{
				for (int i = 0; i < AcceptCellsKol; i++)
				{
					e->Graphics->FillRectangle(Drawing::Brushes::LightBlue, AcceptCells[i][0] * CellsWidth, AcceptCells[i][1] * CellsHeight, CellsWidth, CellsHeight);
				}
			}
		}

		void DrawObject(System::Windows::Forms::PaintEventArgs^  e, Image^ img, int CellsWidth, int CellsHeight, int X, int Y)
		{
			double zoom = 1.0;

			if ((img->Height >= CellsHeight) || (img->Width >= CellsWidth))
			{
				//Цикл зуммирования (вычисление коэффициента зума)
				while (((img->Height * zoom) >= CellsHeight) || ((img->Width * zoom) >= CellsWidth))
					zoom -= 0.01;
			}
			else
			{
				do
					zoom += 0.01;
				while (((img->Height * zoom) < CellsHeight) && ((img->Width * zoom) < CellsWidth));
			}

			//Вырисовка с вычислением центра клетки
			e->Graphics->DrawImage(img, Rectangle(X * CellsWidth + (CellsWidth / 2) - ((img->Width * zoom) / 2) + 3, //Вычисление левой координаты зуммированного изображения
				Y * CellsHeight + (CellsHeight / 2) - ((img->Height * zoom) / 2) + 3, //Вычисление верхней координаты зуммированного изображения
				(img->Width * zoom) - 3, (img->Height * zoom) - 3)); //Вычисление ширины и высоты зуммированного изображения
		}
	
		private: System::Void MainForm_MaximumSizeChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			GameField_pictureBox->Refresh();
		}
	
		private: System::Void MainForm_MinimumSizeChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			GameField_pictureBox->Refresh();
		}
	
		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
		{
			GameField_pictureBox->Refresh();
		}

		private: System::Void MainMenu_toolStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (GameStarted)
			{
				Game_panel->Visible = false;
				GameStarted = false;
				timer1->Enabled = false;
				Start_panel->Visible = true;
				MouseClicked = false;
			}
		}
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		{

		}

		//Вычисление исходных позиций зверя, ловушек и охотников, а также заполнение общего массива координат
		void CreateObjects(int HuntersKol, Hunter** &Hunters, int TrapsKol, Trap** &Traps, Beast* &Beasts, int VerticalCellsCol, int HorizontalCellsCol, int** &tmpMas) 
		{
			Random ^rnd = gcnew Random();
			
			tmpMas = new int*[HuntersKol + TrapsKol + 1];
			for (int i = 0; i < (HuntersKol + TrapsKol + 1); i++)
			{
				tmpMas[i] = new int[2];
			}

			tmpMas[0][0] = rnd->Next(0, HorizontalCellsCol);
			tmpMas[0][1] = rnd->Next(0, VerticalCellsCol);
			if (Difficulty == -1)
				Beasts = new Beast(tmpMas[0][0], tmpMas[0][1], false);
			else if (Difficulty == 1)
				Beasts = new Beast(tmpMas[0][0], tmpMas[0][1], true);

			Traps = new Trap*[TrapsKol];
			for (int i = 0; i < TrapsKol; i++)
			{
				int new_X = 0;
				int new_Y = 0;

				NewRandCoord(&new_X, &new_Y, tmpMas, i + 1, HorizontalCellsCol, VerticalCellsCol, rnd);
				tmpMas[i + 1][0] = new_X;
				tmpMas[i + 1][1] = new_Y;
				Traps[i] = new Trap(new_X, new_Y);
			}

			Hunters = new Hunter*[HuntersKol];
			for (int i = 0; i < HuntersKol; i++)
			{
				int new_X = 0;
				int new_Y = 0;

				NewRandCoord(&new_X, &new_Y, tmpMas, i + TrapsKol + 1, HorizontalCellsCol, VerticalCellsCol, rnd);
				tmpMas[i + TrapsKol + 1][0] = new_X;
				tmpMas[i + TrapsKol + 1][1] = new_Y;
				Hunters[i] = new Hunter(new_X, new_Y);
			}


		}

		//Получение очередной позиции с проверкой на несовпадение с прошлыми позициями
		void NewRandCoord(int* new_X, int* new_Y, int **tmpMas, int Limit, int HorizontalCellsCol, int VerticalCellsCol, Random ^rnd) 
		{
			bool Next = false;
			while (Next != true)
			{
				*new_X = rnd->Next(0, HorizontalCellsCol);
				*new_Y = rnd->Next(0, VerticalCellsCol);

				for (int j = 0; j < Limit; j++)
				{
					if ((*new_X == tmpMas[j][0]) && (*new_Y == tmpMas[j][1]))
					{
						Next = false;
						break;
					}
					else
					{
						Next = true;
					}
				}
			}
			return;
		}
	
		private: System::Void GameField_pictureBox_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
			int X = 0;
			int Y = 0;

			bool isHunter = false;

			for (int i = 0; i < HorizontalCellsKol; i++)
			{
				if ((e->X <= (CellsWidth * (i + 1))) && (e->X > (CellsWidth * i)))
					X = i;
			}
			for (int i = 0; i < VerticalCellsKol; i++)
			{
				if ((e->Y <= (CellsHeight * (i + 1))) && (e->Y >(CellsHeight * i)))
					Y = i;
			}

			for (int i = 0; i < HuntersKol; i++)
			{
				if ((Hunters[i]->GetX() == X) && (Hunters[i]->GetY() == Y))
				{
					isHunter = true;
					HunterNum = i;
					break;
				}
			}

			if (isHunter)
			{
				if (MouseClicked)
				{
					if ((X == XMouseClicked) && (Y == YMouseClicked))
					{
						MouseClicked = false;
						XMouseClicked = -1;
						YMouseClicked = -1;
					}
					else
					{
						MouseClicked = true;
						XMouseClicked = X;
						YMouseClicked = Y;
						AcceptCells = FillAcceptedCellsMas(XMouseClicked, YMouseClicked, tmpMas, false, &AcceptCellsKol, false);
					}
				}
				else
				{
					MouseClicked = true;
					XMouseClicked = X;
					YMouseClicked = Y;
					AcceptCells = FillAcceptedCellsMas(XMouseClicked, YMouseClicked, tmpMas, false, &AcceptCellsKol, false);
				}
			}
			else if ((!isHunter) && MouseClicked && (AcceptCellsKol != 0))
			{
				bool isMove = false;
				for (int i = 0; i < AcceptCellsKol; i++)
				{
					if ((X == AcceptCells[i][0]) && (Y == AcceptCells[i][1]))
					{
						isMove = true;
						break;
					}
				}
				if (isMove)
				{
					Hunters[HunterNum]->Move(X, Y);
					ReplaceCoords(XMouseClicked, YMouseClicked, X, Y, tmpMas);
					MouseClicked = false;
					XMouseClicked = -1;
					YMouseClicked = -1;
					isMove = false;
					HunterNum = -1;
					BeastsMove(Beasts, tmpMas);
				}
			}
		}

		//Проверка доступности клетки
		bool isCellAccept(int X, int Y, int** &tmpMas, bool isBeast, bool BeastKnowsWhereTrap)
		{
			if ((X != -1) && (X < HorizontalCellsKol) && (Y != -1) && (Y < VerticalCellsKol))
			{
				int i = 0;
				if ((!isBeast) && ((X == tmpMas[i][0]) && (Y == tmpMas[i][1])))
				{
					//isAccept = false;
					return false;
				}
				i++;
				if (isBeast)
				{
					if (!BeastKnowsWhereTrap)
						i += TrapsKol;
				}
				for (; i <= (TrapsKol + HuntersKol); i++)
				{
					if ((X == tmpMas[i][0]) && (Y == tmpMas[i][1]))
					{
						//isAccept = false;
						return false;
					}
				}
				return true;
			}
			else
				return false;
		}

		//Заполнение массива доступных для перемещения клеток
		int **FillAcceptedCellsMas(int X, int Y, int** &tmpMas, bool isBeast, int* AcceptCellsKol, bool BeastKnowsWhereTrap)
		{
			int **AcceptCells;
			int kol = 0;
			
			if (isCellAccept((X - 1), Y, tmpMas, isBeast, BeastKnowsWhereTrap))
				kol++;
			if (isCellAccept(X, (Y + 1), tmpMas, isBeast, BeastKnowsWhereTrap))
				kol++;
			if (isCellAccept((X + 1), Y, tmpMas, isBeast, BeastKnowsWhereTrap))
				kol++;
			if (isCellAccept(X, (Y - 1), tmpMas, isBeast, BeastKnowsWhereTrap))
				kol++;
			
			*AcceptCellsKol = kol;
			AcceptCells = new int*[*AcceptCellsKol];
			int i = 0;
			if (isCellAccept((X - 1), Y, tmpMas, isBeast, BeastKnowsWhereTrap))
			{
				AcceptCells[i] = new int[2];
				AcceptCells[i][0] = X - 1;
				AcceptCells[i][1] = Y;
				i++;
			}
			if (isCellAccept(X, (Y + 1), tmpMas, isBeast, BeastKnowsWhereTrap))
			{
				AcceptCells[i] = new int[2];
				AcceptCells[i][0] = X;
				AcceptCells[i][1] = Y + 1;
				i++;
			}
			if (isCellAccept((X + 1), Y, tmpMas, isBeast, BeastKnowsWhereTrap))
			{
				AcceptCells[i] = new int[2];
				AcceptCells[i][0] = X + 1;
				AcceptCells[i][1] = Y;
				i++;
			}			
			if (isCellAccept(X, (Y - 1), tmpMas, isBeast, BeastKnowsWhereTrap))
			{
				AcceptCells[i] = new int[2];
				AcceptCells[i][0] = X;
				AcceptCells[i][1] = Y - 1;
				i++;
			}

			return AcceptCells;
		}

		//Замена старых координат на новые во временном массиве
		void ReplaceCoords(int old_X, int old_Y, int new_X, int new_Y, int** &tmpMas)
		{
			int i = 0;
			for (; i < (HuntersKol + TrapsKol + 1); i++)
			{
				if ((old_X == tmpMas[i][0]) && (old_Y == tmpMas[i][1]))
					break;
			}
			tmpMas[i][0] = new_X;
			tmpMas[i][1] = new_Y;
			return;
		}
		
		//Передвижение зверя
		void BeastsMove(Beast* &Beasts, int** &tmpMas)
		{
			/*for (int i = 0; i < (HuntersKol + TrapsKol + 1); i++)
				MessageBox::Show(tmpMas[i][0] + ";" + tmpMas[i][1]);*/

			Random ^rnd = gcnew Random();

			int old_X = Beasts->GetX();
			int old_Y = Beasts->GetY();
			AcceptCells = FillAcceptedCellsMas(old_X, old_Y, tmpMas, true, &AcceptCellsKol, Beasts->KnowsTrap());
			if (AcceptCellsKol == 0)
			{
				if (!Beasts->KnowsTrap())
				{
					MessageBox::Show("Поздравляю!\nЗверь окружен!");
					Game_panel->Visible = false;
					GameStarted = false;
					timer1->Enabled = false;
					Start_panel->Visible = true;
					MouseClicked = false;
				}
				else
				{
					AcceptCells = FillAcceptedCellsMas(old_X, old_Y, tmpMas, true, &AcceptCellsKol, false);
					if (AcceptCellsKol == 0)
					{
						timer1->Stop();
						MessageBox::Show("Поздравляю!\nЗверь окружен!");
						Game_panel->Visible = false;
						GameStarted = false;
						timer1->Enabled = false;
						Start_panel->Visible = true;
						MouseClicked = false;
					}
					else
					{
						int newPointNum = rnd->Next(0, AcceptCellsKol);
						Beasts->Move(AcceptCells[newPointNum][0], AcceptCells[newPointNum][1]);
						ReplaceCoords(old_X, old_Y, Beasts->GetX(), Beasts->GetY(), tmpMas);
						for (int i = 0; i < TrapsKol; i++)
						{
							if ((Beasts->GetX() == Traps[i]->GetX()) && (Beasts->GetY() == Traps[i]->GetY()))
							{
								MessageBox::Show("Поздравляю!\nЗверь в ловушке!");
								Game_panel->Visible = false;
								GameStarted = false;
								timer1->Enabled = false;
								Start_panel->Visible = true;
								MouseClicked = false;
							}
						}
					}
				}
			}
			else
			{
				int newPointNum = rnd->Next(0, AcceptCellsKol);
				Beasts->Move(AcceptCells[newPointNum][0], AcceptCells[newPointNum][1]);
				ReplaceCoords(old_X, old_Y, Beasts->GetX(), Beasts->GetY(), tmpMas);
				for (int i = 0; i < TrapsKol; i++)
				{
					if ((Beasts->GetX() == Traps[i]->GetX()) && (Beasts->GetY() == Traps[i]->GetY()))
					{
						MessageBox::Show("Поздравляю!\nЗверь в ловушке!");
						Game_panel->Visible = false;
						GameStarted = false;
						timer1->Enabled = false;
						Start_panel->Visible = true;
						MouseClicked = false;
					}
				}
			}

			int HunterStepsNum = 0;
			bool HaveMove = false;
			for (int i = 0; i < HuntersKol; i++)
			{
				AcceptCells = FillAcceptedCellsMas(Hunters[i]->GetX(), Hunters[i]->GetY(), tmpMas, false, &AcceptCellsKol, false);
				HunterStepsNum += AcceptCellsKol;
			}
			if (HunterStepsNum == 0)
				HaveMove = false;
			else
				HaveMove = true;
			if (!HaveMove)
			{
				MessageBox::Show("Поражение!\nХодов нет!");
				Game_panel->Visible = false;
				GameStarted = false;
				timer1->Enabled = false;
				Start_panel->Visible = true;
				MouseClicked = false;
			}
		}

		//Проверка генерации расположения объектов: Если у охотников или зверя доступно меньше 1 возможного шага, то начать ложь (генерация начнется заново)
		bool GenerationTest()
		{
			int HunterStepsNum = 0;

			for (int i = 0; i < HuntersKol; i++)
			{
				AcceptCells = FillAcceptedCellsMas(Hunters[i]->GetX(), Hunters[i]->GetY(), tmpMas, false, &AcceptCellsKol, false);
				HunterStepsNum += AcceptCellsKol;
			}
			if (HunterStepsNum < 1)
				return false;

			AcceptCells = FillAcceptedCellsMas(Beasts->GetX(), Beasts->GetY(), tmpMas, true, &AcceptCellsKol, Beasts->KnowsTrap());
			if (AcceptCellsKol < 1)
				return false;

			return true;
		}
	
		private: System::Void Settings_toolStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (Settings_panel->Visible == false)
				Settings_panel->Visible = true;
			else
				Settings_panel->Visible = false;
		}
	
		private: System::Void Easy_radioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			if (Hard_radioButton->Checked)
			{
				Hard_radioButton->Checked = false;
				Easy_radioButton->Checked = true;
			}
		}

		private: System::Void Hard_radioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			if (Easy_radioButton->Checked)
			{
				Easy_radioButton->Checked = false;
				Hard_radioButton->Checked = true;
			}
		}

		private: System::Void SaveSettings_button_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (Easy_radioButton->Checked)
				Difficulty = -1;
			else if (Hard_radioButton->Checked)
				Difficulty = 1;
			if (GameStarted)
			{
				GameStarted = false;
				timer1->Enabled = false;
				MouseClicked = false;

				bool test = false;
				do
				{
					CreateObjects(HuntersKol, Hunters, TrapsKol, Traps, Beasts, VerticalCellsKol, HorizontalCellsKol, tmpMas);
					test = GenerationTest();
				} while (test == false);

				GameField_pictureBox->Refresh();

				GameStarted = true;
				timer1->Enabled = true;
			}
			Settings_panel->Visible = false;
		}

		private: System::Void CancelSettings_button_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (Difficulty = -1)
			{
				Easy_radioButton->Checked = false;
				Hard_radioButton->Checked = true;
			}
			else if (Difficulty = 1)
			{
				Easy_radioButton->Checked = false;
				Hard_radioButton->Checked = true;
			}
			Settings_panel->Visible = false;
		}
	
		private: System::Void Replay_toolStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (GameStarted)
			{
				GameStarted = false;
				timer1->Enabled = false;
				MouseClicked = false;

				bool test = false;
				do
				{
					CreateObjects(HuntersKol, Hunters, TrapsKol, Traps, Beasts, VerticalCellsKol, HorizontalCellsKol, tmpMas);
					test = GenerationTest();
				} while (test == false);

				GameField_pictureBox->Refresh();

				GameStarted = true;
				timer1->Enabled = true;
			}
		}
	
		private: System::Void Info_toolStripButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (Manual_panel->Visible)
				Manual_panel->Visible = false;
			else
				Manual_panel->Visible = true;
		}
	
		private: System::Void CloseManual_button_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			Manual_panel->Visible = false;
		}
	};
	
}
