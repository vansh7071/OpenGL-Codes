#include<GL/glut.h>
#include<iostream>
#include<Windows.h>
using namespace std;
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 1.0, 0);
	glLineWidth(4.0f);
	glVertex2i(10, 10);
	glVertex2i(10, 50);
	glVertex2i(50, 50);
	glVertex2i(50, 10);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, 1.0, 0);
	glVertex2i(10, 50);
	glVertex2i(50, 50);
	glVertex2i(30, 80);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0, 0);
	glVertex2i(15, 57.5);
	glVertex2i(15, 85);
	glVertex2i(25, 85);
	glVertex2i(25, 72.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 1.0);
	glVertex2i(25, 10);
	glVertex2i(25, 30);
	glVertex2i(35, 30);
	glVertex2i(35, 10);
	glEnd();
	glFlush();
}
void myInit(void) {
	glClearColor(0, 0, 0, 1.0);
	glColor3f(0, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 100, 0, 200);
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024, 1024);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("point display");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}