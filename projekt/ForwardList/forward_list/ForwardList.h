#pragma once
template <class T>
class ForwardList
{
public:
	//Constructors
    ForwardList()
    {

    }
	//Destructor
	~ForwardList()
	{

	}

	//Capacity
	bool empty() 
	{ 
		return true; 
	}

	//Elementaccess
	T& front()
	{

	}

	//Modifiers
	void pushFront(const T& value)
	{

	}

	void popFront()
	{

	}
 
	void clear()
	{

	}

	void insertAfter(T& node, T& newNode)
	{

	}

	void eraseAfter(T& node)
	{
		//Ta bort nodens next
		//Kalla på next nodes destruktor?
	}

	void swap(ForwardList<T> listToSwap)
	{
		//Ändra den listan som kallar på funktionen med den listan som skickas in
		//Kolla så att båda har samma <T>
	}
	//Iterator
	class Iterator
	{
	public:
		//Constructor
		Iterator()
		{

		}
		//Destructor
		~Iterator()
		{

		}
	private:
		
	};
	Iterator begin()
	{

	}
	Iterator end()
	{

	}
};

