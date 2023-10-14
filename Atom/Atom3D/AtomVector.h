/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        Atom3D/AtomVector.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_VECTOR_HEADER
#define ATOM_VECTOR_HEADER

#include <vector>
#include <string>

#define ATOM_EPSILON 0.000001
#define ATOM_VECTOR_ARRAT_TYPE float

typedef ATOM_VECTOR_ARRAT_TYPE AtomPoint;

class AtomVector2;
class AtomVector3;
class AtomVector4;

typedef std::vector<AtomVector2> AtomVector2List;
typedef std::vector<AtomVector3> AtomVector3List;
typedef std::vector<AtomVector4> AtomVector4List;

class AtomMatrix2;
class AtomMatrix2D;
class AtomMatrix3;
class AtomMatrix4;

class AtomQuat;

#define DefineMethod(returnType, method, constState) returnType method(const AtomPoint& v) constState; \
                                                     returnType method(const AtomPoint& vx, const AtomPoint& vy) constState; \
                                                     returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz) constState; \
                                                     returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, const AtomPoint& vw) constState; \
                                                     returnType method(const AtomVector2& v) constState; \
                                                     returnType method(const AtomVector3& v) constState; \
                                                     returnType method(const AtomVector4& v) constState;

#define DefineMethodArgs(returnType, method, constState, ...) returnType method(const AtomPoint& v, __VA_ARGS__) constState; \
                                                              returnType method(const AtomPoint& vx, const AtomPoint& vy, __VA_ARGS__) constState; \
                                                              returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, __VA_ARGS__) constState; \
                                                              returnType method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, const AtomPoint& vw, __VA_ARGS__) constState; \
                                                              returnType method(const AtomVector2& v, __VA_ARGS__) constState; \
                                                              returnType method(const AtomVector3& v, __VA_ARGS__) constState; \
                                                              returnType method(const AtomVector4& v, __VA_ARGS__) constState;

#define DefineOperatorMethod(returnType, method, constState) returnType method(const AtomPoint& v) constState; \
                                                             returnType method(const AtomVector2& v) constState; \
                                                             returnType method(const AtomVector3& v) constState; \
                                                             returnType method(const AtomVector4& v) constState;

#define DefineAtomVectorClass(cn, extra) \
class cn { \
public: \
	cn(); \
	DefineMethod(, cn,); \
	~cn() = default; \
    \
	cn Clone() const; \
	\
	void Copy(AtomVector2* v) const; \
	void Copy(AtomVector3* v) const; \
	void Copy(AtomVector4* v) const; \
	\
	DefineMethod(void, Set,); \
	DefineMethod(void, Add,); \
	DefineMethod(void, Subtract,); \
	DefineMethod(void, Multiply,); \
	DefineMethod(void, Divide,); \
	DefineMethod(void, Modulo,); \
	DefineMethod(void, Min,); \
	DefineMethod(void, Max,); \
	DefineMethod(void, Scale,); \
	DefineMethodArgs(void, ScaleAndAdd, , const AtomPoint& scale); \
	DefineMethod(void, Pow,) \
	\
	void Ceil(); \
	void Floor(); \
	void Round(); \
	\
	DefineMethod(AtomPoint, Distance, const); \
	DefineMethod(AtomPoint, SquaredDistance, const); \
	\
	AtomPoint Length() const; \
	AtomPoint SquaredLength() const; \
	\
	void Negate(); \
	void Inverse(); \
	void Normalize(); \
	\
	DefineMethod(AtomPoint, Dot, const); \
	\
	DefineMethodArgs(void, Lerp, , const AtomPoint& t); \
	\
	void Random(AtomPoint scale = 1.0f); \
	void Zero(); \
	\
	DefineMethod(bool, ExactEquals, const); \
	DefineMethod(bool, Equals, const); \
	\
	DefineOperatorMethod(cn, operator+, const); \
	DefineOperatorMethod(cn, operator-, const); \
	DefineOperatorMethod(cn, operator*, const); \
	DefineOperatorMethod(cn, operator/, const); \
	DefineOperatorMethod(cn, operator%, const); \
	\
	DefineOperatorMethod(cn&, operator+=,); \
	DefineOperatorMethod(cn&, operator-=,); \
	DefineOperatorMethod(cn&, operator*=,); \
	DefineOperatorMethod(cn&, operator/=,); \
    DefineOperatorMethod(cn&, operator%=,); \
	DefineOperatorMethod(cn&, operator=,); \
	\
	DefineOperatorMethod(bool, operator==, const); \
	\
	cn& operator++(); \
	cn& operator--(); \
	\
	std::string ToString() const; \
	\
	extra \
\
};

DefineAtomVectorClass(AtomVector2,
	AtomPoint x;
    AtomPoint y;

	DefineMethod(AtomVector3, Cross, const);
	
	void Transform(const AtomMatrix2& m);
	void Transform(const AtomMatrix2D& m);
	void Transform(const AtomMatrix3& m);
	void Transform(const AtomMatrix4& m);

	DefineMethodArgs(void, Rotate, , const AtomPoint& rad);

	DefineMethod(AtomPoint, Angle, const);
);

