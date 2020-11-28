#include "Material.h"
#pragma once

class Disco : public Material
{
    public:
        Disco();
        Disco(int idMaterial, std::string titulo, int duracion, std::string genero);//:Material(idMaterial, titulo);
        void muestraDatos();
        int cantidadDiasPrestamo(){return 3;};
        int getDuracion(){return duracion;};
        std::string getGenero(){return genero;};
        void setDuracion(int duracion){this->duracion = duracion;};
        void setGenero(std::string genero){this->genero = genero;};
        static int contadorObjetoDisco;
    private:
        int duracion;
        std::string genero;
};

int Disco::contadorObjetoDisco = 0;

Disco::Disco() : Material()
{
    duracion = 100;
    genero = "El Mejor";
    contadorObjetoDisco++;
}
Disco::Disco(int idMaterial, std::string titulo, int duracion, std::string genero):Material(idMaterial, titulo)
{
    this->duracion = duracion;
    this->genero = genero;
    contadorObjetoDisco++;
}

void Disco::muestraDatos()
{
    cout << "----Datos del material----" << endl;
    cout << "ID: " << idMaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Duaracion: " << duracion << endl;
    cout << "Genero: " << genero << endl;
    cout << " " << endl;
}
