#ifndef LABORATOR9_10_INVALIDCODEEXCEPTION_H
#define LABORATOR9_10_INVALIDCODEEXCEPTION_H

#include "stdexcept"
#include <iostream>
using namespace std;

class InvalidCodeException:public invalid_argument{
private:
    char* mesaj;
public:
    InvalidCodeException(char *msg): invalid_argument(msg), mesaj(msg){
    }

    char* what()
    {
        return mesaj;
    }
};


#endif //LABORATOR9_10_INVALIDCODEEXCEPTION_H
