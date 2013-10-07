#ifndef TERMRENDER
#define ENGINE_INPUT_TERM_TERMINPUT_H
#endif

#ifndef ENGINE_INPUT_TERM_TERMINPUT_H
#define ENGINE_INPUT_TERM_TERMINPUT_H

#include "engine/input/InputSystem.h"
#include "engine/scene/SceneSystem.h"

#define TERMINPUT

#include <termbox.h>

namespace engine {
namespace input {
namespace term {

	class TermInput : public InputSystem {
		private:
			scene::SceneSystem *scene;

		public:
			TermInput(scene::SceneSystem *scene)
				:scene(scene)
			{}

			bool init() {
				return true;
			}

			void uninit() {}

			void update();
		private:
			bool handleKey(tb_event *event);
	};

}
}
}

#endif
