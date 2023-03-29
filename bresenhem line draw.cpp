#include <GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;


int x1, Y1, xEnd, yEnd;

void bresenham(int x1, int Y1, int xEnd, int yEnd) {
    int dx = abs(xEnd - x1);
    int dy = abs(yEnd - Y1);
    float m = dy / dx;
    int x, y;
    if (m<1) {
        int p = 2 * dy - dx;
        int ds = 2 * dy;
        int dt = 2 * (dy - dx);
        if (x1 > xEnd) {
            x = xEnd;
            y = yEnd;
            xEnd = x1;
        }
        else {
            x = x1;
            y = Y1;
        }
        glVertex2i(x, y);
        while (x < xEnd) {
            x++;
            if (p < 0) {
                p += ds;
            }
            else {
                y++;
                p += dt;
            }
            glVertex2i(x, y);
        }
    }
    else {
        int p = 2 * dx - dy;
        int ds = 2 * dx;
        int dt = 2 * (dx - dy);
        if (Y1 > yEnd) {
            x = xEnd;
            y = yEnd;
            yEnd = Y1;
        }
        else {
            x = x1;
            y = Y1;
        }
        glVertex2i(x, y);
        while (y < yEnd) {
            y++;
            if (p < 0) {
                p += ds;
            }
            else {
                x++;
                p += dt;
            }
            glVertex2i(x, y);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    bresenham(x1, Y1, xEnd, yEnd);
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);
}

int main(int argc, char** argv) {
    cout << "Enter x1 y1 for line->" << endl;
    cin >> x1 >> Y1;
    cout << "Enter xEnd yEnd for line->" << endl;
    cin >> xEnd >> yEnd;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bresenham Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}