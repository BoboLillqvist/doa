#pragma once
#include <forward_list>

class InterestTable
{
private:
    std::forward_list<std::string> list;

public:
    InterestTable() {}

    void add(std::string interest)
    {
        // TODO: Kolla om intresset redan finns i listan
        // TODO: Kör en toLower() innan, och ev. skala whitespace
        list.push_front(interest);
    }

    std::forward_list<std::string>& getList()
    {
        return list;
    }

    int numberOfCommonInterests(InterestTable& other)
    {
        int commonCounter = 0;

        // Loop this persons interests
        for (auto thisInterest : list)
        {
            // Check if current interest is in the other persons interest table 
            for (auto otherInterest : other.getList())
            {
                if (thisInterest.compare(otherInterest) == 0)
                    commonCounter++;
            }
        }

        return commonCounter;
    }
};
