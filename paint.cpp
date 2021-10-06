#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/freeglut.h>
#endif
#include <iostream>
#include <stdlib.h>

int pointSize = 15;
int pointSizeMax = 25;
int pointSizeMin = 5;
bool leftClick = false;
bool clear = true;

void display(void)
{
	if(clear == true)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POINTS);
		glEnd();
		glFlush();
		clear = false;
	}
	
}

void mouse(int button, int state, int x , int y)
{
	y = 600 - y;
	std::cout << "Mouse coordinates: ";
	std::cout << x << ", " << y << std::endl; // endline is neccassary for terminal to print line by line

	if (button == GLUT_LEFT_BUTTON)
	{
		std::cout << "LEFT BUTTON" << std::endl;
		if (state == GLUT_UP)
		{
			std::cout << "RELEASED!" << std::endl;
			leftClick = false;
		}
		if (state == GLUT_DOWN)
		{
			std::cout << "PRESSED!" << std::endl;
			leftClick = true;
			glPointSize(pointSize);
			glBegin(GL_POINTS);
			glVertex2f(x, y);
			glEnd();
			glFlush();
		}
	}
}

void motion(int x, int y)
{
	y = 600 - y; // flip y
	glPointSize(pointSize);
	if(leftClick == true)
	{
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
	}
	glFlush();
}

void keyboard(unsigned char key, int xmouse, int ymouse)
{
	switch (key){
		case 'R':
		case 'r':
			clear = true;
			glutPostRedisplay();
			// glClear(GL_COLOR_BUFFER_BIT);
			// glBegin(GL_POINTS);
			// glEnd();
			// glFlush();
			std::cout << "SCREEN CLEARED!" << std::endl; 
			break;
		case 'Q':
		case 'q':
			std::cout << "BYE!" << std::endl; 
			exit(0);
			break;
		case '1':
			glColor3f(1,1,1);
			std::cout << "WHITE!" << std::endl;
			break;
		case '2': 
			glColor3f(1,1,0);
			std::cout << "YELLOW!" << std::endl;
			break;
		case '3': 
			glColor3f(1,0,0);
			std::cout << "RED!" << std::endl;
			break;
		case '4': 
			glColor3f(0,1,0);
			std::cout << "GREEN!" << std::endl;
			break;
		case '5': 
			glColor3f(0,0,1);
			std::cout << "BLUE!" << std::endl; 
			break;
		case '+': 
			if(pointSize<pointSizeMax)
			{
				pointSize+=5;
				std::cout << "Point size changed to " << pointSize << std::endl; 
			}
			else
			{
				std::cout << "Point size is already at max " << std::endl;
			}
			break;
		case '-': 
			if(pointSize>pointSizeMin)
			{
				pointSize-=5;
				std::cout << "Point size changed to " << pointSize << std::endl; 
			}
			else
			{
				std::cout << "Point size is already at min " << std::endl;
			}
			break;
		case 's':
			// glColor3f(1, 0, 0);
			glBegin(GL_POLYGON);

			 // <--- -0.60 instead of -0.68
			glVertex3f(300, 560, 0); // <--- -0.68 instead of -0.60
			glVertex3f(400, 415, 0);
			glVertex3f(575, 415, 0);
			glVertex3f(400, 250, 0);
			glVertex3f(500, 450, 0);
			glVertex3f(300, 200, 0);
			glVertex3f(100, 450, 0);
			glVertex3f(200, 250, 0);
			glVertex3f(25, 415, 0);
			glVertex3f(200, 415, 0);

			glEnd();
		default:
         	break;
	}
}

/* main function - program entry point */
int main(int argc, char** argv)
{
	glutInit(&argc, argv);		//starts up GLUT
	glutInitWindowSize(600, 600);
	glutCreateWindow("Paint");	//creates the window
	gluOrtho2D(0, 600, 0, 600);
	glutDisplayFunc(display);	//registers "display" as the display callback function
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	glutMainLoop();				//starts the event loop

	return(0);					//return may not be necessary on all compilers
}









