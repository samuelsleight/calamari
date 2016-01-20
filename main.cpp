#include <calamari/application.hpp>
#include <calamari/object.hpp>
#include <calamari/components.hpp>
#include <calamari/camera.hpp>

class TestCamera : public calamari::Object<calamari::Camera> {
public:
    TestCamera(calamari::State& state) {}
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

    void on_key(calamari::Application& application, int key) {
        std::cout << "Key pressed: " << key << std::endl;
    }
};

class HelloState : public calamari::State {
public:
    HelloState(calamari::Application& application, std::string name)
        : application(application) {

        object = add<TestObject>(name);
        add<TestCamera>();
    }

private:
    calamari::Application& application;
    std::weak_ptr<TestObject> object;
};

int main() {
    calamari::Application().start<HelloState>("Sam");
}
