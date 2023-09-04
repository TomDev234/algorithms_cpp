//
//  test_factorial.cpp
//  algorithms_tests
//
//  Created by Tom on 04.09.23.
//

#include "test_factorial.hpp"
#include "factorial.hpp"
#include <iostream>

using namespace std;

int test_factorial() {
  cout << "Factorial Test\n";
  cout << "--------------\n";
  
  int result = 0;
  const short n = 20;
  const int count = 1000000;
  long number = 0;
  
  auto start = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < count; i++)
    number = iterativeFactorial(n);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  cout << "execution time: " << duration.count() << " ms\n";
  cout << "times per second " << count * 1000 / duration.count() << endl;
  cout << "Factorial(" << n << ")=" << number << endl << endl;
  
  if(number != 2432902008176640000) {
    cout << "IterativeFactorial wrong Number Error!\n";
    result = 1;
  }
  
  number = recursiveFactorial(n);
  if(number != 2432902008176640000) {
    cout << "RecursiveFactorial wrong Number Error!\n";
    result = 1;
  }
  
  return result;
}
