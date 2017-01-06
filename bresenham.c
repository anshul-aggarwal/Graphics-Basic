//Bresenham Line drawing algorithm

#include<GL/glut.h>
#include<stdio.h>

void MyInit()
{
    glClearColor (1.0, 1.0, 1.0, 0.0); //white background
    glColor3f(0.0f, 0.0f,0.0f); // black drawing colour
    glPointSize(1.0); // 1 pixel dot!
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D(0.0, (GLdouble)500, 0.0, (GLdouble)500); //Display area
}   

int main(int argc, char **argv)
{
    int count = 0;
    int x1 = 0, y1 = 0, x2 = 100, y2 = 200;
    //scanf("%d %d %d %d", x1, y1, x2, y2);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,25);
    glutInitWindowSize(500,500);
    glutCreateWindow("Green window");
    MyInit();
    glClear (GL_COLOR_BUFFER_BIT); //clear pixel buffer
    int dy, dx;
    dy = y2-y1;
    dx = x2-x1;
    int p_k1, p_k, y_k1, y_k = y1, x_k1, x_k = x1;
    int p0;
    p0 = 2*dx - dy;
    p_k = p0;
    while(1)
    {
        if (y_k == y2) break;
        y_k1 = y_k + 1;
        if (p_k < 0)
        {
            p_k1 = p_k + 2*dx;
            x_k1 = x_k;
        }
        else
        {
            p_k1 = p_k + 2*dx - 2*dy;
            x_k1 = x_k + 1;
        }
        glBegin(GL_POINTS); // render with points
        glVertex2i(x_k1,y_k1); //display a point
        x_k = x_k1;
        y_k = y_k1;
    }
    glEnd();
    glFlush();
    glutMainLoop();
    return 0;
}

