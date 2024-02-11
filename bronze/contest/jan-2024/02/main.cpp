/*
USACO Bronze 2024: Cannonball
Results: ☑☑☑☑☑☑☑☑☑☑☑☑☑☑☑☑☑☑☑☑
*/

#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>


int main() {

    int n;
    std::cin >> n;

    int start;
    std::cin >> start;

    std::vector<std::pair<int, int>> number_line(n);
    for (auto& number : number_line) {
        std::cin >> number.first
                 >> number.second;
    }

    int current_power = 1;
    int current_location = start - 1;

    char facing = 'R';
    int last_pad = -1;
    int this_pad = -1;

    int answer = 0;
    while (true) {

        if (current_location < 0 || number_line.size() <= current_location) {
            break;
        }

        if (last_pad == 0 && this_pad == 0) {
            break;
        }

        if (number_line[current_location].first == 1 && number_line[current_location].second <= current_power) {

            answer++;
            number_line[current_location].second = INT32_MAX;
        }

        if (number_line[current_location].first == 0) {

            if (facing == 'R') {
                facing = 'L';
            } else {
                facing = 'R';
            }

            last_pad = this_pad;
            this_pad = number_line[current_location].second;

            current_power += number_line[current_location].second;
        }

        if (facing == 'R') {
            current_location += current_power;
        } else {
            current_location -= current_power;
        }
    }

    std::cout << answer << "\n";
    return 0;
}
