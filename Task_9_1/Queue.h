#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
class Queue
{
	public:
		Queue();
		~Queue();
		void push(T data);
		size_t size();
		void pop();
		T front();
		T back();
		bool empty();
	private:
		struct Node{
			T data;
			Node *next;
			Node(T data = T(), Node *next = nullptr)
			{
				this->data = data;
				this->next = next;
			}
		};
		Node *head;
		size_t _size;	
};

