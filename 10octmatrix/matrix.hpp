#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "matrix.h"
#include <iostream>
#include <ostream>
#include <stdexcept>
template <typename T>
size_t Matrix<T>::GetRows() const {
	return data.size();
}
template <typename T>
size_t Matrix<T>::GetColumns() const {
	if(data.empty()){
		return 0;
	}
	return data[0].size();
}
template <typename T>
void Matrix<T>::MakeRectangle(){
	size_t maxSize=0;
	for(const auto& row: data){
		if(row.size()>maxSize){
			maxSize=row.size();
		}
	}
	for(auto& row: data){
		row.resize(maxSize);
	}
}
template <typename T>
T& Matrix<T>::operator() (size_t i, size_t j){
			return data[i][j];
		}
template <typename T>
const T& Matrix<T>::operator() (size_t i, size_t j) const{
			return data[i][j];
}
template <typename T>
std::vector<std::vector<T>>::const_iterator Matrix<T>::begin() const {
			return data.cbegin();
}
template <typename T>
std::vector<std::vector<T>>::const_iterator Matrix<T>::end() const {
			return data.cend();
}
template <typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& matrix){
	const size_t rows = matrix.GetRows();
	const size_t columns = matrix.GetColumns();
	for(size_t i=0; i!=rows; ++i){
		for(size_t j=0; j!=columns; ++j){
			if(j>0){
				out<<"\t";
			}
			out<<matrix(i, j);
		}
		out<<"\n";
	}
	return out;
}
template <typename T>
std::istream& operator >> (std::istream& in, Matrix<T>& matrix){
	const size_t rows = matrix.GetRows();
	const size_t columns = matrix.GetColumns();
	for(size_t i=0; i!=rows; ++i){
		for(size_t j=0; j!=columns; ++j){
			in>>matrix(i, j);	
		}
	}
	return in;
}
template <typename T>
Matrix<T>& Matrix<T>::operator += (const Matrix<T>& other){
	const size_t rows = GetRows();
	const size_t columns = GetColumns();
	if(rows!=other.GetRows()||columns!=other.GetColumns()){
		throw std::invalid_argument("Different sizes");
	}
	for(size_t i=0; i!=rows; ++i){
		for(size_t j=0; j!=columns; ++j){
			data[i][j]+=other.data[i][j];	
		}
	}
	return *this;
}
template <typename T>
Matrix<T> operator+(const Matrix<T>&m1, const Matrix<T>&m2){
	auto tmp {m1};
	tmp+=m2;
	return tmp;
}
template <typename T>
template <typename T1>
bool Matrix<T>::operator ==(const Matrix<T1>& other) const{
	const size_t rows = GetRows();
	const size_t columns = GetColumns();
	if(rows!=other.GetRows()||columns!=other.GetColumns()){
		return false;
	}
	for(size_t i=0; i!=rows; ++i){
		for(size_t j=0; j!=columns; ++j){
			if(!((*this)(i, j)==other(i, j))){
				return false;
			}
		}
	}
	return true;
}
template <typename T1, typename  T2>
bool operator !=(const Matrix<T1>&m1, const Matrix<T2>&m2){
	return !(m1==m2);
	}
#endif //MATRIX_HPP
