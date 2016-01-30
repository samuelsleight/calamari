//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_COMPONENTS_HPP
#define CALAMARI_COMPONENTS_HPP

#include "defines.hpp"
#include "state.hpp"
#include "vector.hpp"

CALAMARI_NS

class Application;
class State;

class TickHandler {
public:
    virtual void on_tick(Application& application) = 0;

    virtual void register_component(State& state);
};

class QuitHandler {
public:
    virtual void on_quit(Application& application) = 0;

    virtual void register_component(State& state);
};

class KeyHandler {
public:
    virtual void on_key_press(Application& application, int key) = 0;
    virtual void on_key_release(Application& application, int key) = 0;

    virtual void register_component(State& state);
};

class ResizeHandler {
public:
    virtual void on_resize(Application& application, Vector<2, int> size) = 0;

    virtual void register_component(State& state);
};

CALAMARI_NS_END

#endif //CALAMARI_COMPONENTS_HPP
