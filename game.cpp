#include "game.h"
using namespace std;
const int INF = 1e9;
vector<pair<int, int>> coordStart;
vector<pair<int, int>> coordFinish;
void setupMAP()
{
	MAP.resize(height);
	mapPositionX = (80 - width) / 2 + 2;
	mapPositionY = (30 - height) / 2;
	for (int i = 0; i < height; i++)MAP[i].resize(width, ' ');
	for (int i = 0; i < height; i++)
	{
		MAP[i][0] = char(219);
		MAP[i][width - 1] = char(219);
	}
	for (int i = 0; i < width; i++)
	{
		MAP[0][i] = char(220);
		MAP[height - 1][i] = char(223);
	}
	setColorForeground(wallColor);
	for (int i = 0; i < height; i++)
	{
		setcur(0 + mapPositionX, i + mapPositionY);
		cout<<MAP[i][0];
		setcur(width - 1 + mapPositionX, i + mapPositionY);
		cout<<MAP[i][width - 1];
	}
	for (int i = 0; i < width; i++)
	{
		setcur(i + mapPositionX, 0 + mapPositionY);
		cout<<MAP[0][i];
		setcur(i + mapPositionX, height - 1 + mapPositionY);
		cout<<MAP[height - 1][i];
	}
	setColorForeground(White);
	setColorBackground(backgroundColor);
	for (int i = 1; i < height-1; i++)
	{
		for (int j = 1; j < width-1; j++)
		{
			setcur(j + mapPositionX, i + mapPositionY);
			cout << MAP[i][j];
		}
	}
	setColorBackground(Black);
}

void deleteMAP()
{
	for (int i = 0; i < height; i++)
	{
		setcur(0 + mapPositionX, i + mapPositionY); cout << ' ';
		setcur(width - 1 + mapPositionX, i + mapPositionY); cout << ' ';
	}
	for (int i = 0; i < width; i++)
	{
		setcur(i + mapPositionX, mapPositionY); cout << ' ';
		setcur(i + mapPositionX, mapPositionY + height); cout << ' ';
	}
}

void clearWithoutColor()
{
	for (int i = 1; i < height - 1; i++)
	{
		for (int j = 1; j < width - 1; j++)
		{
			MAP[i][j] = ' ';
			setcur(j + mapPositionX, i + mapPositionY);
			cout << ' ';
		}
	}
	while (!coordStart.empty())coordStart.pop_back();
	while (!coordFinish.empty())coordFinish.pop_back();
}
void clear()
{
	setColorForeground(wallColor);
	setColorBackground(backgroundColor);
	for (int i = 1; i < height - 1; i++)
	{
		for (int j = 1; j < width - 1; j++)
		{
			MAP[i][j] = ' ';
			setcur(j + mapPositionX, i + mapPositionY);
			cout << ' ';
		}
	}
	while (!coordStart.empty())coordStart.pop_back();
	while (!coordFinish.empty())coordFinish.pop_back();
	setColorForeground(White);
	setColorBackground(Black);
}

