// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

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
    assert(i <= j);
    int max = 1;
    int len;
    for (int k = i; k <= j; ++k) {
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
            i = i * 3 + 1;
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
