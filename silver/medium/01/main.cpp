/*
Codeforces: Running Miles (Medium)
https://codeforces.com/contest/1826/problem/D
*/

#include <bits/stdc++.h>

void solve() {
    int32_t n;
    std::cin >> n;
    std::vector<int32_t> arr(n);
    for (auto& x : arr)
        std::cin >> x;

    // Answer is $$ max(b_l + b_m + b_r - (r - l)) $$. We can rearrange the equation to
    // say $$ max((b_l + l) + b_m + (b_r - r)) $$. We choose loop over the index m, and
    // calculate the maximum of $$ b_l + l $$ and $$ b_r - r $$, which we'll now call
    // $$ L(i) $$ and $$ R(i) $$, where i is the index m. 
    // 
    // To make it efficient, we can observe that the maximum of $$ L(i) $$ can only be
    // $$ max(L(i - 1),\ b_{i - 1} + (i - 1)) $$ (this can be proven similar to Kadane's
    // Algorithm). Similarly, the maximum of $$ R(i) $$ is basically the same except for
    // some minor sign flips. 
    std::vector<int32_t> L(n, INT32_MIN); // The left highest beauty sight when the middle is `i`
    std::vector<int32_t> R(n, INT32_MIN); // The right highest beauty sight when the middle is `i`
    int sol = 0;
    for (int32_t i = 1; i < n; i++)
        L[i] = std::max(L[i - 1], arr[i - 1] + (i - 1));
    for (int32_t i = n - 2; i >= 0; i--)
        R[i] = std::max(R[i + 1], arr[i + 1] - (i + 1));
    for (int32_t i = 1; i < n - 1; i++)
        sol = std::max(sol, L[i] + arr[i] + R[i]);
    std::cout << sol << '\n';
}

int main() {
    int32_t t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}