/**
 * @file functions.h
 * @author Austin Smith aust4513@vandals.uidaho.edu
 * @brief 
 * @version 0.1
 * @date 2023-09-08
 * 
 */


#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <array>
#include <iterator>
#include <string>
#include <time.h>
#include <fstream>
#include <random>
#include <sstream>
using namespace std;

struct Combination {
  vector<int> xcoords;
  vector<int> ycoords;
  double slope;
  double intercept;
};

long long unsigned int factorial(long long unsigned int n);
void generatecombo(vector<Combination> &combo, vector<int> xpoints, vector<int> ypoints, long long unsigned int size, int N);
void removeduplicates(vector<int> &xcoords, vector<int> &ycoords);
void combine(vector<Combination> &combo);
double slopecalc(vector<int> xcoords, vector<int> ycoords, int N);
double interceptcalc(vector<int> xcoords, vector<int> ycoords, double slope, int N);
void printvector(vector<int> xcoords, vector<int> ycoords);
string article(int a);
int generaterandom(int range);

#endif