/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        Atom3D/AtomVector.cpp
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#include "AtomVector.h"
#include "AtomMatrix.h"
#include "AtomQuat.h"

#include "../AtomUtils.h"
#include "../AtomCAPI.h"

#include <cmath>

#define DefineVector2Method(returnType, method, constState, code) \
returnType method(const AtomPoint& v) constState { \
	AtomPoint bx = v; \
	AtomPoint by = v; \
	code \
} \
returnType method(const AtomPoint& vx, const AtomPoint& vy) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, const AtomPoint& vw) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	code \
} \
\
returnType method(const AtomVector2& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	code \
} \
\
returnType method(const AtomVector3& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	code \
} \
\
returnType method(const AtomVector4& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	code \
}

#define DefineVector3Method(returnType, method, constState, code) \
returnType method(const AtomPoint& v) constState { \
	AtomPoint bx = v; \
	AtomPoint by = v; \
	AtomPoint bz = v; \
	code \
} \
returnType method(const AtomPoint& vx, const AtomPoint& vy) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = 0.0f; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = vz; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, const AtomPoint& vw) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = vz; \
	code \
} \
\
returnType method(const AtomVector2& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = 0.0f; \
	code \
} \
\
returnType method(const AtomVector3& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	code \
} \
\
returnType method(const AtomVector4& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	code \
}

#define DefineVector4Method(returnType, method, constState, code) \
returnType method(const AtomPoint& v) constState { \
	AtomPoint bx = v; \
	AtomPoint by = v; \
	AtomPoint bz = v; \
	AtomPoint bw = v; \
	code \
} \
returnType method(const AtomPoint& vx, const AtomPoint& vy) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = 0.0f; \
	AtomPoint bw = 0.0f; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = vz; \
	AtomPoint bw = 0.0f; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, const AtomPoint& vw) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = vz; \
	AtomPoint bw = bw; \
	code \
} \
\
returnType method(const AtomVector2& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = 0.0f; \
	AtomPoint bw = 0.0f; \
	code \
} \
\
returnType method(const AtomVector3& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	AtomPoint bw = 0.0f; \
	code \
} \
\
returnType method(const AtomVector4& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	AtomPoint bw = v.w; \
	code \
}

#define DefineVector2MethodArgs(returnType, method, constState, code, ...) \
returnType method(const AtomPoint& v, __VA_ARGS__) constState { \
	AtomPoint bx = v; \
	AtomPoint by = v; \
	code \
} \
returnType method(const AtomPoint& vx, const AtomPoint& vy, __VA_ARGS__) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, __VA_ARGS__) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, const AtomPoint& vw, __VA_ARGS__) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	code \
} \
\
returnType method(const AtomVector2& v, __VA_ARGS__) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	code \
} \
\
returnType method(const AtomVector3& v, __VA_ARGS__) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	code \
} \
\
returnType method(const AtomVector4& v, __VA_ARGS__) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	code \
}

#define DefineVector3MethodArgs(returnType, method, constState, code, ...) \
returnType method(const AtomPoint& v, __VA_ARGS__) constState { \
	AtomPoint bx = v; \
	AtomPoint by = v; \
	AtomPoint bz = v; \
	code \
} \
returnType method(const AtomPoint& vx, const AtomPoint& vy, __VA_ARGS__) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = 0.0f; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, __VA_ARGS__) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = vz; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, const AtomPoint& vw, __VA_ARGS__) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = vz; \
	code \
} \
\
returnType method(const AtomVector2& v, __VA_ARGS__) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = 0.0f; \
	code \
} \
\
returnType method(const AtomVector3& v, __VA_ARGS__) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	code \
} \
\
returnType method(const AtomVector4& v, __VA_ARGS__) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	code \
}

#define DefineVector4MethodArgs(returnType, method, constState, code, ...) \
returnType method(const AtomPoint& v, __VA_ARGS__) constState { \
	AtomPoint bx = v; \
	AtomPoint by = v; \
	AtomPoint bz = v; \
	AtomPoint bw = v; \
	code \
} \
returnType method(const AtomPoint& vx, const AtomPoint& vy, __VA_ARGS__) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = 0.0f; \
	AtomPoint bw = 0.0f; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, __VA_ARGS__) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = vz; \
	AtomPoint bw = 0.0f; \
	code \
} \
\
returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, const AtomPoint& vw, __VA_ARGS__) constState { \
	AtomPoint bx = vx; \
	AtomPoint by = vy; \
	AtomPoint bz = vz; \
	AtomPoint bw = vw; \
	code \
} \
\
returnType method(const AtomVector2& v, __VA_ARGS__) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = 0.0f; \
	AtomPoint bw = 0.0f; \
	code \
} \
\
returnType method(const AtomVector3& v, __VA_ARGS__) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	AtomPoint bw = 0.0f; \
	code \
} \
\
returnType method(const AtomVector4& v, __VA_ARGS__) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	AtomPoint bw = v.w; \
	code \
}

#define DefineVector2OperatorMethod(returnType, method, constState, code) \
returnType method(const AtomPoint& v) constState { \
	AtomPoint bx = v; \
	AtomPoint by = v; \
	code \
} \
\
returnType method(const AtomVector2& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	code \
} \
\
returnType method(const AtomVector3& v) constState { \
 	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	code \
} \
\
returnType method(const AtomVector4& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	code \
}

