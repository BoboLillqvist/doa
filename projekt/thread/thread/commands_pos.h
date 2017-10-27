#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <random>
#include <deque>;
#include <conio.h>

using namespace std;
#include <iso646.h>

#include "Console.h"
const int Rows = 10;
const int Columns = 10;
enum class commands
{
	Left = 0,
	Right,
	Up,
	Down
};

struct pos
{
	int id = -1;
	int y = 0;
	int x = 0;
	int yOld = 0;
	int xOld = 0;
	pos() {}
	pos(int id, int x, int y, int xOld, int yOld)
	{
		this->id = id;
		this->x = x; this->y = y;
		this->xOld = xOld; this->yOld = yOld;
	}
};

atomic<bool> atomicFlagQuit = false;

mutex mutex_keys[2]; //Två spelare
deque<commands>  keys[2];

mutex mutex_qpos;
deque<pos> queue_position;