#pragma once 
#include <iostream>
#include <bits/stdc++.h>

template <typename T>
class Array{
	private: 
		T *arr;
		int _size;
	public:
		Array(T array[], int size);
		void sort();
		void out();
		~Array();
};


template <typename T>
Array<T>::Array(T array[], int size){
	arr = new T[size];
	_size = size;
	for(int i = 0; i < _size; i++){
		arr[i] = array[i]; 
	}
}

template <typename T>
void Array<T>::sort(){
	for(int i = 0; i < _size; i++){
		for(int j = 1 + i; j < _size; j++){
			if(arr[i] < arr[j]){
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}	
		}
	}
}

template <typename T>
void Array<T>::out(){
	for(int i = 0; i < _size; i++){
		std::cout << arr[i] << std::endl;
	}
}


template <typename T>
Array<T>::~Array(){
	delete[] arr;
}


