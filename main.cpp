#include <calamari/application.hpp>
#include <calamari/object.hpp>
#include <calamari/components.hpp>
#include <calamari/camera.hpp>
#include <calamari/renderable.hpp>

class Triangle : public calamari::Object<calamari::Renderable> {
public:
    Triangle(calamari::State& state) {
        add_vertex(0.3, 0.3, 0.0);
        add_vertex(-0.4, 0.9, 0.0);
        add_vertex(-0.9, -0.3, 0.0);

        translate(1, 0, 0);
    }
};

class Camera : public calamari::Object<calamari::Camera, calamari::ResizeHandler, calamari::KeyHandler> {
public:
    Camera(calamari::State& state, calamari::Vector<2, int> size) : toggle(true) {
        viewport = size;

        translate(1, 0, 0);
        translate(0, 1, 0);
    }

    void on_resize(calamari::Application& application, calamari::Vector<2, int> size) override {
        viewport = size;
    }

    void on_key_press(calamari::Application& application, int key) override {
        toggle = !toggle;
        background.x = toggle ? 1.0 : 0.5;
        background.y = toggle ? 0.0 : 0.5;
        background.z = toggle ? 0.5 : 1.0;
    }

    void on_key_release(calamari::Application& application, int key) override {
        background.r = 1.0 - background.r;
        background.g = 1.0 - background.g;
        background.b = 1.0 - background.b;
    }

    bool toggle;
};

class Handler : public calamari::Object<calamari::QuitHandler> {
public:
    Handler(calamari::State& state) {}

    void on_quit(calamari::Application& application) override {
        std::cout << "Quitting!" << std::endl;
        application.quit();
    }
};

class HelloState : public calamari::State {
public:
    HelloState(calamari::Application& application)
        : application(application) {

        add<Handler>();
        add<Camera>(application.get_window_size());
        add<Triangle>();
    }

private:
    calamari::Application& application;
};

int main() {
    try {
        calamari::Application().start<HelloState>();
    } catch(calamari::CalamariError& error) {
        std::cout << error.what() << std::endl;
    }
}
