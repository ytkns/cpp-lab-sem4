// To jest przykład instrukcji do ćwiczeń - kompletna instrukcja 
// zawsze będzie zawarta w tym miejscu, tj. w pliku main.cpp
//
// Prosze uzupelnic niniejsze kody tak, aby program wykonywal się a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Zaimplementuj odpowiednio klasy niezbedne do dzialania programu odtwarzajac hierarchie dziedziczenia.
// Wszystkie rekonstruowane klasy musza tworzyc jedno drzewo dziedziczenia - kazda klasa musi dziedziczyc 
// z jakiejs innej klasy (jednej) za wyjatkiem klasy znajdujacej sie na samej górze hierarchii dziedziczenia.
// Kod kazdej z definiowanych metod Write moze zawierac dowolną ilosc instrukcji
// wypisujacych na standardowe wyjscie, przy czym kazda z tych instrukcji musi wypisywac 
// albo jedną z liczb podstawionych pod zmienna w main-ie 
// albo tylko jeden z nastepujacych znaków: $, %, &, !, *, @.
// Jesli chcesz, by dana metoda Write powinna wypisywała na wyjsciu rózne znaki, korzystaj z
// wywołan metod Write klasy bazowej np.:
//
//void X99::Write()
//{
//    ...
//
//    cout << '@';    // wypisujemy znak @
//
//    ...
//
//    <nazwa_klasy_bazowej>::Write();    
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
// Pliku Main.cpp oraz funkcji zdefiniowanych juz w zalaczonych plikach cpp nie wolno modyfikowac.
//
// Uwaga: Poziomy dostepu do skladnikow klas powinny byc dobrane zgodnie z zasadami programowania obiektowego (hermetyzacja/ekapsulacja)  
// Staraj się nie powielać tego samego kodu w różnych miejscach. 
// Kazda klasa powinna byc zdefiniowana w oddzielnym pliku h (deklaracje funkcji, klas i metod, ewentualnie takze definicje jesli klasa szablonowa) i cpp (definicje).
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
// * archiwum powinno zawierać katalog z zadaniem labNN/ (gdzie NN to nr laboratorium np. lab01)
// * katalog z zadaniem powinien zawierać podkatalog include/
//   w którym muszą znajdować się wszystkie niezbędne pliki nagłówkowe
// * katalog z zadaniem powinien zawierać podkatalog src/
//   w którym muszą znajdować się wszystkie niezbędne pliki z kodem źródłowym
// * katalog z zadaniem powinien zawierać podkatalog build/ 
//   w którym powinien znajdować się tylko i wyłącznie plik Makefile
// * tworzenie archiwum: tar -czvf nazwa.tar.gz zad/
//   np. tar -czvf lab01.tar.gz lab01/
// * rozpakowanie archiwum: tar -xvf nazwa.tar.gz
//
// * wszystkie funkcje w plikach *.h powinny być okomentowane zgodnie z wczesniej ustalonym wzorem (format pod Doxygena) np.:
// /** @brief Wyszukanie elementu w liscie.
// *
// * Funkcja przeszukuje liste w celu znalezienia podanego elementu.
// *
// * @param[in] list  wskaznik do listy
// * @param[in] c  wartosc szukanego elementu 
// * @return wskaznik do pierwszego elementu listy o wartosci c jesli taki element jest w liscie \n
// * NULL jesli lista nie posiada elementu o wartosci c
// */
// slistEl * find(slist * list, char c);
//
// * do szybkiej weryfikacji poprawnosci wyjscia mozna uzyc diff-a (np.: diff -B plik_z_outputem_z_main plik_z_outputem_z_programu > wyniki_porownania.out)


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
    X07 Y01(nNo);
    
    nNo = 2;
    X01 Y02(nNo);

    nNo = 3;
    X05 Y03(nNo);
    
    X04 Y04;
    
    nNo = 5;
    X02 Y05(nNo);
    
    nNo = 6;
    X03 Y06(nNo);
    
    nNo = 7;
    X06 Y07(nNo);
    
    X02& Y08 = Y05;
    
    X07* pY09 = new X07;

    X06& Y10 = Y03;
    
    X04* apY11[10];
    apY11[0] = &Y01; 
    apY11[1] = &Y02;
    apY11[2] = &Y03;
    apY11[3] = &Y04;
    apY11[4] = (X01*)(&Y05);      
    apY11[5] = &Y06;
    apY11[6] = &Y07;
    apY11[7] = &Y08;
    apY11[8] = pY09;
    apY11[9] = &Y10;
        
    X06 Y12 = Y03;
    X06 Y13 = (X06)Y06;
    X01 Y14 = Y05;
    X04 Y15 = (X06)Y01;
    
    
    
    
    Y05.Write();   cout << endl;
    Y14.Write();   cout << endl;
    Y07.Write();   cout << endl;
    apY11[4]->Write();   cout << endl;
    Y01.Write();   cout << endl;
    apY11[7]->Write();   cout << endl;
    pY09->Write();   cout << endl;
    Y06.Write();   cout << endl;
    apY11[8]->Write();   cout << endl;
    Y03.Write();   cout << endl;
    Y10.Write();   cout << endl;    
    Y04.Write();   cout << endl;
    Y13.Write();   cout << endl;
    Y15.Write();   cout << endl;    
    Y02.Write();   cout << endl;
    Y08.Write();   cout << endl;
    apY11[1]->Write();   cout << endl;
    Y12.Write();   cout << endl;
    
    
    delete pY09;

        
    
    return 0;
}


/** Wynik dzialania programu:
$$$$$&&&&&5&&&&&$$$$$                       X02
&&&&&5&&&&&                                 X01
*******7*******                             X06
5                                           X04
@*1*@                                       X07
5                                           X04
@*1*@                                       X07
!!!!!!******6******!!!!!!                   X03
1                                           X04
%%%@@@***3***@@@%%%                         X05
***3***                                     X06
1                                           X04
******6******                               X06
1                                           X04
&&2&&                                       X01
$$$$$&&&&&5&&&&&$$$$$                       X02
2                                           X04
***3***                                     X06
*/
