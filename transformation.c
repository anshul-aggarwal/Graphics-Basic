//2D Transformations

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

float t_x = 100;
float t_y = 40;
float r_deg = 30;
float sh_x = 0.1;
float sh_y = 0;

int x[4] = {200, 300, 300, 200};
int y[4] = {200, 200, 300, 300};
int x_n[4], y_n[4];


void translate()
{
    for(int i=0;i<4;i++)
    {
        x_n[i] = x[i] + t_x;
        y_n[i] = y[i] + t_y;
        x[i] = x_n[i];
        y[i] = y_n[i];
    }
}

void mirrorY()
{
    for(int i=0;i<4;i++)
    {
        x_n[i] = (-1)*x[i];
        y_n[i] = y[i];
        x[i] = x_n[i];
        y[i] = y_n[i];
    }
}

void mirrorX()
{
    for(int i=0;i<4;i++)
    {
        x_n[i] = x[i];
        y_n[i] = (-1)*y[i];
        x[i] = x_n[i];
        y[i] = y_n[i];
    }
}

void mirrorO()
{
    for(int i=0;i<4;i++)
    {
        x_n[i] = (-1)*x[i];
        y_n[i] = (-1)*y[i];
        x[i] = x_n[i];
        y[i] = y_n[i];
    }
}


void rotate()
{
    float theta = r_deg*3.1415926/180;
    for(int i=0;i<4;i++)
    {
        x_n[i] = x[i] * cos(theta) - y[i] * sin(theta);
        y_n[i] = x[i] * sin(theta) + y[i] * cos(theta);
        
    }
    for(int i=0;i<4;i++)
    {
        x[i] = x_n[i];
        y[i] = y_n[i];
    }
}


void shear()
{
    for(int i=0;i<4;i++)
    {
        x_n[i] = x[i] + y[i] * sh_x;
        y_n[i] = y[i] + x[i] * sh_y;
        
    }
    for(int i=0;i<4;i++)
    {
        x[i] = x_n[i];
        y[i] = y_n[i];
    }
}
void transform()
{
    translate();
    rotate();
    shear();
    glBegin(GL_LINE_LOOP);
    glVertex2f(x[0], y[0]);
    glVertex2f(x[1], y[1]);
    glVertex2f(x[2], y[2]);
    glVertex2f(x[3], y[3]);
    glEnd();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,25);
    glutInitWindowSize(500,500);
    glutCreateWindow("Green window");
    MyInit();
    glClear (GL_COLOR_BUFFER_BIT); //clear pixel buffer
    transform();
    glFlush();
    glutMainLoop();
    return 0;
}

