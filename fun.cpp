#include <iostream>
#include <octave/oct.h>
#include <octave/octave.h>
#include <octave/parse.h>
#include <octave/interpreter.h>
#include"fun.h"

int fun (void)
{
	// Create interpreter.

	octave::interpreter interpreter;

	try
	{
		int status = interpreter.execute ();

		if (status != 0)
		{
			std::cerr << "creating embedded Octave interpreter failed!"
				  << std::endl;
			return status;
		}

		octave_idx_type n = 20;
		octave_value_list in;

		in(0) = octave_value(n);

		octave_value_list out = octave::feval ("hamming", in, 1);

		//std::cout << out.length() << "\n";
		return out.length();


		/*Matrix mOut(out(0).matrix_value());

		std::cout << mOut << "\n";

		ColumnVector vals(3);
		vals(0) = 1;
		vals(1) = 2;
		vals(2) = 3;
		octave_value_list f_arg, f_ret;
		f_arg(0) = octave_value(vals);
		f_arg(1) = octave_value(vals);
		octave::feval ("pkg", ovl ("load", "signal"), 0);
		f_ret = octave::feval("xcorr", f_arg, 1);
		Matrix unis(f_ret(0).matrix_value());
		std::cout << unis << "\n";
	*/
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
