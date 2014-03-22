#include "input_files_generation.hpp"

using namespace std;

int main (int argc, char const *argv[])
{
	// Check if the arguments are passed correctly
	if(argc != 2)
	{
		cerr <<"Wrong number of parameters"<<endl;
		cerr <<"Correct usage : program_name [Output_Dir]"<<endl;
		exit(-1);
	}
	
	try {
		// Instantiate the object and call the write_files method through it
		input_files_generation ifg;
		
		ifg.write_files(argv[1], 0, -1000, 1000);
		ifg.write_files(argv[1], 1, -1000, 1000);
		ifg.write_files(argv[1], 2, -1000, 1000);
		ifg.write_files(argv[1], 3, -1000, 1000);
		ifg.write_files(argv[1], 10, -1000, 1000);
		ifg.write_files(argv[1], 50, -1000, 1000);
		ifg.write_files(argv[1], 100, -1000, 1000);
		
	} catch(exception &e) {
		cout <<e.what()<<endl;
	}
	
	return 0;
}