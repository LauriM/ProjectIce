
#ifndef __INV_OWNER_UNION_H__
#define __INV_OWNER_UNION_H__

#include "engine/actor/ActorBase.h"
#include "engine/world/Room.h"

namespace engine {
namespace inventory {

	enum EOwnerType {
		ROOM,
		ACTOR
	};

	struct UInventoryType {
		EOwnerType ownerType;
		union {
			actor::ActorBase * actorOwner;
			world::Room * roomOwner;			
		};
	};

}
}

#endif