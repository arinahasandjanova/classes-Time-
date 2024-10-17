#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>
#include <iostream>
#include <vector>
template <typename T>
class Matrix{
	private:
		std::vector<std::vector<T>> data;
		void MakeRectangle();
	public:
		size_t GetRows() const;
		size_t GetColumns() const;
		Matrix(const std::vector<std::vector<T>>& d): data {d}{
			MakeRectangle();
		}
		Matrix(size_t rows, size_t columns){
			data.resize(rows);
			for(auto& row: data){
				row.resize(columns);
			}
		}
		/*const std::vector<T>& operator[] (size_t i) const{
			return data[i];
		}
		std::vector<T>& operator[] (size_t i){
			return data[i];
		}*/
		T& operator() (size_t i, size_t j);
		const T& operator() (size_t i, size_t j) const;
		using const_iterator = decltype(data.cbegin());
		std::vector<std::vector<T>>::const_iterator begin() const;
		std::vector<std::vector<T>>::const_iterator end() const;
		Matrix<T>& operator += (const Matrix<T>& other);
		template <typename T1>
		bool operator ==(const Matrix<T1>& other) const;
	};
template <typename T1, typename  T2>
bool operator !=(const Matrix<T1>&m1, const Matrix<T2>&m2);
template <typename T>
Matrix<T> operator+(const Matrix<T>&m1, const Matrix<T>&m2);
template <typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& matrix);
template <typename T>
std::istream& operator >> (std::istream& in, Matrix<T>& matrix);

#include "matrix.hpp"
#endif //MATRIX_H
