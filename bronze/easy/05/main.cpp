/*
USACO Bronze 2017: Promotion Counting (Easy)
http://www.usaco.org/index.php?page=viewproblem2&cpid=591
*/

#include <cstdio>
#include <iostream>


int main() {
	// For USACO contests before 2020
	std::freopen("promote.in", "r", stdin);
	std::freopen("promote.out", "w", stdout);

	int bronze_before, bronze_after, 
		silver_before, silver_after, 
		gold_before, gold_after, 
		plat_before, plat_after;
		
	std::cin >> bronze_before >> bronze_after
			 >> silver_before >> silver_after
			 >> gold_before >> gold_after
			 >> plat_before >> plat_after;
	
	std::cout << (silver_after + gold_after + plat_after) - (silver_before + gold_before + plat_before) << std::endl;
	std::cout << (gold_after + plat_after) - (gold_before + plat_before) << std::endl;
	std::cout << (plat_after) - (plat_before) << std::endl;

	return 0;
}
