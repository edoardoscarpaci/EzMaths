#pragma once
#include <cmath>
template <typename T>

class Vec2
{
public:
	Vec2(T x, T y):x(x), y(y) 
	{

	};

	Vec2(const &Vec2 v)
	{
		x = v.x;
		y = v.y;

	};

	~Vec2() 
	{

	};
	
	Vec2<T>& operator+=(const Vec2<T>& right)
	{
		this.x += right.x;
		this.y += right.y;
		return *this;
	};

	Vec2<T>& operator-=(const Vec2<T>& right)
	{
		this.x -= right.x;
		this.y -= right.y;
		return *this;
	};

	Vec2<T>& operator*=(const Vec2<T>& right)
	{
		this.x *= right.x;
		this.y *= right.y;
		return *this;
	};

	Vec2<T>& operator/=(const Vec2<T>& right)
	{
		this.x /= right.x;
		this.y /= right.y;
		return *this;
	}

	Vec2<T>& operator*=(const float& right)
	{
		this.x *= right;
		this.y *= right;
		return *this;
	}

	Vec2<T>& operator/=(const float& right)
	{
		this.x /= right;
		this.y /= right;
		return *this;
	}

	Vec2<T>& operator=(const Vec2<T>& right) 
	{
		this.x = right.x;
		this.y = right.y;
		return *this;

	}

	T operator[](unsigned int index) 
	{
		if(index > getDimension())
			//error
		return value[index]


	}
	
	
	unsigned int getDimension() 
	{
		return 2;
	}

	T dot(const Vec2<T>& right) 
	{
		return (this.x * right.x + this.y * right.y);
	}

	void reverse() 
	{
		this.x = this.y;
		this.y = this.x;
	}

	float magnitude() 
	{
		return sqrtf(x * x + y * y);
	}
	
	float angleBetween(const Vec2<T>& right)
	{
		return acosf(dot(right) / lenght()*right.lenght());
	}


	static Vec2<T>& Zero()
	{
		return new Vec2(0, 0);
	}

	
	static Vec2<T>& Up()
	{
		return new Vec2(0, 1);
	}

	static Vec2<T>& forward()
	{
		return new Vec2(1, 0);
	}


public:
	T value[2];
	union 
	{
		struct 
		{
			T x;
			T y;
		};

		struct 
		{
			T r;
			T g;
		};
		
	};
	

};



template <typename T>
bool operator==(const Vec2<T>& left,const Vec2<T>& right)
{
	return left.x == right.x && left.y == right.y;
}

template <typename T>
bool operator!=(const Vec2<T>& left, const Vec2<T>& right)
{
	return !(left==right);

}

template <typename T>
inline Vec2<T> operator+(Vec2<T> right,const Vec2<T>& left) 
{
	right += left;
	return right;
}

template <typename T>
inline Vec2<T> operator-(Vec2<T> right, const Vec2<T>& left)
{
	right -= left;
	return right;
}

template <typename T>
inline Vec2<T> operator*(Vec2<T> right, const Vec2<T>& left)
{
	right *= left;
	return right;
}

template <typename T>
inline Vec2<T> operator/(Vec2<T> right, const Vec2<T>& left)
{
	right /= left;
	return right;
}

template <typename T>
inline Vec2<T> operator*(Vec2<T> right, const float& left)
{
	right *= left;
	return right;
}

template <typename T>
inline Vec2<T> operator/(Vec2<T> right, const float& left)
{
	right /= left;
	return right;
}

template <typename T>
inline static T dot(const Vec2<T>& right, const Vec2<T>& left)
{
	return right.dot(left);
}

template <typename T>
inline static float Normalize(const Vec2<T>& right)
{
	return right.magnitude();
}


template <typename T>
inline static float angleBetween2Vector(const Vec2<T>& right, const Vec2<T>& left)
{
	return right.angleBetween(left);
}






