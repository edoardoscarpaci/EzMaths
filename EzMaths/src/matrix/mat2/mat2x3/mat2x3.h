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

	inline static Mat2x3<T> zero()
	{
		return new Mat2x3<T>(new Vec3<T>(0, 0, 0), new Vec3<T>(0, 0, 0));
	}

	inline static Mat2x3<T> one()
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
inline Mat2x3<T> operator/(Mat2x3<T> left, const float& scalar)
{
	return (left /= scalar);
}


template <typename T>
inline Vec3<T> operator*(const Mat2x3<T>& left, const Vec2<T>& right) 
{
	return new Vec3<T>
		(
			left[0][0] * right.x + left[1][0] * right.y,
			left[0][1] * right.x + left[1][1] * right.y,
			left[0][2] * right.x + left[1][2] * right.y

		);
}


template <typename T>
inline Mat2x3<T> operator*(const Mat2x3<T>& left, const Mat2x2<T>& right)
{
	return new Mat2x3<T>
		(
			left[0][0] * right[0][0] + left[1][0] * right[0][1],
			left[0][1] * right[0][0] + left[1][1] * right[0][1],
			left[0][2] * right[0][0] + left[1][2] * right[0][1],

			left[0][0] * right[1][0] + left[1][0] * right[1][1],
			left[0][1] * right[1][0] + left[1][1] * right[1][1],
			left[0][2] * right[1][0] + left[1][2] * right[1][1]


		);
}

template <typename T>
inline Mat3x3<T> operator*(const Mat2x3<T>& left, const Mat3x2<T>& right)
{
	return new Mat3x3<T>
		(
			left[0][0] * right[0][0] + left[1][0] * right[0][1],
			left[0][1] * right[0][0] + left[1][1] * right[0][1],
			left[0][2] * right[0][0] + left[1][2] * right[0][1],

			left[0][0] * right[1][0] + left[1][0] * right[1][1],
			left[0][1] * right[1][0] + left[1][1] * right[1][1],
			left[0][2] * right[1][0] + left[1][2] * right[1][1],

			left[0][0] * right[2][0] + left[1][0] * right[2][1],
			left[0][1] * right[2][0] + left[1][1] * right[2][1],
			left[0][2] * right[2][0] + left[1][2] * right[2][1]

		);
}

template <typename T>
inline Mat4x3<T> operator*(const Mat2x3<T>& left, const Mat4x2<T>& right)
{
	return new Mat3x3<T>
		(
			left[0][0] * right[0][0] + left[1][0] * right[0][1],
			left[0][1] * right[0][0] + left[1][1] * right[0][1],
			left[0][2] * right[0][0] + left[1][2] * right[0][1],

			left[0][0] * right[1][0] + left[1][0] * right[1][1],
			left[0][1] * right[1][0] + left[1][1] * right[1][1],
			left[0][2] * right[1][0] + left[1][2] * right[1][1],

			left[0][0] * right[2][0] + left[1][0] * right[2][1],
			left[0][1] * right[2][0] + left[1][1] * right[2][1],
			left[0][2] * right[2][0] + left[1][2] * right[2][1],

			left[0][0] * right[3][0] + left[1][0] * right[3][1],
			left[0][1] * right[3][0] + left[1][1] * right[3][1],
			left[0][2] * right[3][0] + left[1][2] * right[3][1]

		);
}


template <typename T>
inline Vec2<T> operator*(const Vec3<T>& left, const Mat2x3<T>& right )
{
	return new Vec2<T>
		(
			left.x * right[0][0] + left.y * right[0][1] + left.z * right[0][2],
			left.x * right[1][0] + left.y * right[1][1] + left.z * right[1][2]
		);
}


template <typename T>
inline Mat3x2<T> operator*(const Mat3x2<T>& left, const Mat2x3<T>& right)
{
	return new Mat2x2<T>
		(
			left[0][0] * right[0][0] + left[1][0] * right[0][1] + left[2][0] * right[0][2],
			left[0][1] * right[0][0] + left[1][1] * right[0][1] + left[2][1] * right[0][2],

			left[0][0] * right[1][0] + left[1][0] * right[1][1] + left[2][0] * right[1][2],
			left[0][1] * right[1][0] + left[1][1] * right[1][1] + left[2][1] * right[1][2]

		);
}


template <typename T>
inline Mat2x3<T> operator*(const Mat3x3<T>& left, const Mat2x3<T>& right)
{
	return new Mat2x3<T>
		(
			left[0][0] * right[0][0] + left[1][0] * right[0][1] + left[2][0] * right[0][2],
			left[0][1] * right[0][0] + left[1][1] * right[0][1] + left[2][1] * right[0][2],
			left[0][2] * right[0][0] + left[1][2] * right[0][1] + left[2][2] * right[0][2],

			left[0][0] * right[1][0] + left[1][0] * right[1][1] + left[2][0] * right[1][2],
			left[0][1] * right[1][0] + left[1][1] * right[1][1] + left[2][1] * right[1][2],
			left[0][2] * right[1][0] + left[1][2] * right[1][1] + left[2][2] * right[1][2]


		);
}

template <typename T>
inline Mat2x4<T> operator*(const Mat3x4<T>& left, const Mat2x3<T>& right)
{
	return new Mat2x4<T>
		(
			left[0][0] * right[0][0] + left[1][0] * right[0][1] + left[2][0] * right[0][2],
			left[0][1] * right[0][0] + left[1][1] * right[0][1] + left[2][1] * right[0][2],
			left[0][2] * right[0][0] + left[1][2] * right[0][1] + left[2][2] * right[0][2],
			left[0][3] * right[0][0] + left[1][3] * right[0][1] + left[2][3] * right[0][2],


			left[0][0] * right[1][0] + left[1][0] * right[1][1] + left[2][0] * right[1][2],
			left[0][1] * right[1][0] + left[1][1] * right[1][1] + left[2][1] * right[1][2],
			left[0][2] * right[1][0] + left[1][2] * right[1][1] + left[2][2] * right[1][2],
			left[0][3] * right[1][0] + left[1][3] * right[1][1] + left[2][3] * right[1][2]



		);
}




