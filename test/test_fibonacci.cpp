//
//  test_fibonacci.cpp
//  algorithms_tests
//
//  Created by Tom on 04.09.23.
//

#include "test_fibonacci.hpp"
#include "fibonacci.hpp"
#include <iostream>

using namespace std;

int test_fibonacci() {
  cout << "Fibaonacci Test\n";
  cout << "---------------\n";
  
  int result = 0;
  const short n = 46;
  const int count = 1000000;
  long number = 0;
  
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < count; i++)
    number = iterativeFibonacci(n);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  cout << "execution time: " << duration.count() << " ms\n";
  cout << "times per second " << count * 1000 / duration.count() << endl;
  cout << "Fibaonacci(" << n << ")=" << number << endl << endl;
  
  if(number != 1836311903) {
    cout << "RecursiveFibonacci wrong Number Error!\n";
    result = 1;
  }
  
  number = recursiveFibonacci(n);
  if(number != 1836311903) {
    cout << "Iterativefibonacci wrong Number Error!\n";
    result = 1;
  }
  
  return result;
}
