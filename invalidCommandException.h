#ifndef INVALIDCOMMANDEXCEPTION_H
#define INVALIDCOMMANDEXCEPTION_H

#include <iostream>

class InvalidCommandException {
    std::string name;
public:
    InvalidCommandException(std::string name) : name{name} {}
    void prettyprint() {
        std::cout << "Invalid command: " << name << std::endl;
    }
};

#endif 
