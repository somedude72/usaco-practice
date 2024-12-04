/*
YS/Library Checker: Static Range Sum (Easy)
https://judge.yosupo.jp/problem/static_range_sum
*/

// Solution: Compute the prefix sum array to process
// the queries in O(n) complexity. 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n);
    vector<long long> partial;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++) 
        partial[i + 1] = partial[i] + arr[i];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << partial[b] - partial[a] << '\n';
    }
}
