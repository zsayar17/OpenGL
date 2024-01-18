#include "Input.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    (void)scancode;
    (void)mods;

    if (action == GLFW_PRESS) keyPressed(key);
    else if (action == GLFW_RELEASE) keyReleased(key);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    (void)button;
    (void)mods;

    if (action == GLFW_PRESS) mousePressed(button);
    else if (action == GLFW_RELEASE) mouseReleased(button);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    mouseScrolled(0, xoffset, yoffset);
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    mouseMoved(0, xpos, ypos);
}

void keyPressed(int key) {
    //std::cout << "key pressed: " <<  key << std::endl;
}

void keyReleased(int key) {
    //std::cout << "key released: " <<  key << std::endl;
}

void mousePressed(int button) {
    //std::cout << "mouse pressed: " <<  button << std::endl;
}

void mouseReleased(int button) {
    //std::cout << "mouse released: " <<  button << std::endl;
}

void mouseMoved(int button, double xpos, double ypos) {
    //std::cout << "mouse moved: " <<  xpos << ", " << ypos << std::endl;
}

void mouseScrolled(int button, double xoffset, double yoffset) {
    //std::cout << "mouse scrolled: " <<  xoffset << ", " << yoffset << std::endl;
}
