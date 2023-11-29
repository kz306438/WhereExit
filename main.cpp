#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "consoleGUI/buttons.h"
#include "consoleGUI/cursor.h"
#include "consoleGUI/window.h"
#include "consoleGUI/colors.h"
#include "image.h"
#include "game.h"
#include "menu.h"
using namespace std;

int width = 80;
int height = 30;
int mapPositionX = 2;
int mapPositionY = 0;
int speed = 50;
char startSymbol = char(2);
char finishSymbol = char(3);
bool LeaveMark = false;
vector<vector<char>> MAP;
vector<pair<int, int>> path;
ConsoleColor backgroundColor = Black;
ConsoleColor wallColor = White;


int main()
{
	HWND console = GetConsoleWindow();
	SetConsoleTitleA("    Where Exit!?   ");
	menu();
	return 0;
}