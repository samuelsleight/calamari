//
// Created by Sam Sleight on 21/01/2016.
//

#include "calamari/error.hpp"

CALAMARI_NS

CalamariError::CalamariError(std::string message)
    : std::runtime_error(message) {}

InitialisationError::InitialisationError(std::string message)
    : CalamariError(message) {}

CALAMARI_NS_END
