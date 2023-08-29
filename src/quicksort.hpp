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

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <typename T>

int partition(vector<T>& array, int low, int high) {
  int pivot = array[high];
  int i = low;
  for (int j = low; j <= high - 1; j++) {
    if (array[j] < pivot) {
      swap(array[i], array[j]);
      i++;
    }
  }
  swap(array[i], array[high]);
  return (i);
}

template <typename T>

int randomPartition(vector<T>& array, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(array[randomIndex], array[high]);
    return partition(array, low, high);
}

template <typename T>

void recursiveQuickSort(vector<T>& array, int low, int high) {
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

void iterativeQuickSort(vector<T>& array, int low, int high) {
  stack<int> stack;
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
