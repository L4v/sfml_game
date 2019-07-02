#include "statemachine.hpp"

void StateMachine::addState(StateRef newState, bool isReplacing){
    this->_isAdding = true;
    this->_isReplacing = isReplacing;

    this->_newState = std::move(newState);
}

void StateMachine::removeState(){
    this->_isRemoving = true;
}

void StateMachine::updateStateChanges(){

    // Check if a state is to be removed
    if(this->_isRemoving && !this->_states.empty()){
        this->_states.pop();

        // If the state stack wasn't empty, resume the next state
        if(!this->_states.empty())
            this->_states.top()->resume();

        this->_isRemoving = false;
    }

    // Check if a state is being added
    if(this->_isAdding){

        // Check whether to replace the current state with a new one
        if(!this->_states.empty()){
            if(this->_isReplacing)
                this->_states.pop();
            else
                this->_states.top()->pause();
        }

        this->_states.push(std::move(this->_newState));
        this->_states.top()->init();
        this->_isAdding = false;
    }
}
StateRef& StateMachine::getActiveState() { return this->_states.top(); }
