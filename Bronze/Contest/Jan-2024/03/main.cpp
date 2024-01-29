/*
USACO Bronze 2024: Balancing Bacteria
Results: ☑☑☑☑☑☑☑☑☑☑☒☒☒☒☒
*/

#include <iostream>
#include <vector>
#include <cmath>

// #include <dbg.h>


// Reminder: use long long! 
int main() {
    
    int n;
    std::cin >> n;
    
    std::vector<long long> bacteria_patches(n);
    for (int i = 0; i < n; i++) {
        std::cin >> bacteria_patches[i];
    }
        
    long long answer = 0;
    long long neutralize_times = 0;
    // dbg(bacteria_patches);
    for (long long i = 0; i < n; i++) {
        answer += std::abs(bacteria_patches[i]);
        neutralize_times = -bacteria_patches[i];
        if (neutralize_times == 0) { continue; }
        for (long long j = i; j < n; j++) {
            long long power_difference = (j + 1) - i;
            bacteria_patches[j] += (power_difference * neutralize_times);
        }
        // dbg(bacteria_patches);
    }
    
    std::cout << answer << "\n";
    return 0;
}
