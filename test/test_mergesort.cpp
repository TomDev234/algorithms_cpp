//
//  test_mergesort.cpp
//  algorithms_tests
//
//  Created by Tom on 04.09.23.
//

#include "test_mergesort.hpp"
#include "mergesort.hpp"
#include "is_sorted.hpp"
#include <iostream>

using namespace std;

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
