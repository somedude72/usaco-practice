/*
USACO Bronze 2023: Candy Cane Feast
Results: ☑☒☒☒☒☒☒☒☒☒☒☒
*/

#include <iostream>
#include <vector>


int main() {

    int n, m;
    std::cin >> n >> m;

    std::vector<long long> cows(n);
    std::vector<long long> candies(m);
    for (auto &cow : cows) { std::cin >> cow; }
    for (auto &candy : candies) { std::cin >> candy; }

    for (auto &height : candies) {
        long long height_from_ground = 0;
        for (auto &cow : cows) {
            if (height_from_ground >= cow) {
                continue;
            }

            if (cow <= height) {
                long long eatable_area = (cow - height_from_ground);
                cow += eatable_area;
                height_from_ground += eatable_area;
            } else {
                cow += height - height_from_ground;
                break;
            }
        }
    }

    for (const auto cow : cows) { std::cout << cow << std::endl; }
    return 0;
}
