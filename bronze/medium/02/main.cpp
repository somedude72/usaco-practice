/*
USACO Bronze 2017: Why Did the Cow Cross the Road II (Medium)
https://www.usaco.org/index.php?page=viewproblem2&cpid=712
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


void nextCow(string &road_total, int &answer) {

    char current_cow = *road_total.begin();
    road_total.erase(road_total.begin());

    string road_segment = "";
    for (auto it = road_total.begin(); it < road_total.end(); it++) {
        if (*it == current_cow) {
            answer += road_segment.size();
            road_total.erase(it);
            break;
        }

        unsigned long find_index = road_segment.find(*it);
        if (find_index != string::npos) {
            road_segment.erase(find_index, 1);
        } else {
            road_segment += *it;
        }
    }
}


int main() {

    // For USACO contests before 2020
    std::ifstream fin("circlecross.in");
    std::ofstream fout("circlecross.out");

    string road_total;
    fin >> road_total;

    int answer = 0;
    for (int i = 0; i < 26; i++) {
        nextCow(road_total, answer);
    }

    fout << answer << "\n";
    return 0;
}
