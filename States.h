#ifndef _STATES_H_
#define _STATES_H_

#ifndef STATES_SIZE
    #define STATES_SIZE 20
#endif

#include "State.h"
#include "Edge.h"
#include <ArrayMap.h>
#include <ArrayMap.cpp>

/**
 * A basic Finite State Machine.
 */
class States {
    public:

        States(State* initial, bool enter = true);
        
        /**
         * Take transition from two states when a given event occurs
         */
        bool edge(State *from, State *to, StateEvent event);

        /**
         * Trigger the first event on the current state.
         * (mainly useful if there's only one possible event)
         */
        bool trigger();

        /**
         * Trigger an event on the current state 
         */
        bool trigger(StateEvent event);

        /**
         * Optional. Trigger the update callback on the current state.
         */
        void update();

  private:
    /**
     * Iterator over the available edge slots
     */
    uint8_t it = 0;

    /**
     * Current state
     */
    State *current = 0;

    /**
     * List of states
     */
    ArrayMap<uint8_t, State> states;

    /**
     * List of edges
     */
    Edge edges[STATES_SIZE];
};

#endif