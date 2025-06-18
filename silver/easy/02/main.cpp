/*
USACO Silver 2016: Subsequences Summing to Sevens (Easy)
https://usaco.org/index.php?page=viewproblem2&cpid=595
*/

#include <bits/stdc++.h>

int main() {
    // For USACO contests before 2020
    std::ifstream fin("div7.in");
    std::ofstream fout("div7.out");

    int32_t n;
    fin >> n;

    int64_t running_partials = 0;
    std::vector<int32_t> partials(n + 1, 0);
    for (int32_t i = 0; i < n; i++) {
        int32_t temp;
        fin >> temp;
        running_partials += temp;
        partials[i + 1] = running_partials % 7;
    }

    int32_t sol = 0;
    std::vector<int32_t> beg(7, INT32_MAX);
    std::vector<int32_t> end(7, INT32_MIN);
    for (size_t i = 0; i < partials.size(); i++)
        beg[partials[i]] = std::min<int32_t>(beg[partials[i]], i);
    for (size_t i = 0; i < partials.size(); i++)
        end[partials[i]] = std::max<int32_t>(end[partials[i]], i);
    for (int32_t i = 0; i < 7; i++)
        sol = std::max(sol, end[i] - beg[i]);

    fout << sol << std::endl;
}
