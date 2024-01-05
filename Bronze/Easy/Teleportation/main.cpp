/*
USACO Bronze 2015: Teleportation (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=807
*/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>


int main() {
	// For USACO contests before 2020
	std::freopen("teleport.in", "r", stdin);
	std::freopen("teleport.out", "w", stdout);

	int manureStart, manureEnd, teleport1, teleport2;
	std::cin >> manureStart >> manureEnd >> teleport1 >> teleport2;

	int route1 = std::abs(manureStart - teleport1) + std::abs(teleport2 - manureEnd);
	int route2 = std::abs(manureStart - teleport2) + std::abs(teleport1 - manureEnd);
	int route3 = std::abs(manureStart - manureEnd);

	std::cout << std::min({route1, route2, route3}) << std::endl;
	return 0;
}
