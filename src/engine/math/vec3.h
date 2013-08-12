#ifndef ENGINE_MATH_VEC3_H
#define ENGINE_MATH_VEC3_H

class vec3 {
	public:
		int x;
		int y;
		int z;

		vec3(){
			x = 0;
			y = 0;
			z = 0;
		}

		vec3(int newX, int newY,int newZ){
			x = newX;
			y = newY;
			z = newZ;
		}

		bool operator==(vec3 &vec){
			if(vec.x == x && vec.y == y && vec.z == z){
				return true;
			}else{
				return false;
			}
		}
};

#endif
