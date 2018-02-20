#include <GLFW/glfw3.h>
#include "anim.h"

Anim::Anim( bool run ):
_run( run ), g_window( glfwGetCurrentContext()),
_render( &Render::getRender()),
_input( &Input::getInput()){}
Anim::~Anim() { Render::destroyRender(); Input::destroyInput(); }

void Anim::loop (){
    while ( _run ){
        _run = !glfwWindowShouldClose( g_window );
        glfwSetKeyCallback( g_window, Input::keyCallback );
        _render->render();
    }
}

Anim &Anim::getAnim (){
    static Anim *anim = NULL;
    if ( anim == NULL ){
        glfwInit();
        GLFWwindow *window = glfwCreateWindow(800, 600, " window ", NULL, NULL);
        glfwMakeContextCurrent( window );
        anim = new Anim( true );
    }
    return *anim;
}

void Anim::destroyAnim (){
    Anim *anim = &getAnim();
    delete anim;
    GLFWwindow *g_window = glfwGetCurrentContext();
    glfwDestroyWindow( g_window );
    glfwTerminate();
}
