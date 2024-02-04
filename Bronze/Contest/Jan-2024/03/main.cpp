/*
USACO Bronze 2024: Balancing Bacteria
Results: ☑☑☑☑☑☑☑☑☑☑☒☒☒☒☒
*/

#include <iostream>
#include <vector>
#include <cmath>


// Reminder: use long long! 
int main() {
    
    int n;
    std::cin >> n;
    
    std::vector<long long> bacteria_patches(n);
    for (int i = 0; i < n; i++) {
        std::cin >> bacteria_patches[i];
    }
    
    long long answer = 0;
    long long change_per_unit = 0;
    long long change_total = 0;
    
    int distance = n;
    for (int i = 0; i < n; i++) {
        distance = n - (i + 1);
        bacteria_patches[i] += change_total - (change_per_unit * distance);
        
        answer += std::abs(bacteria_patches[i]);
        change_per_unit += -(bacteria_patches[i]);
        change_total += -(bacteria_patches[i] * (distance + 1));
    }
    
    std::cout << answer << "\n";
    return 0;
}
