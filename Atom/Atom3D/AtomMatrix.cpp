/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        Atom3D/AtomMatrix.cpp
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#include "AtomMatrix.h"
#include "AtomVector.h"
#include "AtomQuat.h"

#include "../AtomUtils.h"
#include "../AtomCAPI.h"

#include <cmath>

#define DefineMatrix2Method(returnValue, method, constValue, code) \
returnValue method(const AtomPoint& v) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v20, const AtomPoint& v21) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v03, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v13, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, const AtomPoint& v23, const AtomPoint& v30, const AtomPoint& v31, const AtomPoint& v32, const AtomPoint& v33) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	code \
} \
\
returnValue method(const AtomVector2& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	code \
} \
\
returnValue method(const AtomVector3& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.z; \
	AtomPoint b11 = 0.0f; \
	code \
} \
\
returnValue method(const AtomVector4& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.z; \
	AtomPoint b11 = v.w; \
	code \
} \
\
returnValue method(const AtomMatrix2& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
} \
\
returnValue method(const AtomMatrix3& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
} \
\
returnValue method(const AtomMatrix4& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
}

#define DefineMatrix2DMethod(returnValue, method, constValue, code) \
returnValue method(const AtomPoint& v) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	AtomPoint b20 = v; \
	AtomPoint b21 = v; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v20, const AtomPoint& v21) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v03, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v13, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, const AtomPoint& v23, const AtomPoint& v30, const AtomPoint& v31, const AtomPoint& v32, const AtomPoint& v33) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	code \
} \
\
returnValue method(const AtomVector2& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	code \
} \
\
returnValue method(const AtomVector3& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.z; \
	AtomPoint b11 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	code \
} \
\
returnValue method(const AtomVector4& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.z; \
	AtomPoint b11 = v.w; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix2& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	code \
} \
\
returnValue method(const AtomMatrix3& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	code \
} \
\
returnValue method(const AtomMatrix4& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	code \
}

#define DefineMatrix3Method(returnValue, method, constValue, code) \
returnValue method(const AtomPoint& v) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b02 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	AtomPoint b12 = v; \
	AtomPoint b20 = v; \
	AtomPoint b21 = v; \
	AtomPoint b22 = v; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b02 = vz; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b12 = vz; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	AtomPoint b22 = vz; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v20, const AtomPoint& v21) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = v02; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = v12; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = v22; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v03, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v13, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, const AtomPoint& v23, const AtomPoint& v30, const AtomPoint& v31, const AtomPoint& v32, const AtomPoint& v33) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = v02; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = v12; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = v22; \
	code \
} \
\
returnValue method(const AtomVector2& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomVector3& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	code \
} \
\
returnValue method(const AtomVector4& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	code \
} \
\
returnValue method(const AtomMatrix2& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix3& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	code \
} \
\
returnValue method(const AtomMatrix4& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	code \
}

#define DefineMatrix4Method(returnValue, method, constValue, code) \
returnValue method(const AtomPoint& v) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b02 = v; \
	AtomPoint b03 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	AtomPoint b12 = v; \
	AtomPoint b13 = v; \
	AtomPoint b20 = v; \
	AtomPoint b21 = v; \
	AtomPoint b22 = v; \
	AtomPoint b23 = v; \
	AtomPoint b30 = v; \
	AtomPoint b31 = v; \
	AtomPoint b32 = v; \
	AtomPoint b33 = v; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b02 = vx; \
	AtomPoint b03 = vy; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b12 = vx; \
	AtomPoint b13 = vy; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	AtomPoint b22 = vx; \
	AtomPoint b23 = vy; \
	AtomPoint b30 = vx; \
	AtomPoint b31 = vy; \
	AtomPoint b32 = vx; \
	AtomPoint b33 = vy; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b02 = vz; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b12 = vz; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	AtomPoint b22 = vz; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = vx; \
	AtomPoint b31 = vy; \
	AtomPoint b32 = vz; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	AtomPoint b22 = 0.0f; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v20, const AtomPoint& v21) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = 0.0f; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = v02; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = v12; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = v22; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v03, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v13, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, const AtomPoint& v23, const AtomPoint& v30, const AtomPoint& v31, const AtomPoint& v32, const AtomPoint& v33) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = v02; \
	AtomPoint b03 = v03; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = v12; \
	AtomPoint b13 = v13; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = v22; \
	AtomPoint b23 = v23; \
	AtomPoint b30 = v30; \
	AtomPoint b31 = v31; \
	AtomPoint b32 = v32; \
	AtomPoint b33 = v33; \
	code \
} \
\
returnValue method(const AtomVector2& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.x; \
	AtomPoint b03 = v.y; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.x; \
	AtomPoint b13 = v.y; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.x; \
	AtomPoint b23 = v.y; \
	AtomPoint b30 = v.x; \
	AtomPoint b31 = v.y; \
	AtomPoint b32 = v.x; \
	AtomPoint b33 = v.y; \
	code \
} \
\
returnValue method(const AtomVector3& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = v.x; \
	AtomPoint b31 = v.y; \
	AtomPoint b32 = v.z; \
	AtomPoint b33 = 0.0f;\
	code \
} \
\
returnValue method(const AtomVector4& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b03 = v.w; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b13 = v.w; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	AtomPoint b23 = v.w; \
	AtomPoint b30 = v.x; \
	AtomPoint b31 = v.y; \
	AtomPoint b32 = v.z; \
	AtomPoint b33 = v.w; \
	code \
} \
\
returnValue method(const AtomMatrix2& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	AtomPoint b22 = 0.0f; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = 0.0f; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix3& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix4& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b03 = m.m03; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b13 = m.m13; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	AtomPoint b23 = m.m23; \
	AtomPoint b30 = m.m30; \
	AtomPoint b31 = m.m31; \
	AtomPoint b32 = m.m32; \
	AtomPoint b33 = m.m33; \
	code \
}

#define DefineMatrix2MethodArgs(returnValue, method, constValue, code, ...) \
returnValue method(const AtomPoint& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, __VA_ARGS__) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, __VA_ARGS__) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v20, const AtomPoint& v21, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v03, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v13, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, const AtomPoint& v23, const AtomPoint& v30, const AtomPoint& v31, const AtomPoint& v32, const AtomPoint& v33, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	code \
} \
\
returnValue method(const AtomVector2& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	code \
} \
\
returnValue method(const AtomVector3& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.z; \
	AtomPoint b11 = 0.0f; \
	code \
} \
\
returnValue method(const AtomVector4& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.z; \
	AtomPoint b11 = v.w; \
	code \
} \
\
returnValue method(const AtomMatrix2& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
} \
\
returnValue method(const AtomMatrix3& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
} \
\
returnValue method(const AtomMatrix4& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
}

#define DefineMatrix2DMethodArgs(returnValue, method, constValue, code, ...) \
returnValue method(const AtomPoint& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	AtomPoint b20 = v; \
	AtomPoint b21 = v; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, __VA_ARGS__) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, __VA_ARGS__) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v20, const AtomPoint& v21, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v03, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v13, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, const AtomPoint& v23, const AtomPoint& v30, const AtomPoint& v31, const AtomPoint& v32, const AtomPoint& v33, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	code \
} \
\
returnValue method(const AtomVector2& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	code \
} \
\
returnValue method(const AtomVector3& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.z; \
	AtomPoint b11 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	code \
} \
\
returnValue method(const AtomVector4& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.z; \
	AtomPoint b11 = v.w; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix2& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	code \
} \
\
returnValue method(const AtomMatrix3& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	code \
} \
\
returnValue method(const AtomMatrix4& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	code \
}

#define DefineMatrix3MethodArgs(returnValue, method, constValue, code, ...) \
returnValue method(const AtomPoint& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b02 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	AtomPoint b12 = v; \
	AtomPoint b20 = v; \
	AtomPoint b21 = v; \
	AtomPoint b22 = v; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, __VA_ARGS__) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, __VA_ARGS__) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b02 = vz; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b12 = vz; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	AtomPoint b22 = vz; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v20, const AtomPoint& v21, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = v02; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = v12; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = v22; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v03, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v13, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, const AtomPoint& v23, const AtomPoint& v30, const AtomPoint& v31, const AtomPoint& v32, const AtomPoint& v33, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = v02; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = v12; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = v22; \
	code \
} \
\
returnValue method(const AtomVector2& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomVector3& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	code \
} \
\
returnValue method(const AtomVector4& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	code \
} \
\
returnValue method(const AtomMatrix2& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix3& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	code \
} \
\
returnValue method(const AtomMatrix4& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	code \
}

#define DefineMatrix4MethodArgs(returnValue, method, constValue, code, ...) \
returnValue method(const AtomPoint& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b02 = v; \
	AtomPoint b03 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	AtomPoint b12 = v; \
	AtomPoint b13 = v; \
	AtomPoint b20 = v; \
	AtomPoint b21 = v; \
	AtomPoint b22 = v; \
	AtomPoint b23 = v; \
	AtomPoint b30 = v; \
	AtomPoint b31 = v; \
	AtomPoint b32 = v; \
	AtomPoint b33 = v; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, __VA_ARGS__) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b02 = vx; \
	AtomPoint b03 = vy; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b12 = vx; \
	AtomPoint b13 = vy; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	AtomPoint b22 = vx; \
	AtomPoint b23 = vy; \
	AtomPoint b30 = vx; \
	AtomPoint b31 = vy; \
	AtomPoint b32 = vx; \
	AtomPoint b33 = vy; \
	code \
} \
\
returnValue method(const AtomPoint& vx, const AtomPoint& vy, const AtomPoint& vz, __VA_ARGS__) constValue { \
	AtomPoint b00 = vx; \
	AtomPoint b01 = vy; \
	AtomPoint b02 = vz; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = vx; \
	AtomPoint b11 = vy; \
	AtomPoint b12 = vz; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = vx; \
	AtomPoint b21 = vy; \
	AtomPoint b22 = vz; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = vx; \
	AtomPoint b31 = vy; \
	AtomPoint b32 = vz; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	AtomPoint b22 = 0.0f; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v20, const AtomPoint& v21, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = 0.0f; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = v02; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = v12; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = v22; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomPoint& v00, const AtomPoint& v01, const AtomPoint& v02, const AtomPoint& v03, const AtomPoint& v10, const AtomPoint& v11, const AtomPoint& v12, const AtomPoint& v13, const AtomPoint& v20, const AtomPoint& v21, const AtomPoint& v22, const AtomPoint& v23, const AtomPoint& v30, const AtomPoint& v31, const AtomPoint& v32, const AtomPoint& v33, __VA_ARGS__) constValue { \
	AtomPoint b00 = v00; \
	AtomPoint b01 = v01; \
	AtomPoint b02 = v02; \
	AtomPoint b03 = v03; \
	AtomPoint b10 = v10; \
	AtomPoint b11 = v11; \
	AtomPoint b12 = v12; \
	AtomPoint b13 = v13; \
	AtomPoint b20 = v20; \
	AtomPoint b21 = v21; \
	AtomPoint b22 = v22; \
	AtomPoint b23 = v23; \
	AtomPoint b30 = v30; \
	AtomPoint b31 = v31; \
	AtomPoint b32 = v32; \
	AtomPoint b33 = v33; \
	code \
} \
\
returnValue method(const AtomVector2& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.x; \
	AtomPoint b03 = v.y; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.x; \
	AtomPoint b13 = v.y; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.x; \
	AtomPoint b23 = v.y; \
	AtomPoint b30 = v.x; \
	AtomPoint b31 = v.y; \
	AtomPoint b32 = v.x; \
	AtomPoint b33 = v.y; \
	code \
} \
\
returnValue method(const AtomVector3& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = v.x; \
	AtomPoint b31 = v.y; \
	AtomPoint b32 = v.z; \
	AtomPoint b33 = 0.0f;\
	code \
} \
\
returnValue method(const AtomVector4& v, __VA_ARGS__) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b03 = v.w; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b13 = v.w; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	AtomPoint b23 = v.w; \
	AtomPoint b30 = v.x; \
	AtomPoint b31 = v.y; \
	AtomPoint b32 = v.z; \
	AtomPoint b33 = v.w; \
	code \
} \
\
returnValue method(const AtomMatrix2& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	AtomPoint b22 = 0.0f; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = 0.0f; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix3& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix4& m, __VA_ARGS__) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b03 = m.m03; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b13 = m.m13; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	AtomPoint b23 = m.m23; \
	AtomPoint b30 = m.m30; \
	AtomPoint b31 = m.m31; \
	AtomPoint b32 = m.m32; \
	AtomPoint b33 = m.m33; \
	code \
}

#define DefineMatrix2OperatorMethod(returnValue, method, constValue, code) \
returnValue method(const AtomPoint& v) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	code \
} \
\
returnValue method(const AtomVector2& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	code \
} \
\
returnValue method(const AtomVector3& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.z; \
	AtomPoint b11 = 0.0f; \
	code \
} \
\
returnValue method(const AtomVector4& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.z; \
	AtomPoint b11 = v.w; \
	code \
} \
\
returnValue method(const AtomMatrix2& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
} \
\
returnValue method(const AtomMatrix3& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
} \
\
returnValue method(const AtomMatrix4& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	code \
}

#define DefineMatrix2DOperatorMethod(returnValue, method, constValue, code) \
returnValue method(const AtomPoint& v) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	AtomPoint b20 = v; \
	AtomPoint b21 = v; \
	code \
} \
\
returnValue method(const AtomVector2& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	code \
} \
\
returnValue method(const AtomVector3& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	code \
} \
\
returnValue method(const AtomVector4& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	code \
} \
\
returnValue method(const AtomMatrix2& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	code \
} \
\
returnValue method(const AtomMatrix3& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	code \
} \
\
returnValue method(const AtomMatrix4& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	code \
}