#define DefineVector3OperatorMethod(returnType, method, constState, code) \
returnType method(const AtomPoint& v) constState { \
	AtomPoint bx = v; \
	AtomPoint by = v; \
	AtomPoint bz = v; \
	code \
} \
\
returnType method(const AtomVector2& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = 0.0f; \
	code \
} \
\
returnType method(const AtomVector3& v) constState { \
 	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	code \
} \
\
returnType method(const AtomVector4& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	code \
}

#define DefineVector4OperatorMethod(returnType, method, constState, code) \
returnType method(const AtomPoint& v) constState { \
	AtomPoint bx = v; \
	AtomPoint by = v; \
	AtomPoint bz = v; \
	AtomPoint bw = v; \
	code \
} \
\
returnType method(const AtomVector2& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = 0.0f; \
	AtomPoint bw = 0.0f; \
	code \
} \
\
returnType method(const AtomVector3& v) constState { \
 	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	AtomPoint bw = 0.0f; \
	code \
} \
\
returnType method(const AtomVector4& v) constState { \
	AtomPoint bx = v.x; \
	AtomPoint by = v.y; \
	AtomPoint bz = v.z; \
	AtomPoint bw = v.w; \
	code \
}

AtomVector2::AtomVector2() {
	x = 0.0f;
	y = 0.0f;
}

DefineVector2Method(, AtomVector2::AtomVector2, , {
	x = bx;
	y = by;
});

AtomVector2 AtomVector2::Clone() const {
	AtomVector2 v;
	v.x = x;
	v.y = y;

	return v;
}

void AtomVector2::Copy(AtomVector2* v) const {
	if (!v) {
		return;
	}

	v->x = x;
	v->y = y;
}

void AtomVector2::Copy(AtomVector3* v) const {
	if (!v) {
		return;
	}

	v->x = x;
	v->y = y;
}

void AtomVector2::Copy(AtomVector4* v) const {
	if (!v) {
		return;
	}

	v->x = x;
	v->y = y;
}

DefineVector2Method(void, AtomVector2::Set, , {
	x = bx;
	y = by;
});

DefineVector2Method(void, AtomVector2::Add, , {
	x += bx;
	y += by;
});

DefineVector2Method(void, AtomVector2::Subtract, , {
	x -= bx;
	y -= by;
});

DefineVector2Method(void, AtomVector2::Multiply, , {
	x *= bx;
	y *= by;
});

DefineVector2Method(void, AtomVector2::Divide, , {
	x /= bx;
	y /= by;
});

DefineVector2Method(void, AtomVector2::Modulo, , {
	x = atom_mod_number(x, bx);
	y = atom_mod_number(y, by);
});

DefineVector2Method(void, AtomVector2::Min, , {
	x = std::min(x, bx);
	y = std::min(y, by);
});

DefineVector2Method(void, AtomVector2::Max, , {
	x = std::max(x, bx);
	y = std::max(y, by);
});

DefineVector2Method(void, AtomVector2::Scale, , {
	x *= bx;
	y *= by;
});

DefineVector2MethodArgs(void, AtomVector2::ScaleAndAdd, , {
	x += bx * scale;
	y += by * scale;
}, const AtomPoint& scale);

DefineVector2Method(void, AtomVector2::Pow, , {
	x = std::pow(x, bx);
	y = std::pow(y, by);
});

void AtomVector2::Ceil() {
	x = std::ceil(x);
	y = std::ceil(y);
}

void AtomVector2::Floor() {
	x = std::floor(x);
	y = std::floor(y);
}

void AtomVector2::Round() {
	x = ::Round(x);
	y = ::Round(y);
}

DefineVector2Method(AtomPoint, AtomVector2::Distance, const, {
	AtomPoint nx = bx - x;
	AtomPoint ny = by - y;

	return std::sqrt(nx * nx + ny * ny);
});

DefineVector2Method(AtomPoint, AtomVector2::SquaredDistance, const, {
	AtomPoint nx = bx - x;
	AtomPoint ny = by - y;

	return nx * nx + ny * ny;
});

AtomPoint AtomVector2::Length() const {
	return std::sqrt(x * x + y * y);
}

AtomPoint AtomVector2::SquaredLength() const {
	return x * x + y * y;
}

void AtomVector2::Negate() {
	x = -x;
	y = -y;
}

void AtomVector2::Inverse() {
	x = 1.0f / x;
	y = 1.0f / y;
}

void AtomVector2::Normalize() {
	AtomPoint len = x * x + y * y;

	if (len > 0.0f) {
		len = 1.0f / std::sqrt(len);
	}

	x *= len;
	y *= len;
}

DefineVector2Method(AtomPoint, AtomVector2::Dot, const, {
	return x * bx + y * by;
});

DefineVector2MethodArgs(void, AtomVector2::Lerp, , {
	x = x + t * (bx - x);
	y = y + t * (by - y);
}, const AtomPoint& t);

