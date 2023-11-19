#include "entitate.h"
#include <cstring>
Entitate::Entitate()
{
    this->id=0;
    this->pret=0;
    this->nume= nullptr;
}

Entitate::Entitate(int id, int pret, char* nume)
{
    this->id=id;
    this->pret=pret;
    this->nume = new char [strlen(nume)+1];
    strcpy_s(this->nume, sizeof this->nume, nume);
}

Entitate::Entitate(const Entitate &e)
{
    this->nume = new char(strlen(e.nume)+1);
    strcpy_s(this->nume, sizeof this->nume, e.nume);
    this->id=e.id;
    this->pret=e.pret;
}



Entitate::~Entitate(){
    if (this->nume){
        delete[] this->nume;
        this->nume = nullptr;
    }
}

char* Entitate::getNume(){
    return this->nume;
}

int Entitate::getId() {
    return this->id;
}

int Entitate::getPret()
{
    return this->pret;
}

void Entitate::setNume(char *n)
{
    if (this->nume) {
        delete[] this->nume;
    }
    this->nume = new char[strlen(n) + 1];
    strcpy_s(this->nume, sizeof this->nume, n);
}

void Entitate::setId(int z)
{
    this->id=z;
}

void Entitate::setPret(int s)
{
    this->pret=s;
}

Entitate& Entitate::operator=(const Entitate &c){
    this->setId(c.id);
    this->setPret(c.pret);
    this->setNume(c.nume);
    return *this;
}

bool Entitate::operator==(const Entitate &c)
{
    return ((strcmp(this->nume, c.nume) == 0) && (this->id == c.id) && (this->pret == c.pret));
}