#define DefineMatrix3OperatorMethod(returnValue, method, constValue, code) \
returnValue method(const AtomPoint& v) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b02 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	AtomPoint b12 = v; \
	AtomPoint b20 = v; \
	AtomPoint b21 = v; \
	AtomPoint b22 = v; \
	code \
} \
\
returnValue method(const AtomVector2& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomVector3& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	code \
} \
\
returnValue method(const AtomVector4& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	code \
} \
\
returnValue method(const AtomMatrix2& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix3& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	code \
} \
\
returnValue method(const AtomMatrix4& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	code \
}

#define DefineMatrix4OperatorMethod(returnValue, method, constValue, code) \
returnValue method(const AtomPoint& v) constValue { \
	AtomPoint b00 = v; \
	AtomPoint b01 = v; \
	AtomPoint b02 = v; \
	AtomPoint b03 = v; \
	AtomPoint b10 = v; \
	AtomPoint b11 = v; \
	AtomPoint b12 = v; \
	AtomPoint b13 = v; \
	AtomPoint b20 = v; \
	AtomPoint b21 = v; \
	AtomPoint b22 = v; \
	AtomPoint b23 = v; \
	AtomPoint b30 = v; \
	AtomPoint b31 = v; \
	AtomPoint b32 = v; \
	AtomPoint b33 = v; \
	code \
} \
\
returnValue method(const AtomVector2& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.x; \
	AtomPoint b03 = v.y; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.x; \
	AtomPoint b13 = v.y; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.x; \
	AtomPoint b23 = v.y; \
	AtomPoint b30 = v.x; \
	AtomPoint b31 = v.y; \
	AtomPoint b32 = v.x; \
	AtomPoint b33 = v.y; \
	code \
} \
\
returnValue method(const AtomVector3& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = v.x; \
	AtomPoint b31 = v.y; \
	AtomPoint b32 = v.z; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomVector4& v) constValue { \
	AtomPoint b00 = v.x; \
	AtomPoint b01 = v.y; \
	AtomPoint b02 = v.z; \
	AtomPoint b03 = v.w; \
	AtomPoint b10 = v.x; \
	AtomPoint b11 = v.y; \
	AtomPoint b12 = v.z; \
	AtomPoint b13 = v.w; \
	AtomPoint b20 = v.x; \
	AtomPoint b21 = v.y; \
	AtomPoint b22 = v.z; \
	AtomPoint b23 = v.w; \
	AtomPoint b30 = v.x; \
	AtomPoint b31 = v.y; \
	AtomPoint b32 = v.z; \
	AtomPoint b33 = v.w; \
	code \
} \
\
returnValue method(const AtomMatrix2& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = 0.0f; \
	AtomPoint b21 = 0.0f; \
	AtomPoint b22 = 0.0f; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix2D& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = 0.0f; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = 0.0f; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = 0.0f; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix3& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b03 = 0.0f; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b13 = 0.0f; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	AtomPoint b23 = 0.0f; \
	AtomPoint b30 = 0.0f; \
	AtomPoint b31 = 0.0f; \
	AtomPoint b32 = 0.0f; \
	AtomPoint b33 = 0.0f; \
	code \
} \
\
returnValue method(const AtomMatrix4& m) constValue { \
	AtomPoint b00 = m.m00; \
	AtomPoint b01 = m.m01; \
	AtomPoint b02 = m.m02; \
	AtomPoint b03 = m.m03; \
	AtomPoint b10 = m.m10; \
	AtomPoint b11 = m.m11; \
	AtomPoint b12 = m.m12; \
	AtomPoint b13 = m.m13; \
	AtomPoint b20 = m.m20; \
	AtomPoint b21 = m.m21; \
	AtomPoint b22 = m.m22; \
	AtomPoint b23 = m.m23; \
	AtomPoint b30 = m.m30; \
	AtomPoint b31 = m.m31; \
	AtomPoint b32 = m.m32; \
	AtomPoint b33 = m.m33; \
	code \
}

AtomMatrix2::AtomMatrix2() {
	m00 = 0.0f;
	m01 = 0.0f;
	m10 = 0.0f;
	m11 = 0.0f;
}

DefineMatrix2Method(, AtomMatrix2::AtomMatrix2, , {
	m00 = b00;
	m01 = b01;
	m10 = b10;
	m11 = b11;
});

AtomMatrix2 AtomMatrix2::Clone() const {
	AtomMatrix2 out;

	out.m00 = m00;
	out.m01 = m01;
	out.m10 = m10;
	out.m11 = m11;

	return out;
}

void AtomMatrix2::Copy(AtomMatrix2* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
}

void AtomMatrix2::Copy(AtomMatrix2D* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
}

void AtomMatrix2::Copy(AtomMatrix3* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
}

void AtomMatrix2::Copy(AtomMatrix4* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
}

void AtomMatrix2::Identity() {
	m00 = 1.0f;
	m01 = 0.0f;
	m10 = 0.0f;
	m11 = 1.0f;
}

DefineMatrix2Method(void, AtomMatrix2::Set, , {
	m00 = b00;
	m01 = b01;
	m10 = b10;
	m11 = b11;
});

void AtomMatrix2::Invert() {
	AtomPoint a0 = m00;
	AtomPoint a1 = m01;
	AtomPoint a2 = m10;
	AtomPoint a3 = m11;

	AtomPoint det = a0 * a3 - a2 * a1;

	if (!det) {
		return;
	}

	det = 1.0f / det;

	m00 = a3 * det;
	m01 = -a1 * det;
	m10 = -a2 * det;
	m11 = a0 * det;
}

AtomPoint AtomMatrix2::Determinant() const {
	return m00 * m11 - m10 * m01;
}

DefineMatrix2Method(void, AtomMatrix2::Add, , {
	m00 += b00;
	m01 += b01;
	m10 += b10;
	m11 += b11;
});

DefineMatrix2Method(void, AtomMatrix2::Subtract, , {
	m00 -= b00;
	m01 -= b01;
	m10 -= b10;
	m11 -= b11;
});

DefineMatrix2Method(void, AtomMatrix2::Multiply, , {
	m00 = m00 * b00 + m10 * b01;
	m01 = m01 * b00 + m11 * b01;
	m10 = m00 * b10 + m10 * b11;
	m11 = m01 * b10 + m11 * b11;
});

void AtomMatrix2::MultiplyScaler(const AtomPoint& scale) {
	m00 *= scale;
	m01 *= scale;
	m10 *= scale;
	m11 *= scale;
}

DefineMatrix2MethodArgs(void, AtomMatrix2::MultiplyScalerAndAdd, , {
	m00 += b00 * scale;
	m01 += b01 * scale;
	m10 += b10 * scale;
	m11 += b11 * scale;
}, const AtomPoint& scale);

DefineMatrix2Method(void, AtomMatrix2::Scale, , {
	m00 = m00 * b00;
	m01 = m01 * b00;
	m10 = m10 * b01;
	m11 = m11 * b11;
});

void AtomMatrix2::FromRotation(const AtomPoint& rad) {
	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	m00 = c;
	m01 = s;
	m10 = -s;
	m11 = c;
}

DefineMatrix2Method(void, AtomMatrix2::FromScaling, , {
	m00 = b00;
	m01 = 0.0f;
	m10 = 0.0f;
	m11 = b01;
});

AtomPoint AtomMatrix2::Frob() const {
	return std::sqrt(m00 * m00 + m01 * m01 + m10 * m10 + m11 * m11);
}

DefineMatrix2Method(bool, AtomMatrix2::ExactEquals, const, {
	return m00 == b00 && m01 == b01 && m10 == b10 && m11 == b11;
});

DefineMatrix2Method(bool, AtomMatrix2::Equals, const, {
	return (
		std::abs(m00 - b00) <= ATOM_EPSILON * std::max(std::max(std::abs(m00), std::abs(b00)), 1.0f) &&
		std::abs(m01 - b01) <= ATOM_EPSILON * std::max(std::max(std::abs(m01), std::abs(b01)), 1.0f) &&
		std::abs(m10 - b10) <= ATOM_EPSILON * std::max(std::max(std::abs(m10), std::abs(b10)), 1.0f) &&
		std::abs(m11 - b11) <= ATOM_EPSILON * std::max(std::max(std::abs(m11), std::abs(b11)), 1.0f)
	);
});

DefineMatrix2OperatorMethod(AtomMatrix2, AtomMatrix2::operator+, const, {
	AtomMatrix2 out;

	out.m00 = m00 + b00;
	out.m01 = m01 + b01;
	out.m10 = m10 + b10;
	out.m11 = m11 + b11;

	return out;
});

DefineMatrix2OperatorMethod(AtomMatrix2, AtomMatrix2::operator-, const, {
	AtomMatrix2 out;

	out.m00 = m00 - b00;
	out.m01 = m01 - b01;
	out.m10 = m10 - b10;
	out.m11 = m11 - b11;

	return out;
});

DefineMatrix2OperatorMethod(AtomMatrix2, AtomMatrix2::operator*, const, {
	AtomMatrix2 out;

	out.m00 = m00 * b00 + m10 * b01;
	out.m01 = m01 * b00 + m11 * b01;
	out.m10 = m00 * b10 + m10 * b11;
	out.m11 = m01 * b10 + m11 * b11;

	return out;
});

DefineMatrix2OperatorMethod(AtomMatrix2&, AtomMatrix2::operator+=, , {
	m00 += b00;
	m01 += b01;
	m10 += b10;
	m11 += b11;

	return *this;
});

DefineMatrix2OperatorMethod(AtomMatrix2&, AtomMatrix2::operator-=, , {
	m00 -= b00;
	m01 -= b01;
	m10 -= b10;
	m11 -= b11;

	return *this;
});

DefineMatrix2OperatorMethod(AtomMatrix2&, AtomMatrix2::operator*=, , {
	m00 = m00 * b00 + m10 * b01;
	m01 = m01 * b00 + m11 * b01;
	m10 = m00 * b10 + m10 * b11;
	m11 = m01 * b10 + m11 * b11;

	return *this;
});

DefineMatrix2OperatorMethod(AtomMatrix2&, AtomMatrix2::operator=, , {
	m00 = b00;
	m01 = b01;
	m10 = b10;
	m11 = b11;

	return *this;
});

DefineMatrix2OperatorMethod(bool, AtomMatrix2::operator==, const, {
	return Equals(b00, b01, b10, b11);
});

AtomMatrix2& AtomMatrix2::operator++() {
	m00++;
	m01++;
	m10++;
	m11++;

	return *this;
}

AtomMatrix2& AtomMatrix2::operator--() {
	m00--;
	m01--;
	m10--;
	m11--;

	return *this;
}

std::string AtomMatrix2::ToString() const {
	std::string result = "mat2(";

	result += std::to_string(m00);
	result += ", ";
	result += std::to_string(m01);
	result += ", ";
	result += std::to_string(m10);
	result += ", ";
	result += std::to_string(m11);

	result += ")";

	return result;
}

void AtomMatrix2::Adjoint() {
	AtomPoint b00 = m00;

	m00 = m11;
	m01 = -m01;
	m10 = -m10;
	m11 = b00;
}

void AtomMatrix2::Rotate(const AtomPoint& rad) {
	AtomPoint a0 = m00;
	AtomPoint a1 = m01;
	AtomPoint a2 = m10;
	AtomPoint a3 = m11;

	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	m00 = a0 * c + a2 * s;
	m01 = a1 * c + a3 * s;
	m10 = a0 * -s + a2 * c;
	m11 = a1 * -s + a3 * c;
}

void AtomMatrix2::Transpose() {
	AtomPoint b01 = m01;

	m01 = m10;
	m10 = b01;
}

void AtomMatrix2::Transpose(AtomMatrix2* m) {
	if (!m) {
		return;
	}

	if (this == m) {
		AtomPoint b01 = m01;

		m01 = m10;
		m10 = b01;
		
		return;
	}

	m00 = m->m00;
	m01 = m->m01;
	m10 = m->m10;
	m11 = m->m11;
}

AtomMatrix2D::AtomMatrix2D() {
	m00 = 0.0f;
	m01 = 0.0f;
	m10 = 0.0f;
	m11 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
}

DefineMatrix2DMethod(, AtomMatrix2D::AtomMatrix2D, , {
	m00 = b00;
	m01 = b01;
	m10 = b10;
	m11 = b11;
	m20 = b20;
	m21 = b21;
});

AtomMatrix2D AtomMatrix2D::Clone() const {
	AtomMatrix2D out;

	out.m00 = m00;
	out.m01 = m01;
	out.m10 = m10;
	out.m11 = m11;
	out.m20 = m20;
	out.m21 = m21;
	
	return out;
}

void AtomMatrix2D::Copy(AtomMatrix2* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
}

void AtomMatrix2D::Copy(AtomMatrix2D* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
	m->m20 = m20;
	m->m21 = m21;
}

void AtomMatrix2D::Copy(AtomMatrix3* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
	m->m20 = m20;
	m->m21 = m21;
}

void AtomMatrix2D::Copy(AtomMatrix4* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
	m->m20 = m20;
	m->m21 = m21;
}

void AtomMatrix2D::Identity() {
	m00 = 1.0f;
	m01 = 0.0f;
	m10 = 0.0f;
	m11 = 1.0f;
	m20 = 0.0f;
	m21 = 0.0f;
}