void AtomVector2::Random(AtomPoint scale) {
	AtomPoint rad = ::Random() * 2.0f * M_PI;

	x = std::cos(rad) * scale;
	y = std::sin(rad) * scale;
}

void AtomVector2::Zero() {
	x = 0.0f;
	y = 0.0f;
}

DefineVector2Method(bool, AtomVector2::ExactEquals, const, {
	return x == bx && y == by;
});

DefineVector2Method(bool, AtomVector2::Equals, const, {
	return (
		std::abs(x - bx) <= ATOM_EPSILON * std::max(std::max(std::abs(x), std::abs(bx)), 1.0f) && // must check and compare with javascript
		std::abs(y - by) <= ATOM_EPSILON * std::max(std::max(std::abs(y), std::abs(by)), 1.0f)
	);
});

DefineVector2OperatorMethod(AtomVector2, AtomVector2::operator+, const, {
	AtomVector2 out;
	
	out.x = x + bx;
	out.y = y + by;

	return out;
});

DefineVector2OperatorMethod(AtomVector2, AtomVector2::operator-, const, {
	AtomVector2 out;
	
	out.x = x - bx;
	out.y = y - by;

	return out;
});

DefineVector2OperatorMethod(AtomVector2, AtomVector2::operator*, const, {
	AtomVector2 out;

	out.x = x * bx;
	out.y = y * by;

	return out;
});

DefineVector2OperatorMethod(AtomVector2, AtomVector2::operator/, const, {
	AtomVector2 out;

	out.x = x / bx;
	out.y = y / by;

	return out;
});

DefineVector2OperatorMethod(AtomVector2, AtomVector2::operator%, const, {
	AtomVector2 out;

	out.x = atom_mod_number(x, bx);
	out.y = atom_mod_number(y, by);

	return out;
});

DefineVector2OperatorMethod(AtomVector2&, AtomVector2::operator+=, , {
	x += bx;
	y += by;

	return *this;
});

DefineVector2OperatorMethod(AtomVector2&, AtomVector2::operator-=, , {
	x -= bx;
	y -= by;

	return *this;
});

DefineVector2OperatorMethod(AtomVector2&, AtomVector2::operator*=, , {
	x *= bx;
	y *= by;

	return *this;
});

DefineVector2OperatorMethod(AtomVector2&, AtomVector2::operator/=, , {
	x /= bx;
	y /= by;

	return *this;
});

DefineVector2OperatorMethod(AtomVector2&, AtomVector2::operator%=, , {
	x = atom_mod_number(x, bx);
	y = atom_mod_number(y, by);

	return *this;
});

DefineVector2OperatorMethod(AtomVector2&, AtomVector2::operator=, , {
	x = bx;
	y = by;

	return *this;
});

DefineVector2OperatorMethod(bool, AtomVector2::operator==, const, {
	return Equals(bx, by);
});

AtomVector2& AtomVector2::operator++() {
	x++;
	y++;

	return *this;
}

AtomVector2& AtomVector2::operator--() {
	x--;
	y--;
	
	return *this;
}

std::string AtomVector2::ToString() const {
	std::string result = "vec2(";
	
	result += std::to_string(x);
	result += ", ";
	result += std::to_string(y);
	
	result += ")";

	return result;
}

DefineVector2Method(AtomVector3, AtomVector2::Cross, const, {
	AtomVector3 out;

	out.x = 0;
	out.y = 0;
	out.z = x * by - y * bx;
	
	return out;
});

void AtomVector2::Transform(const AtomMatrix2& m) {
	x = m.m00 * x + m.m10 * y;
	y = m.m01 * x + m.m11 * y;
}

void AtomVector2::Transform(const AtomMatrix2D& m) {
	x = m.m00 * x + m.m10 * y + m.m20;
	y = m.m01 * x + m.m11 * y + m.m21;
}

void AtomVector2::Transform(const AtomMatrix3& m) {
	x = m.m00 * x + m.m10 * y + m.m20;
	y = m.m01 * x + m.m11 * y + m.m21;
}

void AtomVector2::Transform(const AtomMatrix4& m) {
	x = m.m00 * x + m.m10 * y + m.m30;
	y = m.m01 * x + m.m11 * y + m.m31;
}

DefineVector2MethodArgs(void, AtomVector2::Rotate, , {
	AtomPoint p0 = x - bx;
	AtomPoint p1 = y - by;

	AtomPoint sinC = std::sin(rad);
	AtomPoint cosC = std::cos(rad);

	x = p0 * cosC - p1 * sinC + bx;
	y = p0 * sinC + p1 * cosC + by;
}, const AtomPoint& rad);

DefineVector2Method(AtomPoint, AtomVector2::Angle, const, {
	AtomPoint mag = std::sqrt((x * x + y * y) * (bx * bx + by * by));
	AtomPoint cosine = mag && (x * bx + y * by) / mag;

	return std::acos(std::min(std::max(cosine, -1.0f), 1.0f));
});

AtomVector3::AtomVector3() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

DefineVector3Method(, AtomVector3::AtomVector3, , {
	x = bx;
	y = by;
	z = bz;
});

AtomVector3 AtomVector3::Clone() const {
	AtomVector3 out;

	out.x = x;
	out.y = y;
	out.z = z;
	
	return out;
}

