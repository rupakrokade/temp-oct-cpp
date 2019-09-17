#define fun_h__
//extern "C" int fun (double* answ, double* in1, int in1_row, std::string name, std::string opt);

extern "C"
{
typedef struct octave_fun
{
	char* name1 = "";
	char* name2 = "";
	char* package = "";
	double* input1;
	double* input2;
	double* input3;
	int size_input1[2];
	int size_input2[2];
	int size_input3[2];
	int size_output1[2];
	int size_output2[2];
	int out_count;
	double* output1;
	double* output2;
}octf;

int fun(octf *inp);
}