DefineMatrix2DMethod(void, AtomMatrix2D::Set, , {
	m00 = b00;
	m01 = b01;
	m10 = b10;
	m11 = b11;
	m20 = b20;
	m21 = b21;
});

void AtomMatrix2D::Invert() {
	AtomPoint aa = m00;
	AtomPoint ab = m01;
	AtomPoint ac = m10;
	AtomPoint ad = m11;

	AtomPoint atx = m20;
	AtomPoint aty = m21;

	AtomPoint det = aa * ad - ab * ac;
	if (!det) {
		return;
	}

	det = 1.0f / det;

	m00 = ad * det;
	m01 = -ab * det;
	m10 = -ac * det;
	m11 = aa * det;
	m20 = (ac * aty - ad * atx) * det;
	m21 = (ab * atx - aa * aty) * det;
}

AtomPoint AtomMatrix2D::Determinant() const {
	return m00 * m11 - m01 * m10;
}

DefineMatrix2DMethod(void, AtomMatrix2D::Add, , {
	m00 += b00;
	m01 += b01;
	m10 += b10;
	m11 += b11;
	m20 += b20;
	m21 += b21;
});

DefineMatrix2DMethod(void, AtomMatrix2D::Subtract, , {
	m00 -= b00;
	m01 -= b01;
	m10 -= b10;
	m11 -= b11;
	m20 -= b20;
	m21 -= b21;
});

DefineMatrix2DMethod(void, AtomMatrix2D::Multiply, , {
	m00 = m00 * b00 + m10 * b01;
	m01 = m01 * b00 + m11 * b01;
	m10 = m00 * b10 + m10 * b11;
	m11 = m01 * b10 + m11 * b11;
	m20 = m00 * b20 + m10 * b21 + m20;
	m21 = m01 * b20 + m11 * b21 + m21;
});

void AtomMatrix2D::MultiplyScaler(const AtomPoint& scale) {
	m00 *= scale;
	m01 *= scale;
	m10 *= scale;
	m11 *= scale;
	m20 *= scale;
	m21 *= scale;
}

DefineMatrix2DMethodArgs(void, AtomMatrix2D::MultiplyScalerAndAdd, , {
	m00 += b00 * scale;
	m01 += b01 * scale;
	m10 += b10 * scale;
	m11 += b11 * scale;
	m20 += b20 * scale;
	m21 += b21 * scale;
}, const AtomPoint& scale);

DefineMatrix2DMethod(void, AtomMatrix2D::Scale, , {
	m00 = m00 * b00;
	m01 = m01 * b00;
	m10 = m10 * b01;
	m11 = m11 * b01;
});

DefineMatrix2DMethod(void, AtomMatrix2D::FromScaling, , {
	m00 = b00;
	m01 = 0.0f;
	m10 = 0.0f;
	m11 = b01;
	m20 = 0.0f;
	m21 = 0.0f;
});

AtomPoint AtomMatrix2D::Frob() const {
	return std::sqrt(m00 * m00 + m01 * m01 + m10 * m10 + m11 * m11 + m20 * m20 + m21 * m21 + 1.0f);
}

DefineMatrix2DMethod(bool, AtomMatrix2D::ExactEquals, const, {
	return (
		m00 == b00 && m01 == b01 &&
		m10 == b10 && m11 == b11 &&
		m20 == b20 && m21 == b21
	);
});

DefineMatrix2DMethod(bool, AtomMatrix2D::Equals, const, {
	return (
		std::abs(m00 - b00) <= ATOM_EPSILON * std::max(std::max(std::abs(m00), std::abs(b00)), 1.0f) &&
		std::abs(m01 - b01) <= ATOM_EPSILON * std::max(std::max(std::abs(m01), std::abs(b01)), 1.0f) &&
		std::abs(m10 - b10) <= ATOM_EPSILON * std::max(std::max(std::abs(m10), std::abs(b10)), 1.0f) &&
		std::abs(m11 - b11) <= ATOM_EPSILON * std::max(std::max(std::abs(m11), std::abs(b11)), 1.0f) &&
		std::abs(m20 - b20) <= ATOM_EPSILON * std::max(std::max(std::abs(m20), std::abs(b20)), 1.0f) &&
		std::abs(m21 - b21) <= ATOM_EPSILON * std::max(std::max(std::abs(m21), std::abs(b21)), 1.0f)
	);
});

DefineMatrix2DOperatorMethod(AtomMatrix2D, AtomMatrix2D::operator+, const, {
	AtomMatrix2D out;

	out.m00 = m00 + b00;
	out.m01 = m01 + b01;
	out.m10 = m10 + b10;
	out.m11 = m11 + b11;
	out.m20 = m20 + b20;
	out.m21 = m21 + b21;

	return out;
});

DefineMatrix2DOperatorMethod(AtomMatrix2D, AtomMatrix2D::operator-, const, {
	AtomMatrix2D out;

	out.m00 = m00 - b00;
	out.m01 = m01 - b01;
	out.m10 = m10 - b10;
	out.m11 = m11 - b11;
	out.m20 = m20 - b20;
	out.m21 = m21 - b21;

	return out;
});

DefineMatrix2DOperatorMethod(AtomMatrix2D, AtomMatrix2D::operator*, const, {
	AtomMatrix2D out;

	out.m00 = m00 * b00 + m10 * b01;
	out.m01 = m01 * b00 + m11 * b01;
	out.m10 = m00 * b10 + m10 * b11;
	out.m11 = m01 * b10 + m11 * b11;
	out.m20 = m00 * b20 + m10 * b21 + m20;
	out.m21 = m01 * b20 + m11 * b21 + m21;

	return out;
});

DefineMatrix2DOperatorMethod(AtomMatrix2D&, AtomMatrix2D::operator+=, , {
	m00 += b00;
	m01 += b01;
	m10 += b10;
	m11 += b11;
	m20 += b20;
	m21 += b21;

	return *this;
});

DefineMatrix2DOperatorMethod(AtomMatrix2D&, AtomMatrix2D::operator-=, , {
	m00 -= b00;
	m01 -= b01;
	m10 -= b10;
	m11 -= b11;
	m20 -= b20;
	m21 -= b21;

	return *this;
});

DefineMatrix2DOperatorMethod(AtomMatrix2D&, AtomMatrix2D::operator*=, , {
	m00 = m00 * b00 + m10 * b01;
	m01 = m01 * b00 + m11 * b01;
	m10 = m00 * b10 + m10 * b11;
	m11 = m01 * b10 + m11 * b11;
	m20 = m00 * b20 + m10 * b21 + m20;
	m21 = m01 * b20 + m11 * b21 + m21;

	return *this;
});

DefineMatrix2DOperatorMethod(AtomMatrix2D&, AtomMatrix2D::operator=, , {
	m00 = b00;
	m01 = b01;
	m10 = b10;
	m11 = b11;
	m20 = b20;
	m21 = b21;

	return *this;
});

DefineMatrix2DOperatorMethod(bool, AtomMatrix2D::operator==, const, {
	return Equals(b00, b01, b10, b11, b20, b21);
});

AtomMatrix2D& AtomMatrix2D::operator++() {
	m00++;
	m01++;
	m10++;
	m11++;
	m20++;
	m21++;

	return *this;
}

AtomMatrix2D& AtomMatrix2D::operator--() {
	m00--;
	m01--;
	m10--;
	m11--;
	m20--;
	m21--;

	return *this;
}

std::string AtomMatrix2D::ToString() const {
	std::string result = "mat2d(";

	result += std::to_string(m00);
	result += ", ";
	result += std::to_string(m01);
	result += ", ";
	result += std::to_string(m10);
	result += ", ";
	result += std::to_string(m11);
	result += ", ";
	result += std::to_string(m20);
	result += ", ";
	result += std::to_string(m21);

	result += ")";

	return result;
}

void AtomMatrix2D::Rotate(const AtomPoint& rad) {
	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	m00 = m00 * c + m10 * s;
	m01 = m01 * c + m11 * s;
	m10 = m00 * -s + m10 * c;
	m11 = m01 * -s + m11 * c;
}

DefineMatrix2DMethod(void, AtomMatrix2D::Translate, , {
	m20 = m00 * b00 + m10 * b01 + m20;
	m21 = m01 * b00 + m11 * b01 + m21;
});

DefineMatrix2DMethod(void, AtomMatrix2D::FromTranslation, , {
	m00 = 1.0f;
	m01 = 0.0f;
	m10 = 0.0f;
	m11 = 1.0f;
	m20 = b00;
	m21 = b01;
});

void AtomMatrix2D::FromRotation(const AtomPoint& rad) {
	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	m00 = c;
	m01 = s;
	m10 = -s;
	m11 = c;
	m20 = 0.0f;
	m21 = 0.0f;
}

AtomMatrix3::AtomMatrix3() {
	m00 = 0.0f;
	m01 = 0.0f;
	m02 = 0.0f;
	m10 = 0.0f;
	m11 = 0.0f;
	m12 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = 0.0f;
}

DefineMatrix3Method(, AtomMatrix3::AtomMatrix3, , {
	m00 = b00;
	m01 = b01;
	m02 = b02;
	m10 = b10;
	m11 = b11;
	m12 = b12;
	m20 = b20;
	m21 = b21;
	m22 = b22;
});

AtomMatrix3 AtomMatrix3::Clone() const {
	AtomMatrix3 out;

	out.m00 = m00;
	out.m01 = m01;
	out.m02 = m02;
	out.m10 = m10;
	out.m11 = m11;
	out.m12 = m12;
	out.m20 = m20;
	out.m21 = m21;
	out.m22 = m22;

	return out;
}

void AtomMatrix3::Copy(AtomMatrix2* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
}

void AtomMatrix3::Copy(AtomMatrix2D* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
	m->m20 = m20;
	m->m21 = m21;
}

void AtomMatrix3::Copy(AtomMatrix3* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m02 = m02;
	m->m10 = m10;
	m->m11 = m11;
	m->m12 = m12;
	m->m20 = m20;
	m->m21 = m21;
	m->m22 = m22;
}

void AtomMatrix3::Copy(AtomMatrix4* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m02 = m02;
	m->m10 = m10;
	m->m11 = m11;
	m->m12 = m12;
	m->m20 = m20;
	m->m21 = m21;
	m->m22 = m22;
}

void AtomMatrix3::Identity() {
	m00 = 1.0f;
	m01 = 0.0f;
	m02 = 0.0f;
	m10 = 0.0f;
	m11 = 1.0f;
	m12 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = 1.0f;
}

DefineMatrix3Method(void, AtomMatrix3::Set, , {
	m00 = b00;
	m01 = b01;
	m02 = b02;
	m10 = b10;
	m11 = b11;
	m12 = b12;
	m20 = b20;
	m21 = b21;
	m22 = b22;
});

void AtomMatrix3::Invert() {
	AtomPoint b01 = m22 * m11 - m12 * m21;
	AtomPoint b11 = -m22 * m10 + m12 * m20;
	AtomPoint b21 = m21 * m10 - m11 * m20;

	AtomPoint det = m00 * b01 + m01 * b11 + m02 * b21;
	if (!det) {
		return;
	}

	det = 1.0f / det;

	m00 = b01 * det;
	m01 = (-m22 * m01 + m02 * m21) * det;
	m02 = (m12 * m01 - m02 * m11) * det;
	m10 = b11 * det;
	m11 = (m22 * m00 - m02 * m20) * det;
	m12 = (-m12 * m00 + m02 * m10) * det;
	m20 = b21 * det;
	m21 = (-m21 * m00 + m01 * m20) * det;
	m22 = (m11 * m00 - m01 * m10) * det;
}

AtomPoint AtomMatrix3::Determinant() const {
	return (
		m00 * (m22 * m11 - m12 * m21) +
		m01 * (-m22 * m10 + m12 * m20) + 
		m02 * (m21 * m10 - m11 * m20)
	);
}

DefineMatrix3Method(void, AtomMatrix3::Add, , {
	m00 += b00;
	m01 += b01;
	m02 += b02;
	m10 += b10;
	m11 += b11;
	m12 += b12;
	m20 += b20;
	m21 += b21;
	m22 += b22;
});

DefineMatrix3Method(void, AtomMatrix3::Subtract, , {
	m00 -= b00;
	m01 -= b01;
	m02 -= b02;
	m10 -= b10;
	m11 -= b11;
	m12 -= b12;
	m20 -= b20;
	m21 -= b21;
	m22 -= b22;
});

DefineMatrix3Method(void, AtomMatrix3::Multiply, , {
	m00 = b00 * m00 + b01 * m10 + b02 * m20;
	m01 = b00 * m01 + b01 * m11 + b02 * m21;
	m02 = b00 * m02 + b01 * m12 + b02 * m22;

	m10 = b10 * m00 + b11 * m10 + b12 * m20;
	m11 = b10 * m01 + b11 * m11 + b12 * m21;
	m12 = b10 * m02 + b11 * m12 + b12 * m22;

	m20 = b20 * m00 + b21 * m10 + b22 * m20;
	m21 = b20 * m01 + b21 * m11 + b22 * m21;
	m22 = b20 * m02 + b21 * m12 + b22 * m22;
});

void AtomMatrix3::MultiplyScaler(const AtomPoint& scale) {
	m00 *= scale;
	m01 *= scale;
	m02 *= scale;
	m10 *= scale;
	m11 *= scale;
	m12 *= scale;
	m20 *= scale;
	m21 *= scale;
	m22 *= scale;
}

DefineMatrix3MethodArgs(void, AtomMatrix3::MultiplyScalerAndAdd, , {
	m00 += b00 * scale;
	m01 += b01 * scale;
	m02 += b02 * scale;
	m10 += b10 * scale;
	m11 += b11 * scale;
	m12 += b12 * scale;
	m20 += b20 * scale;
	m21 += b21 * scale;
	m22 += b22 * scale;
}, const AtomPoint& scale);

