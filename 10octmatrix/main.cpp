#include <iostream>
#include "matrix.h"

int main(){
	Matrix<double> m ({
					{1, 2, 3},
					{4, 5, 6},
					{7, 8, 9}
					});
	//std::cout<<m.GetColumns()<<"\n";
	Matrix<double> md(3, 3);
	Matrix<double> s(3, 3);
	std::cin>>md;
	if(md==m){
		std::cout<<"\nyes\n";
	}else if(md!=m){
		std::cout<<"\nno\n";
	}
	std::cout<<"\n"<<md<<"\n";
	s=md+m;
	std::cout<<"\n"<<s<<"\n";
	//m(0,2)=8;
	
	//auto it=m.begin();
	//auto it2=m.end();
	/*for(auto iter=it; iter!=it2; ++iter){
		for(auto elem: *iter){
			std::cout<<elem<<" ";
			}
			std::cout<<"\n";
		}*/
	
	return 0;
}
