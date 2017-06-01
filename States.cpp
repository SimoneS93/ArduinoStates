#include "States.h"


States::States(State* initial, bool enter) {
    current = initial;

    if (enter)
        current->enter(0, current->getId());
}

bool States::edge(State *from, State *to, StateEvent event) {
    Edge edge;
    
    states.put(from->getId(), from);
    states.put(to->getId(), to);
    edge.construct(from, to, event);
    edges[it++] = edge;
}

bool States::trigger() {
    for (uint8_t i = 0; i < it; i++) {
        Edge edge = edges[i];

        if (edge.from->getId() == current->getId()) {
            current->leave(current->getId(), edge.to->getId());
            edge.to->enter(current->getId(), edge.to->getId());
            current = edge.to;
            return true;
        }
    }

    return false;
}

bool States::trigger(StateEvent event) {
    for (uint8_t i = 0; i < it; i++) {
        Edge edge = edges[i];

        if (edge.from->getId() == current->getId() && edge.event == event) {
            current->leave(current->getId(), edge.to->getId());
            edge.to->enter(current->getId(), edge.to->getId());
            current = edge.to;
            return true;
        }
    }

    return false;
}

void States::update() {
    current->update(current->getId());
}