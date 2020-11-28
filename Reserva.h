//#include "Material.h"
#include "Fecha.h"
#pragma once
class Reserva
{
    public:
        Reserva();
        Reserva(int idMaterial, int idCliente, Fecha fechaReservacion);
        Fecha calcularFechaFinReserva(int cantDias);

        int getIdMaterial(){return idMaterial;};
        int getIdCliente(){return idCliente;};
        Fecha getFechaReservacion();

        void setIdMaterial(int idMaterial){this->idMaterial = idMaterial;};
        void setIdCliente(int idCliente){this->idCliente = idCliente;};
        void setFechaReservacion(Fecha fechaReservacion){this->fechaReservacion = fechaReservacion;}
        void muestraDatos();
        static int contadorObjetoReserva;
    private:
        int idMaterial;
        int idCliente;
        Fecha fechaReservacion;
};

int Reserva::contadorObjetoReserva = 0;

Reserva::Reserva()
{
    Fecha fechaTemp;
    idMaterial = 1000;
    idCliente = 1;
    fechaReservacion = fechaTemp;
    contadorObjetoReserva++;
}

Reserva::Reserva(int idMaterial, int idCliente, Fecha fechaReservacion)
{
    this->idMaterial = idMaterial;
    this->idCliente = idCliente;
    this->fechaReservacion = fechaReservacion;
    contadorObjetoReserva++;
}

Fecha Reserva::calcularFechaFinReserva(int cantDias)
{
    return this->fechaReservacion + cantDias;
}

Fecha Reserva::getFechaReservacion()
{
    return this->fechaReservacion;
}

void Reserva::muestraDatos()
{
    cout << "----Datos de la reservacion----" << endl;
    cout << "ID material: " << idMaterial << endl;
    cout << "ID cliente: " << idCliente << endl;
    cout << this->fechaReservacion << endl;
    cout << " " << endl;
}
