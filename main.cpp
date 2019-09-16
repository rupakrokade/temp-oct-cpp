#include<iostream>
#include <stdlib.h>
#include"fun.h"
//#include "funcdemo.h"

int main(void)
{

	octf ins;

	octf *inptr = &ins;

	ins.name1 = "arch_rnd";
	ins.package = "signal";
	ins.name2 = NULL; //Passing "" will not work

//////////////First Input///////////////////
	int row1 = 1;
	int col1 = 5;
	int i,j,k=0;
	int imat[row1][col1];
	int dim = row1*col1;
std::cout << "--Input matrix1: " << row1 << "X" << col1 << "\n";

/*		
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			imat[i][j]=i+j+5;
			printf("%d ",imat[i][j]);
		}
	printf("\n");
	}
*/


	ins.input1 = new double[dim];
	ins.size_input1[1]=row1;
	ins.size_input1[2]=col1;
/*
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			ins.input1[k]=imat[i][j];
			k++;
		}
	}
*/

	ins.input1[0] = 1;
  ins.input1[1] = 2;
  ins.input1[2] = 3;
  ins.input1[3] = 4;
  ins.input1[4] = 5;



//////////////Second Input///////////////////
	int row2 = 1;
	int col2 = 4;
	//i,j,k=0;
	int imat2[row2][col2];
	int dim2 = row2*col2;
std::cout << "--Input matrix2: " << row2 << "X" << col2 << "\n";

/*		
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			imat[i][j]=i+j+5;
			printf("%d ",imat[i][j]);
		}
	printf("\n");
	}
*/


	ins.input2 = new double[dim2];
	ins.size_input2[1]=row2;
	ins.size_input2[2]=col2;
/*
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			ins.input1[k]=imat[i][j];
			k++;
		}
	}
*/

	ins.input2[0] = 7;
  ins.input2[1] = 8;
  ins.input2[2] = 9;
  ins.input2[3] = 10;
//  ins.input2[4] = 5;

//	for(i=0;i<dim;i++)
//		printf("%d ",ins.input1[i]);

//	printf("\n");

//////////////Second Input///////////////////
	int row3 = 1;
	int col3 = 1;
	//i,j,k=0;
	int imat3[row2][col2];
	int dim3 = row3*col3;
std::cout << "--Input matrix3: " << row3 << "X" << col3 << "\n";

/*		
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			imat[i][j]=i+j+5;
			printf("%d ",imat[i][j]);
		}
	printf("\n");
	}
*/


	ins.input3 = new double[dim3];
	ins.size_input3[1]=row3;
	ins.size_input3[2]=col3;
/*
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			ins.input1[k]=imat[i][j];
			k++;
		}
	}
*/

	ins.input3[0] = 5;
//  ins.input3[1] = 1;
//  ins.input3[2] = 3;
 // ins.input3[3] = 4;
//  ins.input3[4] = 5;

//	for(i=0;i<dim;i++)
//		printf("%d ",ins.input1[i]);

//	printf("\n");
//----------------------------------------

	int status_fun = fun(inptr);

	if(status_fun==1)
	{
		std::cout<< "Octave function failed" << std::endl;
		return 1;
	}
	else
	{
//		for(int i=0; i<ins.size_output1[1]; i++)
//		{
//			std::cout<< i+1 <<"\t" << ins.output1[i] << std::endl;
//		}

	int out_dim = ins.size_output1[1] * ins.size_output1[2];
	k=0;

	std::cout << "--output matrix: " << ins.size_output1[1] << "X" << ins.size_output1[2] << "\n";
	for(i=0;i<ins.size_output1[1];i++)
	{
		for(j=0;j<ins.size_output1[2];j++)
		{
			std::cout << ins.output1[k] << " ";
			k++;
		}
	std::cout << '\n';
	}

std::cout << '\n';

		free(ins.output1);
		free(ins.input1);
		free(ins.input2);
		free(ins.input3);
	}
	return 0;
}
