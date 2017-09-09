#pragma once

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
		// Ta bort f�rsta noden
		// �ndra headern till den f�rsta nodens next.
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
		// Kalla p� next nodes destruktor?
	}

	void swap(ForwardList<T> listToSwap)
	{
		// �ndra den listan som kallar p� funktionen med den listan som skickas in
		// Kolla s� att b�da har samma <T>
	}

	// Iterator
	class Iterator
	{
	public:
		// Constructor
		Iterator()
		{

		}

		// Destructor
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

