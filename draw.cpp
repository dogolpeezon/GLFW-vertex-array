#include "draw.h"
#include "anim.h"

Draw::Draw(){}
Draw::~Draw(){}

static GLfloat x = 0.5f;
static GLfloat y = 0.5f;
static GLfloat z = 0.5f;
float vRot = 0;
float vInit(GLfloat vertices[], GLfloat colors[]);

void Draw::drawCube()
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0, -0.5, -10);

     GLfloat vertices[] =
    {
		-x, -y, -z,   -x, -y,  z,   -x,  y,  z,   -x,  y, -z,
		x, -y, -z,    x, -y,  z,    x,  y,  z,    x,  y, -z,
		-x, -y, -z,   -x, -y,  z,    x, -y,  z,    x, -y, -z,
		-z,  y, -z,   -x,  y,  z,    x,  y,  z,    x,  y, -z,
		-x, -y, -z,   -x,  y, -z,    x,  y, -z,    x, -y, -z,
		-z, -y,  z,   -x,  y,  z,    x,  y,  z,    x, -y,  z
    };

    GLfloat colors[] =
    {
        0, 0, 0,   0, 0, 1,   0, 1, 1,   0, 1, 0,
        1, 0, 0,   1, 0, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 0, 1,   1, 0, 1,   1, 0, 0,
        0, 1, 0,   0, 1, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 1, 0,   1, 1, 0,   1, 0, 0,
        0, 0, 1,   0, 1, 1,   1, 1, 1,   1, 0, 1
    };

    glPopMatrix();
    glFlush();
    glRotated(vRot, 0, vRot, vRot);
    vInit(vertices, colors);
    vRot += 1;

}

float vInit(GLfloat *vertices, GLfloat *colors){

    // Enable state for vertex and color
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    // Send data : 24 vertices
    glDrawArrays(GL_QUADS, 0, 24);

    // Cleanup states
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    return 0;
}

Draw &Draw::getDraw(){
    static Draw *draw = 0;
    if( draw == NULL ){
        draw = new Draw();
    }
    return *draw;
}

void Draw::destroyDraw(){
    Draw *draw = &getDraw();
    delete draw;
}
