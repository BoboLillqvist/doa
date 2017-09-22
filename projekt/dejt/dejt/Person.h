#pragma once
#include "InterestTable.h"
class Person
{
private:
    size_t id_;
    std::string name_;
    char gender_;
    std::vector<char> preference_;
	InterestTable it_;

public:
	Person()
	{

	}
};