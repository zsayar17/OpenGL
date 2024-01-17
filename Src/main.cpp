#include <iostream>
#include "../Include/Window.hpp"

void mainLoop(Window *window)
{
    while (!window->shouldClose())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

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
