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

#include <stdio.h>

template <typename T>

void insertionSort(std::vector<T>& array, int left, int right) {
  for (int i = left + 1; i <= right; ++i) {
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

void insertionSort(std::vector<T>& array, int n) {
  for(int i = 0; i < n; i++) {
    int j = i;
    while(j > 0 && array[j] < array[j-1]) {
      swap(array[j],array[j-1]);
      j--;
    }
  }
}

#endif /* insertionsort_hpp */
