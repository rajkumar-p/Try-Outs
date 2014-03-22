#include <fstream>
#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include "input_files_generation.hpp"

using namespace std;

#ifndef NULL
#define NULL 0
#endif

/*
	input_files_generation's constructor
*/
input_files_generation::input_files_generation()
	: writer(), gen()
{
	
}

/*
	input_files_generation's destructor
*/
input_files_generation::~input_files_generation()
{
	// If the file handle is still open, close it
	if (writer.is_open()) {
		writer.close();
	}
}

/*
	Method to write random numbers to files
*/
void input_files_generation::write_files(string dir, int n, int low, int high)
{
	// Convert n into char *
	char n_str[10];
	sprintf(n_str, "%d", n);
	
	// Throw exception if there is an error in the conversion
	if(n_str == NULL)
	{
		throw input_files_generation_exception("Error when converting [int] to [char *]");
	}
	
	// File name of the file to be created
	string file_name = dir + "/" + n_str + "_input.in";
	writer.open(file_name.c_str(), ios::out);
	
	// Throw exception if the call was not successful
	if(writer.fail())
	{
		throw input_files_generation_exception("Error in the call writer.open()");
	}
	
	// Write the total number of elements (n) as the first line
	writer <<n<<endl;
	
	// Set up the random distribution object
	boost::random::uniform_int_distribution<> dist(low, high);
	
	// Write random numbers n times to the file
	for(int i = 0; i < n; ++i)
	{
		writer <<dist(gen)<<endl;
	}
	
	writer.close();
}

/*
	input_files_generation_exception's constructor
*/
input_files_generation_exception::input_files_generation_exception(string msg)
{
	message = msg;
}

/*
	input_files_generation_exception's destructor
*/
input_files_generation_exception::~input_files_generation_exception() throw()
{
	// Do nothing
}

/*
	Overrides exception::what()
*/
const char* input_files_generation_exception::what() const throw()
{
	return message.c_str();
}
