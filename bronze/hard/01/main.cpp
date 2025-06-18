/*
USACO Bronze 2016: Angry Cows (Hard)
https://www.usaco.org/index.php?page=viewproblem2&cpid=592
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


int explode_cow(vector<int>& hay_line, int cow_index) {
    int upper_bound;
    int lower_bound;

    int explosion_intensity = 1;
    int current_index = cow_index;
    while (true) {
        bool next_index = false;
        for (int i = hay_line.size() - 1; i > current_index; i--) {
            if (hay_line[i] <= hay_line[current_index] + explosion_intensity) {
                current_index = i;
                explosion_intensity++;
                next_index = true;
            }
        }

        if (!next_index)
            break;
    }

    upper_bound = current_index;
    explosion_intensity = 1;
    current_index = cow_index;
    while (true) {
        bool next_index = false;
        for (int i = 0; i < current_index; i++) {
            if (hay_line[i] >= hay_line[current_index] - explosion_intensity) {
                current_index = i;
                explosion_intensity++;
                next_index = true;
            }
        }

        if (!next_index)
            break;
    }

    lower_bound = current_index;
    return (upper_bound - lower_bound) + 1;
}


int main() {
    // For USACO contests before 2020
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    int number_of_hay;
    fin >> number_of_hay;

    vector<int> hay_line(number_of_hay);
    for (int index = 0; index < number_of_hay; index++) {
        fin >> hay_line[index];
    }

    sort(hay_line.begin(), hay_line.end());

    int max_explosion = 0;
    for (int index = 0; index < hay_line.size(); index++) {
        max_explosion = max(max_explosion, explode_cow(hay_line, index));
    }
    

    fout << max_explosion << "\n";
    return 0;
}
