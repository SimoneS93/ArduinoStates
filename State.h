#ifndef _STATE_H_
#define _STATE_H_

#include <Arduino.h>

#ifndef StateId 
    typedef int StateId;
#endif

/**
 * Callback when the FSM enters this State
 */
typedef void (*StateEnterCallback)(StateId  from, StateId to);

/**
 * Callback when the FSM leaves this State
 */
typedef void (*StateLeaveCallback)(StateId from, StateId to);

/**
 * Callback when the FSM stays in this State
 */
typedef void (*StateUpdateCallback)(StateId current);


/**
 * State data structure.
 * Allows for the definition of callbacks over its life-cycle
 */
class State {
    public:
        State(StateId id);
        State(StateId id, StateEnterCallback enterCallback);
        State(StateId id, StateEnterCallback enterCallback, StateUpdateCallback updateCallback);
        State(StateId id, StateEnterCallback enterCallback, StateUpdateCallback updateCallback, StateLeaveCallback leaveCallback);

        /**
         *
         */
        StateId getId();

        /**
         * Compare two states for equality
         */
        bool operator==(const State& other);

        /**
         * Call the enter callback 
         */
        void enter(StateId from, StateId self);

        /**
         * Call the leave callback 
         */
        void leave(StateId self, StateId to);

        /**
         * Call the update callback 
         */
        void update(StateId self);

    private:
        StateId id;
        StateEnterCallback enterCallback;
        StateLeaveCallback leaveCallback;
        StateUpdateCallback updateCallback;

        /**
         * Initialize the members
         */
        void construct(StateId id, StateEnterCallback enterCallback, StateUpdateCallback updateCallback, StateLeaveCallback leaveCallback);
};

#endif