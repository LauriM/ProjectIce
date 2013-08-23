
#ifndef __INPUT_MAPPING_H__
#define __INPUT_MAPPING_H__

namespace engine {
namespace input {

	class InputMapping {
	private:
		int _moveNorth;
		int _moveSouth;
		int _moveEast;
		int _moveWest;
		int _suicide;
		InputMapping() {
			// TODO I don't know what keys go with what
			_moveNorth = 106;
			_moveSouth = 107;
			_moveEast = 104;
			_moveWest = 108;
			_suicide = 27;
		}
		static InputMapping * _instance;
	public:

		static InputMapping * getInstance() {
			if ( !_instance )
				_instance = new InputMapping();
			return _instance;
		}

		int getMoveNorth() {
			return _moveNorth;
		}

		int getMoveSouth() {
			return _moveSouth;
		}

		int getMoveEast() {
			return _moveEast;
		}

		int getMoveWest() {
			return _moveWest;
		}

		int getSuicide() {
			return _suicide;
		}

	};

}
}

#endif