DefineMatrix3Method(void, AtomMatrix3::Scale, , {
	m00 = b00 * m00;
	m01 = b00 * m01;
	m02 = b00 * m02;

	m10 = b01 * m10;
	m11 = b01 * m11;
	m12 = b01 * m12;
});

DefineMatrix3Method(void, AtomMatrix3::FromScaling, , {
	m00 = b00;
	m01 = 0.0f;
	m02 = 0.0f;
	m10 = 0.0f;
	m11 = b01;
	m12 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = 1.0f;
});

AtomPoint AtomMatrix3::Frob() const {
	return std::sqrt(
		m00 * m00 +
		m01 * m01 +
		m02 * m02 +
		m10 * m10 +
		m11 * m11 +
		m12 * m12 +
		m20 * m20 +
		m21 * m21 +
		m22 * m22
	);
}

DefineMatrix3Method(bool, AtomMatrix3::ExactEquals, const, {
	return (
		m00 == b00 && m01 == b01 && m02 == b02 &&
		m10 == b10 && m11 == b11 && m12 == b12 &&
		m20 == b20 && m21 == b21 && m22 == b22
	);
});

DefineMatrix3Method(bool, AtomMatrix3::Equals, const, {
	return (
		std::abs(m00 - b00) <= ATOM_EPSILON * std::max(std::max(std::abs(m00), std::abs(b00)), 1.0f) &&
		std::abs(m01 - b01) <= ATOM_EPSILON * std::max(std::max(std::abs(m01), std::abs(b01)), 1.0f) &&
		std::abs(m02 - b02) <= ATOM_EPSILON * std::max(std::max(std::abs(m02), std::abs(b02)), 1.0f) &&
		std::abs(m10 - b10) <= ATOM_EPSILON * std::max(std::max(std::abs(m10), std::abs(b10)), 1.0f) &&
		std::abs(m11 - b11) <= ATOM_EPSILON * std::max(std::max(std::abs(m11), std::abs(b11)), 1.0f) &&
		std::abs(m12 - b12) <= ATOM_EPSILON * std::max(std::max(std::abs(m12), std::abs(b12)), 1.0f) &&
		std::abs(m20 - b20) <= ATOM_EPSILON * std::max(std::max(std::abs(m20), std::abs(b20)), 1.0f) &&
		std::abs(m21 - b21) <= ATOM_EPSILON * std::max(std::max(std::abs(m21), std::abs(b21)), 1.0f) &&
		std::abs(m22 - b22) <= ATOM_EPSILON * std::max(std::max(std::abs(m22), std::abs(b22)), 1.0f)
	);
});

DefineMatrix3OperatorMethod(AtomMatrix3, AtomMatrix3::operator+, const, {
	AtomMatrix3 out;

	out.m00 = m00 + b00;
	out.m01 = m01 + b01;
	out.m02 = m02 + b02;
	out.m10 = m10 + b10;
	out.m11 = m11 + b11;
	out.m12 = m12 + b12;
	out.m20 = m20 + b20;
	out.m21 = m21 + b21;
	out.m22 = m22 + b22;

	return out;
});

DefineMatrix3OperatorMethod(AtomMatrix3, AtomMatrix3::operator-, const, {
	AtomMatrix3 out;

	out.m00 = m00 - b00;
	out.m01 = m01 - b01;
	out.m02 = m02 - b02;
	out.m10 = m10 - b10;
	out.m11 = m11 - b11;
	out.m12 = m12 - b12;
	out.m20 = m20 - b20;
	out.m21 = m21 - b21;
	out.m22 = m22 - b22;

	return out;
});

DefineMatrix3OperatorMethod(AtomMatrix3, AtomMatrix3::operator*, const, {
	AtomMatrix3 out;

	out.m00 = b00 * m00 + b01 * m10 + b02 * m20;
	out.m01 = b00 * m01 + b01 * m11 + b02 * m21;
	out.m02 = b00 * m02 + b01 * m12 + b02 * m22;

	out.m10 = b10 * m00 + b11 * m10 + b12 * m20;
	out.m11 = b10 * m01 + b11 * m11 + b12 * m21;
	out.m12 = b10 * m02 + b11 * m12 + b12 * m22;

	out.m20 = b20 * m00 + b21 * m10 + b22 * m20;
	out.m21 = b20 * m01 + b21 * m11 + b22 * m21;
	out.m22 = b20 * m02 + b21 * m12 + b22 * m22;

	return out;
});

DefineMatrix3OperatorMethod(AtomMatrix3&, AtomMatrix3::operator+=, , {
	m00 += b00;
	m01 += b01;
	m02 += b02;
	m10 += b10;
	m11 += b11;
	m12 += b12;
	m20 += b20;
	m21 += b21;
	m22 += b12;

	return *this;
});

DefineMatrix3OperatorMethod(AtomMatrix3&, AtomMatrix3::operator-=, , {
	m00 -= b00;
	m01 -= b01;
	m02 -= b02;
	m10 -= b10;
	m11 -= b11;
	m12 -= b12;
	m20 -= b20;
	m21 -= b21;
	m22 -= b22;

	return *this;
});

DefineMatrix3OperatorMethod(AtomMatrix3&, AtomMatrix3::operator*=, , {
	m00 = b00 * m00 + b01 * m10 + b02 * m20;
	m01 = b00 * m01 + b01 * m11 + b02 * m21;
	m02 = b00 * m02 + b01 * m12 + b02 * m22;

	m10 = b10 * m00 + b11 * m10 + b12 * m20;
	m11 = b10 * m01 + b11 * m11 + b12 * m21;
	m12 = b10 * m02 + b11 * m12 + b12 * m22;

	m20 = b20 * m00 + b21 * m10 + b22 * m20;
	m21 = b20 * m01 + b21 * m11 + b22 * m21;
	m22 = b20 * m02 + b21 * m12 + b22 * m22;

	return *this;
});

DefineMatrix3OperatorMethod(AtomMatrix3&, AtomMatrix3::operator=, , {
	m00 = b00;
	m01 = b01;
	m02 = b02;
	m10 = b10;
	m11 = b11;
	m12 = b12;
	m20 = b20;
	m21 = b21;
	m22 = b22;

	return *this;
});

DefineMatrix3OperatorMethod(bool, AtomMatrix3::operator==, const, {
	return Equals(b00, b01, b02, b10, b11, b12, b20, b21, b22);
});

AtomMatrix3& AtomMatrix3::operator++() {
	m00++;
	m01++;
	m02++;
	m10++;
	m11++;
	m12++;
	m20++;
	m21++;
	m22++;

	return *this;
}

AtomMatrix3& AtomMatrix3::operator--() {
	m00--;
	m01--;
	m02--;
	m10--;
	m11--;
	m12--;
	m20--;
	m21--;
	m22--;

	return *this;
}

std::string AtomMatrix3::ToString() const {
	std::string result = "mat3(";

	result += std::to_string(m00);
	result += ", ";
	result += std::to_string(m01);
	result += ", ";
	result += std::to_string(m02);
	result += ", ";
	result += std::to_string(m10);
	result += ", ";
	result += std::to_string(m11);
	result += ", ";
	result += std::to_string(m12);
	result += ", ";
	result += std::to_string(m20);
	result += ", ";
	result += std::to_string(m21);
	result += ", ";
	result += std::to_string(m22);

	result += ")";

	return result;
}

void AtomMatrix3::Adjoint() {
	m00 = m11 * m22 - m12 * m21;
	m01 = m02 * m21 - m01 * m22;
	m02 = m01 * m12 - m02 * m11;
	m10 = m12 * m20 - m10 * m22;
	m11 = m00 * m22 - m02 * m20;
	m12 = m02 * m10 - m00 * m12;
	m20 = m10 * m21 - m11 * m20;
	m21 = m01 * m20 - m00 * m21;
	m22 = m00 * m11 - m01 * m10;
}

void AtomMatrix3::Rotate(const AtomPoint& rad) {
	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	m00 = c * m00 + s * m10;
	m01 = c * m01 + s * m11;
	m02 = c * m02 + s * m12;

	m10 = c * m10 - s * m00;
	m11 = c * m11 - s * m01;
	m12 = c * m12 - s * m02;
}

void AtomMatrix3::Transpose() {
	AtomPoint b01 = m01;
	AtomPoint b02 = m02;
	AtomPoint b12 = m12;

	m01 = m10;
	m02 = m12;
	m10 = b01;
	m12 = m20;
	m20 = b02;
	m21 = b12;
}

void AtomMatrix3::Transpose(AtomMatrix3* m) {
	if (!m) {
		return;
	}

	if (this == m) {
		AtomPoint b01 = m01;
		AtomPoint b02 = m02;
		AtomPoint b12 = m12;

		m01 = m10;
		m02 = m12;
		m10 = b01;
		m12 = m20;
		m20 = b02;
		m21 = b12;

		return;
	}

	m00 = m->m00;
	m01 = m->m01;
	m02 = m->m02;
	m10 = m->m10;
	m11 = m->m11;
	m12 = m->m12;
	m20 = m->m20;
	m21 = m->m21;
	m22 = m->m22;
}

DefineMatrix3Method(void, AtomMatrix3::Translate, , {
	m20 = b00 * m00 + b01 * m10 + m20;
	m21 = b00 * m01 + b01 * m11 + m21;
	m22 = b00 * m02 + b01 * m12 + m22;
});

DefineMatrix3Method(void, AtomMatrix3::FromTranslation, , {
	m00 = 1.0f;
	m01 = 0.0f;
	m02 = 0.0f;
	m10 = 0.0f;
	m11 = 1.0f;
	m12 = 0.0f;
	m20 = b00;
	m21 = b01;
	m22 = 1.0f;
});

void AtomMatrix3::FromQuat(const AtomQuat& q) {
	AtomPoint x = q.x;
	AtomPoint y = q.y;
	AtomPoint z = q.z;
	AtomPoint w = q.w;

	AtomPoint x2 = x + x;
	AtomPoint y2 = y + y;
	AtomPoint z2 = z + z;

	AtomPoint xx = x * x2;
	AtomPoint yx = y * x2;
	AtomPoint yy = y * y2;
	AtomPoint zx = z * x2;
	AtomPoint zy = z * y2;
	AtomPoint zz = z * z2;
	AtomPoint wx = w * x2;
	AtomPoint wy = w * y2;
	AtomPoint wz = w * z2;

	m00 = 1.0f - yy - zz;
	m10 = yx - wz;
	m20 = zx + wy;

	m01 = yx + wz;
	m11 = 1.0f - xx - zz;
	m21 = zy - wx;

	m02 = zx - wy;
	m12 = zy + wx;
	m22 = 1.0f - xx - yy;
}

void AtomMatrix3::NormalFromMatrix4(const AtomMatrix4& m) {
	AtomPoint a00 = m.m00;
	AtomPoint a01 = m.m01;
	AtomPoint a02 = m.m02;
	AtomPoint a03 = m.m03;
	AtomPoint a10 = m.m10;
	AtomPoint a11 = m.m11;
	AtomPoint a12 = m.m12;
	AtomPoint a13 = m.m13;
	AtomPoint a20 = m.m20;
	AtomPoint a21 = m.m21;
	AtomPoint a22 = m.m22;
	AtomPoint a23 = m.m23;
	AtomPoint a30 = m.m30;
	AtomPoint a31 = m.m31;
	AtomPoint a32 = m.m32;
	AtomPoint a33 = m.m33;

	AtomPoint b00 = a00 * a11 - a01 * a10;
	AtomPoint b01 = a00 * a12 - a02 * a10;
	AtomPoint b02 = a00 * a13 - a03 * a10;
	AtomPoint b03 = a01 * a12 - a02 * a11;
	AtomPoint b04 = a01 * a13 - a03 * a11;
	AtomPoint b05 = a02 * a13 - a03 * a12;
	AtomPoint b06 = a20 * a31 - a21 * a30;
	AtomPoint b07 = a20 * a32 - a22 * a30;
	AtomPoint b08 = a20 * a33 - a23 * a30;
	AtomPoint b09 = a21 * a32 - a22 * a31;
	AtomPoint b10 = a21 * a33 - a23 * a31;
	AtomPoint b11 = a22 * a33 - a23 * a32;


	AtomPoint det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;

	if (!det) {
		return;
	}

	det = 1.0f / det;

	m00 = (a11 * b11 - a12 * b10 + a13 * b09) * det;
	m01 = (a12 * b08 - a10 * b11 - a13 * b07) * det;
	m02 = (a10 * b10 - a11 * b08 + a13 * b06) * det;

	m10 = (a02 * b10 - a01 * b11 - a03 * b09) * det;
	m11 = (a00 * b11 - a02 * b08 + a03 * b07) * det;
	m12 = (a01 * b08 - a00 * b10 - a03 * b06) * det;

	m20 = (a31 * b05 - a32 * b04 + a33 * b03) * det;
	m21 = (a32 * b02 - a30 * b05 - a33 * b01) * det;
	m22 = (a30 * b04 - a31 * b02 + a33 * b00) * det;
}

void AtomMatrix3::Projection(const AtomPoint& width, const AtomPoint& height) {
	m00 = 2.0f / width;
	m01 = 0.0f;
	m02 = 0.0f;
	m10 = 0.0f;
	m11 = -2.0f / height;
	m12 = 0.0f;
	m20 = -1.0f;
	m21 = 1.0f;
	m22 = 1.0f;
}

