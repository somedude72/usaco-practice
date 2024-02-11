/*
USACO Bronze 2017: The Lost Cow (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=735
*/

#include <cstdio>
#include <iostream>


int calculateDistance(int targe_location, int start_location) {

    int searched_max = start_location;
    int searched_min = start_location;
    int move_dist = 1;
    int total_moved = 0;

    while (searched_max < targe_location || searched_min > targe_location) {
        if (move_dist > 0) {
            searched_max = start_location + move_dist;
        } else {
            searched_min = start_location + move_dist;
        }
        total_moved += std::abs(move_dist) + std::abs(move_dist / -2);
        move_dist *= -2;
    }

    move_dist /= 2;
    if (move_dist > 0) {
        total_moved = total_moved - (searched_max - targe_location);
    } else {
        total_moved = total_moved - (targe_location - searched_min);
    }

    return move_dist;
}


int main() {
    // For USACO contests before 2020
    std::freopen("lostcow.in", "r", stdin);
    std::freopen("lostcow.out", "w", stdout);

    int farmer_location, cow_location;
    std::cin >> farmer_location >> cow_location;

    std::cout << calculateDistance(farmer_location, cow_location);
    return 0;
}
