#include <GL/glut.h>
#include "Structure.hpp"
#include "SimpleStructure.hpp"

void drawRect()
{
	glColor3d(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3d(0.1, 0.1, 0.0);
	glVertex3d(0.9, 0.1, 0.0);
	glVertex3d(0.9, 0.1, 1.0);
	glVertex3d(0.1, 0.1, 1.0);

	glVertex3d(0.9, 0.1, 0.0);
	glVertex3d(0.9, 0.9, 0.0);
	glVertex3d(0.9, 0.9, 1.0);
	glVertex3d(0.9, 0.1, 1.0);

	glVertex3d(0.9, 0.9, 0.0);
	glVertex3d(0.1, 0.9, 0.0);
	glVertex3d(0.1, 0.9, 1.0);
	glVertex3d(0.9, 0.9, 1.0);

	glVertex3d(0.1, 0.9, 0.0);
	glVertex3d(0.1, 0.1, 0.0);
	glVertex3d(0.1, 0.1, 1.0);
	glVertex3d(0.1, 0.9, 1.0);

	glVertex3d(0.1, 0.1, 1.0);
	glVertex3d(0.9, 0.1, 1.0);
	glVertex3d(0.9, 0.9, 1.0);
	glVertex3d(0.1, 0.9, 1.0);
	glEnd();
}

void SimpleStructure::draw()
{
	glLoadIdentity();
	glTranslated(mX, mY, 0.0);
	drawRect();
}
