#include <GL/glut.h>
#include <stdio.h>
#include "Map.hpp"
#include "GL.hpp"

Map* GL::mMap = 0;

void drawSquare() // 妥協
{
	glColor3d(0.5, 1.0, 0.5); // みどり
	glBegin(GL_QUADS);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(1.0, 0.0, 0.0);
	glVertex3d(1.0, 1.0, 0.0);
	glVertex3d(0.0, 1.0, 0.0);
	glEnd();

	glColor3d(0.0, 0.0, 0.0); // くろ
	glBegin(GL_LINE_LOOP);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(1.0, 0.0, 0.0);
	glVertex3d(1.0, 1.0, 0.0);
	glVertex3d(0.0, 1.0, 0.0);
	glEnd();
}

void GL::drawMapCell(int x, int y, int z)
{
	glLoadIdentity();
	glTranslated(x, y, z);
	drawSquare();
}

void GL::init(const char* name, const char* init_data)
{
	// 基本となる正方形を初期化
	glNewList(PRI_SQUARE, GL_COMPILE);
	glBegin(GL_QUADS);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(1.0, 0.0, 0.0);
	glVertex3d(1.0, 1.0, 0.0);
	glVertex3d(0.0, 1.0, 0.0);
	glEnd();
	glEndList();

	glClearColor(1.0, 1.0, 1.0, 1.0);

	mMap = new Map(name, init_data);
}

void GL::display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//	glCallList(PRI_SQUARE);// ほんとはこれしたい
	mMap->draw();

	glFlush();
}

void GL::resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0, 10.0, 0.0, 10.0, -2.0, 2.0);
	gluPerspective(100.0, 1.0, 1.0, 100.0);
	gluLookAt(3.0, -4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	//gluLookAt(1.0, -1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}
