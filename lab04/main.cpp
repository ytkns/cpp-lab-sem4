// To jest przykład instrukcji do ćwiczeń - kompletna instrukcja 
// zawsze będzie zawarta w tym miejscu, tj. w pliku main.cpp
//
// PROJEKT 01 etap 2:
// Prosze uzupelnic niniejsze kody tak, aby program wykonywal się a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
// Plik main.cpp oraz pozostale wstepnie zalaczone pliki (jesli takie sa w katalogoach include lub src) nie moga byc w zaden sposob modyfikowane !
// Klasy DamageEvent, HealEvent, ItemEvent musza dziedziczyc z klasy IEvent. 
//
// Ponizej instrukcja z etapu 1:
//
//    Napiszemy system eventów, który oparty jest o tzw. wzorzec obserwatora (Observer Pattern) i callbacki,
//    czyli funkcje, które rejestrujemy by w odpowiednim momencie mogły zostać wywołane i dać nam informację zwrotną (stąd nazwa :)).
//
//    Jako, że nie znamy jeszcze funkcji lambda, w którą można byłoby opakować wywołanie odpowiedniej metody,
//    to musimy rozwiązać to w trochę mniej elegancki sposób, jak powyżej. :)
//    W bardziej produkcyjnej wersji moglibśmy zrobić, np.
//
//        EventBus bus;
//        ScoreSystem score;
//        
//        bus.subscribe([&](IEvent* e){ score.handleEvent(e); });
//
//    Założenia:
//
//        0) Player i Enemy są tylko tłem, którym (być może) zajmiemy się później.
//        1) Event Bus:
//            * przechowuje kolejkę eventów (std::queue)
//                - trzeba się zastanowić jak sobie zorganizować dziedziczenie i ich kategorie
//            * przechowuje kontener zarejestrowanych callbacków
//            * pozwala na zarejestrowanie callbacka (konwencjonalnie nazywamy to subscribe, a nasłuchującego subscriber)
//            * pozwala na wyemitowanie eventu do wszystkich nasłuchujących
//            * pozwala na przeprocesowanie wszystkich eventów w kolejce, czyli poinformowanie o nich wszystkich nasłuchujących
//
//        2) Systemy - tutaj przyjmujemy tylko, że mają wypisywać jakąś informację, że otrzymały event.
//
//
// Uwaga: nie należy powielać kodu z klasy bazowej w klasach pochodnych, tylko wykorzystać pracę wykonywaną przez metody klasy bazowej 
// w metodach klas pochodnych (także w odniesieniu do konstruktorów).
// Generalnie należy unikać duplikacji jakiegokolwiek kodu.
// Poziomy dostepu do skladnikow klas powinny byc dobrane zgodnie z zasadami programowania obiektowego (hermetyzacja/ekapsulacja)  
// Staraj się nie powielać tego samego kodu w różnych miejscach. 
// Kazda klasa powinna byc zdefiniowana w oddzielnym pliku h (deklaracje funkcji, klas i metod, ewentualnie takze definicje jesli klasa szablonowa) i cpp (definicje).
//
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
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz o strukturze takiej jak w zadaniu na UPeL.
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem projNN_etapM/ (gdzie NN to nr projektu a M to etap np. proj01_etap2)
// * katalog z zadaniem powinien zawierać podkatalog include/
//   w którym muszą znajdować się wszystkie niezbędne pliki nagłówkowe
// * katalog z zadaniem powinien zawierać podkatalog src/
//   w którym muszą znajdować się wszystkie niezbędne pliki z kodem źródłowym
// * katalog z zadaniem powinien zawierać podkatalog build/ 
//   w którym powinien znajdować się tylko i wyłącznie plik Makefile
// * tworzenie archiwum: tar -czvf nazwa.tar.gz zad/
//   np. tar -czvf proj01_etap2.tar.gz proj01_etap2/
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
#include <string>

