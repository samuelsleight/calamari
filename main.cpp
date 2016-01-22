#include <calamari/application.hpp>
#include <calamari/object.hpp>
#include <calamari/components.hpp>
#include <calamari/camera.hpp>
#include <calamari/renderable.hpp>

class TestTriangle : public calamari::Object<calamari::Renderable> {
public:
    TestTriangle(calamari::State& state, float offset) {
        add_vertex(0.0 + offset, 0.5);
        add_vertex(0.5, -0.5 + offset);
        add_vertex(-0.5 + offset, -0.5);

        std::cout << "Triangle Added" << std::endl;
    }
};

class TestCamera : public calamari::Object<calamari::Camera, calamari::KeyHandler> {
public:
    TestCamera(calamari::State& state) : toggle(true) {}

    void on_key_press(calamari::Application& application, int key) {
        toggle = !toggle;
        background.r = toggle ? 1.0 : 0.5;
        background.g = toggle ? 0.0 : 0.5;
        background.b = toggle ? 0.5 : 1.0;
    }

    void on_key_release(calamari::Application& application, int key) {
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

    void on_quit(calamari::Application& application) {
        std::cout << "Quitting!" << std::endl;
        application.quit();
    }

    void on_key_press(calamari::Application& application, int key) {
        std::cout << "Key pressed: " << key << std::endl;
    }

    void on_key_release(calamari::Application& application, int key) {}
};

class HelloState : public calamari::State {
public:
    HelloState(calamari::Application& application, std::string name)
        : application(application) {

        object = add<TestObject>(name);
        add<TestCamera>();
        add<TestTriangle>(0.0f);
        add<TestTriangle>(0.3f);
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
