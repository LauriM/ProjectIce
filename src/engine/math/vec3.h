#ifndef ENGINE_MATH_VEC3_H
#define ENGINE_MATH_VEC3_H

class vec3 {
	public:
		int x;
		int y;
		int z;

		vec3()
			:x(0)
			,y(0)
			,z(0)
		{ }

		vec3(int x, int y,int z)
			:x(x)
			,y(y)
			,z(z)
		{ }

		bool operator ==(const vec3 &vec);
};

#endif
