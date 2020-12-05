#pragma once 
#include <iostream>

template <typename T>
class Ptr
{
	public:
		Ptr();
		Ptr(T* ptr);
		Ptr(Ptr& a);
		~Ptr();
		Ptr& operator=(Ptr& a);
		Ptr(const Ptr<T>& copy) = delete;
		Ptr& operator=(const Ptr<T>& copy) = delete;
		T* operator->();
		T& operator*();
	private:
		T *m_ptr;
};

template <typename T>
Ptr<T>::Ptr()
	: m_ptr(nullptr)
{
	std::cout << "()" << std::endl;
}

template <typename T>
Ptr<T>::Ptr(T* ptr)
	: m_ptr(ptr)
{
	std::cout << "T* ptr" << std::endl;
}

template <typename T>
Ptr<T>::Ptr(Ptr& a)
{
	this->m_ptr = a.m_ptr;
	a.m_ptr = nullptr;
}

template <typename T>
Ptr<T>& Ptr<T>::operator=(Ptr& a)
{
	if(this == &a)
		return *this;
	this->m_ptr = nullptr;
	this->m_ptr = a.m_ptr;	
	a.m_ptr = nullptr;
	std::cout << "operator=(Ptr&a)" << std::endl;
	return *this;
}

template <typename T>
T* Ptr<T>::operator->()
{
	return this->m_ptr;
}

template <typename T>
T& Ptr<T>::operator* ()
{
	return *this->m_ptr;
}

template <typename T>
Ptr<T>::~Ptr()
{
	if(this->m_ptr != nullptr)
	delete m_ptr;
	m_ptr = nullptr;
}
