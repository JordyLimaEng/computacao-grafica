#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>


using namespace std;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

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
    glOrtho(-50,50,-50,50,1,50);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0,0,-2);
    gluLookAt(20,20,20, 0,0,0, 0,0,1);//reposiciona a camera e coloca eixo Z para cima

    Desenha_Eixos(40,40,40); //eixos com valor máximo até 40

    glColor3d(1,1,1);
    glutWireCube(15.5);

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);//Inicia GLUT
    glutInitWindowSize(640,480);//Tamanho da janela na área do monitor
    glutInitWindowPosition(10,10);//Posição da janela no monitor
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE );//Define modo de exibição

    glutCreateWindow("Cena 3D");//Título da janela

    glutReshapeFunc(resize);//redimensiona
    glutDisplayFunc(display);//Processamento da Cena

    glutMainLoop();// laço gráfico

    return EXIT_SUCCESS;
}
