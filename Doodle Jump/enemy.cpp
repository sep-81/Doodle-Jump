

#include "enemy.hpp"


	bool Enemy::is_in_range(Point locat, int start_y)
	{
		if (locat.x + CHARACTER.width >= (location.x - (ENEMY.width / 2)) && locat.x <= location.x + ((ENEMY.width / 2)))
		{
			if (locat.y - CHARACTER.height <= (location.y + start_y) && locat.y >= location.y + start_y - ENEMY.height)
				return true;
		}
		return false;
	}

	void Enemy::draw(Window *win, int start_y)
	{
		win->draw_img("enemy.png", { Point(location.x - ENEMY.width / 2, location.y + start_y - ENEMY.height),Point(location.x + ENEMY.width / 2, location.y + start_y) });
	}