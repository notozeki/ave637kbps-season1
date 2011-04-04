#ifndef ARRAY2D_HPP
#define ARRAY2D_HPP

#define DEL(p) do {if (p) {delete p; p = 0;}} while(0)
#define DELARY(p) do {if(p) {delete[] p; p = 0;}} while(0)

template <class T>
class Array2D {
public:
	Array2D() : mArray(0), mWidth(0), mHeight(0) {}
	Array2D(int width, int height) : mArray(0) {setSize(width, height);}
	void setSize(int width, int height)
	{
		DELARY(mArray);
		mWidth = width;
		mHeight = height;
		mArray = new T[width * height];
	}
	~Array2D() {DELARY(mArray);}
	T& operator()(int x, int y) {return mArray[mWidth * y + x];}
	const T& operator()(int x, int y) const {return mArray[mWidth * y + x];}
	int width() const {return mWidth;}
	int height() const {return mHeight;}
private:
	T* mArray;
	int mWidth;
	int mHeight;
};

#endif // ARRAY2D_HPP