DefineAtomVectorClass(AtomVector3,
	AtomPoint x;
    AtomPoint y;
    AtomPoint z;

	DefineMethod(AtomVector3, Cross, const);

	DefineMethodArgs(void, Slerp, , const AtomPoint& t);
	
	void Hermite(const AtomVector3& b, const AtomVector3& c, const AtomVector3& d, const AtomPoint& t);
	void Bazier(const AtomVector3& b, const AtomVector3& c, const AtomVector3& d, const AtomPoint& t);

	void Transform(const AtomMatrix4& m);
	void Transform(const AtomMatrix3& m);
	void Transform(const AtomQuat& q);

	DefineMethodArgs(void, RotateX, , const AtomPoint& rad);
	DefineMethodArgs(void, RotateY, , const AtomPoint& rad);
	DefineMethodArgs(void, RotateZ, , const AtomPoint& rad);

	DefineMethod(AtomPoint, Angle, const);
);

DefineAtomVectorClass(AtomVector4,
	AtomPoint x;
    AtomPoint y;
	AtomPoint z;
	AtomPoint w;

	AtomVector4 Cross(const AtomVector4& v, const AtomVector4& w) const;

	void Transform(const AtomMatrix4& m);
	void Transform(const AtomQuat& q);
);

/*#define DefineVectorClass(className, extra) \
class className { \
public: \
	className(); \ 
	DefineMethod(, className,); \
	~className() = default; \
    \
	className Clone() const; \
	\
	void Copy(AtomVector2* v) const; \
	void Copy(AtomVector3* v) const; \
	void Copy(AtomVector4* v) const; \
	\
	DefineMethod(void, Set,); \
	DefineMethod(void, Add,); \
	DefineMethod(void, Subtract,); \
	DefineMethod(void, Multiply,); \
	DefineMethod(void, Divide,); \
	DefineMethod(void, Modulo,); \
	DefineMethod(void, Min,); \
	DefineMethod(void, Max,); \
	DefineMethod(void, Scale,); \
	DefineMethodArgs(void, ScaleAndAdd, , const AtomPoint& scale); \
	DefineMethod(void, Pow,) \
	\
	void Ceil(); \
	void Floor(); \
	void Round(); \
	\
	DefineMethod(AtomPoint, Distance, const); \
	DefineMethod(AtomPoint, SquaredDistance, const); \
	\
	AtomPoint Length() const; \
	AtomPoint SquaredLength() const; \
	\
	void Negate(); \
	void Inverse(); \
	void Normalize(); \
	\
	DefineMethod(AtomPoint, Dot, const); \
	\
	DefineMethodArgs(void, Lerp, , const AtomPoint& t); \
	\
	void Random(AtomPoint scale = 1.0f); \
	void Zero(); \
	\
	DefineMethod(bool, ExactEquals, const); \
	DefineMethod(bool, Equals, const); \
	\
	DefineOperatorMethod(className, operator+, const); \
	DefineOperatorMethod(className, operator-, const); \
	DefineOperatorMethod(className, operator*, const); \
	DefineOperatorMethod(className, operator/, const); \
	DefineOperatorMethod(className, operator%, const); \
	\
	DefineOperatorMethod(className&, operator+=,); \
	DefineOperatorMethod(className&, operator-=,); \
	DefineOperatorMethod(className&, operator*=,); \
	DefineOperatorMethod(className&, operator/=,); \
    DefineOperatorMethod(className&, operator%=,); \
	DefineOperatorMethod(className&, operator=,); \
	\
	DefineOperatorMethod(bool, operator==, const); \
	\
	className& operator++(); \
	className& operator--(); \
	\
	std::string ToString() const; \
	\
	extra \
};

DefineVectorClass(AtomVector2,
	AtomPoint x;
    AtomPoint y;

	DefineMethod(AtomVector3, Cross, const);
	
	void Transform(const AtomMatrix2& m);
	void Transform(const AtomMatrix2D& m);
	void Transform(const AtomMatrix3& m);
	void Transform(const AtomMatrix4& m);

	DefineMethodArgs(void, Rotate, , const AtomPoint& rad);

	DefineMethod(AtomPoint, Angle, const);
);

DefineVectorClass(AtomVector3,
	AtomPoint x;
    AtomPoint y;
    AtomPoint z;

	DefineMethod(AtomVector3, Cross, const);

	DefineMethodArgs(void, Slerp, , const AtomPoint& t);
	
	void Hermite(const AtomVector3& b, const AtomVector3& c, const AtomVector3& d, const AtomPoint& t);
	void Bazier(const AtomVector3& b, const AtomVector3& c, const AtomVector3& d, const AtomPoint& t);

	void Transform(const AtomMatrix4& m);
	void Transform(const AtomMatrix3& m);
	void Transform(const AtomQuat& q);

	DefineMethodArgs(void, RotateX, , const AtomPoint& rad);
	DefineMethodArgs(void, RotateY, , const AtomPoint& rad);
	DefineMethodArgs(void, RotateZ, , const AtomPoint& rad);

	DefineMethod(AtomPoint, Angle, const);
);

DefineVectorClass(AtomVector4,
	AtomPoint x;
    AtomPoint y;
	AtomPoint z;
	AtomPoint w;

	AtomVector4 Cross(const AtomVector4& v, const AtomVector4& w) const;

	void Transform(const AtomMatrix4& m);
	void Transform(const AtomQuat& q);
);*/

#undef DefineMethod
#undef DefineMethodArgs
#undef DefineOperatorMethod
//#undef DefineVectorClass

#endif