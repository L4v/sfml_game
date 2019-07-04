#pragma once

#include <map>

class State{
public:
    virtual void init() = 0;

    virtual void handleInput(float dt) = 0;
    virtual void update(float dt) = 0;

    virtual void draw(float dt) = 0;

    virtual void pause() {};
    virtual void resume() {};

protected:
    std::map<std::string, int> _supportedKeys;
    std::map<std::string, int> _keybinds;

    virtual void initKeybinds() = 0;

};
