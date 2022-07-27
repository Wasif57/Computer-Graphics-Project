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

int main(int argc, char** argv)
 {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(1280, 720);   // Set the window's initial width & height
	glutDisplayFunc(Sun); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
 }


