/*
 *
 *
 *  Created on: 2016-8-13
 *  Author: scott.cgi
 */

#ifndef shader_mesh_h
#define shader_mesh_h

#include "Mojoc/Graphics/OpenGL/Head/gl3.h"
#include "Mojoc/Toolkit/Math/Matrix.h"
#include "Mojoc/Toolkit/Math/Math.h"

struct AShaderMesh
{
	GLuint  program;
	GLuint  attribPosition;
	GLuint  attribTexcoord;
	GLuint  attribOpacity;
	GLuint  attribRGB;

	GLint   uniformMVPMatrix;
	GLint   uniformSample2D;

	void (*Use) (Matrix4* mvpMatrix);
	void (*Init)();
};

extern struct AShaderMesh AShaderMesh[1];

#endif