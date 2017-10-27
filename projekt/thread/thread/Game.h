#pragma once
#include "commands_pos.h"
class Game
{

private:
	pos p1;
	pos p2;
public:
	Game() {}

	void operator()() //TRÅDFUNKTIONEN 
	{
		while (true)
		{
			if (_kbhit())
			{
				char c = -1;
				c = _getch();
				if (c == 'q' || c == 'Q')
				{
					atomicFlagQuit = true;
					break;
				}
				else
				{
					switch (c)
					{
					case 'A': keys[0].push_back(commands::Left); break;
					case 'D': keys[0].push_back(commands::Right); break;
					case 'W': keys[0].push_back(commands::Up); break;
					case 'S': keys[0].push_back(commands::Down); break;
					case 'J': keys[1].push_back(commands::Left); break;
					case 'L': keys[1].push_back(commands::Right); break;
					case 'I': keys[1].push_back(commands::Up); break;
					case 'K': keys[1].push_back(commands::Down); break;
					}
				}
			}

			while (!queue_position.empty())
			{
				pos p = queue_position.front();
				queue_position.pop_front();
				switch (p.id)
				{
				case 0:
					p1 = p;
					Console::gotoxy(p.xOld, p.yOld);
					cout << " ";
					Console::gotoxy(p.x, p.y);
					cout << "1";
					Console::gotoxy(p.x, p.y);
					if ((p.x == p2.x) && p.y == p2.y)
					{
						cout << "Game over! player 1 wins!";
					}
					break;
				case 1:
					p2 = p;
					Console::gotoxy(p.xOld, p.yOld);
					cout << " ";
					Console::gotoxy(p.x, p.y);
					cout << "2";
					Console::gotoxy(p.x, p.y);
					break;
				}
			}

			this_thread::sleep_for(chrono::milliseconds(300));
		}
	}
};

