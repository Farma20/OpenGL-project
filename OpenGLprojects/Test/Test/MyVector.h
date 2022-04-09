#pragma once
#include<vector>
//Vector------------------------------------------------------------
class Vector {
protected:
	std::vector<double>vec;
public:
	std::vector<double> getVec();

	Vector& operator= (const Vector& Other);

	void operator+=(const Vector& Other);

	void operator-=(const Vector& Other);

	void operator*=(double i);

	double sclarMulti(const Vector& Other);

};

class Vector2 : public Vector {
public:
	Vector2(double x = 0, double y = 0);

	Vector2 operator+(const Vector2& Other);

	Vector2 operator-(const Vector2& Other);

	Vector2 operator*(double i);

	Vector2 reverse();

};

class Vector3 : public Vector {
public:
	Vector3(double x = 0, double y = 0, double z = 0);

	Vector3 operator+(const Vector3& Other);

	Vector3 operator-(const Vector3& Other);

	Vector3 operator*(double i);
	
	Vector3 reverse();

	Vector3 vectorMulti(const Vector3& Other);
};

class Vector4 : public Vector {
public:
	Vector4(double x = 0, double y = 0, double z = 0, double f = 0);

	Vector4 operator+(const Vector4& Other);

	Vector4 operator-(const Vector4& Other);

	Vector4 operator*(double i);

	Vector4 reverse();
};

//------------------------------------------------------------------



//Matrix-------------------------------------------------------------
class Matrix {
protected:
	std::vector<double> matrix;
public:
	std::vector<double> GetMatrix();

	Matrix& operator=(const Matrix& Other);
};

class Matrix3 : public Matrix {
public:
	Matrix3(double x1 = 0, double x2 = 0, double x3 = 0,
			double y1 = 0, double y2 = 0, double y3 = 0,
			double z1 = 0, double z2 = 0, double z3 = 0);

	Matrix3(Vector3& a, Vector3& b, Vector3& c);

	Matrix3(std::vector<double> mat);

	Matrix3 operator+(const Matrix3& Other);

	Matrix3 operator-(const Matrix3& Other);

	Matrix3 operator*(double num);

	Matrix3 operator*(const Matrix3& Other);

	Matrix3 Transposition();


};

class Matrix4 : public Matrix {
public:
	Matrix4(double x1 = 0, double y1 = 0, double z1 = 0, double f1 = 0,
			double x2 = 0, double y2 = 0, double z2 = 0, double f2 = 0,
			double x3 = 0, double y3 = 0, double z3 = 0, double f3 = 0,
			double x4 = 0, double y4 = 0, double z4 = 0, double f4 = 0 );

	Matrix4(Vector4& a, Vector4& b, Vector4& c, Vector4& d);

	Matrix4(std::vector<double> mat);

	Matrix4(double X, double Y, double Z, char key);

	Matrix4 operator+(const Matrix4& Other);

	Matrix4 operator-(const Matrix4& Other);

	Matrix4 operator*(double num);

	Matrix4 operator*(const Matrix4& Other);

	Matrix4 Transposition();

	
};
//-------------------------------------------------------------------































//class Vector {
//protected:
//	std::vector<double>vec;
//public:
//	template<typename Type>
//	Type* operator+ (Type& secVec) {
//		if (typeid(secVec) == Vector2) {
//			Vector* A = new Vector2(this->vec[0] + secVec.vec[0], this->vec[1] + secVec.vec[1]);
//			return A;
//		}
//		else if (typeid(secVec) == Vector3) {
//			Vector* A = new Vector3(this->vec[0] + secVec.vec[0], this->vec[1] + secVec.vec[1], this->vec[2] + secVec.vec[2]);
//			return A;
//		}
//		else if (typeid(secVec) == Vector4) {
//			Vector* A = new Vector4(this->vec[0] + secVec.vec[0], this->vec[1] + secVec.vec[1], this->vec[2] + secVec.vec[2], this->vec[3] + secVec.vec[3]);
//			return A;
//		}
//	};
//
//	virtual void operator+= (Vector& secVec) {};
//
//	virtual Vector* operator- (Vector& secVec) {};
//
//	virtual void operator-= (Vector& secVec) {};
//
//	Vector* operator* (double a) {
//		if (this->vec.size() == 2) {
//
//		}
//	}
//
//
//};
//
//class Vector2 : public Vector {
//public:
//	Vector2(double x, double y) { vec = { x, y }; }
//
//	Vector* operator+ ( Vector2& secVec) {
//		Vector* A = new Vector2(this->vec[0] + secVec.vec[0], this->vec[1] + secVec.vec[1]);
//		return A;
//	}
//
//	void operator+= (Vector2& secVec) {
//		this->vec[0] += secVec.vec[0];
//		this->vec[1] += secVec.vec[1];
//	}
//
//	Vector* operator- (Vector2& secVec) {
//		Vector* A = new Vector2(this->vec[0] - secVec.vec[0], this->vec[1] - secVec.vec[1]);
//		return A;
//	}
//
//	void operator-= (Vector2& secVec) {
//		this->vec[0] -= secVec.vec[0];
//		this->vec[1] -= secVec.vec[1];
//	}
//};
//
//class Vector3 : public Vector {
//public:
//	Vector3(double x, double y, double z) { vec = { x, y, z }; }
//
//	Vector* operator+ (Vector3& secVec) {
//		Vector* A = new Vector3(this->vec[0] + secVec.vec[0], this->vec[1] + secVec.vec[1], this->vec[2] + secVec.vec[2]);
//		return A;
//	}
//
//	void operator+= (Vector3& secVec) {
//		this->vec[0] += secVec.vec[0];
//		this->vec[1] += secVec.vec[1];
//		this->vec[2] += secVec.vec[2];
//	}
//
//	Vector* operator- (Vector3& secVec) {
//		Vector* A = new Vector3(this->vec[0] - secVec.vec[0], this->vec[1] - secVec.vec[1], this->vec[2] - secVec.vec[2]);
//		return A;
//	}
//
//	void operator-= (Vector3& secVec) {
//		this->vec[0] -= secVec.vec[0];
//		this->vec[1] -= secVec.vec[1];
//		this->vec[2] -= secVec.vec[2];
//	}
//};
//
//class Vector4 : public Vector {
//public:
//	Vector4(double x, double y, double z, double f) { vec = { x, y, z, f }; }
//
//	Vector* operator+ (Vector4& secVec) {
//		Vector* A = new Vector4(this->vec[0] + secVec.vec[0], this->vec[1] + secVec.vec[1], this->vec[2] + secVec.vec[2], this->vec[3] + secVec.vec[3]);
//		return A;
//	}
//
//	void operator+= (Vector4& secVec) {
//		this->vec[0] += secVec.vec[0];
//		this->vec[1] += secVec.vec[1];
//		this->vec[2] += secVec.vec[2];
//		this->vec[3] += secVec.vec[3];
//	}
//
//	Vector* operator- (Vector4& secVec) {
//		Vector* A = new Vector4(this->vec[0] - secVec.vec[0], this->vec[1] - secVec.vec[1], this->vec[2] - secVec.vec[2], this->vec[3] - secVec.vec[3]);
//		return A;
//	}
//
//	void operator-= (Vector4& secVec) {
//		this->vec[0] -= secVec.vec[0];
//		this->vec[1] -= secVec.vec[1];
//		this->vec[2] -= secVec.vec[2];
//		this->vec[3] -= secVec.vec[3];
//	}
//};