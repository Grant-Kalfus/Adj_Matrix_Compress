//Main.cpp
//Grant Kalfus
//January 25 2018
//Demo file for adj_matrix class
#include"adj_matrix.h"

using namespace std;

int main() {
	
	//make 4x4 matrix
	adj_matrix myMatrix(4);
	
	//print the empty matrix
	myMatrix.print_adj_matrix();

	//set the second value in the compressed matrix to 1
	myMatrix.set_value_compressed(1, 2);

	//set the eighth value in the compressed matrix to 1
	myMatrix.set_value_compressed(1, 8);

	//set the fifth value in the compressed matrix to 1
	myMatrix.set_value_compressed(1, 5);
	
	//print the compressed matrix
	myMatrix.print_comp_matrix();
	
	//convert the compressed matrix to a 4x4 adjacency matrix
	myMatrix.decompress_adj();

	//myMatrix.generate_adj_compressed_from_2d();

	//print the new matrix
	myMatrix.print_adj_matrix();

	return 0;
}