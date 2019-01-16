#pragma once
#include "vec/vec.h"
#include "Preprocessor.h"
#include <cmath>
#include "matrix/mat.h"

template <typename T>
class Mat3x3
{
public:
	Mat3x3(const Vec3<T>& v, const Vec3<T>& v1, const Vec3<T>& v2) :
		: value{ v,v1,v2 },
	{

	}

	Mat3x3(T x, T y, T z, T x1, T y1, T z1, T x2, T y2, T z2) :
		: value{ {x,y,z} {x1,y1,z1} {x2,y2,z2} }
	{

	}

	Mat3x3(const Mat3x3<T>& m)
	{
		value[0] = m[0];
		value[1] = m[1];
		value[2] = m[2];
	}

	Vec2<T>& operator[](unsigned int index)
	{
		if (index > 3);
		//error 
		return value[index]
	}

	Mat3x3<T>& operator*=(const float& scalar)
	{
		value[0] *= scalar;
		value[1] *= scalar;
		value[2] *= scalar;
		return *this;

	}

	Mat3x3<T>& operator/=(const float& scalar)
	{
		value[0] /= scalar;
		value[1] /= scalar;
		value[2] /= scalar;

		return *this;

	}

	Mat3x3<T>& operator+=(const Mat3x3& right)
	{
		value[0] += right[0];
		value[1] += right[1];
		value[2] += right[2];

		return *this;

	}

	Mat3x3<T>& operator-=(const Mat3x3<T>& right)
	{
		value[0] -= right[0];
		value[1] -= right[1];
		value[2] -= right[2];

		return *this;

	}

	Mat3x3<T>& operator =(const Mat3x3<T>& right)
	{
		value[0] = right[0];
		value[1] = right[1];
		value[2] = right[2];

		return *this;
	}

	inline static Mat3x3<T> zero()
	{
		return new Mat3x3<T>(new Vec3<T>(0, 0, 0), new Vec3<T>(0, 0, 0), new Vec3<T>(0, 0, 0));
	}

	inline static Mat3x3<T> one()
	{
		return new Mat3x3<T>(new Vec3<T>(1, 1, 1), new Vec3<T>(1, 1, 1), new Vec3<T>(1, 1, 1));

	}

	inline static Mat3x3<T> identity()
	{
		return new Mat3x3<T>(new Vec3<T>(1, 0, 0), new Vec3<T>(0, 1, 0), new Vec3<T>(0, 0, 1));
	}


private:
	Vec3<T>[3] value;

};

template <typename T>
inline Mat3x3<T> operator==(Mat3x3<T> left, const Mat3x3<T>& right)
{
	return (left[0] == right[0]) && (left[1] == right[1]) && (left[2] == right[2]);
}

template <typename T>
inline Mat3x3<T> operator!=(Mat3x3<T> left, const Mat3x3<T>& right)
{
	return !(left == right);
}


template <typename T>
inline Mat3x3<T> operator+(Mat3x3<T> left, const Mat3x3<T>& right)
{
	return (left += right);
}

template <typename T>
inline Mat3x3<T> operator-(Mat3x3<T> left, const Mat3x3<T>& right)
{
	return (left -= right);
}

template <typename T>
inline Mat3x3<T> operator*(Mat3x3<T> left, const float& scalar)
{
	return (left *= scalar);
}

template <typename T>
inline Mat3x3<T> operator/(Mat3x3<T> left, const float& scalar)
{
	return (left /= scalar);
}

template <typename T>
inline Mat3x2<T> operator* (const Mat3x2<T>& left, const Mat3x3<T>& right)
{
	return new Mat3x2<T>
		(
			left[0][0] * right[0][0] + left[1][0] * right[0][1] + left[2][0] * right[0][2],
			left[0][1] * right[0][0] + left[1][1] * right[0][1] + left[2][1] * right[0][2],

			left[0][0] * right[1][0] + left[1][0] * right[1][1] + left[2][0] * right[1][2],
			left[0][1] * right[1][0] + left[1][1] * right[1][1] + left[2][1] * right[1][2],
			
			left[0][0] * right[2][0] + left[1][0] * right[2][1] + left[2][0] * right[2][2],
			left[0][1] * right[2][0] + left[1][1] * right[2][1] + left[2][1] * right[2][2],
			
		);

}


template <typename T>
inline Mat2x3<T> operator* (const Mat3x3<T>& left, const Mat2x3<T>& right )
{
	return new Mat3x2<T>
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
inline Mat3x3<T> operator* (const Mat3x3<T>& left, const Mat3x3<T>& right)
{
	return new Mat3x3<T>
		(
			left[0][0] * right[0][0] + left[1][0] * right[0][1] + left[2][0] * right[0][2],
			left[0][1] * right[0][0] + left[1][1] * right[0][1] + left[2][1] * right[0][2],
			left[0][2] * right[0][0] + left[1][2] * right[0][1] + left[2][2] * right[0][2],

			left[0][0] * right[1][0] + left[1][0] * right[1][1] + left[2][0] * right[1][2],
			left[0][1] * right[1][0] + left[1][1] * right[1][1] + left[2][1] * right[1][2],
			left[0][2] * right[1][0] + left[1][2] * right[1][1] + left[2][2] * right[1][2],

			left[0][0] * right[2][0] + left[1][0] * right[2][1] + left[2][0] * right[2][2],
			left[0][1] * right[2][0] + left[1][1] * right[2][1] + left[2][1] * right[2][2],
			left[0][2] * right[2][0] + left[1][2] * right[2][1] + left[2][2] * right[2][2],
		);

}


template <typename T>
inline Vec3<T> operator* (const Mat3x3<T>& left, const Vec3<T>& right)
{
	return new Vec3<T>
		(
			left[0][0] * right.x + left[1][0] * right.y + left[2][0] * right.z,
			left[0][1] * right.x + left[1][1] * right.y + left[2][1] * right.z,
			left[0][2] * right.x + left[1][2] * right.y + left[2][2] * right.z
		);

}


template <typename T>
inline Vec3<T> operator* (const Vec3<T>& left, const Mat3x3<T>& right)
{
	return new Vec3 <T>
		(
			right[0][0] * left.x + right[0][1] * left.y + right[2][0] * left.z,
			right[1][0] * left.x + right[1][1] * left.y + right[2][1] * left.z,
			right[2][0] * left.x + right[2][1] * left.y + right[2][2] * left.z
		);

}


