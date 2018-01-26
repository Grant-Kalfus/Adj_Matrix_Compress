#include"adj_matrix.h"

using namespace std;

int main() {
	adj_matrix myMatrix(4);
	myMatrix.print_adj_matrix();

	myMatrix.set_value_compressed(1, 2);

	myMatrix.set_value_compressed(1, 8);

	myMatrix.set_value_compressed(1, 5);
	myMatrix.print_comp_matrix();
	myMatrix.decompress_adj();

	//myMatrix.generate_adj_compressed_from_2d();

	myMatrix.print_adj_matrix();

	return 0;
}