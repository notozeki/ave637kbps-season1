#include <math.h>
#include "Vector.hpp"

Vector::Vector()
	: mX(0), mY(0), mZ(0)
{
}

Vector::Vector(double x, double y, double z)
	: mX(x), mY(y), mZ(z)
{
}

void Vector::setComp(double x, double y, double z)
{
	mX = x;
	mY = y;
	mZ = z;
}

void Vector::normalize()
{
	(*this) *= 1 / norm();
}

double Vector::norm() const
{
	return sqrt(mX*mX + mY*mY + mZ*mZ);
}

double Vector::x() const
{
	return mX;
}

double Vector::y() const
{
	return mY;
}

double Vector::z() const
{
	return mZ;
}

Vector Vector::operator+(const Vector& rhs) const
{
	return Vector(mX + rhs.mX, mY + rhs.mY, mZ + rhs.mZ);
}

Vector& Vector::operator+=(const Vector& rhs)
{
	mX += rhs.mX;
	mY += rhs.mY;
	mZ += rhs.mZ;
	return *this;
}

Vector& Vector::operator*=(const double a)
{
	mX *= a;
	mY *= a;
	mZ *= a;
	return *this;
}


Vector operator*(const double a, const Vector& rhs)
{
	return Vector(a*rhs.mX, a*rhs.mY, a*rhs.mZ);
}

Vector operator*(const Vector& lhs, const double a)
{
	return Vector(a*lhs.mX, a*lhs.mY, a*lhs.mZ);
}

double innerProd(const Vector& lhs, const Vector& rhs)
{
	return lhs.mX*rhs.mX + lhs.mY*rhs.mY + lhs.mZ*rhs.mZ; 
}
