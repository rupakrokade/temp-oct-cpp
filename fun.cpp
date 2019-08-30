
#include <iostream>
#include <octave/oct.h>
#include <octave/octave.h>
#include <octave/parse.h>
#include <octave/interpreter.h>
#include <math.h>
#include <string>
#include "fun.h"

extern "C"
{

int fun (double* answ, double* size, std::string name)
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

		in(0) = octave_value(size);
		//std::cout << in.length() << "\n";
		//std::cout << in << "\n";

		for (octave_idx_type i = 0; i < in.length(); i++)
        in(i) = octave_value (size[i]);
		

		octave_value_list out = octave::feval (name, in, 1);
		//octave_value_list out = octave::feval ("hamming", in, 1);
		Matrix mOut(out(0).matrix_value());
		//std::cout << mOut << "\n";

		//std::cout << mOut.length() << "\n";
		for(int i=0; i<mOut.length(); i++)
		{
			answ[i] = mOut(i);//.float_value();
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
