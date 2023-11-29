#include "image.h"
using namespace std;
void textBuild(int x, int y)
{
	vector<vector<char>> arr =
	{
		{char(219),char(219),char(219),char(219),char(32),char(32),char(219),char(32),char(219),char(32),char(219),char(219),char(219),char(32),char(219),char(32),char(32),char(32),char(219),char(219),char(219),char(219),char(32)},
		{char(219),char(32),char(32),char(219),char(219),char(32),char(219),char(32),char(219),char(32),char(32),char(219),char(32),char(32),char(219),char(32),char(32),char(32),char(219),char(32),char(32),char(219),char(219)},
	    {char(219),char(219),char(219),char(219),char(32),char(32),char(219),char(32),char(219),char(32),char(32),char(219),char(32),char(32),char(219),char(32),char(32),char(32),char(219),char(32),char(32),char(219),char(219)},
		{char(219),char(32),char(32),char(219),char(219),char(32),char(219),char(32),char(219),char(32),char(32),char(219),char(32),char(32),char(219),char(32),char(32),char(32),char(219),char(32),char(32),char(219),char(219)},
		{char(219),char(219),char(219),char(219),char(32),char(32),char(219),char(219),char(219),char(32),char(219),char(219),char(219),char(32),char(219),char(219),char(219),char(32),char(219),char(219),char(219),char(219),char(32)}
	};
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			setcur(x + j, y + i);
			cout << arr[i][j];
		}
	}
}
void textYour(int x, int y)
{
	vector<vector<char>> arr =
	{
		{char(219),char(219),char(32),char(219),char(219),char(32),char(219),char(219),char(219),char(219),char(32),char(219),char(32),char(219),char(32),char(219),char(219),char(219),char(219)},
        {char(32),char(219),char(219),char(219),char(32),char(32),char(219),char(32),char(32),char(219),char(32),char(219),char(32),char(219),char(32),char(219),char(32),char(32),char(219)},
        {char(32),char(32),char(219),char(32),char(32),char(32),char(219),char(32),char(32),char(219),char(32),char(219),char(32),char(219),char(32),char(219),char(219),char(219),char(219)},
        {char(32),char(32),char(219),char(32),char(32),char(32),char(219),char(32),char(32),char(219),char(32),char(219),char(32),char(219),char(32),char(219),char(32),char(219),char(32)},
        {char(32),char(32),char(219),char(32),char(32),char(32),char(219),char(219),char(219),char(219),char(32),char(219),char(219),char(219),char(32),char(219),char(32),char(219),char(32)}
	};
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			setcur(x + j, i + y);
			cout << arr[i][j];
		}
	}
}
void textMaze(int x, int y)
{
	vector<vector<char>> arr =
	{
		{char(219),char(32),char(32),char(32),char(219),char(32),char(219),char(219),char(219),char(219),char(32),char(219),char(219),char(219),char(219),char(32),char(219),char(219),char(219)},
        {char(219),char(219),char(32),char(219),char(219),char(32),char(219),char(32),char(32),char(219),char(32),char(32),char(32),char(219),char(219),char(32),char(219),char(32),char(32)},
        {char(219),char(32),char(219),char(32),char(219),char(32),char(219),char(219),char(219),char(219),char(32),char(32),char(219),char(219),char(32),char(32),char(219),char(219),char(219)},
        {char(219),char(32),char(32),char(32),char(219),char(32),char(219),char(32),char(32),char(219),char(32),char(219),char(219),char(32),char(32),char(32),char(219),char(32),char(32)},
        {char(219),char(32),char(32),char(32),char(219),char(32),char(219),char(32),char(32),char(219),char(32),char(219),char(219),char(219),char(219),char(32),char(219),char(219),char(219)}

	};
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			setcur(x + j, i + y);
			cout << arr[i][j];
		}
	}
}