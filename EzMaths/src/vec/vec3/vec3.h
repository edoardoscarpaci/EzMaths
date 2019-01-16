#pragma once
#pragma once
#include <cmath>
template <typename T>

class Vec3
{
public:
	Vec3(T x, T y, T z) :x(x), y(y),z(z)
	{

	};

	Vec3(const &Vec3 v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

	};

	Vec3(const Vec2& v):x(v.x),y(v.y),z(0)
	{
	
	}

	Vec3(const Vec2& v, T z) :x(v.x), y(v.y), z(z)
	{

	}

	~Vec3()
	{

	};
 
	Vec3<T>& operator+=(const Vec3<T>& right)
	{
		this.x += right.x;
		this.y += right.y;
		this.z += right.z;

		return *this;
	};

	Vec3<T>& operator-=(const Vec3<T>& right)
	{
		this.x -= right.x;
		this.y -= right.y;
		this.z -= right.z;

		return *this;
	};

	Vec3<T>& operator*=(const Vec3<T>& right)
	{
		this.x *= right.x;
		this.y *= right.y;
		this.z *= right.z;

		return *this;
	};

	Vec3<T>& operator/=(const Vec3<T>& right)
	{
		this.x /= right.x;
		this.y /= right.y;
		this.z /= right.z;

		return *this;
	}

	Vec3<T>& operator*=(const float& right)
	{
		this.x *= right;
		this.y *= right;
		this.z *= right;

		return *this;
	}

	Vec3<T>& operator/=(const float& right)
	{
		this.x /= right;
		this.y /= right;
		this.z /= right;

		return *this;
	}

	Vec3<T>& operator=(const Vec3<T>& right)
	{
		this.x = right.x;
		this.y = right.y;
		this.z = right.z;
		return *this;

	}

	T dot(const Vec3<T>& right)
	{
		return (this.x * right.x + this.y * right.y + this.z * right.z);
	}

	Vec3<T>& crossProduct(const Vec3<T>& right) 
	{
		this.x = this.y * right.z - this.z - right.y;
		this.y = this.z * right.x - this.x * right.z;
		this.z = this.x * right.y - this.y * right.x;
		return *this;
		//return new Vec3<T>(this.y * right.z - this.z - right.y, this.z * right.x - this.x * right.z, this.x * right.y - this.y * right.x);
	}

	float magnitude()
	{
		return sqrtf(x * x + y * y + z * z);
	}

	float angleBetween(const Vec3<T>& right)
	{
		return acosf(dot(right) / lenght()*right.lenght());
	}


	T operator[](unsigned int index)
	{
		if (index > getDimension())
			//error
			return value[index]


	}


	unsigned int getDimension()
	{
		return 3;
	}

	static Vec3<T> Zero()
	{
		return new Vec3<T>(0, 0, 0);
	}

	static Vec3<T> Up()
	{
		return new Vec3<T>(0, 1, 0);
	}

	static Vec3<T> forward()
	{
		return new Vec3<T>(0, 0 ,1);
	}

	static Vec3<T> right() 
	{
		return new Vec3<T>(1, 0, 0);
	}



public:
	union
	{
		struct
		{
			T x;
			T y;
			T z;
		};

		struct
		{
			T r;
			T g;
			T b;
		};

	};


};


template <typename T>
bool operator==(const Vec3<T>& left, const Vec3<T>& right)
{
	return left.x == right.x && left.y == right.y && left.z == right.z;
}

template <typename T>
bool operator!=(const Vec3<T>& left, const Vec3<T>& right)
{
	return !(left == right);

}

template <typename T>
inline Vec3<T> operator+(Vec3<T> right, const Vec3<T>& left)
{
	right += left;
	return right;
}

template <typename T>
inline Vec3<T> operator-(Vec3<T> right, const Vec3<T>& left)
{
	right -= left;
	return right;
}

template <typename T>
inline Vec3<T> operator*(Vec3<T> right, const Vec3<T>& left)
{
	right *= left;
	return right;
}

template <typename T>
inline Vec3<T> operator/(Vec3<T> right, const Vec3<T>& left)
{
	right /= left;
	return right;
}

template <typename T>
inline Vec3<T> operator*(Vec3<T> right, const float& left)
{
	right *= left;
	return right;
}

template <typename T>
inline Vec3<T> operator/(Vec3<T> right, const float& left)
{
	right /= left;
	return right;
}

template <typename T>
inline static float Normalize(const Vec3<T>& right)
{
	return right.magnitude();
}


template <typename T>
inline static T dot(const Vec3<T>& right, const Vec3<T>& left)
{
	return right.dot(left);
}


template <typename T>
inline static float angleBetween2Vector(const Vec3<T>& right, const Vec3<T>& left)
{
	return right.angleBetween(left);
}


template <typename T>
inline Vec3<T> crossProduct(Vec3<T> right, const Vec3<T>& left)
{
	return right.crossProduct(left);
}






