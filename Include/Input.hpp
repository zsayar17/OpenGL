#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include "../Essantials/glad/glad.h"
#include "../Essantials/Glfw/include/GLFW/glfw3.h"
#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

void keyPressed(int key);
void keyReleased(int key);

void mousePressed(int button);
void mouseReleased(int button);
void mouseMoved(int button, double xpos, double ypos);
void mouseScrolled(int button, double xoffset, double yoffset);

#endif
