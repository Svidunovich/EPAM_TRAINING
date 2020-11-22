#pragma once
#include <iostream>

template <typename T>
class Queue
{
	public:
		Queue() : _size(0)
		{}
		Queue(const Queue& other)
		{
			_size = other._size;
			try
			{
				_data = new T[_size];
				for(size_t i = 0; i < _size; ++i)
				{
					_data[i] = other._data[i];
				}
			}
			catch(std::bad_alloc e)
			{
				std::cout << e.what() << std::endl;
				_size = 0;
			}
		}
		void push(T value)
		{
			T* otherData;
			otherData = _data;
			try
			{
				_data = new T[_size + 1];
				for(size_t i = 0; i < _size; ++i)
				{
					_data[i] = otherData[i];
				}
				_data[_size] = value;
				_size++;
				if(_size > 1)
				{
						delete[] otherData;
				}
			}
			catch(std::bad_alloc e)
			{
				std::cout << e.what() << std::endl;
				_data = otherData;
			}
		}
		T pop()
		{
			if(_size == 0)
			{
				return 0;
			}
			T value;
			value = _data[0];
			try
			{
				T* otherData;
				otherData = new T[_size - 1];
				_size--;
				for(size_t i = 0; i < _size; ++i)
				{
					otherData[i] = _data[i + 1];
				}
				if(_size > 0)
				{
					delete[] _data;
				}
				_data = otherData;
				return value;
			}
			catch(std::bad_alloc e)
			{
				std::cout << e.what() << std::endl;
				return 0;
			}
		}
		~Queue()
		{
			delete[] _data;
		}
		T front()
		{
			if(_size > 0)
			{
				return _data[0];
			}
			else
			{
				return 0;
			}
		}
		T back()
		{
			if(_size > 0)
			{
				return _data[_size - 1];
			}
			else
			{
				return 0;
			}
		}
		bool empty()
		{
			return _size == 0;
		}
		size_t size()
		{
			return _size;
		}

	private:
		T* _data;
		size_t _size;	
};


