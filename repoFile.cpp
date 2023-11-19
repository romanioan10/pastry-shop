#include "repoFile.h"
#include "entitate.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void RepoFile::setUP()
{
    ifstream f(this->fisier);
    char nume[20];
    int id, pret;
    while (f>>id)
    {
        f>>pret;
        f>>nume;
        this->adauga(id, pret, nume);
    }
    f.close();
}
void RepoFile::setIN(vector<Entitate> lista)
{
    ofstream g(this->fisier);
    for(int i=0;i<lista.size();i++)
        g<<lista[i].getId()<<" "<<lista[i].getPret()<<" "<<lista[i].getNume()<<endl;
}
