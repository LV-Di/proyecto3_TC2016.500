#include <iostream>
#include <string>
#pragma once

class Fecha
{
    public:
        Fecha();
        Fecha(int dd, int mm, int aa);
        void setFecha(int dd, int mm, int aa);
        int getDd(){return dd;};
        int getMm(){return mm;};
        int getAa(){return aa;};

        Fecha operator+(int);
        bool operator>=(Fecha);
        bool operator<=(Fecha);
        bool operator>(Fecha);
        bool operator<(Fecha);
        bool operator==(Fecha);
        friend istream& operator>>(istream&, Fecha&);
        friend ostream& operator<<(ostream&, Fecha);
        std::string getNombreMes();

    private:
        int dd;
        int mm;
        int aa;
};

Fecha::Fecha()
{
    dd = 01;
    mm = 01;
    aa = 2020;
}

Fecha::Fecha(int dd, int mm, int aa)
{
    this->dd = dd;
    this->mm = mm;
    this->aa = aa;
}

int getSerialDate(int y, int m, int d)
{
    m = (m + 9) % 12;
    y = y - m/10;
    int serialDate = 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + ( d - 1 );
    return serialDate;
}
 calcDiasXMes(int mm, int aa)
{
	if(mm == 2)
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

int dayNumber(int dd, int mm, int aa)
{
    int dd_ = 0;
    int aa_ = 1900;
    while (aa_< aa)
    {
        for (int mm_ = 1; mm_ < 13; mm_++)
        {
            dd_ += calcDiasXMes(mm_, aa_);
        }
        aa_++;
    }

    for(int m_ = 1; m_ < mm; m_++)
    {
        dd_ += calcDiasXMes(m_, aa);
    }

    dd_ += dd + 1;

    return dd_;
}
int ddd(int serialDate)
{
    int nDay;
    int nMonth;
    int nYear;
    if (serialDate == 60)
    {
        nDay    = 29;
        nMonth    = 2;
        nYear    = 1900;
    }
    else if (serialDate < 60)
    {
        serialDate++;
    }
    int l = serialDate + 68569 + 2415019;
    int n = int(( 4 * l ) / 146097);
            l = l - int(( 146097 * n + 3 ) / 4);
    int i = int(( 4000 * ( l + 1 ) ) / 1461001);
        l = l - int(( 1461 * i ) / 4) + 31;
    int j = int(( 80 * l ) / 2447);
        nDay = l - int(( 2447 * j ) / 80);
        l = int(j / 11);
        nMonth = j + 2 - ( 12 * l );
        nYear = 100 * ( n - 49 ) + i + l;
    return nDay;
}
int mmm(int serialDate)
{
    int nDay;
    int nMonth;
    int nYear;
    if (serialDate == 60)
    {
        nDay    = 29;
        nMonth    = 2;
        nYear    = 1900;
    }
    else if (serialDate < 60)
    {
        serialDate++;
    }
    int l = serialDate + 68569 + 2415019;
    int n = int(( 4 * l ) / 146097);
            l = l - int(( 146097 * n + 3 ) / 4);
    int i = int(( 4000 * ( l + 1 ) ) / 1461001);
        l = l - int(( 1461 * i ) / 4) + 31;
    int j = int(( 80 * l ) / 2447);
        nDay = l - int(( 2447 * j ) / 80);
        l = int(j / 11);
        nMonth = j + 2 - ( 12 * l );
        nYear = 100 * ( n - 49 ) + i + l;
    return nMonth;
}

int aaa(int serialDate)
{
    int nDay;
    int nMonth;
    int nYear;

    if (serialDate == 60)
    {
        nDay    = 29;
        nMonth    = 2;
        nYear    = 1900;
    }
    else if (serialDate < 60)
    {
        serialDate++;
    }

    int l = serialDate + 68569 + 2415019;
    int n = int(( 4 * l ) / 146097);
            l = l - int(( 146097 * n + 3 ) / 4);
    int i = int(( 4000 * ( l + 1 ) ) / 1461001);
        l = l - int(( 1461 * i ) / 4) + 31;
    int j = int(( 80 * l ) / 2447);
        nDay = l - int(( 2447 * j ) / 80);
        l = int(j / 11);
        nMonth = j + 2 - ( 12 * l );
        nYear = 100 * ( n - 49 ) + i + l;
    return nYear;
}

std::string Fecha::getNombreMes()
{
    if(mm == 1){return "Ene";};
    if(mm == 2){return "Feb";};
    if(mm == 3){return "Mar";};
    if(mm == 4){return "Abr";};
    if(mm == 5){return "May";};
    if(mm == 6){return "Jun";};
    if(mm == 7){return "Jul";};
    if(mm == 8){return "Ago";};
    if(mm == 9){return "Sep";};
    if(mm == 10){return "Oct";};
    if(mm == 11){return "Nov";};
    if(mm == 12){return "Dic";};
}

istream& operator>>(istream &ins, Fecha &Fecha1){
  cout << "Dia: " << endl;
  ins >> Fecha1.dd;
  cout << "Mes: " << endl;
  ins >> Fecha1.mm;
  cout << "Anio: " << endl;
  ins >> Fecha1.aa;
  return ins;
}

ostream& operator << (ostream &out, Fecha Fecha1){
  out << "Dia: " << Fecha1.dd << endl;
  out << "Mes: " << Fecha1.mm << endl;
  out << "Anio: " << Fecha1.aa << endl;
  return out;
}

Fecha Fecha::operator+(int cantDias)
{
    int serialDate = dayNumber(dd, mm, aa) + cantDias;
    int dd_ = ddd(serialDate);
    int mm_ = mmm(serialDate);
    int aa_ = aaa(serialDate);
    Fecha temp(dd_, mm_, aa_);
    return temp;
}
bool Fecha::operator>(Fecha F1)
{
    int dd_, mm_, aa_;
    dd_ = F1.dd;
    mm_ = F1.mm;
    aa_ = F1.aa;
    int iSerialDate = dayNumber(dd, mm, aa);
    int oSerialDate = dayNumber(dd_, mm_, aa_);

    if(iSerialDate > oSerialDate)
    {
        return true;
    } else
    {
        return false;
    }
}
bool Fecha::operator<(Fecha F1)
{
    int dd_, mm_, aa_;
    dd_ = F1.dd;
    mm_ = F1.mm;
    aa_ = F1.aa;
    int iSerialDate = dayNumber(dd, mm, aa);
    int oSerialDate = dayNumber(dd_, mm_, aa_);

    if(iSerialDate < oSerialDate)
    {
        return true;
    } else
    {
        return false;
    }
}
bool Fecha::operator==(Fecha F1)
{
    int dd_, mm_, aa_;
    dd_ = F1.dd;
    mm_ = F1.mm;
    aa_ = F1.aa;
    int iSerialDate = dayNumber(dd, mm, aa);
    int oSerialDate = dayNumber(dd_, mm_, aa_);

    if(iSerialDate == oSerialDate)
    {
        return true;
    } else
    {
        return false;
    }
}
bool Fecha::operator>=(Fecha F1)
{
    int dd_, mm_, aa_;
    dd_ = F1.dd;
    mm_ = F1.mm;
    aa_ = F1.aa;
    int iSerialDate = dayNumber(dd, mm, aa);
    int oSerialDate = dayNumber(dd_, mm_, aa_);

    if(iSerialDate >= oSerialDate)
    {
        return true;
    } else
    {
        return false;
    }
}
bool Fecha::operator<=(Fecha F1)
{
    int dd_, mm_, aa_;
    dd_ = F1.dd;
    mm_ = F1.mm;
    aa_ = F1.aa;
    int iSerialDate = dayNumber(dd, mm, aa);
    int oSerialDate = dayNumber(dd_, mm_, aa_);

    if(iSerialDate <= oSerialDate)
    {
        return true;
    } else
    {
        return false;
    }
}
