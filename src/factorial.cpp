//
//  factorial.cpp
//  algorithms_cpp
//
//  Created by Tom on 13.08.23.
//

#include "factorial.hpp"

long recursiveFactorial(long n) {
  long result;
  if(n == 0)
    result = 1;
  else
    result = n * recursiveFactorial(n - 1);
  return result;
}

long iterativeFactorial(long n) {
  long result = 1;
  for(long i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}
