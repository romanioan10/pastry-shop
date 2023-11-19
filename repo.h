#include <vector>
#include "entitate.h"
#include "InvalidCodeException.h"
#include "ElementNotFoundException.h"
#pragma once

class Repo{
private:
    vector<Entitate> Entitati;
public:
    Repo()
    {
        this->Entitati.reserve(0);
    }

    ~Repo()
    {
        this->Entitati.clear();
    }

    int getSize()
    {
        return this->Entitati.size();
    }

    void adauga(int id, int pret, char* nume)
    {
        {
            int ok=0;
            Entitate entitate(id, pret, nume);
            vector<Entitate> lista = getAll();
            for(int i=0;i<lista.size();i++)
                if(id==lista[i].getId())
                    ok=1;
            if(ok==0)
                Entitati.push_back(entitate);
            else
                throw ElementNotFoundException("id deja exista");

        }
    }

    vector<Entitate> getAll()
    {
        return this->Entitati;
    }

    void sterge(int pos)
    {
        if(Entitati.cbegin()+pos == Entitati.end())
            throw ElementNotFoundException("pozitie invalida");
        else
            Entitati.erase(Entitati.cbegin()+pos);
    }
};