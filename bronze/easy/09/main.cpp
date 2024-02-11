/*
USACO Bronze 2016: The Cow Signal (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=665
*/

#include <cstdio>
#include <iostream>
#include <vector>


std::vector<char> create_line(int line_length, int multiplier) {

    char character;
    std::vector<char> line;
    for (int j = 0; j < line_length; j++) {
        std::cin >> character;
        for (int k = 0; k < multiplier; k++) {
            line.push_back(character);
        }
    }

    return line;
}


void outputLine(std::vector<char> line, int multiplier) {

    for (int j = 0; j < multiplier; j++) {
        for (char character : line) {
            std::cout << character;
        }

        std::cout << "\n";
    }
}


int main() {
    // For USACO contests before 2020
    std::freopen("cowsignal.in", "r", stdin);
    std::freopen("cowsignal.out", "w", stdout);

    int row_number, line_length, multiplier;
    std::cin >> row_number >> line_length >> multiplier;

    for (int i = 0; i < row_number; i++) {
        auto line = create_line(line_length, multiplier);
        outputLine(line, multiplier);
    }

    return 0;
}
