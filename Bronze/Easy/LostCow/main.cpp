/*
USACO Bronze 2017: The Lost Cow (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=735
*/

#include <cstdio>
#include <iostream>


int calculateDistance(int targetLocation, int startLocation) {
	
	int searchedMax = startLocation;
	int searchedMin = startLocation;
	int moveDistance = 1;
	int totalMoved = 0;

	while (searchedMax < targetLocation || searchedMin > targetLocation) {
		if (moveDistance > 0) {
			searchedMax = startLocation + moveDistance;
		} else {
			searchedMin = startLocation + moveDistance;
		}
		totalMoved += std::abs(moveDistance) + std::abs(moveDistance/-2);
		moveDistance *= -2;
	}

	moveDistance /= 2;
	if (moveDistance>0) {
		totalMoved = totalMoved - (searchedMax - targetLocation);
	} else {
		totalMoved = totalMoved - (targetLocation - searchedMin);
	}

	return moveDistance;
}


int main() {
	// For USACO contests before 2020
	std::freopen("lostcow.in", "r", stdin);
	std::freopen("lostcow.out", "w", stdout);

	int farmerLocation, cowLocation;
	std::cin >> farmerLocation >> cowLocation;

	std::cout << calculateDistance(farmerLocation, cowLocation);
	return 0;
}
