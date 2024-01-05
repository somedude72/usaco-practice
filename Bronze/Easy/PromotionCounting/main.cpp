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

	int bronzeBefore, bronzeAfter, 
		silverBefore, silverAfter, 
		goldBefore, goldAfter, 
		platBefore, platAfter;
		
	std::cin >> bronzeBefore >> bronzeAfter
			 >> silverBefore >> silverAfter
			 >> goldBefore >> goldAfter
			 >> platBefore >> platAfter;
	
	std::cout << (silverAfter + goldAfter + platAfter) - (silverBefore + goldBefore + platBefore) << std::endl;
	std::cout << (goldAfter + platAfter) - (goldBefore + platBefore) << std::endl;
	std::cout << (platAfter) - (platBefore) << std::endl;

	return 0;
}
