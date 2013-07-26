#ifndef ENGINE_UI_CONTAINERBASE_H
#define ENGINE_UI_CONTAINERBASE_H

#include "engine/math/AABB.h"

namespace engine {
namespace UI {

	/**
	 * Base class for containers that are inside the window
	 */
	class ContainerBase {
		protected:
			bool closed; /* is the container stopped? if so, kill the window */
			bool interaction;

		public:
			virtual ~ContainerBase() {};

			virtual void init()   = 0;
			virtual void uninit() = 0;

			/**
			 * Render the window, only draw to these bounds.
			 * Function drawToBounds(bounds,pos,char); is used
			 */
			virtual void render(AABB bounds) = 0;

			/**
			 * Passes the input controls to the container
			 */
			virtual void handleInput(int key) = 0;

			/* getters / setters */

			bool getInteraction(){
				return interaction;
			}

			bool getClosed(){
				return closed;
			}
	};

}
}

#endif
