
#include<stdio.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

void init();
void display();
void drawpolygon(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint);
void setpixel(GLint, GLint);

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

void drawpolygon(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();
	glFlush();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	GLint x0 = 100;
	GLint y0 = 100;
	GLint x1 = 150;
	GLint y1 = 150;
	drawpolygon(x0, y0, x1, y0, x1, y1, x0, y1);
	int opt;
	float sh;
	GLint x0_New, x1_New, y0_New, y1_New;
	cout<<"\n1. Shear along X-axis\n 2. Shear along Y-axis\n 3. Exit\n";
	cout<<"Enter your option";
	cin>>opt;
	switch (opt)
	{
	case 1: cout<<"\nEnter shear parameter:";
		cin>> sh;
		x0_New = x0 + sh * y1;
		x1_New = x1 + sh * y1;
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0, 0.0, 0.0);
		drawpolygon(x0, y0, x1, y0, x1_New, y1, x0_New, y1);
		break;
	case 2: cout<<"\nEnter shear parameter:";
		cin>>sh;
		y0_New = y0 + sh * x1;
		y1_New = y1 + sh * x1;
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0, 0.0, 0.0);
		drawpolygon(x0, y0, x1, y0_New, x1, y1_New, x0, y1);
		break;
	
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(600, 50);
	glutCreateWindow("Shearing");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}