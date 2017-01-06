//Bresenham Mid Point Ellipse algorithm

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

void EllipsePoints(int x, int y)
{
    glVertex2i(xc+x,yc+y);
    glVertex2i(xc-x,yc+y);
    glVertex2i(xc+x,yc-y);
    glVertex2i(xc-x,yc-y);
}

void MidPointEllipse(int rx, int ry)
{
    int x = 0;
    int y = ry;
    EllipsePoints(x,y);
    int p1, p2;
    p1 = ry*ry-rx*rx*ry+rx*rx/4;
    while(2*ry*ry*x<=2*rx*rx*y)
    {
        x++;
        if (p1>=0)
        {
            y=y-1;
            p1+=2*ry*ry*x+ry*ry-2*rx*rx*y; 
        }
        else
        {
            p1+=2*ry*ry*x+ry*ry;
        }        
        EllipsePoints(x,y);
    }
    p2 = ry*ry*x*x + ry*ry/4 + ry*ry*x + rx*rx*y*y + rx*rx - rx*rx*2*y - rx*rx*ry*ry;
    while(2*ry*ry*x>2*rx*rx*y)
    {
        y--;
        if (p2<=0)
        {
            x=x+1;
            p2+=2*ry*ry*x+rx*rx-2*rx*rx*y; 
        }
        else
        {
            p2+=(-2)*rx*rx*y+rx*rx;
        }        
        EllipsePoints(x,y);
        if(y<=0) break;
    }
}


int main(int argc, char **argv)
{
    int rx = 200;
    int ry = 100;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,25);
    glutInitWindowSize(500,500);
    glutCreateWindow("Green window");
    MyInit();
    glClear (GL_COLOR_BUFFER_BIT); //clear pixel buffer
    glBegin(GL_POINTS); // render with points
    MidPointEllipse(rx,ry);
    glEnd();
    glFlush();
    glutMainLoop();
    return 0;
}

