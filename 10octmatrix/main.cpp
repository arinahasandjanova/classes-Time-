#include <iostream>
#include "matrix.h"

int main(){
	Matrix<int> m ({
					{1, 2, 3},
					{4, 5, 6}
					});
	std::cout<<m[1][1]<<"\n";
	std::cout<<m.GetColumns()<<"\n";
	Matrix<double> md(3, 4);
	md[0][0]=8;
	std::cout<<md[0][0]<<"\n";
	md[0].resize(10);
	
	return 0;
}
