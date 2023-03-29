#include <GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

GLdouble x1, x2, Y1, y2;

void display() {
    GLdouble dx, dy, steps;
    float xinc, yinc, x, y;
    x = x1;
    y = Y1;
    dx = x2 - x1;
    dy = y2 - Y1;
    steps = (abs(dx) > abs(dy) ? dx : dy);
    xinc = dx / (float)steps;
    yinc = dy / (float)steps;

    glPointSize(1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    glVertex2d(x, y);
    for (int i = 0;i < steps;i++) {
        x += xinc;
        y += yinc;
        glVertex2d(x, y);
    }
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 50, 0, 100);
}

int main(int argc, char** argv) {
    cout << "Enter x1 y1 for line->" << endl;
    cin >> x1 >> Y1;
    cout << "Enter x2 y2 for line->" << endl;
    cin >> x2 >> y2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}