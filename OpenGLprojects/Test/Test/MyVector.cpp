#include "MyVector.h"
#include <iostream>
#include <vector>


//Vector1------------------------------------------------------------
std::vector<double> Vector::getVec() {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	return vec;
}

Vector& Vector::operator=(const Vector& Other) {
	vec = Other.vec;
	return *this;
}

void Vector::operator+=(const Vector& Other) {
	if (Other.vec.size() == 2) {
		vec[0] += Other.vec[0];
		vec[1] += Other.vec[1];
	}
	else if (Other.vec.size() == 3) {
		vec[0] += Other.vec[0];
		vec[1] += Other.vec[1];
		vec[2] += Other.vec[2];
	}
	else if (Other.vec.size() == 4) {
		vec[0] += Other.vec[0];
		vec[1] += Other.vec[1];
		vec[2] += Other.vec[2];
		vec[3] += Other.vec[3];
	}
}

void Vector::operator-=(const Vector& Other) {
	if (Other.vec.size() == 2) {
		vec[0] -= Other.vec[0];
		vec[1] -= Other.vec[1];
	}
	else if (Other.vec.size() == 3) {
		vec[0] -= Other.vec[0];
		vec[1] -= Other.vec[1];
		vec[2] -= Other.vec[2];
	}
	else if (Other.vec.size() == 4) {
		vec[0] -= Other.vec[0];
		vec[1] -= Other.vec[1];
		vec[2] -= Other.vec[2];
		vec[3] -= Other.vec[3];
	}
}

void Vector::operator*=(double i) {
	for (int k = 0; k < vec.size(); k++) {
		vec[k] *= i;
	}
}

double Vector::sclarMulti(const Vector& Other) {
	double result = 0;
	for (int i = 0; i < vec.size(); i++)
		result += vec[i] * Other.vec[i];
	return result;
}

//-------------------------------------------------------------------



//Vector2------------------------------------------------------------
Vector2::Vector2(double x, double y) {
	vec.push_back(x);
	vec.push_back(y);
}

Vector2 Vector2::operator+(const Vector2& Other) {
	return Vector2(vec[0] + Other.vec[0], vec[1] + Other.vec[1]);
}

Vector2 Vector2::operator-(const Vector2& Other) {
	return Vector2(vec[0] - Other.vec[0], vec[1] - Other.vec[1]);
}

Vector2 Vector2::operator*(double i) {
	return Vector2(vec[0] * i, vec[1] * i);
}

Vector2 Vector2::reverse() {
	Vector2 reverseVec = *this;
	reverseVec *= -1;
	return reverseVec;
}

//-------------------------------------------------------------------




//Vector3------------------------------------------------------------
Vector3::Vector3(double x, double y, double z) {
	vec.push_back(x);
	vec.push_back(y);
	vec.push_back(z);
}

Vector3 Vector3::operator+(const Vector3& Other) {
	return Vector3(vec[0] + Other.vec[0], vec[1] + Other.vec[1], vec[2] + Other.vec[2]);
}

Vector3 Vector3::operator-(const Vector3& Other) {
	return Vector3(vec[0] - Other.vec[0], vec[1] - Other.vec[1], vec[2] - Other.vec[2]);
}

Vector3 Vector3::operator*(double i) {
	return Vector3(vec[0] * i, vec[1] * i, vec[2] * i);
}

Vector3 Vector3::reverse() {
	Vector3 reverseVec = *this;
	reverseVec *= -1;
	return reverseVec;
}

Vector3 Vector3::vectorMulti(const Vector3& Other) {

	return Vector3(
		(vec[1] * Other.vec[2] - vec[2] * Other.vec[1]),
		(vec[2] * Other.vec[0] - vec[0] * Other.vec[2]),
		(vec[0] * Other.vec[1] - vec[1] * Other.vec[0])
	);
	/*if (this->sclarMulti(Other) <= 0) {
		
	}*/
}
//-------------------------------------------------------------------




//Vector4------------------------------------------------------------
Vector4::Vector4(double x , double y , double z, double f) {
	vec.push_back(x);
	vec.push_back(y);
	vec.push_back(z);
	vec.push_back(f);
}

