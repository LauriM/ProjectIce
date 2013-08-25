#include "precompiled.h"

#include "engine/math/vec2.h"

vec2::vec2() {
    x = 0;
    y = 0;
}

vec2::vec2(const int newX, const int newY) {
    x = newX;
    y = newY;
}

vec2::vec2(const vec2& vec) {
    x = vec.x;
    y = vec.y;
}

vec2& vec2::operator+=(const vec2 &rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

vec2& vec2::operator-=(const vec2 &rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

vec2& vec2::operator*=(int rhs) {
    this->x *= rhs;
    this->y *= rhs;
    return *this;
}

vec2& vec2::operator/=(int rhs) {
    this->x /= rhs;
    this->y /= rhs;
    return *this;
}

bool vec2::operator==(const vec2 &rhs) {
    return this->x == rhs.x && this->y == rhs.y;
}

bool vec2::operator!=(const vec2 &rhs) {
	return this->x != rhs.x || this->y != rhs.y;
}

vec2 vec2::operator+(const vec2 &rhs) {
    return vec2(*this) += rhs;
}

vec2 vec2::operator-(const vec2 &rhs) {
    return vec2(*this) -= rhs;
}

vec2 vec2::operator*(int rhs) {
    return vec2(*this) *= rhs;
}

vec2 vec2::operator/(int rhs) {
    return vec2(*this) /= rhs;
}

int vec2::operator*(const vec2 &rhs) {
    return this->x * rhs.x + this->y * rhs.y;
}

double vec2::distance() const {
    double xSqrd = pow( x, 2.0 );
    double ySqrd = pow( y, 2.0 );
    double distance = sqrt( xSqrd + ySqrd );
    return distance;    
}

bool vec2::operator < (const vec2 & rhs) const {
    double leftDistance = distance();
    double rightDistance = rhs.distance();
    if ( leftDistance < rightDistance ) {
        return true;
    }    
    else {
        return false;
    }
}

bool vec2::operator > (const vec2 & rhs) const {
    double leftDistance = distance();
    double rightDistance = rhs.distance();
    if ( leftDistance > rightDistance ) {
        return true;
    }    
    else {
        return false;
    }
}