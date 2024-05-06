	
#include "game.hpp"


int main(int argc , char* argv[])
{
	Window win(640, 1024);
	Game game;
	game.get_input(argc , argv);
	
	while (1)
	{
		if(game.is_end())
		{
			
			break;
		}
		game.update(&win);
		game.draw(&win);
		delay(20);
	}
	game.print_result(&win);


}