#pragma once

#pragma once
#pragma once
#include "vec/vec.h"
#include "Preprocessor.h"
#include <cmath>
#include "matrix/mat.h"


template <typename T>

class Mat2x4
{
public:
	Mat2x4(const Vec4<T>& v, const Vec<T>& v1) :
		: value{v,v1}
	{

	}

	Mat2x4(T x, T y, T z, T w, T x1, T y1, T z1, T w1) :
	value{{x,y,z,w},{x1,y1,z1,w1}}
	{

	}

	Mat2x4(const Mat2x4<T>& m)
	{
		value[0] = m[0];
		value[1] = m[1];
	}

	Vec4<T>& operator[](unsigned int index)
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

	Mat2x4<T>& operator/=(const float& scalar)
	{
		value[0] /= scalar;
		value[1] /= scalar;
		return *this;

	}

	Mat2x4<T>& operator+=(const Mat2x4<T>& right)
	{
		value[0] += right[0];
		value[1] += right[1];
		return *this;

	}

	Mat2x4<T>& operator-=(const Mat2x4<T>& right)
	{
		value[0] -= right[0];
		value[1] -= right[1];
		return *this;

	}

	Mat2x4<T>& operator =(const Mat2x4<T>& right)
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

	Mat2x4<T>& dot(const Mat2x2<T>& right)
	{

		value[0][0] = value[0][0] * right[0][0] + value[1][0] * right[0][1];
		value[0][1] = value[0][1] * right[0][0] + value[1][1] * right[0][1];
		value[0][2] = value[0][2] * right[0][0] + value[1][2] * right[0][1];
		value[0][3] = value[0][3] * right[0][0] + value[1][3] * right[0][1];


		value[1][0] = value[0][0] * right[1][0] + value[1][0] * right[1][1];
		value[1][1] = value[0][1] * right[1][0] + value[1][1] * right[1][1];
		value[1][2] = value[0][2] * right[1][0] + value[1][2] * right[1][1];
		value[1][3] = value[0][3] * right[1][0] + value[1][3] * right[1][1];


		return *this;
	}


	Vec4<T> dot(const Vec2<T>& right)
	{
		return new Vec4<T>
			(
				value[0][0] * right.x + value[1][0] * right.y,
				value[0][1] * right.x + value[1][1] * right.y,
				value[0][2] * right.x + value[1][2] * right.y,
				value[0][3] * right.x + value[1][3] * right.y,

			)
	}

	inline static Mat2x4<T>& zero()
	{
		return new Mat2x4<T>(new Vec4<T>(0, 0, 0, 0), new Vec4<T>(0, 0, 0, 0));
	}

	inline static Mat2x4<T>& one()
	{
		return new Mat2x4<T>(new Vec3<T>(1, 1, 1, 1), new Vec4<T>(1, 1, 1, 1));

	}



private:
	Vec4<T>[2] value;

};

template <typename T>
inline Mat2x4<T> operator+(Mat2x4<T> left, const Mat2x4<T>& right)
{
	return (left += right);
}

template <typename T>
inline Mat2x4<T> operator-(Mat2x4<T> left, const Mat2x4<T>& right)
{
	return (left -= right);
}

template <typename T>
inline Mat2x4<T> operator*(Mat2x4<T> left, const float& scalar)
{
	return (left *= scalar);
}

template <typename T>
inline Mat2x4<T> operator*(const Mat2x4<T>& left, const Mat2x2<T>& right)
{

	return new Mat2x4<T>
		(
			left[0][0] * right[0][0] + left[1][0] * right[0][1],
			left[0][1] * right[0][0] + left[1][1] * right[0][1],
			left[0][2] * right[0][0] + left[1][2] * right[0][1],
			left[0][3] * right[0][0] + left[1][3] * right[0][1],

			left[0][0] * right[1][0] + left[1][0] * right[1][1]
			left[0][1] * right[1][0] + left[1][1] * right[1][1]
			left[0][2] * right[1][0] + left[1][2] * right[1][1]
			left[0][2] * right[1][0] + left[1][3] * right[1][1]

		);
}

template <typename T>
inline Vec4<T> operator*(const Mat2x4<T>& left, const Vec2<T>& right)
{
	return new Vec3<T>
		(
			right.x * left[0][0] + right.y * left[1][0],
			right.x * left[0][1] + right.y * left[1][1],
			right.x * left[0][2] + right.y * left[1][2],
			right.x * left[0][3] + right.y * left[1][3]
		);
}

template <typename T>
inline Vec2<T> operator*(const Vec4<T>& right, const Mat2x4<T>& left)
{
	return new Vec2<T>
		(
			right.x * left[0][0] + right.y * left[0][1] + right.z * left[0][2], right.w * value[0][3];
			right.x * left[1][0] + right.y * left[1][1] + right.z * left[1][2], right.w * value[1][3];
		);
}



template <typename T>
inline Mat2x4<T> operator/(Mat2x4<T> left, const float& scalar)
{
	return (left /= scalar);
}


