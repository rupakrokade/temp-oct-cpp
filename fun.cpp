
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
		static octave::interpreter interpreter;
		bool status = interpreter.initialized();
		
		if(status==false)
		{
		interpreter.initialize ();
		int status_exec = interpreter.execute ();

			if (status_exec != 0)
			{
				std::cerr << "creating embedded Octave interpreter failed!"
						<< std::endl;
			}
		}
		
		try
		{	
			octave_value_list in;

			Matrix inMatrix_x(inp->size_input1[2], 1);
			
			for( unsigned int i = 0; i < inp->size_input1[2]; i++ )
			{
					inMatrix_x(i, 0) = inp->input1[i]; 
			}

			in(0) = inMatrix_x;
			Matrix mIn(in(0).matrix_value());
			std::cout << mIn << "\n";
		
			if(inp->name2)
			{
				in(1) = inp->name2;
			}

			octave_value_list out = octave::feval (inp->name1, in, 1);

			Matrix mOut(out(0).matrix_value());
			//std::cout << mOut << "\n";
			int len = mOut.numel();
			inp->size_output1[1] = len;
			inp->output1 = new double[len];

			for(int i=0; i<len; i++)
			{
				inp->output1[i] = mOut(i);
			}	
		}
		catch (const octave::exit_exception& ex)
		{
			std::cerr << "Octave interpreter exited with status = "
					<< ex.exit_status () << std::endl;
			return 1;
		}
		catch (const octave::execution_exception&)
		{
			std::cerr << "error encountered in Octave evaluator!" << std::endl;
			return 1;
		}
		return 0;
	}	
}
