/*
CSES: Maximum Subarray Sum (Easy)
https://cses.fi/problemset/task/1643
*/

// Solution: Using Kadane's algorithm (https://www.youtube.com/watch?v=86CQq3pKSUw)
// to find the maximum sum of a subarray ending at the ith element, then iterating
// over the maximum sums to find the largest.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int32_t N;
    cin >> N;
    
    vector<int64_t> max_sub(N);
    for (int32_t i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        if (i == 0) {
            max_sub[i] = a;
        } else {
            max_sub[i] = max(max_sub[i - 1] + a, a);
        }
    }

    int64_t sol = INT64_MIN;
    for (const auto& element : max_sub)
        sol = max(sol, element);
    cout << sol << endl;
}
