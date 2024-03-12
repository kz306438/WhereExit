#pragma once
#include <vector>
#include "consoleGUI/GUI.h"
std::vector<std::vector<std::vector<char>>> content =
{
	{
		{' ','W','H','I','T','E',' '}
	},
	{
		{' ','B','L','U','E',' ',' '}
	},
	{
		{' ','G','R','E','E','N',' '}
	},
	{
		{' ','C','Y','A','N',' ',' '}
	},
	{
		{' ',' ','R','E','D',' ',' '}
	},
	{
		{'M','A','G','E','N','T','A'}
	},
	{
		{'Y','E','L','L','O','W',' '}
	}
};
extern ScrollButton wallsColor(content, 56, 18, ScrollButton::Orientation::HORIZONTAL);
extern ScrollButton mapColor(content, 56, 23, ScrollButton::Orientation::HORIZONTAL);