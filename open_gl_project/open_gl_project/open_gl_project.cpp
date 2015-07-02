// open_gl_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h> 

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.f, 0.f, 0.f);

    glRectf(-25.f, 25.f, 25.f, -25.f);

    glFlush();
}


void SetupRC(void)
{
    glClearColor(0.f, 0.f, 1.f, 1.f);
}


void ChangeSize(GLsizei w, GLsizei h)
{
    if (h == 0)
    {
        h = 1;
    }

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    GLfloat aspectRatio = (GLfloat)w / (GLfloat)h;

    if (w <= h)
    {
        glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 /aspectRatio, 1.0, -1.0);
    }
    else
    {
        glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void Display() 
{
    glClear(GL_COLOR_BUFFER_BIT); 
    glFlush(); 
}

void Initialize()
{ 
    glClearColor(0.8, 1.0, 0.6, 1.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(-200.0, 200.0, -200.0, 200.0, -5.0, 5.0); 
}

int main(int argc, char ** argv)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("GLRect");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    SetupRC();
    glutMainLoop();

//     glutInit(&argc, argv); 
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
//     glutInitWindowSize(400, 400); 
//     glutInitWindowPosition(100, 200); 
//     glutCreateWindow("Our first GLUT application!"); 
//     glutDisplayFunc(Display); 
//     Initialize(); 
//     glutMainLoop(); 
    return 0; 
}
