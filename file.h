//#ifndef LABORATOR9_10_FILE_H
//#define LABORATOR9_10_FILE_H
//
//#ifndef LAB9_10_REPOFILE_H
//#define LAB9_10_REPOFILE_H
//#include "repo.h"
//#include <fstream>
//
//using namespace std;
//
//class RepoFile : public Repo {
//private:
//    string fileName;
//public:
//
//    RepoFile(){
//    }
//
//    RepoFile(string file): fileName(file){
//        loadFromFile();
//    }
//    ~RepoFile(){
//
//    }
//
//    void addElement(int id, int pret, char *nume){
//        Repo::adauga(id, pret, nume);
//        this->saveToFile();
//    }
//
//    void deleteElement(int id){
//        Repo::sterge(id);
//        this->saveToFile();
//    }
//
//
//    vector<Entitate> getRepo()
//    {
//        return Repo::getAll();
//    }
//
//    //    Repo<T>& operator=(const Repo<T> &repo1);
//    //
//    //    Repo<T>& operator=(const map<T, int>&repo1);
//
//private:
//    void loadFromFile(){
//        ifstream f(this->fileName);
//        if(f.is_open())
//        {
//            int id, pret;
//            char *nume;
//            while(!f.eof())
//            {
//                f >>id>>pret>>nume;
//                this->addElement(id, pret, nume);
//            }
//        }
//        f.close();
//    }
//
//    void saveToFile(){
//        ofstream f(this->fileName);
//        vector<Entitate> repository = this->getRepo();
//        for(auto itr = repository.begin(); itr != repository.end(); itr++)
//            f << itr->getId() << ' ' <<  itr->getPret()<<" "<<itr->getNume();
//        f.close();
//    }
//};
//
//
//#endif //LAB9_10_REPOFILE_H
//
//#endif //LABORATOR9_10_FILE_H