Vector4 Vector4::operator+(const Vector4& Other) {
	return Vector4(vec[0] + Other.vec[0], vec[1] + Other.vec[1], vec[2] + Other.vec[2], vec[3] + Other.vec[3]);
}

Vector4 Vector4::operator-(const Vector4& Other) {
	return Vector4(vec[0] - Other.vec[0], vec[1] - Other.vec[1], vec[2] - Other.vec[2], vec[3] - Other.vec[3]);
}

Vector4 Vector4::operator*(double i) {
	return Vector4(vec[0] * i, vec[1] * i, vec[2] * i, vec[3] * i);
}

Vector4 Vector4::reverse() {
	Vector4 reverseVec = *this;
	reverseVec *= -1;
	return reverseVec;
}
//-------------------------------------------------------------------






//Matrix-------------------------------------------------------------
std::vector<double> Matrix::GetMatrix() {
	std::cout << std::endl;
	for (int i = 0; i < matrix.size(); i++) {
		if (i % 3 == 0 && matrix.size() == 9) std::cout << std::endl;
		else if (i % 4 == 0 && matrix.size() == 16) std::cout << std::endl;

		std::cout << matrix[i] << " ";
	}

	return matrix;
}

Matrix& Matrix::operator=(const Matrix& Other) {
	matrix = Other.matrix;
	return *this;
}
//-------------------------------------------------------------------


