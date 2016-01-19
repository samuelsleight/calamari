#include <calamari/application.hpp>
#include <calamari/object.hpp>
#include <calamari/components.hpp>

class TestObject : public calamari::Object<calamari::QuitHandler, calamari::KeyHandler> {
public:
    TestObject(calamari::State& state) {}

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
        : application(application), name(name) {

        object = add<TestObject>();
    }

    void tick() {}

private:
    calamari::Application& application;
    std::string name;
    std::weak_ptr<TestObject> object;
};

int main() {
    calamari::Application().start<HelloState>("Sam");
}
