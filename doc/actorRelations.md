# Actor related classes

* ActorBase - The actor itself
* ActorManager - Handles movement
* ActorSystem - Stores actors
* AISystem - Handles AI

 --> ActorContainer

ActorBase

ActorBase <- ActorSystem <- ActorManager
                   |        ^--- AISystem
                   ---------------|
