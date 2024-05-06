#include "sequence.hpp"


Point Sequence::improve_locattion(Point location)
	{
		Point result;
		result.x = location.x;
		result.y = SCREEN.height - location.y;
		return result;
	}
	void Sequence::reset_bplat()
	{
		for (int i = 0; i < platforms.size(); i++)
		{
			if (platforms[i]->get_plat_type() == "bplatform")
			{
				((Bplatform*)platforms[i])->reset();
			}
		}
	}
	int Sequence::enemy_attack(Point location)
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i].is_in_range(location, start_y))
				return END_OF_GAME;
		}
		return NOTHING;
	}
	int Sequence::see_spring(Point location)
	{
		for (int i = 0; i < springs.size(); i++)
		{
			if (springs[i].is_in_range(location, start_y))
				return ON_SPRING;
		}
		return NOTHING;

	}
	void Sequence::update_mplat()
	{
		for (int i = 0; i < platforms.size(); i++)
		{
			if (platforms[i]->get_plat_type() == "mplatform")
				platforms[i]->update_locat();
		}
	}
	int Sequence::is_on_platform(Point location)
	{
		for (int i = 0; i < platforms.size(); i++)
		{
			if (platforms[i]->is_in_range(location, start_y))
			{
				if (platforms[i]->get_plat_type() == "bplatform")
					return ON_BR_PLAT;

				return ON_PLATFORM;
			}
		}
		return NOTHING;
	}
	int Sequence::see_anything(Point location, int player_vy)
	{
		int result = enemy_attack(location);
		if (result)
			return result;
		if (player_vy <= 0)
		{
			result = is_on_platform(location);
			if (result)
			{
				return result;
			}
			
			result = see_spring(location);
			if (result)
				return result;
		}
		return NOTHING;
	}
	int Sequence::get_total_height()
	{
		return total_height;
	}

	bool Sequence::is_in_range(int score)
	{
		
		if (start <= score && (score <= end || end == -1))
			return true;

		return false;
	}


	void Sequence::realloc ()
	{
			for (int i = 0 ; i < platforms.size(); i++)
			{
				Point locat = platforms[i]->get_loc();
				string plat_type = platforms[i]->get_plat_type();
				
		Base_platform *temp;

		if (plat_type == "platform")
		{
			temp = new Platform(locat , plat_type);
			platforms[i] = temp;

		}

		if (plat_type == "mplatform")
		{
			temp = new Mplatform(locat , plat_type);
			platforms[i] = temp;


		}
		if (plat_type == "bplatform")
		{
			temp = new Bplatform(locat , plat_type);
			platforms[i] = temp;


		}
			}

	}




	void Sequence::sequence_init(Point location, string plat_type)
	{
		
		Point correct_locate = improve_locattion(location);

		Base_platform *temp;

		if (plat_type == "platform")
		{
			temp = new Platform(correct_locate , plat_type);
			platforms.push_back(temp);

		}

		if (plat_type == "mplatform")
		{
			temp = new Mplatform(correct_locate , plat_type);
			platforms.push_back(temp);


		}
		if (plat_type == "bplatform")
		{
			temp = new Bplatform(correct_locate , plat_type);
			platforms.push_back(temp);


		}
		if (plat_type == "spring")
		{
			springs.push_back(Spring(correct_locate));

		}

		if (plat_type == "enemy")
		{
			enemies.push_back(Enemy(correct_locate));


		}

	}
	void Sequence::draw(Window *win)
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i].draw(win, start_y);
		}
		for (int i = 0; i < springs.size(); i++)
		{
			springs[i].draw(win, start_y);
		}
		for (int i = 0; i < platforms.size(); i++)
		{
			platforms[i]->draw(win, start_y);
		}
	}