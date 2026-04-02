// To jest przykład instrukcji do ćwiczeń - kompletna instrukcja 
// zawsze będzie zawarta w tym miejscu, tj. w pliku main.cpp
//
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
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

#include "Dictionary.h"

#include <vector>
#include "Statistics.h"
#include "PairStatistics.h"

#include "SPtr.h"
#include "Test.h"

using namespace std;


int main(int argc, char** argv) 
{
	cout << "=== 1 ==========================================" << endl;

    Dictionary Dict;

    string key1 = "key1";
    string key2 = "key2";
    string key3 = "key3";
    
	Dict["key1"] = 1;
    Dict["key2"] = 2;
    Dict["key3"] = 3;
    
    cout << Dict["key1"] << " ";
    cout << Dict["key2"] << " ";
    cout << Dict["key3"] << " ";
    cout << endl;
    
    cout << Dict[key1] << " ";
    cout << Dict[key2] << " ";
    cout << Dict[key3] << " ";
    cout << endl;
    
	Dict.print();
    
    Dict["key2"] = 20;
    Dict["key4"] = 4;
	Dict.print();
    
    Dict.clear();
    Dict.print();


	cout << endl;
 	cout << "=== 2 ==========================================" << endl;

	vector<int> v{3,7,9,7,8,0,2,6,7,3,1,5,3,0,0,4,1,8,9,9};
 
	Statistics s; 
    for (int x : v)
        s(x);
        
	s.Print();
	
	cout << endl;
	
	PairStatistics ps; 
    for (int i = 1; i < v.size(); i++)
        ps(v[i-1], v[i]);
        
	ps.Print();


	cout << endl;
 	cout << "=== 3 ==========================================" << endl;

	SPtr<Test> p1(new Test(1));

	{
		SPtr<Test> p2 = p1;
		SPtr<Test> p3(p2);
		
		p2->hello();
		(*p3).hello();
		
		SPtr<Test> p4(new Test(2));
		SPtr<Test> p5(new Test(3));
		
		p4 = p1;
		p5 = p4;
		
		p5->hello();
		
		p5 = p5;   // self-assignment
		
		SPtr<Test> p6 = p5;
		SPtr<Test> p7(new Test(4));
		
		p7 = p6;
		
		p7->hello();
	}
	
	p1->hello();
	

	return 0;
}


/** Wynik dzialania programu:
=== 1 ==========================================
1 2 3
1 2 3
[key1,1] [key2,2] [key3,3]
[key1,1] [key2,20] [key3,3] [key4,4]
Empty Dictionary

=== 2 ==========================================
Srednia z wyrazow ciagu: 4.6
Najmniejszy wyraz ciagu: 0
Najwiekszy wyraz ciagu: 9

Liczba par rownych: 2
Liczba par rosnacych: 10
Liczba par malejacych: 7

=== 3 ==========================================
Test(1) created
count = 1
count = 2
count = 3
Hello from 1
Hello from 1
Test(2) created
count = 1
Test(3) created
count = 1
count = 0
Test(2) destroyed
count = 4
count = 0
Test(3) destroyed
count = 5
Hello from 1
count = 6
Test(4) created
count = 1
count = 0
Test(4) destroyed
count = 7
Hello from 1
count = 6
count = 5
count = 4
count = 3
count = 2
count = 1
Hello from 1
count = 0
Test(1) destroyed
*/
