#include "const.hpp"
#ifndef SPRING_H
#define SPRING_H


class Spring


{
private:
	Point location;
public:
	Spring(Point locate) { location = locate; }
	bool is_in_range(Point locat, int start_y);

	void draw(Window *win, int start_y);;
	

};
#endif