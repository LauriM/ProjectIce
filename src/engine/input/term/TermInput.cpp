#include "precompiled.h"

#include "engine/input/term/TermInput.h"

#ifdef TERMRENDER

namespace engine {
namespace input {
namespace term {

	void TermInput::update() {
		tb_event *event;

		for(;;) {
			tb_poll_event(event);

			if(handleKey(event)){
				return;
			}
		}
	}

	/**
	 * Returns true if a valid key was pressed
	 */
	bool TermInput::handleKey(tb_event *event) {
		if(event->type != TB_EVENT_KEY){
			return false;
		}

		//Arrow-keys
		if(event->key == TB_KEY_ARROW_UP){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(0,-1));
			return true;
		}

		if(event->key == TB_KEY_ARROW_DOWN){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(0,1));
			return true;
		}

		if(event->key == TB_KEY_ARROW_LEFT){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(-1,0));
			return true;
		}

		if(event->key == TB_KEY_ARROW_RIGHT){
			scene->getActorManager()->moveActorRel(scene->getPlayerActor(),vec2(1,0));
			return true;
		}

		if(event->key == TB_KEY_CTRL_C){
			tb_shutdown();
			exit(0);
		}

		return true;
	}

}
}
}

#endif
