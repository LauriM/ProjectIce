TODO
====

##General

* Better room generators (some randomization!)
* dynamic world sizes on file saves!
* colors
* settings system (!)
* UI system and backend stuff
* SAVING SYSTEM

##UI

* Selection to actually work
* How to handle the output?

Have this kind of object with pointers to handle the output to correct functions.

    struct SelectionState {
        int value;
        bool isComplete;
    }

Or capture the whole Main loop for UI... selection is overriding anyway.

Secondary
=========

* loading of the world (or streaming parts of it(?)) (Possibly not needed at all)
* figure out where the spamming comes when a save loading from disk
