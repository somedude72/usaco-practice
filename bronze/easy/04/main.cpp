/*
USACO Bronze 2016: Diamond Collector (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=639
*/

#include <cstdio>
#include <iostream>
#include <vector>


int main() {
    // For USACO contests before 2020
    std::freopen("diamond.in", "r", stdin);
    std::freopen("diamond.out", "w", stdout);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> diamonds(n);
    for (auto& item : diamonds) { std::cin >> item; }

    int answer = 0;
    for (const auto& center : diamonds) {
        int max_showcase = 0;
        for (const auto& diamond : diamonds) {
            if (center <= diamond && diamond - center <= k) {
                max_showcase++;
            }
        }

        if (max_showcase >= answer) {
            answer = max_showcase;
        }
    }

    std::cout << answer << std::endl;
    return 0;
}
