/*
USACO Bronze 2023: Cowntact Tracing
Results: ☑☒☑☒☒☑☑☒☒☒☒☒
*/

#include <vector>
#include <iostream>
#include <algorithm>



int calculateNightsPassed(int clusterSize, int isEdge) {

	if (isEdge) { return clusterSize - 1; }
	if (clusterSize % 2 == 0) { return (clusterSize - 2) / 2; }
	if (clusterSize % 2 != 0) { return (clusterSize - 1) / 2; }
}


int main() {
	
	int n;
	std::cin >> n;

	int count = 0;
	bool edge = false;
	std::vector<char> scene(n);
	std::vector<int>  clusterSize;
	std::vector<bool> isEdge;
	for (int i = 0; i < n; i++) {
		std::cin >> scene[i];
		if (scene[i] == '1') { count++; }
		if (scene[i] == '1' && i == 0) { edge = true; }
		if (scene[i] == '1' && i == n - 1) { edge = true; }

		if (scene[i] == '0' && count != 0) { 
			clusterSize.push_back(count); 
			isEdge.push_back(edge);
			count = 0;
			edge = 0;
		}

		if (scene[i] == '1' && i == n - 1) { 
			clusterSize.push_back(count); 
			isEdge.push_back(edge);
			count = 0;
			edge = 0;
		}
	}
	
	if (clusterSize.size() == 0) { std::cout << 0 << std::endl; return 0;}

	int maxNightsPassed;
	std::vector<int> nightsPassed(clusterSize.size());
	for (int i = 0; i < clusterSize.size(); i++) {
		nightsPassed[i] = calculateNightsPassed(clusterSize[i], isEdge[i]);
	}

	std::sort(nightsPassed.begin(), nightsPassed.end());
	maxNightsPassed = nightsPassed[0];
	int answer = 0;
	for (int i = 0; i < clusterSize.size(); i++) {
		answer += clusterSize[i] / (2 * maxNightsPassed + 1);
		if (clusterSize[i] % (2 * maxNightsPassed + 1) != 0) { answer++; }
	}

	std::cout << answer << std::endl;
	return 0;
}
