
#include "spring.hpp"

 bool Spring:: is_in_range(Point locat, int start_y)
	{
		if (locat.x + CHARACTER.width >= (location.x - (SPRING.width / 2)) && locat.x <= location.x + ((SPRING.width / 2)))
		{
			if (locat.y >= location.y + start_y - SPRING.height && locat.y <= location.y + start_y)
				return true;
		}
		return false;

	}

 void Spring:: draw(Window *win, int start_y)
	{
		win->draw_img("spring.png", { Point(location.x - SPRING.width / 2, location.y + start_y - SPRING.height),Point(location.x + SPRING.width / 2, location.y + start_y) });
	}
