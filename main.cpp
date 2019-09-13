#include<iostream>
#include <stdlib.h>
#include"fun.h"
//#include "funcdemo.h"

int main(void)
{

	octf ins;

	octf *inptr = &ins;

	ins.name1 = "sqrt";
	ins.name2 = NULL; //Passing "" will not work



	int dim = 1;
	ins.input1 = new double[dim];
	ins.size_input1[2]=dim;

	double val = 5.0;

	for(int i=0; i<dim; i++)
		ins.input1[i]=i+val;
	

	int status_fun = fun(inptr);

	if(status_fun==1)
	{
		std::cout<< "Octave function failed" << std::endl;
		return 1;
	}
	else
	{
		for(int i=0; i<ins.size_output1[1]; i++)
		{
			std::cout<< i+1 <<"\t" << ins.output1[i] << std::endl;
		}

		free(ins.output1);
		free(ins.input1);
	}
	return 0;
}
