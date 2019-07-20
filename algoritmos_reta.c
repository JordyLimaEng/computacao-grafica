#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define Pixelx 800
#define Pixely 600






void eq_reta(){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1.0,1.0,1.0);

    int x,y;
    float TempoInicio, TempoFinal, Reta;

    float x1=0,y1=0,x2=100000,y2=100000;
    int dx = x2-x1;

    float m = (y2-y1)/(x2-x1);

    glBegin(GL_POINTS);
    TempoInicio = GetTickCount(); //inicia contagem

    //Algoritmo da eq reta
    for(int i=x1; i<x2; i++){
        x = (m*(y2 - y1)) - x1;
        y = (m*(x2 - x1)) - y1;

        if(x >= 0 && y>=0){
                printf("%d, %d\n",x,y );
            glVertex2f(x,y);
        }

        x1++;
        y1++;
    }

    TempoFinal = GetTickCount();
    Reta = TempoFinal - TempoInicio;
    printf("Tempo Algoritmo Eq Reta - %.6f s\n", Reta/1000);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void brenseham(){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1.0,1.0,0.0);

    float TempoInicio, TempoFinal, Bres;
    int x,y;
    int x1 = 0, y1 = 0, x2 = 100000, y2 = 100000; //pontos inicial e final

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * (dy - dx);

    TempoInicio = GetTickCount(); //inicia contagem
    if(x1>x2){
        x = x2;
        y = y2;
        x2 = x1;
    }else{
        x = x1;
        y = y1;
    }

    glBegin(GL_POINTS);
    glVertex2f(x,y);

      while(x < x2){
          x++;
          if(p<0)
           p += 2 * dy;
          else{
           y++;
           p += 2*(dy-dx);
      }
    glVertex2f(x,y);
    }
    TempoFinal = GetTickCount();

    Bres = TempoFinal - TempoInicio;
    printf("Tempo Algoritmo BRESEHAM - %.6f s\n", Bres/1000);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void DDA(){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1.0,0.0,0.0);

    float TempoInicio, TempoFinal, DDA;
    int x,y;
    int x1 = 0, y1 = 0, x2 = 100000, y2 = 100000; //pontos inicial e final

    TempoInicio = GetTickCount(); //inicia contagem
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int steps;

    //calcula a inclinação
    dx = x2-x1;
    dy = y2-y1;

    //verifica para qual eixo a reta está mais próxima
    if( abs(dx) >= abs(dy) )
        steps = abs(dx);
    else
        steps = abs(dy);

    glBegin(GL_POINTS);
    glVertex2f(x1,y1);

    for(int i=1; i<=steps; i++){
        x1 = x1+dx/steps;
        y1 = y1+dy/steps;

        glVertex2f(x1,y1);
    }

    TempoFinal = GetTickCount();

    DDA = TempoFinal - TempoInicio;
    printf("Tempo Algoritmo DDA - %.6f s\n", DDA/1000);
    glEnd();
    glFlush();
    glutSwapBuffers();
}


int main(int argc, char *argv[]){

    glutInit(&argc, argv);//Inicia GLUT
    glutInitWindowSize(Pixelx, Pixely);//Tamanho da janela na área do monitor
    glutInitWindowPosition(10,10);//Posição da janela no monitor
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );//Define modo de exibição

    glutCreateWindow("Eq_reta");//Título da janela
    gluOrtho2D(0.0,50.0,0.0,50.0);
    glutDisplayFunc(eq_reta);//Processamento da Cena

    glutCreateWindow("breseham");//Título da janela
    gluOrtho2D(0.0,50.0,0.0,50.0);
    glutDisplayFunc(brenseham);//Processamento da Cena

    glutCreateWindow("DDA");//Título da janela
    gluOrtho2D(0.0,50.0,0.0,50.0);
    glutDisplayFunc(DDA);//Processamento da Cena

    glutMainLoop();// laço gráfico

    return 0;
}
