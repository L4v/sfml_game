#pragma once

#include <memory>
#include <stack>

#include "state.hpp"

typedef std::unique_ptr<State> StateRef;
class StateMachine{
public:
    /*
    * Default constructors
    */
    StateMachine(){}
    ~StateMachine(){}

    /*
    * Add a state to the state stack
    */
    void addState(StateRef newState, bool isReplacing = true);
    /*
    * Remove state from the top of the stack
    */
    void removeState();

    /*
    * Processess all the required state changes
    */
    void updateStateChanges();

    /*
    * Returns current active state
    */
    StateRef& getActiveState();

private:
    std::stack<StateRef> _states;
    StateRef _newState;

    bool _isRemoving;
    bool _isAdding;
    bool _isReplacing;
};