#include "EventBus.h"   
#include "Enemy.h"      
#include "Player.h"     
#include "ScoreSystem.h"
#include "LootSystem.h" 
#include "SoundSystem.h"
#include "BusProxy.h"

#include "IEvent.h"
#include "DamageEvent.h"
#include "HealEvent.h"
#include "ItemEvent.h"

using namespace std;


int main() 
{

    cout << "=== 1 ============================================" << endl;

    EventBus bus;

    bus.subscribe(&ScoreSystem::handleEvent);
    bus.subscribe(&LootSystem::handleEvent);
    bus.subscribe(&SoundSystem::handleEvent);

    Enemy enemy1(1, 50, bus);
    Enemy enemy2(2, 30, bus);
    Player player(1, 100, bus);

    enemy1.takeDamage(20);
    enemy2.takeDamage(40);

    player.heal(25);
    player.pickItem("Smasher");

    enemy1.takeDamage(40);

    bus.processEvents();


    cout << "=== 2 ============================================" << endl;

    bus(new DamageEvent(10, 1));
    bus(new HealEvent(10, 5));
    bus(new ItemEvent(10, "Potion"));

    bus.processEvents();


    cout << "=== 3 ============================================" << endl;

    IEvent* e1 = new DamageEvent(100, 1000);
    IEvent* e2 = new HealEvent(200, 2000);
    IEvent* e3 = new ItemEvent(300, "Legendary Sword");

    bus[0](e1); 
    bus[1](e2); 
    bus[2](e3); 

    delete e1;
    delete e2;
    delete e3;


    cout << "=== 4 ============================================" << endl;

    BusProxy proxy(bus);

    proxy.subscribe(&ScoreSystem::handleEvent);

    enemy1.takeDamage(5);

    proxy.processEvents();


    cout << "=== 5 ============================================" << endl;

    EventBus& a = EventBus::getInstance();
    EventBus& b = EventBus::getInstance();

    a.subscribe(&ScoreSystem::handleEvent);
    b.subscribe(&SoundSystem::handleEvent);

    Enemy enemy4(4, 100, a);

    enemy4.takeDamage(50);

    b.processEvents();


    cout << "=== 6 ============================================" << endl;

    EventBus testBus;

    testBus.subscribe(&ScoreSystem::handleEvent);
    testBus.subscribe(&SoundSystem::handleEvent);
    testBus.subscribe(&LootSystem::handleEvent);

    testBus(new DamageEvent(7, 77));
    testBus(new HealEvent(7, 33));
    testBus(new ItemEvent(7, "Shield"));

    testBus.processEvents();


    return 0;
}


/** Wynik dzialania programu:
=== 1 ============================================
[ScoreSystem] Enemy 1 took 20 damage
[SoundSystem] Play hit sound
[ScoreSystem] Enemy 2 took 40 damage
[SoundSystem] Play hit sound
[SoundSystem] Play heal sound
[LootSystem] Player 1 picked up: Smasher
[SoundSystem] Play item pickup sound
[ScoreSystem] Enemy 1 took 40 damage
[SoundSystem] Play hit sound
=== 2 ============================================
[ScoreSystem] Enemy 10 took 1 damage
[SoundSystem] Play hit sound
[SoundSystem] Play heal sound
[LootSystem] Player 10 picked up: Potion
[SoundSystem] Play item pickup sound
=== 3 ============================================
[ScoreSystem] Enemy 100 took 1000 damage
[SoundSystem] Play item pickup sound
=== 4 ============================================
[ScoreSystem] Enemy 1 took 5 damage
[SoundSystem] Play hit sound
[ScoreSystem] Enemy 1 took 5 damage
=== 5 ============================================
[ScoreSystem] Enemy 4 took 50 damage
[SoundSystem] Play hit sound
=== 6 ============================================
[ScoreSystem] Enemy 7 took 77 damage
[SoundSystem] Play hit sound
[SoundSystem] Play heal sound
[SoundSystem] Play item pickup sound
[LootSystem] Player 7 picked up: Shield
*/