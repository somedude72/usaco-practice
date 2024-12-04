/*
Codeforces: Convenient For Everybody (Easy)
https://codeforces.com/problemset/problem/939/C
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, beg, end;
    cin >> n;
    vector<int> master(n);
    vector<int> prefix(n);

    for (auto& x : master)
        cin >> x;
    cin >> beg >> end;
    beg--; end--;

    for (int i = 0; i < n; i++) {
        int s_index = (beg - i + n) % n;
        int f_index = (end - i + n) % n;
        prefix[s_index] += master[i];
        prefix[f_index] -= master[i];
        if (f_index < s_index) {
            prefix[0] += master[i];
        }
    }

    int answer = 0;
    int running = 0, maximum = 0;
    for (int i = 0; i < n; i++) {
        running += prefix[i];
        if (running > maximum) {
            maximum = running;
            answer = i + 1;
        }
    }

    cout << answer << '\n';
}
