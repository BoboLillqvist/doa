#pragma once
#include <forward_list>

class InterestTable
{
private:
    std::forward_list<std::string> list;

public:
    InterestTable()
    {

    }

    std::forward_list<std::string>& getList()
    {
        return list;
    }

    int numberOfCommonInterests(InterestTable& other)
    {
        return -1;
    }
};
