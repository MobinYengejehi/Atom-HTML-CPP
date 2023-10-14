/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        Atom3D/AtomMatrix.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_MATRIX_HEADER
#define ATOM_MATRIX_HEADER

#include "AtomVector.h"

typedef std::vector<AtomMatrix2> AtomMatrix2List;
typedef std::vector<AtomMatrix2D> AtomMatrix2DList;
typedef std::vector<AtomMatrix3> AtomMatrix3List;
typedef std::vector<AtomMatrix4> AtomMatrix4List;

class AtomQuat2;

#define DefineMethod(returnValue, method, constValue) returnValue method(const AtomPoint& v) constValue; \
                                                      returnValue method(const AtomPoint& vx, const AtomPoint& vy) constValue; \
                                                      returnValue method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz) constValue; \
                                                      returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11) constValue; \
                                                      returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v20, const AtomPoint& v21) constValue; \
                                                      returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22) constValue; \
                                                      returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v03, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v13, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, const AtomPoint& v23, const AtomPoint& v30, const AtomPoint& v31, const AtomPoint& v32, const AtomPoint& v33) constValue; \
                                                      returnValue method(const AtomVector2& v) constValue; \
                                                      returnValue method(const AtomVector3& v) constValue; \
                                                      returnValue method(const AtomVector4& v) constValue; \
                                                      returnValue method(const AtomMatrix2& m) constValue; \
                                                      returnValue method(const AtomMatrix2D& m) constValue; \
                                                      returnValue method(const AtomMatrix3& m) constValue; \
                                                      returnValue method(const AtomMatrix4& m) constValue;

#define DefineMethodArgs(returnValue, method, constValue, ...) returnValue method(const AtomPoint& v, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomPoint& vx, const AtomPoint& vy, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v20, const AtomPoint& v21, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v03, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v13, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, const AtomPoint& v23, const AtomPoint& v30, const AtomPoint& v31, const AtomPoint& v32, const AtomPoint& v33, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomVector2& v, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomVector3& v, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomVector4& v, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomMatrix2& m, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomMatrix2D& m, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomMatrix3& m, __VA_ARGS__) constValue; \
                                                               returnValue method(const AtomMatrix4& m, __VA_ARGS__) constValue;

#define DefineOperatorMethod(returnValue, method, constValue) returnValue method(const AtomPoint& v) constValue; \
                                                              returnValue method(const AtomVector2& v) constValue; \
                                                              returnValue method(const AtomVector3& v) constValue; \
                                                              returnValue method(const AtomVector4& v) constValue; \
                                                              returnValue method(const AtomMatrix2& v) constValue; \
                                                              returnValue method(const AtomMatrix2D& v) constValue; \
                                                              returnValue method(const AtomMatrix3& v) constValue; \
                                                              returnValue method(const AtomMatrix4& v) constValue; \

