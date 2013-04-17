#include <stdio.h>

#define _TO_STRING(value) #value
#define TO_STRING(value) _TO_STRING(value)

#define LINEINFO printf("["TO_STRING(__FILE__)":"TO_STRING(__LINE__)"] ");

#define PRINT(p_msg) printf(p_msg);
#define PRINTLN(p_msg) printf(p_msg"\n");
#define ECHO(p_msg) LINEINFO printf(p_msg"\n");

#define OK PRINTLN("OK"); testOks++;
#define FAIL PRINTLN("FAIL"); testFails++;

#define INT_EQUALS(p_name,p_var1,p_var2) LINEINFO PRINT("< "p_name" > ") \
		if(p_var1 == p_var2){ \
			OK\
		}else{\
			FAIL\
		}

#define INT_GREATER(p_name,p_var1,p_var2) LINEINFO PRINT("< "p_name" > ") \
	if(p_var1 > p_var2){ \
		OK\
	}else{\
		FAIL\
	}

#define BOOL_TRUE(p_name,p_var) LINEINFO PRINT("< "p_name" > ") \
	if(p_var == true){ \
		OK\
	}else{\
		FAIL\
	}

#define BOOL_FALSE(p_name,p_var) LINEINFO PRINT("< "p_name" > ") \
	if(p_var == false){ \
		OK\
	}else{\
		FAIL\
	}

#define END printf("Fails: %i Oks: %i\n",testFails,testOks);

#include "engine/world/Tile.h"

using namespace engine;

int testFails = 0;
int testOks   = 0;

int main(){
	PRINTLN("Starting tests");

	ECHO("Tile");

	world::Tile testTile;
	testTile.setType(world::TILE_TREE);

	BOOL_TRUE("Tree blocks",testTile.blocks);
	INT_GREATER("Tree has HP",testTile.hp,0);

	ECHO("Tests complete");
	END
	return 0;
}
