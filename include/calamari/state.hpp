//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_STATE_HPP
#define CALAMARI_STATE_HPP

#include "defines.hpp"
#include "objectbase.hpp"

#include <vector>

CALAMARI_NS

class Application;
class Renderer;

class TickHandler;
class QuitHandler;
class KeyHandler;
class Camera;

class State {
public:
    State() = default;

    virtual ~State() {}

    template<typename ObjectT, typename... ObjectTConstructorArgs>
    std::weak_ptr<ObjectT> add(ObjectTConstructorArgs& ... args) {
        objects.emplace_back(new ObjectT(*this, args...));
        objects.back()->register_object(*this);
        return std::static_pointer_cast<ObjectT>(objects.back());
    };

    void register_tick_handler(TickHandler& handler);
    void register_quit_handler(QuitHandler& handler);
    void register_key_handler(KeyHandler& handler);

    void set_camera(Camera& camera);

    void on_tick(Application& application);
    void on_quit(Application& application);
    void on_key(Application& application, int key);

private:
    friend class Renderer;

    std::vector<std::shared_ptr<impl::ObjectBase>> objects;

    std::vector<std::reference_wrapper<TickHandler>> tick_handlers;
    std::vector<std::reference_wrapper<QuitHandler>> quit_handlers;
    std::vector<std::reference_wrapper<KeyHandler>> key_handlers;

    Camera* camera;
};

CALAMARI_NS_END

#endif //CALAMARI_STATE_HPP
