// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair
#include <vector>   // vector

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

#ifdef CACHE
// -------------------
// collatz_eval_cached
// -------------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param cache a vector with value as the cycle length of
 * it's index
 * @return the max cycle length of the range [i, j]
 */
int collatz_eval_cached (int i, int j, vector<int>& cache);
#endif

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

#endif // Collatz_h
