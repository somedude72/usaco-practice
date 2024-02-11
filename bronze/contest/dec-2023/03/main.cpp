/*
USACO Bronze 2023: Farmer John Actually Farms
Results: Not attempted
*/

#include <algorithm>
#include <iostream>
#include <vector>


bool plant_value_h(std::vector<long long> v1, std::vector<long long> v2) {

    return (v1[0] < v2[0]);
}


bool plant_value_t(std::vector<long long> v1, std::vector<long long> v2) {

    return (v1[2] < v2[2]);
}


long long days_plant_becomes_taller(std::vector<long long> plant_one,
                                    std::vector<long long> plant_two) {

    if (plant_one[0] > plant_two[0]) {
        return 0;
    }
    if (plant_one[1] > plant_two[1]) {
        return (plant_two[0] - plant_one[0]) / (plant_one[1] - plant_two[1]) + 1;
    }
    return 0;
}


bool satisfied_farmer_john(std::vector<std::vector<long long>> plants) {

    std::sort(plants.begin(), plants.end(), plant_value_h);
    std::reverse(plants.begin(), plants.end());
    for (int i = 0; i < plants.size(); i++) {
        if (!(plants[i][2] <= i)) {
            return false;
        }
    }

    return true;
}


void run_test_case() {

    int n;
    std::cin >> n;

    std::vector<std::vector<long long>> plants(n, std::vector<long long>(3));
    for (auto &plant : plants) { std::cin >> plant[0]; }
    for (auto &plant : plants) { std::cin >> plant[1]; }
    for (auto &plant : plants) { std::cin >> plant[2]; }

    long long days = 0;
    std::sort(plants.begin(), plants.end(), plant_value_t);
    for (int i = 0; i < n - 1; i++) {
        days = std::max(
               days_plant_becomes_taller(plants[i], plants[i + 1]), days);
    }

    for (int i = 0; i < n; i++) { plants[i][0] += plants[i][1] * days; }

    if (satisfied_farmer_john(plants)) {
        std::cout << days << "\n";
        return;
    }

    std::cout << -1 << "\n";
}


int main() {

    int t;
    std::cin >> t;

    while (t--) { run_test_case(); }
    return 0;
}
