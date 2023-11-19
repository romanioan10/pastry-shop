#ifndef LABORATOR9_10_SERVICE_H
#define LABORATOR9_10_SERVICE_H
using namespace std;
#include <iostream>
#include <cstring>
#include "repoFile.h"
#include "ElementNotFoundException.h"


class Service {
private:
    RepoFile  repoFile;
public:
    Service()
    {
        this->repoFile = RepoFile();
    }

    Service(const RepoFile &repoFile)
    {
        this->repoFile= repoFile;
    }

    ~Service() {};

    void adaugareService(int id, int suma, char* nume)
    {
        repoFile.adauga(id, suma, nume);
    }

    vector<Entitate> GetAllService()
    {
        return this->repoFile.getAll();
    }

    void afisareService()
    {
        vector<Entitate> lista=GetAllService();
        Afis(lista);
    }
    void Afis(vector<Entitate> lista)
    {
        if(lista.size()==0) cout<<"Lista dupa criteriu este goala!"<<endl<<endl;
        for(int i=0;i<lista.size();i++){
            cout<<i+1<<")"<<lista[i];
            cout<<endl;
        }
    }

    void stergereiD(int id)
    {
        int ok=0;
        vector<Entitate> lista = GetAllService();
        for(int i=0;i<lista.size();i++)
            if(id==lista[i].getId())
            {
                repoFile.sterge(i);
                ok=1;
            }
        if(ok==0)
            throw ElementNotFoundException("id inexistent");
    }

    int suma(char* nume)
    {
        int s=0;
        vector<Entitate> lista = GetAllService();
        for(int i=0;i<lista.size();i++)
            if(strcmp(nume, lista[i].getNume())==0)
                s+=lista[i].getPret();
        return s;
    }

    void filtrareNume(char* nume)
    {
        vector<Entitate> lista = GetAllService();
        vector<Entitate> nou;
        for(int i=0;i<lista.size();i++)
            if(strcmp(nume, lista[i].getNume())==0)
                nou.push_back(lista[i]);
        Afis(nou);
    }

    void filtrarePretMaiMiciDecatUnDat(int pret)
    {
        vector<Entitate> lista = GetAllService();
        vector<Entitate> nou;
        for(int i=0;i<lista.size();i++)
            if(lista[i].getPret()<pret)
                nou.push_back(lista[i]);
        Afis(nou);
    }

    void initializareFisier()
    {
        this->repoFile.setUP();
    }

    void copiereFisier()
    {
        this->repoFile.setIN(GetAllService());
    }
};
#endif //LABORATOR9_10_SERVICE_H
