#include "VertexShader.hpp"


VertexShader::VertexShader() : AShader("", NULL) {

}

VertexShader::VertexShader(const VertexShader& other) : AShader("", NULL) {

}

VertexShader& VertexShader::operator=(const VertexShader& other) {
    (void)other;
    return *this;
}

VertexShader::VertexShader(const std::string& shader_path, void *data) : AShader(shader_path, data) {
    createBufferObject();
}

VertexShader::~VertexShader() {

}

void VertexShader::createBufferObject() {
    glGenBuffers(1, &_buffer_object_id); // Generate buffer object
    glBindBuffer(GL_ARRAY_BUFFER, _buffer_object_id); // Bind buffer object
    glBufferData(GL_ARRAY_BUFFER, sizeof(_data), _data, GL_STATIC_DRAW); // TODO: Change GL_STATIC_DRAW to GL_DYNAMIC_DRAW
}

void VertexShader::createShader() {
    char info_log[512];
    int success;

    _shader_id = glCreateShader(shader_type); // Create shader
    glShaderSource(_shader_id, 1, &shader_code.c_str(), NULL); // Attach shader code to shader
    glCompileShader(_shader_id); // Compile shader
    glGetShaderiv(_shader_id, GL_COMPILE_STATUS, &success); // Get compilation status of shader

    if (!success) {
        glGetShaderInfoLog(_shader_id, 512, NULL, info_log); // Get info log of shader if compilation failed
        throw ShaderCompilationError(info_log);
    }
}

