#include "Queue.h"

template <typename T>
Queue<T>::Queue()
{
	_size = 0;
	head = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{		
	while(_size != 0)
	{
		Node *temp = this->head;
		this->head = this->head->next;
		delete temp;
		_size--;
	}
	delete this->head;
}

template <typename T>
bool Queue<T>::empty()
{
	return this->head == nullptr;
}

template <typename T>
T Queue<T>::front()
{
	return this->head->data;
}

template <typename T>
T Queue<T>::back()
{
	Node *current = this->head;
	while(current->next != nullptr)
	{
		current = current->next;
	}
	return current->data;
}

template <typename T>
void Queue<T>::pop()
{
	Node *temp = this->head;	
	this->head = this->head->next;
	delete temp;
	_size--;
}

template <typename T>
void Queue<T>::push(T data)
{
	if(head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node *current = this->head;
		while(current->next != nullptr)
		{
			current = current->next; 
		}
		current->next = new Node(data);
	}
	_size++;
}

template <typename T>
size_t Queue<T>::size()
{
	return _size;
}

