#include "Window.h"

Window::Window(int n): size(n) {};

void Window::Run(){
    cout << "Okno o rozmiarze " << size <<  " jest wyswietlone !" << endl;
}

void Window::Maximize(){
    cout << "Okno o rozmiarze " << size << " zmaksymalizowane !" << endl;
}