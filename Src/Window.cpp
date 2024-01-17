#include "../Include/Window.hpp"

// Static methods
Window* Window::createNewWindow(int width, int height, const std::string& window_name) {
    Window* window;

    try {
        window = new Window(width, height, window_name);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    return window;
}

// Hidden chopplin form
Window::Window() {

}

Window::Window(const Window& other) {
    (void)other;
}

Window& Window::operator=(const Window& other) {
    (void)other;
    return *this;
}

Window::Window(int width, int height, const std::string& window_name)
{
    createWindow(width, height, window_name);
    initGlad();
    resizeViewport(width, height);
    setKeyEvent();
}

// Reachable Choplin Form methods
Window::~Window() {
    glfwTerminate(); // Terminate glfw
}

void Window::createWindow(int width, int height, const std::string& window_name) {
    this->width = width;
    this->height = height;

    glfwInit(); // Initialize glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Set minor version of opengl
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Set major version of opengl
    window = glfwCreateWindow(width, height, window_name.c_str(), NULL, NULL); // Create window
    if (window == NULL) throw CreateWindowFailure(); // Throw exception if window was not created
    glfwMakeContextCurrent(window); // Make window current
}

void Window::initGlad() {
    // glfwGetProcAddress is a function pointer to the OS specific function that loads the address of the OpenGL function
    // gladLoadGLLoader is a function that loads all the OpenGL functions specified by the function pointer on the OS
    // GLADloadproc is a function pointer to the OS specific function that loads the address of the OpenGL function
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) throw InitGladFailure();
}


void Window::pollEvents() {
    glfwPollEvents(); // Poll events
}

void Window::swapBuffers() {
    glfwSwapBuffers(window); // Swap buffers
}

void Window::clearWindow() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear window
}

void Window::setKeyEvent() {
    glfwSetKeyCallback(window, key_callback); // Set callback function for key events
    glfwSetMouseButtonCallback(window, mouse_button_callback); // Set callback function for mouse button events
    glfwSetScrollCallback(window, scroll_callback); // Set callback function for scroll events
    glfwSetCursorPosCallback(window, cursor_position_callback); // Set callback function for cursor position events
}

void Window::resizeViewport(int width, int height) {
    this->width = width;
    this->height = height;

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // Set callback function
}

void Window::refreshWindow() {
    clearWindow();
    swapBuffers();
    pollEvents();
}

int Window::shouldClose() {
    return glfwWindowShouldClose(window); // Return if window should close
}

int Window::fpsCounter() {
    static int frames = 0, prev_fps = 0;
    static double lastTime = glfwGetTime();
    double current_time;

    frames++;
    current_time = glfwGetTime();
    if (current_time - lastTime >= 1.0)
    {
        std::cout << "FPS: " << frames << std::endl;
        prev_fps = frames;
        frames = 0;
        lastTime = current_time;
    }
    return (prev_fps);
}


// viewports transform the 2D coordinates it processed to coordinates on your screen
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height); // Set viewport
}

