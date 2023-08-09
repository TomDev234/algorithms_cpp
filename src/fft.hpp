//
//  fft.hpp
//  algorithms
//
//  Created by Tom on 31.07.23.
//

#ifndef fft_hpp
#define fft_hpp

#include <complex>
#include <valarray>
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
void fft_divide_conquer(CArray& x);
void fft_breadth_first(CArray &x);
void ifft(CArray& x);

#endif /* fft_hpp */
