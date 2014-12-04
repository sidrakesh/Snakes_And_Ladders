#pragma once
#include "fstream"
#include "HighScores.h"
#include "msclr/marshal.h"
#include "msclr/marshal_cppstd.h"
using namespace std;
namespace Snakes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form6
	/// </summary>
	public ref class Form6 : public System::Windows::Forms::Form
	{
	public:
		Form6(void)
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
		~Form6()
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
	private: System::Windows::Forms::Label^  label4;
	public: 
		int Score;
		System::String^ Player;
	private: System::Windows::Forms::Label^  label5;
	public: 
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(115, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 36);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Congratulations!";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(38, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(38, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(38, 147);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(38, 177);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 13);
			this->label5->TabIndex = 4;
			// 
			// Form6
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(438, 216);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form6";
			this->Text = L"Form6";
			this->Load += gcnew System::EventHandler(this, &Form6::Form6_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form6_Load(System::Object^  sender, System::EventArgs^  e) {
				label2->Text = String::Concat(Player," is the winner!");
				label3->Text = String::Concat("Score : ",Convert::ToString(Score));
				ComparePreviousYearsHighscore();
			 }

private: void StringToChar(char* str,string s)
		 {
		 int i;
		 for(i=0;i < (int)s.length();i++)
			 str[i] = s[i];
		 str[i]='\0';
		 }
private: void ComparePreviousYearsHighscore()
		 {
			ifstream infile;
			ofstream outfile;
			HighScores High,HighC;
			System::String^ PlayerName;
			string s;
			char str[100];
			msclr::interop::marshal_context context;

			infile.open("HighScores.dat",ios::in|ios::ate);
			int endposition = (int)infile.tellg();
			infile.close();
			int n = endposition/sizeof(HighScores);
			int i,j,flag=0;

			if(endposition<=0)
			{
				s = context.marshal_as<std::string>(Player);
				StringToChar(str,s);
				High.SetName(str);
				High.SetScore(Score);
				flag=1;
				outfile.open("HighScores.dat",ios::in|ios::app);
				outfile.write((char*)&High,sizeof(HighScores));
				outfile.close();
				label4->Text = "New HighScore!";
			}
			else
			{
				for(i=0;i<n;i++)
				{
					infile.open("HighScores.dat",ios::in);
					infile.seekg(i*sizeof(HighScores));
					infile.read((char*)&High,sizeof(HighScores));
					infile.close();

					PlayerName = gcnew String(High.GetName());

					if(String::Compare(Player,PlayerName)==0&&High.GetScore()<Score)
					{
						flag=1;
						label4->Text = String::Concat("Previous highscore : ",Convert::ToString(High.GetScore()));
						label5->Text = "New highscore !!!";
						High.SetScore(Score);
						for(j=0;j<n;j++)
						{
							if(j!=i)
							{
								infile.open("HighScores.dat",ios::in);
								infile.seekg(j*sizeof(HighScores));
								infile.read((char*)&HighC,sizeof(HighScores));
								infile.close();

								outfile.open("NewHighScores.dat",ios::out|ios::app);
								outfile.write((char*)&HighC,sizeof(HighScores));
								outfile.close();
							}
							else
							{
								outfile.open("NewHighScores.dat",ios::out|ios::app);
								outfile.write((char*)&High,sizeof(HighScores));
								outfile.close();
							}
						}
						outfile.open("HighScores.dat",ios::trunc);
						outfile.close();

						for(i=0;i<n;i++)
						{
							infile.open("NewHighScores.dat",ios::in);
							infile.seekg(i*sizeof(HighScores));
							infile.read((char*)&High,sizeof(HighScores));
							infile.close();

							outfile.open("HighScores.dat",ios::out|ios::app);
							outfile.write((char*)&High,sizeof(HighScores));
							outfile.close();
						}
						remove("NewHighScores.dat");
						break;
					}
				
					else if(String::Compare(Player,PlayerName)==0&&High.GetScore()>=Score)
					{
						flag=1;
						label4->Text = String::Concat("Previous highscore : ",Convert::ToString(High.GetScore()));
						break;
					}
				}	
			}
			
		 if(flag==0)
		 {
			s = context.marshal_as<std::string>(Player);
			StringToChar(str,s);
			High.SetName(str);
			High.SetScore(Score);

			outfile.open("HighScores.dat",ios::out|ios::app);
			outfile.write((char*)&High,sizeof(HighScores));
			outfile.close();
		 }
	}
};
}
