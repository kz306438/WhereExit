#include "settings.h"
#include "setupButtons.h"
#include <iostream>
void settings()
{
	system("cls");
	bool stopSettings = false;
	bool isChange = false;
	Window custom(41, 24, 41, 3);
	custom.addWindowName("custom", 5, 0);
	custom.show();
	SliderButton sliderButtonWidth(10, 40, "WIDTH", width/2, 45, 6, SliderButton::Orientation::HORIZONTAL);
	SliderButton sliderButtonHeight(10, 30, "HEIGHT", height, 50, 10, SliderButton::Orientation::HORIZONTAL);
	StandartButton sbBack(20, 5, "BACK", 8, 3);
	sliderButtonWidth.connect([&]() {width -= 2; isChange = true; }, [&]() {width += 2; isChange = true; });
	sliderButtonHeight.connect([&]() {height -= 1; isChange = true; }, [&]() {height += 1; isChange = true; });
	sbBack.connect([&]() {stopSettings = true; });
	wallsColor.addName("WALL COLOR:", 56, 16);
	wallsColor.connect([&]()
		{
			if (wallsColor.getSlideNumber() == 0)wallColor = White;
			if (wallsColor.getSlideNumber() == 1)wallColor = Blue;
			if (wallsColor.getSlideNumber() == 2)wallColor = Green;
			if (wallsColor.getSlideNumber() == 3)wallColor = Cyan;
			if (wallsColor.getSlideNumber() == 4)wallColor = Red;
			if (wallsColor.getSlideNumber() == 5)wallColor = Magenta;
			if (wallsColor.getSlideNumber() == 6)wallColor = Yellow;
		},
		[&]()
		{
			if (wallsColor.getSlideNumber() == 0)wallColor = White;
			if (wallsColor.getSlideNumber() == 1)wallColor = Blue;
			if (wallsColor.getSlideNumber() == 2)wallColor = Green;
			if (wallsColor.getSlideNumber() == 3)wallColor = Cyan;
			if (wallsColor.getSlideNumber() == 4)wallColor = Red;
			if (wallsColor.getSlideNumber() == 5)wallColor = Magenta;
			if (wallsColor.getSlideNumber() == 6)wallColor = Yellow;
		});
	mapColor.addName("BACKGROUND COLOR:", 53, 21);
	mapColor.connect([&]()
		{
			if (mapColor.getSlideNumber() == 0)backgroundColor = White;
			if (mapColor.getSlideNumber() == 1)backgroundColor = Blue;
			if (mapColor.getSlideNumber() == 2)backgroundColor = Green;
			if (mapColor.getSlideNumber() == 3)backgroundColor = Cyan;
			if (mapColor.getSlideNumber() == 4)backgroundColor = Red;
			if (mapColor.getSlideNumber() == 5)backgroundColor = Magenta;
			if (mapColor.getSlideNumber() == 6)backgroundColor = Yellow;
		},
		[&]()
		{
			if (mapColor.getSlideNumber() == 0)backgroundColor = White;
			if (mapColor.getSlideNumber() == 1)backgroundColor = Blue;
			if (mapColor.getSlideNumber() == 2)backgroundColor = Green;
			if (mapColor.getSlideNumber() == 3)backgroundColor = Cyan;
			if (mapColor.getSlideNumber() == 4)backgroundColor = Red;
			if (mapColor.getSlideNumber() == 5)backgroundColor = Magenta;
			if (mapColor.getSlideNumber() == 6)backgroundColor = Yellow;
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