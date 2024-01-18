#ifndef __VERTEX_SHADER_HPP__
#define __VERTEX_SHADER_HPP__

#include "../../Essantials/glad/glad.h"
#include "AShader.hpp"
#include "../Utilis/Exceptions.hpp"
#include <iostream>


class VertexShader : public AShader {
    private:
        static const GLenum shader_type = GL_VERTEX_SHADER;

        VertexShader();
        VertexShader(const VertexShader& other);
        VertexShader& operator=(const VertexShader& other);

    protected:
        void createBufferObject();
        void createShader();

    public:

        VertexShader(const std::string& shader_path, void *data);
        ~VertexShader();

};

#endif
