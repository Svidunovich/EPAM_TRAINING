#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <random>
#include <functional>
#include <chrono>

template <typename T>
class Queue // : std::queue<T>
{
	public:
		Queue();
		// Queue(const Queue &copy);
		~Queue();
		void push(T data);
		size_t size();
		void pop();
		T front();
		T back();
		bool empty();
		T find(const T& val);
		void sort();
		//auto find(const T& val);
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

