#ifndef ENGINE_MATH_VEC2_H
#define ENGINE_MATH_VEC2_H

class vec2 {
	public:
		int x;
		int y;

		vec2();
		vec2(const int newX, const int newY);
		vec2(const vec2& vec);

		vec2  operator+(const vec2 &rhs);
		vec2  operator-(const vec2 &rhs);
		int   operator*(const vec2 &rhs);
		bool  operator==(const vec2 &rhs);
		vec2  operator*(int rhs);
		vec2  operator/(int rhs);

		vec2& operator+=(const vec2 &rhs);
		vec2& operator-=(const vec2 &rhs);
		vec2& operator*=(int rhs);
		vec2& operator/=(int rhs);
};

#endif
