/*
USACO: Berry Picking (Normal)
https://usaco.org/index.php?page=viewproblem2&cpid=990
*/

#include <bits/stdc++.h>

std::pair<int, int> get_berries(std::vector<int>& berries, int buckets, int limit) {
    int minimum_bucket = limit;
    int total_collected = 0;
    if (limit <= 0)
        return { 0, 0 };
    std::sort(berries.begin(), berries.end(), 
        [](int a, int b) { return a > b; });
    for (size_t i = 0; i < berries.size(); i++) {
        buckets -= berries[i] / limit;
        total_collected += ((int) (berries[i] / limit)) * limit;
        berries[i] %= limit;
        if (buckets <= 0) {
            berries[i] += std::abs(buckets) * limit;
            total_collected -= std::abs(buckets) * limit;
            buckets = 0;
            break;
        }
    }

    std::sort(berries.begin(), berries.end(),
        [](int a, int b) { return a > b; });
    for (int i = 0; i < buckets && !berries.empty(); i++) {
        total_collected += berries[0];
        minimum_bucket = berries[0];
        berries.erase(berries.begin());
    }

    return { minimum_bucket, total_collected };
}

int main() {
    // For USACO contests before 2020
    std::ifstream fin("berries.in");
    std::ofstream fout("berries.out");

    int n, k;
    fin >> n >> k;
    int max_b = 0;
    std::vector<int> berries(n);
    for (auto& x : berries) {
        fin >> x;
        max_b = std::max(max_b, x);
    }
    
    int solution = 0;
    for (int b = 1; b <= max_b; b++) {
        std::vector<int> temp_berries = berries;
        auto elsie = get_berries(temp_berries, k / 2, b);
        auto bessie = get_berries(temp_berries, k / 2, elsie.first);
        solution = std::max(solution, bessie.second);
    }

    fout << solution << std::endl;
}
