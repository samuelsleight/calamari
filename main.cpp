#include <calamari/application.hpp>
#include <calamari/object.hpp>
#include <calamari/components.hpp>

class TestObject : public calamari::Object<calamari::QuitHandler> {
public:
    TestObject(calamari::State& state) {}

    void test(std::string wat) {
        std::cout << wat << std::endl;
    }

    void on_quit(calamari::Application& application) {
        std::cout << "Quitting!" << std::endl;
        application.quit();
    }
};

class HelloState;

class GoodbyeState : public calamari::State {
public:
    GoodbyeState(calamari::Application& application, std::string name)
        : application(application), name(name) {}

    void tick() {
        std::cout << "Goodbye, " << name << std::endl;
        // application.enter_state<HelloState>(name);
    }

private:
    calamari::Application& application;
    std::string name;
};

class HelloState : public calamari::State {
public:
    HelloState(calamari::Application& application, std::string name)
        : application(application), name(name) {

        object = add<TestObject>();
    }

    void tick() {
        std::cout << "Hello there, " << name << std::endl;
        object.lock()->test("HELP ME");
        application.enter_state<GoodbyeState>(name);
    }

private:
    calamari::Application& application;
    std::string name;
    std::weak_ptr<TestObject> object;
};

int main() {
    calamari::Application().start<HelloState>("Sam");
}
