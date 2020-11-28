#include <iostream>
#include <string>
#pragma once

using namespace std;

class Material
{
    public:
        Material();
        Material(int idMaterial, std::string titulo);
        void setIdMaterial(int idMaterial){this->idMaterial = idMaterial;};
        void setTitulo(std::string titulo){this->titulo = titulo;};
        int getIdMaterial(){return idMaterial;}
        std::string getTitulo(){return titulo;}

        virtual void muestraDatos() = 0;
        virtual int cantidadDiasPrestamo() = 0;
    protected:
        int idMaterial;
        std::string titulo;
};
Material::Material()
{
    idMaterial = 111;
    titulo = "EL TACO MAS LOCO";

}
Material::Material(int idMaterial, std::string titulo)
{
    this->idMaterial = idMaterial;
    this->titulo = titulo;
}
