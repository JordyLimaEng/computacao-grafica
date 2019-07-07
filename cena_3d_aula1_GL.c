#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

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

static void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0,50.0,-50.0,50.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_LINES); //desenha uma linha
        glColor3d(1,0.5,1.0);
        glVertex2d(-10,-5);
        glVertex2d(10,10);
    glEnd();

    glBegin(GL_POINTS);//desenha pontos
        glColor3d(0,1.0,1.0);
        glVertex2d(-30,0);
        glVertex2d(-10,-30);
        glVertex2d(-30,-30);

    glEnd();

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
