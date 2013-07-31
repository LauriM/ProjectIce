#include "Player.h"

namespace engine {
namespace player {

void Player::init(){
	position.x = 1;
	position.y = 1;

	location.x = 1;
	location.y = 1;
	location.z = 1;

	hp    = PLAYER_DEFAULT_MAXHP;
	maxHp = PLAYER_DEFAULT_MAXHP;

	name = "Benedict Arnold";

	LOG_INFO("Player init done");
}

void Player::update(){
	/* tick player */
}

String Player::getName() {
	return name;
}

}
}
