/*
USACO Bronze 2024: Mejority Opinion
Results: ☑☑☑☑☑☑☑☑☑☑☑☑☑☑☑
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>


void run_test_case() {

    int n;
    std::cin >> n;

    int fresh = 0;
    int paired = 0;
    int sandwich = 0;

    std::set<int> hays;
    for (int i = 0; i < n; i++) {
        sandwich = paired;
        paired = fresh;

        std::cin >> fresh;
        if (fresh == sandwich || fresh == paired) {
            hays.insert(fresh);
        }
    }

    if (hays.size() == 0) {
        std::cout << -1 << "\n";
        return;
    }

    std::string answer = "";
    for (const auto& hay : hays) {
        answer += std::to_string(hay);
        answer += " ";
    }

    answer.pop_back();
    std::cout << answer << "\n";
    return;
}


int main() {

    int test_cases;
    std::cin >> test_cases;

    while (test_cases--) {
        run_test_case();
    }

    return 0;
}
