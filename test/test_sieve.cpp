//
//  test_sieve.cpp
//  algorithms_tests
//
//  Created by Tom on 04.09.23.
//

#include "test_sieve.hpp"
#include "sieve.hpp"
#include <iostream>

using namespace std;

int test_sieve() {
  cout << "Sieve Test\n";
  cout << "----------\n";
  
  int result = 0;
  const int n = 1000000;
  const int count = 1000;
  vector<int>primes;
  
  cout << "Following are the prime numbers smaller than or equal to " << n << endl;
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < count; i++)
    primes = SieveOfEratosthenes(n);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  cout << "execution time: " << duration.count() << " ms\n";
  cout << "times per second " << count * 1000 / duration.count() << endl;
  cout << "Number of Primes found = " << primes.size() << endl;
  
  if(primes.size() != 78498) {
    cout << "Wrong Number of Primes Error!\n";
    result = 1;
  }
  
  int numberOfPrimes = (int)primes.size();
  if (numberOfPrimes > 50)
    numberOfPrimes = 50;
  for (int i = 0; i < numberOfPrimes; i++)
    cout << primes[i] << " ";
  cout << endl << endl;
  
  return result;
}
