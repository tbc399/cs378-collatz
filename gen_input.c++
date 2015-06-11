/**
 * used to generate acceptable input to collatz
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <cstdlib>

using namespace std;

int cycle_length (long i) {
    int len = 1;
    while (i != 1) {
        if (len++ == INT_MAX) {
            //cout << "length: " << len << "\n";
            return 0;
        }
        if (i >= INT_MAX) {
            //cout << "i: " << i << "\n";
            return 0;
        }
        if (i % 2 == 0) { // i is even
            i /= 2;
        } else {
            i = i * 3 + 1;
        }
    }
    return len;
}

bool scan_range (int i, int j) {
    int begin = 1;
    int end = 1;
    if (i < j) {
    	begin = i;
    	end = j;
    } else {
    	begin = j;
    	end = i;
    }
    int max = 1;
    int len;
    for (int k = begin; k <= end; ++k) {
        len = cycle_length(k);
        if (!len)
            return false;
        if (len > max)
            max = len;
    }
    return true;
}

pair<int, int> gen_pair () {
    int p1 = rand() % 1000000 + 1;
    int p2 = rand() % 1000000 + 1;
    return make_pair(p1, p2 );
}

int main () {
    //cout << INT_MAX <<"\n";
    int count = 1000;
    while (count > 0) {
        pair<int, int> p = gen_pair();
        if (count == 25)
            cout << "56 56\n";
        else if (count == 50)
            cout << "1 1\n";
        else if (count == 75)
            cout << "1 2\n";
        else if (scan_range(p.first, p.second))
            cout << p.first << " " << p.second << "\n";
        else
            continue;
        --count;
    }
    return 0;
}