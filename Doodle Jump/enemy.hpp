#include "const.hpp"
#ifndef ENEMY_H
#define ENEMY_H


class Enemy


{
private:
	Point location;
public:
	Enemy(Point locat) : location(locat) {}
	bool is_in_range(Point locat, int start_y);
	

	void draw(Window *win, int start_y);
	
};




#endif