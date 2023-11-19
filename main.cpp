#include "UI.h"
#include "teste.h"
#include "repoFile.h"
int main()
{
    allTests();
    RepoFile repoFile("patiserie.txt");
    Service service(repoFile);
    UI ui(service);
    ui.menu();


    return 0;

}
