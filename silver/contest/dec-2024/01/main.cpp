/*
USACO Silver 2024: Cake Game
Results: ☑☑☒☒☒☒☒☒☒☒☒
*/

#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int64_t> partials(n + 1, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> partials[i + 1];
        partials[i + 1] += partials[i];
    }

    int64_t bessy_sol = INT64_MAX;
    int64_t elsie_sol = INT64_MAX;
    for (int i = 1; i <= n / 2; i++)
        bessy_sol = std::min(bessy_sol, partials[i + (n / 2)] - partials[i - 1]);
    elsie_sol = partials[partials.size() - 1] - bessy_sol;
    std::cout << bessy_sol << ' ' << elsie_sol << '\n';
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}