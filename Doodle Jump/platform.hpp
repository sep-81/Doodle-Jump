
#include "const.hpp"
#ifndef PLATFORM_H
#define PLATFORM_H

class Base_platform
{
protected:
	Point location;
	string plat_type;
public:
	string get_plat_type() { return plat_type; }
	Point get_loc()
	{
		return location;
	}
	virtual bool is_in_range(Point locat, int start_y);
	
	virtual void update_locat() {}
	
	
	virtual void draw(Window* win, int start_y) = 0;

};


class Platform : public Base_platform
{
private:

public:
	
	Platform(Point locate, string type) { location = locate, plat_type = type; }
	void draw(Window *win, int start_y);
	
};


class Mplatform : public Base_platform


{
private:
	int speed_x = MOVING_PLATFORM_SPEED;
public:
	
	Mplatform(Point locate, string type) { location = locate, plat_type = type; }
	void update_locat();
	
	void draw(Window *win, int start_y);
	

};


class Bplatform : public Base_platform


{
private:
	bool is_it_hit = false;
	int stage = 0;
public:
	
	Bplatform(Point locate, string type) { location = locate, plat_type = type; }
	bool is_in_range(Point locat, int start_y);

	void draw(Window *win, int start_y);
	
	void reset();
	

};

#endif
