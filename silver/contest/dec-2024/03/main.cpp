/**
 * USACO Silver 2024: 2D Conveyor Belt
 * Results: Not attempted
 */

#include <bits/stdc++.h>

struct Query {
    int row, col;
    char dir;
};

bool is_valid(const std::vector<std::string>& squares, int row, int col) {
    return row >= 0 && row < squares.size() &&
        col >= 0 && col < squares[0].size();
}

int floodfill(std::vector<std::string>& squares, int row, int col) {
    if (squares[row][col] == '.')
        return 0;
    squares[row][col] = '.';
    int ret = 0;
    const int row_dirs[4] = { 1, 0, -1, 0 };
    const int col_dirs[4] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; i++) {
        int new_row = row + row_dirs[i];
        int new_col = col + col_dirs[i];
        if (!is_valid(squares, new_row, new_col))
            continue;
        char new_char = squares[new_row][new_col];
        if (i == 0 && new_char != 'U' && new_char != '?')
            continue;
        if (i == 1 && new_char != 'L' && new_char != '?')
            continue;
        if (i == 2 && new_char != 'D' && new_char != '?')
            continue;
        if (i == 3 && new_char != 'R' && new_char != '?')
            continue;
        ret += floodfill(squares, new_row, new_col);
    }

    return ret + 1;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::string> squares(n + 2, std::string(n + 2, '?'));
    std::vector<Query> queries(q, Query());
    for (auto& query : queries) {
        std::cin >> query.row >> query.col >> query.dir;
        squares[query.row][query.col] = query.dir;
    }

    std::vector<int> unusable(q);
    int total = (n + 2) * (n + 2) - floodfill(squares, 0, 0);
    for (int i = q - 1; i >= 0; i--) {
        unusable[i] = total;
        Query curr_query = queries[i];
        char square = squares[curr_query.row][curr_query.col];
        
    }

    for (const auto& answer : unusable) {
        std::cout << answer << '\n';
    }
}