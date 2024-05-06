
#include "platform.hpp"

	 bool Base_platform::is_in_range(Point locat, int start_y)
	{
		if (locat.x + CHARACTER.width >= (location.x - (PLATFORM.width / 2)) && locat.x <= location.x + ((PLATFORM.width / 2)))
		{
			if (locat.y >= location.y + start_y - PLATFORM.height && locat.y <= location.y + start_y)
				return true;
		}
		return false;
	}
	
	
	
	


	void Platform:: draw(Window *win, int start_y)
	{
		win->draw_img("platform.png", { Point(location.x - PLATFORM.width / 2, location.y + start_y - PLATFORM.height),Point(location.x + PLATFORM.width / 2, location.y + start_y) });
	}




     void Mplatform:: update_locat()
	{
		location.x += speed_x;
		if (location.x >= SCREEN.width)
		{
			speed_x = -speed_x;
			location.x = SCREEN.width - (location.x - SCREEN.width);
		}
		if (location.x <= 0)
		{
			speed_x = -speed_x;
			location.x = -location.x;
		}
	}
	void Mplatform:: draw(Window *win, int start_y)
	{
		win->draw_img("mplatform.png", { Point(location.x - PLATFORM.width / 2, location.y + start_y - PLATFORM.height),Point(location.x + PLATFORM.width / 2, location.y + start_y) });
	}





	bool Bplatform:: is_in_range(Point locat, int start_y)
	{
		if (Base_platform::is_in_range(locat, start_y))
		{
			is_it_hit = true;
			return true;
		}
		return false;
	}
	void Bplatform:: draw(Window *win, int start_y)
	{
		if (stage >= 4)
		{ 
			is_it_hit = false;
			return;
		}
		if (stage == 0)
			win->draw_img("bplatform.png", { Point(location.x - PLATFORM.width / 2,location.y + start_y - PLATFORM.height),Point(location.x + PLATFORM.width / 2, location.y + start_y) });
		if (stage == 1)
			win->draw_img("bplatform1.png", { Point(location.x - PLATFORM.width / 2,location.y + start_y - PLATFORM.height),Point(location.x + PLATFORM.width / 2, location.y + start_y) });
		if (stage == 2)
			win->draw_img("bplatform2.png", { Point(location.x - PLATFORM.width / 2,location.y + start_y - PLATFORM.height),Point(location.x + PLATFORM.width / 2, location.y + start_y) });
		if (stage == 3)
			win->draw_img("bplatform3.png", { Point(location.x - PLATFORM.width / 2,location.y + start_y - PLATFORM.height),Point(location.x + PLATFORM.width / 2, location.y + start_y) });
		if (is_it_hit)
			stage++;
	}
	void Bplatform:: reset()
	{
		stage = 0;
		is_it_hit = false;
	}