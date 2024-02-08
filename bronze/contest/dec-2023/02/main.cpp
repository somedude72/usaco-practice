/*
USACO Bronze 2023: Cowntact Tracing
Results: ☑☒☑☒☒☑☑☒☒☒☒☒
*/

#include <vector>
#include <iostream>
#include <algorithm>



int calculate_nights_passed(int cluster_size, int is_edge) {

	if (is_edge) { return cluster_size - 1; }
	if (cluster_size % 2 == 0) { return (cluster_size - 2) / 2; }
	if (cluster_size % 2 != 0) { return (cluster_size - 1) / 2; }
	return 0;
}


int main() {
	
	int n;
	std::cin >> n;

	int count = 0;
	bool edge = false;
	std::vector<char> scene(n);
	std::vector<int>  cluster_size;
	std::vector<bool> is_edge;
	for (int i = 0; i < n; i++) {
		std::cin >> scene[i];
		if (scene[i] == '1') { count++; }
		if (scene[i] == '1' && i == 0) { edge = true; }
		if (scene[i] == '1' && i == n - 1) { edge = true; }

		if (scene[i] == '0' && count != 0) { 
			cluster_size.push_back(count); 
			is_edge.push_back(edge);
			count = 0;
			edge = 0;
		}

		if (scene[i] == '1' && i == n - 1) { 
			cluster_size.push_back(count); 
			is_edge.push_back(edge);
			count = 0;
			edge = 0;
		}
	}
	
	if (cluster_size.size() == 0) { std::cout << 0 << std::endl; return 0;}

	int max_nights_passed;
	std::vector<int> nights_passed(cluster_size.size());
	for (int i = 0; i < cluster_size.size(); i++) {
		nights_passed[i] = calculate_nights_passed(cluster_size[i], is_edge[i]);
	}

	std::sort(nights_passed.begin(), nights_passed.end());
	max_nights_passed = nights_passed[0];
	int answer = 0;
	for (int i = 0; i < cluster_size.size(); i++) {
		answer += cluster_size[i] / (2 * max_nights_passed + 1);
		if (cluster_size[i] % (2 * max_nights_passed + 1) != 0) { answer++; }
	}

	std::cout << answer << std::endl;
	return 0;
}
