/*
USACO Bronze 2019: Where Am I? (Easy)
https://www.usaco.org/index.php?page=viewproblem2&cpid=964
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>


int calculate_uniqueness(int &length, std::string &mailboxes) {
    
    for (int i = 0; i < length; i++) {
        int total_strings = length - i;
        
        std::set<std::string> current_strings;
        for (auto it = mailboxes.begin(); it < mailboxes.begin() + total_strings;
                 it++) {
            
            std::string current_string = "";
            for (auto pos = it; pos <= it + i; pos++) {
                current_string += *pos;
            }
            
            current_strings.insert(current_string);
        }
        
        if (current_strings.size() == total_strings) {
            return i + 1;
        }
    }
    
    return -1;
}


int main() {
    std::ifstream fin("whereami.in");
    std::ofstream fout("whereami.out");
    
    int length;
    fin >> length;
    
    std::string mailboxes;
    fin >> mailboxes;
    
    int answer = 0;
    answer = calculate_uniqueness(length, mailboxes);
    
    fout << answer << "\n";
    return 0;
}
