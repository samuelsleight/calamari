//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_RENDERER_HPP
#define CALAMARI_RENDERER_HPP

#include "defines.hpp"
#include "window.hpp"

namespace calamari {

class Renderer {
public:
    Renderer(Window& window);

    void clear(float d, float d1, float d2, float d3);
    void render();

private:
    Window& window;
};

}


#endif //CALAMARI_RENDERER_HPP
