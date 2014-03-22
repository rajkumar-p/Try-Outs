// 
//  input_files_generation.hpp
//  input_files_generation
//  
//  Created by raj on 2012-01-21.
//  Free as in free speech.
// 

#include <fstream>
#include <string>
#include <exception>
#include <boost/random/mersenne_twister.hpp>

using namespace std;

/*
	Class to generate the random input files
*/
class input_files_generation
{
public:
	input_files_generation ();
	virtual ~input_files_generation ();
	void write_files(string , int , int , int);

private:
	ofstream writer;
	boost::random::mt19937 gen;
};

/*
	Class to handle exceptions when using input_files_generation
*/
class input_files_generation_exception : public exception
{
public:
	input_files_generation_exception (string );
	virtual ~input_files_generation_exception () throw();
	virtual const char *what() const throw();

private:
	string message;
};