#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;



void draw_triangle(void) {
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.0f, 0.5f);
    glEnd();
    glFlush();
}

// Function to draw triangles and its transformations
void display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    /* Clears buffers to preset values */
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    draw_triangle();

    // for scaling
    glColor3f(0.0f, 0.0f, 1.0f);
    glScalef(0.5f, 0.5f, 0.0f);
    draw_triangle();

    // for rotation
    glColor3f(0.0f, 1.0f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    draw_triangle();

    //for translation
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(1.0f, 1.0f, 0.0f);
    draw_triangle();


}

void Init()
{
    /* Set clear color to white */
    glClearColor(1.0, 1.0, 1.0, 0);
    /* Set fill color to black */
    glColor3f(1.0, 0.0, 0.0);
    /* glViewport(0 , 0 , 640 , 480); */
    /* glMatrixMode(GL_PROJECTION); */
    /* glLoadIdentity(); */
    gluOrtho2D(0, 640, 0, 480);
}

void main(int argc, char** argv)
{
    /* Initialise GLUT library */
    glutInit(&argc, argv);
    /* Set the initial display mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /* Set the initial window position and size */
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    /* Create the window with title "DDA_Line" */
    glutCreateWindow("2d transformations");
    /* Initialize drawing colors */
    Init();
    /* Call the displaying function */
    glutDisplayFunc(display);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
}