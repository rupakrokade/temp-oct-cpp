
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
			unsigned int k=0;
////////////////First Input////////////////
			octave_value_list in;
			if(inp->size_input1[1]!=0 || inp->size_input1[2]!=0)
			{

				Matrix inMatrix_x(inp->size_input1[1],inp->size_input1[2]);

				for( unsigned int i = 0; i < inp->size_input1[1]; i++ )
				{
					for( unsigned int j = 0; j < inp->size_input1[2]; j++ )
					{
							inMatrix_x(i, j) = inp->input1[k]; 
							k++;
					}
				}

				in(0) = inMatrix_x;

				Matrix mIn(in(0).matrix_value());
				std::cout << "-------Input Matrix-------" << "\n";
				std::cout << mIn << "\n";
				std::cout << "--------------------" << "\n";
			}
////////////////Second Input////////////////
			if(inp->size_input2[1]!=0 || inp->size_input2[2]!=0)
			{
				octave_value_list in2;

				Matrix inMatrix_x2(inp->size_input2[1],inp->size_input2[2]);
				k=0;
				for( unsigned int i = 0; i < inp->size_input2[1]; i++ )
				{
					for( unsigned int j = 0; j < inp->size_input2[2]; j++ )
					{
							inMatrix_x2(i, j) = inp->input2[k]; 
							k++;
					}
				}

				in(1) = inMatrix_x2;
				Matrix mIn2(in(1).matrix_value());
				std::cout << "-------Input Matrix-------" << "\n";
				std::cout << mIn2 << "\n";
				std::cout << "--------------------" << "\n";

			}
////////////////Second Input////////////////
			if(inp->size_input3[1]!=0 || inp->size_input3[2]!=0)
			{
				octave_value_list in3;

				Matrix inMatrix_x3(inp->size_input3[1],inp->size_input3[2]);
				k=0;
				for( unsigned int i = 0; i < inp->size_input3[1]; i++ )
				{
					for( unsigned int j = 0; j < inp->size_input3[2]; j++ )
					{
							inMatrix_x3(i, j) = inp->input3[k]; 
							k++;
					}
				}

				in(2) = inMatrix_x3;
				Matrix mIn3(in(2).matrix_value());
				std::cout << "-------Input Matrix-------" << "\n";
				std::cout << mIn3 << "\n";
				std::cout << "--------------------" << "\n";


			}
//-------------------------------------------------------
			if(inp->name2)
			{
				in(3) = inp->name2;
			}

			octave::feval ("pkg", ovl("load", "signal"), 0);
/*
			if(inp->package)
			{
				std::cout << "Loading package: " << inp->package << "\n";
				octave::feval ("pkg", ovl("load", inp->package), 0);
			}
*/
			octave_value_list out = octave::feval (inp->name1, in, 1);

			Matrix mOut(out(0).matrix_value());


			//std::cout << mOut << "\n";



			
			int row1 = mOut.rows();
			int col1 = mOut.columns();
			//std::cout << "--output matrix: " << row1 << "X" << col1 << "\n";

			inp->size_output1[1] = row1;
			inp->size_output1[2] = col1;
			int len = row1*col1;
			inp->output1 = new double[len];
			k=0;

			for(unsigned int i=0;i<row1;i++)
				{
					for(unsigned int j=0;j<col1;j++)
					{
						inp->output1[k]=mOut(k);
						k++;
					}
				}

//			for(int i=0; i<len; i++)
//			{
//				inp->output1[i] = mOut(i);
//			}	
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
