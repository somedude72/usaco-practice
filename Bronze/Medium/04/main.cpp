/*
USACO Bronze 2019: Cow Gymnastics (Normal)
http://www.usaco.org/index.php?page=viewproblem2&cpid=963
*/

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


bool is_consistent_pair(int cow_one, int cow_two, 
					  vector<vector<int>> sessions) {

	int best_cow;
	int worse_cow;
	for (auto &cow : sessions[0]) {
		if (cow == cow_one) {
			best_cow = cow_one;
			worse_cow = cow_two;
			break;
		} else if (cow == cow_two) {
			best_cow = cow_two;
			worse_cow = cow_one;
			break;
		}
	}

	for (auto &session : sessions) {
		for (auto &cow : session) {
			if (cow == best_cow) {
				break;
			} else if (cow == worse_cow) {
				return false;
			}
		}
	}

	return true;
}


int main() {
	// For USACO contests before 2020
	ifstream fin("gymnastics.in");
	ofstream fout("gymnastics.out");

	int k, n;
	fin >> k >> n;

	vector<vector<int>> sessions(k, vector<int> (n));
	for (auto &session : sessions) {
		for (auto &cow : session) {
			fin >> cow;
		}
	}

	int answer = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (is_consistent_pair(i, j, sessions)) {
				answer++; 
			}
		}
	}

	fout << answer << std::endl;
	return 0;
}
