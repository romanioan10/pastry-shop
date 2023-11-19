using namespace std;
#include <iostream>
#include "service.h"
#include "InvalidCodeException.h"
#include "nrNatural.h"

class UI {
private:
    Service service;
public:
    UI(const Service &service)
    {
        this->service = service;
    }

    void adaugare()
    {
        try
        {
            int id, suma;
            char *nume = new char[15];
            NrNatural nrNatural(0);

            cout << "Dati un id:";
            cin >> id;
            nrNatural.validare(id);
            cout << "Dati o suma:";
            cin >> suma;
            nrNatural.validare(suma);
            cout << "Dati un nume:";
            cin >> nume;
            this->service.adaugareService(id, suma, nume);
        }
        catch(InvalidCodeException exception)
        {
            cout<<exception.what()<<endl;
        }
        catch(ElementNotFoundException exception)
        {
            cout<<exception.what()<<endl;
        }
    }

    void stergere()
    {
        try
        {
            int id;
            NrNatural nrNatural(0);
            cout << "Dati id-ul: ";
            cin >> id;
            nrNatural.validare(id);
            this->service.stergereiD(id);
        }
        catch (InvalidCodeException exception)
        {
            cout<<exception.what()<<endl;
        }
        catch(ElementNotFoundException exception)
        {
            cout<<exception.what()<<endl;
        }
    }

    void pretMaiMic()
    {
        try {
            NrNatural nrNatural(1);
            int pret;
            cout << "Dati pretul: ";
            cin >> pret;
            nrNatural.validare(pret);
            this->service.filtrarePretMaiMiciDecatUnDat(pret);
        }
        catch(InvalidCodeException exception)
        {
            cout<<exception.what()<<endl;
        }
    }
    void printMenu()
    {
        cout << "1. Adauga o tranzactie" << endl;
        cout << "2. Afiseaza tranzactiile" << endl;
        cout << "3. Elimina tranzactia dupa id" << endl;
        cout << "4. Suma totala a unui aliment dat" << endl;
        cout << "5. Filtrarea unui aliment dat" << endl;
        cout << "6. Filtrarea entitatilor mai mici decat un pret dat" << endl;
        cout << "0. Iesire" << endl;
        cout << "Dati o optiune: "<<endl;
    }
    int menu()
    {
        this->service.initializareFisier();
        while (true)
        {
            printMenu();
            int opt = 0;
            cin >> opt;
            switch (opt) {
                case 1:
                {
                    adaugare();
//                    this->service.adaugareService(1, 15,"paine");
//                    this->service.adaugareService(2, 120,"lapte");
//                    this->service.adaugareService(3, 50,"praji");
//                    this->service.adaugareService(4, 250,"cafea");
//                    this->service.adaugareService(5, 67,"cafea");
//                    this->service.adaugareService(6, 136,"paine");
                    this->service.copiereFisier();
                    break;
                }
                case 2:
                    this->service.afisareService();
                    break;
                case 3:
                {
                    stergere();
                    this->service.copiereFisier();
                    break;
                }
                case 4:
                {
                    char* nume = new char[15];
                    cout<<"Dati alimentul dorit: ";
                    cin>>nume;
                    cout<<"suma este: "<<this->service.suma(nume);
                    cout<<endl;
                    break;
                }
                case 5:
                {
                    char* nume = new char[15];
                    cout<<"Dati alimentul dorit: ";
                    cin>>nume;
                    this->service.filtrareNume(nume);
                    break;
                }
                case 6:
                {
                    pretMaiMic();
                    break;
                }
                default:
                    cout << "la revedere " << endl;
                    return 0;
            }
        }
    }
};
