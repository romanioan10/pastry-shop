#ifndef LABORATOR9_10_REPOFILE_H
#define LABORATOR9_10_REPOFILE_H
#include <vector>
#include <fstream>
#include <cstring>
#include "entitate.h"
#include "repo.h"

class RepoFile: public Repo{
private:
    char fisier[20];
public:
    RepoFile():Repo()
    {
        strcpy(this->fisier, "");
    }
    RepoFile(char* t):Repo()
    {
        strcpy(this->fisier, t);
    }
    ~RepoFile(){
    }
    void setUP();
    void setIN(vector<Entitate> lista);
};
#endif //LABORATOR9_10_REPOFILE_H
