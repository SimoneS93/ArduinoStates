#include "State.h"


State::State(StateId id) {
    construct(id, NULL, NULL, NULL);
}

State::State(StateId id, StateEnterCallback enterCallback) {
    construct(id, enterCallback, NULL, NULL);
}

State::State(StateId id, StateEnterCallback enterCallback, StateUpdateCallback updateCallback) {
    construct(id, enterCallback, updateCallback, NULL);
}

State::State(StateId id, StateEnterCallback enterCallback, StateUpdateCallback updateCallback, StateLeaveCallback leaveCallback) {
    construct(id, enterCallback, updateCallback, leaveCallback);
}

StateId State::getId() {
    return id;
}

bool State::operator==(const State& other) {
    // two states are equal if they have the same ID 
    return id == other.id;
}

void State::enter(StateId from, StateId self) {
    if (enterCallback) {
        enterCallback(from, self);
    }
}

void State::leave(StateId self, StateId to) {
    if (leaveCallback) {
        leaveCallback(self, to);
    }
}

void State::update(StateId self) {
    if (updateCallback) {
        updateCallback(self);
    }
}

void State::construct(StateId id, StateEnterCallback enterCallback, StateUpdateCallback updateCallback, StateLeaveCallback leaveCallback) {
    this->id = id;
    this->enterCallback = enterCallback;
    this->updateCallback = updateCallback;
    this->leaveCallback = leaveCallback;
}