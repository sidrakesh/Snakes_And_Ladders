#pragma once
class Details
{
private:
	int PlayersNumber;
	int BoardWidth;
	int BoardHeight;
public:
	void SetPlayersNumber(int num)
	{
		PlayersNumber = num;
	}
	void SetBoardWidth(int num)
	{
		BoardWidth = num;
	}
	void SetBoardHeight(int num)
	{
		BoardHeight = num;
	}
	int GetPlayersNumber()
	{
		return PlayersNumber;
	}
	int GetBoardWidth()
	{
		return BoardWidth;
	}
	int GetBoardHeight()
	{
		return BoardHeight;
	}
	Details(void)
	{
	}

	virtual ~Details(void)
	{
	}
};

