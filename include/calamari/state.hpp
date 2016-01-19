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
class QuitHandler;

class State {
public:
    State() = default;
    virtual ~State() {}

    virtual void tick() = 0;

    template<typename ObjectT, typename... ObjectTConstructorArgs>
    std::weak_ptr<ObjectT> add(ObjectTConstructorArgs&... args) {
        objects.emplace_back(new ObjectT(*this, args...));
        objects.back()->register_object(*this);
        return std::static_pointer_cast<ObjectT>(objects.back());
    };

    void register_quit_handler(QuitHandler &handler);
    void on_quit(Application &application);

private:
    std::vector<std::shared_ptr<impl::ObjectBase>> objects;
    std::vector<std::reference_wrapper<QuitHandler>> quit_handlers;
};

CALAMARI_NS_END

#endif //CALAMARI_STATE_HPP
