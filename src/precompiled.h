#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

#include "stdio.h"

#define _TO_STRING(value) #value
#define TO_STRING(value) _TO_STRING(value)

#include "engine/log/LogSystem.h"

/* Asserting helpers */
#define _ASSERT_RANGE(p_value,p_max) assert(p_value >= 0); assert(p_value < p_max);

/* Settings for world generation, size, etc */

#define ROOM_WIDTH 80
#define ROOM_HEIGHT 20 

#define WORLD_WIDTH 15
#define WORLD_HEIGHT 15
#define WORLD_DEPTH 10
#define WORLD_WATER_LEVEL 2

typedef std::string String;
