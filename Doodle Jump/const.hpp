#ifndef CONST_H
#define CONST_H

#include "rsdl.hpp"
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;
const int RELEASED = 0;
const int SPEED_Y = 30;
const int SPEED_X = 15;
const int RIGHT = true;
const int LEFT = false;
const int SPRING_SPEED = 50;
const int GRAVITY = 1;
const int MOVING_PLATFORM_SPEED = 10;
const int ON_PLATFORM = -1;
const int ON_SPRING = -2;
const int END_OF_GAME = -3;
const int ON_BR_PLAT = -4;
const int NOTHING = 0;
const int NUMBERS_OF_FRAMES = 7;

struct Size
{
	int width;
	int height;
};
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 1024;
const Size SCREEN = { SCREEN_WIDTH , SCREEN_HEIGHT };

const int ENEMY_WIDTH = 136;
const int ENEMY_HEIGHT = 184;
const Size ENEMY = Size{ ENEMY_WIDTH , ENEMY_HEIGHT };
const int PLATFORM_WIDTH = 120;
const int PLATFORM_HEIGHT = 36;
const Size PLATFORM = { PLATFORM_WIDTH , PLATFORM_HEIGHT };

const int SPRING_WIDTH = 56;
const int SPRING_HEIGHT = 46;
const Size SPRING = { SPRING_WIDTH , SPRING_HEIGHT };

const int CHARACTER_WIDTH = 124;
const int CHARACTER_HEIGHT = 120;
const Size CHARACTER = { CHARACTER_WIDTH , CHARACTER_HEIGHT };

struct Velocity
{
	Velocity(int x, int y) : vx(x), vy(y) {}
	int vx;
	int vy;
};


#endif