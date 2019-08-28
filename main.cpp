#include<iostream>
#include"fun.h"
//#include "funcdemo.h"

int main(void)
{
  int n=5;
	double ar[n];

	fun(ar, n, "hamming");
	std::cout << ar[1] << std::endl;
	return 0;
}
