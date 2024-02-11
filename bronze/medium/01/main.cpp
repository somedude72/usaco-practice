/*
USACO Bronze 2018: Blocked Billboard II (Normal)
https://www.usaco.org/index.php?page=viewproblem2&cpid=783
*/

#include <fstream>
#include <iostream>

using namespace std;


struct Rectangle {

    int x1, y1, x2, y2;
    int area() {
        return (x2 - x1) * (y2 - y1);
    }
};


int calculate_overlap(Rectangle a, Rectangle b) {

    if (a.x1 < b.x1 && b.x1 < a.x2 && b.y2 > a.y2 && b.y1 < a.y1) {
        return (b.x1 - a.x1) * (a.y2 - a.y1);
    }

    if (b.x1 < a.x1 && a.x1 < b.x2 && b.y2 > a.y2 && b.y1 < a.y1) {
        return (a.x2 - b.x2) * (a.y2 - a.y1);
    }

    if (b.y1 < a.y2 < b.y2) {
        return (a.x2 - a.x1) * (b.y1 - a.y1);
    }

    { return (a.x2 - a.x1) * (a.y2 - b.y2); }
}


bool is_corner_covered(int x, int y, Rectangle a) {

    if (a.x1 <= x && x <= a.x2 && a.y1 <= y && y <= a.y2) {
        return true;
    }

    return false;
}


int main() {
    // For USACO contests before 2020
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");

    Rectangle lawnmower, cow_feed;
    fin >> lawnmower.x1 >> lawnmower.y1 >> lawnmower.x2 >> lawnmower.y2;
    fin >> cow_feed.x1 >> cow_feed.y1 >> cow_feed.x2 >> cow_feed.y2;

    int covered_corners = 0;
    if (is_corner_covered(lawnmower.x1, lawnmower.y1, cow_feed)) {
        covered_corners++;
    }
    if (is_corner_covered(lawnmower.x1, lawnmower.y2, cow_feed)) {
        covered_corners++;
    }
    if (is_corner_covered(lawnmower.x2, lawnmower.y2, cow_feed)) {
        covered_corners++;
    }
    if (is_corner_covered(lawnmower.x2, lawnmower.y1, cow_feed)) {
        covered_corners++;
    }

    if (covered_corners == 4) {
        fout << 0 << "\n";
    } else if (covered_corners == 2) {
        fout << calculate_overlap(lawnmower, cow_feed) << "\n";
    } else {
        fout << lawnmower.area() << "\n";
    }

    return 0;
}
