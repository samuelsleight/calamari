//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_APPLICATION_HPP
#define CALAMARI_APPLICATION_HPP

#include "defines.hpp"
#include "window.hpp"
#include "renderer.hpp"
#include "eventmanager.hpp"
#include "state.hpp"

#include <memory>

CALAMARI_NS

class Application {
public:
    friend class EventManager;

    Application();

    template<typename StateT, typename... StateTConstructorArgs>
    void start(StateTConstructorArgs&&... args) {
        this->state = std::unique_ptr<State>(new StateT(*this, std::forward<StateTConstructorArgs>(args)...));
        run();
    }

    template<typename StateT, typename... StateTConstructorArgs>
    void enter_state(StateTConstructorArgs&&... args) {
        this->state = std::unique_ptr<State>(new StateT(*this, std::forward<StateTConstructorArgs>(args)...));
    }

    void quit();

private:
    void run();

    Window window;
    Renderer renderer;
    EventManager events;

    std::unique_ptr<State> state;
};

CALAMARI_NS_END

#endif //CALAMARI_APPLICATION_HPP
