//
//  quicksort.hpp
//  algorithms_cpp
//
//  Created by Tom on 12.08.23.
//
// Pros: very fast, no extra Memory needed
// Cons: bad worst Case, use Randomization to mitigate that

#ifndef quicksort_hpp
#define quicksort_hpp

#include "insertionsort.hpp"
#include <iostream>
#include <vector>
#include <stack>

#define CacheLineSize 64

template <typename T>

int partition1(std::vector<T>array, int low, int high) {
  // Partition into a[lo..i-1], a[i], a[i+1..hi].
  int i = low, j = high + 1; // left and right scan indices
  T pivot = array[low]; // partitioning item
  while (true) {
    // Scan right, scan left, check for scan complete, and exchange.
    while (array[++i] < pivot)
      if (i == high)
        break;
    while (pivot < array[--j])
      if (j == low)
        break;
    if (i >= j)
      break;
    swap(array[i], array[j]);
  }
  swap(array[low], array[j]);
  return j;
}

template <typename T>

int partition2(std::vector<T>& array, int low, int high) {
  int pivot = array[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (array[j] < pivot) {
      i++;
      std::swap(array[i], array[j]);
    }
  }
  std::swap(array[i + 1], array[high]);
  return (i + 1);
}

template <typename T>

int randomPartition(std::vector<T>& array, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    std::swap(array[randomIndex], array[high]);
    return partition2(array, low, high);
}

// chosing the Median of 3 random Elements

// 3 Way Quicksort, dealing with Duplicates

template <typename T>

void recursiveQuickSort(std::vector<T>& array, int low, int high) {
  if (low < high) {
    int pivot = randomPartition(array, low, high);
    
    if (pivot - low < CacheLineSize / sizeof(T))
    insertionSort(array, low, pivot - 1);
    else
      recursiveQuickSort(array, low, pivot - 1);
    
    if (high - pivot < CacheLineSize / sizeof(T))
      insertionSort(array, pivot + 1, high);
    else
      recursiveQuickSort(array, pivot + 1, high);
  }
}

template <typename T>

void iterativeQuickSort(std::vector<T>& array, int low, int high) {
  std::stack<int> stack;
  stack.push(low);
  stack.push(high);

  while (!stack.empty()) {
    high = stack.top();
    stack.pop();
    low = stack.top();
    stack.pop();

    if (high - low < CacheLineSize / sizeof(T)) {
      insertionSort(array, low, high);
      continue;
    }

    int pivotIndex = randomPartition(array, low, high);

    if (pivotIndex - 1 > low) {
      stack.push(low);
      stack.push(pivotIndex - 1);
    }

    if (pivotIndex + 1 < high) {
      stack.push(pivotIndex + 1);
      stack.push(high);
    }
  }
}

#endif /* quicksort_hpp */
