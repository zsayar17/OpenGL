#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "../../Essantials/glad/glad.h"
#include "../../Essantials/Glfw/include/GLFW/glfw3.h"

#include "../Utilis/Exceptions.hpp"
#include "../Utilis/Input.hpp"

#include <iostream>

class Window
{
    private:
        Window();
        Window(int width, int height, const std::string& window_name);
        Window(const Window& other);
        Window& operator=(const Window& other);

        void createWindow(int width, int height, const std::string& window_name);
        void initGlad();
        void setKeyEvent();
        void pollEvents();
        void swapBuffers();
        void clearWindow();



        GLFWwindow* window;
        int width, height;

        static int fps;

    public:
        ~Window();
        static Window* createNewWindow(int width, int height, const std::string& window_name);

        void resizeViewport(int width, int height);
        void refreshWindow();
        int shouldClose();
        int fpsCounter();
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);


#endif
