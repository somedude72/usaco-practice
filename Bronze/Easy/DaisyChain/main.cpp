/*
USACO Bronze 2020: Daisy Chains (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=1060
*/

#include <vector>
#include <iostream>


bool isAverageInRange(int rangeStart, int rangeEnd, 
					  std::vector<int> vector) {

	float average = 0.0;
	for (int k = rangeStart; k <= (rangeStart + rangeEnd); k++) {
		average += float(vector[k]);
	}

	average /= rangeEnd + 1;
	for (int k = rangeStart; k <= (rangeStart + rangeEnd); k++) {
		if (float(vector[k]) == average) {
			return true;
		}
	}

	return false;
}

int main() {
	
	int n;
	std::cin >> n;

	std::vector<int> flowers(n);
	for (auto &flower : flowers) { std::cin >> flower; }

	int answer = 0;
	for (int endpoint = 0; endpoint < flowers.size(); endpoint++) {
		for (int startpoint = 0; startpoint < (flowers.size() - endpoint); startpoint++) {
			if (isAverageInRange(startpoint, endpoint, flowers)) { answer++; }
		}
	}

	std::cout << answer << std::endl;
	return 0;
}
