#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include <exception>
#include <string>


class CreateWindowFailure : public std::exception
{
    public:
        virtual const char* what() const throw() {
            return ("Window creation failed");
        }
};

class InitGladFailure : public std::exception
{
    public:
        virtual const char* what() const throw() {
            return ("Glad initialization failed");
        }
};

class InintEngineFailure : public std::exception
{
    public:
        virtual const char* what() const throw() {
            return ("Engine initialization failed");
        }
};

class ShaderFileFailure : public std::exception
{
    public:
        virtual const char* what() const throw() {
            return ("Shader file could not be opened");
        }
};

class ShaderCompilationError : public std::exception
{
    public:
        ShaderCompilationError(const char* info_log) : _info_log(info_log) {}
        virtual const char* what() const throw() {
            return (_info_log);
        }

    private:
        const char* _info_log;
};

#endif
