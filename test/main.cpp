//
//  main.cpp
//  tests
//
//  Created by Tom on 02.08.23.
//

#include "algorithms_cpp.hpp"
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

int test_insertionsort() {
  cout << "Insertion Sort\n";
  cout << "--------------\n";
  
  vector<int>originalArray = { 458, 557, 746, 88, 287, 751, 615, 269, 910, 722, 297, 234, 128, 205, 275, 246, 882, 262, 7, 843, 860, 14, 702, 525, 392, 585, 168, 313, 146, 89, 727, 58, 743, 495, 63, 908, 265, 436, 262, 924, 79, 7, 627, 350, 840, 984, 977, 475, 177, 196, 529, 863, 51, 180, 718, 243, 395, 122, 949, 377, 661, 896, 9, 128, 423, 805, 652, 809, 26, 10, 973, 865, 11, 54, 339, 929, 222, 696, 913, 215, 855, 882, 848, 111, 902, 213, 468, 536, 530, 933, 143, 338, 691, 89, 799, 496, 512, 391, 371, 781};
  
  vector<int>sortedArray = { 7, 7, 9, 10, 11, 14, 26, 51, 54, 58, 63, 79, 88, 89, 89, 111, 122, 128, 128, 143, 146, 168, 177, 180, 196, 205, 213, 215, 222, 234, 243, 246, 262, 262, 265, 269, 275, 287, 297, 313, 338, 339, 350, 371, 377, 391, 392, 395, 423, 436, 458, 468, 475, 495, 496, 512, 525, 529, 530, 536, 557, 585, 615, 627, 652, 661, 691, 696, 702, 718, 722, 727, 743, 746, 751, 781, 799, 805, 809, 840, 843, 848, 855, 860, 863, 865, 882, 882, 896, 902, 908, 910, 913, 924, 929, 933, 949, 973, 977, 984};

  const int count = 1000000;
  vector<int>array;
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < count; i++) {
    array = originalArray;
    const int n = (int)array.size();
    insertionSort(array, n);
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  cout << "execution time: " << duration.count() << " ms\n";
  cout << "times per second " << count * 1000 / duration.count() << endl;

  int result = 0;
  if (array != sortedArray) {
    cout << "The vectors are not equal Error!" << endl;
    result = 1;
  }
  else {
    cout << "The vectors are equal." << endl;
  }
  cout << endl;
  
  return result;
}

int test_mergesort() {
  cout << "Merge Sort\n";
  cout << "----------\n";
  
  vector<int>originalArray = { 458, 557, 746, 88, 287, 751, 615, 269, 910, 722, 297, 234, 128, 205, 275, 246, 882, 262, 7, 843, 860, 14, 702, 525, 392, 585, 168, 313, 146, 89, 727, 58, 743, 495, 63, 908, 265, 436, 262, 924, 79, 7, 627, 350, 840, 984, 977, 475, 177, 196, 529, 863, 51, 180, 718, 243, 395, 122, 949, 377, 661, 896, 9, 128, 423, 805, 652, 809, 26, 10, 973, 865, 11, 54, 339, 929, 222, 696, 913, 215, 855, 882, 848, 111, 902, 213, 468, 536, 530, 933, 143, 338, 691, 89, 799, 496, 512, 391, 371, 781};
  
  vector<int>sortedArray = { 7, 7, 9, 10, 11, 14, 26, 51, 54, 58, 63, 79, 88, 89, 89, 111, 122, 128, 128, 143, 146, 168, 177, 180, 196, 205, 213, 215, 222, 234, 243, 246, 262, 262, 265, 269, 275, 287, 297, 313, 338, 339, 350, 371, 377, 391, 392, 395, 423, 436, 458, 468, 475, 495, 496, 512, 525, 529, 530, 536, 557, 585, 615, 627, 652, 661, 691, 696, 702, 718, 722, 727, 743, 746, 751, 781, 799, 805, 809, 840, 843, 848, 855, 860, 863, 865, 882, 882, 896, 902, 908, 910, 913, 924, 929, 933, 949, 973, 977, 984};
  
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
  if (array != sortedArray) {
    cout << "IterativeMergeSort the vectors are not equal Error!" << endl;
    result = 1;
  }
  else {
    cout << "IterativeMergeSort the vectors are equal." << endl;
  }
  
  array = originalArray;
  recursiveMergeSort(array, 0, (int)array.size() - 1);
  
  if (array != sortedArray) {
    cout << "RecursiveMergeSort the vectors are not equal Error!" << endl;
    result = 1;
  }
  else {
    cout << "RecursiveMergeSort the vectors are equal." << endl;
  }

  cout <<endl;
  return result;
}

int test_quicksort() {
  cout << "Quick Sort\n";
  cout << "----------\n";
  
  vector<int>originalArray = { 458, 557, 746, 88, 287, 751, 615, 269, 910, 722, 297, 234, 128, 205, 275, 246, 882, 262, 7, 843, 860, 14, 702, 525, 392, 585, 168, 313, 146, 89, 727, 58, 743, 495, 63, 908, 265, 436, 262, 924, 79, 7, 627, 350, 840, 984, 977, 475, 177, 196, 529, 863, 51, 180, 718, 243, 395, 122, 949, 377, 661, 896, 9, 128, 423, 805, 652, 809, 26, 10, 973, 865, 11, 54, 339, 929, 222, 696, 913, 215, 855, 882, 848, 111, 902, 213, 468, 536, 530, 933, 143, 338, 691, 89, 799, 496, 512, 391, 371, 781};
  
  vector<int>sortedArray = { 7, 7, 9, 10, 11, 14, 26, 51, 54, 58, 63, 79, 88, 89, 89, 111, 122, 128, 128, 143, 146, 168, 177, 180, 196, 205, 213, 215, 222, 234, 243, 246, 262, 262, 265, 269, 275, 287, 297, 313, 338, 339, 350, 371, 377, 391, 392, 395, 423, 436, 458, 468, 475, 495, 496, 512, 525, 529, 530, 536, 557, 585, 615, 627, 652, 661, 691, 696, 702, 718, 722, 727, 743, 746, 751, 781, 799, 805, 809, 840, 843, 848, 855, 860, 863, 865, 882, 882, 896, 902, 908, 910, 913, 924, 929, 933, 949, 973, 977, 984};
  
  const int count = 1000000;
  vector<int>array;
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < count; i++) {
    array = originalArray;
    const int n = (int)array.size();
    iterativeQuickSort(array,0,n-1);
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  cout << "execution time: " << duration.count() << " ms\n";
  cout << "times per second " << count * 1000 / duration.count() << endl;

  int result = 0;
  if (array != sortedArray) {
    cout << "IterativeQuickSort the vectors are not equal Error!" << endl;
    result = 1;
  }
  else {
    cout << "IterativeQuickSort the vectors are equal." << endl;
  }
  
  array = originalArray;
  recursiveQuickSort(array, 0, (int)array.size() - 1);
  if (array != sortedArray) {
    cout << "RecursiveQuickSort the vectors are not equal Error!" << endl;
    result = 1;
  }
  else {
    cout << "RecursiveQuickSort the vectors are equal." << endl;
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
  cout << "Failed Tests " << result << endl;
  return result;
}
