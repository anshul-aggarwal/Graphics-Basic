//Liang Barsky Clipping algorithm

#include<stdio.h>
#include<GL/glut.h>

int xmin=100, ymin=100, xmax=400,ymax=400;

int x1,y_1,x2,y2;

int includecheck(double p,double q,double *t1,double *t2)
{
    double t=q/p;
    if(p<0.0)       
    {   
        if(t>*t1) *t1=t;
        if(t>*t2) return(0); 
    }
    else if(p>0.0)
    {
        if(t<*t2) *t2=t;
        if(t<*t1) return(0);
    }
    else if(p==0.0)
    { 
        if(q<0.0) return(0);
    }
    return(1);
}
void clipit(int x0,int y0,int x1,int y_1)
{
    double dx= x1-x0,dy=y_1-y0, te=0.0,tl=1.0;

    if(includecheck(-dx,x0-xmin,&te,&tl) && includecheck(dx,xmax-x0,&te,&tl) && includecheck(-dy,y0-ymin,&te,&tl) && includecheck(dy,ymax-y0,&te,&tl))
    {
        if(tl<1.0)
        {
            x1=x0+tl*dx;
            y_1=y0+tl*dy;
        }
        if(te>0.0)
        {
            x0=x0+te*dx;
            y0=y0+te*dy;
        }
    }    
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
    glEnd();
    glColor3f(0.5,0.5,0.5); 
    glBegin(GL_LINES);
    glVertex2d(x0,y0);
    glVertex2f(x1,y_1);
    glEnd();

}
void display()
{
    int x0=60,y0=20,x1=320,y_1=450;
    glClear(GL_COLOR_BUFFER_BIT);
    clipit(x0,y0,x1,y_1);
    glFlush();
}

void myinit()
{   
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)500, 0.0, (GLdouble)500); //Display area
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("LineClip");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
