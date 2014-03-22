# Input Files Generation

## Overview
This is a small program to generate random numbers to a number of files which can then be used to test various algorithms.

## Implementation Details
The algorithm is implemented using C++. You need to pass in the output directory where you want the files generated. Random numbers are generated using the boost C++ libraries. (Link given below). The main method to generate & write random numbers to a file is  

<code> void input_files_generation::write_files(string dir, int n, int low, int high) </code>

where did is the directory to where the files need to be written, n is the number of elements to be written, low is the low range of the random number generator and high is its high range.

## Input and Output
The input is a directory location to which the files need to written. The programs then writes random numbers to into the files. Without any change to the source, it should write 7 files to the passed dir. The number of files and the range of the numbers can be changed in the source code.
 
## How to run
Since only the source file is provided, you need to first compile the source before running it. You need the gnu c++ compiler (goto link given in the root README). Since a Makefile with the compiler flags, boost libraries location etc (or change according to your settings) is provided, to compile and link the source type in from console **make**. Now to run the linked program, type in from console **./main output_directory**. The above program should run your code. You can bypass manual compiling and linking by using a good editor. Link to Eclipse CDT download is given in the root README.

## Links
Boost C++ Libraries - <http://www.boost.org/>