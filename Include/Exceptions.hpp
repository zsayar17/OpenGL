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

#endif
