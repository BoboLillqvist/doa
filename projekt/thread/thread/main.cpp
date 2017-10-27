//Trådar
#include "commands_pos.h"
#include "Game.h"
#include "Player.h"
int main()
{
	Game game;
	Player pl1(0, 0, 0), pl2(1, Rows - 1, Columns - 1);

	thread t1(game), t2(pl1), t3(pl2);

	t1.join();
	t2.join();
	t3.join();

	system("pause");
	return 0;
}