/*
Codeforces: Kayaking (Medium)
https://codeforces.com/contest/863/problem/B
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int calculate_stability(int remove_index_one, int remove_index_two,
                        vector<int> weight) {

    int stability = 0;
    weight.erase(weight.begin() + remove_index_one);
    weight.erase(weight.begin() + remove_index_two - 1);
    for (int i = 0; i < weight.size() - 1; i += 2) {
        stability += (weight[i + 1] - weight[i]);
    }

    return stability;
}


int main() {

    int n;
    cin >> n;
    vector<int> weight(2 * n);
    for (auto &person : weight) {
        cin >> person;
    }

    sort(weight.begin(), weight.end());

    vector<int> answer;
    for (int i = 0; i < weight.size() - 1; i++) {
        for (int j = i + 1; j < weight.size(); j++) {
            answer.push_back(calculate_stability(i, j, weight));
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer[0] << "\n";
    return 0;
}
