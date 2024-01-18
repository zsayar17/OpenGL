#include "AShader.hpp"

const char* AShader::file_path = "Shaders/";

AShader::AShader() {

}

AShader::AShader(const AShader& other) {
    (void)other;
}

AShader& AShader::operator=(const AShader& other) {
    (void)other;
    return *this;
}

AShader::~AShader() {

}

AShader::AShader(const std::string& shader_path, void* data) : _data(data){
    readShaderFile(shader_path);
    std::cout << shader_code << std::endl;
}

void AShader::readShaderFile(const std::string& shader_path) {
    std::ifstream shader_file;
    std::string line;

    shader_code = "";
    shader_file.open((file_path + shader_path).c_str());
    if (!shader_file.is_open()) throw ShaderFileFailure();

    while (std::getline(shader_file, line)) shader_code += line + "\n";
    if (*(shader_code.end() - 1) == '\n') shader_code.erase(shader_code.end() - 1); // Erase last newline character

    shader_file.close();
}
