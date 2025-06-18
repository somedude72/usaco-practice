/*
USACO Silver 2018: MooTube (Easy)
https://usaco.org/index.php?page=viewproblem2&cpid=788
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int bfs(std::vector<std::vector<std::pair<int, int>>> graph, int start, int req) {
    int ret = 0;
    std::queue<std::pair<int, int>> queue; // first = node, second = current relevance
    queue.push({ start, INT32_MAX });
    while (!queue.empty()) {
        std::pair<int, int> curr = queue.front();
        queue.pop();
        ret++;
        for (const auto& next : graph[curr.first]) {
            if (graph[next.first][0].first == -1) continue; // visited
            if (std::min(curr.second, next.second) < req) continue; // doesn't have enough relevance
            std::pair<int, int> new_node = { next.first, std::min(curr.second, next.second)};
            queue.push(new_node);
        }
        
        graph[curr.first].clear();
        graph[curr.first].push_back({ -1, -1 });
    }

    return ret - 1;
}

int main() {
    // For USACO contests before 2020
    std::ifstream fin("mootube.in");
    std::ofstream fout("mootube.out");

    int n, q;
    fin >> n >> q;
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, r;
        fin >> a >> b >> r;
        graph[a - 1].push_back({ b - 1, r });
        graph[b - 1].push_back({ a - 1, r });
    }

    for (int i = 0; i < q; i++) {
        int req, start;
        fin >> req >> start;
        fout << bfs(graph, start - 1, req) << std::endl;
    }
}