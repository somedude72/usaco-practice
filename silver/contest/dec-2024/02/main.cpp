/**
 * USACO Silver 2024: Deforestation
 * Results: Not attempted
 */

#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;

    /**
     * Events[i][0] - The location of the event (for sorting purposes)
     * Events[i][1] - The type of event (0 is interval start, 1 is tree, 2 is interval end)
     * Events[i][2] - (for intervals) Contraint of number of choppable trees
     * Events[i][3] - (for intervals) Other interval endpoint
     */
    std::vector<std::array<int, 4>> events;
    std::vector<int> trees(n);

    for (int i = 0; i < n; i++) {
        std::cin >> trees[i];
        events.push_back({ trees[i], 1 });
    }

    std::sort(trees.begin(), trees.end());
    for (int i = 0; i < k; i++) {
        int l, r, limit;
        std::cin >> l >> r >> limit;
        int lower = std::lower_bound(trees.begin(), trees.end(), l) - trees.begin();
        int upper = std::upper_bound(trees.begin(), trees.end(), r) - trees.begin();
        int choppable = upper - lower - limit;
        events.push_back({ l, 0, choppable, r });
        events.push_back({ r, 2, choppable, l });
    }

    std::sort(events.begin(), events.end(), 
        [](const std::array<int, 4>& a, const std::array<int, 4>& b) {
            return a[0] != b[0] ? 
                a[0] < b[0] :
                a[1] < b[1];
    });

    int total_chopped = 0;
    std::multiset<int> constraints;
    std::map<int, std::map<int, int>> chopped_map;
    constraints.insert(INT32_MAX);

    for (int i = 0; i < events.size(); i++) {
        if (events[i][1] == 1) {            // Encountering a tree
            if (*constraints.begin() - total_chopped > 0)
                total_chopped++;
        } else if (events[i][1] == 0) {     // Encountering the start of an interval
            constraints.insert(total_chopped + events[i][2]);
            chopped_map[events[i][0]][events[i][2]] = 
                total_chopped + events[i][2];
        } else {                            // Encountering the end of an interval (undoing the start of interval constraint)
            constraints.erase(
                constraints.find(chopped_map[events[i][3]][events[i][2]]));
        }
    }

    std::cout << total_chopped << '\n';
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}