void AtomVector3::Copy(AtomVector2* v) const {
	if (!v) {
		return;
	}

	v->x = x;
	v->y = y;
}

void AtomVector3::Copy(AtomVector3* v) const {
	if (!v) {
		return;
	}

	v->x = x;
	v->y = y;
	v->z = z;
}

void AtomVector3::Copy(AtomVector4* v) const {
	if (!v) {
		return;
	}

	v->x = x;
	v->y = y;
	v->z = z;
}

DefineVector3Method(void, AtomVector3::Set, , {
	x = bx;
	y = by;
	z = bz;
});

DefineVector3Method(void, AtomVector3::Add, , {
	x += bx;
	y += by;
	z += bz;
});

DefineVector3Method(void, AtomVector3::Subtract, , {
	x -= bx;
	y -= by;
	z -= bz;
});

DefineVector3Method(void, AtomVector3::Multiply, , {
	x *= bx;
	y *= by;
	z *= bz;
});

DefineVector3Method(void, AtomVector3::Divide, , {
	x /= bx;
	y /= by;
	z /= bz;
});

DefineVector3Method(void, AtomVector3::Modulo, , {
	x = atom_mod_number(x, bx);
	y = atom_mod_number(y, by);
	z = atom_mod_number(z, bz);
});

DefineVector3Method(void, AtomVector3::Min, , {
	x = std::min(x, bx);
	y = std::min(y, by);
	z = std::min(z, bz);
});

DefineVector3Method(void, AtomVector3::Max, , {
	x = std::max(x, bx);
	y = std::max(y, by);
	z = std::max(z, bz);
});

DefineVector3Method(void, AtomVector3::Scale, , {
	x *= bx;
	y *= by;
	z *= bz;
});

DefineVector3MethodArgs(void, AtomVector3::ScaleAndAdd, , {
	x += bx * scale;
	y += by * scale;
	z += bz * scale;
}, const AtomPoint& scale);

DefineVector3Method(void, AtomVector3::Pow, , {
	x = std::pow(x, bx);
	y = std::pow(y, by);
	z = std::pow(z, bz);
});

void AtomVector3::Ceil() {
	x = std::ceil(x);
	y = std::ceil(y);
	z = std::ceil(z);
}

void AtomVector3::Floor() {
	x = std::floor(x);
	y = std::floor(y);
	z = std::floor(z);
}

void AtomVector3::Round() {
	x = ::Round(x);
	y = ::Round(y);
	z = ::Round(z);
}

DefineVector3Method(AtomPoint, AtomVector3::Distance, const, {
	AtomPoint nx = bx - x;
	AtomPoint ny = by - y;
	AtomPoint nz = bz - z;

	return std::sqrt(nx * nx + ny * ny + nz * nz);
});

DefineVector3Method(AtomPoint, AtomVector3::SquaredDistance, const, {
	AtomPoint nx = bx - x;
	AtomPoint ny = by - y;
	AtomPoint nz = bz - z;

	return nx * nx + ny * ny + nz * nz;
});

AtomPoint AtomVector3::Length() const {
	return std::sqrt(x * x + y * y + z * z);
}

AtomPoint AtomVector3::SquaredLength() const {
	return x * x + y * y + z * z;
}

void AtomVector3::Negate() {
	x = -x;
	y = -y;
	z = -z;
}

void AtomVector3::Inverse() {
	x = 1.0f / x;
	y = 1.0f / y;
	z = 1.0f / z;
}

void AtomVector3::Normalize() {
	AtomPoint len = x * x + y * y + z * z;

	if (len > 0.0f) {
		len = 1.0f / std::sqrt(len);
	}

	x *= len;
	y *= len;
	z *= len;
}

DefineVector3Method(AtomPoint, AtomVector3::Dot, const, {
	return x * bx + y * by + z * bz;
});

DefineVector3MethodArgs(void, AtomVector3::Lerp, , {
	x = x + t * (bx - x);
	y = y + t * (by - y);
	z = z + t * (bz - z);
}, const AtomPoint& t);

void AtomVector3::Random(AtomPoint scale) {
	AtomPoint rad = ::Random() * 2.0f * M_PI;
	AtomPoint nz = ::Random() * 2.0f - 1.0f;
	AtomPoint zScale = std::sqrt(1.0f - nz * nz) * scale;

	x = std::cos(rad) * zScale;
	y = std::sin(rad) * zScale;
	z = nz * scale;
}

void AtomVector3::Zero() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

DefineVector3Method(bool, AtomVector3::ExactEquals, const, {
	return x == bx && y == by && z == bz;
});

DefineVector3Method(bool, AtomVector3::Equals, const, {
	return (
		std::abs(x - bx) <= ATOM_EPSILON * std::max(std::max(std::abs(x), std::abs(bx)), 1.0f) &&
		std::abs(y - by) <= ATOM_EPSILON * std::max(std::max(std::abs(y), std::abs(by)), 1.0f) &&
		std::abs(z - bz) <= ATOM_EPSILON * std::max(std::max(std::abs(z), std::abs(bz)), 1.0f)
	);
});

