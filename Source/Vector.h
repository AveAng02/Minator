#pragma once

#include <string>

#ifndef VECTOR_H
#define VECTOR_H

namespace Dragon
{
	class Vector
	{
	public:

		Vector() : x(0.0), y(0.0), z(0.0) {}

		Vector(double x_ = 0.0, double y_ = 0.0, double z_ = 0.0)
			: x(x_), y(y_), z(z_) {}

		// copy constructor
		Vector(const Vector& vec_)
			: x(vec_.x), y(vec_.y), z(vec_.z) {}

		// copy assignment operator
		Vector& operator=(const Vector& vec_)
		{
			x = vec_.x;
			y = vec_.y;
			z = vec_.z;
			return *this;
		}

		Vector& operator+(const Vector& vec_);
		Vector& operator-(const Vector& vec_);
		Vector& operator*(const double value);
		Vector& operator/(const double value);

		void operator+=(const Vector& vec_);
		void operator-=(const Vector& vec_);
		void operator*=(const double value);
		void operator/=(const double value);

		double getMagnitude();
		double getSquareMagnitude();
		
		Vector getNormalized();

		double dot(const Vector& vec_);
		Vector& cross(const Vector& vec_);

		std::string toString();

		double x, y, z;
	};
}

#endif // !VECTOR_H_
