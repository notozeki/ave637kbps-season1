#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector {
public:
	Vector();
	Vector(double x, double y, double z);
	void setComp(double x, double y, double z);
	void normalize();
	double norm() const;
	double x() const;
	double y() const;
	double z() const;
	Vector operator+(const Vector& rhs) const;
	Vector& operator+=(const Vector& rhs);
	Vector& operator*=(const double a);
	friend Vector operator*(const double a, const Vector& rhs);
	friend Vector operator*(const Vector& lhs, const double a);
	friend double innerProd(const Vector& lhs, const Vector& rhs);
private:
	double mX, mY, mZ;
};

#endif // VECTOR_HPP
