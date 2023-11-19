#ifndef LABORATOR9_10_ELEMENTNOTFOUNDEXCEPTION_H
#define LABORATOR9_10_ELEMENTNOTFOUNDEXCEPTION_H
#include "stdexcept"
#include <iostream>
using namespace std;

class ElementNotFoundException :
        public runtime_error{
private:
    char* message;
public:
    ElementNotFoundException(char* msg):
            runtime_error(msg), message(msg){
    }
    char* what(){
        return message;
    }

};

#endif //LABORATOR9_10_ELEMENTNOTFOUNDEXCEPTION_H
