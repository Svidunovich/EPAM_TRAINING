#include "vector.h"


		Vector::Vector(double num[], int size){
				m_length = size;
				d_num = new double[m_length];
				for(int i = 0; i < m_length; i++){
					d_num[i] = num[i];
				}
			}

		Vector::Vector(int size){
				m_length = size;
				d_num = new double[m_length];
			}

		Vector::Vector(){
				m_length = 0;
			}
		

		void Vector::searchSum(){
			double sum = 0;
			for(int i = 0; i < m_length; i++){
				if(d_num[i] > 0){
					while(i != m_length - 1){
						i++;
						sum += d_num[i];
					}
				} 
	     	}
			std::cout << "Sum of element: " << sum << std::endl;
		}

		void Vector::sort(){
			for(int i = 0; i < m_length; i++){
				for(int j = 1 + i; j < m_length; j++){
					if(d_num[i] < d_num[j]){
						double temp = d_num[i];
						d_num[i] = d_num[j];
						d_num[j] = temp;
					}
				}
			}
		}

		void Vector::output(){
			for(int i = 0; i < m_length ; i++){
				std::cout << d_num[i] << "   ";
			}
			std::cout << "\n\n";
		}

		void Vector::min(){
			double min = d_num[0];
			for(int i = 1; i < m_length; i++){
				if(min > d_num[i]){
					min = d_num[i];
				}
			}
			std::cout << "Minimum number: " << min << "\n\n";
		}

		void Vector::max(){
			double max = d_num[0];
			for(int i = 1; i < m_length; i++){
				if(max < d_num[i]){
					max = d_num[i];	
				}
			}
			std::cout << "Maximum number: " << max << "\n\n";
		}

		void Vector::middle(){
			double middle = d_num[0];
			for(int i = 1; i < m_length; i++){
				middle += d_num[i];	
			}
			std::cout << "Avarage of numbers: " << middle / 10 << "\n\n";
		}


