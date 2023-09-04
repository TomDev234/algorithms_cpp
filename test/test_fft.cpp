//
//  test_fft.cpp
//  algorithms_tests
//
//  Created by Tom on 04.09.23.
//

#include "test_fft.hpp"
#include "fft.hpp"
#include <iostream>

using namespace std;

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
