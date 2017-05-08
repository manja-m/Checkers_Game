#include<GL/glut.h>
#include<math.h>
#define TWO_PI 6.28571428f
int board[8][4] = {
	{  5 , 11 , 17 , 23 },
	{  4 , 10 , 16 , 22 },
	{  3 ,  9 , 15 , 21 },
	{ -1 , -1 , -1 , -1 },
	{ -1 , -1 , -1 , -1 },
	{  2 ,  8 , 14 , 20 },
	{  1 ,  7 , 13 , 19 },
	{  0 ,  6 , 12 , 18 }
};
class Board
{
public:
	Board() {}
	virtual ~Board() {}
	void draw()
	{
		int color = 0;
		GLfloat x,y;
		for(int i = 0; i < 8; i++ )
		{
			color = i % 2 ;
			for(int j = 0; j < 8; j++)
			{
				glBegin(GL_QUADS);
				if(color == 0) { glColor3f(1.0f,0.0f,0.0f);/* Red Color */ color = 1; }
				else { glColor3f(0.0f,1.0f,0.0f);  /* Green Color */ color = 0; }
				x = -40.0f + ( i * 10);
				y = -40.0f + ( j * 10);
				glVertex2f(x, y);
				glVertex2f(x+10, y);
				glVertex2f(x+10, y+10);
				glVertex2f(x, y+10);
				glEnd();
			}
		}

	}
};
class Pawn
{
private:
	int x,y,player;
public:
	Pawn() {}
	void create_pawn(int _x,int _y,int _player)
	{
		x = _x; y = _y; player = _player;
	}
	int which_player()
	{
		return player;
	}
	void get_the_index(int *_x,int *_y)
	{
		*_x = x; *_y = y; return;
	}
	void draw()
	{
		GLfloat center_x,center_y;
		if ( player == 1 ) glColor3f(1.0f,1.0f,1.0f); // Player 1 Pawn Color
		else glColor3f(0.0f,0.0f,0.0f); // Player 2 Pawn Color
		center_x = -35.0f /* -40 + 5 */ + (GLfloat)(x*10);
		center_y = -35.0f /* -40 + 5 */ + (GLfloat)((x%2 + y)*20);
		glBegin(GL_POLYGON);
		for(float theta = 0.0; theta <  TWO_PI; theta += 0.2f)
			glVertex2f(center_x + 4.5f * cos(theta), center_y + 4.5f * sin(theta));
		glEnd();
	}
};