DefineVector3OperatorMethod(AtomVector3, AtomVector3::operator+, const, {
	AtomVector3 out;

	out.x = x + bx;
	out.y = y + by;
	out.z = z + bz;

	return out;
});

DefineVector3OperatorMethod(AtomVector3, AtomVector3::operator-, const, {
	AtomVector3 out;

	out.x = x - bx;
	out.y = y - by;
	out.z = z - bz;

	return out;
});

DefineVector3OperatorMethod(AtomVector3, AtomVector3::operator*, const, {
	AtomVector3 out;

	out.x = x * bx;
	out.y = y * by;
	out.z = z * bz;

	return out;
});

DefineVector3OperatorMethod(AtomVector3, AtomVector3::operator/, const, {
	AtomVector3 out;

	out.x = x / bx;
	out.y = y / by;
	out.z = z / bz;

	return out;
});

DefineVector3OperatorMethod(AtomVector3, AtomVector3::operator%, const, {
	AtomVector3 out;

	out.x = atom_mod_number(x, bx);
	out.y = atom_mod_number(y, by);
	out.z = atom_mod_number(z, bz);

	return out;
});

DefineVector3OperatorMethod(AtomVector3&, AtomVector3::operator+=, , {
	x += bx;
	y += by;
	z += bz;
	
	return *this;
});

DefineVector3OperatorMethod(AtomVector3&, AtomVector3::operator-=, , {
	x -= bx;
	y -= by;
	z -= bz;
	
	return *this;
});

DefineVector3OperatorMethod(AtomVector3&, AtomVector3::operator*=, , {
	x *= bx;
	y *= by;
	z *= bz;

	return *this;
});

DefineVector3OperatorMethod(AtomVector3&, AtomVector3::operator/=, , {
	x /= bx;
	y /= by;
	z /= bz;

	return *this;
});

DefineVector3OperatorMethod(AtomVector3&, AtomVector3::operator%=, , {
	x = atom_mod_number(x, bx);
	y = atom_mod_number(y, by);
	z = atom_mod_number(z, bz);

	return *this;
});

DefineVector3OperatorMethod(AtomVector3&, AtomVector3::operator=, , {
	x = bx;
	y = by;
	z = bz;

	return *this;
});

DefineVector3OperatorMethod(bool, AtomVector3::operator==, const, {
	return Equals(bx, by, bz);
});

AtomVector3& AtomVector3::operator++() {
	x++;
	y++;
	z++;
	
	return *this;
}

AtomVector3& AtomVector3::operator--() {
	x--;
	y--;
	z--;
	
	return *this;
}

std::string AtomVector3::ToString() const {
	std::string result = "vec3(";

	result += std::to_string(x);
	result += ", ";
	result += std::to_string(y);
	result += ", ";
	result += std::to_string(z);

	result += ")";

	return result;
}

DefineVector3Method(AtomVector3, AtomVector3::Cross, const, {
	AtomVector3 out;

	out.x = y * bz - z * by;
	out.y = z * bx - x * bz;
	out.z = x * by - y * bx;

	return out;
});

DefineVector3MethodArgs(void, AtomVector3::Slerp, , {
	AtomPoint dotProduct = Dot(bx, by, bz);
	AtomPoint angle = std::acos(std::min(1.0f, std::max(dotProduct, -1.0f)));
	AtomPoint sinTotal = std::sin(angle);

	AtomPoint ratioA = std::sin((1.0f - t) * angle) / sinTotal;
	AtomPoint ratioB = std::sin(t * angle) / sinTotal;

	x = ratioA * x + ratioB * bx;
	y = ratioA * y + ratioB * by;
	z = ratioA * z + ratioB * bz;
}, const AtomPoint& t);


void AtomVector3::Hermite(const AtomVector3& b, const AtomVector3& c, const AtomVector3& d, const AtomPoint& t) {
	AtomPoint factorTimes2 = t * t;
	AtomPoint factor1 = factorTimes2 * (2.0f * t - 3.0f) + 1.0f;
	AtomPoint factor2 = factorTimes2 * (t - 2.0f) + t;
	AtomPoint factor3 = factorTimes2 * (t - 1.0f);
	AtomPoint factor4 = factorTimes2 * (3.0f - 2.0f * t);

	x = x * factor1 + b.x * factor2 + c.x * factor3 + d.x * factor4;
	y = y * factor1 + b.y * factor2 + c.y * factor3 + d.y * factor4;
	z = z * factor1 + b.z * factor2 + c.z * factor3 + d.z * factor4;
}

void AtomVector3::Bazier(const AtomVector3& b, const AtomVector3& c, const AtomVector3& d, const AtomPoint& t) {
	AtomPoint inverseFactor = 1.0f - t;
	AtomPoint inverseFactorTimes2 = inverseFactor * inverseFactor;
	AtomPoint factorTimes2 = t * t;
	AtomPoint factor1 = inverseFactorTimes2 * inverseFactor;
	AtomPoint factor2 = 3.0f * t * inverseFactorTimes2;
	AtomPoint factor3 = 3.0f * factorTimes2 * inverseFactor;
	AtomPoint factor4 = factorTimes2 * t;

	x = x * factor1 + b.x * factor2 + c.x * factor3 + d.x * factor4;
	y = y * factor1 + b.y * factor2 + c.y * factor3 + d.y * factor4;
	z = z * factor1 + b.z * factor2 + c.z * factor3 + d.z * factor4;
}

