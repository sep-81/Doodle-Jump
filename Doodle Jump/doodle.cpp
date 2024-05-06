

#include "doodle.hpp"

void  Doodle::init_vx(int vx)
	{
		if (vx > 0)
			left_or_right = RIGHT;
		if (vx < 0)
			left_or_right = LEFT;
		speed.vx = vx;
	}
void Doodle::init_vy(int vy)
	{
		
		speed.vy = vy;
	}
	void Doodle::is_it_jump(bool direc)
	{
		is_jump = direc;
		if (is_jump)
		how_much_be_jumped = NUMBERS_OF_FRAMES;
	    else
	    	how_much_be_jumped = 0 ;
	}
void Doodle::update_y(int y)
	{
		location.y = y;
	}
int Doodle::calcu_distance_y()
	{
		int new_vy = speed.vy - GRAVITY;
		int move_in_y = (new_vy + speed.vy) / 2;
		speed.vy = new_vy;
		if (move_in_y > 0)
			score += move_in_y;
		return move_in_y;
	}
int Doodle::get_vy()
	{
		return speed.vy;
	}
void Doodle::update_x()
	{
		location.x += speed.vx;
		if (location.x >= SCREEN.width)
		{
			location.x = -CHARACTER.width + (location.x - SCREEN.width);
		}
		if (location.x + CHARACTER.width <= 0)
		{
			location.x = SCREEN_WIDTH + location.x + CHARACTER.width;
		}
	}
int Doodle::get_score()
	{
		return score;
	}

void Doodle::draw(Window *win)
	{
		
		if (is_jump)
		{
			win->draw_img("left_jumping1.png", { Point(location.x , location.y - CHARACTER.height),Point(location.x + CHARACTER.width, location.y) }, NULL_RECT, 0,left_or_right );
			--how_much_be_jumped;
			if (how_much_be_jumped == 0)
				is_jump = false;
		}
		else
			win->draw_img("left1.png", { Point(location.x , location.y - CHARACTER.height),Point(location.x + CHARACTER.width, location.y)}, NULL_RECT, 0,left_or_right );
		
	}