#include "WindowApplication.h"

WindowApplication::WindowApplication(int i, int k, string n): id(i), Window(k), Application(n) {};

void WindowApplication::Run(){
    Window::Run();
    Application::Run();
    cout << "Aplikacja okienkowa o id = 1216 jest uruchomiona !" << endl;
}