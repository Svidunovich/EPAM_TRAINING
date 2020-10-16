#include <iostream>
#include <algorithm> 
#include <cstring>



class String{
	private:
		char *m_string;
		int m_len;
	public:
		String(char *str, int size){
			m_len = size;
			m_string = new char[size];
			std::copy_n(str, size, m_string);
		}
		void change(){
			int count = 0;
			for(int i = 0; i < m_len; i++){
				if(m_string[i] == '.'){
					break;
				}
				if(m_string[i] == '3'){
					m_string[i] = '+';
					count++;
				}
			}
			std::cout << "Number of change: " << count << "\n\n";
		}

		void output(){
			for(int i = 0; i < m_len; i++){
				std::cout << m_string[i];
			}
			std::cout << std::endl;
		}	

		~String(){
			delete[] m_string;
		}
};



int main(){
	char *str = new char;
	std::cin >> str;
	std::cout << "\n";
	String place(str, strlen(str));
	place.change();
	place.output();
	return 0;
}
