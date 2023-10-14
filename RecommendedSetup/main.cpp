#include <iostream>
#include <thread>

#include "Atom/Atom.h"
#include "Atom/AtomMacros.h"

bool Wait(size_t ms) {
	atom_sleep(ms);
	return true;
}

int main() {
	atom_application_init();

	std::cout << "this is a shared cpp app! mother fucker hahah" << std::endl;

	while (Wait(100000));
	
#if !ATOM_SYSTEM_OS_WASM
	atom_application_uninit();
#endif

	return EXIT_SUCCESS;
}

/*#include "Atom/Atom.h"
#include "Atom/AtomMacros.h"
#include "Atom/AtomStyleMacros.h"

#include "Atom/Atom3D/Atom3D.h"

void GetProjectionMatrix(AtomPoint fov, AtomPoint aspect, AtomPoint near, AtomPoint far) {
	AtomMatrix4 mat;

	mat.Perspective(fov, aspect, near, far);

	ATOM_JS_VARIABLE::global().call<void>("CreateMatData", mat.m00, mat.m01, mat.m02, mat.m03, mat.m10, mat.m11, mat.m12, mat.m13, mat.m20, mat.m21, mat.m22, mat.m23, mat.m30, mat.m31, mat.m32, mat.m33);
}

void GetModelViewMatrix(AtomPoint cubeRotation) {
	AtomMatrix4 mat;
	mat.Identity();
	
	AtomVector3 xAxis(1.0f, 0.0f, 0.0f);
	AtomVector3 yAxis(0.0f, 1.0f, 0.0f);
	AtomVector3 zAxis(0.0f, 0.0f, 1.0f);

	mat.Translate(-0.0f, 0.0f, -6.0f);

	mat.Rotate(cubeRotation * 0.3f, xAxis);
	mat.Rotate(cubeRotation * 0.7f, yAxis);
	mat.Rotate(cubeRotation, zAxis);

	ATOM_JS_VARIABLE::global().call<void>("CreateMatData", mat.m00, mat.m01, mat.m02, mat.m03, mat.m10, mat.m11, mat.m12, mat.m13, mat.m20, mat.m21, mat.m22, mat.m23, mat.m30, mat.m31, mat.m32, mat.m33);
}

int main() {
	atom_application_init();

	AtomElement webGlCanvas = Element { Node "canvas", Attribute {"width", "640"}, Attribute {"height", "480"} };

	webGlCanvas.ApplyOption(Style {
		CssProperty(position) = Css(absolute),
		CssProperty(left) = Css(50%),
		CssProperty(top) = Css(50%),
		CssProperty(transform) = Css(translate(-50%, -50%))
	});

	AtomGetDocumentBodyElement() += webGlCanvas;

	ATOM_DIRECT_ASM({
		const canvas = atom_get_element_by_reference($0);
		if (!canvas) {
			return;
		}

		const gl = canvas.getContext("webgl");

		if (gl == null) {
			alert("Unable to initialize WebGL. Your browser or machine may not support it.");

			return;
		}

		gl.clearColor(0.0, 0.0, 0.0, 0.5);

		gl.clear(gl.COLOR_BUFFER_BIT);

		self.GL = gl;
		self.GetProjectionMatrix = wasmTable.get($1);
		self.GetModelViewMatrix = wasmTable.get($2);
	}, webGlCanvas.GetHandle(), GetProjectionMatrix, GetModelViewMatrix);

	while (true) atom_sleep(5000);

	return NULL;
}*/