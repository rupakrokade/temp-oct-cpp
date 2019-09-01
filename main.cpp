#include<iostream>
#include"fun.h"
//#include "funcdemo.h"

int main(void)
{
/*
  double* n;
	double val = 5.0;
	//val[0]=5.0;
	n = &val;
	double ar[(int)val];
	//n[0]=3.0;
*/

	int dim = 5;
	double val = 15.0;
	double in[dim];
	for(int i=0; i<dim; i++)
		in[i]=i+val;
	
	double ar[(int)val];
	

	fun(ar, in, dim, "sqrt","");
	for(int i=0; i<dim; i++)
		std::cout << ar[i] << std::endl;
	return 0;
}
