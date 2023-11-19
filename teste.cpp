#include "teste.h"
#include "entitate.h"
#include "repo.h"
#include <cassert>
#include <vector>
#include "service.h"

void testeEntitate()
{
    Entitate entitate(1,1,"paine");
    assert(entitate.getId()==1);
    entitate.setId(15);
    assert(entitate.getId()==15);

}

void testeRepo()
{
    Repo repo;
    repo.adauga(1,1,"paine");
    vector <Entitate> lista = repo.getAll();
    assert(lista.size() == 1);
}

void testeService()
{
    Service service;
    service.adaugareService(1,1,"cafea");
    service.adaugareService(2,1,"franzela");
    service.adaugareService(3,1,"paine");
    vector <Entitate> lista = service.GetAllService();
    assert(lista.size()==3);
    service.stergereiD(3);

    lista=service.GetAllService();
    assert(lista.size()==2);

    assert(service.suma("cafea")==1);


}

void allTests()
{
    cout<<"incep testele"<<endl;
    testeEntitate();
    testeRepo();
    testeService();
    cout<<"testele sunt bune!!"<<endl;
}
