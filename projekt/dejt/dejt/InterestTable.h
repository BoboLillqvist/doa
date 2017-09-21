#pragma once
#include <forward_list>

class InterestTalbe
{
private:
    std::forward_list<std::string> list;

public:
    InterestTalbe()
    {

    }

    std::forward_list<std::string>& getList()
    {
        return list;
    }

    int numberOfCommonInterests()
    {
        return -1;
    }
};
