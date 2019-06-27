#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include <time.h>

using namespace std;

float angle = 0.0f, a = 10.0f, red=255, green=255, blue=255;
int fg=1, fg_color=1;

void renderScene(void) {

    srand (time(NULL));

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	0.0f, 0.0f, a,
                0.0f, 0.0f,  0.0f,
                0.0f, 1.0f,  0.0f);

	glRotatef(angle, 0.0f, 1.0f, 0.0f);

    glColor3f(red,green,blue);

    if(fg_color == 0){
        red = rand() % 255 + 0;
        green = rand() % 255 + 0;
        blue = rand() % 255 + 0;
    }

	glBegin(GL_TRIANGLES);
		glVertex3f(-2.0f,-2.0f, 0.0f);
		glVertex3f( 2.0f, 0.0f, 0.0);
		glVertex3f( 0.0f, 2.0f, 0.0);
	glEnd();

	angle+=0.1f;

	if(fg==0){
        Sleep(1);
        a-=0.001f;
        if(a<=9.9f){fg=1;}
	}else{
	    Sleep(1);
        a+=0.001f;
        if(a >= 20.0f){fg=0;}
	}

	glutSwapBuffers();
}

void changeSize(int w, int h){
    // Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;
	float ratio = 1.0* w / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

    // Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,1000);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y){
    if (key == 27){
        exit(0);
    }
}

void processSpecialKeys(int key, int x, int y) {

	switch(key) {
		case GLUT_KEY_F1 :
                fg_color = 1;
				red = 1.0;
				green = 0.0;
				blue = 0.0; break;
		case GLUT_KEY_F2 :
                fg_color = 1;
				red = 0.0;
				green = 1.0;
				blue = 0.0; break;
		case GLUT_KEY_F3 :
				fg_color = 1;
				red = 0.0;
				green = 0.0;
				blue = 1.0; break;
        case GLUT_KEY_F4 :
				fg_color = 1;
				red = 255;
				green = 255;
				blue = 255; break;
	}
}

int main(int argc, char **argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(550,550);
	glutCreateWindow("Vai Dar Certo Garoto! - GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	//callback function when the program is idle
	glutIdleFunc(renderScene);

	//functions to process the keyboard input
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);


	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
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
