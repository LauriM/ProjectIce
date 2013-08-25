#ifndef ENGINE_RENDER_COLOR_H
#define ENGINE_RENDER_COLOR_H

namespace engine {
namespace render {

	/**
	 * All the colors that are supported by the game.
	 *
	 * Rendering system should convert these to its own color system.
	 */
	typedef enum colorE {
		C_WHITE = 0,
		C_BLACK,
		C_RED,
		C_GREEN,
		C_BLUE,
	} Color ;

}
}

#endif