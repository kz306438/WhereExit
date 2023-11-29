#include "settings.h"
#include <iostream>
void settings()
{
	system("cls");
	bool stopSettings = false;
	bool isChange = false;
	SliderButton sliderButtonWidth(10, 40, "width", width/2, 45, 3, SliderButton::Orientation::HORIZONTAL);
	SliderButton sliderButtonHeight(10, 30, "height", height, 50, 7, SliderButton::Orientation::HORIZONTAL);
	StandartButton sbBack(20, 5, "Back", 5, 3);
	sliderButtonWidth.connect([&]() {width -= 2; isChange = true; }, [&]() {width += 2; isChange = true; });
	sliderButtonHeight.connect([&]() {height -= 1; isChange = true; }, [&]() {height += 1; isChange = true; });
	sbBack.connect([&]() {stopSettings = true; });
	std::vector<std::vector<std::vector<char>>> content =
	{
		{
			{' ','w','h','i','t','e',' '}
		},
		{
			{' ','b','l','u','e',' ',' '}
		},
		{
			{' ','g','r','e','e','n',' '}
		},
		{
			{' ','c','y','a','n',' ',' '}
		},
		{
			{' ',' ','r','e','d',' ',' '}
		},
		{
			{'m','a','g','e','n','t','a'}
		},
		{
			{'y','e','l','l','o','w',' '}
		}
	};
	ScrollButton wallsColor(content, 56, 15, ScrollButton::Orientation::HORIZONTAL);
	wallsColor.addName("wall color:", 56, 13);
	wallsColor.connect([&]() 
		{
			switch (wallsColor.getSlideNumber())
			{
			case 0:
				wallColor = White;
				break;
			case 1:
				wallColor = BrightBlue;
				break;
			case 2:
				wallColor = Green;
				break;
			case 3:
				wallColor = Cyan;
				break;
			case 4:
				wallColor = BrightRed;
				break;
			case 5:
				wallColor = Magenta;
				break;
			case 6:
				wallColor = Yellow;
				break;

			}
		}, [&]() 
		{
			switch (wallsColor.getSlideNumber())
			{
			case 0:
				wallColor = White;
				break;
			case 1:
				wallColor = BrightBlue;
				break;
			case 2:
				wallColor = Green;
				break;
			case 3:
				wallColor = Cyan;
				break;
			case 4:
				wallColor = BrightRed;
				break;
			case 5:
				wallColor = Magenta;
				break;
			case 6:
				wallColor = Yellow;
				break;

			}
		});
	ScrollButton mapColor(content, 56, 20, ScrollButton::Orientation::HORIZONTAL);
	mapColor.addName("background color:", 53, 18);
	mapColor.connect([&]()
		{
			switch (mapColor.getSlideNumber())
			{
			case 0:
				backgroundColor = White;
				break;
			case 1:
				backgroundColor = BrightBlue;
				break;
			case 2:
				backgroundColor = Green;
				break;
			case 3:
				backgroundColor = Cyan;
				break;
			case 4:
				backgroundColor = BrightRed;
				break;
			case 5:
				backgroundColor = Magenta;
				break;
			case 6:
				backgroundColor = Yellow;
				break;
			}
		},
		[&]()
		{
			switch (mapColor.getSlideNumber())
			{
			case 0:
				backgroundColor = White;
				break;
			case 1:
				backgroundColor = BrightBlue;
				break;
			case 2:
				backgroundColor = Green;
				break;
			case 3:
				backgroundColor = Cyan;
				break;
			case 4:
				backgroundColor = BrightRed;
				break;
			case 5:
				backgroundColor = Magenta;
				break;
			case 6:
				backgroundColor = Yellow;
				break;
			}
		});
	setupInputHandling();
	while (!stopSettings)
	{
		mouseButtonInteraction(&sliderButtonWidth, &sliderButtonHeight, &sbBack, &wallsColor, &mapColor);
	}
	if (isChange)
	{
		if (MAP.size() != 0)
		{
			clearWithoutColor();
		}
	}
}