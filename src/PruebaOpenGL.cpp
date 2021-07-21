//============================================================================
// Name        : PruebaOpenGL.cpp
// Author      : CodeRaido
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdlib.h>
#include <iostream>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
using namespace std;
GLfloat t = 0;

//vertex
GLfloat v[8][3] = { { -.5, .5, .5 }, { .5, .5, .5 }, { .5, -.5, .5 }, { -.5,
		-.5, .5 }, { -.5, .5, -.5 }, { .5, .5, -.5 }, { .5, -.5, -.5 }, { -.5,
		-.5, -.5 }, };

void windowResize(int w, int h) {
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(0, ratio, 0.1, 100);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void drawSquareFace(GLfloat p0[], GLfloat p1[], GLfloat p2[], GLfloat p3[],
		GLfloat colorRGB[3]) {
	glBegin(GL_POLYGON);
	glColor3fv(colorRGB);
	glVertex3fv(p0);
	glVertex3fv(p1);
	glVertex3fv(p2);
	glVertex3fv(p3);
	glEnd();
}
void drawCube(GLfloat v0[], GLfloat v1[], GLfloat v2[], GLfloat v3[],
		GLfloat v4[], GLfloat v5[], GLfloat v6[], GLfloat v7[]) {
	//FrontalFace
	GLfloat redColor[3] = { 1, 0, 0 };
	GLfloat greenColor[3] = { 0, 1, 0 };
	GLfloat blueColor[3] = { 0, 0, 1 };
	GLfloat orangeColor[3] = { 1, .5, 0 };
	GLfloat yellowColor[3] = { 1, 1, 0 };
	GLfloat whiteColor[3] = { 1, 1, 1 };
	drawSquareFace(v0, v1, v2, v3, whiteColor);	//Front Face
	drawSquareFace(v4, v5, v6, v7, yellowColor);	//Back Face
	drawSquareFace(v0, v1, v5, v4, redColor);	//Top Face
	drawSquareFace(v2, v3, v7, v6, orangeColor);	//Bottom Face
	drawSquareFace(v0, v3, v7, v4, blueColor);	//Left Face
	drawSquareFace(v1, v2, v6, v5, greenColor);	//Right Face

}
void spinObject() {
	t += .25;
	if (t > 360) {
		t = 0;
	}
	glutPostRedisplay();
}
void display() {
	// Set every pixel in the frame buffer to the current clear color.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(t, 15, 8, 10);
	drawCube(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
	//Siempre que se utilice buffer doble
	glutSwapBuffers();

	//glFinish();
	//glFlush();

}

int main(int argc, char *args[]) {

	glutInit(&argc, args);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(500, 500);

	glutCreateWindow("First OpenGL app");
	glutDisplayFunc(display); //funcion que procesa cada frame
	glutReshapeFunc(windowResize);
	glutIdleFunc(spinObject);
	glutMainLoop();

	return 0;
}
/**
 * GLUT_SINGLE Solo utiliza 1 buffer para guardar fotogramas y cargarlos
 *
 *Orden en el que se pintan cada una de las caras del cubo
 *
 * 0	1
 *
 * 3	2
 *
 *
 * */
