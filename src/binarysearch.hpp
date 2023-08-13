//
//  binarysearch.hpp
//  algorithms_cpp
//
//  Created by Tom on 13.08.23.
//

#ifndef binarysearch_hpp
#define binarysearch_hpp

#include <vector>

template <typename T>

int recursiveBinarySearch(std::vector<T>array, int left, int right, T target) {
  if(left == right) {
    if(array[left] == target)
      return left;
    else
      return -1;
  }
  else {
    int middle = (left + right) / 2;
    if(array[middle] < target)
      return recursiveBinarySearch (array, left, middle - 1, target);
    else if(array[middle] > target)
      return recursiveBinarySearch (array, middle + 1, right, target);
    else
      return middle;
  }
}

template <typename T>

int iterativeBinarySearch(std::vector<T>array, T target) {
  int left = 0;
  int right = array.size() - 1;
  while (left <= right) {
    int middle = (left + right) / 2;
    if (array[middle] < target)
      right = middle - 1;
    else if (array[middle] > target)
      left = middle + 1;
    else
      return middle;
  }
  return -1;
}

#endif /* binarysearch_hpp */
