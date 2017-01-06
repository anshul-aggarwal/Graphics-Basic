//Bresenham Mid Point Circle

#include<GL/glut.h>
#include<math.h>
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

int xc = 250;
int yc = 250;

void CirclePoints(int x, int y)
{
    glVertex2i(xc+x,yc+y);
    glVertex2i(xc+x,yc-y);
    glVertex2i(xc-x,yc+y);
    glVertex2i(xc-x,yc-y);
    glVertex2i(xc+y,yc+x);
    glVertex2i(xc+y,yc-x);
    glVertex2i(xc-y,yc+x);
    glVertex2i(xc-y,yc-x);
}

void MidPointCircle(int radius)
{
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    CirclePoints(x,y);
    
    while(y>x)
    {
        if (d<0) d+= 2*x+3;
        else
        {
            d += 2*(x-y)+5;
            y--;
        }
        x++;
        CirclePoints(x,y);
    }
}


int main(int argc, char **argv)
{
    int radius = 100;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,25);
    glutInitWindowSize(500,500);
    glutCreateWindow("Green window");
    MyInit();
    glClear (GL_COLOR_BUFFER_BIT); //clear pixel buffer
    glBegin(GL_POINTS); // render with points
    MidPointCircle(radius);
    glEnd();
    glFlush();
    glutMainLoop();
    return 0;
}

