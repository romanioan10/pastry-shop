#ifndef LABORATOR9_10_ENTITATE_H
#define LABORATOR9_10_ENTITATE_H

#define LABORATOR7_8_CHELTUIELI_H
#include <iostream>
using namespace std;


class Entitate{

private:
    int id, pret;
    char *nume;
public:
    Entitate();
    Entitate(int id, int pret, char* n);
    Entitate(const Entitate &c);
    ~Entitate();
    int getPret();
    int getId();
    char* getNume();
    void setPret(int s);
    void setId(int z);
    void setNume(char *n);
    Entitate& operator=(const Entitate &p);
    bool operator==(const Entitate &p);
    friend ostream& operator<<(ostream& os, const Entitate& c)
    {
        os<<"Id: "<<c.id<<" "<<"Pret: "<<c.pret<<" "<<"Nume: "<<c.nume<<endl;
        return os;
    }
};

#endif //LABORATOR9_10_ENTITATE_H
