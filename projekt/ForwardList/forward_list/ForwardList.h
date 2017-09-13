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
	// Constructors
    ForwardList()
    {
		head = nullptr;
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
		if (head == nullptr)
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
	private:
		pointer ptr_;
	};

	Iterator begin()
	{
		return Iterator(head);
	}

	Iterator end()
	{
		return Iterator(nullptr);
	}
};

