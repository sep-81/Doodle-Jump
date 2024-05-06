
  
 #include "game.hpp"


	bool Game:: out_of_screen()
	{
		Point location = player.get_loc();
		
		if (location.y - CHARACTER.height >= SCREEN.height)
			return true;
		return false;

	}
	void Game:: see_anything()
	{
		if (out_of_screen())
		{
			status = END_OF_GAME;
		
			return;
		}
		for (int i = 0; i < sequences.size(); i++)
		{
			status = sequences[i].see_anything(player.get_loc(), player.get_vy());
			if (status)
				break;
		}
		int vy = player.get_vy();
		if (status == ON_PLATFORM)
			vy = SPEED_Y;
		if (status == ON_SPRING)
			vy = SPRING_SPEED;
		if (vy != player.get_vy())
			player.is_it_jump(true);
		else
			player.is_it_jump(false);
		player.init_vy(vy);

	}


	void Game:: sque_start_y()
	{
		int height = start_y;
		for (int i = 0; i < sequences.size(); i++)
		{
			sequences[i].init_start_from_y(height);
			height -= sequences[i].get_total_height();


		}

	}
void Game:: update_mplat()
	{
		for (int i = 0; i < sequences.size(); i++)
		{
			sequences[i].update_mplat();
		}
	}
	
	void Game:: choose_sequence()
	{
		
		if(sequences.size() >=1)
		{
			if (sequences[0].get_total_height() <= start_y)
			{
				start_y -= sequences[0].get_total_height();
		
				sequences.erase(sequences.begin());
						
			}

						
	    }
	    if (total_height >= SCREEN.height)
		{
			
			return;
		}
		vector<int>possible_sequence;
		for (int i = 0; i < main_sequences.size(); i++)
		{
			if (main_sequences[i].is_in_range(player.get_score()))
			{
				possible_sequence.push_back(i);


				
			}
		}
		srand(time(NULL));

		
			for (int i = sequences.size(); total_height < SCREEN.height; i++)
			{
				int size = possible_sequence.size();

				int wich_index = rand() % size;
				int wich_sequ = possible_sequence[wich_index];
				Sequence temp = main_sequences[wich_sequ];
				temp.realloc();
				sequences.push_back(temp);
				total_height += sequences[i].get_total_height();


			


				
	
			}

	}
	void Game::update_my_screen()
	{

		choose_sequence();
		int previous_y = player.get_loc().y;
		int character_y = previous_y - player.calcu_distance_y();

		
		if (character_y >= SCREEN.height / 2)
		{
			player.update_y(character_y);
		}
		else 
		{
			player.update_y(SCREEN.height / 2);
			int move_up_screen = (SCREEN.height / 2) - character_y;
			start_y += move_up_screen;
			total_height -= move_up_screen;
		


		}
		
		update_mplat();
		sque_start_y();
		

	}

  void Game::get_input(int argc , char* argv[])
	{

		if (argc != 2)
		{
			cout << "please enter filename \n";
			abort();
		}
		ifstream fin(argv[1]);
		if (!fin)
			abort();
		
		fin >> number_of_sequence;
		
		for (int i = 0; i < number_of_sequence; i++)
		{
			int start1, end1, total, entities;
			fin >> start1 >> end1 >> total >> entities;
			main_sequences.push_back(Sequence(start1, end1, total, entities));
			
			for (int j = 0; j < entities; j++)
			{
				
				int x, y;
				string type;
				fin >> x >> y >> type;

				main_sequences[i].sequence_init(Point(x, y), type);
			}
		}
		fin.close();
		
		
	}

	void Game::draw(Window *win)
	{
		win->clear();

		win->draw_img("background.png");
		win->update_screen();
		for (int i = 0; i < sequences.size(); i++)
		{
			sequences[i].draw(win);
		

		}
		player.draw(win);
		win->update_screen();

	}
	void Game:: update(Window* win)
	{
		while (win->has_pending_event())
		{
			Event event = win->poll_for_event();
			Event::EventType type = event.get_type();

			if (type == Event::KEY_PRESS)
			{
				char passed_char = event.get_pressed_key();
				if (passed_char == 'a')
				{
					player.init_vx(-SPEED_X);
				}
				if (passed_char == 'd')
				{
					player.init_vx(SPEED_X);
				}
			}

			if (type == Event::KEY_RELEASE)
			{
				player.init_vx(RELEASED);
			}

			if (type == Event::EventType::QUIT)
			{
				exit(0);
			}

		}
		player.update_x();
		update_my_screen();
		see_anything();
	}
	bool Game:: is_end ()
	{
		if (status == END_OF_GAME)
			return true;
		return false;
	}
	void Game:: print_result (Window *win)
	{
		win->clear();
		string result = "END OF THE GAME \n your score : ";
		result += to_string(player.get_score());
		win->show_text(result , Point(100,100) , RED , "FreeSans-LrmZ.ttf");
		win->update_screen();
		while(true)
		{
			if (win->has_pending_event())
			{
				Event event = win->poll_for_event();
			Event::EventType type = event.get_type();
				if (type == Event::KEY_PRESS || type == Event::QUIT)
					break;
			}
		}

	}


