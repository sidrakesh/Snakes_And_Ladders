#pragma once
#include "Element.h"
#include "fstream"
#include "Details.h"

namespace Snakes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form3
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
	public:
		Form3(void)
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
		~Form3()
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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	public:
		int PlayersNumber;
	private:
		int SnakesNumber;
		int LaddersNumber;
		int BoardWidth;
		int BoardHeight;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Width of Board : ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Height of Board : ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(40, 150);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Set snake : ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(136, 49);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form3::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(136, 83);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form3::textBox2_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(110, 150);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(85, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Snake Head at :";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(216, 147);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(45, 20);
			this->textBox3->TabIndex = 8;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(110, 202);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(102, 13);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Number of snakes : ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(225, 202);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(13, 13);
			this->label11->TabIndex = 20;
			this->label11->Text = L"0";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(216, 172);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(45, 20);
			this->textBox10->TabIndex = 25;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(110, 175);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(76, 13);
			this->label18->TabIndex = 23;
			this->label18->Text = L"Snake Tail at :";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gold;
			this->button1->Location = System::Drawing::Point(330, 158);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 30);
			this->button1->TabIndex = 26;
			this->button1->Text = L"Add snake";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form3::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Gold;
			this->button2->Location = System::Drawing::Point(330, 249);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 30);
			this->button2->TabIndex = 34;
			this->button2->Text = L"Add ladder";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form3::button2_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(216, 263);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(45, 20);
			this->textBox4->TabIndex = 33;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(110, 266);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 13);
			this->label4->TabIndex = 32;
			this->label4->Text = L"Ladder Tail at :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(225, 293);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 31;
			this->label6->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(110, 293);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(102, 13);
			this->label7->TabIndex = 30;
			this->label7->Text = L"Number of ladders : ";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(216, 238);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(45, 20);
			this->textBox5->TabIndex = 29;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(110, 241);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(87, 13);
			this->label8->TabIndex = 28;
			this->label8->Text = L"Ladder Head at :";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(40, 241);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(64, 13);
			this->label9->TabIndex = 27;
			this->label9->Text = L"Set ladder : ";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Gold;
			this->button3->Location = System::Drawing::Point(330, 49);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(91, 54);
			this->button3->TabIndex = 35;
			this->button3->Text = L"Set Dimensions";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form3::button3_Click);
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SandyBrown;
			this->ClientSize = System::Drawing::Size(527, 348);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form3";
			this->Text = L"Settings";
			this->Load += gcnew System::EventHandler(this, &Form3::Form3_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Form3_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 Element Snake,fe; 
			 ifstream infile;
			 ofstream outfile;
			 int Head,Tail;
			 int flag = 0;
			 Head = Convert::ToInt32(textBox3->Text);
			 Tail = Convert::ToInt32(textBox10->Text);
			 BoardWidth = Convert::ToInt32(textBox1->Text);
			 BoardHeight = Convert::ToInt32(textBox2->Text);
			 if(!(BoardWidth<=12&&BoardWidth>=5))
				 MessageBox::Show("Enter the width in the range 5 -12","!");
			 else if(!(BoardHeight<=12&&BoardHeight>=5))
				 MessageBox::Show("Enter the height in the range 5 -12","!");
			 else
			 { 
				if(Head<=Tail)
					 MessageBox::Show("Head must be greater than tail","!");
				else if(Head>=BoardWidth*BoardHeight||Head<=0)
					 MessageBox::Show("Index of head is incorrect","!");
				else if(Tail>=BoardWidth*BoardHeight||Tail<=0)
					 MessageBox::Show("Index of tail is incorrect","!");
				else if(Head==BoardWidth*BoardHeight)
					 MessageBox::Show("Top of a snake cannot be at the last element!","!");
				else
				{
					Snake.SetElementStart(Head,BoardWidth);
					Snake.SetElementEnd(Tail,BoardWidth);
									
					infile.open("Snakes.dat",ios::in|ios::ate);
					int endposition = (int)infile.tellg();
					infile.close();
					int i,n;
					n = endposition/sizeof(Element);
					
					if(endposition<=0)
					{
						outfile.open("Snakes.dat",ios::out|ios::app);
						outfile.write((char*)&Snake,sizeof(Element));
						outfile.close();
						flag=1;
						SnakesNumber = 1;
						label11->Text = Convert::ToString(SnakesNumber);
					}
					else
					{
						

							for(i=0;i<n;i++)
							{
								infile.open("Snakes.dat",ios::in);
								infile.seekg(i*sizeof(Element));
								infile.read((char*)&fe,sizeof(Element));
								infile.close();
							
								if(fe.S()==Head-1||fe.E()==Tail-1||fe.S()==Tail-1||fe.E()==Head-1)
								{
									flag = 1;
									MessageBox::Show("This snake is coincident with another element","!");
									break;
								}
							}
					
						}	
						infile.open("Ladders.dat",ios::in|ios::ate);
						endposition = (int)infile.tellg();
						infile.close();
						n = endposition/sizeof(Element);

						if(endposition>0)
						for(i=0;i<n;i++)
						{
							infile.open("Ladders.dat",ios::in);
							infile.seekg(i*sizeof(Element));
							infile.read((char*)&fe,sizeof(Element));
							infile.close();
						
							if(fe.S()==Head-1||fe.E()==Tail-1||fe.S()==Tail-1||fe.E()==Head-1)
							{
								flag = 1;
								MessageBox::Show("This snake is coincident with another element","!");
								break;
							}
						}

  						if(flag==0)
						{
							outfile.open("Snakes.dat",ios::out|ios::app);
							outfile.write((char*)&Snake,sizeof(Element));
							outfile.close();

							SnakesNumber++;
							label11->Text = Convert::ToString(SnakesNumber);
						}
					
					
			 
				 }
			 
			 }
			 
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 Element Ladder,fe; 
			 ifstream infile;
			 ofstream outfile;
			 int Top,Bottom;
			 int flag = 0;
			 Top = Convert::ToInt32(textBox5->Text);
			 Bottom = Convert::ToInt32(textBox4->Text);
			 BoardWidth = Convert::ToInt32(textBox1->Text);
			 BoardHeight = Convert::ToInt32(textBox2->Text);
			 if(!(BoardWidth<=12&&BoardWidth>=5))
				 MessageBox::Show("Enter the width in the range 5 -12","!");
			 else if(!(BoardHeight<=12&&BoardHeight>=5))
				 MessageBox::Show("Enter the height in the range 5 -12","!");
			 else
			 { 
				if(Top<=Bottom)
					 MessageBox::Show("Top must be greater than Bottom","!");
				else if(Top>=BoardWidth*BoardHeight||Top<=0)
					 MessageBox::Show("Index of Top is incorrect","!");
				else if(Bottom>=BoardWidth*BoardHeight||Bottom<=0)
					 MessageBox::Show("Index of Bottom is incorrect","!");
				else if(Bottom==1)
					 MessageBox::Show("Bottom of Ladder cannot be one!","!");
				else
				{
					Ladder.SetElementStart(Top,BoardWidth);
					Ladder.SetElementEnd(Bottom,BoardWidth);
									
					infile.open("Ladders.dat",ios::in|ios::ate);
					int endposition = (int)infile.tellg();
					infile.close();
					int i,n;
					n = endposition/sizeof(Element);
					
					if(endposition<=0)
					{
						outfile.open("Ladders.dat",ios::out|ios::app);
						outfile.write((char*)&Ladder,sizeof(Element));
						outfile.close();
						flag=1;
						LaddersNumber = 1;
						label6->Text = Convert::ToString(LaddersNumber);
					}
					else
					{
						

							for(i=0;i<n;i++)
							{
								infile.open("Ladders.dat",ios::in);
								infile.seekg(i*sizeof(Element));
								infile.read((char*)&fe,sizeof(Element));
								infile.close();
							
								if(fe.S()==Top-1||fe.E()==Bottom-1||fe.S()==Bottom-1||fe.E()==Top-1)
								{
									flag = 1;
									MessageBox::Show("This Ladder is coincident with another element","!");
									break;
								}
							}
					
						}	
						infile.open("Snakes.dat",ios::in|ios::ate);
						endposition = (int)infile.tellg();
						infile.close();
						n = endposition/sizeof(Element);

						if(endposition>0)
						for(i=0;i<n;i++)
						{
							infile.open("Snakes.dat",ios::in);
							infile.seekg(i*sizeof(Element));
							infile.read((char*)&fe,sizeof(Element));
							infile.close();
						
							if(fe.S()==Top-1||fe.E()==Bottom-1||fe.S()==Bottom-1||fe.E()==Top-1)
							{
								flag = 1;
								MessageBox::Show("This Ladder is coincident with another element","!");
								break;
							}
						}

  						if(flag==0)
						{
							outfile.open("Ladders.dat",ios::out|ios::app);
							outfile.write((char*)&Ladder,sizeof(Element));
							outfile.close();

							LaddersNumber++;
							label6->Text = Convert::ToString(LaddersNumber);
						}
					
					
			 
				 }
			 
			 }
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			BoardWidth = Convert::ToInt32(textBox1->Text);
			BoardHeight = Convert::ToInt32(textBox2->Text);

			Details Custom;
			Custom.SetBoardWidth(BoardWidth);
			Custom.SetBoardHeight(BoardHeight);
			Custom.SetPlayersNumber(PlayersNumber);

			ofstream outfile;
			outfile.open("Details.dat",ios::out|ios::app);
			outfile.write((char*)&Custom,sizeof(Details));			
			outfile.close();
		 }
};
}
