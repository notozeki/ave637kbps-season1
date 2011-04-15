#ifndef GL_HPP
#define GL_HPP

class Map;

class GL {
public:
	static void init(const char* name, const char* init_data);
	static void display();
	static void resize(int w, int h);
	static void drawMapCell(int x, int y, int z);
private:
	enum {
		PRI_SQUARE,
	};
	static Map* mMap;
};

#endif // GL_HPP
