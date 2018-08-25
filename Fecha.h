#include <iostream>
#ifndef Fecha_H_
#define Fecha_H_

using namespace std;

int DiasMes(int iM);

class Fecha
{
public:

    Fecha();
    Fecha(int dd, int mm, int aa);

    void setDia(int dd);
    int getDia();

    void setMes(int mm);
    int getMes();

    void setAno(int aa);
    int getAno();

    void setFecha(int dd, int mm, int aa);

    Fecha operator+(int dias);
    bool operator >=(Fecha f1);
    bool operator <=(Fecha f1);
    bool operator < (Fecha f1);
    bool operator > (Fecha f1);
    bool operator ==(Fecha f1);
    friend ostream& operator<<(ostream& os, const Fecha& dt);
    friend istream& operator >> (istream& in, Fecha& dt);

    string nombreMes()const; //private
    bool esBisiesto();

private:

    int dd;
    int mm;
    int aa;

};
Fecha::Fecha()
{
    dd = 0;
    mm = 0;
    aa = 0;
}
Fecha::Fecha(int dd, int mm, int aa)
{
    this -> dd = dd;
    this -> mm = mm;
    this -> aa = aa;
}

void Fecha::setDia(int dd)
{
    this -> dd = dd;
}
int Fecha::getDia()
{
    return dd;
}

void Fecha::setMes(int mm)
{
    this-> mm = mm;
}
int Fecha::getMes()
{
    return mm;
}

void Fecha::setAno(int aa)
{
    this-> aa = aa;
}
int Fecha::getAno()
{
    return aa;
}

void Fecha::setFecha(int dd, int mm, int aa)
{
    this -> dd = dd;
    this -> mm = mm;
    this -> aa = aa;
}

Fecha Fecha::operator+(int dias)
{
    int iDiasMes = DiasMes(mm);
    Fecha diaEntrega;
    int suma;
    suma = dd + dias;
    int diasResp, mesResp, anoResp;
    mesResp = mm;
    anoResp = aa;

    if (suma <= iDiasMes)
    {
        diasResp = suma;
    }
    else if (suma > iDiasMes && mm != 12)
    {
        diasResp = suma - iDiasMes;
        mesResp = mm + 1;
    }
    else if (suma > iDiasMes && mm == 12)
    {
        anoResp = aa + 1;
        mesResp = 1;
        diasResp = suma - iDiasMes;
    }

    diaEntrega.setFecha(diasResp, mesResp, anoResp);
    return diaEntrega;
}
bool Fecha::operator ==(Fecha f1)
{
  if (this->aa == f1.aa && this->mm == f1.mm && this->dd == f1.dd)
 return true;
 else
  return false;

}

bool Fecha :: operator > (Fecha f1)
{

    if (aa > f1.aa)
        return true;
    if (aa == f1.aa && mm > f1.mm)
        return true;
    if (aa == f1.aa && mm == f1.mm && dd > f1.dd)
        return true;
    else return false;

}
bool Fecha :: operator < (Fecha f1)
{

    if (aa < f1.aa)
        return true;
    if (aa == f1.aa && mm < f1.mm)
        return true;
    if (aa == f1.aa && mm == f1.mm && dd < f1.dd)
        return true;
    else return false;

}
 bool Fecha :: operator <= (Fecha f1)
{

    if (aa < f1.aa)
        return true;
    if (aa == f1.aa && mm < f1.mm)
        return true;
    if (aa == f1.aa && mm == f1.mm && dd <= f1.dd)
        return true;
    else return false;

}
 bool Fecha :: operator >= (Fecha f1)
{

     if (aa > f1.aa)
        return true;
    if (aa == f1.aa && mm > f1.mm)
        return true;
    if (aa == f1.aa && mm == f1.mm && dd >= f1.dd)
        return true;
    else return false;

}

string Fecha::nombreMes()const
{
    string nombreMes;
    switch (mm)
    {
    case 1:
        nombreMes = "Ene";
        return nombreMes;
        break;
    case 2:
        nombreMes = "Feb";
        return nombreMes;
        break;
    case 3:
        nombreMes = "Mar";
        return nombreMes;
        break;
    case 4:
        nombreMes = "Abr";
        return nombreMes;
        break;
    case 5:
        nombreMes = "May";
        return nombreMes;
        break;
    case 6:
        nombreMes = "Jun";
        return nombreMes;
        break;
    case 7:
        nombreMes = "Jul";
        return nombreMes;
        break;
    case 8:
        nombreMes = "Ago";
        return nombreMes;
        break;
    case 9:
        nombreMes = "Sept";
        return nombreMes;
        break;
    case 10:
        nombreMes = "Oct";
        return nombreMes;
        break;
    case 11:
        nombreMes = "Nov";
        return nombreMes;
        break;
    case 12:
        nombreMes = "Dic";
        return nombreMes;
        break;
    }
}
bool Fecha::esBisiesto()
{
    if (aa % 4 == 0)
    {
        if (aa % 100 == 0)
        {
            if (aa % 400 == 0)
            {

                cout << aa << " es ano bisiesto";
                return true;
            }
            else
                cout << aa << " no es ano bisiesto";
            return false;
        }
        else
            cout << aa << " es ano bisiesto;";
        return true;
    }
    else
        cout << aa << " no es ano bisiesto";
    return false;
}

ostream& operator<<(ostream& os, const Fecha& dt)
{
string nomMes = dt.nombreMes();
    os << dt.dd << "/" << nomMes << "/" << dt.aa;
    return os;
}

istream& operator >> (istream& in, Fecha& dt)
 {
     cout << "Dia: ";
     in >> dt.dd;
     cout << "Mes: ";
     in >> dt.mm;
     cout << "Ano: ";
     in >> dt.aa;
    return in;
}
int DiasMes(int iM)
{

    if (iM > 0 && iM < 13)
    {
        {
            if (iM == 4 || iM == 6 || iM == 9 || iM == 11)
                return 30;
            else if (iM == 2)
                return 28;
            else
                return 31;
        }
    }
    else
        cout << "Mes incorrecto\n" ;
    return -1;


}
#endif
