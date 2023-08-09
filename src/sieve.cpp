//
//  sieve.cpp
//  algorithms
//
//  Created by Tom on 31.07.23.
//

#include "sieve.hpp"

// Create a boolean array "prime[0..n]" and initialize all entries it as true. A value in prime[i] will finally be false if i is. Not a prime, else true.

vector<int>SieveOfEratosthenes(int n) {
  vector<bool>isPrime(n + 1, true);
  // calculate Primes
  for (int p = 2; p * p <= n; p++)
    if (isPrime[p])
      for (int i = p * p; i <= n; i += p)
        isPrime[i] = false;
  // create Prime Array
  vector<int>primes;
  for (int i = 2; i < n; i++)
    if (isPrime[i])
      primes.push_back(i);
  return primes;
}
