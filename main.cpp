#include <iostream>
#include <string>

using namespace std;



class Material
{
public:
 virtual void muestraDatos(); //Virtual por ser una clase abstracta
 virtual int cantidadDiasPrestamo();
private:
    int idMaterial;
    std::string titulo;
};

class Libro : public Material
{
public:
    int numPag;
    std::string autor;
private:
    int numPag;
    std::string autor;
};

class Disco : public Material
{
private:
    int duracion;
    std::string genero;
};

class Software : public Material
{
private:
    int version;
    std::string so;
};

class Fecha
{
public:
    Fecha();
    Fecha(int dd, int mm, int aa);
    void setFecha(int dd, int mm, int aa);
    int getDd(){return dd;};
    int getMm(){return mm;};
    int getAa(){return aa;};


    Fecha operator+();
    Fecha operator>=();
    Fecha operator<=();
    Fecha operator>();
    Fecha operator<();
    Fecha operator==();
    //Fecha operator>>();
    //Fecha operator<<();


private:
    int dd;
    int mm;
    int aa;
};

int calcDiasXMes(int mm, int aa)
{
	if( mm == 2)
	{
		if((aa%400==0) || (aa%4==0 && aa%100!=0))
			return 29;
		else
			return 28;
	}
	else if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 ||mm == 10 || mm == 12)
		return 31;
	else
		return 30;
}

Fecha Fecha::operator+()
{
    int dd_;
    int mm_;
    int aa_;

    int diasM = calcDiasXMes(mm, aa);

    int diasA;
    for (int i; i < 12 ; i++)
    {
        diasA += calcDiasXMes(i, aa);
    }

    if(mm == 12 & dd == 31)
    {
        aa_ = aa + 1;
        Fecha temp(1, 1, aa_);
        return temp;
    }
    if (dd == diasM) {
        mm_ = 1 + mm;
        dd_ = 0;
    }
    else {
        mm_ = mm;
        dd_ = 1 + dd;
    }
    Fecha temp(dd_, mm_, aa_);
    return temp;
}

class Reserva
{
public:
    Fecha calcularFechaFinReserva(int cantDias);

private:
    int idMaterial;
    int idCliente;
    Fecha fechaReservacion;
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
    //AAA
}
