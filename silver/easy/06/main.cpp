/*
Codeforces: Studying Algorithms (Easy)
https://codeforces.com/gym/102951/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (auto& element : arr)
        cin >> element;
    sort(arr.begin(), arr.end());

    int ans = 0;
    int running = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        if (running + arr[i] <= x) {
            running += arr[i];
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
