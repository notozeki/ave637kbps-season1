#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

class Structure {
public:
	virtual void draw() = 0;
	void setLocate(int x, int y);
protected:
	int mX;
	int mY;
};

#endif // STRUCTURE_HPP