void AtomVector3::Transform(const AtomMatrix4& m) {
	AtomPoint w = m.m03 * x + m.m13 * y + m.m23 * z + m.m33;
	w = w || 1.0f;

	x = (m.m00 * x + m.m10 * y + m.m20 * z + m.m30) / w;
	y = (m.m01 * x + m.m11 * y + m.m21 * z + m.m31) / w;
	z = (m.m02 * x + m.m12 * y + m.m22 * z + m.m32) / w;
}

void AtomVector3::Transform(const AtomMatrix3& m) {
	x = x * m.m00 + y * m.m10 + z * m.m20;
	y = x * m.m01 + y * m.m11 + z * m.m21;
	z = z * m.m02 + y * m.m12 + z * m.m22;
}

void AtomVector3::Transform(const AtomQuat& q) {
	AtomPoint qx = q.x;
	AtomPoint qy = q.y;
	AtomPoint qz = q.z;
	AtomPoint qw = q.w;

	AtomPoint uvx = qy * z - qz * y;
	AtomPoint uvy = qz * x - qx * z;
	AtomPoint uvz = qx * y - qy * x;

	AtomPoint uuvx = qy * uvz - qz * uvy;
	AtomPoint uuvy = qz * uvx - qx * uvz;
	AtomPoint uuvz = qx * uvy - qy * uvx;

	AtomPoint w2 = qw * 2.0f;
	
	uvx *= w2;
	uvy *= w2;
	uvz *= w2;

	uuvx *= 2.0f;
	uuvy *= 2.0f;
	uuvz *= 2.0f;

	x = x + uvx + uuvx;
	y = y + uvy + uuvy;
	z = z + uvz + uuvz;
}

DefineVector3MethodArgs(void, AtomVector3::RotateX, , {
	AtomVector3 p;
	AtomVector3 r;

	p.x = x - bx;
	p.y = y - by;
	p.z = z - bz;

	r.x = p.x;
	r.y = p.y * std::cos(rad) - p.z * std::sin(rad);
	r.z = p.y * std::sin(rad) + p.z * std::cos(rad);

	x = r.x + bx;
	y = r.y + by;
	z = r.z + bz;
}, const AtomPoint& rad);

DefineVector3MethodArgs(void, AtomVector3::RotateY, , {
	AtomVector3 p;
	AtomVector3 r;

	p.x = x - bx;
	p.y = y - by;
	p.z = z - bz;

	r.x = p.z * std::sin(rad) + p.x * std::cos(rad);
	r.y = p.y;
	r.z = p.z * std::cos(rad) - p.x * std::sin(rad);

	x = r.x + bx;
	y = r.y + by;
	z = r.z + bz;
}, const AtomPoint& rad);

DefineVector3MethodArgs(void, AtomVector3::RotateZ, , {
	AtomVector3 p;
	AtomVector3 r;

	p.x = x - bx;
	p.y = y - by;
	p.z = z - bz;

	r.x = p.x * std::cos(rad) - p.y * std::sin(rad);
	r.y = p.x * std::sin(rad) + p.y * std::cos(rad);
	r.z = p.z;

	x = r.x + bx;
	y = r.y + by;
	z = r.z + bz;
}, const AtomPoint& rad);

DefineVector3Method(AtomPoint, AtomVector3::Angle, const, {
	AtomPoint mag = std::sqrt((x * x + y * y + z * z) * (bx * bx + by * by + bz * bz));
	AtomPoint cosine = mag && Dot(bx, by, bz) / mag;

	return std::acos(std::min(1.0f, std::max(cosine, -1.0f)));
});

AtomVector4::AtomVector4() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

DefineVector4Method(, AtomVector4::AtomVector4, , {
	x = bx;
	y = by;
	z = bz;
	w = bw;
});

AtomVector4 AtomVector4::Clone() const {
	AtomVector4 out;

	out.x = x;
	out.y = y;
	out.z = z;
	out.w = w;

	return out;
}

void AtomVector4::Copy(AtomVector2* v) const {
	if (!v) {
		return;
	}

	v->x = x;
	v->y = y;
}

void AtomVector4::Copy(AtomVector3* v) const {
	if (!v) {
		return;
	}

	v->x = x;
	v->y = y;
	v->z = z;
}

void AtomVector4::Copy(AtomVector4* v) const {
	if (!v) {
		return;
	}

	v->x = x;
	v->y = y;
	v->z = z;
	v->w = w;
}

DefineVector4Method(void, AtomVector4::Set, , {
	x = bx;
	y = by;
	z = bz;
	w = bw;
});


DefineVector4Method(void, AtomVector4::Add, , {
	x += bx;
	y += by;
	z += bz;
	w += bw;
});

DefineVector4Method(void, AtomVector4::Subtract, , {
	x -= bx;
	y -= by;
	z -= bz;
	w -= bw;
});

DefineVector4Method(void, AtomVector4::Multiply, , {
	x *= bx;
	y *= by;
	z *= bz;
	w *= bw;
});

