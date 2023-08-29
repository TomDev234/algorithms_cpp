//
//  test_omp.cpp
//  algorithms_cpp
//
//  Created by Tom on 16.08.23.
//

#include "test_omp.hpp"

#include <iostream>
#include <omp.h>

using namespace std;

int test_omp() {
  int result = 0;
  cout << "Number of Threads=" << omp_get_max_threads() << endl;
  #pragma omp parallel
  {
    #pragma omp critical
    {
      cout << "Hello from process " << omp_get_thread_num() << endl;
    }
  }
  int total_sum = 0;
  #pragma omp parallel
  {
    int partial_sum = 0;
    #pragma omp for
    for(int i = 1; i <= 10000; i++) {
      partial_sum += i;
    }
    #pragma omp critical
    {
      total_sum += partial_sum;
    }
  }
  if(total_sum != 50005000)
    result = 1;
  cout << "Total Sum=" << total_sum << endl << endl;
  return result;
}
