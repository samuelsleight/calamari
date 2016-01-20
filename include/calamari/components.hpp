//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_COMPONENTS_HPP
#define CALAMARI_COMPONENTS_HPP

#include "defines.hpp"
#include "state.hpp"

CALAMARI_NS

class Application;
class State;

class TickHandler {
public:
    virtual void on_tick(calamari::Application& application) = 0;

    virtual void register_object(calamari::State& state);
};

class QuitHandler {
public:
    virtual void on_quit(calamari::Application& application) = 0;

    virtual void register_object(calamari::State& state);
};

class KeyHandler {
public:
    virtual void on_key(calamari::Application& application, int key) = 0;

    virtual void register_object(calamari::State& state);
};

CALAMARI_NS_END

#endif //CALAMARI_COMPONENTS_HPP
