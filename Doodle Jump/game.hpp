#include "sequence.hpp"
#include "doodle.hpp"
#ifndef GAME_H
#define GAME_H


class Game
{
private:

	int total_height = 0;
	int number_of_sequence;
	int start_y = 0;
	int status = 0;
	vector<Sequence>main_sequences;
	vector<Sequence>sequences;
	
	bool repeated;
	Doodle player;
public:
	bool out_of_screen();
	
	void see_anything();
	


	void sque_start_y();
	
	void update_mplat();
	
	
	void choose_sequence();
	
	void update_my_screen();
	

    void get_input(int argc , char* argv[]);
	
	

	void draw(Window *win);
	
	void update(Window* win);
	
	bool is_end ();
	
	void print_result (Window *win);
	

};
#endif