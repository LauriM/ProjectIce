#include "scppt.h"
#include "engine/world/Tile.h"

using namespace engine;

int testFails = 0;
int testOks   = 0;

int main(){
	SCPPT_START;

	PRINTLN("-> Tile");

	world::Tile testTile;
	testTile.setType(world::TILE_TREE);

	SCPPT_COMPARE("Tree blocks movement",testTile.blocks,==,true);
	SCPPT_COMPARE("Tree has HP",testTile.hp,>,0);

	PRINTLN("Tests complete");

	SCPPT_END;

	return 0;
}
