/*
USACO Bronze 2020: Do you know your ABCs? (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=1059
*/

#include <algorithm>
#include <iostream>
#include <vector>


int main() {

    int sum = 0;
    std::vector<int> input(6);

    for (int i = 0; i <= 6; i++) {
        std::cin >> input[i];
        if (input[i] > sum) {
            sum = input[i];
        }
    }

    std::sort(input.begin(), input.end());

    std::cout << input[0] << " "
              << input[1] << " "
              << sum - (input[1] + input[0])
              << std::endl;

    return 0;
}
