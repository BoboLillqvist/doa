#pragma once
#include <forward_list>
#include <algorithm>    // transform()
#include <string>       // tolower

class InterestTable
{
private:
    std::forward_list<std::string> list;

public:
    InterestTable() {}

	void add(std::string interest)
	{
        // Flag
		bool inList = false;

        // Transform interest to lowercase
		std::transform(interest.begin(), interest.end(), interest.begin(), tolower);

        // Check if interest already in list
		for (auto thisInterest : list)
			if (thisInterest == interest)
				inList = true;

		if (!inList && interest != "")
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
            // Check if current interest is in the other persons interest table 
            for (auto otherInterest : other.getList())
                if (thisInterest == otherInterest)
                    commonCounter++;

        return commonCounter;
    }
};
