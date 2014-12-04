#pragma once

#include "Form5.h"
#include "Form2.h"
#include "Form7.h"
#include "Details.h"
#include "fstream"
using namespace std;
namespace Snakes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 





	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  howToPlayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  howToPlayToolStripMenuItem1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->howToPlayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->howToPlayToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Orange;
			this->button1->Location = System::Drawing::Point(147, 190);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(169, 53);
			this->button1->TabIndex = 6;
			this->button1->Text = L"New Game";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LawnGreen;
			this->button2->Location = System::Drawing::Point(147, 249);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(169, 53);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Options";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->howToPlayToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(464, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"E&xit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// howToPlayToolStripMenuItem
			// 
			this->howToPlayToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->howToPlayToolStripMenuItem1});
			this->howToPlayToolStripMenuItem->Name = L"howToPlayToolStripMenuItem";
			this->howToPlayToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->howToPlayToolStripMenuItem->Text = L"Help";
			// 
			// howToPlayToolStripMenuItem1
			// 
			this->howToPlayToolStripMenuItem1->Name = L"howToPlayToolStripMenuItem1";
			this->howToPlayToolStripMenuItem1->Size = System::Drawing::Size(152, 22);
			this->howToPlayToolStripMenuItem1->Text = L"How to play\?";
			this->howToPlayToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::howToPlayToolStripMenuItem1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LemonChiffon;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(464, 308);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Welcome!!";
			this->TransparencyKey = System::Drawing::Color::Transparent;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 Details det;
				 srand((unsigned int)time(NULL));
				 ifstream infile;
				 ofstream outfile;
				 Element Snake,Ladder;
				 int i,Start,End;
				 infile.open("Details.dat",ios::ate|ios::in);
				 
				 if((int)infile.tellg()<=0)
				 {
					 det.SetPlayersNumber(2);
					 det.SetBoardWidth(8);
					 det.SetBoardHeight(8);
					 infile.close();
				   	 outfile.open("Details.dat",ios::out|ios::app);
					 outfile.write((char*)&det,sizeof(Details));
					 outfile.close();

					 for(i=0;i<4;i++)
					 {
						 do{
						 Start = rand()%64+1;
						 End = rand()%64+1;
						 }while(Start<End);

						 Snake.SetElementStart(Start,8);
						 Snake.SetElementEnd(End,8);

						 outfile.open("Snakes.dat",ios::out|ios::app);
						 outfile.write((char*)&Snake,sizeof(Element));
						 outfile.close();
					 }

					 for(i=0;i<4;i++)
					 {
						 do{
						 Start = rand()%64+1;
						 End = rand()%64+1;
						 }while(Start<End);

						 Ladder.SetElementStart(Start,8);
						 Ladder.SetElementEnd(End,8);

						 outfile.open("Ladders.dat",ios::out|ios::app);
						 outfile.write((char*)&Ladder,sizeof(Element));
						 outfile.close();
					 }

				 }
				 else infile.close();

				 Form5^ form5 = gcnew Form5();
				 form5->Show();
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 	 Form2^ form2 = gcnew Form2();
				 form2->Show();
		 }
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Form1::Close();
		 }
private: System::Void howToPlayToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 Form7^ form7 = gcnew Form7();
			 form7->Show();
		 }
};
}

