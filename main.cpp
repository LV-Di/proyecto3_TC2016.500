#include <iostream>
#include <fstream>
#include <string>


#include "Libro.h"
#include "Disco.h"
#include "Software.h"
#include "Reserva.h"
using namespace std;

int main()
{



//--------------------------------------
    //Declara variables de tipo archivo
    ifstream archivoMaterial;
    ifstream archivoReserva;
    //Declara variables de tipo texto
    std::string nombreMaterial;
    std::string nombreReserva;

    //Recepci�n del nombre de la plantilla
    //cout << "Favor de especifica el nombre del archivo que contiene la plantilla (excluye la terminacion '.txt')" << endl;
    //getline(cin, nombreMaterial);
    nombreMaterial = "Material";
    nombreMaterial = nombreMaterial + ".txt";
    //Abre documento con plantilla
    archivoMaterial.open(nombreMaterial);
    //Comprobaci�n de la existencia del archivo de plantilla
    if(archivoMaterial.good() == 0)
    {
        cout << "El archivo que contiene la plantilla con nombre: " << nombreMaterial <<" no existe. Favor de verificar si se encuentra en la carpeta correspondiente" << endl;
        return 0;//<--Finaliza el la ejecuci�n
    }

    //Recepci�n del nombre del documento con los datos
    //cout << " " << endl;//<--Mejora el formato visual en la consola
    //cout << "Favor de especifica el nombre del archivo que contiene los datos (excluye la terminacion '.txt')" << endl;
    //getline(cin, nombreReserva);
    nombreReserva = "Reserva";
    nombreReserva = nombreReserva + ".txt";
    //Abre documento con datos
    archivoReserva.open(nombreReserva);
    //Comprobaci�n de la existencia del archivo de datos
    if(archivoReserva.good() == 0)
    {
        cout << "El archivo que contiene los datos con nombre: " << nombreReserva <<" no existe. Favor de verificar si se encuentra en la carpeta correspondiente" << endl;
        return 0;//<--Finaliza el la ejecuci�n
    }
    int maxNumberOfMaterials = 30;
    int maxNumberOfReservations = 60;
    Material *materialArr[maxNumberOfMaterials];
    Reserva reservacionesArr[maxNumberOfReservations];
    int idMaterial_;
    std::string titulo_;
    std::string tipo;
    int atributo1;
    std::string atributo2;
    int i;

    i = 0;
    while (archivoMaterial >> idMaterial_ >> titulo_ >> tipo >> atributo1 >> atributo2)
    {

        if(tipo == "S")
        {
           materialArr[i] = new Software(idMaterial_, titulo_, atributo1, atributo2);;
        }
        if(tipo == "D")
        {
           materialArr[i] = new Disco(idMaterial_, titulo_, atributo1, atributo2);
        }
        if(tipo == "L")
        {
           materialArr[i] = new Libro(idMaterial_, titulo_, atributo1, atributo2);
        }
        i++;
    }
    int dd_, mm_, aa_, idCliente_, iTemp, r;

    r = 0;
    while (archivoReserva >> dd_ >> mm_ >> aa_ >> idMaterial_ >> idCliente_)
    {
        for(iTemp = i - 1; iTemp > -1; iTemp--)
        {
            if(materialArr[iTemp]->getIdMaterial() == idMaterial_)
            {
                Fecha fechaReservacion(dd_, mm_, aa_);
                reservacionesArr[r].setIdMaterial(idMaterial_);
                reservacionesArr[r].setIdCliente(idCliente_);
                reservacionesArr[r].setFechaReservacion(fechaReservacion);
                r++;
            }
        }
    }



    int iterateIndicator = 1;
    while(iterateIndicator == 1)
    {
        cout << "Menu de inicio" << endl;
        cout << "Ingrese la letra que haga referencia a la opcion deseada" << endl;
        cout << "a. Consultar la lista de Materiales."  << endl;
        cout << "b. Consultar la lista de reservaciones."  << endl;
        cout << "c. Consultar las reservaciones de un material dado."  << endl;
        cout << "d. Consultar las reservaciones de una fecha dada."  << endl;
        cout << "e. Hacer una reservacion."  << endl;
        cout << "f. Terminar."  << endl;


        char resp;
        cin >> resp;
        int maxTemp = 0;
        int totalMaterials = Software::contadorObjetoSoftware + Disco::contadorObjetoDisco + Libro::contadorObjetoLibro;

        if(resp == 'a')
        {
            while (totalMaterials > maxTemp)
            {
                materialArr[maxTemp]->muestraDatos();
                maxTemp++;
            }
        }
        if(resp == 'b')
        {
            while (maxNumberOfReservations > maxTemp)
            {
                if(reservacionesArr[maxTemp].getIdCliente() != 1)
                {
                    reservacionesArr[maxTemp].muestraDatos();
                    maxTemp++;
                } else {maxTemp++;}
            }
        }
        if(resp == 'c')
        {
            int respId;
            cout << "Que material deseas consultar?" << endl;
            cin >> respId;
            while (maxNumberOfReservations > maxTemp)
            {
                if(reservacionesArr[maxTemp].getIdMaterial() == respId)
                {
                   reservacionesArr[maxTemp].muestraDatos();
                }
                maxTemp++;
            }
            if(maxTemp == maxNumberOfReservations - 1)
            {
                cout << "El ID consultado no tiene reservaciones. Intente de nuevo." << endl;
            }
        }
        if(resp == 'd')
        {
            int d, m, a;
            cout << "Que fecha deseas consultar?" << endl;
            cout << "Especifica el dia: " << endl;
            cin >> d;
            cout << "Especifica el mes: " << endl;
            cin >> m;
            cout << "Especifica el anio: " << endl;
            cin >> a;

            Fecha fechaResp(d, m, a);

            while (maxNumberOfReservations > maxTemp)
            {
                if(reservacionesArr[maxTemp].getIdCliente() != 1)
                {
                    int maxTempM = 0;
                    while (totalMaterials > maxTempM)
                    {
                        if(materialArr[maxTempM]->getIdMaterial() == reservacionesArr[maxTemp].getIdMaterial())
                        {
                            int cantPrestamo = materialArr[maxTempM]->cantidadDiasPrestamo();
                            if(reservacionesArr[maxTemp].getFechaReservacion() <= fechaResp && reservacionesArr[maxTemp].calcularFechaFinReserva(cantPrestamo) >= fechaResp )
                            {
                                reservacionesArr[maxTemp].muestraDatos();
                            }
                        }
                        maxTempM++;
                    }
                    maxTemp++;
                } else {maxTemp++;}
            }
        }
        if(resp == 'e')
        {
            int respMatId, respClintId, d, m, a;
            cout << "Que ID de material deseas reservar?" << endl;
            cin >> respMatId;
            cout << "Cual es el ID del cliente que hace la reservacion?" << endl;
            cin >> respClintId;
            cout << "Dia de reservacion" << endl;
            cin >> d;
            cout << "Mes de reservacion" << endl;
            cin >> m;
            cout << "Anio de reservacion" << endl;
            cin >> a;
            int foundM = 0;
            int doneR = 0;

            Fecha fechaResp(d, m, a);
            int maxTempR = 0;

            while (totalMaterials > maxTemp)
            {
                if(materialArr[maxTemp]->getIdMaterial() == respMatId)
                {
                    foundM = 1;
                    int cantPrestamo = materialArr[maxTemp]->cantidadDiasPrestamo();
                    maxTempR = 0;
                    while(maxTempR < maxNumberOfReservations)
                    {
                        if(reservacionesArr[maxTempR].getIdMaterial() == respMatId)
                        {
                            cout << reservacionesArr[maxTempR].getFechaReservacion() << endl;
                            cout << reservacionesArr[maxTempR].calcularFechaFinReserva(cantPrestamo)<< endl;
                            if(reservacionesArr[maxTempR].getFechaReservacion() > fechaResp + cantPrestamo || reservacionesArr[maxTempR].calcularFechaFinReserva(cantPrestamo) < fechaResp )
                            {


                                reservacionesArr[maxTempR + 1].setIdMaterial(respMatId);
                                reservacionesArr[maxTempR + 1].setIdCliente(respClintId);
                                reservacionesArr[maxTempR + 1].setFechaReservacion(fechaResp);
                                maxTemp = totalMaterials + 1;
                                maxTempR = maxNumberOfReservations + 1;
                                doneR = 1;
                                cout << "Reservacion completada." << endl;
                                cout << " " << endl;
                            }
                            else
                            {
                                maxTemp = totalMaterials + 1;
                                maxTempR = maxNumberOfReservations + 1;
                                doneR = -1;
                            }
                        }
                        maxTempR++;
                    }
                }
                maxTemp++;
            }
            if(foundM == 0)
            {
                cout << "El ID del material no existe." << endl;
            }
            if(doneR == -1)
            {
                cout << "La fecha de reservacion esta ocupada." << endl;
            }
        }
        if(resp == 'f')
        {
            cout << "Gracias por usar nuestro servicio, hasta pronto" << endl;
            iterateIndicator--;
        }
        if(resp != 'a' && resp != 'b' && resp != 'c' && resp != 'd' && resp != 'e' && resp != 'f')
        {
            cout << "Respuesta invalida, intenta de nuevo." << endl;
            cout << " " << endl;
        }

    }

    archivoMaterial.close();
    archivoReserva.close();
    return 0;
}
