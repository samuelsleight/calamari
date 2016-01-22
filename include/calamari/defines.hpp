//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_DEFINES_HPP
#define CALAMARI_DEFINES_HPP

#define CALAMARI_NS_NAME calamari
#define CALAMARI_NS namespace CALAMARI_NS_NAME {
#define CALAMARI_NS_END }

#define CALAMARI_GLSL(name, source) const GLchar* name = "#version 330\n" #source

#endif //CALAMARI_DEFINES_HPP
