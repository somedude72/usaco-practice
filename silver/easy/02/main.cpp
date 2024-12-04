/*
USACO Silver 2016: Subsequences Summing to Sevens (Easy)
https://usaco.org/index.php?page=viewproblem2&cpid=595
*/

// Solution: Compute the prefix sum array. Observe that a subarray
// meets the requirement of having its sum be a multiple of seven
// only if the ends of the prefix sum mod 7 are the same. Then,
// compute the maximum subarray. 
#include <bits/stdc++.h>
using namespace std;

int main() {
    // For USACO contests before 2020
    ifstream fin("div7.in");
    ofstream fout("div7.out");

    int n; 
    fin >> n;
    vector<long long> arr(n);
    vector<long long> partials;
    for (size_t i = 0; i < arr.size(); i++)
        fin >> arr[i];
    partials[0] = arr[0];
    for (size_t i = 1; i < partials.size(); i++) 
        partials[i] = partials[i - 1] + arr[i];
    for (size_t i = 0; i < partials.size(); i++)
        partials[i] = partials[i] % 7;
    
    vector<int> longest_length(7, 0);
    for (int i = 0; i < 7; i++) {
        auto a = find(partials.begin(), partials.end(), i);
        auto b = find(partials.rbegin(), partials.rend(), i);
        if (a == partials.end() || b == partials.rend())
            continue;
        longest_length[i] = distance(a, b.base() - 1);
    }

    int answer = 0;
    for (const auto& element : longest_length)
        answer = max(element, answer);
    fout << answer << endl;
}
