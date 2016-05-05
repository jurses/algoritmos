#include <iostream>
#include <cstring>

enum Semana{
    Lunes,
    Martes,
    Miercoles
};

std::string cadena;

int main(void){
    cadena = "¿Qué tal?";
    switch(2){
        case Lunes: std::cout << "Es Lunes!" << std::endl; break;
        case Martes: std::cout << "Es Martes!" << std::endl; break;
        case Miercoles: std::cout << "Es X!" << std::endl; break;
    }

    cadena += Martes;
    std::cout << cadena << std::endl;
}
