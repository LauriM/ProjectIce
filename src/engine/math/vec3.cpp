#include "vec3.h"

bool vec3::operator ==(const vec3 &vec) {
	return vec.x == x && vec.y == y && vec.z == z;
}
