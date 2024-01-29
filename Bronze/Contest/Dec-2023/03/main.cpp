/*
USACO Bronze 2023: Farmer John Actually Farms
Results: Not attempted
*/

#include <iostream>
#include <algorithm>
#include <vector>


bool plantHValue(std::vector<long long> v1, std::vector<long long> v2) {

	return (v1[0] < v2[0]);
}


bool plantTValue(std::vector<long long> v1, std::vector<long long> v2) {

	return (v1[2] < v2[2]);
}


long long daysPlantBecomesTaller(std::vector<long long> plantOne, 
								 std::vector<long long> plantTwo) {

	if (plantOne[0] > plantTwo[0]) { return 0; }
	if (plantOne[1] > plantTwo[1]) { return (plantTwo[0] - plantOne[0]) / (plantOne[1] - plantTwo[1]) + 1; }
	return 0;
}


bool satisfiedFarmerJohn(std::vector<std::vector<long long>> plants) {

	std::sort(plants.begin(), plants.end(), plantHValue);
	std::reverse(plants.begin(), plants.end());
	for (int i = 0; i < plants.size(); i++) {
		if (!(plants[i][2] <= i)) {
			return false;
		}
	}
	
	return true;
}


void runTestCase() {

	int n;
	std::cin >> n;

	std::vector<std::vector<long long>> plants(n, std::vector<long long>(3));
	for (auto &plant : plants) { std::cin >> plant[0]; }
	for (auto &plant : plants) { std::cin >> plant[1]; }
	for (auto &plant : plants) { std::cin >> plant[2]; }

	long long days = 0;
	std::sort(plants.begin(), plants.end(), plantTValue);
	for (int i = 0; i < n - 1; i++) {
		days = std::max(daysPlantBecomesTaller(plants[i], plants[i + 1]), days);
	}

	for (int i = 0; i < n; i++) { plants[i][0] += plants[i][1] * days; }

	if (satisfiedFarmerJohn(plants)) { 
		std::cout << days << "\n"; 
		return;
	}
	
	std::cout << -1 << "\n";
}


int main() {
	
	int t;
	std::cin >> t;

	while (t--) { runTestCase(); }
	return 0;
}
