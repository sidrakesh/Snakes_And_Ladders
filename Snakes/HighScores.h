#pragma once
class HighScores
{
private:
	char Name[20];
	int Score;

public:
	void SetName(char* name)
	{
		strcpy_s(Name,name);
	}
	void SetScore(int score)
	{
		Score = score;
	}
	char* GetName()
	{
		return Name;
	}
	int GetScore()
	{
		return Score;
	}
	HighScores(void)
	{
	}

	virtual ~HighScores(void)
	{
	}
};

