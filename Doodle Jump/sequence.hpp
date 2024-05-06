

#include "enemy.hpp"
#include "spring.hpp"
#include "platform.hpp"
#ifndef SEQUE_H
#define SEQUE_H
class Sequence
{
private:
	int start, end, total_height , number_of_entities;
	int start_y = 0;
	vector<Enemy>enemies;
	vector<Spring>springs;
	vector<Base_platform*>platforms;
public:
	
	Sequence(int start1, int end1, int total, int entities) : start(start1), end(end1), total_height(total),
		number_of_entities(entities) {}
	void init_start_from_y(int y)
	{
		start_y = y;
	}
	Point improve_locattion(Point location);
	
	void reset_bplat();
	
	int enemy_attack(Point location);
	
	int see_spring(Point location);
	

	void update_mplat();
	
	int is_on_platform(Point location);
	
	int see_anything(Point location, int player_vy);
	
	int get_total_height();
	
	bool is_in_range(int score);
	

	void realloc ();
	




	void sequence_init(Point location, string plat_type);
	
	void draw(Window *win);

};
#endif