void AtomMatrix3::FromRotation(const AtomPoint& rad) {
	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	m00 = c;
	m01 = s;
	m02 = 0.0f;

	m10 = -s;
	m11 = c;
	m12 = 0.0f;

	m20 = 0.0f;
	m21 = 0.0f;
	m22 = 1.0f;
}

AtomMatrix4::AtomMatrix4() {
	m00 = 0.0f;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = 0.0f;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = 0.0f;
	m23 = 0.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 0.0f;
}

DefineMatrix4Method(, AtomMatrix4::AtomMatrix4, , {
	m00 = b00;
	m01 = b01;
	m02 = b02;
	m03 = b03;
	m10 = b10;
	m11 = b11;
	m12 = b12;
	m13 = b13;
	m20 = b20;
	m21 = b21;
	m22 = b22;
	m23 = b23;
	m30 = b30;
	m31 = b31;
	m32 = b32;
	m33 = b33;
});

AtomMatrix4 AtomMatrix4::Clone() const {
	AtomMatrix4 out;

	out.m00 = m00;
	out.m01 = m01;
	out.m02 = m02;
	out.m03 = m03;
	out.m10 = m10;
	out.m11 = m11;
	out.m12 = m12;
	out.m13 = m13;
	out.m20 = m20;
	out.m21 = m21;
	out.m22 = m22;
	out.m23 = m23;
	out.m30 = m30;
	out.m31 = m31;
	out.m32 = m32;
	out.m33 = m33;

	return out;
}

void AtomMatrix4::Copy(AtomMatrix2* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
}

void AtomMatrix4::Copy(AtomMatrix2D* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m10 = m10;
	m->m11 = m11;
	m->m20 = m20;
	m->m21 = m21;
}

void AtomMatrix4::Copy(AtomMatrix3* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m02 = m02;
	m->m10 = m10;
	m->m11 = m11;
	m->m12 = m12;
	m->m20 = m20;
	m->m21 = m21;
	m->m22 = m22;
}

void AtomMatrix4::Copy(AtomMatrix4* m) const {
	if (!m) {
		return;
	}

	m->m00 = m00;
	m->m01 = m01;
	m->m02 = m02;
	m->m03 = m03;
	m->m10 = m10;
	m->m11 = m11;
	m->m12 = m12;
	m->m13 = m13;
	m->m20 = m20;
	m->m21 = m21;
	m->m22 = m22;
	m->m23 = m23;
	m->m30 = m30;
	m->m31 = m31;
	m->m32 = m32;
	m->m33 = m33;
}

void AtomMatrix4::Identity() {
	m00 = 1.0f;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = 1.0f;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = 1.0f;
	m23 = 0.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 1.0f;
}

DefineMatrix4Method(void, AtomMatrix4::Set, , {
	m00 = b00;
	m01 = b01;
	m02 = b02;
	m03 = b03;
	m10 = b10;
	m11 = b11;
	m12 = b12;
	m13 = b13;
	m20 = b20;
	m21 = b21;
	m22 = b22;
	m23 = b23;
	m30 = b30;
	m31 = b31;
	m32 = b32;
	m33 = b33;
});

void AtomMatrix4::Invert() {
	AtomPoint b00 = m00 * m11 - m01 * m10;
	AtomPoint b01 = m00 * m12 - m02 * m10;
	AtomPoint b02 = m00 * m13 - m03 * m10;
	AtomPoint b03 = m01 * m12 - m02 * m11;
	AtomPoint b04 = m01 * m13 - m03 * m11;
	AtomPoint b05 = m02 * m13 - m03 * m12;
	AtomPoint b06 = m20 * m31 - m21 * m30;
	AtomPoint b07 = m20 * m32 - m22 * m30;
	AtomPoint b08 = m20 * m33 - m23 * m30;
	AtomPoint b09 = m21 * m32 - m22 * m31;
	AtomPoint b10 = m21 * m33 - m23 * m31;
	AtomPoint b11 = m22 * m33 - m23 * m32;

	AtomPoint det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;

	if (!det) {
		return;
	}

	det = 1.0f / det;

	m00 = (m11 * b11 - m12 * b10 + m13 * b09) * det;
	m01 = (m02 * b10 - m01 * b11 - m03 * b09) * det;
	m02 = (m31 * b05 - m32 * b04 + m33 * b03) * det;
	m03 = (m22 * b04 - m21 * b05 - m23 * b03) * det;
	m10 = (m12 * b08 - m10 * b11 - m13 * b07) * det;
	m11 = (m00 * b11 - m02 * b08 + m03 * b07) * det;
	m12 = (m32 * b02 - m30 * b05 - m33 * b01) * det;
	m13 = (m20 * b05 - m22 * b02 + m23 * b01) * det;
	m20 = (m10 * b10 - m11 * b08 + m13 * b06) * det;
	m21 = (m01 * b08 - m00 * b10 - m03 * b06) * det;
	m22 = (m30 * b04 - m31 * b02 + m33 * b00) * det;
	m23 = (m21 * b02 - m20 * b04 - m23 * b00) * det;
	m30 = (m11 * b07 - m10 * b09 - m12 * b06) * det;
	m31 = (m00 * b09 - m01 * b07 + m02 * b06) * det;
	m32 = (m31 * b01 - m30 * b03 - m32 * b00) * det;
	m33 = (m20 * b03 - m21 * b01 + m22 * b00) * det;
}

AtomPoint AtomMatrix4::Determinant() const {
	AtomPoint b0 = m00 * m11 - m01 * m10;
	AtomPoint b1 = m00 * m12 - m02 * m10;
	AtomPoint b2 = m01 * m12 - m02 * m11;
	AtomPoint b3 = m20 * m31 - m21 * m30;
	AtomPoint b4 = m20 * m32 - m22 * m30;
	AtomPoint b5 = m21 * m32 - m22 * m31;
	AtomPoint b6 = m00 * b5 - m01 * b4 + m02 * b3;
	AtomPoint b7 = m10 * b5 - m11 * b4 + m12 * b3;
	AtomPoint b8 = m20 * b2 - m21 * b1 + m22 * b0;
	AtomPoint b9 = m30 * b2 - m31 * b1 + m32 * b0;

	return m13 * b6 - m03 * b7 + m33 * b8 - m23 * b9;
}

DefineMatrix4Method(void, AtomMatrix4::Add, , {
	m00 += b00;
	m01 += b01;
	m02 += b02;
	m03 += b03;
	m10 += b10;
	m11 += b11;
	m12 += b12;
	m13 += b13;
	m20 += b20;
	m21 += b21;
	m22 += b22;
	m23 += b23;
	m30 += b30;
	m31 += b31;
	m32 += b32;
	m33 += b33;
});

DefineMatrix4Method(void, AtomMatrix4::Subtract, , {
	m00 -= b00;
	m01 -= b01;
	m02 -= b02;
	m03 -= b03;
	m10 -= b10;
	m11 -= b11;
	m12 -= b12;
	m13 -= b13;
	m20 -= b20;
	m21 -= b21;
	m22 -= b22;
	m23 -= b23;
	m30 -= b30;
	m31 -= b31;
	m32 -= b32;
	m33 -= b33;
});

DefineMatrix4Method(void, AtomMatrix4::Multiply, , {
	AtomPoint b0 = b00;
	AtomPoint b1 = b01;
	AtomPoint b2 = b02;
	AtomPoint b3 = b03;
	
	m00 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	m01 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	m02 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	m03 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;

	b0 = b10;
	b1 = b11;
	b2 = b12;
	b3 = b13;

	m10 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	m11 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	m12 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	m13 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;

	b0 = b20;
	b1 = b21;
	b2 = b22;
	b3 = b23;

	m20 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	m21 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	m22 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	m23 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;

	b0 = b30;
	b1 = b31;
	b2 = b32;
	b3 = b33;

	m30 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	m31 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	m32 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	m33 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;
});

void AtomMatrix4::MultiplyScaler(const AtomPoint& scale) {
	m00 *= scale;
	m01 *= scale;
	m02 *= scale;
	m03 *= scale;
	m10 *= scale;
	m11 *= scale;
	m12 *= scale;
	m13 *= scale;
	m20 *= scale;
	m21 *= scale;
	m22 *= scale;
	m23 *= scale;
	m30 *= scale;
	m31 *= scale;
	m32 *= scale;
	m33 *= scale;
}

DefineMatrix4MethodArgs(void, AtomMatrix4::MultiplyScalerAndAdd, , {
	m00 += b00 * scale;
	m01 += b01 * scale;
	m02 += b02 * scale;
	m03 += b03 * scale;
	m10 += b10 * scale;
	m11 += b11 * scale;
	m12 += b12 * scale;
	m13 += b13 * scale;
	m20 += b20 * scale;
	m21 += b21 * scale;
	m22 += b22 * scale;
	m23 += b23 * scale;
	m30 += b30 * scale;
	m31 += b31 * scale;
	m32 += b32 * scale;
	m33 += b33 * scale;
}, const AtomPoint& scale);

DefineMatrix4Method(void, AtomMatrix4::Scale, , {
	m00 *= b00;
	m01 *= b00;
	m02 *= b00;
	m03 *= b00;
	m10 *= b01;
	m11 *= b01;
	m12 *= b01;
	m13 *= b01;
	m20 *= b02;
	m21 *= b02;
	m22 *= b02;
	m23 *= b02;
});

DefineMatrix4Method(void, AtomMatrix4::FromScaling, , {
	m00 = b00;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = b01;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = b02;
	m23 = 0.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 1.0f;
});

AtomPoint AtomMatrix4::Frob() const {
	return std::sqrt(
		m00 * m00 +
		m01 * m01 +
		m02 * m02 +
		m03 * m03 +
		m10 * m10 +
		m11 * m11 +
		m12 * m12 +
		m13 * m13 +
		m20 * m20 +
		m21 * m21 +
		m22 * m22 +
		m23 * m23 +
		m30 * m30 +
		m31 * m31 +
		m32 * m32 +
		m33 * m33
	);
}

DefineMatrix4Method(bool, AtomMatrix4::ExactEquals, const, {
	return (
		m00 == b00 && m01 == b01 && m02 == b02 && m03 == b03 &&
		m10 == b10 && m11 == b11 && m12 == b12 && m13 == b13 &&
		m20 == b20 && m21 == b21 && m22 == b22 && m23 == b23 &&
		m30 == b30 && m31 == b31 && m32 == b32 && m33 == b33
	);
});

DefineMatrix4Method(bool, AtomMatrix4::Equals, const, {
	return (
		std::abs(m00 - b00) <= ATOM_EPSILON * std::max(std::max(std::abs(m00), std::abs(b00)), 1.0f) &&
		std::abs(m01 - b01) <= ATOM_EPSILON * std::max(std::max(std::abs(m01), std::abs(b01)), 1.0f) &&
		std::abs(m02 - b02) <= ATOM_EPSILON * std::max(std::max(std::abs(m02), std::abs(b02)), 1.0f) &&
		std::abs(m03 - b03) <= ATOM_EPSILON * std::max(std::max(std::abs(m03), std::abs(b03)), 1.0f) &&
		std::abs(m10 - b10) <= ATOM_EPSILON * std::max(std::max(std::abs(m10), std::abs(b10)), 1.0f) &&
		std::abs(m11 - b11) <= ATOM_EPSILON * std::max(std::max(std::abs(m11), std::abs(b11)), 1.0f) &&
		std::abs(m12 - b12) <= ATOM_EPSILON * std::max(std::max(std::abs(m12), std::abs(b12)), 1.0f) &&
		std::abs(m13 - b13) <= ATOM_EPSILON * std::max(std::max(std::abs(m13), std::abs(b13)), 1.0f) &&
		std::abs(m20 - b20) <= ATOM_EPSILON * std::max(std::max(std::abs(m20), std::abs(b20)), 1.0f) &&
		std::abs(m21 - b21) <= ATOM_EPSILON * std::max(std::max(std::abs(m21), std::abs(b21)), 1.0f) &&
		std::abs(m22 - b22) <= ATOM_EPSILON * std::max(std::max(std::abs(m22), std::abs(b22)), 1.0f) &&
		std::abs(m23 - b23) <= ATOM_EPSILON * std::max(std::max(std::abs(m23), std::abs(b23)), 1.0f) &&
		std::abs(m30 - b30) <= ATOM_EPSILON * std::max(std::max(std::abs(m30), std::abs(b30)), 1.0f) &&
		std::abs(m31 - b31) <= ATOM_EPSILON * std::max(std::max(std::abs(m31), std::abs(b31)), 1.0f) &&
		std::abs(m32 - b32) <= ATOM_EPSILON * std::max(std::max(std::abs(m32), std::abs(b32)), 1.0f) &&
		std::abs(m33 - b33) <= ATOM_EPSILON * std::max(std::max(std::abs(m33), std::abs(b33)), 1.0f)
	);
});

DefineMatrix4OperatorMethod(AtomMatrix4, AtomMatrix4::operator+, const, {
	AtomMatrix4 out;

	out.m00 = m00 + b00;
	out.m01 = m01 + b01;
	out.m02 = m02 + b02;
	out.m03 = m03 + b03;
	out.m10 = m10 + b10;
	out.m11 = m11 + b11;
	out.m12 = m12 + b12;
	out.m13 = m13 + b13;
	out.m20 = m20 + b20;
	out.m21 = m21 + b21;
	out.m22 = m22 + b22;
	out.m23 = m23 + b23;
	out.m30 = m30 + b30;
	out.m31 = m31 + b31;
	out.m32 = m32 + b32;
	out.m33 = m33 + b33;

	return out;
});