//Matrix3-------------------------------------------------------------
Matrix3::Matrix3(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {
	matrix = { x1, x2, x3, y1, y2, y3, z1, z2, z3 };
}

Matrix3::Matrix3(Vector3& a, Vector3& b, Vector3& c) {
	std::vector<double> copyVec1 = a.getVec();
	std::vector<double> copyVec2 = b.getVec();
	std::vector<double> copyVec3 = c.getVec();

	matrix.push_back(copyVec1[0]);
	matrix.push_back(copyVec2[0]);
	matrix.push_back(copyVec3[0]);

	matrix.push_back(copyVec1[1]);
	matrix.push_back(copyVec2[1]);
	matrix.push_back(copyVec3[1]);

	matrix.push_back(copyVec1[2]);
	matrix.push_back(copyVec2[2]);
	matrix.push_back(copyVec3[2]);
}

Matrix3::Matrix3(std::vector<double> mat) {
	matrix = mat;
}

Matrix3 Matrix3::operator+(const Matrix3& Other) {
	std::vector<double>newMatrix(matrix.size());
	for (int i = 0; i < matrix.size(); i++)
		newMatrix[i] = matrix[i] + Other.matrix[i];
	return Matrix3(newMatrix);
}

Matrix3 Matrix3::operator-(const Matrix3& Other) {
	std::vector<double>newMatrix(matrix.size());
	for (int i = 0; i < matrix.size(); i++)
		newMatrix[i] = matrix[i] - Other.matrix[i];
	return Matrix3(newMatrix);
}

Matrix3 Matrix3::operator*(double num) {
	std::vector<double>newMatrix(matrix.size());
	for (int i = 0; i < matrix.size(); i++)
		newMatrix[i] = matrix[i] * num;
	return Matrix3(newMatrix);
}

Matrix3 Matrix3::operator*(const Matrix3& Other) {
	std::vector<double>newMatrix(matrix.size());
	int i = 0, j = 0, k = 0, num_j = 0, num_k = 0, count = 0;
	while (i != matrix.size()) {
		while (count != 3) {
			do {
				newMatrix[i] += matrix[j] * Other.matrix[k];
				j++;
				k += 3;
			} while (j % 3 != 0);
			i++;
			j = num_j;
			k = ++num_k;
			count++;
		}
		num_k = 0;
		k = num_k;
		num_j+=3;
		j = num_j;
		count = 0;
	}
	return Matrix3(newMatrix);
}

Matrix3 Matrix3::Transposition() {
	std::vector<double>newMatrix(matrix.size());
	for (int i = 0, j = 0, count = 0, num_j = 0; i < matrix.size(); i++, j += 3, count++) {
		if (count == 3) {
			j = ++num_j;
			count = 0;
		}
		newMatrix[j] = matrix[i];
	}
	return Matrix3(newMatrix);
}
//-------------------------------------------------------------------


//Matrix4-------------------------------------------------------------

Matrix4::Matrix4(double x1, double y1, double z1, double f1, double x2, double y2, double z2, double f2, double x3, double y3, double z3, double f3, double x4, double y4, double z4, double f4) {
	matrix = { x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, f1, f2, f3, f4 };
}

Matrix4::Matrix4(Vector4& a, Vector4& b, Vector4& c, Vector4& d) {
	std::vector<double> copyVec1 = a.getVec();
	std::vector<double> copyVec2 = b.getVec();
	std::vector<double> copyVec3 = c.getVec();
	std::vector<double> copyVec4 = d.getVec();

	matrix.push_back(copyVec1[0]);
	matrix.push_back(copyVec2[0]);
	matrix.push_back(copyVec3[0]);
	matrix.push_back(copyVec4[0]);

	matrix.push_back(copyVec1[1]);
	matrix.push_back(copyVec2[1]);
	matrix.push_back(copyVec3[1]);
	matrix.push_back(copyVec4[1]);

	matrix.push_back(copyVec1[2]);
	matrix.push_back(copyVec2[2]);
	matrix.push_back(copyVec3[2]);
	matrix.push_back(copyVec4[2]);

	matrix.push_back(copyVec1[3]);
	matrix.push_back(copyVec2[3]);
	matrix.push_back(copyVec3[3]);
	matrix.push_back(copyVec4[3]);
}

Matrix4::Matrix4(std::vector<double> mat) {
	matrix = mat;
}

Matrix4::Matrix4(double X, double Y, double Z, char key) {
	if (key == 'T') {
		for (int i = 0, j = 0; i < 16; i++) {
			if (i == j) {
				matrix.push_back(1);
				j += 5;
			}
			else if (i == 3) matrix.push_back(X);
			else if (i == 7) matrix.push_back(Y);
			else if (i == 11) matrix.push_back(Z);
			else matrix.push_back(0);
		}
	}
	else if (key == 'S') {
		for (int i = 0; i < 16; i++) {
			if (i == 0) matrix.push_back(X);
			else if (i == 5) matrix.push_back(Y);
			else if (i == 10) matrix.push_back(Z);
			else if (i == 15) matrix.push_back(1);
			else matrix.push_back(0);
		}
	}
}

Matrix4 Matrix4::operator+(const Matrix4& Other) {
	std::vector<double>newMatrix(matrix.size());
	for (int i = 0; i < matrix.size(); i++)
		newMatrix[i] = matrix[i] + Other.matrix[i];
	return Matrix4(newMatrix);
}

Matrix4 Matrix4::operator-(const Matrix4& Other) {
	std::vector<double>newMatrix(matrix.size());
	for (int i = 0; i < matrix.size(); i++)
		newMatrix[i] = matrix[i] - Other.matrix[i];
	return Matrix4(newMatrix);
}

Matrix4 Matrix4::operator*(double num) {
	std::vector<double>newMatrix(matrix.size());
	for (int i = 0; i < matrix.size(); i++)
		newMatrix[i] = matrix[i] * num;
	return Matrix4(newMatrix);
}

Matrix4 Matrix4::operator*(const Matrix4& Other) {
	std::vector<double>newMatrix(matrix.size());
	int i = 0, j = 0, k = 0, num_j = 0, num_k = 0, count = 0;
	while (i != matrix.size()) {
		while (count != 4) {
			do {
				newMatrix[i] += matrix[j] * Other.matrix[k];
				j++;
				k += 4;
			} while (j % 4 != 0);
			i++;
			j = num_j;
			k = ++num_k;
			count++;
		}
		num_k = 0;
		k = num_k;
		num_j += 4;
		j = num_j;
		count = 0;
	}
	return Matrix4(newMatrix);
}

Matrix4 Matrix4::Transposition() {
	std::vector<double>newMatrix(matrix.size());
	for (int i = 0, j = 0, count = 0, num_j = 0; i < matrix.size(); i++, j += 4, count++) {
		if (count == 4) {
			j = ++num_j;
			count = 0;
		}
		newMatrix[j] = matrix[i];
	}
	return Matrix4(newMatrix);
}


	
//-------------------------------------------------------------------

//
