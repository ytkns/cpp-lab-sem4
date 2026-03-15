#include "Window.h"

Window::Window(int windowSize): size(windowSize) {};

void Window::Run(){
    cout << "Okno o rozmiarze " << size <<  " jest wyswietlone !" << endl;
}

void Window::Maximize(){
    cout << "Okno o rozmiarze " << size << " zmaksymalizowane !" << endl;
}
