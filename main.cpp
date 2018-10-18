#include <windows.h>
#include <gl/gl.h>
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <fstream>
#include <iostream>
#include<stdio.h>
#include <cstdio>


using namespace std;
void renderScene(void);
void changeSize(int w, int h);
void introscreen();
void drawBuses();
void drawDatafirst();
void drawDevices();
void drawSwitches();
void processSpecialKeys(int key, int x, int y);
void processNormalKeys(unsigned char key, int x, int y);
void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string);
/////////////////////////////////////////////

float x=0.0f;
float y=0.0f;
float x1=0.0f;
float y11=0.0f;
float x2=0.0f;
float y2=0.0f;
float x3=0.0f;
float y3=0.0f;
float flag=0.0f;
float flag1=0.0f;
float flag2=0.0f;
float flag3=0.0f;


int main(int argc, char **argv)
{

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circuit switching");



    // register callbacks
    glutDisplayFunc(renderScene);
    //glutIdleFunc(renderScene);

    glutKeyboardFunc(processNormalKeys);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
void processSpecialKeys(int key, int x, int y)
{

    switch(key)
    {
    case GLUT_KEY_UP :

        break;

    }
}

void processNormalKeys(unsigned char key, int x, int y)
{

    if (key == 27)
        exit(0);

    if(key == 32 || key==13 ){
    glutIdleFunc(renderScene);
    }
    if(key == 'f')
        glutFullScreen();

}
void introscreen() {
	glColor3f(1.0f, 1.0f, 1.0f);
	char buf[100] = { 0 };
	sprintf(buf, "PC");
    renderBitmapString(-0.65f,0.0f,0.0f,GLUT_BITMAP_TIMES_ROMAN_24,buf);
	sprintf(buf, "Mob");
    glColor3f(0.0f, 0.0f, 1.0f);

	renderBitmapString(0.65f, 0.1f,0.0, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	//switch1 S1
	glColor3f(1.0f, 1.0f, 1.0f);
	sprintf(buf, "S1");
    renderBitmapString(-0.05,0.58f,0.0f,GLUT_BITMAP_TIMES_ROMAN_24,buf);

	//switch2 S2
	sprintf(buf, "S2");
    glColor3f(0.0f, 0.0f, 0.0f);
    renderBitmapString(-0.05f,0.0f,0.0f,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    //switch3 word S3
    glColor3f(1.0f, 0.0f, 0.0f);
	sprintf(buf, "S3");
    renderBitmapString(-0.05f,-0.65f,0.0f,GLUT_BITMAP_TIMES_ROMAN_24,buf);

    //space to start switching
    glColor3f(1.0f, 0.0f, 1.0f);
	sprintf(buf, "Press Space or Enter to Start Switching !");
    renderBitmapString(-0.9f,0.9f,0.0f,GLUT_BITMAP_HELVETICA_12,buf);
     glColor3f(1.0f, 1.0f, 1.0f);
	sprintf(buf, "Press f for full screen ");
    renderBitmapString(-0.9f,0.8f,0.0f,GLUT_BITMAP_HELVETICA_12,buf);
}


void changeSize(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;

    float ratio =  w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45,ratio,1,100);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}
void renderScene(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawSwitches();
    drawDevices();
    drawBuses();
    drawDatafirst();
    introscreen();

    glutSwapBuffers();

}


void drawSwitches()
{
    //draw circles for each switch
    GLfloat angle;
    int i;
    int numofsements=100;
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //upper circle
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1.0f, 0.0f, 1.0f);
    for(i=0; i<=numofsements; i++)
    {
        angle = i*2.0*3.14 /numofsements;
        glVertex3f(0.1*cos(angle),0.1*sin(angle)+0.6,0.0f);
    }

    glEnd();

    //center circle
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1.0f, 1.0f, 0.0);
    for(i=0; i<=numofsements; i++)
    {
        angle = i*2.0*3.14 /numofsements;
        glVertex3f(0.1*cos(angle),0.1*sin(angle),0.0f);
    }

    glEnd();


    //lower circle
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1.0f, 0.5f, 5.0f);
    for(i=0; i<=numofsements; i++)
    {
        angle = i*2.0*3.14 /numofsements;
        glVertex3f(0.1*cos(angle),0.1*sin(angle)-0.6,0.0f);
    }

    glEnd();
    glFlush();


}

void drawDevices()
{
//receiver
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0);

    glVertex3f(0.6f,0.3f,0.0f);
    glVertex3f(0.9f,0.3f,0.0f);
    glVertex3f(0.9f,-0.3f,0.0f);
    glVertex3f(0.6f,-0.3f,0.0f);



    glEnd();

//sender
    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 1.0);
    glVertex3f(-0.6f,0.2f,0.0f);
    glVertex3f(-0.45f,0.1f,0.0f);
    glVertex3f(-0.5f,-0.1f,0.0f);
    glVertex3f(-0.7f,-0.1f,0.0f);
    glVertex3f(-0.75f,0.1f,0.0f);



    glEnd();
    glFlush();

}
void drawBuses()
{
    //bus between right and lower switch
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.55f,-0.1f,0.0f);
    glVertex3f(-0.1f,-0.6f,0.0f);

    glEnd();
