// To jest przykład instrukcji do ćwiczeń - kompletna instrukcja 
// zawsze będzie zawarta w tym miejscu, tj. w pliku main.cpp
//
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Zaimplementuj odpowiednio klasy niezbedne do dzialania programu odtwarzajac hierarchie dziedziczenia.
// Wszystkie rekonstruowane klasy musza tworzyc jedno drzewo dziedziczenia - kazda klasa musi dziedziczyc 
// z jakiejs innej klasy (jednej) za wyjatkiem klasy znajdujacej sie na samej górze hierarchii dziedziczenia.
// Przynajmniej 1 klasa musi byc abstrakcyjna, przynajmniej jedna metoda WriteN musi byc wirtualna 
// (niekoniecznie w klasie bedacej na samej gorze hierarchii dziedziczenia).
// Kod kazdej z definiowanych metod WriteN moze zawierac dowolną ilosc instrukcji
// wypisujacych na standardowe wyjscie, przy czym kazda z tych instrukcji musi wypisywac 
// albo jedną z liczb podstawionych pod zmienna nNo w main-ie 
// albo tylko jeden z nastepujacych znaków: $, %, &, !, *, @.
// Jesli chcesz, by dana metoda WriteN powinna wypisywała na wyjsciu rózne znaki, korzystaj z
// wywołan metod o tej samej nazwie WriteN klasy bazowej np.:
//
//void X99::Write2()
//{
//    ...
//
//    cout << '@';    // wypisujemy znak @
//
//    ...
//
//    <nazwa_klasy_bazowej>::Write2();    
//
//    ...
//
//    char cDecor = '@';    // wypisujemy znak @ (ten sam co wyzej)
//
//    ...
//
//    for (int i=0; i<=2; i++)
//        cout << cDecor;    // wypisujemy znak @ (ten sam co wyzej)
//
//
//    ...
//
//    // cout << '%';    // ZLE !!! Probujemy wypisac inny znak niz wczesniej wypisywany.
//
//}
//
// Uwaga: nie należy powielać kodu z klasy bazowej w klasach pochodnych, tylko wykorzystać pracę wykonywaną przez metody klasy bazowej 
// w metodach klas pochodnych (także w odniesieniu do konstruktorów).
// Generalnie należy unikać duplikacji jakiegokolwiek kodu.
// Poziomy dostepu do skladnikow klas powinny byc dobrane zgodnie z zasadami programowania obiektowego (hermetyzacja/ekapsulacja)  
// Staraj się nie powielać tego samego kodu w różnych miejscach. 
// Kazda klasa powinna byc zdefiniowana w oddzielnym pliku h (deklaracje funkcji, klas i metod, ewentualnie takze definicje jesli klasa szablonowa) i cpp (definicje).
//
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

using namespace std;


#include "X01.h"
#include "X02.h"
#include "X03.h"
#include "X04.h"
#include "X05.h"
#include "X06.h"
#include "X07.h"



int main()
{
    int nNo;
    
    nNo = 1;
    X03 Y01(nNo);
    
    nNo = 2;
    X06 Y02(nNo);

    nNo = 3;
    X04 Y03(nNo);
    
    nNo = 5;
    X02 Y05(nNo);
    
    nNo = 6;
    X01 Y06(nNo);
    
    nNo = 7;
    X05 Y07(nNo);
    
    X02& Y08 = Y05;
    
    X03* pY09 = new X03;

    X05& Y10 = Y03;
    
    X07* apY11[10];
    apY11[0] = &Y01; 
    apY11[1] = &Y02;
    apY11[2] = &Y03;
    apY11[4] = (X06*)(&Y05);      
    apY11[5] = &Y06;
    apY11[6] = &Y07;
    apY11[7] = &Y08;
    apY11[8] = pY09;
    apY11[9] = &Y10;
        
    X05 Y12 = Y03;
    X05 Y13 = (X05)Y06;
    X06 Y14 = Y05;
    
    Y05.Write1();   cout << endl;
    Y05.Write2();   cout << endl;
    Y05.Write3();   cout << endl;

    Y14.Write1();   cout << endl;
    Y14.Write2();   cout << endl;
    Y14.Write3();   cout << endl;
    
    Y07.Write1();   cout << endl;
    Y07.Write2();   cout << endl;
    Y07.Write3();   cout << endl;

    Y01.Write1();   cout << endl;
    Y01.Write2();   cout << endl;
    Y01.Write3();   cout << endl;
    
    apY11[7]->Write1();   cout << endl;
    apY11[7]->Write2();   cout << endl;
    apY11[7]->Write3();   cout << endl;
    
    pY09->Write1();   cout << endl;
    pY09->Write2();   cout << endl;
    pY09->Write3();   cout << endl;
    
    Y06.Write1();   cout << endl;
    Y06.Write2();   cout << endl;
    Y06.Write3();   cout << endl;
    
    apY11[8]->Write1();   cout << endl;
    apY11[8]->Write2();   cout << endl;
    apY11[8]->Write3();   cout << endl;
    
    Y03.Write1();   cout << endl;
    Y03.Write2();   cout << endl;
    Y03.Write3();   cout << endl;
    
    Y10.Write1();   cout << endl;    
    Y10.Write2();   cout << endl;    
    Y10.Write3();   cout << endl;    

    Y13.Write1();   cout << endl;
    Y13.Write2();   cout << endl;
    Y13.Write3();   cout << endl;
    
    Y02.Write1();   cout << endl;
    Y02.Write2();   cout << endl;
    Y02.Write3();   cout << endl;
    
    Y08.Write1();   cout << endl;
    Y08.Write2();   cout << endl;
    Y08.Write3();   cout << endl;
    
    apY11[1]->Write1();   cout << endl;
    apY11[1]->Write2();   cout << endl;
    apY11[1]->Write3();   cout << endl;

    Y12.Write1();   cout << endl;
    Y12.Write2();   cout << endl;
    Y12.Write3();   cout << endl;
    
    delete pY09;
        
    return 0;
}


/** Wynik dzialania programu:
$$$$$$$$$$&&&&&&&&&&&&&&&$$$$$
$$$$$&&&&&&&&&&&&&&&$$$$$$$$$$
$$$$$$$$$$&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$
&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&
*********************
7
7
@@***@
@1@@
@@1@@
$$$$$$$$$$&&&&&&&&&&&&&&&$$$$$
5
5
@@***@
@1@@
@@1@@
!!!!!!!!!!!!******************!!!!!!
!!!!!!6!!!!!!!!!!!!
!!!!!!!!!!!!6!!!!!!!!!!!!
@@***@
1
1
%%%%%%@@@@@@*********@@@%%%
%%%@@@3@@@@@@%%%%%%
%%%%%%@@@@@@3@@@@@@%%%%%%
%%%%%%@@@@@@*********@@@%%%
3
%%%%%%@@@@@@3@@@@@@%%%%%%
******************
6
6
&&&&&&
&&&&&&
&&&&&&&&
$$$$$$$$$$&&&&&&&&&&&&&&&$$$$$
$$$$$&&&&&&&&&&&&&&&$$$$$$$$$$
$$$$$$$$$$&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$
&&&&&&
2
2
*********
3
3
*/