DefineMatrix4OperatorMethod(AtomMatrix4, AtomMatrix4::operator-, const, {
	AtomMatrix4 out;

	out.m00 = m00 - b00;
	out.m01 = m01 - b01;
	out.m02 = m02 - b02;
	out.m03 = m03 - b03;
	out.m10 = m10 - b10;
	out.m11 = m11 - b11;
	out.m12 = m12 - b12;
	out.m13 = m13 - b13;
	out.m20 = m20 - b20;
	out.m21 = m21 - b21;
	out.m22 = m22 - b22;
	out.m23 = m23 - b23;
	out.m30 = m30 - b30;
	out.m31 = m31 - b31;
	out.m32 = m32 - b32;
	out.m33 = m33 - b33;

	return out;
});

DefineMatrix4OperatorMethod(AtomMatrix4, AtomMatrix4::operator*, const, {
	AtomMatrix4 out;

	AtomPoint b0 = b00;
	AtomPoint b1 = b01;
	AtomPoint b2 = b02;
	AtomPoint b3 = b03;
	
	out.m00 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	out.m01 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	out.m02 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	out.m03 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;

	b0 = b10;
	b1 = b11;
	b2 = b12;
	b3 = b13;

	out.m10 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	out.m11 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	out.m12 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	out.m13 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;

	b0 = b20;
	b1 = b21;
	b2 = b22;
	b3 = b23;

	out.m20 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	out.m21 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	out.m22 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	out.m23 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;

	b0 = b30;
	b1 = b31;
	b2 = b32;
	b3 = b33;

	out.m30 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	out.m31 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	out.m32 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	out.m33 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;

	return out;
});

DefineMatrix4OperatorMethod(AtomMatrix4&, AtomMatrix4::operator+=, , {
	m00 += b00;
	m01 += b01;
	m02 += b02;
	m03 += b03;
	m10 += b10;
	m11 += b11;
	m12 += b12;
	m13 += b13;
	m20 += b20;
	m21 += b21;
	m22 += b22;
	m23 += b23;
	m30 += b30;
	m31 += b31;
	m32 += b32;
	m33 += b33;

	return *this;
});

DefineMatrix4OperatorMethod(AtomMatrix4&, AtomMatrix4::operator-=, , {
	m00 -= b00;
	m01 -= b01;
	m02 -= b02;
	m03 -= b03;
	m10 -= b10;
	m11 -= b11;
	m12 -= b12;
	m13 -= b13;
	m20 -= b20;
	m21 -= b21;
	m22 -= b22;
	m23 -= b23;
	m30 -= b30;
	m31 -= b31;
	m32 -= b32;
	m33 -= b33;

	return *this;
});

DefineMatrix4OperatorMethod(AtomMatrix4&, AtomMatrix4::operator*=, , {
	AtomPoint b0 = b00;
	AtomPoint b1 = b01;
	AtomPoint b2 = b02;
	AtomPoint b3 = b03;

	m00 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	m01 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	m02 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	m03 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;

	b0 = b10;
	b1 = b11;
	b2 = b12;
	b3 = b13;

	m10 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	m11 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	m12 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	m13 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;

	b0 = b20;
	b1 = b21;
	b2 = b22;
	b3 = b23;

	m20 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	m21 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	m22 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	m23 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;

	b0 = b30;
	b1 = b31;
	b2 = b32;
	b3 = b33;

	m30 = b0 * m00 + b1 * m10 + b2 * m20 + b3 * m30;
	m31 = b0 * m01 + b1 * m11 + b2 * m21 + b3 * m31;
	m32 = b0 * m02 + b1 * m12 + b2 * m22 + b3 * m32;
	m33 = b0 * m03 + b1 * m13 + b2 * m23 + b3 * m33;

	return *this;
});

DefineMatrix4OperatorMethod(AtomMatrix4&, AtomMatrix4::operator=, , {
	m00 = b00;
	m01 = b01;
	m02 = b02;
	m03 = b03;
	m10 = b10;
	m11 = b11;
	m12 = b12;
	m13 = b13;
	m20 = b20;
	m21 = b21;
	m22 = b22;
	m23 = b23;
	m30 = b30;
	m31 = b31;
	m32 = b32;
	m33 = b33;

	return *this;
});

DefineMatrix4OperatorMethod(bool, AtomMatrix4::operator==, const, {
	return Equals(b00, b01, b02, b03, b10, b11, b12, b13, b20, b21, b22, b23, b30, b31, b32, b33);
});

AtomMatrix4& AtomMatrix4::operator++() {
	m00++;
	m01++;
	m02++;
	m03++;
	m10++;
	m11++;
	m12++;
	m13++;
	m20++;
	m21++;
	m22++;
	m23++;
	m30++;
	m31++;
	m32++;
	m33++;

	return *this;
}

AtomMatrix4& AtomMatrix4::operator--() {
	m00--;
	m01--;
	m02--;
	m03--;
	m10--;
	m11--;
	m12--;
	m13--;
	m20--;
	m21--;
	m22--;
	m23--;
	m30--;
	m31--;
	m32--;
	m33--;

	return *this;
}

std::string AtomMatrix4::ToString() const {
	std::string result = "mat4(";

	result += std::to_string(m00);
	result += ", ";
	result += std::to_string(m01);
	result += ", ";
	result += std::to_string(m02);
	result += ", ";
	result += std::to_string(m03);
	result += ", ";
	result += std::to_string(m10);
	result += ", ";
	result += std::to_string(m11);
	result += ", ";
	result += std::to_string(m12);
	result += ", ";
	result += std::to_string(m13);
	result += ", ";
	result += std::to_string(m20);
	result += ", ";
	result += std::to_string(m21);
	result += ", ";
	result += std::to_string(m22);
	result += ", ";
	result += std::to_string(m23);
	result += ", ";
	result += std::to_string(m30);
	result += ", ";
	result += std::to_string(m31);
	result += ", ";
	result += std::to_string(m32);
	result += ", ";
	result += std::to_string(m33);

	result += ")";

	return result;
}


void AtomMatrix4::Adjoint() {
	AtomPoint b00 = m00 * m11 - m01 * m10;
	AtomPoint b01 = m00 * m12 - m02 * m10;
	AtomPoint b02 = m00 * m13 - m03 * m10;
	AtomPoint b03 = m01 * m12 - m02 * m11;
	AtomPoint b04 = m01 * m13 - m03 * m11;
	AtomPoint b05 = m02 * m13 - m03 * m12;
	AtomPoint b06 = m20 * m31 - m21 * m30;
	AtomPoint b07 = m20 * m32 - m22 * m30;
	AtomPoint b08 = m20 * m33 - m23 * m30;
	AtomPoint b09 = m21 * m32 - m22 * m31;
	AtomPoint b10 = m21 * m33 - m23 * m31;
	AtomPoint b11 = m22 * m33 - m23 * m32;

	m00 = m11 * b11 - m12 * b10 + m13 * b09;
	m01 = m02 * b10 - m01 * b11 - m03 * b09;
	m02 = m31 * b05 - m32 * b04 + m33 * b03;
	m03 = m22 * b04 - m21 * b05 - m23 * b03;
	m10 = m12 * b08 - m10 * b11 - m13 * b07;
	m11 = m00 * b11 - m02 * b08 + m03 * b07;
	m12 = m32 * b02 - m30 * b05 - m33 * b01;
	m13 = m20 * b05 - m22 * b02 + m23 * b01;
	m20 = m10 * b10 - m11 * b08 + m13 * b06;
	m21 = m01 * b08 - m00 * b10 - m03 * b06;
	m22 = m30 * b04 - m31 * b02 + m33 * b00;
	m23 = m21 * b02 - m20 * b04 - m23 * b00;
	m30 = m11 * b07 - m10 * b09 - m12 * b06;
	m31 = m00 * b09 - m01 * b07 + m02 * b06;
	m32 = m31 * b01 - m30 * b03 - m32 * b00;
	m33 = m20 * b03 - m21 * b01 + m22 * b00;
}

void AtomMatrix4::Rotate(const AtomPoint& rad, const AtomVector3& v) {
	AtomPoint x = v.x;
	AtomPoint y = v.y;
	AtomPoint z = v.z;

	AtomPoint len = std::sqrt(x * x + y * y + z * z);
	AtomPoint s, c, t;
	AtomPoint b00, b01, b02;
	AtomPoint b10, b11, b12;
	AtomPoint b20, b21, b22;

	if (len < ATOM_EPSILON) {
		return;
	}

	len = 1.0f / len;
	
	x *= len;
	y *= len;
	z *= len;

	s = std::sin(rad);
	c = std::cos(rad);
	t = 1.0f - c;

	AtomPoint a00 = m00;
	AtomPoint a01 = m01;
	AtomPoint a02 = m02;
	AtomPoint a03 = m03;
	AtomPoint a10 = m10;
	AtomPoint a11 = m11;
	AtomPoint a12 = m12;
	AtomPoint a13 = m13;
	AtomPoint a20 = m20;
	AtomPoint a21 = m21;
	AtomPoint a22 = m22;
	AtomPoint a23 = m23;

	b00 = x * x * t + c;
	b01 = y * x * t + z * s;
	b02 = z * x * t - y * s;
	b10 = x * y * t - z * s;
	b11 = y * y * t + c;
	b12 = z * y * t + x * s;
	b20 = x * z * t + y * s;
	b21 = y * z * t - x * s;
	b22 = z * z * t + c;

	m00 = a00 * b00 + a10 * b01 + a20 * b02;
	m01 = a01 * b00 + a11 * b01 + a21 * b02;
	m02 = a02 * b00 + a12 * b01 + a22 * b02;
	m03 = a03 * b00 + a13 * b01 + a23 * b02;
	m10 = a00 * b10 + a10 * b11 + a20 * b12;
	m11 = a01 * b10 + a11 * b11 + a21 * b12;
	m12 = a02 * b10 + a12 * b11 + a22 * b12;
	m13 = a03 * b10 + a13 * b11 + a23 * b12;
	m20 = a00 * b20 + a10 * b21 + a20 * b22;
	m21 = a01 * b20 + a11 * b21 + a21 * b22;
	m22 = a02 * b20 + a12 * b21 + a22 * b22;
	m23 = a03 * b20 + a13 * b21 + a23 * b22;
}

void AtomMatrix4::RotateX(const AtomPoint& rad) {
	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	AtomPoint a10 = m10;
	AtomPoint a11 = m11;
	AtomPoint a12 = m12;
	AtomPoint a13 = m13;
	AtomPoint a20 = m20;
	AtomPoint a21 = m21;
	AtomPoint a22 = m22;
	AtomPoint a23 = m23;

	m10 = a10 * c + a20 * s;
	m11 = a11 * c + a21 * s;
	m12 = a12 * c + a22 * s;
	m13 = a13 * c + a23 * s;
	m20 = a20 * c - a10 * s;
	m21 = a21 * c - a11 * s;
	m22 = a22 * c - a12 * s;
	m23 = a23 * c - a13 * s;
}

void AtomMatrix4::RotateY(const AtomPoint& rad) {
	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	AtomPoint a00 = m00;
	AtomPoint a01 = m01;
	AtomPoint a02 = m02;
	AtomPoint a03 = m03;
	AtomPoint a20 = m20;
	AtomPoint a21 = m21;
	AtomPoint a22 = m22;
	AtomPoint a23 = m23;

	m00 = a00 * c - a20 * s;
	m01 = a01 * c - a21 * s;
	m02 = a02 * c - a22 * s;
	m03 = a03 * c - a23 * s;
	m20 = a00 * s + a20 * c;
	m21 = a01 * s + a21 * c;
	m22 = a02 * s + a22 * c;
	m23 = a03 * s + a23 * c;
}

void AtomMatrix4::RotateZ(const AtomPoint& rad) {
	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	AtomPoint a00 = m00;
	AtomPoint a01 = m01;
	AtomPoint a02 = m02;
	AtomPoint a03 = m03;
	AtomPoint a10 = m10;
	AtomPoint a11 = m11;
	AtomPoint a12 = m12;
	AtomPoint a13 = m13;
	
	m00 = a00 * c + a10 * s;
	m01 = a01 * c + a11 * s;
	m02 = a02 * c + a12 * s;
	m03 = a03 * c + a13 * s;
	m10 = a10 * c - a00 * s;
	m11 = a11 * c - a01 * s;
	m12 = a12 * c - a02 * s;
	m13 = a13 * c - a03 * s;
}

void AtomMatrix4::Transpose() {
	AtomPoint a01 = m01;
	AtomPoint a02 = m02;
	AtomPoint a03 = m03;
	AtomPoint a12 = m12;
	AtomPoint a13 = m13;
	AtomPoint a23 = m23;

	m01 = m10;
	m02 = m20;
	m03 = m30;
	m10 = a01;
	m12 = m21;
	m13 = m31;
	m20 = a02;
	m21 = a12;
	m23 = m32;
	m30 = a03;
	m31 = a13;
	m32 = a23;
}

void AtomMatrix4::Transpose(AtomMatrix4* m) {
	if (!m) {
		return;
	}

	if (this == m) {
		AtomPoint a01 = m01;
		AtomPoint a02 = m02;
		AtomPoint a03 = m03;
		AtomPoint a12 = m12;
		AtomPoint a13 = m13;
		AtomPoint a23 = m23;

		m01 = m10;
		m02 = m20;
		m03 = m30;
		m10 = a01;
		m12 = m21;
		m13 = m31;
		m20 = a02;
		m21 = a12;
		m23 = m32;
		m30 = a03;
		m31 = a13;
		m32 = a23;
		
		return;
	}

	m00 = m->m00;
	m01 = m->m10;
	m02 = m->m20;
	m03 = m->m30;
	m10 = m->m01;
	m11 = m->m11;
	m12 = m->m21;
	m13 = m->m31;
	m20 = m->m02;
	m21 = m->m12;
	m22 = m->m22;
	m23 = m->m32;
	m30 = m->m03;
	m31 = m->m13;
	m32 = m->m23;
	m33 = m->m33;
}