//bool isInside(int x, int y, int rows, int cols) {
//	return x >= 0 && x < rows && y >= 0 && y < cols;
//}
//
//vector<pair<int, int>> findPath(vector<vector<char>>& maze, pair<int, int> start, pair<int, int> finish) {
//	int rows = maze.size();
//	int cols = maze[0].size();
//
//	// Массивы для хранения посещенных ячеек и пути
//	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
//	vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, { -1, -1 }));
//
//	// Стек для хранения координат пути
//	stack<pair<int, int>> pathStack;
//
//	// Очередь для BFS
//	queue<pair<int, int>> q;
//
//	/*for (int i = 0; i < start.size(); ++i)
//	{
//		q.push(start[i]);
//		visited[start[i].first][start[i].second] = true;
//	}*/
//	// Начальная точка
//	q.push(start);
//	visited[start.first][start.second] = true;
//
//	// Возможные смещения для перемещения в соседние ячейки (вверх, вниз, влево, вправо)
//	int dx[] = { -1, 1, 0, 0 };
//	int dy[] = { 0, 0, -1, 1 };
//
//	while (!q.empty()) {
//		pair<int, int> current = q.front();
//		q.pop();
//
//		if (current == finish) {
//			// Найден путь до финиша, восстановим путь
//			vector<pair<int, int>> path;
//			pair<int, int> p = finish;
//			while (p != make_pair(-1, -1)) {
//				pathStack.push(p);
//				p = parent[p.first][p.second];
//			}
//
//			// Переносим координаты пути из стека в вектор в правильном порядке
//			while (!pathStack.empty()) {
//				path.push_back(pathStack.top());
//				pathStack.pop();
//			}
//
//			return path;
//		}
//
//		// Перебираем соседние ячейки
//		for (int i = 0; i < 4; ++i) {
//			int nx = current.first + dx[i];
//			int ny = current.second + dy[i];
//
//			if (isInside(nx, ny, rows, cols) && maze[nx][ny] != (char)219 && maze[nx][ny] != (char)176 && maze[nx][ny] != (char)177
//				&& maze[nx][ny] != (char)178 && maze[nx][ny] != (char)220 && maze[nx][ny] != (char)223 && !visited[nx][ny]) {
//				q.push(make_pair(nx, ny));
//				visited[nx][ny] = true;
//				parent[nx][ny] = current;
//			}
//		}
//	}
//
//	// Если путь до финиша не найден, вернем пустой путь
//	return vector<pair<int, int>>();
//}

vector<pair<int,int>> bfs(vector<vector<char>>& a, vector<pair<int, int>>& start, vector< pair<int, int>>& finish)
{
	int h = a.size(), w = a[0].size();
	vector<vector<int>> dist(h, vector<int>(w, INF));
	vector<vector<pair<int, int>>> from(h, vector<pair<int, int>>(w, { -1,-1 }));
	vector<pair<int, int>> path;
	queue<pair<int, int>> q;

	for (auto [x, y] : start)
	{
		dist[y][x] = 0;
		q.push({ y, x });
	}

	vector<int> dy = { -1, 0, 1, 0 };
	vector<int> dx = { 0, 1, 0, -1 };
	while (!q.empty())
	{
		pair<int, int> v = q.front();
		q.pop();
		for (int d = 0; d < dy.size(); d++)
		{
			int ty = v.first + dy[d];
			int tx = v.second + dx[d];
			if (ty >= 0 && h > ty && tx >= 0 && w > tx &&
				a[ty][tx] != char(219) && a[ty][tx] != char(220) && a[ty][tx] != char(223) && a[ty][tx] != char(176) && a[ty][tx] != char(177) && a[ty][tx] != char(178) && dist[ty][tx] > dist[v.first][v.second] + 1)
			{
				dist[ty][tx] = dist[v.first][v.second] + 1;
				from[ty][tx] = v;
				q.push({ ty, tx });
			}
		}
	}
	auto [finishX, finishY] = finish[0];
	for (auto [x, y] : finish)
	{
		if (dist[finishY][finishX] > dist[y][x])
		{
			finishY = y;
			finishX = x;
		}
	}

	if (dist[finishY][finishX] != INF)
	{
		int y = finishY;
		int x = finishX;
		path.push_back({ y,x });
		while (x != -1 && y != -1)
		{
			pair<int, int> v = from[y][x];
			y = v.first;
			x = v.second;
			path.push_back(v);
		}
	}
	return path;
}


