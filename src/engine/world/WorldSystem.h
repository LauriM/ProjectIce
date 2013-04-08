#ifndef ENGINE_WORLD_WORLDSYSTEM_H
#define ENGINE_WORLD_WORLDSYSTEM_H

#include "precompiled.h"

#include "engine/EngineSystem.h"
#include "engine/world/Room.h"
#include "engine/math/vec3.h"

namespace engine {
namespace world {

	class WorldSystem : public engine::EngineSystem {
	private:
		Room rooms[WORLD_WIDTH][WORLD_HEIGHT][WORLD_DEPTH];
		//TODO: create some ASSERTS to make sure the array is accessed correctly (2013-04-02)
	public:
		WorldSystem();

		virtual bool init();
		virtual void uninit();
		virtual void update();

		void generate();

		Room* getRoom(int x,int y,int z);
		Room* getRoom(vec3 pos);

		void loadFromFile(String filename);
		void saveToFile(String filename);
	};

}
}

#endif
