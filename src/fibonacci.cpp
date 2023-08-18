//
//  fibonacci.cpp
//  algorithms_cpp
//
//  Created by Tom on 05.08.23.
//

#include "fibonacci.hpp"
#include <vector>

using namespace std;

long recursiveFibonacci(short n) {
  long result;
  if(n == 1 || n == 2)
    result = 1;
  else
    result = recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
  return result;
}

long memoizedFibonacciWorker(short n, vector<long>&m) {
  long result;
  if(m[n] != 0)
    result = m[n];
  else if(n == 1 || n == 2)
    result = 1;
  else {
    result = memoizedFibonacciWorker(n - 1, m) + memoizedFibonacciWorker(n - 2, m);
    m[n] = result;
  }
  return result;
}

long memoizedFibonacci(short n) {
  vector<long>m(n + 1, 0);
  long result = memoizedFibonacciWorker(n, m);
  return result;
}

long iterativeFibonacci(short n) {
  long result;
  if(n == 1 || n == 2)
    result = 1;
  else {
    vector<long>a(n+1);
    a[1] = 1;
    a[2] = 1;
    for(int i = 3; i <= n; i++)
      a[i] = a[i-1] + a[i-2];
    result = a[n];
  }
  return result;
}
