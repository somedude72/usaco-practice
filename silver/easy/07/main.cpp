/*
USACO: Counting Haybales (Easy)
https://usaco.org/index.php?page=viewproblem2&cpid=666
*/

#include <bits/stdc++.h>

int main() {
    // For USACO contests before 2020
    std::ifstream fin("haybales.in");
    std::ofstream fout("haybales.out");

    int n, q;
    fin >> n >> q;
    std::vector<int> arr(n);
    for (auto& element : arr)
        fin >> element;
    std::sort(arr.begin(), arr.end());

    for (int i = 0; i < q; i++) {
        int a, b;
        fin >> a >> b;
        auto hi = std::lower_bound(arr.begin(), arr.end(), b);
        auto lo = std::lower_bound(arr.begin(), arr.end(), a);
        if (*hi > b && hi != arr.end())
            hi--;
        hi = hi == arr.end() ? hi - 1 : hi;
        fout << hi - lo + 1 << '\n';
    }
}