DefineVector4Method(void, AtomVector4::Divide, , {
	x /= bx;
	y /= by;
	z /= bz;
	w /= bw;
});

DefineVector4Method(void, AtomVector4::Modulo, , {
	x = atom_mod_number(x, bx);
	y = atom_mod_number(y, by);
	z = atom_mod_number(z, bz);
	w = atom_mod_number(w, bw);
});

DefineVector4Method(void, AtomVector4::Min, , {
	x = std::min(x, bx);
	y = std::min(y, by);
	z = std::min(z, bz);
	w = std::min(w, bw);
});

DefineVector4Method(void, AtomVector4::Max, , {
	x = std::max(x, bx);
	y = std::max(y, by);
	z = std::max(z, bz);
	w = std::max(w, bw);
});

DefineVector4Method(void, AtomVector4::Scale, , {
	x *= bx;
	y *= by;
	z *= bz;
	w *= bw;
});

DefineVector4MethodArgs(void, AtomVector4::ScaleAndAdd, , {
	x += bx * scale;
	y += by * scale;
	z += bz * scale;
	w += bw * scale;
}, const AtomPoint& scale);

DefineVector4Method(void, AtomVector4::Pow, , {
	x = std::pow(x, bx);
	y = std::pow(y, by);
	z = std::pow(z, bz);
	w = std::pow(w, bw);
});

DefineVector4Method(AtomPoint, AtomVector4::Distance, const, {
	AtomPoint nx = bx - x;
	AtomPoint ny = by - y;
	AtomPoint nz = bz - z;
	AtomPoint nw = bw - w;

	return std::sqrt(nx * nx + ny * ny + nz * nz + nw * nw);
});

DefineVector4Method(AtomPoint, AtomVector4::SquaredDistance, const, {
	AtomPoint nx = bx - x;
	AtomPoint ny = by - y;
	AtomPoint nz = bz - z;
	AtomPoint nw = bw - w;

	return nx * nx + ny * ny + nz * nz + nw * nw;
});

AtomPoint AtomVector4::Length() const {
	return std::sqrt(x * x + y * y + z * z + w * w);
}

AtomPoint AtomVector4::SquaredLength() const {
	return x * x + y * y + z * z + w * w;
}

void AtomVector4::Negate() {
	x = -x;
	y = -y;
	z = -z;
	w = -w;
}

void AtomVector4::Inverse() {
	x = 1.0f / x;
	y = 1.0f / y;
	z = 1.0f / z;
	w = 1.0f / w;
}

void AtomVector4::Normalize() {
	AtomPoint len = x * x + y * y + z * z + w * w;

	if (len > 0.0f) {
		len = 1.0f / std::sqrt(len);
	}

	x *= len;
	y *= len;
	z *= len;
	w *= len;
}

DefineVector4Method(AtomPoint, AtomVector4::Dot, const, {
	return x * bx + y * by + z * bz + w * bw;
});

DefineVector4MethodArgs(void, AtomVector4::Lerp, , {
	x = x + t * (bx - x);
	y = y + t * (by - y);
	z = z + t * (bz - z);
	w = w + t * (bw - w);
}, const AtomPoint& t);

void AtomVector4::Random(AtomPoint scale) {
	AtomPoint v1, v2, v3, v4;
	AtomPoint s1, s2;
	AtomPoint rand;

	rand = ::Random();
	v1 = rand * 2.0f - 1.0f;
	v2 = (4.0f * ::Random() - 2.0f) * std::sqrt(rand * (-rand) + rand);
	s1 = v1 * v1 + v2 * v2;

	rand = ::Random();
	v3 = rand * 2.0f - 1.0f;
	v4 = (4.0f * ::Random() - 2.0f) * std::sqrt(rand * (-rand) + rand);
	s2 = v3 * v3 + v4 * v4;

	AtomPoint d = std::sqrt((1.0f - s1) / s2);

	x = scale * v1;
	y = scale * v2;
	z = scale * v3 * d;
	w = scale * v4 * d;
}

void AtomVector4::Zero() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

DefineVector4Method(bool, AtomVector4::ExactEquals, const, {
	return x == bx && y == by && z == bz && w == bw;
});

DefineVector4Method(bool, AtomVector4::Equals, const, {
	return (
		std::abs(x - bx) <= ATOM_EPSILON * std::max(std::max(std::abs(x), std::abs(bx)), 1.0f) &&
		std::abs(y - by) <= ATOM_EPSILON * std::max(std::max(std::abs(y), std::abs(by)), 1.0f) &&
		std::abs(z - bz) <= ATOM_EPSILON * std::max(std::max(std::abs(z), std::abs(bz)), 1.0f) &&
		std::abs(w - bw) <= ATOM_EPSILON * std::max(std::max(std::abs(w), std::abs(bw)), 1.0f)
	);
});

DefineVector4OperatorMethod(AtomVector4, AtomVector4::operator+, const, {
	AtomVector4 out;

	out.x = x + bx;
	out.y = y + by;
	out.z = z + bz;
	out.w = w + bw;

	return out;
});

DefineVector4OperatorMethod(AtomVector4, AtomVector4::operator-, const, {
	AtomVector4 out;

	out.x = x - bx;
	out.y = y - by;
	out.z = z - bz;
	out.w = w - bw;

	return out;
});

