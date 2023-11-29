#pragma once
#include <vector>
#include "consoleGUI/colors.h"
extern int width;
extern int height;
extern int speed;
extern int mapPositionX;
extern int mapPositionY;
extern char startSymbol;
extern char finishSymbol;
extern bool LeaveMark;
extern std::vector<std::vector<char>> MAP;
extern std::vector<std::pair<int, int>> path;
extern ConsoleColor backgroundColor;
extern ConsoleColor wallColor;