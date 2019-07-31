#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>

//Alteração da "caixa" de visualização, teclas de comandos:
/// parametro = tecla + e tecla -
/// LEFT = F12 e F11
/// RIGHT = F10 e F9
/// BOTTOM = F8 e F7
/// TOP = F6 e F5
/// FAR = F4 e F3
/// NEAR = F2 e F1

// os rotates estão bugados, mas a tentativa era de rotacionar no eixo x e eixo y separadamente.
/// EIXO Y = seta para ESQUERDA e seta para DIREITA
/// EIXO X = seta para CIMA e seta para BAIXO

using namespace std;

float angle = 0.0f, a = 10.0f, red=255, green=255, blue=255, eixo_x=0.0f, eixo_y=0.0f, eixo_z=0.0f;
int fg=1, fg_color=1;

//Parametros para GLOrtho
double esq=-50, dir=50, baixo=-50, cima=50, perto=1, longe=50;

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
    glOrtho(esq, dir, baixo, cima, perto, longe);
    //glFrustum(esq, dir, baixo, cima, perto, longe);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0,0,-2);
    gluLookAt(20,20,20, 0,0,0, 0,0,1);//reposiciona a camera e coloca eixo Z para cima
    glRotatef(angle, eixo_x, eixo_y, eixo_z);

    Desenha_Eixos(40,40,40); //eixos com valor m�ximo at� 40

    glColor3d(red,green,blue);
    glutWireTeapot(10);

    glFlush();
}

void TeclasEspeciais(int key, int x, int y) {

	switch(key) {
		case GLUT_KEY_F1 :
		    cout << "near = " << perto <<endl;
                perto += 0.5;
                break;
		case GLUT_KEY_F2 :
		     cout << "near = " << perto <<endl;
                perto -= 0.5;
                break;
		case GLUT_KEY_F3 :
		    cout << "far = " << longe <<endl;
                longe += 0.5;
                break;
        case GLUT_KEY_F4 :
            cout << "far = " << longe <<endl;
                longe -= 0.5;
                break;
        case GLUT_KEY_F5 :
		    cout << "top = " << cima <<endl;
                cima += 0.5;
                break;
		case GLUT_KEY_F6 :
		     cout << "top = " << cima <<endl;
                cima -= 0.5;
                break;
		case GLUT_KEY_F7 :
		    cout << "bottom = " << baixo <<endl;
                baixo += 0.5;
                break;
        case GLUT_KEY_F8 :
            cout << "bottom = " << baixo <<endl;
                baixo -= 0.5;
                break;
        case GLUT_KEY_F9 :
		    cout << "right = " << dir <<endl;
                dir += 0.5;
                break;
		case GLUT_KEY_F10 :
		     cout << "right = " << dir <<endl;
                dir -= 0.5;
                break;
		case GLUT_KEY_F11 :
		    cout << "left = " << esq <<endl;
                esq += 0.5;
                break;
        case GLUT_KEY_F12 :
            cout << "left = " << esq <<endl;
                esq -= 0.5;
                break;
        case GLUT_KEY_LEFT :
            cout << "angulo = " << angle <<endl;
                eixo_x=0.0f;
                eixo_y=1;
                eixo_z=0.0f;
                angle -= 2.5;
                break;
        case GLUT_KEY_RIGHT :
            cout << "angulo = " << angle <<endl;
                eixo_x=0.0f;
                eixo_y=1;
                eixo_z=0.0f;
                angle += 2.5;
                break;
        case GLUT_KEY_UP :
            cout << "angulo = " << angle <<endl;
                eixo_x=1;
                eixo_y=0.0f;
                eixo_z=0.0f;
                angle -= 2.5;
                break;
        case GLUT_KEY_DOWN :
            cout << "angulo = " << angle <<endl;
                eixo_x=1;
                eixo_y=0.0f;
                eixo_z=0.0f;
                angle += 2.5;
                break;
	}
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);//Inicia GLUT
    glutInitWindowSize(640,480);//Tamanho da janela na �rea do monitor
    glutInitWindowPosition(10,10);//Posi��o da janela no monitor
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE );//Define modo de exibi��o

    glutCreateWindow("Cena 3D");//T�tulo da janela

    glutReshapeFunc(resize);//redimensiona
    glutDisplayFunc(display);//Processamento da Cena

    glutIdleFunc(display); //chama função de criação da cena quando programa está inativo

	glutSpecialFunc(TeclasEspeciais);

    glutMainLoop();// la�o gr�fico

    return EXIT_SUCCESS;
}


/**<
GLUT_KEY_F1		    F1 function key
GLUT_KEY_F2		    F2 function key
GLUT_KEY_F3		    F3 function key
GLUT_KEY_F4		    F4 function key
GLUT_KEY_F5		    F5 function key
GLUT_KEY_F6		    F6 function key
GLUT_KEY_F7		    F7 function key
GLUT_KEY_F8		    F8 function key
GLUT_KEY_F9		    F9 function key
GLUT_KEY_F10		F10 function key
GLUT_KEY_F11		F11 function key
GLUT_KEY_F12		F12 function key
GLUT_KEY_LEFT		Left function key
GLUT_KEY_RIGHT		Right function key
GLUT_KEY_UP		    Up function key
GLUT_KEY_DOWN		Down function key
GLUT_KEY_PAGE_UP	Page Up function key
GLUT_KEY_PAGE_DOWN	Page Down function key
GLUT_KEY_HOME		Home function key
GLUT_KEY_END		End function key
GLUT_KEY_INSERT		Insert function key
 */
