
#ifndef ENGINE_ACTOR_ACTORBODYLIMB_H
#define ENGINE_ACTOR_ACTORBODYLIMB_H

#include "precompiled.h"

#include <vector>

namespace engine {
namespace actor {
	
	class ActorBodyLimb {
	private:
		void attachToParent( ActorBodyLimb * parent );
	protected:
		String name;
		ActorBodyLimb * parent;
		std::vector<ActorBodyLimb*> children;
	public:
		/** The body part has come into existance!
		 * @param parent the body part of which this body part is attached too (can be NULL as an indicator that it's the head)
	  	 */
		ActorBodyLimb( ActorBodyLimb * parent, String name );

		/** The body part was severed and so are all of the children underneath it. 
		 */
		~ActorBodyLimb( );

		/** Used for display purposes, you can give the limb a name like hand, feet, etc.
		 * @return the name of the limb
		 */
		String getName();

		/** Returns the reference to the limb of which this limb is attached too
		 * @return the pointer to the top limb
		 */
		ActorBodyLimb * getParent();

		/** Returns a list of children in which this limb is directly attached too (1 level deep)
		 * @return the pointer to the top limb
		 */		
		std::vector<ActorBodyLimb*> getDirectChildren();

		/** Returns the list of ALL of the children which are underneath this limb (for example head -> body -> arm -> hand)
		 * @return the pointer to the top limb
		 */
		std::vector<ActorBodyLimb*> getAllChildren();
	};

}
}

#endif
