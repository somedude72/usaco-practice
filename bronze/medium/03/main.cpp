/*
USACO Bronze 2017: Why Did the Cow Cross the Road III (Medium)
https://www.usaco.org/index.php?page=viewproblem2&cpid=713
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>

using namespace std;


int main() {

    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");

    int number_of_cows;
    fin >> number_of_cows;

    pair<int, int> cows[1000]{};
    for (int i = 0; i < number_of_cows; i++) {
        fin >> cows[i].first >> cows[i].second;
    }

    sort(begin(cows), begin(cows) + number_of_cows);
    for (int current_cow = 0; current_cow < number_of_cows; current_cow++) {
        if (current_cow == 0) {
            cows[current_cow].first += cows[current_cow].second;
            continue;
        }

        if (cows[current_cow - 1].first > cows[current_cow].first) {
            cows[current_cow].first = cows[current_cow - 1].first;
        }

        cows[current_cow].first += cows[current_cow].second;
    }

    fout << cows[number_of_cows - 1].first << "\n";
    return 0;
}
