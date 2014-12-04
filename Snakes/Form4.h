#pragma once
#include "fstream"
#include "Element.h"
#include "cstdlib"
#include "ctime"
#include "String"
#include "Details.h"
#include "Form6.h"
using namespace std;
namespace Snakes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form4
	/// </summary>
	public ref class Form4 : public System::Windows::Forms::Form
	{
	public:
		Form4(void)
		{
			InitializeComponent();
			Details Format;
			ifstream infile;

			infile.open("Details.dat",ios::in);
			infile.seekg(0);
			infile.read((char*)&Format,sizeof(Details));
			infile.close();

			PlayersNumber = Format.GetPlayersNumber();
			BoardWidth = Format.GetBoardWidth();
			BoardHeight = Format.GetBoardHeight();
			
			remove("Details.dat");

			int i,j,k;
			Element snake,ladder;

			infile.open("Ladders.dat",ios::in|ios::ate);
			int endposition = (int)infile.tellg();
			infile.close();
			int n = endposition/sizeof(Element);
			LaddersPositionsTop = gcnew array<System::Windows::Forms::PictureBox^>(n);
			LaddersPositionsBottom = gcnew array<System::Windows::Forms::PictureBox^>(n);
			if(endposition>0)
				for(k=0;k<n;k++)
				{
					infile.open("Ladders.dat",ios::in);
					infile.seekg(k*sizeof(Element));
					infile.read((char*)&ladder,sizeof(Element));
					infile.close();

					LaddersPositionsTop[k] = gcnew System::Windows::Forms::PictureBox();
					LaddersPositionsTop[k]->BackColor = System::Drawing::Color::Orange;
					LaddersPositionsTop[k]->Location = System::Drawing::Point(305+ladder.SX()*45,517-ladder.SY()*45);
					LaddersPositionsTop[k]->Name = (Convert::ToString(1+ladder.SX()+ladder.SY()*(BoardWidth)));
					LaddersPositionsTop[k]->Size = System::Drawing::Size(30, 30);
					LaddersPositionsTop[k]->TabIndex = ladder.SY()*(BoardWidth)+ladder.SX()+1;
				   	LaddersPositionsTop[k]->TabStop = false;

					this->Controls->Add(LaddersPositionsTop[k]);
				}

			if(endposition>0)
				for(k=0;k<n;k++)
				{
					infile.open("Ladders.dat",ios::in);
					infile.seekg(k*sizeof(Element));
					infile.read((char*)&ladder,sizeof(Element));
					infile.close();

					LaddersPositionsBottom[k] = gcnew System::Windows::Forms::PictureBox();
					LaddersPositionsBottom[k]->BackColor = System::Drawing::Color::Orange;
					LaddersPositionsBottom[k]->Location = System::Drawing::Point(305+ladder.EX()*45,517-ladder.EY()*45);
					LaddersPositionsBottom[k]->Name = (Convert::ToString(1+ladder.EX()+ladder.EY()*(BoardWidth)));
					LaddersPositionsBottom[k]->Size = System::Drawing::Size(30, 30);
					LaddersPositionsBottom[k]->TabIndex = ladder.EY()*(BoardWidth)+ladder.EX()+1;
				   	LaddersPositionsBottom[k]->TabStop = false;

					this->Controls->Add(LaddersPositionsBottom[k]);
				}

				infile.open("Snakes.dat",ios::in|ios::ate);
				endposition = (int)infile.tellg();
				infile.close();
				n = endposition/sizeof(Element);
				SnakesPositionsHead = gcnew array<System::Windows::Forms::PictureBox^>(n);
				SnakesPositionsTail = gcnew array<System::Windows::Forms::PictureBox^>(n);
			if(endposition>0)
				for(k=0;k<n;k++)
				{
					infile.open("Snakes.dat",ios::in);
					infile.seekg(k*sizeof(Element));
					infile.read((char*)&snake,sizeof(Element));
					infile.close();
					SnakesPositionsHead[k] = gcnew System::Windows::Forms::PictureBox();
					SnakesPositionsHead[k]->BackColor = System::Drawing::Color::Green;
					SnakesPositionsHead[k]->Location = System::Drawing::Point(305+snake.SX()*45,517-snake.SY()*45);
					SnakesPositionsHead[k]->Name = (Convert::ToString(1+snake.SX()+snake.SY()*(BoardWidth)));
					SnakesPositionsHead[k]->Size = System::Drawing::Size(30, 30);
					SnakesPositionsHead[k]->TabIndex = snake.SY()*(BoardWidth)+snake.SX()+1;
				   	SnakesPositionsHead[k]->TabStop = false;

					this->Controls->Add(SnakesPositionsHead[k]);
				}
			
			if(endposition>0)
				for(k=0;k<n;k++)
				{
					infile.open("Snakes.dat",ios::in);
					infile.seekg(k*sizeof(Element));
					infile.read((char*)&snake,sizeof(Element));
					infile.close();
					SnakesPositionsTail[k] = gcnew System::Windows::Forms::PictureBox();
					SnakesPositionsTail[k]->BackColor = System::Drawing::Color::Green;
					SnakesPositionsTail[k]->Location = System::Drawing::Point(305+snake.EX()*45,517-snake.EY()*45);
					SnakesPositionsTail[k]->Name = (Convert::ToString(1+snake.EX()+snake.EY()*(BoardWidth)));
					SnakesPositionsTail[k]->Size = System::Drawing::Size(30, 30);
					SnakesPositionsTail[k]->TabIndex = snake.EY()*(BoardWidth)+snake.EX()+1;
				   	SnakesPositionsTail[k]->TabStop = false;

					this->Controls->Add(SnakesPositionsTail[k]);
				}
			Cells = gcnew array<System::Windows::Forms::PictureBox^,2>(BoardHeight,BoardWidth);

			for(i=0;i<BoardHeight;i++)
				for(j=0;j<BoardWidth;j++)
				{	
					Cells[i,j] = gcnew System::Windows::Forms::PictureBox();
					Cells[i,j]->BackColor = System::Drawing::Color::White;
					Cells[i,j]->Location = System::Drawing::Point(300+j*45,512-i*45);
					
					if(i%2==0)
					Cells[i,j]->Name = (Convert::ToString(1+j+i*(BoardWidth)));
					else Cells[i,j]->Name = (Convert::ToString(-j+(i+1)*(BoardWidth)));
					Cells[i,j]->Size = System::Drawing::Size(40, 40);
					Cells[i,j]->TabIndex = i*(BoardWidth)+j+1;
				   	Cells[i,j]->TabStop = false;
					
					this->Controls->Add(Cells[i,j]);
				}
	
			Cells[0,0]->BackColor = System::Drawing::Color::Black;

			Positions = gcnew array<System::Windows::Forms::Label^,2>(BoardHeight,BoardWidth);
			for(i=0;i<BoardHeight;i++)
				for(j=0;j<BoardWidth;j++)
				{
					Positions[i,j] = gcnew System::Windows::Forms::Label();
					Positions[i,j]->Location = System::Drawing::Point(310+j*45,528-i*45);
					Positions[i,j]->Text = Cells[i,j]->Name;
					Positions[i,j]->BackColor = System::Drawing::Color::White;
					this->Controls->Add(Positions[i,j]);
					Positions[i,j]->BringToFront();
					Positions[i,j]->AutoSize = true;
				}
		}
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label10;

	public: 
	private:
		array<System::Windows::Forms::PictureBox^,2>^ Cells;
		array<System::Windows::Forms::Label^,2>^ Positions;
		array<System::Windows::Forms::PictureBox^>^ SnakesPositionsHead;
		array<System::Windows::Forms::PictureBox^>^ SnakesPositionsTail;
		array<System::Windows::Forms::PictureBox^>^ LaddersPositionsTop;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::PictureBox^  pictureBox2;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::PictureBox^  pictureBox1;




		 array<System::Windows::Forms::PictureBox^>^ LaddersPositionsBottom;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::RichTextBox^  richTextBox4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	public:
		System::String^ PlayerA;
		System::String^ PlayerB;
		System::String^ PlayerC;
	private:
		int PlayersNumber;
		int BoardWidth;
		int BoardHeight;
		int PositionA;
		int PositionB;
		int PositionC;
		int ScoreA;
		int ScoreB;
		int ScoreC;
	
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(40, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Player 1 :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Blue;
			this->label2->Location = System::Drawing::Point(43, 126);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Score : ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Blue;
			this->label3->Location = System::Drawing::Point(104, 122);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"0";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Blue;
			this->button1->Location = System::Drawing::Point(45, 75);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 39);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Roll";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form4::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->Enabled = false;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(186, 75);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(56, 39);
			this->richTextBox1->TabIndex = 10;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::White;
			this->richTextBox2->Enabled = false;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(186, 232);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(56, 39);
			this->richTextBox2->TabIndex = 15;
			this->richTextBox2->Text = L"";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Red;
			this->button2->Location = System::Drawing::Point(43, 232);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(106, 39);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Roll";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form4::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(104, 277);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(24, 25);
			this->label4->TabIndex = 13;
			this->label4->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(43, 281);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Score : ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(40, 193);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(122, 29);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Player 2 :";
			// 
			// richTextBox3
			// 
			this->richTextBox3->BackColor = System::Drawing::Color::White;
			this->richTextBox3->Enabled = false;
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox3->Location = System::Drawing::Point(186, 371);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(56, 39);
			this->richTextBox3->TabIndex = 20;
			this->richTextBox3->Text = L"";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Yellow;
			this->button3->Location = System::Drawing::Point(43, 371);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 39);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Roll";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form4::button3_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Yellow;
			this->label8->Location = System::Drawing::Point(43, 421);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(63, 20);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Score : ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Yellow;
			this->label9->Location = System::Drawing::Point(42, 332);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(122, 29);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Player 3 :";
			// 
			// richTextBox4
			// 
			this->richTextBox4->BackColor = System::Drawing::Color::White;
			this->richTextBox4->Enabled = false;
			this->richTextBox4->Location = System::Drawing::Point(43, 492);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->Size = System::Drawing::Size(210, 51);
			this->richTextBox4->TabIndex = 21;
			this->richTextBox4->Text = L"";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Yellow;
			this->label7->Location = System::Drawing::Point(104, 417);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(24, 25);
			this->label7->TabIndex = 22;
			this->label7->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(95, 465);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(112, 24);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Message : ";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(723, 590);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(43, 13);
			this->label12->TabIndex = 31;
			this->label12->Text = L"SNAKE";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Green;
			this->pictureBox2->Location = System::Drawing::Point(660, 582);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(41, 38);
			this->pictureBox2->TabIndex = 30;
			this->pictureBox2->TabStop = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(431, 590);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(51, 13);
			this->label11->TabIndex = 29;
			this->label11->Text = L"LADDER";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Orange;
			this->pictureBox1->Location = System::Drawing::Point(369, 582);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(41, 38);
			this->pictureBox1->TabIndex = 28;
			this->pictureBox1->TabStop = false;
			// 
			// Form4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::LightSkyBlue;
			this->ClientSize = System::Drawing::Size(882, 629);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form4";
			this->Text = L"The Board";
			this->Load += gcnew System::EventHandler(this, &Form4::Form4_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form4_Load(System::Object^  sender, System::EventArgs^  e) {
				 srand((unsigned int) time(NULL));
				 label1->Text = PlayerA;
				 label6->Text = PlayerB;
				 label9->Text = PlayerC;
				 PositionA=0;
				 PositionB=0;
				 PositionC=0;
				 ScoreA=0;
				 ScoreB=0;
				 ScoreC=0;
				 button2->Enabled = false;	
				 button3->Enabled = false;
			 }

	private: int GetX(int position)
			 {
				 if(((int)position/BoardWidth)%2==0)
				 {
					return (position%BoardWidth);
				 }
				 else
				 {
					return BoardWidth-1-(position%BoardWidth);
				 }
			 }

	private: int GetY(int position)
			 {
				return (int)(position/BoardWidth);
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 int Dice;
				 ScoreA++;
				 Element c;
				 ifstream infile;
				 Dice = rand()%6+1;
				 richTextBox1->Text = Convert::ToString(Dice);
				 
				 if(PositionA!=0&&PositionB!=PositionA&&PositionC!=PositionA)
					Cells[GetY(PositionA),GetX(PositionA)]->BackColor = System::Drawing::Color::White;
				 
				 PositionA+=Dice;

				 if(PositionA > BoardHeight*BoardWidth-1)
				 {
					PositionA-=Dice;
					Cells[GetY(PositionA),GetX(PositionA)]->BackColor = System::Drawing::Color::Blue;
				 }
				 else if(PositionA == BoardHeight*BoardWidth-1)
				 {
					Cells[GetY(PositionA),GetX(PositionA)]->BackColor = System::Drawing::Color::Blue;
					richTextBox4->Text = String::Concat(PlayerA," is the winner!");
					Form6^ form6 = gcnew Form6();
					form6->Score = ScoreA;
					form6->Player = PlayerA;
					form6->Show();
					Form4::Close();
				 }
				 else if(PositionA<BoardHeight*BoardWidth-1)
				 {
					infile.open("Snakes.dat",ios::in|ios::ate);
					int endposition = (int)infile.tellg();
					infile.close();
					int n = endposition/sizeof(Element);

					int i;
					if(endposition>0)
					{
						for(i=0;i<n;i++)
						{
							infile.open("Snakes.dat",ios::in);
							infile.seekg(i*sizeof(Element));
							infile.read((char*)&c,sizeof(Element));
							infile.close();

							if(c.S()==PositionA)  //snake's mouth
							{
								richTextBox4->Text = String::Concat("Snake at Board position ",Convert::ToString(PositionA+1)," got you!");
								PositionA = c.E();
							}
						 }

						 for(i=0;i<n;i++)
						 {
							infile.open("Ladders.dat",ios::in);
							infile.seekg(i*sizeof(Element));
							infile.read((char*)&c,sizeof(Element));
							infile.close();

							if(c.E()==PositionA)  //Ladders's bottom
							{
								richTextBox4->Text = String::Concat("You are up through ladder at position ",Convert::ToString(PositionA+1),"!");
								PositionA = c.S();
							}
						 }
					 Cells[GetY(PositionA),GetX(PositionA)]->BackColor = System::Drawing::Color::Blue;
					}
				}

				 button1->Enabled = false;
				 button2->Enabled = true;
				 label3->Text = Convert::ToString(ScoreA);
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 ScoreB++;
				 int Dice;
				 Element c;
				 ifstream infile;
				 Dice = rand()%6+1;
				 richTextBox2->Text = Convert::ToString(Dice);
			
				 if(PositionB!=0&&PositionA!=PositionB&&PositionC!=PositionB)
					Cells[GetY(PositionB),GetX(PositionB)]->BackColor = System::Drawing::Color::White;
				 PositionB+=Dice;

				 if(PositionB > BoardHeight*BoardWidth-1)
				 {
					PositionB-=Dice;
					Cells[GetY(PositionB),GetX(PositionB)]->BackColor = System::Drawing::Color::Red;
				 }
				 else if(PositionB == BoardHeight*BoardWidth-1)
				 {
					Cells[GetY(PositionB),GetX(PositionB)]->BackColor = System::Drawing::Color::Red;
					richTextBox4->Text = String::Concat(PlayerB," is the winner!");
					Form6^ form6 = gcnew Form6();
					form6->Score = ScoreB;
					form6->Player = PlayerB;
					form6->Show();
					remove("Snakes.dat");
					remove("Ladders.dat");
					Form4::Close();
				 }
				 else if(PositionB<BoardHeight*BoardWidth-1)
				 {
					infile.open("Snakes.dat",ios::in|ios::ate);
					int endposition = (int)infile.tellg();
					infile.close();
					int n = endposition/sizeof(Element);

					 int i;
					if(endposition>0)
					{
					 for(i=0;i<n;i++)
					 {
						infile.open("Snakes.dat",ios::in);
						infile.seekg(i*sizeof(Element));
						infile.read((char*)&c,sizeof(Element));
						infile.close();

						if(c.S()==PositionB)  //snake's mouth
						{
							richTextBox4->Text = String::Concat("Snake at Board position ",Convert::ToString(PositionB+1)," got you!");
							PositionB = c.E();
						}
				   	 }

					 for(i=0;i<n;i++)
					 {
						infile.open("Ladders.dat",ios::in);
						infile.seekg(i*sizeof(Element));
						infile.read((char*)&c,sizeof(Element));
						infile.close();

						if(c.E()==PositionB)  //Ladders's bottom
						{
							richTextBox4->Text = String::Concat("You are up through ladder at position ",Convert::ToString(PositionB+1),"!");
							PositionB = c.S();
						}
					 }
					}
				  Cells[GetY(PositionB),GetX(PositionB)]->BackColor = System::Drawing::Color::Red;
				 }

				 button2->Enabled = false;
				 label4->Text = Convert::ToString(ScoreB);				 
				 if(PlayersNumber == 3)
				 {
					button3->Enabled = true;
				 }
				 else
				 {
					button1->Enabled = true;
				 }
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 ScoreC++;
				 int Dice;
				 Element c;
				 ifstream infile;
				 Dice = rand()%6+1;
				 richTextBox3->Text = Convert::ToString(Dice);
				 
				 if(PositionC!=0&&PositionB!=PositionC&&PositionA!=PositionC)
					Cells[GetY(PositionC),GetX(PositionC)]->BackColor = System::Drawing::Color::White;
				 
				 PositionC+=Dice;

				 if(PositionC > BoardHeight*BoardWidth-1)
				 {
						PositionC-=Dice;
						Cells[GetY(PositionC),GetX(PositionC)]->BackColor = System::Drawing::Color::Yellow;
				 }
				 else if(PositionC == BoardHeight*BoardWidth-1)
				 {
					richTextBox4->Text = String::Concat(PlayerC," is the winner!");
					Form6^ form6 = gcnew Form6();
					form6->Player = PlayerC;
					form6->Score = ScoreC;
					form6->Show();
					remove("Snakes.dat");
					remove("Ladders.dat");
					Form4::Close();
					Cells[GetY(PositionC),GetX(PositionC)]->BackColor = System::Drawing::Color::Yellow;
				 }
				 
				 else if(PositionC<BoardHeight*BoardWidth-1)
				 {
					infile.open("Snakes.dat",ios::in|ios::ate);
					int endposition = (int)infile.tellg();
					infile.close();
					int n = endposition/sizeof(Element);

					int i;
					
					if(endposition>0)
					{
						for(i=0;i<n;i++)
			   			{
							infile.open("Snakes.dat",ios::in);
							infile.seekg(i*sizeof(Element));
							infile.read((char*)&c,sizeof(Element));
							infile.close();

							if(c.S()==PositionC)  //snake's mouth
							{
								richTextBox4->Text = String::Concat("Snake at Board position ",Convert::ToString(PositionC+1)," got you!");
								PositionC = c.E();
							}
						}

						for(i=0;i<n;i++)
						{
							infile.open("Ladders.dat",ios::in);
							infile.seekg(i*sizeof(Element));
							infile.read((char*)&c,sizeof(Element));
							infile.close();

							if(c.E()==PositionC)  //Ladders's bottom
							{
								richTextBox4->Text = String::Concat("You are up through ladder at position ",Convert::ToString(PositionC+1),"!");
								PositionC = c.S();
							}
						}
					 Cells[GetY(PositionC),GetX(PositionC)]->BackColor = System::Drawing::Color::Yellow;
					 }
				 }
				 button3->Enabled = false;
				 button1->Enabled = true;
				 label7->Text = Convert::ToString(ScoreC);
		 }
};
}
