/*
CSES: Subarray Divisibility (Easy)
https://cses.fi/problemset/task/1662
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int64_t psum = 0;
    vector<int64_t> totals(n);
    totals[0] = 1;
    for (int i = 0; i < n; i++) {
        int current;
        cin >> current;
        psum += current;
        totals[(psum % n + n) % n]++;
    }

    int64_t answer = 0;
    for (const auto& x : totals)
        answer += x * (x - 1) / 2;
    cout << answer << '\n';
}
