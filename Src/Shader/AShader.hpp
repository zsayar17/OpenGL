#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#include "../../Essantials/glad/glad.h"
#include "../Utilis/Exceptions.hpp"
#include <iostream>
#include <fstream>

class AShader {
    private:
        static const char* file_path;

        AShader();
        AShader(const AShader& other);
        AShader& operator=(const AShader& other);

        std::string shader_code;

        void readShaderFile(const std::string& shader_path);

    protected:
        AShader(const std::string& shader_path, void *data);
        virtual ~AShader();

        unsigned int _buffer_object_id;
        unsigned int _shader_id;
        void*        _data;

        virtual void createBufferObject() = 0;
        virtual void createShader() = 0;
};


#endif
