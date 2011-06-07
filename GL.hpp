#ifndef GL_HPP
#define GL_HPP

#include "Vector.hpp"
class Map;

class GL {
public:
	static void init(int* argcp, char** argv,
			 const char* name, const char* init_data, 
			 const int screen_x, const int screen_y);
	static void display();
	static void resize(int w, int h);
	static void mouse(int button, int state, int x, int y);
	static void motion(int x, int y);
	static void keyboard(unsigned char key, int x, int y);
	static void drawMapCell(int x, int y, int z);
	static void mainLoop();
private:
	enum {
		PRI_SQUARE,
	};
	typedef enum {
		MB_NOPUSH = 0,
		MB_LEFT,
		MB_RIGHT,
		MB_MIDDLE,
	} MouseButton;
	static Map* mMap;

	static MouseButton mMouseButton;
	static int mMouseBuf[2];

	static int mScreenX;
	static int mScreenY;
	static Vector mCameraDir;
	static Vector mViewpoint;
	static double mMagni;
};

#endif // GL_HPP
