#pragma once
#include <forward_list>
#include "Couple.h"

class CoupleList
{
private:
	std::forward_list<Couple> list;
public:
	CoupleList()
	{

	}

	std::forward_list<Couple>& getList()
	{
		return list;
	}
};