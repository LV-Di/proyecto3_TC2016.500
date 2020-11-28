#include "Material.h"
#pragma once

class Software : public Material
{
    public:
        Software();
        Software(int idMaterial, std::string titulo, int version, std::string so);//:Material(idMaterial, titulo);
        void muestraDatos();
        int cantidadDiasPrestamo(){return 3;};
        int getVersion(){return version;};
        std::string getSo(){return so;};
        void setVersion(int version){this->version = version;};
        void setSo(std::string so){this->so = so;};
        static int contadorObjetoSoftware;
    private:
        int version;
        std::string so;
};

int Software::contadorObjetoSoftware = 0;

Software::Software() : Material()
{
    version = 100;
    so = "El Mejor";
    contadorObjetoSoftware++;
}
Software::Software(int idMaterial, std::string titulo, int version, std::string so):Material(idMaterial, titulo)
{
    this->version = version;
    this->so = so;
    contadorObjetoSoftware++;
}

void Software::muestraDatos()
{
    cout << "----Datos del material----" << endl;
    cout << "ID: " << idMaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Version: " << version << endl;
    cout << "Sistema operativo: " << so << endl;
    cout << " " << endl;
}
