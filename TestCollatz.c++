// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

TEST(CollatzFixture, read_1) {
    string s("1 10\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ( 1, p.first);
    ASSERT_EQ(10, p.second);
}
    
TEST(CollatzFixture, read_2) {
    string s("1 1\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ(1, p.first);
    ASSERT_EQ(1, p.second);
}

TEST(CollatzFixture, read_3) {
    string s("-3 10\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ(-3, p.first);
    ASSERT_EQ(10, p.second);
}

TEST(CollatzFixture, read_4) {
    string s("4 -9\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ( 4, p.first);
    ASSERT_EQ(-9, p.second);
}

#ifndef CACHE
// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

#else
// -----------
// eval_cached
// -----------

TEST(CollatzFixture, eval_cached_1) {
    vector<int> cache;
    const int v = collatz_eval_cached(1, 10, cache);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_cached_2) {
    vector<int> cache;
    const int v = collatz_eval_cached(100, 200, cache);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_cached_3) {
    vector<int> cache;
    const int v = collatz_eval_cached(201, 210, cache);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_cached_4) {
    vector<int> cache;
    const int v = collatz_eval_cached(900, 1000, cache);
    ASSERT_EQ(174, v);}
#endif

// ------
// cyclen
// ------

TEST (CollatzFixture, cyclen_1) {
    const int i = collatz_cyclen(1);
    ASSERT_EQ(1, i);
}

TEST (CollatzFixture, cyclen_2) {
    const int i = collatz_cyclen(5);
    ASSERT_EQ(6, i);
}

TEST (CollatzFixture, cyclen_3) {
    const int i = collatz_cyclen(10);
    ASSERT_EQ(7, i);
}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 1, 1, 1);
    ASSERT_EQ("1 1 1\n", w.str());
}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, -1, 10, -5);
    ASSERT_EQ("-1 10 -5\n", w.str());
}

TEST(CollatzFixture, print_4) {
    ostringstream w;
    collatz_print(w, 7, -5, 0);
    ASSERT_EQ("7 -5 0\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

TEST(CollatzFixture, solve_2) {
    istringstream r("5 5\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("5 5 6\n", w.str());
}

/*
% ls -al /usr/include/gtest/
...
gtest.h
...



% locate libgtest.a
/usr/lib/libgtest.a
...



% locate libpthread.a
...
/usr/lib32/libpthread.a



% locate libgtest_main.a
/usr/lib/libgtest_main.a
...



% g++-4.8 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -lpthread



% valgrind TestCollatz        >  TestCollatz.out 2>&1
% gcov-4.8 -b Collatz.c++     >> TestCollatz.out
% gcov-4.8 -b TestCollatz.c++ >> TestCollatz.out



% cat TestCollatz.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestCollatz
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Collatz
[ RUN      ] Collatz.read
[       OK ] Collatz.read (31 ms)
[ RUN      ] Collatz.eval_1
[       OK ] Collatz.eval_1 (5 ms)
[ RUN      ] Collatz.eval_2
[       OK ] Collatz.eval_2 (3 ms)
[ RUN      ] Collatz.eval_3
[       OK ] Collatz.eval_3 (3 ms)
[ RUN      ] Collatz.eval_4
[       OK ] Collatz.eval_4 (3 ms)
[ RUN      ] Collatz.print
[       OK ] Collatz.print (17 ms)
[ RUN      ] Collatz.solve
[       OK ] Collatz.solve (10 ms)
[----------] 7 tests from Collatz (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Collatz.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Collatz.c++.gcov'
...
File 'TestCollatz.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestCollatz.c++.gcov'
...
*/