//bus between right and center switch
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.48,0.0f,0.0f);
    glVertex3f(-0.1f,0.0f,0.0f);

    glEnd();
    //bus between right and upper
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.55f,0.17f,0.0f);
    glVertex3f(-0.1f,0.6f,0.0f);


    glEnd();

    //bus between left and lower

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.6f,-0.2f,0.0f);
    glVertex3f(0.1f,-0.6f,0.0f);

    glEnd();

    //bus between left and center switch
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.1,0.0f,0.0f);
    glVertex3f(0.6f,0.0f,0.0f);

    glEnd();
    //bus between left and upper
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.6f,0.2f,0.0f);
    glVertex3f(0.1f,0.6f,0.0f);

    glEnd();
    //bus between center and upper switch
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.f,0.5f,0.0f);
    glVertex3f(0.0f,0.1f,0.0f);

    glEnd();
    //bus between center and lower switch
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f,-0.1f,0.0f);
    glVertex3f(0.0f,-0.5f,0.0f);


    glEnd();
}

void drawDatafirst()
{
    //data at first
    // right up part
    glPushMatrix();                     //Save the transformations performed thus far
  //  glTranslatef(0.1f, 0.0f, 0.0f);  // move to new refrence point
    glTranslatef(x, y, 0.0f);		    // trace x and y axis
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.7f);        //change color to off-white
    glVertex3f(-0.7f,-0.05f,0.0f);
    glVertex3f(-0.6f,-0.05f,0.0f);
    glVertex3f(-0.6f,-0.15f,0.0f);
    glVertex3f(-0.7f,-0.15f,0.0f);
    glEnd();
    // to change direction
     if (flag == 0.0)
    {
        if(x<0.1)
            x+=0.001;
        else flag=1.0;
    }
    if(flag==1.0){
        if (x < 0.65f && y>-0.65f )
        {
            x += 0.001f;
            y -= 0.001f;
        }
        else
            flag = 2.0;
    }
    if (flag == 2.0)
    {
        if (y <= 0.1f)
            y += 0.001f;
        else
            flag = 3.0;
    }
    if(flag ==3.0f)
    {
        if (x <1.4f)
            x += 0.001f;


    }


    glPopMatrix();

    //right down part

    glPushMatrix();                     //Save the transformations performed thus far
    glTranslatef(0.0f, 0.0f, 0.0f);  // move to new refrence point
    glTranslatef(x1, y11, 0.0f);		    // trace x and y axis
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.7f);        //change color to off-white
    glVertex3f(-0.7f,-0.15f,0.0f);
    glVertex3f(-0.6f,-0.15f,0.0f);
    glVertex3f(-0.6f,-0.25f,0.0f);
    glVertex3f(-0.7f,-0.25f,0.0f);

    glEnd();
    // to change direction
    if (flag1 == 0.0)
    {
        if(x1<0.2)
            x1+=0.0001;
        else flag1=1.0;
    }
    if(flag1==1.0){
        if (x1 < 0.65f && y11>-0.6f )
        {
            x1 += 0.001f;
            y11 -= 0.001f;
        }
        else
            flag1 = 2.0;
    }
    if (flag1 == 2.0)
    {
        if (y11 <= 0.2f)
            y11 += 0.001f;
        else
            flag1 = 3.0;
    }
    if(flag1 ==3.0)
    {
        if (x1 <1.3f)
            x1 += 0.001f;

           else flag1=4.0;
    }

      if(flag1==4.0){
        if( y11>0.11 )
            y11-=0.001;
         else   flag1=5.0;
    }
    if(flag1 ==5.0){
        if( x1<1.4)
            x1+=0.001;
    }
glPopMatrix();
    //up left part

    glPushMatrix();                     //Save the transformations performed thus far
    glTranslatef(x2, y2, 0.0f);		    // trace x and y axis
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.7f);        //change color to off-white

    glVertex3f(-0.8f,-0.05f,0.0f);
    glVertex3f(-0.7f,-0.05f,0.0f);
    glVertex3f(-0.7f,-0.15f,0.0f);
    glVertex3f(-0.8f,-0.15f,0.0f);
    glEnd();
    // to change direction
    if (flag2 == 0.0)
    {
        if(x2<0.2)
            x2+=0.00005;
        else flag2=1.0;
    }
    if(flag2==1.0){
        if (x2 < 0.75f && y2>-0.65f )
        {
            x2 += 0.001f;
            y2 -= 0.001f;
        }
        else
            flag2 = 2.0;
    }
    if (flag2 == 2.0)
    {
        if (y2 <= 0.1f)
            y2 += 0.001f;
        else
            flag2 = 3.0;
    }
    if(flag2 ==3.0f)
    {
        if (x2 <1.4f)
            x2 += 0.001f;


    }
    glPopMatrix();
    //down left part


    glPushMatrix();                     //Save the transformations performed thus far
    glTranslatef(x3, y3, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.7f);        //change color to off-white

    glVertex3f(-0.8f,-0.15f,0.0f);
    glVertex3f(-0.7f,-0.15f,0.0f);
    glVertex3f(-0.7f,-0.25f,0.0f);
    glVertex3f(-0.8f,-0.25f,0.0f);
    if (flag3 == 0.0)
    {
        if(x3<0.3)
            x3+=0.00005;
        else flag3=1.0;
    }
    if(flag3==1.0){
        if (x3 < 0.75f && y3>-0.6f )
        {
            x3 += 0.001f;
            y3 -= 0.001f;
        }
        else
            flag3 = 2.0;
    }
    if (flag3 == 2.0)
    {
        if (y3 <= 0.2f)
            y3 += 0.001f;
        else
            flag3 = 3.0;
    }
    if(flag3 ==3.0)
    {
        if (x3 <1.4f)
            x3 += 0.001f;

           else flag3=4.0;
    }

    if(flag3==4.0){
        if( y3>0.11)
            y3-=0.001;
    }
    glEnd();

    glPopMatrix();

}
//bitmap for show strings on screen
void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {

  char *c;
  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}

