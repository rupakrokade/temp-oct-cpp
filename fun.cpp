
#include <iostream>
#include <octave/oct.h>
#include <octave/octave.h>
#include <octave/parse.h>
#include <octave/interpreter.h>
#include "fun.h"

extern "C"
{

int fun (void)
{
	int answ;
	// Create interpreter.
	
	static octave::interpreter interpreter;
	bool status = interpreter.initialized();
	double output[20];
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

		octave_idx_type n = 3.6;
		octave_value_list in;

		in(0) = octave_value(n);

		octave_value_list out = octave::feval ("round", in, 1);
		
	  answ = out(0).int_value();
		
		return answ;

	
		
	
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
