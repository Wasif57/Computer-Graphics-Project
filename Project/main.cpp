#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<GL/gl.h>
#include<cstring>
#include<windows.h>
#include<mmsystem.h>

float angle1=30.0f;
float angle2=0.2f;
float angle3=0.0f;
float angle4=0.0f;

float speed1=3.0f;
float speed2=3.0f;

float cloudX=0;
float cloudY=0;

float cloudX2=0;
float CloudY2=0;

int cloudStatus=1;

void handleKeyPress(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 27: //escape button
        exit(0);
    default:
        break;
    }

    glutPostRedisplay();
}

void idle()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300.0, 300.0, -200.0, 200.0);
}

void initRendering() //initialize Rendering
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); // enable lighting
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<num_segments;i++)
    {
        float a=2.0f *3.1415926f * float(i)/float(num_segments);

        float x=r * cosf(a);
        float y=r * sinf(a);

        glVertex2f(x+cx, y+cy);
    }
    glEnd();
}

void Sun()
{
    glPushMatrix();

    glColor3f(1.000,1.000,0.000);
    DrawCircle(110,170,20,100);
    glPopMatrix();
}

void House()
{
    glBegin(GL_POLYGON); //gate
    glColor3f(0.412,0.412,0.412);
    glVertex2f(-50,-80);
    glVertex2f(-50,35);
    glVertex2f(10,75);
    glVertex2f(70,35);
    glVertex2f(70,-80);


    glBegin(GL_POLYGON); //door
    glColor3f(0.3,0.2,0.0);
    glVertex2f(-60,-80);
    glVertex2f(-60,40);
    glVertex2f(10,90);
    glVertex2f(80,40);
    glVertex2f(80,-80);
    glEnd();


    glBegin(GL_POLYGON); //room
    glColor3f(1.000,0.647,0.000);
    glVertex2f(-100,-80);
    glVertex2f(-100,110);
    glVertex2f(50,110);
    glVertex2f(100,70);
    glVertex2f(80,40);
    glVertex2f(10,90);
    glVertex2f(-60,40);
    glVertex2f(-60,-80);
    glVertex2f(-60,-80);
    glEnd();


    glBegin(GL_POLYGON); //left room window
    glColor3f(0.663,0.663,0.663);
    glVertex2f(-170,-70);
    glVertex2f(-170,40);
    glVertex2f(-110,40);
    glVertex2f(-100,-70);


    glBegin(GL_POLYGON); //left room
    glColor3f(0.3,0.2,0.0);
    glVertex2f(-180,-80);
    glVertex2f(-180,110);
    glVertex2f(-100,110);
    glVertex2f(-100,-80);
    glEnd();


    glBegin(GL_POLYGON); //roof
    glColor3f(0.698,0.133,0.133);
    glVertex2f(-190,110);
    glVertex2f(-140,165);
    glVertex2f(-100,110);
    glVertex2f(-90,110);
    glEnd();

    glBegin(GL_POLYGON); //right room window
    glColor3f(0.663,0.663,0.663);
    glVertex2f(90,-20);
    glVertex2f(90,30);
    glVertex2f(140,30);
    glVertex2f(140,-20);


    glBegin(GL_POLYGON); //right room
    glColor3f(1.000,0.549,0.000);
    glVertex2f(80,-80);
    glVertex2f(80,40);
    glVertex2f(150,40);
    glVertex2f(150,-80);
    glEnd();


    glBegin(GL_POLYGON); //right roof
    glColor3f(0.698,0.133,1.333);
    glVertex2f(70,40);
    glVertex2f(115,90);
    glVertex2f(160,40);

}

int main(int argc, char** argv)
 {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(1280, 720);   // Set the window's initial width & height
	glutDisplayFunc(Sun); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
 }


