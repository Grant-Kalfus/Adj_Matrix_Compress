#pragma once
#include<iostream>
#include<iomanip>
#define NULL nullptr

//The class takes an adjacency matrix and removes all the repeated entries in the upper triangle of the matrix
//It then creates a 1d array, and fills it with the remaining values in the matrix
//It can also perform the reverse operation, that is to take the 1d compressed array and turn it into an adjacency matrix
//Data type of stored matrix elements
typedef int type;
class adj_matrix
{
public:
	//Default constructor 
	//Creates a 2x2 matrix full of zeros
	adj_matrix();

	//USER FUNCTIONS -------------------------------------------------------------------------
	
	//Size of the created matrix
	//Allows user to adjust the size of the adjacency matrix
	adj_matrix(const int dimension = 2);
	

	//Get the maximum entries in the small matrix
	unsigned int max_entries(bool exclude_sym_line = false);

	//Create the compressed matrix from loaded 2d matrix
	void generate_adj_compressed_from_2d();

	//Convert compressed matrix back to uncompressed
	void decompress_adj();

	//Prints the stored adjacency matrix to the console
	void print_adj_matrix(int width = 2);

	//Prints the compressed 1d array to the console
	void print_comp_matrix(int width = 2);

	//SET FUNCTIONS -------------------------------------------------------------------------

	//Set a value of the 2d matrix. For value, use specified type. Use a number greater than zero for both rows and columns
	void set_value_2d(type value, unsigned int row, unsigned int column);

	//Set a value in the compressed matrix, index will be the position in the 1d array
	void set_value_compressed(type value, unsigned int index);

	//Deconstructor to free memory
	~adj_matrix();

private:
	//Implementation for ceiling function 
	int ceilingFunction(double passIn);
	
	//Compress the matrix
	void compress(int offset = 0, int runNum = 0);
	
	//Decompress the matrix 
	void decompress(int offset = 0, int runNum = 0);

	//
	type **adj_array;
	type *adj_compressed;
	
	int dim;
	int SIZE_OF_ADJ_ARRAY;
	int SIZE_OF_COMP_ARRAY;
};

