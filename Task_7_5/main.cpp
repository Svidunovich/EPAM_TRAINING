#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>


void out(std::vector<std::string> &v){
	std::cout << "==================================================\n";
	for(int i = 1; i < v.size() + 1; i++){
		std::cout << v[i - 1] << " | ";
		if(i % 4 == 0){
			std::cout << std::endl;
		}
	}
	std::cout << "\n==================================================";
	std::cout << "\n\n";
}


int main(){
	srand(time(NULL));

	std::vector<std::string> deck;
	std::vector<std::string> suits = {"Diamond", "Heart", "Spade", "Club"};
	std::vector<std::string> cards = { "Ace", "King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2" };

	for(int i = 0; i < 13; i++){
		deck.push_back(suits[0] + " " + cards[i]);
		deck.push_back(suits[1] + " " + cards[i]);
		deck.push_back(suits[2] + " " + cards[i]);		
		deck.push_back(suits[3] + " " + cards[i]);
	}

	std::unordered_set<int> random;

	while(random.size() != 52){
		random.insert(rand() % 52);
	}
	std::unordered_set<int>::const_iterator it;
	it = random.begin();

	std::vector<std::string> player_1, player_2, player_3, player_4;	

	while(it != random.end()){
		player_1.push_back(deck[*it]);
		it++;
		player_2.push_back(deck[*it]);
		it++;
		player_3.push_back(deck[*it]);
		it++;
		player_4.push_back(deck[*it]);
		it++;
	}

	std::cout << "Player cards one: " << std::endl;
	out(player_1);
	std::cout << "Player cards two: " << std::endl;
	out(player_2);
	std::cout << "Player cards three: " << std::endl;
	out(player_3);
	std::cout << "Player cards four: " << std::endl;
	out(player_4);

	return 0;
}