DefineMatrix4Method(void, AtomMatrix4::Translate, , {
	AtomPoint x = b00;
	AtomPoint y = b01;
	AtomPoint z = b02;

	m30 = m00 * x + m10 * y + m20 * z + m30;
	m31 = m01 * x + m11 * y + m21 * z + m31;
	m32 = m02 * x + m12 * y + m22 * z + m32;
	m33 = m03 * x + m13 * y + m23 * z + m33;
});

DefineMatrix4MethodArgs(void, AtomMatrix4::Translate, , {
	if (!mm) {
		return;
	}

	AtomPoint x = b00;
	AtomPoint y = b01;
	AtomPoint z = b02;

	if (this == mm) {
		m30 = mm->m00 * x + mm->m10 * y + mm->m20 * z + mm->m30;
		m31 = mm->m01 * x + mm->m11 * y + mm->m21 * z + mm->m31;
		m32 = mm->m02 * x + mm->m12 * y + mm->m22 * z + mm->m32;
		m33 = mm->m03 * x + mm->m13 * y + mm->m23 * z + mm->m33;
	} else {
		AtomPoint a00 = mm->m00;
		AtomPoint a01 = mm->m01;
		AtomPoint a02 = mm->m02;
		AtomPoint a03 = mm->m03;
		AtomPoint a10 = mm->m10;
		AtomPoint a11 = mm->m11;
		AtomPoint a12 = mm->m12;
		AtomPoint a13 = mm->m13;
		AtomPoint a20 = mm->m20;
		AtomPoint a21 = mm->m21;
		AtomPoint a22 = mm->m22;
		AtomPoint a23 = mm->m23;

		m00 = a00;
		m01 = a01;
		m02 = a02;
		m03 = a03;
		m10 = a10;
		m11 = a11;
		m12 = a12;
		m13 = a13;
		m20 = a20;
		m21 = a21;
		m22 = a22;
		m23 = a23;

		m30 = a00 * x + a10 * y + a20 * z + mm->m30;
		m31 = a01 * x + a11 * y + a21 * z + mm->m31;
		m32 = a02 * x + a12 * y + a22 * z + mm->m32;
		m33 = a03 * x + a13 * y + a23 * z + mm->m33;
	}
}, AtomMatrix4* mm);

DefineMatrix4Method(void, AtomMatrix4::FromTranslation, , {
	m00 = 1.0f;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = 1.0f;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = 1.0f;
	m23 = 0.0f;
	m30 = b00;
	m31 = b01;
	m32 = b02;
	m33 = 1.0f;
});

void AtomMatrix4::FromRotation(const AtomPoint& rad, const AtomVector3& v) {
	AtomPoint x = v.x;
	AtomPoint y = v.y;
	AtomPoint z = v.z;

	AtomPoint len = std::sqrt(x * x + y * y + z * z);
	AtomPoint s, c, t;

	if (len < ATOM_EPSILON) {
		return;
	}

	len = 1.0f / len;

	x *= len;
	y *= len;
	z *= len;

	s = std::sin(rad);
	c = std::cos(rad);
	t = 1.0f - c;

	m00 = x * x * t + c;
	m01 = y * x * t + z * s;
	m02 = z * x * t - y * s;
	m03 = 0.0f;
	m10 = x * y * t - z * s;
	m11 = y * y * t + c;
	m12 = z * y * t + x * s;
	m13 = 0.0f;
	m20 = x * z * t + y * s;
	m21 = y * z * t - x * s;
	m22 = z * z * t + c;
	m23 = 0.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 1.0f;
}

void AtomMatrix4::FromXRotation(const AtomPoint& rad) {
	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	m00 = 1.0f;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = c;
	m12 = s;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = -s;
	m22 = c;
	m23 = 0.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 1.0f;
}

void AtomMatrix4::FromYRotation(const AtomPoint& rad) {
	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	m00 = c;
	m01 = 0.0f;
	m02 = -s;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = 1.0f;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = s;
	m21 = 0.0f;
	m22 = c;
	m23 = 0.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 1.0f;
}

void AtomMatrix4::FromZRotation(const AtomPoint& rad) {
	AtomPoint s = std::sin(rad);
	AtomPoint c = std::cos(rad);

	m00 = c;
	m01 = s;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = -s;
	m11 = c;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = 1.0f;
	m23 = 0.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 1.0f;
}

void AtomMatrix4::FromRotationTranslation(const AtomQuat& q, const AtomVector3& v) {
	AtomPoint x = q.x;
	AtomPoint y = q.y;
	AtomPoint z = q.z;
	AtomPoint w = q.w;

	AtomPoint x2 = x + x;
	AtomPoint y2 = y + y;
	AtomPoint z2 = z + z;

	AtomPoint xx = x * x2;
	AtomPoint xy = x * y2;
	AtomPoint xz = x * z2;
	AtomPoint yy = y * y2;
	AtomPoint yz = y * z2;
	AtomPoint zz = z * z2;
	AtomPoint wx = w * x2;
	AtomPoint wy = w * y2;
	AtomPoint wz = w * z2;

	m00 = 1.0f - (yy + zz);
	m01 = xy + wz;
	m02 = xz - wy;
	m03 = 0.0f;
	m10 = xy - wz;
	m11 = 1.0f - (xx + zz);
	m12 = yz + wx;
	m13 = 0.0f;
	m20 = xz + wy;
	m21 = yz - wx;
	m22 = 1.0f - (xx + yy);
	m23 = 0.0f;
	m30 = v.x;
	m31 = v.y;
	m32 = v.z;
	m33 = 1.0f;
}

void AtomMatrix4::FromQuat2(const AtomQuat2& q) {
	AtomVector3 translation(0.0f);
	
	AtomPoint bx = -q.x;
	AtomPoint by = -q.y;
	AtomPoint bz = -q.z;
	AtomPoint bw = q.w;
	AtomPoint ax = q.ex;
	AtomPoint ay = q.ey;
	AtomPoint az = q.ez;
	AtomPoint aw = q.ew;

	AtomPoint magnitude = bx * bx + by * by + bz * bz + bw * bw;
	
	if (magnitude > 0.0f) {
		translation.x = ((ax * bw + aw * bx + ay * bz - az * by) * 2.0f) / magnitude;
		translation.y = ((ay * bw + aw * by + az * bx - ax * bz) * 2.0f) / magnitude;
		translation.z = ((az * bw + aw * bz + ax * by - ay * bx) * 2.0f) / magnitude;
	}else{
		translation.x = (ax * bw + aw * bx + ay * bz - az * by) * 2.0f;
		translation.y = (ay * bw + aw * by + az * bx - ax * bz) * 2.0f;
		translation.z = (az * bw + aw * bz + ax * by - ay * bx) * 2.0f;
	}
	
	AtomQuat quat;
	quat.x = q.x;
	quat.y = q.y;
	quat.z = q.z;
	quat.w = q.w;

	FromRotationTranslation(quat, translation);
}

AtomVector3 AtomMatrix4::GetTranslation() const {
	AtomVector3 out;

	out.x = m30;
	out.y = m31;
	out.z = m32;

	return out;
}

AtomVector3 AtomMatrix4::GetScaling() const {
	AtomVector3 out;

	out.x = std::sqrt(m00 * m00 + m01 * m01 + m02 * m02);
	out.y = std::sqrt(m10 * m10 + m11 * m11 + m12 * m12);
	out.z = std::sqrt(m20 * m20 + m21 * m21 + m22 * m22);

	return out;
}

AtomQuat AtomMatrix4::GetRotation() const {
	AtomQuat out;

	AtomVector3 scaling = GetScaling();

	AtomPoint is1 = 1.0f / scaling.x;
	AtomPoint is2 = 1.0f / scaling.y;
	AtomPoint is3 = 1.0f / scaling.z;

	AtomPoint sm11 = m00 * is1;
	AtomPoint sm12 = m01 * is2;
	AtomPoint sm13 = m02 * is3;
	AtomPoint sm21 = m10 * is1;
	AtomPoint sm22 = m11 * is2;
	AtomPoint sm23 = m12 * is3;
	AtomPoint sm31 = m20 * is1;
	AtomPoint sm32 = m21 * is2;
	AtomPoint sm33 = m22 * is3;

	AtomPoint trace = sm11 + sm22 + sm33;
	AtomPoint S = 0.0f;

	if (trace > 0.0f) {
		S = std::sqrt(trace + 1.0f) * 2.0f;
		out.w = 0.25f * S;
		out.x = (sm23 - sm32) / S;
		out.y = (sm31 - sm13) / S;
		out.z = (sm12 - sm21) / S;
	}else if (sm11 > sm22 && sm11 > sm33) {
		S = std::sqrt(1.0f + sm11 - sm22 - sm33) * 2.0f;
		out.w = (sm23 - sm32) / S;
		out.x = 0.25f * S;
		out.y = (sm12 + sm21) / S;
		out.z = (sm31 + sm13) / S;
	}else if (sm22 > sm33) {
		S = std::sqrt(1.0f + sm22 - sm11 - sm33) * 2.0f;
		out.w = (sm31 - sm13) / S;
		out.x = (sm12 + sm21) / S;
		out.y = 0.25f * S;
		out.z = (sm23 + sm32) / S;
	}else{
		S = std::sqrt(1.0f + sm33 - sm11 - sm22) * 2.0f;
		out.w = (sm12 - sm21) / S;
		out.x = (sm31 + sm13) / S;
		out.y = (sm23 + sm32) / S;
		out.z = 0.25f * S;
	}

	return out;
}

AtomQuat AtomMatrix4::Decompose(AtomVector3* t, AtomVector3* s) const {
	AtomQuat out;

	if (!t) {
		return out;
	}

	if (!s) {
		return out;
	}

	t->x = m30;
	t->y = m31;
	t->z = m32;

	AtomPoint a11 = m00;
	AtomPoint a12 = m01;
	AtomPoint a13 = m02;
	AtomPoint a21 = m10;
	AtomPoint a22 = m11;
	AtomPoint a23 = m12;
	AtomPoint a31 = m20;
	AtomPoint a32 = m21;
	AtomPoint a33 = m22;

	s->x = std::sqrt(a11 * a11 + a12 * a12 + a13 * a13);
	s->y = std::sqrt(a21 * a21 + a22 * a22 + a23 * a23);
	s->z = std::sqrt(a31 * a31 + a32 * a32 + a33 * a33);

	AtomPoint is1 = 1.0f / s->x;
	AtomPoint is2 = 1.0f / s->y;
	AtomPoint is3 = 1.0f / s->z;

	AtomPoint sm11 = a11 * is1;
	AtomPoint sm12 = a12 * is2;
	AtomPoint sm13 = a13 * is3;
	AtomPoint sm21 = a21 * is1;
	AtomPoint sm22 = a22 * is2;
	AtomPoint sm23 = a23 * is3;
	AtomPoint sm31 = a31 * is1;
	AtomPoint sm32 = a32 * is2;
	AtomPoint sm33 = a33 * is3;

	AtomPoint trace = sm11 + sm22 + sm33;
	AtomPoint S = 0.0f;

	if (trace > 0.0f) {
		S = std::sqrt(trace + 1.0f) * 2.0f;
		out.w = 0.25f * S;
		out.x = (sm23 - sm32) / S;
		out.y = (sm31 - sm13) / S;
		out.z = (sm12 - sm21) / S;
	}else if (sm11 > sm22 && sm11 > sm33) {
		S = std::sqrt(1.0f + sm11 - sm22 - sm33) * 2.0f;
		out.w = (sm23 - sm32) / S;
		out.x = 0.25f * S;
		out.y = (sm12 + sm21) / S;
		out.z = (sm31 + sm13) / S;
	}else if (sm22 > sm33) {
		S = std::sqrt(1.0f + sm22 - sm11 - sm33) * 2.0f;
		out.w = (sm31 - sm13) / S;
		out.x = (sm12 + sm21) / S;
		out.y = 0.25f * S;
		out.z = (sm23 + sm32) / S;
	}else{
		S = std::sqrt(1.0f + sm33 - sm11 - sm22) * 2.0f;
		out.w = (sm12 - sm21) / S;
		out.x = (sm31 + sm13) / S;
		out.y = (sm23 + sm32) / S;
		out.z = 0.25f * S;
	}

	return out;
}

void AtomMatrix4::FromRotationTranslationScale(const AtomQuat& q, const AtomVector3& v, const AtomVector3& s) {
	AtomPoint x = q.x;
	AtomPoint y = q.y;
	AtomPoint z = q.z;
	AtomPoint w = q.w;

	AtomPoint x2 = x + x;
	AtomPoint y2 = y + y;
	AtomPoint z2 = z + z;

	AtomPoint xx = x * x2;
	AtomPoint xy = x * y2;
	AtomPoint xz = x * z2;
	AtomPoint yy = y * y2;
	AtomPoint yz = y * z2;
	AtomPoint zz = z * z2;
	AtomPoint wx = w * x2;
	AtomPoint wy = w * y2;
	AtomPoint wz = w * z2;

	AtomPoint sx = s.x;
	AtomPoint sy = s.y;
	AtomPoint sz = s.z;

	m00 = (1.0f - (yy + zz)) * sx;
	m01 = (xy + wz) * sx;
	m02 = (xz - wy) * sx;
	m03 = 0.0f;
	m10 = (xy - wz) * sy;
	m11 = (1.0f - (xx + zz)) * sy;
	m12 = (yz + wx) * sy;
	m13 = 0.0f;
	m20 = (xz + wy) * sz;
	m21 = (yz - wx) * sz;
	m22 = (1.0f - (xx + yy)) * sz;
	m23 = 0.0f;
	m30 = v.x;
	m31 = v.y;
	m32 = v.z;
	m33 = 1.0f;
}

