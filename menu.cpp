#include "menu.h"

void menu()
{
	StandartButton sbPLAY(25, 5, "PLAY", 8, 5), sbSettings(25, 5, "SETTINGS", 8, 12), sbExite(25, 5, "EXIT", 8, 19);
	bool stopMenu = false;
	int activeButton = 0;
	sbPLAY.connect([&]() { activeButton = 1; });
	sbSettings.connect([&]() {activeButton = 2; });
	sbExite.connect([&]() { activeButton = 3; stopMenu = true; });
	setupInputHandling();
	while (!stopMenu)
	{
		textBuild(60, 6);
		textYour(61, 12);
		textMaze(62, 18);
		invisibleCursor();
		mouseButtonInteraction(&sbPLAY, &sbSettings, &sbExite);
		if (activeButton == 1)
		{
			game();
			activeButton = 0;
			system("cls");
			setupInputHandling();
		}
		else if (activeButton == 2)
		{
			settings();
			activeButton = 0;
			system("cls");
			setupInputHandling();
		}
		else if (activeButton == 3)
		{
			exit(0);
		}
		Sleep(10);
	}
}