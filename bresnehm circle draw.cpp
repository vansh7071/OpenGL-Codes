#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

// Center of the cicle = (320, 240)
int xc, yc,radius;

// Plot eight points using circle's symmetrical property
void plot_point(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc - y, yc - x);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc - y, yc + x);
    glEnd();
}

// Function to draw a circle using bresenham's
// circle drawing algorithm
void bresenham_circle(int r)
{
    int x = 0, y = r;
    float pk = 3-2*r;

    /* Plot the points */
    /* Plot the first point */
    plot_point(x, y);
    int k;
    /* Find all vertices till x=y */
    while (y>=x)
    {
        x++;
        if (pk < 0) {
           pk = pk + 4*x + 6;
        }
            
        else
        {
             y--;
            pk = pk + 4 * (x-y) + 10;
            
        }
        plot_point(x, y);
    }
    glFlush();
}

// Function to draw two concentric circles
void concentric_circles(void)
{
    /* Clears buffers to preset values */
    glClear(GL_COLOR_BUFFER_BIT);

    bresenham_circle(radius);
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
    cout<< "Enter centre cordinates for the circle" << endl;
    cout << "Enter value for x-:"<<endl;
    cin >> xc;
    cout << "Enter value for y-:" << endl;
    cin >> yc;
    cout << "Enter the radius-:" << endl;
    cin >> radius;
    /* Initialise GLUT library */
    glutInit(&argc, argv);
    /* Set the initial display mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /* Set the initial window position and size */
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    /* Create the window with title "DDA_Line" */
    glutCreateWindow("bresenham_circle");
    /* Initialize drawing colors */
    Init();
    /* Call the displaying function */
    glutDisplayFunc(concentric_circles);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
}