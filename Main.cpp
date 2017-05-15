#include"Events.h"
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(15, 15);
	glutCreateWindow("Checkers Game");
	glutReshapeFunc(reshape_event_handler);
	glutDisplayFunc(display_event_handler);
	glutMouseFunc(mouse_event_handler);
	glutKeyboardFunc(keyboard_event_handler);
	/*Testing*/ //glutTimerFunc(30,rotate_the_board,0);
	glutMainLoop();
	return 0;
}