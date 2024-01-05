/*
USACO Bronze 2016: Diamond Collector (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=639
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
	// For USACO contests before 2020
	std::freopen("diamond.in", "r", stdin);
	std::freopen("diamond.out", "w", stdout);

	int n, k;
	std::cin >> n >> k;

	std::vector<int> diamonds(n);
	for (int &item : diamonds) { std::cin >> item; }

	int answer = 0;
	for (const int center : diamonds) {
		int maxShowcase = 0;
		for (const int diamond : diamonds) {
			if (center <= diamond && diamond - center <= k) {
				maxShowcase++;
			}
		}

		if (maxShowcase >= answer) {
			answer = maxShowcase;
		}
	}

	std::cout << answer << std::endl;
	return 0;
}
