#pragma once
#include "Game.h"

namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace Runtime::InteropServices;

	public ref class MyForm : public System::Windows::Forms::Form {
	private:
		Game<float>* game;

		bool a_pressed = false, d_pressed = false;
		int mins, secs, m_secs;
		String ^username, ^death_time_text = "";

		System::Drawing::Image^ img_player = gcnew System::Drawing::Bitmap("player.png");
		System::Drawing::Image^ img_platform = gcnew System::Drawing::Bitmap("platform.png");
		System::Drawing::Image^ img_laser = gcnew System::Drawing::Bitmap("laser.png");

		System::Windows::Forms::Timer^  timer1;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::Label^  label5;
	    System::Windows::Forms::Label^  label6;
		System::Windows::Forms::Label^  label7;
		System::Windows::Forms::Label^  label8;
		System::Windows::Forms::Label^  label9;
		System::Windows::Forms::Panel^  panel1;
		System::Windows::Forms::Panel^  panel2;
		System::Windows::Forms::Panel^  panel3;
		System::Windows::Forms::Panel^  panel4;
		System::Windows::Forms::Panel^  panel5;
		System::Windows::Forms::Button^  button1;
		System::Windows::Forms::Button^  button2;
		System::Windows::Forms::Button^  button3;
		System::Windows::Forms::Button^  button4;
		System::Windows::Forms::Button^  button5;
		System::Windows::Forms::Button^  button6;
		System::Windows::Forms::Button^  button7;
		System::Windows::Forms::ListBox^  listBox1;
		System::Windows::Forms::TextBox^  textBox1;
		
	public:
		MyForm(void) {
			InitializeComponent();
			game = new Game<float>();
			game->setScreenSize(this->Size.Width, this->Size.Height);
			game->Load();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(26, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 42);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Lasers";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(75, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 33);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Pausa";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(211, 26);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Presione \'P\' para continuar\r\nPresione \'Esc\' para volver al menú principal";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(20, 76);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(211, 39);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Tiempo:\r\nPresione \'R\' para volver a empezar\r\nPresione \'Esc\' para volver al menú p"
				L"rincipal";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(64, 24);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(122, 33);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Perdiste";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(30, 117);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Usuario:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(96, 23);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(166, 33);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Cómo jugar";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 74);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(333, 78);
			this->label8->TabIndex = 1;
			this->label8->Text = resources->GetString(L"label8.Text");
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ForeColor = System::Drawing::Color::Red;
			this->label9->Location = System::Drawing::Point(79, 98);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(190, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"*No puede tener más de 18 caracteres";
			this->label9->Visible = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Location = System::Drawing::Point(190, 135);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(279, 263);
			this->panel1->TabIndex = 7;
			this->panel1->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(82, 114);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(81, 20);
			this->textBox1->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(33, 141);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 24);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Jugar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(115, 220);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(48, 24);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Salir";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(33, 180);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 24);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Controles";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(33, 220);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(76, 24);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Historial";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->button3->Location = System::Drawing::Point(139, 180);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(24, 24);
			this->button3->TabIndex = 3;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(158, 144);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(247, 142);
			this->panel2->TabIndex = 8;
			this->panel2->Visible = false;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Location = System::Drawing::Point(158, 144);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(247, 142);
			this->panel3->TabIndex = 9;
			this->panel3->Visible = false;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->button6);
			this->panel4->Controls->Add(this->listBox1);
			this->panel4->Location = System::Drawing::Point(158, 115);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(247, 309);
			this->panel4->TabIndex = 10;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(81, 267);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(91, 23);
			this->button6->TabIndex = 1;
			this->button6->Text = L"Volver";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(26, 50);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(197, 173);
			this->listBox1->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->button7);
			this->panel5->Controls->Add(this->label8);
			this->panel5->Controls->Add(this->label7);
			this->panel5->Location = System::Drawing::Point(124, 178);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(342, 243);
			this->panel5->TabIndex = 11;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(131, 197);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 2;
			this->button7->Text = L"Volver";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	/*funciones*/
	private: void setWindowText() {
		if (game->getCurrentScreen() == game->getScreen(1) || game->getCurrentScreen() == game->getScreen(4)) {
			Text = username + " - ";

			mins = game->getTimer() / 3900;
			secs = game->getTimer() / 65;
			m_secs = ((game->getTimer() % 65) * (1000 / 65));

			if (mins < 10) {
				Text += "0";
			}
			Text += mins.ToString() + ":";
			if (secs < 10) {
				Text += "0";
			}
			Text += secs.ToString() + ":";
			if (m_secs < 100) {
				Text += "0";
				if (m_secs < 10) {
					Text += "0";

				}
			}
			Text += m_secs.ToString();
		}
		else {
			Text = "Lasers";
		}
	}

	private: void visibleScreen() {
		if (game->getCurrentScreen() == game->getScreen(5)) {
			mins = game->getDeathTime() / 3900;
			secs = game->getDeathTime() / 65;
			m_secs = ((game->getDeathTime() % 65) * (1000 / 65));
			death_time_text = "";

			if (mins < 10) {
				death_time_text += "0";
			}
			death_time_text += (mins.ToString() + ":");
			if (secs < 10) {
				death_time_text += "0";
			}
			death_time_text += (secs.ToString() + ":");
			if (m_secs < 100) {
				death_time_text += "0";
				if (m_secs < 10) {
					death_time_text += "0";

				}
			}
			death_time_text += m_secs.ToString();
			label4->Text = L"Tiempo: " + death_time_text + "\r\nPresione \'R\' para volver a empezar\r\nPresione \'Esc\' para volver al menú principal";
		}

		game->getCurrentScreen() == game->getScreen(0) ? showMenuButtons() : hideMenuButtons();
		panel2->Visible = game->getCurrentScreen() == game->getScreen(4);
		panel3->Visible = game->getCurrentScreen() == game->getScreen(5);
		panel4->Visible = game->getCurrentScreen() == game->getScreen(2) || game->getCurrentScreen() == game->getScreen(3);
		panel5->Visible = game->getCurrentScreen() == game->getScreen(6);
	}
	
	private: void hideButton(Button^ button) {
		button->Visible = false;
		button->Enabled = false;
	}

	private: void showButton(Button^ button) {
		button->Visible = true;
		button->Enabled = true;
	}

	private: void hideMenuButtons() {
		label1->Visible = false;
		panel1->Visible = false;
		hideButton(button1);
		hideButton(button2);
		hideButton(button3);
		hideButton(button4);
		hideButton(button5);
	}

	private: void showMenuButtons() {
		label1->Visible = true;
		panel1->Visible = true;
		showButton(button1);
		showButton(button2);
		showButton(button3);
		showButton(button4);
		showButton(button5);
	}

	private: void updateUsername() {
		username = textBox1->Text;
		std::string aux;
		game->MarshalString(username, aux);
		game->setUsername(aux);
	}

	private: void loadLeaderboard() {
		listBox1->Items->Clear();
		listBox1->Items->Add("Mejores Tiempos Locales");
		listBox1->Items->Add(" ");
		String^ aux;
		for (int i = 0; i < 10; i++) {
			if (i == game->getScores()->size()) break;
			aux = marshal_as<String^>(game->getScores()->getPos(i)->getDataString());
			if (i < 9) {
				listBox1->Items->Add((i + 1) + ". " + aux);
			}
			else {
				listBox1->Items->Add((i + 1) + "." + aux);
			}
		}
	}

	private: void loadHistory() {
		listBox1->Items->Clear();
		listBox1->Items->Add("Historial");
		listBox1->Items->Add(" ");
		String^ aux;

		for (int i = 0; i < 10; i++) {
			if (game->getHistory()->isEmpty()) break;
			aux = marshal_as<String^>(game->getHistory()->first()->getDataString());
			listBox1->Items->Add("** " + aux);
			game->getHistory()->pop();
		}
		
	}

	/*loop*/
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = CreateGraphics();
		BufferedGraphicsContext ^context = BufferedGraphicsManager::Current;
		BufferedGraphics ^buffer = context->Allocate(g, this->ClientRectangle);

		game->Run(buffer->Graphics, img_player, img_platform, img_laser);
		setWindowText();
		visibleScreen();

		buffer->Render(g);
		delete buffer;
		delete context;
		delete g;
	}

	/*teclas*/
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::A) {
			game->getPlayer()->setHSpd(-game->getWalkSpd());
			a_pressed = true;
		}

		else if (e->KeyCode == Keys::D) {
			game->getPlayer()->setHSpd(game->getWalkSpd());
			d_pressed = true;
		}

		if (e->KeyCode == Keys::Space && game->isPlatformBelow()) {
			game->getPlayer()->setVSpd(game->getJumpSpd());
		}

		if (e->KeyCode == Keys::P) {
			if (game->getCurrentScreen() == game->getScreen(1)) {
				game->LoadScreen(game->getScreen(4));
			}
			else if (game->getCurrentScreen() == game->getScreen(4)) {
				game->stopScreen();
			}
		}

		if (e->KeyCode == Keys::Escape && (game->getCurrentScreen() == game->getScreen(4) || game->getCurrentScreen() == game->getScreen(5))) {
			game->LoadGame();
			game->stopScreen();
			game->stopScreen();
		}

		if (e->KeyCode == Keys::R && game->getCurrentScreen() == game->getScreen(5)) {
			game->stopScreen();
			game->LoadGame();
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::A) {
			a_pressed = false;
			if (d_pressed) {
				game->getPlayer()->setHSpd(game->getWalkSpd());
			}
		}
		if (e->KeyCode == Keys::D) {
			d_pressed = false;
			if (a_pressed) {
				game->getPlayer()->setHSpd(-game->getWalkSpd());
			}
		}

		if (!a_pressed && !d_pressed) {
			game->getPlayer()->setHSpd(0);
		}
	}
	
	/*botones*/
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		updateUsername();
		if (username != "" && game->getUsername().size() < 19) {
			game->LoadScreen(game->getScreen(1));
			label9->Visible = false;
		}
		label9->Visible = game->getUsername().size() >= 19;
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		game->LoadScreen(game->getScreen(6));
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		game->loadData();
		game->organizeData();
		loadLeaderboard();
		game->LoadScreen(game->getScreen(2));
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		game->loadData();
		game->organizeData2();
		loadHistory();
		game->LoadScreen(game->getScreen(3));
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}

	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		game->stopScreen();
	}

	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		game->stopScreen();
	}
};
}
