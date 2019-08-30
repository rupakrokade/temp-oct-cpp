#include<iostream>
#include"fun.h"
//#include "funcdemo.h"

int main(void)
{
  double* n;
	double* val;// = 5.0;
	val[0]=5.0;
	n = &val;
	double ar[(int)val];
	//n[0]=3.0;

	fun(ar, n, "hamming");
//	for(int i=0; i<ar.length(); i++)
		std::cout << ar[1] << std::endl;
	return 0;
}
