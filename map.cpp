#define DELETE(p) do {if (p) {delete p; p = 0;}} while(0)

template <class T>
class Array2D {
public:
	Array2D() : mArray(0), mWidth(0), mHeight(0) {}
	Array2D(int width, int height) {setSize(width, height);}
	void setSize(int width, int height)
	{
		DELETE(mArray);
		mWidth = width;
		mHeight = height;
		mArray = new T[width * height];
	}
	~Array2D() {DELETE(mArray);}
	T& operator()(int x, int y) {return mArray[mWidth * y + x];}
	int width() const {return mWidth;}
	int height() const {return mHeight;}
private:
	T* mArray;
	int mWidth;
	int mHeight;
};

class Map {
public:
	Map();
	~Map();
	void draw() const;
private:
	Array2D<MapEntry> mCells;
};

class MapEntry {
public:
	MapEntry(x, y, height);
	~MapEntry();
	void draw() const;
	int x() const;
	int y() const;
private:
	int mX;
	int mY;
	int mHeight; // マイナスなら海
};

Map::Map(char* map_data)
{
	// セルのサイズ測定と初期化
	int x = 0;
	int max_x = 0;
	int y = 0;
	for (int i = 0; map_data[i] != '\0'; i++) {
		switch (map_data[i]) {
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
			// do nothing
			break;
		}
	}
	mCells.setSize(max_x, y);

for (int i = 0; map_data[i] != '\0'; i++) {
		switch (map_data[i]) {
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
			// do nothing
			break;
		}
	}
}
