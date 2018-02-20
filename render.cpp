#include <iostream>
#include "render.h"
#include "draw.h"

Render::Render(): g_window(glfwGetCurrentContext()),_draw( &Draw::getDraw()){}
Render::~Render(){}

void Render::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _draw->drawCube();

    glfwSwapBuffers( g_window );
    glfwPollEvents();
}

Render &Render::getRender(){
    static Render *render = NULL;
    if( render == NULL ){
        render = new Render();
        glClearColor( 0.15f, 0.15f, 0.15f, 1.0f );

        glMatrixMode( GL_PROJECTION );
        glViewport( 0.0f, 0.0f, 800.0f, 600.0f );
        glMatrixMode( GL_MODELVIEW );

        glEnable( GL_DEPTH_TEST );
        glEnable( GL_AUTO_NORMAL );
        glEnable( GL_NORMALIZE );
        glShadeModel( GL_SMOOTH );
    }
    return *render;
}

void Render::destroyRender(){
    Render *render = &getRender();
    delete render;
}
