#include "vec3.h"

bool vec3::operator==(const vec3 &vec){
	if(vec.x == x && vec.y == y && vec.z == z){
		return true;
	}else{
		return false;
	}
}