/*
USACO Bronze 2020: Daisy Chains (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=1060
*/

#include <vector>
#include <iostream>


bool is_average_in_range(int range_start, int range_end, 
					  std::vector<int> vector) {

	float average = 0.0;
	for (int k = range_start; k <= (range_start + range_end); k++) {
		average += float(vector[k]);
	}

	average /= range_end + 1;
	for (int k = range_start; k <= (range_start + range_end); k++) {
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
	for (int end_point = 0; end_point < flowers.size(); end_point++) {
		for (int start_point = 0; start_point < (flowers.size() - end_point); start_point++) {
			if (is_average_in_range(start_point, end_point, flowers)) { answer++; }
		}
	}

	std::cout << answer << std::endl;
	return 0;
}
