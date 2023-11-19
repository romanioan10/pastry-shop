#ifndef LABORATOR9_10_NRNATURAL_H
#define LABORATOR9_10_NRNATURAL_H

#include "InvalidCodeException.h"

class NrNatural{
private:
    int nr;
public:
    NrNatural(int nrDat):nr(nrDat){}

    void validare(int nrDat)
    {
        if(nrDat<nr)
            throw InvalidCodeException("Numarul trebuie sa fie natural");
    }
};

#endif //LABORATOR9_10_NRNATURAL_H
