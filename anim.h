#ifndef _anim_h_
#define _anim_h_

#include <iostream>
#include <GLFW/glfw3.h>
#include "render.h"
#include "input.h"

class Anim {
private:
    bool _run;
    Render *_render;
    Input *_input;
    //Shader * _shader;
    GLFWwindow *g_window;

    Anim( bool run );
    ~Anim();

public:
    void loop();
    static Anim &getAnim();
    static void destroyAnim();
};
#endif
