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
#include <vector>   // vector

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

#ifndef CACHE
// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
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
        len = collatz_cyclen(k);
        if (len > max)
            max = len;
    }
    assert(max > 0);
    return max;
}

#else
// -------------------
// collatz_eval_cached
// -------------------

int collatz_eval_cached (int i, int j, vector<int>& cache) {
    assert(i > 0);
    assert(j > 0);
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
        if (k < (int)(cache.size()) && cache[k]) {
            len = cache[k];
        } else if (k < (int)(cache.size()) && cache[k] == 0) {
            cache[k] = len = collatz_cyclen(k);
        } else {
            cache.resize(k+1);
            cache[k] = len = collatz_cyclen(k);
        }
        if (len > max)
            max = len;
    }
    assert(max > 0);
    return max;
}
#endif

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
    #ifdef CACHE
    vector<int> cache;
    #endif
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        int v;
        #ifdef CACHE
        v = collatz_eval_cached(i, j, cache);
        #else
        v = collatz_eval(i, j);
        #endif
        collatz_print(w, i, j, v);}}
