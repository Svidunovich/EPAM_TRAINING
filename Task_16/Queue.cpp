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

/*
template <typename T>
Queue<T>::Queue(const Queue &copy)
{
	this->head->data = copy->head->data;
	Node *current1 = this->head;
	Node *current2 = copy->head;
	for(size_t i = 0; i < copy->_size; i++)
	{
		current1->next = new Node;
		current1 = current1->next;
		current2 = current2->next;
		current1->data = current2->data;
	}
	this->_size = copy->_size;
}
*/

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

/*
template <typename T>
auto Queue<T>::find(const T& val)
{
	auto it = std::find(this->c.begin(), this->c.end(), val);
	return it;
}
*/

template <typename T>
T Queue<T>::find(const T& val)
{
	Node *current = this->head;
	for(size_t i = 0; i < this->_size; i++)
	{
		if(current->data == val) { return current->data; };
		current = current->next;
	}
	return 0;
}

template <typename T>
void Queue<T>::sort()
{
	std::multiset<T> ms;
	size_t size = this->size();
	for(size_t i = 0; i < size; i++)
	{
		ms.emplace(this->front());
		this->pop();
	}	
	auto it = ms.begin();	
	for(size_t i = 0; i < size; i++)
	{
		this->push(*it);
		it++;
	}
}
