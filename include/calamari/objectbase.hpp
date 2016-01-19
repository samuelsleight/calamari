//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_OBJECTBASE_HPP
#define CALAMARI_OBJECTBASE_HPP

#include "defines.hpp"

#include <memory>

CALAMARI_NS

class State;

namespace impl {

struct ObjectBase : public std::enable_shared_from_this<ObjectBase> {
    virtual void register_object(calamari::State& state) = 0;
};

}

CALAMARI_NS_END

#endif //CALAMARI_OBJECTBASE_HPP
