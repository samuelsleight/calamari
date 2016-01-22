//
// Created by Sam Sleight on 21/01/2016.
//

#ifndef CALAMARI_ERROR_HPP
#define CALAMARI_ERROR_HPP

#include "defines.hpp"

#include <stdexcept>
#include <string>

CALAMARI_NS

class CalamariError : public std::runtime_error {
protected:
    CalamariError(std::string message);
};

class InitialisationError : public CalamariError {
public:
    InitialisationError(std::string message);
};

CALAMARI_NS_END

#endif //CALAMARI_ERROR_HPP
