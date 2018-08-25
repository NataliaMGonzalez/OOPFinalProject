
#include <iostream>
#ifndef Software_H_
#define Software_H_
#include "Material.h"
using namespace std;


class Software : public Material
{
public:

    Software();
    Software(string sTitulo, int idMaterial, string sistemaOper);
    void muestra();
    int cantidadDiasPrestamo();

    void setSistema(string sistemaOper);
    string getSistema();

private:

    string sistemaOper;
};
//constructor default
Software :: Software ()
{
    sTitulo = " ";
    idMaterial = 0;
    sistemaOper = " ";
}
//constructor con parametros
Software :: Software(string sTitulo, int idMaterial, string sistemaOper)
{
    this ->sTitulo = sTitulo;
    this ->idMaterial = idMaterial;
    this ->sistemaOper = sistemaOper;
}

void Software::muestra()
{
    cout << "Software\n";
    cout << idMaterial << " " << sTitulo << " " << sistemaOper;

}

int Software::cantidadDiasPrestamo()
{
    return 1;
}

void Software::setSistema(string sistemaOper)
{
    this -> sistemaOper = sistemaOper;
}

string Software::getSistema()
{
    return sistemaOper;
}
#endif
