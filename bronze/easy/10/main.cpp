/*
USACO Bronze 2015: Teleportation (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=807
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>


int main() {
    // For USACO contests before 2020
    std::freopen("teleport.in", "r", stdin);
    std::freopen("teleport.out", "w", stdout);

    int manure_start, manure_end, teleport_one, teleport_two;
    std::cin >> manure_start >> manure_end >> teleport_one >> teleport_two;

    int route1 = std::abs(manure_start - teleport_one) + std::abs(teleport_two - manure_end);
    int route2 = std::abs(manure_start - teleport_two) + std::abs(teleport_one - manure_end);
    int route3 = std::abs(manure_start - manure_end);

    std::cout << std::min({ route1, route2, route3 }) << std::endl;
    return 0;
}
