/*
USACO Bronze 2017: The Bovine Shuffle (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=760
*/

#include <cstdio>
#include <vector>
#include <iostream>


const int SHUFFLE_TIMES = 3;


std::vector<int> performShuffle(std::vector<int> list, 
								std::vector<int> key) {

	std::vector<int> shuffledList(list.size());
	for (int i = 0; i < list.size(); i++) {
		shuffledList[i] = list[key[i]-1];
	}

	return shuffledList;
}


int main() {
	// For USACO contests before 2020
	std::freopen("shuffle.in", "r", stdin);
	std::freopen("shuffle.out", "w", stdout);
	
	int n;
	std::cin >> n;
	std::vector<int> key(n);
	std::vector<int> list(n);
	
	for (int &item : key) { std::cin >> item; }
	for (int &item : list) { std::cin >> item; }

	for(int i = 0; i < SHUFFLE_TIMES; i++) {
		list = performShuffle(list, key);
	}

	for (int item : list) { std::cout << item << std::endl; }
	return 0;
}
