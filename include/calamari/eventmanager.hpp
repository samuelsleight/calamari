//
// Created by Sam Sleight on 19/01/2016.
//

#ifndef CALAMARI_EVENTMANAGER_HPP
#define CALAMARI_EVENTMANAGER_HPP

#include "defines.hpp"

CALAMARI_NS

class Application;

class EventManager {
private:
    friend class Application;

    EventManager(Application& application);

    Application& application;

public:
    void close_callback();
    void key_callback(int key, int scancode, int action, int mods);
    void resize_callback(int width, int height);
};

CALAMARI_NS_END

#endif //CALAMARI_EVENTMANAGER_HPP
