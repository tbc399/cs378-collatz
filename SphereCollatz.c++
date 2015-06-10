// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

using namespace std;

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
pair<int, int> collatz_read (const string& s);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int collatz_eval (int i, int j);

// --------------
// collatz_cyclen
// --------------

/**
 * compute the cycle length of given int
 * @param i an int
 * @return the cycle length of i
 */
int collatz_cyclen (int i);

// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (ostream& w, int i, int j, int v);

// -------------
// collatz_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void collatz_solve (istream& r, ostream& w);

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    int begin = 1;
    int end = 1;
    if (i < j) {
    	begin = i;
    	end = j;
    } else {
    	begin = j;
    	end = i;
    }
    //assert(i <= j);
    int max = 1;
    int len;
    for (int k = begin; k <= end; ++k) {
        len = collatz_cyclen(k);
        if (len > max)
            max = len;
    }
    assert(max > 0);
    return max;
}

// --------------
// collatz_cyclen
// --------------

int collatz_cyclen (int i) {
    assert(i > 0);
    int len = 1;
    while (i != 1) {
        ++len;
        if (i % 2 == 0) { // i is even
            i /= 2;
        } else {
            i = (i * 3) + 1;
        }
        assert(i > 0);
    }
    return len;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}

// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;
}