//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_STATE_HPP
#define CALAMARI_STATE_HPP

#include "defines.hpp"
#include "objectbase.hpp"
#include "vector.hpp"

#include <vector>

CALAMARI_NS

class Application;
class Renderer;

class TickHandler;
class QuitHandler;
class KeyHandler;
class ResizeHandler;

class Renderable;
class Camera;

class State {
public:
    State() = default;

    virtual ~State() {}

    template<typename ObjectT, typename... ObjectTConstructorArgs>
    std::shared_ptr<ObjectT> add(ObjectTConstructorArgs&&... args) {
        objects.emplace_back(new ObjectT(*this, std::forward<ObjectTConstructorArgs>(args)...));
        objects.back()->register_object(*this);
        return std::static_pointer_cast<ObjectT>(objects.back());
    };

    void register_tick_handler(TickHandler& handler);
    void register_quit_handler(QuitHandler& handler);
    void register_key_handler(KeyHandler& handler);
    void register_resize_handler(ResizeHandler& handler);

    void register_renderable(Renderable& renderable);
    void set_camera(Camera& camera);

    void on_tick(Application& application);
    void on_quit(Application& application);
    void on_key_press(Application& application, int key);
    void on_key_release(Application& application, int key);
    void on_resize(Application& application, Vector<2, int> size);

private:
    friend class Renderer;

    std::vector<std::shared_ptr<impl::ObjectBase>> objects;

    std::vector<std::reference_wrapper<TickHandler>> tick_handlers;
    std::vector<std::reference_wrapper<QuitHandler>> quit_handlers;
    std::vector<std::reference_wrapper<KeyHandler>> key_handlers;
    std::vector<std::reference_wrapper<ResizeHandler>> resize_handlers;
    std::vector<std::reference_wrapper<Renderable>> renderables;

    Camera* camera;
};

CALAMARI_NS_END

#endif //CALAMARI_STATE_HPP
