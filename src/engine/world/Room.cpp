#include "precompiled.h"
#include "engine/world/Room.h"
#include "engine/math/random.h"
#include "engine/math/AABB.h"

namespace engine {
namespace world {

	Room::Room(){
		//Initialize empty room
		roomType = ROOM_TYPE_EMPTY;

		Tile tempTile;
		tempTile.setType(TILE_VOID);

		for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
			tiles[i] = tempTile;
			visual[i] = tempTile;
		}
	}

	Tile* Room::getTile(const vec2 pos){
		return getTile(pos.x,pos.y);
	}

	/**
	 * Returns direct access to the tile array, useful when raw access needed to the array.
	 */
	Tile* Room::getTileArray(){
		return tiles;
	}

	Tile* Room::getTile(const int x,const int y){
		ASSERT_TILE_XY(x,y);

		return &tiles[(x * ROOM_HEIGHT) + y];
	}

	void Room::setTile(const vec2 pos,const Tile tile){
		setTile(pos.x,pos.y,tile);
	}

	void Room::setTile(const int x,const int y,const Tile tile){
		ASSERT_TILE_XY(x,y);
		tiles[(x * ROOM_HEIGHT) + y] = tile;
	}

	Tile* Room::getVisual(const vec2 pos){
		return getTile(pos.x, pos.y);
	}

	Tile* Room::getVisual(const int x,const int y){
		ASSERT_TILE_XY(x,y);
		return &visual[(x * ROOM_HEIGHT) + y];
	}

	Tile* Room::getVisualArray(){
		return visual;
	}

	void Room::applyVisual(const vec2 pos){
		applyVisual(pos.x, pos.y);
	}

	void Room::applyVisual(const int x,const int y){
		ASSERT_TILE_XY(x,y);

		visual[(x * ROOM_HEIGHT) + y] = tiles[(x * ROOM_HEIGHT) + y];
	}

	/**
	 * Regenerate the room.
	 *
	 * Input: Reads roomType and builds on top of that.
	 */
	void Room::generate(){
		//Lets get the simple types out from the way first... air and water...

		Tile tempTile;

		switch(roomType){
		case ROOM_TYPE_EMPTY:
			//Loop trough all tiles and set them to void
			tempTile.setType(TILE_VOID);

			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				tiles[i] = tempTile;
			}

			break;
		case ROOM_TYPE_WATER:
			tempTile.setType(TILE_WATER);

			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				tiles[i] = tempTile;
			}

