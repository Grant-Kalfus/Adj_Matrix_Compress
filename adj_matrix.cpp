#include "adj_matrix.h"


//default constructor for the adj matrix class
//Creates a 2x2 matrix filled with zeros
adj_matrix::adj_matrix()
{
	SIZE_OF_ADJ_ARRAY = 2; 
	adj_array = new type*[SIZE_OF_ADJ_ARRAY];
	
	for (int i = 0; i < SIZE_OF_ADJ_ARRAY; i++)  
		adj_array[i] = new type[SIZE_OF_ADJ_ARRAY]; 

	for (int i = 0; i < SIZE_OF_ADJ_ARRAY; i++) {
		for (int j = 0; j < SIZE_OF_ADJ_ARRAY; j++)
			adj_array[i][j] = 0;
	}

	SIZE_OF_COMP_ARRAY = max_entries();

	adj_compressed = new type[SIZE_OF_COMP_ARRAY];
	for (int i = 0; i < SIZE_OF_COMP_ARRAY; i++)
		adj_compressed[i] = 0;

}

//creates a nxn matrix based off use defined argument
//the array will be initialized with all zeros 
adj_matrix::adj_matrix(const int dimension)
{
	//Can't have matrix that it less than 2x2
	if (dimension < 2) {
		std::cerr << "ERROR: Cannot make graph with less than two verticies! You entered: " << dimension;
		abort();
	}
	
	//set size
	SIZE_OF_ADJ_ARRAY = dimension;

	//Do some dynamic allocation 
	adj_array = new type*[SIZE_OF_ADJ_ARRAY];

	for (int i = 0; i < SIZE_OF_ADJ_ARRAY; i++) { adj_array[i] = new type[SIZE_OF_ADJ_ARRAY]; }

	for (int i = 0; i < SIZE_OF_ADJ_ARRAY; i++) {
		for (int j = 0; j < SIZE_OF_ADJ_ARRAY; j++) {
			adj_array[i][j] = 0;
		}
	}

	
	SIZE_OF_COMP_ARRAY = max_entries();

	adj_compressed = new type[SIZE_OF_COMP_ARRAY];
	for (int i = 0; i < SIZE_OF_COMP_ARRAY; i++)
		adj_compressed[i] = 0;
}

//one line implementation of the ceiling function
int adj_matrix::ceilingFunction(double passIn) { if (passIn > int(passIn)) { return (int(passIn) + 1); } else { return int(passIn); } }

//Deconstructor to free memory
adj_matrix::~adj_matrix()
{
	for (int i = 0; i < SIZE_OF_ADJ_ARRAY; i++) 
		delete [] adj_array[i];

	delete [] adj_array;
	
	if (adj_compressed != NULL) {
		delete [] adj_compressed;
	}
}

//function to get the max amount of space to allocate in the 1d compressed array
//Take the size of the adjacency matrix (n), and 
unsigned int adj_matrix::max_entries(bool exclude_sym_line)
{
	int n = SIZE_OF_ADJ_ARRAY;
	if (exclude_sym_line)
		n = ((n*(n + 1)) / 2) - n;
	else
		n = ((n*(n + 1)) / 2);
	return n;
}

//Prints the currently stored adjacency matrix
void adj_matrix::print_adj_matrix(int width)
{
	std::cout << "Currently stored adjacency matrix:\n--------------------------------------------------------\n";
	for (int i = 0; i < SIZE_OF_ADJ_ARRAY; i++) {
		for (int j = 0; j < SIZE_OF_ADJ_ARRAY; j++) {
			std::cout << std::setw(width) << std::left << adj_array[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------\n"; 
}

//Prints the currently stored compressed matrix
void adj_matrix::print_comp_matrix(int width)
{
	std::cout << "Currently stored compressed matrix:\n--------------------------------------------------------\n";
	for (int i = 0; i < SIZE_OF_COMP_ARRAY; i++) {
		std::cout << std::setw(width) << std::left << adj_compressed[i];
	}
	std::cout << "\n--------------------------------------------------------\n";
}

//Set a value in the 2d matrix 
void adj_matrix::set_value_2d(type value, unsigned int row, unsigned int column)
{
	row -= 1;
	column -= 1;
	if (row >= SIZE_OF_ADJ_ARRAY || column >= SIZE_OF_ADJ_ARRAY) {
		std::cerr << "Error: maximum dimension exceeded\nValid maximum value: " << SIZE_OF_ADJ_ARRAY << ".\n Entered values were: Row - " << row + 1 << " Column - " << column + 1 << ".\n";
		return;
	}

	adj_array[row][column] = value;
	
}

//Set a value in the compressed matrix
void adj_matrix::set_value_compressed(type value, unsigned int index)
{
	if (index >= SIZE_OF_COMP_ARRAY) {
		std::cerr << "Error: maximum index exceeded\nValid maximum value: " << SIZE_OF_COMP_ARRAY << ".\n Entered value was: " << index << ".\n";
		return;
	}

	adj_compressed[index] = value;
}

//blocks user from entering parameters into the compress function
void adj_matrix::generate_adj_compressed_from_2d() { compress(); }

//blocks user from entering parameters into the decompress function
void adj_matrix::decompress_adj() { decompress(); }

//Compression algorithm
void adj_matrix::compress(int offset, int runNum)
{
	if (offset != SIZE_OF_ADJ_ARRAY - 1) {
		for (int i = offset; i < SIZE_OF_ADJ_ARRAY; i++)
			adj_compressed[i + runNum + offset] = adj_array[i][offset];
		compress(offset + 1, runNum + SIZE_OF_ADJ_ARRAY - offset - 2);
		return;
	}
	else {
		adj_compressed[SIZE_OF_COMP_ARRAY - 1] = adj_array[offset - 1][offset - 1];
		return;
	}
}


//Decompression algorithm
void adj_matrix::decompress(int offset, int runNum)
{
	if (offset != SIZE_OF_ADJ_ARRAY - 1) {
		for (int i = offset; i < SIZE_OF_ADJ_ARRAY; i++) {
			adj_array[i][offset] = adj_compressed[i + runNum + offset];
			adj_array[offset][i] = adj_compressed[i + runNum + offset];
		}
		decompress(offset + 1, runNum + SIZE_OF_ADJ_ARRAY - offset - 2);
		return;
	}
	else {
		 adj_array[offset - 1][offset - 1] = adj_compressed[SIZE_OF_COMP_ARRAY - 1];
		return;
	}
}
