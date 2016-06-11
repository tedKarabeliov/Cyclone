#include <iostream>
#include <windows.h>

#include "precision.h"
#include "core.h"
#include "include\gl\freeglut.h"
#include "timing.h"

using namespace std;

float angle = 0.0f;

void display()
{
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLES);
		glVertex3f(-2.0f, -2.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0);
		glVertex3f(0.0f, 2.0f, 0.0);
	glEnd();

	angle += 0.5f;

	// Update the displayed content.
	glutSwapBuffers();
}

void update()
{
	TimingData::get().update();


	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	TimingData::init();

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("blq");

	glutDisplayFunc(display);
	glutIdleFunc(update);

	glClearColor(0.9f, 0.95f, 1.0f, 1.0f);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 640, 480);
	gluPerspective(60.0, (double)640 / (double)480, 1, 500);
	glMatrixMode(GL_MODELVIEW);

	glutMainLoop();

	TimingData::deinit();
}