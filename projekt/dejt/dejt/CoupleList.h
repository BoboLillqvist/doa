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
	void add(Couple& couple)
	{
		list.push_front(couple);
	}

	std::forward_list<Couple>& getList()
	{
		return list;
	}
	//TODO: Filspararfunktion för couplelist
};