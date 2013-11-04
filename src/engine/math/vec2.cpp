#include "precompiled.h"

#include "engine/math/vec2.h"

#include "engine/math/random.h"

vec2::vec2()
	: x(0)
	, y(0)
{ }

vec2::vec2(const int newX, const int newY)
	: x(newX)
	, y(newY)
{ }

vec2::vec2(const vec2& vec)
	: x(vec.x)
	, y(vec.y)
{ }

vec2& vec2::operator +=(const vec2 &rhs) {
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

vec2& vec2::operator -=(const vec2 &rhs) {
	this->x -= rhs.x;
	this->y -= rhs.y;
	return *this;
}

vec2& vec2::operator *=(int rhs) {
	this->x *= rhs;
	this->y *= rhs;
	return *this;
}

vec2& vec2::operator /=(int rhs) {
	this->x /= rhs;
	this->y /= rhs;
	return *this;
}

bool vec2::operator ==(const vec2 &rhs) {
	return this->x == rhs.x && this->y == rhs.y;
}

bool vec2::operator !=(const vec2 &rhs) {
	return this->x != rhs.x || this->y != rhs.y;
}

vec2 vec2::operator +(const vec2 &rhs) {
	return vec2(*this) += rhs;
}

vec2 vec2::operator -(const vec2 &rhs) {
	return vec2(*this) -= rhs;
}

vec2 vec2::operator *(int rhs) {
	return vec2(*this) *= rhs;
}

vec2 vec2::operator /(int rhs) {
	return vec2(*this) /= rhs;
}

int vec2::operator *(const vec2 &rhs) {
	return this->x * rhs.x + this->y * rhs.y;
}

int vec2::lengthSquared() const {
	return x * x + y * y;
}

double vec2::length() const {
	return sqrt((double) lengthSquared());
}

bool vec2::operator <(const vec2 & rhs) const {
	return lengthSquared() < rhs.lengthSquared();
}

bool vec2::operator >(const vec2 & rhs) const {
	return lengthSquared() > rhs.lengthSquared();
}

/**
 * set vector to random n / s / e / w direction with speed 1
 */
void vec2::randomNSWE() {
	switch(randomRange(0,3)){
	case 0:
		x = 1; y = 0;
		break;
	case 1:
		x = -1; y = 0;
		break;
	case 2:
		x = 0; y = -1;
		break;
	case 3:
		x = 0; y = 1;
		break;
	default:
		x = 1; y = 0;
		break;
	}
}
