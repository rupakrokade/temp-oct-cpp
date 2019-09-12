
#include <iostream>
#include <stdlib.h>
#include <octave/oct.h>
#include <octave/octave.h>
#include <octave/parse.h>
#include <octave/interpreter.h>
#include <math.h>
#include <string>
#include "fun.h"

extern "C"
{

int fun (octf *inp)
{
  //double answ;
// Create interpreter.
	
	static octave::interpreter interpreter;
	bool status = interpreter.initialized();
	
	if(status==false)
	{
	interpreter.initialize ();
	int status = interpreter.execute ();

		if (status != 0)
		{
			std::cerr << "creating embedded Octave interpreter failed!"
				  << std::endl;
			//return status;
		}
	}
	
	try
	{	
		//std::cout << size << "\n";
		//octave_idx_type n = size;
		octave_value_list in;

	//std::vector<double> x;
		Matrix inMatrix_x(inp->size_input1[2], 1);
		for( unsigned int i = 0; i < inp->size_input1[2]; i++ )
		{
				inMatrix_x(i, 0) = inp->input1[i]; // inMatrix_x(i) would also do the job
		}
/*
		std::cout << sizeof inMatrix_x / sizeof inMatrix_x(0,0) << "\n";
		std::cout << "-------rows-------" << "\n";

		std::cout << sizeof inMatrix_x(0,0) / sizeof(int) << "\n";
		std::cout << "-------cols-------" << "\n";
*/

		in(0) = inMatrix_x;
		Matrix mIn(in(0).matrix_value());
		std::cout << mIn << "\n";

/*
		in(0) = octave_value(size);
		//std::cout << in.length() << "\n";
		//std::cout << in << "\n";

		for (octave_idx_type i = 0; i < in.length(); i++)
        in(i) = octave_value (size[i]);
		
*/
		if(inp->name2!="")
			in(1) = inp->name2;
	
		octave_value_list out = octave::feval (inp->name1, in, 1);
		//octave_value_list out = octave::feval (name, in, 1);
		//octave_value_list out = octave::feval ("hamming", in, 1);
		Matrix mOut(out(0).matrix_value());
		//std::cout << mOut << "\n";
		int len = mOut.numel();
		inp->size_output1[1] = len;
		inp->output1 = new double[len];
		//inp->arr = (double*)malloc(sizeof(double)*len);
		//inp->arr[0] = (double)len;
		//std::cout << mOut(0) << "\n";
		for(int i=0; i<len; i++)
		{
			inp->output1[i] = mOut(i);//.float_value();
		}
		
		
		/*		
		Matrix mOut(out(0).matrix_value());

		//std::cout << mOut << "\n";

		
		for(int i=0;i<n;i++)
		{
			answ[i] = mOut(i);//.int_value();
		}
	  
		for(int i=0;i<n;i++)
		{
			std::cout << answ[i] << std::endl;
		}*/
		//std::cerr << "REACHED HERE!" << *answ << "\n";
		//return answ;

	
		
	
	}
	catch (const octave::exit_exception& ex)
	{
		std::cerr << "Octave interpreter exited with status = "
			  << ex.exit_status () << std::endl;
	}
	catch (const octave::execution_exception&)
	{
		std::cerr << "error encountered in Octave evaluator!" << std::endl;
	}
	return 0;
}
}
