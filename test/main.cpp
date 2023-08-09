//
//  main.cpp
//  tests
//
//  Created by Tom on 02.08.23.
//

#include "algorithms_cpp.hpp"
#include <iostream>
#include <vector>

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
  int numberOfPrimes = (int)primes.size();
  if (numberOfPrimes > 50)
    numberOfPrimes = 50;
  for (int i = 0; i < numberOfPrimes; i++)
    cout << primes[i] << " ";
  cout << endl << endl;
  return result;
}

int test_fibonacci() {
  cout << "Fibaonacci Test\n";
  cout << "---------------\n";
  int result = 0;
  const short n = 46;
  const int count = 1000000;
  long number = 0;
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < count; i++)
    number = fibonacci(n);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  cout << "execution time: " << duration.count() << " ms\n";
  cout << "times per second " << count * 1000 / duration.count() << endl;
  cout << "Fibaonacci(" << n << ")=" << number << endl << endl;
  return result;
}

int test_fft() {
  cout << "FFT Test\n";
  cout << "--------\n";
  int result = 0;
  const Complex test[] = { 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 };
  CArray data(test, 8);
  // forward fft
  fft_divide_conquer(data);
  cout << "fft" << endl;
  for (int i = 0; i < 8; ++i)
    cout << data[i] << endl;
  // inverse fft
  ifft(data);
  cout << endl << "ifft" << endl;
  for (int i = 0; i < 8; ++i)
    cout << data[i] << endl;
  cout << endl;
  return result;
}

int main() {
  int result = 0;
  result += test_sieve();
  result += test_fibonacci();
  result += test_fft();
  return result;
}
