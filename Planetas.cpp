#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>


using namespace std;

float R_SOL = 0.0;
bool fg_s = false, fg_t = false, fg_l = false;

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    ///void glOrtho(GLdouble left,GLdouble right,GLdouble bottom,GLdouble top,GLdouble nearVal,GLdouble farVal);
    glOrtho(-100,100,-100,100,1,500);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0,0,-85);

    //SOL
    glRotatef(R_SOL,0,1,0);
    glColor3d(1,1,0);
	glutWireSphere(20, 50, 50);

    //TERRA
	glRotated(-90,1,0,0);
	glTranslated(50,0,0);
    glColor3d(0,0,1);
	glRotatef(R_SOL+0.75,0,1,0);
	glutWireSphere(10, 50, 50);

    //LUA
    glRotated(-55,0,0,1);
    glTranslated(15,0,0);
    glColor3d(1,1,1);
	glRotatef(R_SOL+1.0,0,1,0);
	glutWireSphere(3, 50, 50);

	R_SOL+=0.05;
    glFlush();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);//Inicia GLUT
    glutInitWindowSize(640,480);//Tamanho da janela na ?rea do monitor
    glutInitWindowPosition(10,10);//Posi??o da janela no monitor
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE );//Define modo de exibição

    glutCreateWindow("Solar System");//Título da janela

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);//Processamento da Cena
    glutIdleFunc(display);

    glutMainLoop();// laço grafico

    return EXIT_SUCCESS;
}
