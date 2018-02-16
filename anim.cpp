#include <GLFW/glfw3.h>
#include "anim.h"

Anim::Anim( bool run ):
_run( run ), g_window( glfwGetCurrentContext()),
_render( &Render::getRender()),
_input( &Input::getInput()){}
// _shader( &Shader::getShader() )

Anim::~Anim() { Render::destroyRender(); Input::destroyInput(); }
// Shader::destroyShader();

void Anim::loop (){
    std::cout << "In loop.." << std::endl;

    while ( _run ){
        _run = !glfwWindowShouldClose( g_window );
        //_input->update();
        glfwSetKeyCallback( g_window, Input::keyCallback );
        _render->render();
    }
    std::cout << "Exit render.." << std::endl;
    std::cout << "Exit loop.." << std::endl;

}

Anim &Anim::getAnim (){
    std::cout << "Enter getAnim.." << std::endl;

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
    std::cout << "Enter destroyAnim.." << std::endl;

    Anim *anim = &getAnim();
    delete anim;
    GLFWwindow *g_window = glfwGetCurrentContext();
    glfwDestroyWindow( g_window );
    glfwTerminate();
}
