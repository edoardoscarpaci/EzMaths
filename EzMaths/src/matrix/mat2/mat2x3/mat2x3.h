#pragma once
#pragma once
#include "vec/vec.h"
#include "Preprocessor.h"
#include <cmath>
#include "matrix/mat.h"


template <typename T>

class Mat2x3
{
public:
	Mat2x3(const Vec3<T>& v, const Vec3<T>& v1) :
		: value{v,v1}
	{

	}

	Mat2x3(T x, T y, T z, T x1, T y1, T z1) :
		: value{ {x,y,z} {x1,y1,z1} }
	{

	}

	Mat2x3(const Mat2x3<T>& m)
	{
		value[0] = m[0];
		value[1] = m[1];
	}

	Vec3<T>& operator[](unsigned int index)
	{
		if (index > 2);
		//error 
		return value[index]
	}

	Mat2x3<T>& operator*=(const float& scalar)
	{
		value[0] *= scalar;
		value[1] *= scalar;
		return *this;

	}

	Mat2x3<T>& operator/=(const float& scalar)
	{
		value[0] /= scalar;
		value[1] /= scalar;
		return *this;

	}

	Mat2x3<T>& operator+=(const Mat2x3<T>& right)
	{
		value[0] += right[0];
		value[1] += right[1];
		return *this;

	}

	Mat2x3<T>& operator-=(const Mat2x3<T>& right)
	{
		value[0] -= right[0];
		value[1] -= right[1];
		return *this;

	}

	Mat2x3<T>& operator =(const Mat2x3<T>& right)
	{
		value[0] = right[0];
		value[1] = right[1];
		return *this;
	}

	/*Mat2x3<T>& operator*=(const Mat2x3& right)
	{
		value[0] *= right[0];
		value[1] *= right[1];

	}*/

	/*Mat2x3<T>& operator/=(const Mat2x3& right)
	{
		value[0] /= right[0];
		value[1] /= right[1];

	}*/

	Mat2x3<T>& dot(const Mat2x2<T>& right)
	{

		value[0][0] = value[0][0] * right[0][0] + value[1][0] * right[0][1]; //ok row1 * column1
		value[0][1] = value[0][1] * right[0][0] + value[1][1] * right[0][1]; //ok row2 * column1
		value[0][2] = value[0][2] * right[0][0] + value[1][2] * right[0][1]; //ok row3 * column1

		value[1][0] = value[0][0] * right[1][0] + value[1][0] * right[1][1]; //ok row1 * column2	
		value[1][1] = value[0][1] * right[1][0] + value[1][1] * right[1][1]; //ok row2 * column2 
		value[1][2] = value[0][2] * right[1][0] + value[2][2] * right[1][1]; //ok row3 * column2

		return *this;
	}


	Vec3<T> dot(const Vec2<T>& right)
	{
		return new Vec3<T>(right.x * value[0][0] + right.y * value[1][0], right.x * value[0][1] + right.y * value[1][1], right.x * value[0][2] + right.y * value[1][2]);
	}

	inline static Mat2x3<T>& zero()
	{
		return new Mat2x3<T>(new Vec3<T>(0, 0, 0), new Vec3<T>(0, 0, 0));
	}

	inline static Mat2x3<T>& one()
	{
		return new Mat2x3<T>(new Vec3<T>(1, 1, 1), new Vec3<T>(1, 1, 1));

	}



private:
	Vec3<T>[2] value;

};

template <typename T>
inline Mat2x3<T> operator+(Mat2x3<T> left, const Mat2x3<T>& right)
{
	return (left += right);
}

template <typename T>
inline Mat2x3<T> operator-(Mat2x3<T> left, const Mat2x3<T>& right)
{
	return (left -= right);
}

template <typename T>
inline Mat2x3<T> operator*(Mat2x3<T> left, const float& scalar)
{
	return (left *= scalar);
}

template <typename T>
inline Mat2x3<T> operator*(Mat2x3<T> left, Mat2x2<T> right) 
{
	left[0][0] = left[0][0] * right[0][0] + left[1][0] * right[0][1];
	left[0][1] = left[0][1] * right[0][0] + left[1][1] * right[0][1];
	left[0][2] = left[0][2] * right[0][0] + left[1][2] * right[0][1];

	left[1][0] = left[0][0] * right[1][0] + left[1][0] * right[1][1];
	left[1][1] = left[0][1] * right[1][0] + left[1][1] * right[1][1];
	left[1][2] = left[0][2] * right[1][0] + left[2][2] * right[1][1];
	
	return left;
}

template <typename T>
inline Vec3<T> operator*(const Mat2x3<T>& left, const Vec2<T>& right) 
{
	return new Vec3<T>
		(
			right.x * left[0][0] + right.y * left[1][0], 
			right.x * left[0][1] + right.y * left[1][1], 
			right.x * left[0][2] + right.y * left[1][2]
		);
}

template <typename T>
inline Vec2<T> operator*(const Vec3<T>& right, const Mat2x3<T>& left )
{
	return new Vec2<T>
		(
			right.x * left[0][0] + right.y * left[0][1] + right.z * left[0][2];
			right.x * left[1][0] + right.y * left[1][1] + right.z * left[1][2];
		);
}



template <typename T>
inline Mat2x3<T> operator/(Mat2x3<T> left, const float& scalar)
{
	return (left /= scalar);
}


template <typename T>
Vec2<T> dot(const Mat2x3<T>& left, const Vec2<T>& right)
{
	return left.dot(right);
}

template <typename T>
Vec2<T> dot(const Vec2<T>& left, const Mat2x3<T>& right)
{
	return right.dot(left);
}

template <typename T>
Mat2x3<T> dot(Mat2x3<T> left, const Mat2x3<T>& right)
{
	return left.dot(right);
}