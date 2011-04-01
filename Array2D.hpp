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
