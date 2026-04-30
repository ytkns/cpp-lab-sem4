// To jest przykład instrukcji do ćwiczeń - kompletna instrukcja 
// zawsze będzie zawarta w tym miejscu, tj. w pliku main.cpp
//
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// (UWAGA: rozwiazanie tego zadania moze wymagac implementacji dodatkowej 2 klasy) 
//
// Pliku main.cpp, nie wolno modyfikowac.
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod)
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile, chyba że polecenie stanowi inaczej)
//
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz o strukturze takiej jak w zadaniu na UPeL.
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem labNN/ (gdzie NN to nr laboratorum np. lab01)
// * katalog z zadaniem powinien zawierać podkatalog include/
//   w którym muszą znajdować się wszystkie niezbędne pliki nagłówkowe
// * katalog z zadaniem powinien zawierać podkatalog src/
//   w którym muszą znajdować się wszystkie niezbędne pliki z kodem źródłowym
// * katalog z zadaniem powinien zawierać podkatalog build/ 
//   w którym powinien znajdować się tylko i wyłącznie plik Makefile
// * tworzenie archiwum: tar -czvf nazwa.tar.gz zad/
//   np. tar -czvf lab01.tar.gz lab01/
// * rozpakowanie archiwum: tar -xvf nazwa.tar
// * wszystkie funkcje w plikach *.h powinny być okomentowane - przykład prawidłowej dokumentacji funkcji:
//
// /** @brief Wyszukanie elementu w liscie.
// *
// * Funkcja przeszukuje liste w celu znalezienia podanego elementu.
// *
// * @param[in] list  wskaznik do listy
// * @param[in] c  wartosc szukanego elementu
// * @return wskaznik do pierwszego elementu listy o wartosci c jesli taki element jest w liscie \n
// * NULL jesli lista nie posiada elementu o wartosci c
// */
// slistEl* find(slist* list, char c);


#include <iostream>
#include "Pipeline.h"

using namespace std;


int main(int argc, char** argv) 
{
    Pipeline p;

    p[0] = 2.0;
    p[1] = -1.0;
    p[2] = 0.5;

    Pipeline a = p.add(3.0);
    Pipeline b = p.add(5.0);

    p[0] = 10.0;
    p[1] = 4.0;

    std::cout << "LAZY_TEST1\n";
    std::cout << a(1.0) << "\n";
    std::cout << b(1.0) << "\n";

    Pipeline c = a.add(2.0);

    p[2] = -3.0;

    std::cout << "LAZY_TEST2\n";
    std::cout << c(1.0) << "\n";
    std::cout << a(1.0) << "\n";

    std::cout << "LAZY_TEST3\n";
    std::cout << a(2.0) << "\n";
    std::cout << c(2.0) << "\n";

    std::cout << "INDEX_TEST\n";
    std::cout << p[0] << "\n";
    std::cout << a[0] << "\n";			


	return 0;
}


/** Wynik dzialania programu:
LAZY_TEST1
1
3
LAZY_TEST2
3
1
LAZY_TEST3
0
2
INDEX_TEST
10
2
*/
