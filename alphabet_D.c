//Create Alphabet D

#include<GL/glut.h>

int cx = 200, cy = 250;

void scp(int x, int y)
{
    glVertex2i(cx+x, cy+y);
    glVertex2i(cx+y, cy+x);
    glVertex2i(cx+x, cy-y);
    glVertex2i(cx+y, cy-x);
}


void semicircle(int radius)
{
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    scp(x,y);
    while(y>x)
    {
        if(d<0)
        {
            d += 2*x + 3;
        }
        else
        {
            d += 2*(x-y) + 5;
            y--;
        }
        x++;
        scp(x,y);
    }
}  

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    semicircle(100);
    semicircle(120);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(200, 150);
    glVertex2f(200, 350);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(180, 150);
    glVertex2f(180, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(180, 130, 0);
    glVertex3f(200, 130, 0);
    glVertex3f(200, 150, 0);
    glVertex3f(180, 150, 0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(180, 350, 0);
    glVertex3f(200, 350, 0);
    glVertex3f(200, 370, 0);
    glVertex3f(180, 370, 0);
    glEnd();
    glFlush();
}


void MyInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0); //drawing color
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble)500, 0, (GLdouble)500);
       
}

void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("Green Window");
    MyInit();

    glutDisplayFunc(display);

    glutMainLoop();
}
