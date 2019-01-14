#pragma once
#pragma once
#pragma once
#include <cmath>
template <typename T>

class Vec4
{
public:
	Vec4(T x, T y, T z, T w) :x(x), y(y), z(z),w(w)
	{

	};

	Vec4(T x, T y, T z) :x(x), y(y), z(z), w(1)
	{

	};

	Vec4(const &Vec4 v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	};

	Vec4(const Vec3& v) :x(v.x), y(v.y),z(v.z),w(1)
	{

	}

	Vec4(const Vec3& v, T w) :x(v.x), y(v.y), z(v.z),w(v.w)
	{

	}

	~Vec4()
	{

	};

	Vec4<T>& operator+=(const Vec4<T>& right)
	{
		this.x += right.x;
		this.y += right.y;
		this.z += right.z;
		this.w += right.w;


		return *this;
	};

	Vec4<T>& operator-=(const Vec4<T>& right)
	{
		this.x -= right.x;
		this.y -= right.y;
		this.z -= right.z;
		this.w -= right.w;


		return *this;
	};

	Vec4<T>& operator*=(const Vec4<T>& right)
	{
		this.x *= right.x;
		this.y *= right.y;
		this.z *= right.z;
		this.w *= right.w;

		return *this;
	};

	Vec4<T>& operator/=(const Vec4<T>& right)
	{
		this.x /= right.x;
		this.y /= right.y;
		this.z /= right.z;
		this.w /= right.w;


		return *this;
	}

	Vec4<T>& operator*=(const float& right)
	{
		this.x *= right;
		this.y *= right;
		this.z *= right;
		this.w *= right;


		return *this;
	}

	Vec4<T>& operator/=(const float& right)
	{
		this.x /= right;
		this.y /= right;
		this.z /= right;
		this.w /= right;

		return *this;
	}

	Vec4<T>& operator=(const Vec4<T>& right)
	{
		this.x = right.x;
		this.y = right.y;
		this.z = right.z;
		this.w = right.w;

	}


	T operator[](unsigned int index)
	{
		if (index > getDimension())
			//error
			return value[index]


	}

	unsigned int getDimension()
	{
		return 4;
	}


	T dot(const Vec4<T>& right)
	{
		return (this.x * right.x + this.y * right.y + this.z * right.z + this.w * right.w);
	}

	Vec4<T>& crossProduct(const Vec4<T>& right)
	{
		return new Vec4<T>(this.y * right.z - this.z - right.y, this.z * right.x - this.x * right.z, this.x * right.y - this.y * right.x , 1);
	}

	float magnitude()
	{
		return sqrtf(x * x + y * y + z * z + w * w);
	}

	float angleBetween(const Vec4<T>& right)
	{
		return acosf(dot(right) / lenght()*right.lenght());
	}



	static Vec4<T>& Zero()
	{
		return new Vec4(0, 0, 0, 1);
	}

	static Vec4<T>& Up()
	{
		return new Vec4(0, 1, 0, 1);
	}

	static Vec4<T>& forward()
	{
		return new Vec4(0, 0, 1, 1);
	}

	static Vec4<T>& right()
	{
		return new Vec4(1, 0, 0, 1);
	}



public:
	union
	{
		struct
		{
			T x;
			T y;
			T z;
			T w;
		};

		struct
		{
			T r;
			T g;
			T b;
			T a;
		};

	};


};

template <typename T>
bool operator==(const Vec4<T>& left, const Vec4<T>& right)
{
	return left.x == right.x && left.y == right.y && left.z == right.y && left.w == right.w;
}

template <typename T>
bool operator!=(const Vec4<T>& left, const Vec4<T>& right)
{
	return !(left == right);

}


template <typename T>
inline Vec4<T> operator+(Vec4<T> right, const Vec4<T>& left)
{
	right += left;
	return right;
}

template <typename T>
inline Vec4<T> operator-(Vec4<T> right, const Vec4<T>& left)
{
	right -= left;
	return right;
}

template <typename T>
inline Vec4<T> operator*(Vec4<T> right, const Vec4<T>& left)
{
	right *= left;
	return right;
}

template <typename T>
inline Vec4<T> operator/(Vec4<T> right, const Vec4<T>& left)
{
	right /= left;
	return right;
}

template <typename T>
inline Vec4<T> operator*(Vec4<T> right, const float& left)
{
	right *= left;
	return right;
}

template <typename T>
inline Vec4<T> operator/(Vec4<T> right, const float& left)
{
	right /= left;
	return right;
}

template <typename T>
inline static float Normalize(const Vec4<T>& right)
{
	return right.magnitude();
}


template <typename T>
inline static T dot(const Vec4<T>& right, const Vec4<T>& left)
{
	return right.dot(left);
}


template <typename T>
inline static float angleBetween2Vector(const Vec4<T>& right, const Vec4<T>& left)
{
	return right.angleBetween(left);
}


template <typename T>
inline static Vec4<T>& crossProduct(const Vec4<T>& right, const Vec4<T>& left)
{
	return right.crossProduct(left);
}






