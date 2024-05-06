#include "const.hpp"
#ifndef DOODLE_H
#define DOODLE_H
class Doodle

{
private:
	
	bool is_jump = false;
	int how_much_be_jumped = 0;
	bool left_or_right = RIGHT;
	Velocity speed;
	Point location;
	int score = 0;

public:
	Doodle()
		: speed(Velocity(0 , SPEED_Y)), location(Point(SCREEN.width / 2, SCREEN.height / 2)) { }
	Point get_loc()
	{
		return location;
	}
	void init_vx(int vx);
	
	void init_vy(int vy);
	
	void is_it_jump(bool direc);
	
	void update_y(int y);
	
	int calcu_distance_y();
	
	int get_vy();
	
	void update_x();

	int get_score();
	
	void draw(Window *win);
	

};
#endif