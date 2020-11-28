#include "Material.h"
#pragma once

class Libro : public Material
{
    public:
        Libro();
        Libro(int idMaterial, std::string titulo, int numPag, std::string autor);//:Material(idMaterial, titulo);
        void muestraDatos();
        int cantidadDiasPrestamo(){return 5;};
        int getNumPag(){return numPag;};
        std::string getAutor(){return autor;};
        void setNumPag(int numPag){this->numPag = numPag;};
        void setAutor(std::string autor){this->autor = autor;};
        static int contadorObjetoLibro;
    private:
        int numPag;
        std::string autor;
};

int Libro::contadorObjetoLibro = 0;

Libro::Libro() : Material()
{
    numPag = 100;
    autor = "Luis Vega";
    contadorObjetoLibro++;
}
Libro::Libro(int idMaterial, std::string titulo, int numPag, std::string autor):Material(idMaterial, titulo)
{
    this->numPag = numPag;
    this->autor = autor;
    contadorObjetoLibro++;
}

void Libro::muestraDatos()
{
    cout << "----Datos del material----" << endl;
    cout << "ID: " << idMaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Numero de paginas: " << numPag << endl;
    cout << "Autor: " << autor << endl;
    cout << " " << endl;
}
