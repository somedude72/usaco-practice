/*
USACO Bronze 2023: Candy Cane Feast
Results: ☑☒☒☒☒☒☒☒☒☒☒☒
*/

#include <iostream>
#include <vector>


int main() {
	
	int numberOfCows, numberOfCandy;
	std::cin >> numberOfCows >> numberOfCandy;

	std::vector<long long> cows(numberOfCows);
	std::vector<long long> candies(numberOfCandy);
	for (auto &cow : cows) { std::cin >> cow; }
	for (auto &candy : candies) { std::cin >> candy; }

	for (auto &height : candies) {
		long long heightFromGround = 0;
		for (auto &cow : cows) {
			if (heightFromGround >= cow) { continue; }

			if (cow <= height) {
				long long eatableArea = (cow - heightFromGround);
				cow += eatableArea;
				heightFromGround += eatableArea;
			} else {
				cow += height - heightFromGround;
				break;
			}
		}
	}

	for (const auto cow : cows) { std::cout << cow << std::endl; }
	return 0;
}
