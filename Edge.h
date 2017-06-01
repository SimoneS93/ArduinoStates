#ifndef _STATES_EDGE_H_
#define _STATES_EDGE_H_

#include <Arduino.h>
#include "State.h"

/**
 * Here StateEvent is an alias to int, but it could be
 * a user-defined data-type that implements operator==
 */
typedef int StateEvent;

/**
 * Edge data-structure.
 * It connects two states when an event occurs.
 */
class Edge {
    public:
        State *from;
        State *to;
        StateEvent event;

        void construct(State *from, State *to, StateEvent event);
};

#endif