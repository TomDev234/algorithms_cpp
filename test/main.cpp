//
//  main.cpp
//  tests
//
//  Created by Tom on 02.08.23.
//

#include "algorithms_cpp.hpp"
#include "test_omp.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <random>
#include <algorithm>

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

template <typename T>

bool isSorted(vector<T>array) {
  // Test whether the array entries are in order.
  for (int i = 1; i < array.size(); i++)
    if (array[i] < array[i-1])
      return false;
    return true;
}

int test_insertionsort() {
  cout << "Insertion Sort\n";
  cout << "--------------\n";
  
  vector<int>originalArray = { 458, 557, 746, 88, 287, 751, 615, 269, 910, 722, 297, 234, 128, 205, 275, 246, 882, 262, 7, 843, 860, 14, 702, 525, 392, 585, 168, 313, 146, 89, 727, 58, 743, 495, 63, 908, 265, 436, 262, 924, 79, 7, 627, 350, 840, 984, 977, 475, 177, 196, 529, 863, 51, 180, 718, 243, 395, 122, 949, 377, 661, 896, 9, 128, 423, 805, 652, 809, 26, 10, 973, 865, 11, 54, 339, 929, 222, 696, 913, 215, 855, 882, 848, 111, 902, 213, 468, 536, 530, 933, 143, 338, 691, 89, 799, 496, 512, 391, 371, 781};

  const int count = 1000000;
  vector<int>array;
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < count; i++) {
    array = originalArray;
    insertionSort(array);
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  cout << "execution time: " << duration.count() << " ms\n";
  cout << "times per second " << count * 1000 / duration.count() << endl;
  
  int result = 0;
  if (!isSorted(array)) {
    cout << "Vector not sorted Error!" << endl;
    result = 1;
  }
  else {
    cout << "The Vector is sorted." << endl;
  }
  cout << endl;
  
  return result;
}

int test_mergesort() {
  cout << "Merge Sort\n";
  cout << "----------\n";
  
  vector<int>originalArray = { 458, 557, 746, 88, 287, 751, 615, 269, 910, 722, 297, 234, 128, 205, 275, 246, 882, 262, 7, 843, 860, 14, 702, 525, 392, 585, 168, 313, 146, 89, 727, 58, 743, 495, 63, 908, 265, 436, 262, 924, 79, 7, 627, 350, 840, 984, 977, 475, 177, 196, 529, 863, 51, 180, 718, 243, 395, 122, 949, 377, 661, 896, 9, 128, 423, 805, 652, 809, 26, 10, 973, 865, 11, 54, 339, 929, 222, 696, 913, 215, 855, 882, 848, 111, 902, 213, 468, 536, 530, 933, 143, 338, 691, 89, 799, 496, 512, 391, 371, 781};
  
  const int count = 1000000;
  vector<int>array;
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < count; i++) {
    array = originalArray;
    iterativeMergeSort(array);
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  cout << "execution time: " << duration.count() << " ms\n";
  cout << "times per second " << count * 1000 / duration.count() << endl;

  int result = 0;
  if (!isSorted(array)) {
    cout << "IterativeMergeSort the Vector is not sorted Error!" << endl;
    result = 1;
  }
  else {
    cout << "IterativeMergeSort the Vector is sorted." << endl;
  }
  
  array = originalArray;
  recursiveMergeSort(array, 0, (int)array.size() - 1);
  
  if (!isSorted(array)) {
    cout << "RecursiveMergeSort the Vector is not sorted Error!" << endl;
    result = 1;
  }
  else {
    cout << "RecursiveMergeSort the Vector is sorted." << endl;
  }

  cout <<endl;
  return result;
}

int test_quicksort() {
  cout << "Quick Sort\n";
  cout << "----------\n";
  
  vector<int>originalArray = { 458, 557, 746, 88, 287, 751, 615, 269, 910, 722, 297, 234, 128, 205, 275, 246, 882, 262, 7, 843, 860, 14, 702, 525, 392, 585, 168, 313, 146, 89, 727, 58, 743, 495, 63, 908, 265, 436, 262, 924, 79, 7, 627, 350, 840, 984, 977, 475, 177, 196, 529, 863, 51, 180, 718, 243, 395, 122, 949, 377, 661, 896, 9, 128, 423, 805, 652, 809, 26, 10, 973, 865, 11, 54, 339, 929, 222, 696, 913, 215, 855, 882, 848, 111, 902, 213, 468, 536, 530, 933, 143, 338, 691, 89, 799, 496, 512, 391, 371, 781};
  
  const int count = 1000000;
  vector<int>array;
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < count; i++) {
    array = originalArray;
    const int n = (int)array.size() - 1;
    iterativeQuickSort(array,0,n);
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  cout << "execution time: " << duration.count() << " ms\n";
  cout << "times per second " << count * 1000 / duration.count() << endl;

  int result = 0;
  if (!isSorted(array)) {
    cout << "IterativeQuickSort the Vector is not sorted Error!" << endl;
    result = 1;
  }
  else {
    cout << "IterativeQuickSort the Vector is sorted." << endl;
  }
  
  array = originalArray;
  recursiveQuickSort(array, 0, (int)array.size() - 1);
  if (!isSorted(array)) {
    cout << "RecursiveQuickSort the Vector is not sorted Error!" << endl;
    result = 1;
  }
  else {
    cout << "RecursiveQuickSort the Vector is sorted." << endl;
  }

  cout <<endl;
  return result;
}

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
