//
//  main.cpp
//  tests
//
//  Created by Tom on 02.08.23.
//

#include "test_sieve.hpp"
#include "test_fibonacci.hpp"
#include "test_factorial.hpp"
#include "test_fft.hpp"
#include "test_insertionsort.hpp"
#include "test_mergesort.hpp"
#include "test_quicksort.hpp"
#include "test_omp.hpp"
#include <iostream>

using namespace std;

int main() {
  int result = 0;
  result += test_sieve();
  result += test_fibonacci();
  result += test_factorial();
  result += test_fft();
  result += test_insertionsort();
  result += test_mergesort();
  result += test_quicksort();
  result += test_omp();
  cout << "Failed Tests " << result << endl;
  return result;
}
