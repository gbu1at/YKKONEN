#include <bits/stdc++.h>
using namespace std;



struct Matrix {
	int size;
	std::vector<std::vector<int>> m;
	Matrix(const std::vector<std::vector<int>>& m) {
		int n = m.size();
		size = 1;
		while (size < n) size *= 2;
		this->m.assign(size, vector<int>(size, 0));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				this->m[i][j] = m[i][j];
	}
	Matrix(const Matrix& m11, const Matrix& m12, const Matrix& m21, const Matrix& m22) {
		size = m11.size * 2;
		m.assign(size, std::vector<int>(size));


		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				int value;

				if (i >= size / 2 && j >= size / 2) value = m22.m[i - size / 2][j - size / 2];
				else if (j >= size / 2) value = m12.m[i][j - size / 2];
				else if (i >= size / 2) value = m21.m[i - size / 2][j];
				else value = m11.m[i][j];

				m[i][j] = value;
			}
		}
	}
	Matrix one() const {
		std::vector<std::vector<int>> result(size / 2, vector<int>(size / 2, 0));
		for (int i = 0; i < size / 2; ++i)
			for (int j = 0; j < size / 2; ++j)
				result[i][j] = m[i][j];
		return Matrix(result);
	}
	Matrix two() const {
		std::vector<std::vector<int>> result(size / 2, vector<int>(size / 2, 0));
		for (int i = 0; i < size / 2; ++i)
			for (int j = size / 2; j < size; ++j)
				result[i][j - size / 2] = m[i][j];
		return Matrix(result);
	}
	Matrix three() const {
		std::vector<std::vector<int>> result(size / 2, vector<int>(size / 2, 0));
		for (int i = size / 2; i < size; ++i)
			for (int j = 0; j < size / 2; ++j)
				result[i - size / 2][j] = m[i][j];
		return Matrix(result);
	}
	Matrix four() const {
		std::vector<std::vector<int>> result(size / 2, vector<int>(size / 2, 0));
		for (int i = size / 2; i < size; ++i)
			for (int j = size / 2; j < size; ++j)
				result[i - size / 2][j - size / 2] = m[i][j];
		return Matrix(result);
	}
};


Matrix operator+(const Matrix& m1, const Matrix& m2) {
	int size = m1.size;
	std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));


	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			result[i][j] = m1.m[i][j] + m2.m[i][j];

	return Matrix(result);
}


Matrix operator-(const Matrix& m1, const Matrix& m2) {
	int size = m1.size;
	std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));


	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			result[i][j] = m1.m[i][j] - m2.m[i][j];

	return Matrix(result);
}


Matrix operator*(const Matrix& m1, const Matrix& m2) {
	assert(m1.size == m2.size);
	if (m1.size == 1) {
		std::vector<std::vector<int>> result = {{m1.m[0][0] * m2.m[0][0]}};
		return Matrix( result );
	}
	Matrix A11 = m1.one();
	Matrix A12 = m1.two();
	Matrix A21 = m1.three();
	Matrix A22 = m1.four();

	Matrix B11 = m2.one();
	Matrix B12 = m2.two();
	Matrix B21 = m2.three();
	Matrix B22 = m2.four();


	Matrix D1 = (A11 + A22) * (B11 + B22);
	Matrix D3 = A11 * (B22 + B12);
	Matrix D2 = (A12 - A11) * B22;
	Matrix D5 = A22 * (B21 + B11);
	Matrix D4 = (A21 - A22) * B11;
	Matrix D6 = (A12 + A22) * (B21 - B22);
	Matrix D7 = (A11 + A21) * (B12 - B11);

	Matrix C11 = D1 + D6 + D2 - D5;
	Matrix C12 = D2 + D3;
	Matrix C21 = D4 + D5;
	Matrix C22 = D1 + D7 + D4 - D3;

	return Matrix(C11, C12, C21, C22);
}


Matrix good(const Matrix& a, const Matrix& b) {
	int size = a.size;
	std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j) {
			for (int k = 0; k < size; ++k)
				result[i][j] += a.m[i][k] * b.m[k][j];
		}
	return Matrix(result);
}


bool operator==(const Matrix& a, const Matrix& b) {
	int size = a.size;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			if (a.m[i][j] != b.m[i][j]) return false;
	return true;
}


std::vector<std::vector<int>> rndMatrix(int size) {
	std::vector<std::vector<int>> result(size, vector<int>(size, 0));
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			result[i][j] = rand() % 4;
	return result;
}


#define TIME

int main() {
	std::vector<std::vector<int>> x = rndMatrix(100); 
	Matrix a(x);
	std::vector<std::vector<int>> y = rndMatrix(100); 
	Matrix b(y);

	#ifdef TIME
		int start1 = clock();
	#endif

	Matrix c = a * b;

	#ifdef TIME
		int finish1 = clock();
		std::cout << (finish1 - start1) / (double) CLOCKS_PER_SEC << '\n';
	#endif

	#ifdef TIME
		int start2 = clock();
	#endif

	Matrix e = good(a, b);

	#ifdef TIME
		int finish2 = clock();
		std::cout << (finish2 - start2) / (double) CLOCKS_PER_SEC << '\n';
	#endif

	if (c == e) std::cout << "OK\n";
	else std::cout << "NO\n";

	return 0;
}
