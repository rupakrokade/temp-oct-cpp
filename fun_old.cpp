// file main.cc
// compile and link with mkoctfile --link-stand-alone main.cc -o bentest
#include <iostream>
#include <octave/oct.h>
#include <octave/builtin-defun-decls.h>

int fun ()
{
  Matrix a = Matrix (1,4);
  for (int k = 0; k < a.columns (); ++k)
    a(0, k) = k % 2;

  std::cout << "in:" << a << std::endl;

  octave_value_list in;
  in(0) = a;

  octave_value_list out = Ffft (in, 1);
  ComplexMatrix o = out(0).complex_matrix_value ();
  std::cout << "out:" << o << std::endl;

  return 0;
}
