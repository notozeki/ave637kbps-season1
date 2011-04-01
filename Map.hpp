#ifndef MAP_HPP
#define MAP_HPP

#include "Array2D.hpp"

class MapEntry {
public:
	MapEntry();
	~MapEntry();
	void setParam(int x, int y, int height);
	int x() const;
	int y() const;
	int height() const;
private:
	int mX;
	int mY;
	int mHeight; // マイナスなら海
};

class Map {
public:
	Map(char* name, char* init_data);
	~Map();
	void draw() const;
	void heightcat_view(int level) const; // デバッグ用
private:
	Array2D<MapEntry> mCells;
	char* mName;
};

#endif // MAP_HPP
