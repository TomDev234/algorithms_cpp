//
//  fibonacci.cpp
//  algorithms_cpp
//
//  Created by Tom on 05.08.23.
//

#include "fibonacci.hpp"
#include <vector>

long fibonacci(short n) {
  long result;
  if (n == 1 || n == 2)
    result = 1;
  else {
    std::vector<long>a(n+1);
    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i <= n; i++)
      a[i] = a[i-1] + a[i-2];
    result = a[n];
  }
  return result;
}
