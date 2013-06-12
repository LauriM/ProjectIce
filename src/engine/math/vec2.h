#ifndef ENGINE_MATH_VEC2_H
#define ENGINE_MATH_VEC2_H

class vec2 {
	public:
		int x;
		int y;

		vec2(){
			x = 0;
			y = 0;
		}

		vec2(int newX, int newY){
			x = newX;
			y = newY;
		}
};

#endif