DefineVector4OperatorMethod(AtomVector4, AtomVector4::operator*, const, {
	AtomVector4 out;

	out.x = x * bx;
	out.y = y * by;
	out.z = z * bz;
	out.w = w * bw;

	return out;
});

DefineVector4OperatorMethod(AtomVector4, AtomVector4::operator/, const, {
	AtomVector4 out;

	out.x = x / bx;
	out.y = y / by;
	out.z = z / bz;
	out.w = w / bw;

	return out;
});

DefineVector4OperatorMethod(AtomVector4, AtomVector4::operator%, const, {
	AtomVector4 out;

	out.x = atom_mod_number(x, bx);
	out.y = atom_mod_number(y, by);
	out.z = atom_mod_number(z, bz);
	out.w = atom_mod_number(w, bw);

	return out;
});

DefineVector4OperatorMethod(AtomVector4&, AtomVector4::operator+=, , {
	x += bx;
	y += by;
	z += bz;
	w += bw;

	return *this;
});

DefineVector4OperatorMethod(AtomVector4&, AtomVector4::operator-=, , {
	x -= bx;
	y -= by;
	z -= bz;
	w -= bw;

	return *this;
});

DefineVector4OperatorMethod(AtomVector4&, AtomVector4::operator*=, , {
	x *= bx;
	y *= by;
	z *= bz;
	w *= bw;

	return *this;
});

DefineVector4OperatorMethod(AtomVector4&, AtomVector4::operator/=, , {
	x /= bx;
	y /= by;
	z /= bz;
	w /= bw;

	return *this;
});

DefineVector4OperatorMethod(AtomVector4&, AtomVector4::operator%=, , {
	x = atom_mod_number(x, bx);
	y = atom_mod_number(y, by);
	z = atom_mod_number(z, bz);
	w = atom_mod_number(w, bw);

	return *this;
});

DefineVector4OperatorMethod(AtomVector4&, AtomVector4::operator=, , {
	x = bx;
	y = by;
	z = bz;
	w = bw;

	return *this;
});

DefineVector4OperatorMethod(bool, AtomVector4::operator==, const, {
	return Equals(bx, by, bz, bw);
});

AtomVector4& AtomVector4::operator++() {
	x++;
	y++;
	z++;
	w++;

	return *this;
}

AtomVector4& AtomVector4::operator--() {
	x--;
	y--;
	z--;
	w--;
	
	return *this;
}

std::string AtomVector4::ToString() const {
	std::string result = "vec4(";

	result += std::to_string(x);
	result += ", ";
	result += std::to_string(y);
	result += ", ";
	result += std::to_string(z);
	result += ", ";
	result += std::to_string(w);

	result += ")";

	return result;
}

AtomVector4 AtomVector4::Cross(const AtomVector4& v, const AtomVector4& ww) const {
	AtomVector4 out;

	AtomPoint A = v.x * ww.y - v.y * ww.x;
	AtomPoint B = v.x * ww.z - v.z * ww.x;
	AtomPoint C = v.x * ww.w - v.w * ww.x;
	AtomPoint D = v.y * ww.z - v.z * ww.y;
	AtomPoint E = v.y * ww.w - v.w * ww.y;
	AtomPoint F = v.z * ww.w - v.w * ww.z;
	AtomPoint G = x;
	AtomPoint H = y;
	AtomPoint I = z;
	AtomPoint J = w;

	out.x = H * F - I * E + J * D;
	out.y = -(G * F) + I * C - J * B;
	out.z = G * E - H * C + J * A;
	out.w = -(G * D) + H * B - I * A;

	return out;
}

void AtomVector4::Transform(const AtomMatrix4& m) {
	x = m.m00 * x + m.m10 * y + m.m20 * z + m.m30 * w;
	y = m.m01 * x + m.m11 * y + m.m21 * z + m.m31 * w;
	z = m.m02 * x + m.m12 * y + m.m22 * z + m.m32 * w;
	w = m.m03 * x + m.m13 * y + m.m23 * z + m.m33 * w;
}

void AtomVector4::Transform(const AtomQuat& q) {
	AtomPoint qx = q.x;
	AtomPoint qy = q.y;
	AtomPoint qz = q.z;
	AtomPoint qw = q.w;

	AtomPoint ix = qw * x + qy * z - qz * y;
	AtomPoint iy = qw * y + qz * x - qx * z;
	AtomPoint iz = qw * z + qx * y - qy * x;
	AtomPoint iw = -qx * x - qy * y - qz * z;

	x = ix * qw + iw * -qx + iy * -qz - iz * -qy;
	y = iy * qw + iw * -qy + iz * -qx - ix * -qz;
	z = iz * qw + iw * -qz + ix * -qy - iy * -qx;
}

#undef DefineVector2Method
#undef DefineVector3Method
#undef DefineVector4Method

#undef DefineVector2MethodArgs
#undef DefineVector3MethodArgs
#undef DefineVector4MethodArgs

#undef DefineVector2OperatorMethod
#undef DefineVector3OperatorMethod
#undef DefineVector4OperatorMethod