void walkingThePath()
{
	setColorForeground(White);
	setColorBackground(backgroundColor);
	pair<int, int> prev;
	if(!path.empty()) prev = path[path.size() - 1];
	if (LeaveMark)
	{
		for (int i = path.size() - 2; i >= 0; i--)
		{
			setcur(path[i].second + mapPositionX, path[i].first + mapPositionY);
			cout << char(2);
			setcur(prev.second + mapPositionX, prev.first + mapPositionY);
			cout << ' ';
			if (abs(path[i].first - prev.first) == 1)
			{
				Sleep(100 - speed);
				setcur(prev.second + mapPositionX, prev.first + mapPositionY);
				cout << char(250);
				MAP[prev.first][prev.second] = char(250);
			}
			else
			{
				Sleep((100 - speed)/2);
				if ((prev.second - mapPositionX) % 2 == 0)
				{
					setcur(prev.second + mapPositionX, prev.first + mapPositionY);
					cout << char(250);
					MAP[prev.first][prev.second] = char(250);
				}
			}
			prev = path[i];
		}
	}
	else
	{
		for (int i = path.size() - 2; i >= 0; i--)
		{
			setcur(path[i].second + mapPositionX, path[i].first + mapPositionY);
			cout << char(2);
			setcur(prev.second + mapPositionX, prev.first + mapPositionY);
			cout << ' ';
			if (abs(path[i].first - prev.first) == 1)
			{
				Sleep(100 - speed);
			}
			else
			{
				Sleep((100 - speed)/2);
			}
			prev = path[i];
		}
	}
	setColorForeground(White);
	setColorBackground(Black);
}

