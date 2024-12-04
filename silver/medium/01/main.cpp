/*
USACO: Wormhole Sort (Medium)
https://usaco.org/index.php?page=viewproblem2&cpid=992&lang=en
*/

#include <bits/stdc++.h>

struct Hole {
    int a, b, w;
};

std::vector<int> bfs(const std::vector<std::vector<int>>& graph, const std::vector<int>& components, int start_index) {
    std::vector<int> ret = components;
    std::queue<int> queue;
    queue.push(start_index);
    while (!queue.empty()) {
        int front = queue.front();
        ret[front] = start_index;
        queue.pop();
        for (const auto& neighbor : graph[front]) {
            if (components[neighbor] == -1) {
                queue.push(neighbor);
            }
        }
    }

    return ret;
}

bool check(const std::vector<std::vector<int>>& graph, const std::vector<int>& cows) {
    std::vector<int> components(cows.size(), -1);
    for (size_t i = 0; i < components.size(); i++)
        if (components[i] == -1)
            components = bfs(graph, components, i);

    for (size_t i = 0; i < components.size(); i++)
        if (components[i] != components[cows[i]])
            return false;
    return true;
}

int main() {
    // For USACO contests before 2020
    std::ifstream fin("wormsort.in");
    std::ofstream fout("wormsort.out");

    int n, m;
    fin >> n >> m;
    std::vector<int> cows(n);
    std::vector<Hole> holes(m);

    for (auto& cow : cows) {
        fin >> cow;
        cow--;
    }

    for (auto& hole : holes) {
        fin >> hole.a >> hole.b >> hole.w;
        hole.a--;
        hole.b--;
    }

    sort(holes.begin(), holes.end(),
        [](Hole& a, Hole& b) { return a.w < b.w; });
    if (is_sorted(cows.begin(), cows.end())) {
        fout << -1 << std::endl;
        return 0;
    }

    // high stores unsortable, low stores sortable  
    // middle is included when checking sortability
    int low = 0;
    int high = holes.size() - 1;
    while (abs(high - low) != 1) {
        int middle = (high + low) / 2;

        std::vector<std::vector<int>> graph(cows.size());
        for (size_t i = middle; i < holes.size(); i++) {
            graph[holes[i].a].push_back(holes[i].b);
            graph[holes[i].b].push_back(holes[i].a);
        }

        if (check(graph, cows)) {
            low = middle;
        } else {
            high = middle;
        }
    }

    fout << holes[low].w << std::endl;
    return 0;
}
