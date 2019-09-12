#include<iostream>
#include <stdlib.h>
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
	
	octf ins;

	octf *inptr = &ins;

	ins.name1 = "hamming";
	ins.name2 = "symmetric";



	int dim = 1;
	ins.input1 = new double[dim];
	ins.size_input1[2]=dim;

	double val = 5.0;
	//double in[dim];
	for(int i=0; i<dim; i++)
		ins.input1[i]=i+val;
	
	//double ar[(int)val];


	//ins.arr = new double[5];
	//ins.arr = (double*)malloc(sizeof(double)*5);
	fun(inptr);
	
	//int out_len = 5;//ins.output1[0];

	//fun(ar, in, dim, "sqrt","");
	for(int i=0; i<ins.size_output1[1]; i++)
{
		std::cout<< i <<"\t" << ins.output1[i] << std::endl;
}
	free(ins.output1);
	free(ins.input1);
	return 0;
}
