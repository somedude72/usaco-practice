/*
USACO: High Card Low Card (Easy)
https://usaco.org/index.php?page=viewproblem2&cpid=573
*/

#include <bits/stdc++.h>

int main() {
    // For USACO contests before 2020
    std::ifstream fin("cardgame.in");
    std::ofstream fout("cardgame.out");

    int n;
    fin >> n;
    std::vector<int> foe_cards(n);
    std::vector<int> my_cards;

    for (int i = 0; i < n; i++)
        fin >> foe_cards[i];

    std::vector<int> sorted_foe_cards = foe_cards;
    std::sort(sorted_foe_cards.begin(), sorted_foe_cards.end());
    for (int i = 0; i < 2 * n; i++) {
        auto it = std::lower_bound(
            sorted_foe_cards.begin(), 
            sorted_foe_cards.end(), 
            i + 1);
        if (it == sorted_foe_cards.end() || *it != i + 1) {
            my_cards.push_back(i);
        }
    }
    
    int solution = 0;
    std::vector<int> my_low_cards(my_cards.begin(), my_cards.begin() + n / 2);
    std::vector<int> my_high_cards(my_cards.begin() + n / 2, my_cards.end());
    for (int i = 0; i < n / 2; i++) {
        auto minimum = std::upper_bound(
            my_high_cards.begin(), 
            my_high_cards.end(), 
            foe_cards[i]);
        if (minimum != my_high_cards.end()) {
            solution++;
            my_high_cards.erase(minimum);
        } else {
            my_high_cards.erase(my_high_cards.begin());
        }
    }

    for (int i = 0; i < n / 2; i++) {
        auto maximum = std::upper_bound(
            my_low_cards.begin(), 
            my_low_cards.end(), 
            foe_cards[i + n / 2]);
        if (maximum != my_low_cards.begin()) {
            solution++;
            my_low_cards.erase(maximum - 1);
        } else {
            my_low_cards.pop_back();
        }
    }

    fout << solution << std::endl;
}