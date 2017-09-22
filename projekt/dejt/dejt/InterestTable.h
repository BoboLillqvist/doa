#pragma once
#include <forward_list>
#include <algorithm>
#include <string>
class InterestTable
{
private:
    std::forward_list<std::string> list;

public:
    InterestTable() {}

	void add(std::string interest)
	{
		bool isInList = false;
		// TODO: Kolla om intresset redan finns i listan
		// TODO: Kör en toLower() innan, och ev. skala whitespace
		std::transform(interest.begin(), interest.end(), interest.begin(), ::tolower);
		for (auto thisInterest : list)
		{
			if (thisInterest==interest)
				isInList = true;
		}
		if (!isInList && !(interest==""))
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
                if (thisInterest == otherInterest)
                    commonCounter++;
            }
        }
        return commonCounter;
    }
};
