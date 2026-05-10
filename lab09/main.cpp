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
#include <vector>
#include <sstream>
#include <functional>

#include "Sensor.h"
#include "Router.h"
#include "Camera.h"
#include "DiagnosticVisitorImpl.h"
#include "ActionVisitorImpl.h"


// =========================
// HASH 
// =========================

size_t hashStr(const std::string& s) {
    return std::hash<std::string>{}(s);
}

// =========================
// EXTRACT LINE
// =========================

bool extractLine(const std::string& out, const std::string& key, std::string& result) {
    std::istringstream iss(out);
    std::string line;

    while (std::getline(iss, line)) {
        if (line.find(key) != std::string::npos) {
            result = line;
            return true;
        }
    }
    return false;
}

// =========================
// TEST FUNCTION
// =========================

void test(const std::string& name,
          const std::string& out,
          const std::string& key,
          size_t expectedHash,
          int points,
          int& score) {

    std::string line;
    bool found = extractLine(out, key, line);

    std::cout << name << ": ";

    if (found && hashStr(line) == expectedHash) {
        std::cout << "OK (+" << points << ")\n";
        score += points;
    } else {
        std::cout << "BAD (+0)\n";

        // ===== dodatkowa informacja =====
        std::cout << "  expected: \"" << key << "\"\n";

        if (found) {
            std::cout << "  got     : \"" << line << "\"\n";
        } else {
            std::cout << "  got     : <NOT FOUND>\n";
        }
    }
}

// =========================
// RUN PROGRAM
// =========================

std::string runTest() {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    std::vector<Device*> devices;

    devices.push_back(new Sensor("S-1", 0.92));
    devices.push_back(new Router("R-1", 8));
    devices.push_back(new Camera("C-1", 720));

    DiagnosticVisitorImpl diag;
    ActionVisitorImpl act;

    std::cout << "--- DIAGNOSTICS ---\n";
    for (auto d : devices)
        d->accept(diag);

    std::cout << "--- ACTIONS ---\n";
    for (auto d : devices)
        d->accept(act);

    for (auto d : devices)
        delete d;

    std::cout.rdbuf(old);
    return buffer.str();
}

// =========================
// MAIN
// =========================

int main() {
    
    int score = 0;

    std::string out = runTest();

    // ===== pokaz raw output (debug) =====
    std::cout << "===== PROGRAM OUTPUT =====\n";
    std::cout << out;
    std::cout << "==========================\n\n";

    // =========================
    // EXPECTED
    // =========================

    std::string sensorLine = "S-1: Sensor DEGRADED";
    std::string routerLine = "R-1: Router stable";
    std::string cameraLine = "C-1: Camera LOW RES";

    std::string sensorAct = "Measuring environment...";
    std::string routerAct = "Routing packets...";
    std::string cameraAct = "Recording video...";

    // =========================
    // TESTY (85 pkt)
    // =========================

    test("SENSOR", out, "S-1", hashStr(sensorLine), 15, score);
    test("ROUTER", out, "R-1", hashStr(routerLine), 15, score);
    test("CAMERA", out, "C-1", hashStr(cameraLine), 15, score);

    test("SENSOR ACTION", out, "Measuring", hashStr(sensorAct), 10, score);
    test("ROUTER ACTION", out, "Routing", hashStr(routerAct), 10, score);
    test("CAMERA ACTION", out, "Recording", hashStr(cameraAct), 10, score);

    test("HEADER DIAG", out, "--- DIAGNOSTICS ---",
         hashStr("--- DIAGNOSTICS ---"), 5, score);

    test("HEADER ACTION", out, "--- ACTIONS ---",
         hashStr("--- ACTIONS ---"), 5, score);

    // =========================
    // FINAL (15 pkt)
    // =========================

    bool full =
        out.find("Sensor") != std::string::npos &&
        out.find("Router") != std::string::npos &&
        out.find("Camera") != std::string::npos &&
        out.find("Measuring") != std::string::npos &&
        out.find("Routing") != std::string::npos &&
        out.find("Recording") != std::string::npos;

    std::cout << "\nFINAL CONSISTENCY: ";

    if (full) {
        std::cout << "OK (+15)\n";
        score += 15;
    } else {
        std::cout << "BAD (+0)\n";
    }

    // =========================
    // RESULT
    // =========================

    std::cout << "\n=====================\n";
    std::cout << "FINAL SCORE: " << score << " / 100\n";
    std::cout << "=====================\n";


    return 0;
}


/** Wynik dzialania programu:
===== PROGRAM OUTPUT =====
--- DIAGNOSTICS ---
S-1: Sensor DEGRADED
R-1: Router stable
C-1: Camera LOW RES
--- ACTIONS ---
Measuring environment...
Routing packets...
Recording video...
==========================

SENSOR: OK (+15)
ROUTER: OK (+15)
CAMERA: OK (+15)
SENSOR ACTION: OK (+10)
ROUTER ACTION: OK (+10)
CAMERA ACTION: OK (+10)
HEADER DIAG: OK (+5)
HEADER ACTION: OK (+5)

FINAL CONSISTENCY: OK (+15)

=====================
FINAL SCORE: 100 / 100
=====================
*/
