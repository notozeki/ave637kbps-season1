#include <stdio.h>
#include <string.h>
#include "Map.hpp"
#include "Array2D.hpp"

Map::Map(const char* name, const char* init_data)
{
	// マップネーム初期化
	mName = strdup(name);

	// セルのサイズ測定と初期化
	int x = 0;
	int max_x = 0;
	int y = 0;
	for (int i = 0; init_data[i] != '\0'; i++) {
		switch (init_data[i]) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case 's':
			x++;
			break;

		case '\n':
			y++;
			max_x = (x > max_x)? x : max_x;
			x = 0;
			break;

		default:
			/* do nothing */;
			break;
		}
	}
	mCells.setSize(max_x, y);

	// マップの各エントリを初期化
	x = 0;
	y = 0;
	for (int i = 0; init_data[i] != '\0'; i++) {
		if ('0' <= init_data[i] && init_data[i] <= '9') {
			mCells(x, y).setParam(x, y, init_data[i] - '0');
			x++;
		}
		else if (init_data[i] == 's') {
			mCells(x, y).setParam(x, y, -1);
			x++;
		}
		else if (init_data[i] == '\n') {
			y++;
			x = 0;
		}
		else {
			/* do nothing */;
		}
	}
}

Map::~Map()
{
}

void Map::draw() const
{
	/* not implemented */
}

void Map::heightcat_view(int level) const
{
	int width = mCells.width();
	int height = mCells.height();
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int c = mCells(x, y).height();
			if (c < 0) {
				printf("~");
			}
			else if (c <= level) {
				printf("_");
			}
			else {
				printf(".");
			}
		}
		printf("\n");
	}
}

MapEntry::MapEntry()
{
}

MapEntry::~MapEntry()
{
}

void MapEntry::setParam(int x, int y, int height)
{
	mX = x;
	mY = y;
	mHeight = height;
}

int MapEntry::x() const
{
	return mX;
}

int MapEntry::y() const
{
	return mY;
}

int MapEntry::height() const
{
	return mHeight;
}