void AtomMatrix4::FromRotationTranslationScaleOrigin(const AtomQuat& q, const AtomVector3& v, const AtomVector3& s, const AtomVector3& o) {
	AtomPoint x = q.x;
	AtomPoint y = q.y;
	AtomPoint z = q.z;
	AtomPoint w = q.w;

	AtomPoint x2 = x + x;
	AtomPoint y2 = y + y;
	AtomPoint z2 = z + z;

	AtomPoint xx = x * x2;
	AtomPoint xy = x * y2;
	AtomPoint xz = x * z2;
	AtomPoint yy = y * y2;
	AtomPoint yz = y * z2;
	AtomPoint zz = z * z2;
	AtomPoint wx = w * x2;
	AtomPoint wy = w * y2;
	AtomPoint wz = w * z2;

	AtomPoint sx = s.x;
	AtomPoint sy = s.y;
	AtomPoint sz = s.z;

	AtomPoint ox = o.x;
	AtomPoint oy = o.y;
	AtomPoint oz = o.z;

	AtomPoint out0 = (1.0f - (yy + zz)) * sx;
	AtomPoint out1 = (xy + wz) * sx;
	AtomPoint out2 = (xz - wy) * sx;
	AtomPoint out4 = (xy - wz) * sy;
	AtomPoint out5 = (1.0f - (xx + zz)) * sy;
	AtomPoint out6 = (yz + wx) * sy;
	AtomPoint out8 = (xz + wy) * sz;
	AtomPoint out9 = (yz - wx) * sz;
	AtomPoint out10 = (1.0f - (xx + yy)) * sz;

	m00 = out0;
	m01 = out1;
	m02 = out2;
	m03 = 0.0f;
	m10 = out4;
	m11 = out5;
	m12 = out6;
	m13 = 0.0f;
	m20 = out8;
	m21 = out9;
	m22 = out10;
	m23 = 0.0f;
	m30 = v.x + ox - (out0 * ox + out4 * oy + out8 * oz);
	m31 = v.y + oy - (out1 * ox + out5 * oy + out9 * oz);
	m32 = v.z + oz - (out2 * ox + out6 * oy + out10 * oz);
	m33 = 1.0f;

}

void AtomMatrix4::FromQuat(const AtomQuat& q) {
	AtomPoint x = q.x;
	AtomPoint y = q.y;
	AtomPoint z = q.z;
	AtomPoint w = q.w;

	AtomPoint x2 = x + x;
	AtomPoint y2 = y + y;
	AtomPoint z2 = z + z;

	AtomPoint xx = x * x2;
	AtomPoint yx = y * x2;
	AtomPoint yy = y * y2;
	AtomPoint zx = z * x2;
	AtomPoint zy = z * y2;
	AtomPoint zz = z * z2;
	AtomPoint wx = w * x2;
	AtomPoint wy = w * y2;
	AtomPoint wz = w * z2;

	m00 = 1.0f - yy - zz;
	m01 = yx + wz;
	m02 = zx - wy;
	m03 = 0.0f;

	m10 = yx - wz;
	m11 = 1.0f - xx - zz;
	m12 = zy + wx;
	m13 = 0.0f;

	m20 = zx + wy;
	m21 = zy - wx;
	m22 = 1.0f - xx - yy;
	m23 = 0.0f;

	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 1.0f;
}

void AtomMatrix4::Frustum(const AtomPoint& left, const AtomPoint& right, const AtomPoint& bottom, const AtomPoint& top, const AtomPoint& near, const AtomPoint& far) {
	AtomPoint rl = 1.0f / (right - left);
	AtomPoint tb = 1.0f / (top - bottom);
	AtomPoint nf = 1.0f / (near - far);

	m00 = near * 2.0f * rl;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = near * 2.0f * tb;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = (right + left) * rl;
	m21 = (top + bottom) * tb;
	m22 = (far + near) * nf;
	m23 = -1.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = far * near * 2.0f * nf;
	m33 = 0.0f;
}

void AtomMatrix4::Perspective(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near, const AtomPoint& far) {
	PerspectiveNO(fovy, aspect, near, far);
}

void AtomMatrix4::Perspective(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near) {
	PerspectiveNO(fovy, aspect, near);
}

void AtomMatrix4::PerspectiveNO(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near, const AtomPoint& far) {
	AtomPoint f = 1.0f / std::tan(fovy / 2.0f);
	AtomPoint nf = 1.0f / (near - far);

	m00 = f / aspect;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = f;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = (far + near) * nf;
	m23 = -1.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 2.0f * far * near * nf;
	m33 = 0.0f;
}

void AtomMatrix4::PerspectiveNO(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near) {
	AtomPoint f = 1.0f / std::tan(fovy / 2.0f);

	m00 = f / aspect;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = f;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = -1.0f;
	m23 = -1.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = -2.0f * near;
	m33 = 0.0f;
}

void AtomMatrix4::PerspectiveZO(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near, const AtomPoint& far) {
	AtomPoint f = 1.0f / std::tan(fovy / 2.0f);
	AtomPoint nf = 1.0f / (near - far);

	m00 = f / aspect;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = f;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = far * nf;
	m23 = -1.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = far * near * nf;
	m33 = 0.0f;
}

void AtomMatrix4::PerspectiveZO(const AtomPoint& fovy, const AtomPoint& aspect, const AtomPoint& near) {
	AtomPoint f = 1.0f / std::tan(fovy / 2.0f);

	m00 = f / aspect;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = f;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = -1.0f;
	m23 = -1.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = -near;
	m33 = 0.0f;
}

void AtomMatrix4::PerspectiveFromFieldOfView(const AtomFieldOfView& fov, const AtomPoint& near, const AtomPoint& far) {
	AtomPoint upTan = std::tan((fov.upDegrees * M_PI) / 180.0f);
	AtomPoint downTan = std::tan((fov.downDegrees * M_PI) / 180.0f);
	AtomPoint leftTan = std::tan((fov.leftDegrees * M_PI) / 180.0f);
	AtomPoint rightTan = std::tan((fov.rightDegrees * M_PI) / 180.0f);
	AtomPoint xScale = 2.0f / (leftTan + rightTan);
	AtomPoint yScale = 2.0f / (upTan + downTan);

	m00 = xScale;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = yScale;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = -((leftTan - rightTan) * xScale * 0.5f);
	m21 = (upTan - downTan) * yScale * 0.5f;
	m22 = far / (near - far);
	m23 = -1.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = (far * near) / (near - far);
	m33 = 0.0f;
}

void AtomMatrix4::Ortho(const AtomPoint& left, const AtomPoint& right, const AtomPoint& bottom, const AtomPoint& top, const AtomPoint& near, const AtomPoint& far) {
	OrthoNO(left, right, bottom, top, near, far);
}

void AtomMatrix4::OrthoNO(const AtomPoint& left, const AtomPoint& right, const AtomPoint& bottom, const AtomPoint& top, const AtomPoint& near, const AtomPoint& far) {
	AtomPoint lr = 1.0f / (left - right);
	AtomPoint bt = 1.0f / (bottom - top);
	AtomPoint nf = 1.0f / (near - far);

	m00 = -2.0f * lr;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = -2.0f * bt;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = 2.0f * nf;
	m23 = 0.0f;
	m30 = (left + right) * lr;
	m31 = (top + bottom) * bt;
	m32 = (far + near) * nf;
	m33 = 1.0f;
}

void AtomMatrix4::OrthoZO(const AtomPoint& left, const AtomPoint& right, const AtomPoint& bottom, const AtomPoint& top, const AtomPoint& near, const AtomPoint& far) {
	AtomPoint lr = 1.0f / (left - right);
	AtomPoint bt = 1.0f / (bottom - top);
	AtomPoint nf = 1.0f / (near - far);

	m00 = -2.0f * lr;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = -2.0f * bt;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = nf;
	m23 = 0.0f;
	m30 = (left + right) * lr;
	m31 = (top + bottom) * bt;
	m32 = near * nf;
	m33 = 1.0f;
}

void AtomMatrix4::LookAt(const AtomVector3& eye, const AtomVector3& center, const AtomVector3& up) {
	AtomPoint x0, x1, x2, y0, y1, y2, z0, z1, z2, len;

	AtomPoint eyex = eye.x;
	AtomPoint eyey = eye.y;
	AtomPoint eyez = eye.z;

	AtomPoint upx = up.x;
	AtomPoint upy = up.y;
	AtomPoint upz = up.z;

	AtomPoint centerx = center.x;
	AtomPoint centery = center.y;
	AtomPoint centerz = center.z;

	if (
		std::abs(eyex - centerx) < ATOM_EPSILON &&
		std::abs(eyey - centery) < ATOM_EPSILON &&
		std::abs(eyez - centerz) < ATOM_EPSILON
	) {
		Identity();
		return;
	}

	z0 = eyex - centerx;
	z1 = eyey - centery;
	z2 = eyez - centerz;

	len = 1.0f / std::sqrt(z0 * z0 + z1 * z1 + z2 * z2);
	
	z0 *= len;
	z1 *= len;
	z2 *= len;

	x0 = upy * z2 - upz * z1;
	x1 = upz * z0 - upx * z2;
	x2 = upx * z1 - upy * z0;
	
	len = std::sqrt(x0 * x0 + x1 * x1 + x2 * x2);
	
	if (!len) {
		x0 = 0.0f;
		x1 = 0.0f;
		x2 = 0.0f;
	}else{
		len = 1.0f / len;
		
		x0 *= len;
		x1 *= len;
		x2 *= len;
	}

	y0 = z1 * x2 - z2 * x1;
	y1 = z2 * x0 - z0 * x2;
	y2 = z0 * x1 - z1 * x0;

	len = std::sqrt(y0 * y0 + y1 * y1 + y2 * y2);
	
	if (!len) {
		y0 = 0.0f;
		y1 = 0.0f;
		y2 = 0.0f;
	}else{
		len = 1.0f / len;

		y0 *= len;
		y1 *= len;
		y2 *= len;
	}

	m00 = x0;
	m01 = y0;
	m02 = z0;
	m03 = 0.0f;
	m10 = x1;
	m11 = y1;
	m12 = z1;
	m13 = 0.0f;
	m20 = x2;
	m21 = y2;
	m22 = z2;
	m23 = 0.0f;
	m30 = -(x0 * eyex + x1 * eyey + x2 * eyez);
	m31 = -(y0 * eyex + y1 * eyey + y2 * eyez);
	m32 = -(z0 * eyex + z1 * eyey + z2 * eyez);
	m33 = 1.0f;
}

void AtomMatrix4::TargetTo(const AtomVector3& eye, const AtomVector3& target, const AtomVector3& up) {
	AtomPoint eyex = eye.x;
	AtomPoint eyey = eye.y;
	AtomPoint eyez = eye.z;

	AtomPoint upx = up.x;
	AtomPoint upy = up.y;
	AtomPoint upz = up.z;

	AtomPoint z0 = eyex - target.x;
	AtomPoint z1 = eyey - target.y;
	AtomPoint z2 = eyez - target.z;

	AtomPoint len = z0 * z0 + z1 * z1 + z2 * z2;

	if (len > 0.0f) {
		len = 1.0f / std::sqrt(len);

		z0 *= len;
		z1 *= len;
		z2 *= len;
	}

	AtomPoint x0 = upy * z2 - upz * z1;
	AtomPoint x1 = upz * z0 - upx * z2;
	AtomPoint x2 = upx * z1 - upy * z0;

	len = x0 * x0 + x1 * x1 + x2 * x2;

	if (len > 0.0f) {
		len = 1.0f / std::sqrt(len);

		x0 *= len;
		x1 *= len;
		x2 *= len;
	}

	m00 = x0;
	m01 = x1;
	m02 = x2;
	m03 = 0.0f;
	m10 = z1 * x2 - z2 * x1;
	m11 = z2 * x0 - z0 * x2;
	m12 = z0 * x1 - z1 * x0;
	m13 = 0.0f;
	m20 = z0;
	m21 = z1;
	m22 = z2;
	m23 = 0.0f;
	m30 = eyex;
	m31 = eyey;
	m32 = eyez;
	m33 = 1.0f;
}

void AtomCalculateLDUMatrix(AtomMatrix2* L, AtomMatrix2* D, AtomMatrix2* U, AtomMatrix2* a) {
	if (!L) {
		return;
	}

	if (!D) {
		return;
	}

	if (!U) {
		return;
	}

	if (!a) {
		return;
	}

	L->m10 = a->m10 / a->m00;
	U->m00 = a->m00;
	U->m01 = a->m01;
	U->m11 = a->m11 - L->m10 * U->m01;
}

#undef DefineMatrix2Method
#undef DefineMatrix2DMethod
#undef DefineMatrix3Method
#undef DefineMatrix4Method

#undef DefineMatrix2MethodArgs
#undef DefineMatrix2DMethodArgs
#undef DefineMatrix3MethodArgs
#undef DefineMatrix4MethodArgs

#undef DefineMatrix2OperatorMethod
#undef DefineMatrix2DOperatorMethod
#undef DefineMatrix3OperatorMethod
#undef DefineMatrix4OperatorMethod