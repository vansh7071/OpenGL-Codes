#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

// Center of the cicle = (320, 240)
int xc, yc, rx,ry;

// Plot eight points using circle's symmetrical property
void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x , y);
    glEnd();
}

void midptellipse(int rx, int ry,
    int xc, int yc)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) +
        (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // For region 1
    while (dx < dy)
    {

        // Print points based on 4-way symmetry
        plot(x + xc, y + yc);
        plot(-x + xc, y + yc);
        plot(x + xc, -y + yc);
        plot(-x + xc, -y + yc);

        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
        ((rx * rx) * ((y - 1) * (y - 1))) -
        (rx * rx * ry * ry);

    // Plotting points of region 2
    while (y >= 0)
    {

        // Print points based on 4-way symmetry
        plot(x + xc ,y + yc);
        plot(-x + xc, y + yc);
        plot(x + xc, -y + yc);
        plot(-x + xc, -y + yc);

        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);

    midptellipse(rx, ry, xc, yc);

    glFlush();
}
// Function to draw a circle using bresenham's
// circle drawing algorithm

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

int main(int argc, char** argv)
{
    cout << "Enter centre cordinates for the circle" << endl;
    cout << "Enter value for x-:" << endl;
    cin >> xc;
    cout << "Enter value for y-:" << endl;
    cin >> yc;
    cout << "Enter the minor radius-:" << endl;
    cin >> rx;
    cout << "Enter the major radius-:" << endl;
    cin >> ry;
    /* Initialise GLUT library */
    glutInit(&argc, argv);
    /* Set the initial display mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /* Set the initial window position and size */
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    /* Create the window with title "DDA_Line" */
    glutCreateWindow("Mid-point ellipse");
    /* Initialize drawing colors */
    Init();
    /* Call the displaying function */
    glutDisplayFunc(display);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
    return 0;
}