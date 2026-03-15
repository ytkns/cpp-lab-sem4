#include "Application.h"

Application::Application(string n): name(n) {};

void Application::Run(){
    cout << "Aplikacja o nazwie " << name <<  " jest uruchomiona !" << endl;

}

void Application::ActivateLog(){
    cout << "Dziennik zdarzen aplikacji o nazwie " << name <<  " jest aktywowany !" << endl;
}

