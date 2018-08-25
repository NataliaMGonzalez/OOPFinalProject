
#include <iostream>
#ifndef Libro_H_
#define Libro_H_
#include "Material.h"
using namespace std;


class Libro : public Material
{
public:

    Libro();
    Libro(string sTitulo, int idMaterial, string sAutor, int numPags);
    void muestra();
    int cantidadDiasPrestamo();

    void setAutor (string sAutor);
    string getAutor ();

    void setNumPags(int numPags);
    int getNumPags();

private:

    int numPags;
    string sAutor;


};
//constructor default
Libro :: Libro ()
{
    sTitulo = " ";
    idMaterial = 0;
    sAutor = " ";
    numPags = 0;
}
//constructor con parametros
Libro :: Libro(string sTitulo, int idMaterial, string sAutor, int numPags)
{
    this->sTitulo = sTitulo;
    this->idMaterial = idMaterial;
    this->sAutor = sAutor;
    this->numPags = numPags;
}

void Libro::muestra()
{
    cout << "Libro\n";
    cout << idMaterial << " " << sTitulo << " " << sAutor << " " << numPags << " pags";

}

int Libro::cantidadDiasPrestamo()
{
    return 10;
}

void Libro::setAutor (string sAutor)
{
    this-> sAutor = sAutor;
}

string Libro::getAutor ()
{
    return sAutor;
}

void Libro::setNumPags(int numPags)
{
    this-> numPags = numPags;
}

int Libro::getNumPags()
{
    return numPags;
}
#endif
