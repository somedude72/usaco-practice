/*
USACO Silver 2017: Why Did The Cow Cross The Road II (Easy)
https://usaco.org/index.php?page=viewproblem2&cpid=715
*/

#include <bits/stdc++.h>

int main() {
    // For USACO contests before 2020
    std::ifstream fin("maxcross.in");
    std::ofstream fout("maxcross.out");

    int32_t n, k, b;
    fin >> n >> k >> b;
    std::vector<int> arr(n, 0);
    std::vector<int> partials(n + 1, 0);
    for (int i = 0; i < b; i++) {
        int32_t pos;
        fin >> pos;
        ++arr[pos - 1];
    }

    int32_t sol = INT32_MAX;
    for (size_t i = 1; i < partials.size(); i++)
        partials[i] = partials[i - 1] + arr[i - 1];
    for (size_t i = 1; i < partials.size() - k + 1; i++)
        sol = std::min(sol, partials[i + k - 1] - partials[i - 1]);
    fout << sol << '\n';
}
