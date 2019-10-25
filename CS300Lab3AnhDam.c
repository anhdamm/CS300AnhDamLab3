// Anh Dam - Lab 3
#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>

// Declare global variables
float theta;
float frameNumber = 0.0;
GLfloat xt=0.0,yt=0.0,zt=0.0,xw=0.0;   /* x,y,z translation */
GLfloat xs=1.0,ys=1.0,zs=1.0;
float rotX = 0.0, rotY = 0.0;
GLfloat xangle=0.0,yangle=0.0,zangle=0.0,angle=0.0;   /* axis angles */

/*
 Initializes OpenGL
 */
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-600, 600, -600, 600, -600, 600);
    glMatrixMode(GL_MODELVIEW);
}

/*
 Draw the front of the car
 */
void front() {
    glColor3f(0.917647, 0.678431, 0.917647);
    glPushMatrix();
    glTranslatef(-450.0, -250.0, 0.0);
    glScalef(0.01, 0.3, 0.85);
    glutSolidCube(600);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(600);
    glPopMatrix();
    
    glColor3f(0.7, 0.3, 0.0);
    glPushMatrix();
    glTranslatef(-370.0, -70.0, 0.0);
    glRotatef(-45.0, 0.0, 0.0, 1.0);
    glScalef(0.01, 0.42, 0.85);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(600);
    glPopMatrix();
}

/*
 Draw the back of the car
 */
void back() {
    glColor3f(0.8, 0.196078, 0.6);
    glPushMatrix();
    glTranslatef(450.0, -250.0, 0.0);
    glScalef(0.01, 0.3, 0.85);
    glutSolidCube(600);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(600);
    glPopMatrix();
    
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(380.0, -80.0, 0.0);
    glRotatef(38.0, 0.0, 0.0, 1.0);
    glScalef(0.01, 0.42, 0.85);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(600);
    glPopMatrix();
}

/*
 Draw the top of the car
 */
void top() {
    glColor3f(0.85, 0.85, 0.1);
    glPushMatrix();
    glTranslatef(15.0, 20.0, 0.0);
    glScalef(1, 0.01, 0.85);
    glutSolidCube(600);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(600);
    glPopMatrix();
}

/*
 Draw the bottom of the car
 */
void bottom() {
    glColor3f(0.85, 0.85, 0.95);
    glPushMatrix();
    glTranslatef(0.0, -350.0, 0.0);
    glScalef(1.5, 0.01, 0.85);
    glutSolidCube(600);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(600);
    glPopMatrix();
}

/*
 Draw the left side of the car
 */
void left() {
    glColor3f(0.59, 0.41, 0.31);
    glPushMatrix();
    glTranslatef(0.0, -250.0, 250.0);
    glScalef(1.5, 0.3, 0.01);
    glutSolidCube(600);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(600);
    glPopMatrix();
}

/*
 Draw the right side of the car
 */
void right() {
    glColor3f(0.0, 0.0, 0.61);
    glPushMatrix();
    glTranslatef(0.0, -250.0, -250.0);
    glScalef(1.5, 0.3, 0.01);
    glutSolidCube(600);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(600);
    glPopMatrix();
}

/*
 Draw the wheels of the car
 */
void wheel(int x, int y, int z) {
    float th;
    glColor3f(0.258824, 0.435294, 0.258824);
    int j;
    for(j = 0; j < 50; j += 10) {
        glBegin(GL_POLYGON);
        for(int i = 0; i < 360; i++) {
            th = i*3.142/180;
            glVertex3f(x+70*cos(th), y+70*sin(th), z+j);
        }
        glEnd();
    }
}

/*
 Draw the car's borders
 */
void carBorder() {
    glPushMatrix();
    glTranslatef(-50.0, -160.0, 250.0);
    glScalef(0.01, 0.6, 0.01);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(600);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-50.0, -160.0, -250.0);
    glScalef(0.01, 0.6, 0.01);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(600);
    glPopMatrix();
}

/*
 Draw the car by combining top/bottom/right/left/wheel functions
 */
void car() {
    front();
    back();
    top();
    bottom();
    left();
    right();
    wheel(-300, -400, 200);
    wheel(300, -400, 200);
    wheel(-300, -400, -200);
    wheel(300, -400, -200);
    carBorder();
}

/*
 Draw disk / circle
 */
void drawDisk(double radius) {
    int d;
    glBegin(GL_POLYGON);
    for (d = 0; d < 32; d++) {
        double angle = 2*4.132/32 * d;
        glVertex2d( radius*cos(angle), radius*sin(angle));

    }
    glEnd();
}

/*
 Draw the sun
 */
void drawSun() {
    int i;
    glColor3f(1,1,0);
    for (i = 0; i < 13; i++) { // Draw 13 rays, with different rotations.
        glRotatef( 360 / 13, 0, 0, 1 ); // Note that the rotations accumulate!
        glBegin(GL_LINES);
        glVertex2f(20, 20);
        glVertex2f(40, 40);
        glEnd();
    }
    drawDisk(20.0);
    glColor3f(1.0,1.0,0.0);
}

/*
 Display the objects
 */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(rotY, 0.0,1.0,0.0);
    glRotatef(rotX, 1.0,0.0,0.0);
    glRotatef(xangle,1.0,0.0,0.0);
    glRotatef(yangle,0.0,1.0,0.0);
    glRotatef(zangle,0.0,0.0,1.0);
    glTranslatef(xt,yt,zt);
    glScalef(xs,ys,zs);
    car();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(300,400,0);
    glRotatef(frameNumber*0.3,0,0,1);
    drawSun();
    glPopMatrix();
    
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

/*
  This function is set as the glutTimerFunc to drive the animation
 */
void doFrame(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(1,doFrame,0);
}

/*
 GLUT calls this routine when the window is resized
 */
void reshape ( int w, int h ) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-600, 600, -600, 600, -600, 600);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*
 GLUT calls this routine when a non-special key is pressed
 */
void keyboard(GLubyte key, GLint x, GLint y) {
#pragma unused(x,y)
    switch (key) {
        case 'q':
            exit(0); // exit
        case 'x' : // move to right
            xt += 10;
            break;
        case 'X' : // move to left
            xt -= 10;
            break;
        case 'y' : //Move up
            yt += 10;
            break;
        case 'Y' : //Move down
            yt -= 10;
            break;
        case 'z':
            zangle += 100;
            break;
    }
    glutPostRedisplay();
}

/*
GLUT calls this routine when an arrow key is pressed
 */
void SpecialKey(int key, int x, int y)
{
    
    switch (key) {
        case GLUT_KEY_UP:
            rotX -= 20.0;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            rotX += 20.0;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            rotY -= 20.0;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            rotY += 20.0;
            glutPostRedisplay();
            break;
    }
}

/*
 Executes the main() function to display window.
 */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Anh Dam Lab 3");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialKey);
    glutReshapeFunc(reshape);
    glutTimerFunc(200,doFrame,0);

    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
