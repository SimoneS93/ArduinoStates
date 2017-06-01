#include "Edge.h"


void Edge::construct(State *from, State *to, StateEvent event) {
    this->from = from;
    this->to = to;
    this->event = event;
}