			break;
		case ROOM_TYPE_GROUND:
			tempTile.setType(TILE_GRASS);

			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				tiles[i] = tempTile;
			}

			for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
				if(randomRange(0,10) > 8){
					tiles[i] = Tile(TILE_TREE);
				}
			}

			break;
		case ROOM_TYPE_DUNGEON:
			generateDungeon();
			break;
		}
	}

	/**
	 * This room is generated to be a dungeon.
	 */
	void Room::generateDungeon() {
		std::vector<vec2> roomMarkers; //Markers to point out where are the rooms, used later on the generation.

		Tile tempTile(TILE_ROCK_FLOOR);

		//Fill with rocks
		for(int i = 0;i < (ROOM_WIDTH * ROOM_HEIGHT);++i){
			tiles[i] = Tile(TILE_SOLID_ROCK);
		}

		//Insert the random rooms
		int roomCount = randomRange(5,30);

		while(roomCount > 0){
			AABB room;
			//first size, then position, so we are sure it wont go over the limits
			room.size.x = randomRange(5,10);
			room.size.y = randomRange(4,10);

			room.pos.x = randomRange(1,(ROOM_WIDTH  - room.size.x - 1));  //One is to make sure the collision AABB doesn't go out of bounds.
			room.pos.y = randomRange(1,(ROOM_HEIGHT - room.size.y - 1)); 

			AABB roomCollision = room;

			//roomCollision is one larger than the room.
			--roomCollision.pos.x;
			--roomCollision.pos.y;
			++++roomCollision.size.x; //Double because --roomCollision moves it back
			++++roomCollision.size.y;

			//Only create room and tick the counter if the room is clear to be placed.
			if(AABBBlockCheck(roomCollision,false) == false){
				AABBSetTile(room,Tile(TILE_ROCK_FLOOR));
				/*
				roomMarkers.push_back(
					vec2( 
						randomRange(room.pos.x, (room.pos.x + room.size.x - 1)) ,
						randomRange(room.pos.y, (room.pos.y + room.size.x - 1))
					));

				*/

				roomMarkers.push_back(room.pos);
			}
			--roomCount;
		}

		//Paths between the rooms
		int pathCount = randomRange(25,50);
		while (pathCount > 0) {
			//TODO: Add change of disconnected room.
			//Start from a marker, create a path until hits something

			vec2 pos = vec2(randomRange(0,ROOM_WIDTH - 1), randomRange(0,ROOM_HEIGHT -1));
			vec2 dir;
			dir.randomNSWE();
			int timer = -1;
			int miss = 0;

			for(;;){
				--timer;
				if(timer < 0){
					dir.randomNSWE();
					timer = randomRange(5,10);
				}

				if(miss > 5){
					//5 misses, stop pathing!
					break;
				}

				pos += dir;

				if(pos.x < 0 || pos.x > (ROOM_WIDTH - 1)|| pos.y < 0 || pos.y > (ROOM_HEIGHT - 1)){
					dir.randomNSWE();
					++miss;
					continue; //Hit a wall!
				}

				if(getTile(pos)->blocks == false){
					break; //Found non-blocking place, not going there!
				}

				setTile(pos,Tile(TILE_ROCK_FLOOR));
			}

			--pathCount;
		}

		//Solid walls around the room to make debugging easier

		//TODO: these are not working as expected.
		AABB line;
		line.pos.x = 0;
		line.pos.y = 0;
		line.size.y = 1;
		line.size.x = ROOM_WIDTH;
		AABBSetTile(line,Tile(TILE_SOLID_ROCK));

		line.pos.x = 0;
		line.pos.y = 0;
		line.size.y = ROOM_HEIGHT;
		line.size.x = 1;
		AABBSetTile(line,Tile(TILE_SOLID_ROCK));

		line.pos.x = 0;
		line.pos.y = ROOM_HEIGHT-1;
		line.size.y = 1;
		line.size.x = ROOM_WIDTH;
		AABBSetTile(line,Tile(TILE_SOLID_ROCK));

		line.pos.x = ROOM_WIDTH-1;
		line.pos.y = 0;
		line.size.y = ROOM_HEIGHT;
		line.size.x = 1;
		AABBSetTile(line,Tile(TILE_SOLID_ROCK));
	}



	/**
	 * Prints the room layout to the cmd. Used for debugging.
	 */
	void Room::printLayout(){
		for(int y = 0;y < ROOM_HEIGHT;++y){
			for(int x = 0;x < ROOM_WIDTH;++x){
				printf("%c",getTile(x,y)->visual);
			}
			printf("\n");
		}
	}

	/**
	 *
	 * Checks if the block type is found.
	 */
	bool Room::AABBBlockCheck(AABB box,bool type){
		for(int x = box.pos.x; x < ( box.pos.x + box.size.x ); ++x){
			for(int y = box.pos.y; y < ( box.pos.y + box.size.y ); ++y){
				if (getTile(x,y)->blocks == type){
					return true;
				}
			}
		}

		return false;
	}

	/**
	 * Sets the AABB given to certain tile type.
	 */
	void Room::AABBSetTile(AABB area,Tile tile){
		for(int x = area.pos.x; x < ( area.pos.x + area.size.x ); ++x){
			for(int y = area.pos.y; y < ( area.pos.y + area.size.y ); ++y){
				setTile(x,y,tile);
			}
		}
	}

	/**
	 * Checks los between two tiles
	 *
	 * Returns true if line is possible, false if not
	 */
	bool Room::lineOfSight(vec2 start, vec2 end) {
		ASSERT_TILE_XY(start.x,start.y);
		ASSERT_TILE_XY(end.x,end.y);

		float xMul;
		float yMul;
		int len;

		int dx = end.x - start.x;
		int dy = end.y - start.y;

		if(start == end){
			return true;
		}

		//calculate ray multiplier stuffj
		if(abs(dx) > abs(dy)) {
			xMul = 1.0f;
			yMul = dy/((float)dx);
			len  = dx;
		}else{
			xMul = dx/((float)dy);
			yMul = 1.0f;
			len  = dy;
		}

		//raycast!
		for(int i = 0; i != len; len < 0 ? --i : ++i){
			vec2 pos;
			pos.x = start.x + ((dx < 0) ? ceil(i * xMul) : i * xMul);
			pos.y = start.y + ((dy < 0) ? ceil(i * yMul) : i * yMul);

			if(getTile(pos)->blocks){
				return false; //Hit a block on the way!
			}
		}

		//ray didn't hit
		return true;
	}

}
}
