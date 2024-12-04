/*
USACO Bronze 2024: Balancing Bacteria
Results: ☑☑☑☑☑☑☑☑☑☑☒☒☒☒☒
*/

#include <cmath>
#include <iostream>
#include <vector>


void use_fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// Reminder: use long long!
int main() {

    int n;
    std::cin >> n;

    use_fast_io();

    long long answer = 0;
    long long change_per_unit = 0;
    long long change_total = 0;

    long long distance = n;

    std::vector<long long> bacteria_patches(n);
    for (int i = 0; i < n; i++) {
        std::cin >> bacteria_patches[i];

        distance = n - (i + 1);
        bacteria_patches[i] += change_total - (change_per_unit * distance);

        answer += std::abs(bacteria_patches[i]);
        change_per_unit += -(bacteria_patches[i]);
        change_total += -(bacteria_patches[i] * (distance + 1));
    }

    std::cout << answer << '\n';
    return 0;
}
