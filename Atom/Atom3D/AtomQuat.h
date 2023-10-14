/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        Atom3D/AtomQuat.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_QUAT_HEADER
#define ATOM_QUAT_HEADER

#include "AtomVector.h"

// todo

enum class AtomAngleOrder {
	Unknown = 0,
	XYZ = 1,
	XZY = 2,
	YXZ = 3,
	YZX = 4,
	ZXY = 5,
	ZYX = 6
};

class AtomQuat {
public:
	AtomPoint x;
	AtomPoint y;
	AtomPoint z;
	AtomPoint w;

	AtomQuat() = default;
	AtomQuat(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, const AtomPoint& vw);
	AtomQuat(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, AtomAngleOrder order = AtomAngleOrder::ZYX);
	AtomQuat(const AtomMatrix3& m);
	AtomQuat(const AtomQuat& q);
	~AtomQuat() = default;

	AtomQuat Clone() const;

	void Copy(AtomQuat* q);

	void            SetAngleOrder(const AtomAngleOrder& o);
	AtomAngleOrder& GetAngleOrder() const;

	void Identity();
	void SetAxisAngle(const AtomVector3& axis, const AtomPoint& rad);

	AtomPoint GetAxisAngle(const AtomQuat& q) const;
	AtomPoint GetAngle(const AtomQuat& q) const;

	void Multiply(const AtomQuat& q);

	void RotateX(const AtomPoint& rad);
	void RotateY(const AtomPoint& rad);
	void RotateZ(const AtomPoint& rad);

	void CalculateW();

	void Exp();
	void Log();
	void Scale(const AtomQuat& q);

	void Pow(const AtomPoint& v);

	void Slerp(const AtomQuat& q, const AtomPoint& t);

	void Random();
	void Invert();
	void Conjugate();

private:
	AtomAngleOrder order;
};

class AtomQuat2 {
public:
	AtomPoint x;
	AtomPoint y;
	AtomPoint z;
	AtomPoint w;
	AtomPoint ex;
	AtomPoint ey;
	AtomPoint ez;
	AtomPoint ew;
};

#endif