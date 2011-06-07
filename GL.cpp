#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <stdio.h>
#include "Map.hpp"
#include "GL.hpp"
#include "Vector.hpp"

Map* GL::mMap = 0;

GL::MouseButton GL::mMouseButton;
int GL::mMouseBuf[2];

int GL::mScreenX;
int GL::mScreenY;
Vector GL::mCameraDir;
Vector GL::mViewpoint;
double GL::mMagni;

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

void GL::init(int* argcp, char** argv,
	      const char* name, const char* init_data, 
	      const int screen_x, const int screen_y)
{
	/* データ準備 */
	// 基本となる正方形を初期化
	glNewList(PRI_SQUARE, GL_COMPILE);
	glBegin(GL_QUADS);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(1.0, 0.0, 0.0);
	glVertex3d(1.0, 1.0, 0.0);
	glVertex3d(0.0, 1.0, 0.0);
	glEnd();
	glEndList();

	mMap = new Map(name, init_data);

	mViewpoint.setComp(mMap->width() / 2.0, mMap->height() / 2.0, 0.0);
	mCameraDir.setComp(0.0, 1.0, 10.0);
	mCameraDir.normalize();
	mMagni = 10.0;

	mScreenX = screen_x;
	mScreenY = screen_y;

	/* OpenGL, GLUTの設定 */
	glutInitWindowSize(mScreenX, mScreenY);
	glutInit(argcp, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("My Sim");

	glutDisplayFunc(GL::display);
	glutReshapeFunc(GL::resize);
	glutMouseFunc(GL::mouse);
	glutMotionFunc(GL::motion);
	glutKeyboardFunc(GL::keyboard);

	glEnable(GL_DEPTH_TEST);

	glClearColor(1.0, 1.0, 1.0, 1.0);

}

void GL::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	glCallList(PRI_SQUARE);// ほんとはこれしたい
	mMap->draw();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0, 10.0, 0.0, 10.0, -2.0, 2.0);
	gluPerspective(100.0, 1.0, 0.0, 100.0);
	//gluLookAt(3.0, -4.0, 5.0, 3.0, 3.0, 0.0, 0.0, 0.0, 1.0);
	Vector t = mViewpoint + mCameraDir * mMagni;
	gluLookAt(t.x(), t.y(), t.z(), 
		  mViewpoint.x(), mViewpoint.y(), mViewpoint.z(), 
		  0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	glFlush();
}

void GL::resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0, 10.0, 0.0, 10.0, -2.0, 2.0);
	gluPerspective(100.0, 1.0, 0.0, 100.0);
	//gluLookAt(3.0, -4.0, 5.0, 3.0, 3.0, 0.0, 0.0, 0.0, 1.0);
	Vector t = mViewpoint + mCameraDir * mMagni;
	gluLookAt(t.x(), t.y(), t.z(), 
		  mViewpoint.x(), mViewpoint.y(), mViewpoint.z(), 
		  0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void GL::mouse(int button, int state, int x, int y)
{
	switch (state) {
	case GLUT_DOWN:
		mMouseBuf[0] = x;
		mMouseBuf[1] = y;

		switch (button) {
		case GLUT_LEFT_BUTTON:
			mMouseButton = MB_LEFT;
			break;
		case GLUT_MIDDLE_BUTTON:
			mMouseButton = MB_MIDDLE;
			break;
		case GLUT_RIGHT_BUTTON:
			mMouseButton = MB_RIGHT;
			break;
		default:
			mMouseButton = MB_NOPUSH;
			break;
		}
		break;
	case GLUT_UP:
		mMouseButton = MB_NOPUSH;
		break;
	default:
		break;
	}
}

void GL::motion(int x, int y)
{
	double drag_x = x - mMouseBuf[0];
	double drag_y = y - mMouseBuf[1];

	switch (mMouseButton) {
	case MB_LEFT: // 視点の移動
		
		break;
	case MB_MIDDLE: // ズーム
		break;
	case MB_RIGHT: // カメラの移動
		break;
	default:
		break;
	}
	mMouseBuf[0] = x;
	mMouseBuf[1] = y;
}

void GL::keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'u':
		mMagni -= 1;
		if (mMagni < 5) mMagni = 5;
		break;
	case 'd':
		mMagni += 1;
		if (mMagni > 100) mMagni = 100;
		break;
	default:
		/* nothing to do */
		break;
	}
	glutPostRedisplay();

}

void GL::mainLoop()
{
	glutMainLoop();
}
/*
void GL::idle()
{
}*/
