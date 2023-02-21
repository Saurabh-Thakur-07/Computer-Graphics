#include<iostream>
#include<GL/glut.h>
using namespace std;

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 300.0);
}
void ellipseDisplay(int xc,int yc,int rx,int ry,int rc,int gc,int bc)
{
    glPointSize(1.0);
	glBegin(GL_POLYGON);
    glColor3f(rc,gc,bc);
    // int rx=30,ry=15;//major axis minor axis
    int cx=xc,cy=yc;//coordinates of center
    float x=0,y=ry,p1,p2,dx,dy;
    p1=ry*ry+rx*rx*0.25 -rx*rx*ry;
    dx=2*ry*ry*x;
    dy=2*rx*rx*y;
    while(dx < dy)
    {
        glVertex2d(cx+x,cy+y);
        glVertex2d(cx+x,cy-y);
        glVertex2d(cx-x,cy-y);
        glVertex2d(cx-x,cy+y);
        if(p1 < 0)
        {
            x++;
            dx=dx+2*ry*ry;
            p1 = p1 + dx + ry*ry;
        }
        else
        {
            x++;
            y--;
            dx=dx+2*ry*ry;
            dy=dy-2*rx*rx;
            p1 = p1 + dx-dy+ry*ry;
        }
    }
    p2 = (ry*ry*(x+0.5)*(x+0.5))+(rx*rx*(y-1)*(y-1))-(rx*rx*ry*ry);
    while(y>=0)
    {
        glVertex2d(cx+x,cy+y);
        glVertex2d(cx+x,cy-y);
        glVertex2d(cx-x,cy-y);
        glVertex2d(cx-x,cy+y);
        if(p2 < 0)
        {
            x++;
            y--;
            dx = dx + 2*ry*ry;
            dy = dy - 2*rx*rx;
            p2 = p2 - dy+dx+ rx*rx;
        }
        else
        {
            y--;
            dy = dy - 2*rx*rx;
            p2 = p2 - dy + rx*rx;
        }
    }
    glEnd();
}
void circleDisplay(int xc,int yc,int r,int rc,int gc,int bc)
{
    glPointSize(1.0);
	glBegin(GL_POLYGON);
    glColor3f(rc,gc,bc);
    int Xcentre=xc, Ycentre=yc;
    int x=0, y=r;
    int p=1-r;

    while(x<=y)
    {
        glVertex2d(x+Xcentre, y+Ycentre);
        glVertex2d(-x+Xcentre, y+Ycentre);
        glVertex2d(x+Xcentre, -y+Ycentre);
        glVertex2d(-x+Xcentre, -y+Ycentre);
        glVertex2d(y+Xcentre, x+Ycentre);
        glVertex2d(-y+Xcentre, x+Ycentre);
        glVertex2d(y+Xcentre, -x+Ycentre);
        glVertex2d(-y+Xcentre, -x+Ycentre);
        if(p<0)
        {
            p=p+2*x+3;
            x=x+1;
        }
        else
        {
            p=p-2*y+2*x+5;
            x=x+1;
            y=y-1;
        }
    }
    glEnd();
}

void display()
{
    circleDisplay(100,100,30,1,1,0);
    //for ellitical eyes
    ellipseDisplay(92,115,6,4,0,0,0);
    ellipseDisplay(110,115,6,4,0,0,0);
    //for circular eyes
    // circleDisplay(92,115,5,0,0,0);
    // circleDisplay(110,115,5,0,0,0);
    //for traingular eyes
    // glColor3f(0.0,0.0,0.0);
    // glBegin(GL_POLYGON);
    // glBegin(GL_LINE_LOOP);
    //     glVertex3f(110.0-5,110.0,0.0);
    //     glVertex3f(120.0-5,120.0,0.0);
    //     glVertex3f(130.0-5,110.0,0.0);
    // glEnd();
    // glColor3f(0.0,0.0,0.0);
    //     glBegin(GL_POLYGON);
    //     glBegin(GL_LINE_LOOP);
    //     glVertex3f(110.0-30,110.0,0.0);
    //     glVertex3f(120.0-30,120.0,0.0);
    //     glVertex3f(130.0-30,110.0,0.0);
    // glEnd();
    //for triangular nose
    // glColor3f(0.0,0.0,0.0);
    // glBegin(GL_POLYGON);
    // glBegin(GL_LINE_LOOP);
    //     glVertex3f(100.0+3,100+5,0.0);
    //     glVertex3f(90+7,90.0,0.0);
    //     glVertex3f(110.0-2,90.0,0.0);
    // glEnd();
    //for circular nose
    circleDisplay(100,97,5,0,0,0);
    //for smile
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(90-5,100.0-15,0.0);
        glVertex3f(110+5,100-15,0.0);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 600);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Circle Midpoint");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();   
}