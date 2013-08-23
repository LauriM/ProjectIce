#ifndef ENGINE_RENDER_RENDERSYSTEM_H
#define ENGINE_RENDER_RENDERSYSTEM_H

#include "engine/scene/SceneSystem.h"
#include "engine/UI/UISystem.h"

#include "engine/math/vec3.h"

namespace engine {
namespace render {

	/**
	 * RenderSystem is a parent class for the actual rendering systems.
	 *
	 * RenderSystem gets pointers to the sceneSystem and uiSystem and will build the visuals from that.
	 */
	class RenderSystem : public EngineSystem {
	protected:
		vec3 cameraPos;
	public:
		~RenderSystem() {};

		vec3 getCameraPos(){
			return cameraPos;
		}

		void setCameraPos(vec3 pos){
			cameraPos = pos;
		}
	};

}
}

#endif
