//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_OBJECT_HPP
#define CALAMARI_OBJECT_HPP

#include "defines.hpp"

#include <iostream>

CALAMARI_NS

class State;

namespace impl {

template<typename... Components>
struct ObjectSpecBase;

template<>
struct ObjectSpecBase<> : public ObjectBase {
    virtual void register_object(calamari::State& state) {}
};

template<typename Component, typename... Components>
struct ObjectSpecBase<Component, Components...> : public ObjectSpecBase<Components...>, Component {
    virtual void register_object(calamari::State& state) {
        Component::register_object(state);
        ObjectSpecBase<Components...>::register_object(state);
    }
};

}

template<typename... Components>
class Object : public impl::ObjectSpecBase<Components...> {
public:
    Object() = default;

private:
    friend class State;

    void register_object(State& state) {
        impl::ObjectSpecBase<Components...>::register_object(state);
    }
};

CALAMARI_NS_END

#endif //CALAMARI_OBJECT_HPP
