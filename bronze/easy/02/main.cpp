/*
USACO Bronze 2017: Blocked Billboard (Easy)
https://www.usaco.org/index.php?page=viewproblem2&cpid=759

Note -
This is a particularly hacky and slow solution that was written very hastefully :P
*/

#include <cstdio>
#include <iostream>
#include <vector>


int main() {
    // For USACO contests before 2020
    std::freopen("billboard.in", "r", stdin);
    std::freopen("billboard.out", "w", stdout);

    std::vector<std::vector<int>> scene(2000,
                                        std::vector<int>(2000));

    int billboard_one;
    int billboard_two;
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    x1 += 1000;
    y1 += 1000;
    x2 += 1000;
    y2 += 1000;
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            scene[j][i] += 1;
        }
    }
    billboard_one = (x2 - x1) * (y2 - y1);

    std::cin >> x1 >> y1 >> x2 >> y2;
    x1 += 1000;
    y1 += 1000;
    x2 += 1000;
    y2 += 1000;
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            scene[j][i] += 1;
        }
    }
    billboard_two = (x2 - x1) * (y2 - y1);

    std::cin >> x1 >> y1 >> x2 >> y2;
    x1 += 1000;
    y1 += 1000;
    x2 += 1000;
    y2 += 1000;
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            scene[j][i] += 1;
        }
    }

    int blocked = 0;
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            if (scene[j][i] == 2) {
                blocked++;
            }
        }
    }

    std::cout << (billboard_one + billboard_two) - blocked << std::endl;
    return 0;
}
