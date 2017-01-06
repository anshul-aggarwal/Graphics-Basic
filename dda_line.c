//DDA Line drawing algorithm

#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

void Displaydot()
{
    glClear (GL_COLOR_BUFFER_BIT); //clear pixel buffer
    glBegin(GL_POINTS); // render with points
    glVertex2i(50,40); //display a point
    glEnd();
    glFlush();
}

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
    int x1 = 0, y1 = 500, x2 = 100, y2 = 80;
    //scanf("%d %d %d %d", x1, y1, x2, y2);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,25);
    glutInitWindowSize(500,500);
    glutCreateWindow("Green window");
    MyInit();
    glClear (GL_COLOR_BUFFER_BIT); //clear pixel buffer
    int steps;
    char mode;
    float xinc, yinc;
    if(fabs(x2-x1)>fabs(y2-y1))
    {
        steps = fabs(x2-x1);
        mode = 'x';
        xinc = 1;
        yinc = fabs(y2-y1)/steps;
    }
    else
    {
        steps = fabs(y2-y1);
        mode = 'y';
        yinc = 1;
        xinc = fabs(x2-x1)/steps;
    }
    float x = x1, y = y1;
    while(1)
    {
        //glutDisplayFunc(Displaydot);
        int a, b;
        a = round(x);
        b = round(y);
        //glClear (GL_COLOR_BUFFER_BIT); //clear pixel buffer
        glBegin(GL_POINTS); // render with points
        glVertex2i(a,b); //display a point
        count++;
        //printf("\n(%d, %d)", a,b);
        //glEnd();
        //glFlush();
        if (round(x)==x2 && round(y)==y2) break;
        if (x1<x2) x = x+xinc;
        else x = x-xinc;
        if (y1<y2) y = y+yinc;
        else y = y-yinc;
    }
    //printf("%d", count);
    glEnd();
    glFlush();
    glutMainLoop();
    return 0;
}

