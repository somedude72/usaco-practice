/*
USACO Bronze 2018: The Bucket List (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=856&lang=en
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


std::vector<int> range_add_vector(std::vector<int> vector, int number, 
								  int range_start, int range_end) {

	for (int i = std::min(range_start, range_end); i < std::max(range_start, range_end); i++) {
		vector[i] += number;
	}

	return vector;
}


int main() {
	// For USACO contests before 2020
	std::freopen("blist.in", "r", stdin);
	std::freopen("blist.out", "w", stdout);

	int n;
	std::cin >> n;

	std::vector<int> buckets_needed(1000);
	for (int i = 0; i < n; i++) {
		int required_bucket = 0;
		int time_one = 0;
		int time_two = 0;

		std::cin >> time_two >> time_one >> required_bucket;
		buckets_needed = range_add_vector(buckets_needed, required_bucket, time_one, time_two);
	}

	int max_buckets = 0;
	for (int i = 0; i < 1000; i++) {
		if (buckets_needed[i] > max_buckets) {
			max_buckets = buckets_needed[i];
		}
	}

	std::cout << max_buckets << std::endl;

	return 0;
}
