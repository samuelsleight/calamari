#include <calamari/application.hpp>
#include <calamari/object.hpp>
#include <calamari/components.hpp>
#include <calamari/camera.hpp>
#include <calamari/renderable.hpp>

class TestTriangle : public calamari::Object<calamari::Renderable> {
public:
    TestTriangle(calamari::State& state) {
        add_vertex(0.3, 0.3, 0.0);
        add_vertex(-0.4, 0.9, 0.0);
        add_vertex(-0.9, -0.3, 0.0);

        std::cout << "Triangle Added" << std::endl;
    }
};

class TestCamera : public calamari::Object<calamari::Camera, calamari::ResizeHandler, calamari::KeyHandler> {
public:
    TestCamera(calamari::State& state, calamari::Vector<2, int> size) : toggle(true) {
        viewport = size;
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

class TestObject : public calamari::Object<calamari::QuitHandler, calamari::KeyHandler> {
public:
    TestObject(calamari::State& state, std::string name) {}

    void test(std::string wat) {
        std::cout << wat << std::endl;
    }

    void on_quit(calamari::Application& application) override {
        std::cout << "Quitting!" << std::endl;
        application.quit();
    }

    void on_key_press(calamari::Application& application, int key) override {
        std::cout << "Key pressed: " << key << std::endl;
    }

    void on_key_release(calamari::Application& application, int key) override {}
};

class HelloState : public calamari::State {
public:
    HelloState(calamari::Application& application, std::string name)
        : application(application) {

        object = add<TestObject>(name);
        add<TestCamera>(application.get_window_size());
        add<TestTriangle>();
    }

private:
    calamari::Application& application;
    std::weak_ptr<TestObject> object;
};

int main() {
    try {
        calamari::Application().start<HelloState>("Sam");
    } catch(calamari::CalamariError& error) {
        std::cout << error.what() << std::endl;
    }
}
