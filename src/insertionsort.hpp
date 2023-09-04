//
//  insertionsort.hpp
//  algorithms_cpp
//
//  Created by Tom on 11.08.23.
//
// Pros: very fast for small Arrays, In Place, no extra Memory needed
// Cons: slow for bigger Arrays

#ifndef insertionsort_hpp
#define insertionsort_hpp

#include <vector>

template <typename T>

void insertionSort(std::vector<T>& array, int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    T key = array[i];
    int j = i - 1;
    while (j >= left && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}

template <typename T>

void insertionSort(std::vector<T>&array) {
  int n = (int)array.size();
  for (int i = 1; i < n; i++) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}

template <typename T>

void insertionSortAlgs4(std::vector<T>&a) {
  // Sort a[] into increasing order.
  int n = (int)a.size();
  for (int i = 1; i < n; i++) {
    // Insert a[i] among a[i-1], a[i-2], a[i-3]... ..
    for (int j = i; j > 0 && a[j] < a[j-1]; j--)
      std::swap(a[j], a[j-1]);
  }
}

#endif /* insertionsort_hpp */
