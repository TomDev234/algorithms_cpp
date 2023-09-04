//
//  mergesort.hpp
//  algorithms_cpp
//
//  Created by Tom on 11.08.23.
//
// Pros: ?
// Cons: needs extra Memory

#ifndef mergesort_hpp
#define mergesort_hpp

// Optimizing Merge Sort:
// stop partitioning subarrays when size S is reached, where S is the number of data items fitting into the CPU's Cache of 32 kB or Cache Line of 64 Bytes Size.
// Each of these subarrays are sorted with an in-place sorting algorithm such as insertion sort, to discourage memory swaps, and normal merge sort is then
// completed in the standard recursive fashion.
// Merge sort parallelizes well due to use of the divide-and-conquer method.
// Merging of the Arrays can be optimized by Parallel For Loops.

#include "insertionsort.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
//#include <omp.h>

// Merge two subarrays of arr[].
// First subarray is arr[left..mid].
// Second subarray is arr[mid+1..right].

#define CacheLineSize 64

template <typename T>

void merge(std::vector<T>& array, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  
  // Create temporary arrays
  std::vector<int> leftArray(n1);
  std::vector<int> rightArray(n2);
  
  // Copy data to temporary arrays leftArray[] and rightArray[]
  for (int i = 0; i < n1; i++) {
    leftArray[i] = array[left + i];
  }
  for (int i = 0; i < n2; i++) {
    rightArray[i] = array[mid + 1 + i];
  }
  
  // Merge the temporary arrays back into array[left..right]
  int i = 0; // Initial index of first subarray
  int j = 0; // Initial index of second subarray
  int k = left; // Initial index of merged subarray
  
  while (i < n1 && j < n2) {
    if (leftArray[i] <= rightArray[j]) {
      array[k] = leftArray[i];
      i++;
    }
    else {
      array[k] = rightArray[j];
      j++;
    }
    k++;
  }
  
  // Copy the remaining elements of leftArr[], if any
  while (i < n1) {
    array[k] = leftArray[i];
    i++;
    k++;
  }
  
  // Copy the remaining elements of rightArr[], if any
  while (j < n2) {
    array[k] = rightArray[j];
    j++;
    k++;
  }
}

template <typename T>

void recursiveMergeSort(std::vector<T>& array, int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2;
    
    // Sort first and second halves
    
    if (middle - left < CacheLineSize / sizeof(T))
      insertionSort(array, left, middle);
    else
      recursiveMergeSort(array, left, middle);
    
    if (right - middle < CacheLineSize / sizeof(T))
      insertionSort(array, left, right);
    else
      recursiveMergeSort(array, middle + 1, right);
    
    // Merge the sorted halves
    merge(array, left, middle, right);
  }
}

template <typename T>

void iterativeMergeSort(std::vector<T>&array) {
  int n = (int)array.size();
  for (int currentSize = 1; currentSize <= n - 1; currentSize = 2 * currentSize) {
    for (int left = 0; left < n - 1; left += 2 * currentSize) {
      int mid = std::min(left + currentSize - 1, n - 1);
      int right = std::min(left + 2 * currentSize - 1, n - 1);
      if (right - left + 1 < CacheLineSize / sizeof(T)) {
        insertionSort(array, left, right);
      }
      else {
        merge(array, left, mid, right);
      }
    }
  }
}

#endif /* mergesort_hpp */
