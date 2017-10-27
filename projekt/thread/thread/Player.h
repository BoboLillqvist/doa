#pragma once
#include "commands_pos.h"
class Player
{
private:
	int id;
	int x, y;
public:
	Player(int id, int x, int y) { this->id = id; this->x = x; this->y = y; }

	void operator()() //TRÅDFUNKTIONEN Player pl1; pl1();
	{
		while (!atomicFlagQuit)
		{
			mutex_keys[id].lock();
			if (!keys[id].empty())
				switch (keys[id].front())
				{
				case commands::Left:
					if (x > 0)
					{
						x--;
						queue_position.push_back(pos(id, x, y, x + 1, y));
					}
					keys[id].pop_front();
					
					break;
				case commands::Right:
					if (x < Rows)
					{
						x++;
						queue_position.push_back(pos(id, x, y, x - 1, y));
					}
						keys[id].pop_front();
					
					break;
				case commands::Up:
					if (y > 0)
					{
						y--;
						queue_position.push_back(pos(id, x, y, x, y + 1));
					}
						keys[id].pop_front();
					
					break;
				case commands::Down:
					if (y < Columns)
					{
						y++;
						queue_position.push_back(pos(id, x, y, x, y - 1));
					}
						keys[id].pop_front();
					
					break;
				}

			mutex_keys[id].unlock();

			this_thread::sleep_for(chrono::milliseconds(300));
		}
	}
};