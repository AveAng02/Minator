
#include "Vector.h"

namespace Dragon
{
	Vector& Vector::operator+(const Vector& vec_)
	{
		Vector result(this->x + vec_.x, this->y + vec_.y, this->z + vec_.z);
		return result;
	}

	Vector& Vector::operator-(const Vector& vec_)
	{
		Vector result(this->x - vec_.x, this->y - vec_.y, this->z - vec_.z);
		return result;
	}

	Vector& Vector::operator*(const double value)
	{
		Vector result(this->x * value, this->y * value, this->z * value);
		return result;
	}

	Vector& Vector::operator/(const double value)
	{
		Vector result(this->x / value, this->y / value, this->z / value);
		return result;
	}

	void Vector::operator+=(const Vector& vec_)
	{
		this->x += vec_.x;
		this->y += vec_.y;
		this->z += vec_.z;
	}

	void Vector::operator-=(const Vector& vec_)
	{
		this->x -= vec_.x;
		this->y -= vec_.y;
		this->z -= vec_.z;
	}

	void Vector::operator*=(const double value)
	{
		x *= value;
		y *= value;
		z *= value;
	}

	void Vector::operator/=(const double value)
	{
		x /= value;
		y /= value;
		z /= value;
	}

	double Vector::getMagnitude()
	{
		return sqrt(getSquareMagnitude());
	}

	double Vector::getSquareMagnitude()
	{
		return x * x + y * y + z * z;
	}

	Vector Vector::getNormalized()
	{
		double value = getMagnitude();
		Vector result(x / value, y / value, z / value);
		return result;
	}

	double Vector::dot(const Vector& vec_)
	{
		return x * vec_.x + y * vec_.y + z * vec_.z;
	}

	Vector& Vector::cross(const Vector& vec_)
	{
		double x_ = y * vec_.z - z * vec_.y;
		double y_ = x * vec_.z - z * vec_.x;
		double z_ = x * vec_.y - y * vec_.x;
		Vector result(x_, y_, z_);
		return result;
	}

	std::string Vector::toString()
	{
		std::string xVal = std::to_string(x), yVal = std::to_string(y), zVal = std::to_string(z);

		// include vector id in the printing statement later
		std::string str = "Vector : [ " + xVal + ", " + yVal + ", " + zVal + "]";
		return str;
	}
}