void game()
{
	system("cls");
	bool stopGame = false;
	Window menu(31, 26, 85, 2), menuWalls(31, 8, 85, 15);
	menu.show();
	menuWalls.show();
	setcur(85, 15); cout << char(219);
	setcur(85, 22); cout << char(219);
	setcur(115, 15); cout << char(219);
	setcur(115, 22); cout << char(219);
	setcur(89, 17); cout << "start - ";
	setcur(101, 17); cout << "finish - ";
	pair<int, int> lastStart = { INF,INF };
	SwitchButton switchButtonLeaveMark(10, 3, false, 96, 10);
	switchButtonLeaveMark.addName("leave a mark", 93, 13);
	StandartButton sbClear(13, 3, "clear", 87, 23), sbStart(13, 3, "start", 101, 23);
	vector<pair<int, int>> tempCoordStart;
	sbClear.connect(clear);
	sbStart.connect([&]()
	{
			setColorForeground(White);
			setColorBackground(backgroundColor);
			coordStart = {};
			coordFinish = {};
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (MAP[i][j] == char(250))
					{
						MAP[i][j] = ' ';
						setcur(j + mapPositionX, i + mapPositionY);
						cout << ' ';
					}
					if (MAP[i][j] == char(3))coordFinish.push_back({ j,i });
					if (MAP[i][j] == char(2))coordStart.push_back({ j,i });
				}
			}
			for (int i = 0; i < coordFinish.size(); i++)
			{
				setcur(coordFinish[i].first + mapPositionX, coordFinish[i].second + mapPositionY);
				cout << finishSymbol;
			}
			if (!coordStart.empty() && !coordFinish.empty())
			{
				path = bfs(MAP, coordStart, coordFinish);
				walkingThePath();
			}
			for (int i = 0; i < coordStart.size(); i++)MAP[coordStart[i].second][coordStart[i].first] = startSymbol;
			for (int i = 0; i < coordFinish.size(); i++)MAP[coordFinish[i].second][coordFinish[i].first] = finishSymbol;
			setColorForeground(White);
			setColorBackground(Black);
	});
	SliderButton slbSpeed(1, 20, "speed", speed/5, 90, 4, SliderButton::Orientation::HORIZONTAL);
	slbSpeed.connect([&]() {speed -= 5; }, [&]() {speed += 5; });
	switchButtonLeaveMark.connect([&]() { LeaveMark = false; }, [&]() { LeaveMark = true; });
	vector<vector<char>> arrX = { {'X'} };
	CustomButton back(arrX, arrX, 116, 1);
	back.setButtonForegroundColor(BrightRed);
	back.connect([&]() {stopGame = true; });
	char tempWall = ' ';

	vector<vector<char>> arr176 = { {char(176),char(176)},{char(176),char(176)} }, arr177 = { {char(177),char(177)},{char(177),char(177)} }, arr178 = { {char(178),char(178)},{char(178),char(178)} }, arr219 = { {char(219),char(219)},{char(219),char(219)} };
	CustomButton wall176(arr176, arr176, 89, 19), wall177(arr177, arr177, 94, 19), wall178(arr178, arr178, 99, 19), wall219(arr219, arr219, 104, 19);
	vector<vector<char>> arr2 = { {char(2)} };
	vector<vector<char>> arr3 = { {3} };
	CustomButton wall2(arr2, arr2, 97, 17), wall3(arr3, arr3, 110, 17);
	wall2.connect([&]() { tempWall = char(2); });
	wall3.connect([&]() { tempWall = char(3); });
	wall176.connect([&]() { tempWall = char(176); });
	wall177.connect([&]() { tempWall = char(177); });
	wall178.connect([&]() { tempWall = char(178); });
	wall219.connect([&]() { tempWall = char(219); });
	vector<vector<char>> squar = { {char(220), char(220)}, {char(223), char(223)} };
	CustomButton eraser(squar, squar, 108, 19);
	eraser.connect([&]() {tempWall = ' '; });
	invisibleCursor();
	setupInputHandling();
	setupMAP();
	while (!stopGame)
	{
		mouseButtonInteraction(&switchButtonLeaveMark, &sbClear, &sbStart,
			&wall176, &wall177, &wall178, &wall219, &eraser, &wall2, &wall3, &back, &slbSpeed);
		if (COORD mousePos = GetCursorPosition(); GetAsyncKeyState(VK_LBUTTON) & 0x8000
			&& mousePos.X >= mapPositionX + 1 && mousePos.X < mapPositionX + width - 1
			&& mousePos.Y >= mapPositionY + 1 && mousePos.Y < mapPositionY + height - 1)
		{
			setColorForeground(wallColor);
			setColorBackground(backgroundColor);
			if (tempWall != char(2) && tempWall != char(3))
			{
				if ((mousePos.X - mapPositionX) % 2 == 0)
				{
					setcur(mousePos.X, mousePos.Y); std::cout << tempWall;
					setcur(mousePos.X - 1, mousePos.Y); std::cout << tempWall;
					
					MAP[mousePos.Y - mapPositionY][mousePos.X - mapPositionX] = tempWall;
					MAP[mousePos.Y - mapPositionY][mousePos.X - mapPositionX - 1] = tempWall;
				}
				else
				{
					setcur(mousePos.X, mousePos.Y); std::cout << tempWall;
					setcur(mousePos.X + 1, mousePos.Y); std::cout << tempWall;
					MAP[mousePos.Y - mapPositionY][mousePos.X - mapPositionX] = tempWall;
					MAP[mousePos.Y - mapPositionY][mousePos.X - mapPositionX + 1] = tempWall;
				}
			}
			else
			{
				setColorForeground(White);
				if ((mousePos.X - mapPositionX) % 2 == 0)
				{
					setcur(mousePos.X, mousePos.Y); std::cout << ' ';
					setcur(mousePos.X - 1, mousePos.Y); std::cout << ' ';
					MAP[mousePos.Y - mapPositionY][mousePos.X - mapPositionX] = ' ';
					MAP[mousePos.Y - mapPositionY][mousePos.X - mapPositionX - 1] = ' ';
				}
				else
				{
					setcur(mousePos.X, mousePos.Y); std::cout << ' ';
					setcur(mousePos.X + 1, mousePos.Y); std::cout << ' ';
					MAP[mousePos.Y - mapPositionY][mousePos.X - mapPositionX] = ' ';
					MAP[mousePos.Y - mapPositionY][mousePos.X - mapPositionX + 1] = ' ';
				}
				if ((mousePos.X - mapPositionX) % 2 != 0)mousePos.X += 1;
				setcur(mousePos.X, mousePos.Y); std::cout << tempWall;
				MAP[mousePos.Y - mapPositionY][mousePos.X - mapPositionX] = tempWall;
			}
		}
		setColorForeground(White);
		setColorBackground(Black);
	}
}