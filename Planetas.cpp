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

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void Desenha_Eixos(int dim_x, int dim_y, int dim_z){

    glBegin(GL_LINES); //Eixo X - Vermelho
        glColor3d(1,0,0);
        glVertex3f(dim_x,0,0);
        glVertex3f(0,0,0);
    glEnd();

    glBegin(GL_LINES); //Eixo Y - Verde
        glColor3d(0,1,0);
        glVertex3f(0,dim_y,0);
        glVertex3f(0,0,0);
    glEnd();

    glBegin(GL_LINES); //Eixo Z - Azul
        glColor3d(0,0,1);
        glVertex3f(0,0,dim_z);
        glVertex3f(0,0,0);
    glEnd();

}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    ///void glOrtho(GLdouble left,GLdouble right,GLdouble bottom,GLdouble top,GLdouble nearVal,GLdouble farVal);
    glOrtho(-100,100,-100,100,1,100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0,0,0);

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
    glRotated(-90,1,0,0);
    glRotated(-45,0,0,1);
    glTranslated(20,0,0);
    glColor3d(1,1,1);
	glRotatef(R_SOL+1.0,0,1,0);
	glutWireSphere(3, 50, 50);

	R_SOL+=0.05;
    glFlush();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);//Inicia GLUT
    glutInitWindowSize(640,480);//Tamanho da janela na área do monitor
    glutInitWindowPosition(10,10);//Posição da janela no monitor
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE );//Define modo de exibição

    glutCreateWindow("Solar System");//Título da janela

    glutReshapeFunc(resize);//redimensiona
    glutDisplayFunc(display);//Processamento da Cena
    glutIdleFunc(display);

    glutMainLoop();// laço gráfico

    return EXIT_SUCCESS;
}
