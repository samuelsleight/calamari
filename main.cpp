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
    }
};

class Camera : public calamari::Object<calamari::Camera, calamari::ResizeHandler, calamari::KeyHandler, calamari::TickHandler> {
public:
    Camera(calamari::State& state, calamari::Vector<2, int> size)
        : up(false), down(false), left(false), right(false), toggle(true) {

        viewport = size;

        translate(0, 0, 0);
    }

    void on_tick(calamari::Application& application) override {
        calamari::Matrix<4, 4, float> translation = pop_transformation().transformation;
        calamari::Matrix<4, 4, float> rotation = pop_transformation().transformation;

        push_transformation(rotation * calamari::rotation(calamari::Axis::Y, 3.14159 / 30));

        if(up || down || left || right) {
            push_transformation(translation * calamari::translation(
                (left || right) ? (left ? -0.1 : 0.1) : 0,
                (up || down) ? (up ? 0.1 : -0.1) : 0,
                0
            ));
        } else {
            push_transformation(translation);
        }
    }

    void on_resize(calamari::Application& application, calamari::Vector<2, int> size) override {
        viewport = size;
    }

    void on_key_press(calamari::Application& application, calamari::Key key) override {
        switch(key.key) {
            case calamari::KeyCode::Up:
            case calamari::KeyCode::W:
                up = true;
                break;

            case calamari::KeyCode::Down:
            case calamari::KeyCode::S:
                down = true;
                break;

            case calamari::KeyCode::Left:
            case calamari::KeyCode::A:
                left = true;
                break;

            case calamari::KeyCode::Right:
            case calamari::KeyCode::D:
                right = true;
                break;
        }

        toggle = !toggle;
        background.x = toggle ? 1.0 : 0.5;
        background.y = toggle ? 0.0 : 0.5;
        background.z = toggle ? 0.5 : 1.0;
    }

    void on_key_release(calamari::Application& application, calamari::Key key) override {
        switch(key.key) {
            case calamari::KeyCode::Up:
            case calamari::KeyCode::W:
                up = false;
                break;

            case calamari::KeyCode::Down:
            case calamari::KeyCode::S:
                down = false;
                break;

            case calamari::KeyCode::Left:
            case calamari::KeyCode::A:
                left = false;
                break;

            case calamari::KeyCode::Right:
            case calamari::KeyCode::D:
                right = false;
                break;

            default:
                break;
        }

        background.r = 1.0 - background.r;
        background.g = 1.0 - background.g;
        background.b = 1.0 - background.b;
    }

    bool up, down, left, right;
    bool toggle;
};

class Handler : public calamari::Object<calamari::QuitHandler, calamari::KeyHandler> {
public:
    Handler(calamari::State& state) {}

    void on_quit(calamari::Application& application) override {
        std::cout << "Quitting!" << std::endl;
        application.quit();
    }

    void on_key_press(calamari::Application& application, calamari::Key key) override {}

    void on_key_release(calamari::Application& application, calamari::Key key) override {
        if(key.key == calamari::KeyCode::Escape) {
            application.quit();
        }
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
