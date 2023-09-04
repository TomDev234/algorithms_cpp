//
//  is_sorted.hpp
//  algorithms_tests
//
//  Created by Tom on 04.09.23.
//

#ifndef is_sorted_hpp
#define is_sorted_hpp

#include <vector>

template <typename T>

bool isSorted(std::vector<T>array) {
  bool result = true;
  // Test whether the array entries are in order.
  for (int i = 1; i < array.size(); i++)
    if (array[i] < array[i-1]) {
      result = false;
      break;
    }
  return result;
}

#endif /* is_sorted_hpp */
