/*
USACO Bronze 2018: The Bucket List (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=856&lang=en
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


std::vector<int> rangeAddVector(std::vector<int> vector, int number, 
								int rangeStart, int rangeEnd) {

	for (int i = std::min(rangeStart, rangeEnd); i < std::max(rangeStart, rangeEnd); i++) {
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

	std::vector<int> bucketsNeeded(1000);
	for (int i = 0; i < n; i++) {
		int requiredBucket = 0;
		int timeOne = 0;
		int timeTwo = 0;

		std::cin >> timeTwo >> timeOne >> requiredBucket;
		bucketsNeeded = rangeAddVector(bucketsNeeded, requiredBucket, timeOne, timeTwo);
	}

	int maxBuckets = 0;
	for (int i = 0; i < 1000; i++) {
		if (bucketsNeeded[i] > maxBuckets) {
			maxBuckets = bucketsNeeded[i];
		}
	}

	std::cout << maxBuckets << std::endl;

	return 0;
}
