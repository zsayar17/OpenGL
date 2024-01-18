#include <iostream>

#include <unistd.h>
#include "Window/Window.hpp"
#include "Shader/VertexShader.hpp"

void setup() {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left
        0.5f, -0.5f, 0.0f, // right
        0.0f,  0.5f, 0.0f  // top
    };

    VertexShader *vertex_shader = new VertexShader("vertex.glsl", vertices);

}

void update() {

}

void draw() {

}

void mainLoop(Window *window)
{

    setup();
    while (!window->shouldClose())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        update();
        draw();

        window->refreshWindow();
        window->fpsCounter();
    }
}

int main(int argc, char **argv)
{
    Window *window;

    window = Window::createNewWindow(800, 600, "Hello World");
    mainLoop(window);
}
