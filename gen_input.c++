/**
 * used to generate acceptable input to collatz
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int cycle_length (int i) {
    int len = 1;
    while (i != 1) {
        if (len++ == INT_MAX)
            return 0;
        if (i % 2 == 0) { // i is even
            i /= 2;
        } else {
            i = i * 3 + 1;
        }
    }
    return len;
}

int main () {
    cout << INT_MAX <<"\n";
    vector<int> to_exclude;
    int n;
    for (int i = 1; i <= 1000000; ++i) {
        if (!(n = cycle_length(i))) {
            cout << "excluding " << i << "\n";
            to_exclude.push_back(i);
        }
    }
    return 0;
}