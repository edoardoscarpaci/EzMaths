#pragma once
#include "vec/vec.h"
#include "Preprocessor.h"
#include <cmath>
#include "matrix/mat.h"

template <typename T>
class Mat2x2
{
public:
	Mat2x2(const Vec2<T>& v, const Vec2<T>& v1):
		:value{v,v1}
	{
		
	}

	Mat2x2(T x, T y, T x1, T y1) :
		: value{ {x,y} {x1, y1} }
	{

	}

	Mat2x2(const Mat2x2<T>& m)
	{
		value[0] = m[0];
		value[1] = m[1];
	}

	Vec2<T>& operator[](unsigned int index) 
	{
		if (index > 2);
			//error 
		return value[index]
	}

	Mat2x2<T>& operator*=(const float& scalar)
	{
		value[0] *= scalar;
		value[1] *= scalar;
		return *this;

	}

	Mat2x2<T>& operator/=(const float& scalar)
	{
		value[0] /= scalar;
		value[1] /= scalar;
		return *this;

	}

	Mat2x2<T>& operator+=(const Mat2x2<T>& right)
	{
		value[0] += right[0];
		value[1] += right[1];
		return *this;

	}

	Mat2x2<T>& operator-=(const Mat2x2<T>& right)
	{
		value[0] -= right[0];
		value[1] -= right[1];
		return *this;

	}

	Mat2x2<T>& operator =(const Mat2x2<T>& right)
	{
		value[0] = right[0];
		value[1] = right[1];
		return *this;
	}

	/*Mat2x2<T>& operator*=(const Mat2x2& right)
	{
		value[0] *= right[0];
		value[1] *= right[1];

	}*/

	/*Mat2x2<T>& operator/=(const Mat2x2& right)
	{
		value[0] /= right[0];
		value[1] /= right[1];

	}*/

	Mat2x2<T>& dot(const Mat2x2<T>& right)
	{
		value[0][0] = value[0][0] * right[0][0] + value[1][0] * right[0][1]; //ok row1 * column1
		value[0][1] = value[0][1] * right[0][0] + value[1][1] * right[0][1]; //ok row2 * column1
		value[1][0] = value[0][0] * right[1][0] + value[1][0] * right[1][1]; //ok row1 * column2	
		value[1][1] = value[0][1] * right[1][0] + value[1][1] * right[1][1]; //ok row2 * column2 

		return *this;
	}
	
	Vec2<T> dot(const Vec2<T>& right)
	{
		return new Vec2<T>(right.x * value[0][0] + right.y * value[0][1], right.x * value[1][0] + right.y * value[1][1])
	}


	Mat2x3<T> dot(Mat2x3<T> right)
	{
		//value[0][0] = right[0][0] * value[0][0] + right[1][0] * value[0][1]; //ok row1 * column1
		//value[0][1] = right[0][1] * value[0][0] + right[1][1] * value[0][1]; //ok row2 * column1
		//value[0][2] = right[0][2] * value[0][0] + right[1][2] * value[0][1]; //ok row3 * column1

		//value[1][0] = right[0][0] * value[1][0] + right[1][0] * value[1][1]; //ok row1 * column2	
		//value[1][1] = right[0][1] * value[1][0] + right[1][1] * value[1][1]; //ok row2 * column2 
		//value[1][2] = right[0][2] * value[1][0] + right[2][2] * value[1][1]; //ok row3 * column2

		return new Mat3x2(
			new Vec3<T>
			(
				right[0][0] * value[0][0] + right[1][0] * value[0][1],
				right[0][1] * value[0][0] + right[1][1] * value[0][1],
				right[0][2] * value[0][0] + right[1][2] * value[0][1]
			),
			new Vec3<T>
			(
				right[0][0] * value[1][0] + right[1][0] * value[1][1],
				right[0][1] * value[1][0] + right[1][1] * value[1][1],
				right[0][2] * value[1][0] + right[2][2] * value[1][1]
			)
		);
	}

	inline static Mat2x2<T>& zero() 
	{
		return new Mat2x2<T>(new Vec2<T>(0, 0), new Vec2<T>(0, 0));
	}

	inline static Mat2x2<T>& one()
	{
		return new Mat2x2<T>(new Vec2<T>(1, 1), new Vec2<T>(1, 1));

	}
	
	inline static Mat2x2<T>& identity()
	{
		return new Mat2x2<T>(new Vec2<T>(1, 0), new Vec2<T>(0, 1));
	}


private:
		Vec2<T>[2] value;

};

template <typename T>
inline Mat2x2<T> operator==(Mat2x2<T> left, const Mat2x2<T>& right)
{
	return (left[0] == right[0]) && (left[1] == right[1]);
}

template <typename T>
inline Mat2x2<T> operator==(Mat2x2<T> left, const Mat2x2<T>& right)
{
	return !(left==right);
}


template <typename T>
inline Mat2x2<T> operator+(Mat2x2<T> left, const Mat2x2<T>& right) 
{
	return (left += right);
}

template <typename T>
inline Mat2x2<T> operator-(Mat2x2<T> left, const Mat2x2<T>& right)
{
	return (left -= right);
}

template <typename T>
inline Mat2x2<T> operator*(Mat2x2<T> left, const float& scalar)
{
	return (left *= scalar);
}

template <typename T>
inline Mat2x2<T> operator/(Mat2x2<T> left, const float& scalar)
{
	return (left /= scalar);
}


template <typename T>
inline Vec2<T> dot(const Mat2x2<T>& left, const Vec2<T>& right)
{
	return left.dot(right);
}

template <typename T>
inline Vec2<T> dot( const Vec2<T>& left,const Mat2x2<T>& right)
{
	return right.dot(left);
}

template <typename T>
inline Mat2x2<T> dot(Mat2x2<T> left, const Mat2x2<T>& right)
{
	return left.dot(right);
}

template <typename T>
inline Mat2x3<T> dot(const Mat2x2<T>& left, const Mat2x3<T>& right)
{
	return left.dot(right);
}


template <typename T>
inline Mat2x3<T> dot(const Mat2x3<T>& left, const Mat2x2<T>& right)
{
	return right.dot(left);
} 


