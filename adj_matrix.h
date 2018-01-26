#pragma once
#include<iostream>
#include<iomanip>
#define NULL nullptr
typedef int type;
class adj_matrix
{
public:
	adj_matrix();

	//USR FUNCTIONS -------------------------------------------------------------------------
	
	//Size of the created matrix
	adj_matrix(const int dimension = 2);
	

	//Get the maximum entries in the small matrix
	unsigned int max_entries(bool exclude_sym_line = false);

	//Create the compressed matrix
	
	void generate_adj_compressed_from_2d();

	void decompress_adj();

	void print_adj_matrix(int width = 2);

	void print_comp_matrix(int width = 2);

	//SET FUNCTIONS -------------------------------------------------------------------------

	//Set a value of the 2d matrix. For value, use specified type. Use a number greater than zero for both rows and columns
	void set_value_2d(type value, unsigned int row, unsigned int column);

	void set_value_compressed(type value, unsigned int index);

	~adj_matrix();

private:
	int ceilingFunction(double passIn);
	void compress(int offset = 0, int runNum = 0);
	void decompress(int offset = 0, int runNum = 0);

	type **adj_array;
	type *adj_compressed;
	int dim;
	int SIZE_OF_ADJ_ARRAY;
	int SIZE_OF_COMP_ARRAY;
};

