#pragma once
#include <exception>
template <class T>
struct Node
{
    T value;
    Node<T>* next;

    Node()
    {
        next = nullptr;
    }

    Node(const T& tValue)
    {
        next = nullptr;
        value = tValue;
    }
};

template <class T>
class ForwardList
{
private:
    Node<T>* head;

public:

	// Iterator
	class Iterator
	{
	public:
		typedef Iterator selfType;
		typedef Node<T> valueType;
		typedef Node<T>& reference;
		typedef Node<T>* pointer;

		// Constructor
		Iterator(pointer ptr) : ptr_(ptr)
		{

		}

		// Destructor
		~Iterator()
		{

		}
		reference operator*()
		{
			return *ptr_;
		}

		pointer operator->()
		{
			return ptr_;
		}
		bool operator!=(const selfType& rhs)
		{
			return ptr_ != rhs.ptr_;
		}
		bool operator==(const selfType& rhs)
		{
			return ptr_ == rhs.ptr_;
		}
	private:
		pointer ptr_;
	};


	Iterator begin() const
	{
		return Iterator(head);
	}

	Iterator end() const
	{
		return Iterator(nullptr);
	}

	// Constructors
    ForwardList()
    {
		head = nullptr;
    }

	ForwardList(const ForwardList& listToCopy)
	{
		if (listToCopy.head != nullptr)
		{
			ForwardList<T>::Iterator copyListIt=listToCopy.begin();
			Node<T>* node = new Node<T>(copyListIt->value);
			head = node;
			ForwardList<T>::Iterator thisListIt=this->begin();
			copyListIt = copyListIt->next;
			while (copyListIt != listToCopy.end())
			{
				//1. Skapa en ny nod.
				Node<T>* node = new Node<T>(copyListIt->value);

				//2. Ändra det iteratorn pekar pås next till den nya noden 
				thisListIt->next = node;

				//3. Flytta fram iteratorn till denna nya nod
				copyListIt = copyListIt->next;
				thisListIt = node;
			}
		}
		else
		{
			head = nullptr;
		}
	}

	// Destructor
	~ForwardList()
	{

	}

	// Capacity
	bool empty() 
	{ 
		return (head == nullptr);
	}

	// Elementaccess
	T& front()
	{
		if (empty())
			throw std::exception("Trying to check front of empty list");
        else
			return head->value;
	}

	// Modifiers
	void pushFront(const T& value)
	{
		// Create new node
		Node<T>* node = new Node<T>(value);

		// Set new nodes next to the current head
		node->next = head;

		// Point head to the new node
		head = node;
	}

	void popFront()
	{
        // If trying to pop empty list, throw an exception
		if (empty())
			throw std::exception("Trying to pop empty list");

        // Temporary node pointer
		Node<T>* temp = head->next;

        // Delete pop:ed node from memory
		delete head;

        // Point to next node
		head = temp;
	}
 
	void clear()
	{

	}

	void insertAfter(T& node, T& newNode)
	{

	}

	void eraseAfter(T& node)
	{
		// Ta bort nodens next
		// Kalla på next nodes destruktor?
	}

	void swap(ForwardList<T> listToSwap)
	{
		// Ändra den listan som kallar på funktionen med den listan som skickas in
		// Kolla så att båda har samma <T>
	}

};