#define DefineMatrixClass(className, extra) \
class className { \
public: \
	className(); \
    DefineMethod(, className,); \
	~className() = default; \
    \
    className Clone() const; \
    \
    void Copy(AtomMatrix2* m) const; \
    void Copy(AtomMatrix2D* m) const; \
    void Copy(AtomMatrix3* m) const; \
    void Copy(AtomMatrix4* m) const; \
    \
    void Identity(); \
    \
    DefineMethod(void, Set,); \
    \
    void Invert(); \
    \
    AtomPoint Determinant() const; \
    \
    DefineMethod(void, Add,); \
    DefineMethod(void, Subtract,); \
    DefineMethod(void, Multiply,); \
    void MultiplyScaler(const AtomPoint& v); \
    DefineMethodArgs(void, MultiplyScalerAndAdd, , const AtomPoint& scale); \
    \
    DefineMethod(void, Scale,); \
    \
    DefineMethod(void, FromScaling,); \
    \
    AtomPoint Frob() const; \
    \
    DefineMethod(bool, ExactEquals, const); \
    DefineMethod(bool, Equals, const); \
    \
    DefineOperatorMethod(className, operator+, const); \
    DefineOperatorMethod(className, operator-, const); \
    DefineOperatorMethod(className, operator*, const); \
    \
    DefineOperatorMethod(className&, operator+=,); \
    DefineOperatorMethod(className&, operator-=,); \
    DefineOperatorMethod(className&, operator*=,); \
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

DefineMatrixClass(AtomMatrix2,
    AtomPoint m00;
    AtomPoint m01;
    AtomPoint m10;
    AtomPoint m11;

    void Adjoint();

    void Rotate(const AtomPoint& rad);

    void Transpose();
    void Transpose(AtomMatrix2* m);

    void FromRotation(const AtomPoint& rad);
);

DefineMatrixClass(AtomMatrix2D,
    AtomPoint m00;
    AtomPoint m01;
    AtomPoint m10;
    AtomPoint m11;
    AtomPoint m20;
    AtomPoint m21;

    void Rotate(const AtomPoint& rad);

    DefineMethod(void, Translate, );
    DefineMethod(void, FromTranslation, );

    void FromRotation(const AtomPoint& rad);
);

DefineMatrixClass(AtomMatrix3,
    AtomPoint m00;
    AtomPoint m01;
    AtomPoint m02;
    AtomPoint m10;
    AtomPoint m11;
    AtomPoint m12;
    AtomPoint m20;
    AtomPoint m21;
    AtomPoint m22;

    void Adjoint();

    void Rotate(const AtomPoint& rad);

    void Transpose();
    void Transpose(AtomMatrix3* m);

    DefineMethod(void, Translate, );
    DefineMethod(void, FromTranslation, );
    
    void FromQuat(const AtomQuat& q);

    void NormalFromMatrix4(const AtomMatrix4& m);

    void Projection(const AtomPoint& width, const AtomPoint& height);

    void FromRotation(const AtomPoint& rad);
);

struct AtomFieldOfView {
    AtomPoint upDegrees;
    AtomPoint downDegrees;
    AtomPoint leftDegrees;
    AtomPoint rightDegrees;
};

DefineMatrixClass(AtomMatrix4,
    AtomPoint m00;
    AtomPoint m01;
    AtomPoint m02;
    AtomPoint m03;
    AtomPoint m10;
    AtomPoint m11;
    AtomPoint m12;
    AtomPoint m13;
    AtomPoint m20;
    AtomPoint m21;
    AtomPoint m22;
    AtomPoint m23;
    AtomPoint m30;
    AtomPoint m31;
    AtomPoint m32;
    AtomPoint m33;

    void Adjoint();

    void Rotate(const AtomPoint& rad, const AtomVector3& v);
    void RotateX(const AtomPoint& rad);
    void RotateY(const AtomPoint& rad);
    void RotateZ(const AtomPoint& rad);

    void Transpose();
    void Transpose(AtomMatrix4* m);

    DefineMethod(void, Translate, );
    DefineMethodArgs(void, Translate, , AtomMatrix4* mm);
    DefineMethod(void, FromTranslation, );

    void FromRotation(const AtomPoint& rad, const AtomVector3& v);
    void FromXRotation(const AtomPoint& rad);
    void FromYRotation(const AtomPoint& rad);
    void FromZRotation(const AtomPoint& rad);
    void FromRotationTranslation(const AtomQuat& q, const AtomVector3& v);
    void FromQuat2(const AtomQuat2& q);

    AtomVector3 GetTranslation() const;
    AtomVector3 GetScaling() const;
    AtomQuat    GetRotation() const;

    AtomQuat Decompose(AtomVector3* t, AtomVector3* s) const;

    void FromRotationTranslationScale(const AtomQuat& q, const AtomVector3& v, const AtomVector3& s);
    void FromRotationTranslationScaleOrigin(const AtomQuat& q, const AtomVector3& v, const AtomVector3& s, const AtomVector3& o);
    void FromQuat(const AtomQuat& q);

    void Frustum(const AtomPoint& left, const AtomPoint& right, const AtomPoint& bottom, const AtomPoint& top, const AtomPoint& near, const AtomPoint& far);

    void Perspective(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near, const AtomPoint& far);
    void Perspective(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near);
    void PerspectiveNO(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near, const AtomPoint& far);
    void PerspectiveNO(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near);
    void PerspectiveZO(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near, const AtomPoint& far);
    void PerspectiveZO(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near);
    void PerspectiveFromFieldOfView(const AtomFieldOfView& fov, const AtomPoint& near, const AtomPoint& far);

    void Ortho(const AtomPoint& left, const AtomPoint& right, const AtomPoint& bottom, const AtomPoint& top, const AtomPoint& near, const AtomPoint& far);
    void OrthoNO(const AtomPoint& left, const AtomPoint& right, const AtomPoint& bottom, const AtomPoint& top, const AtomPoint& near, const AtomPoint& far);
    void OrthoZO(const AtomPoint& left, const AtomPoint& right, const AtomPoint& bottom, const AtomPoint& top, const AtomPoint& near, const AtomPoint& far);

    void LookAt(const AtomVector3& eye, const AtomVector3& center, const AtomVector3& up);

    void TargetTo(const AtomVector3& eye, const AtomVector3& target, const AtomVector3& up);
);

void AtomCalculateLDUMatrix(AtomMatrix2* L, AtomMatrix2* D, AtomMatrix2* U, AtomMatrix2* a);

#undef DefineMethod
#undef DefineMethodArgs
#undef DefineOperatorMethod
#undef DefineMatrixClass

#endif