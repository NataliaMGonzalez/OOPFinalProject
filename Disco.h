#include <iostream>
#ifndef Disco_H_
#define Disco_H_
#include "Material.h"
using namespace std;


class Disco : public Material
{
public:

    Disco();
    Disco(string sTitulo, int idMaterial, int iDuracion);
    void muestra();
    int cantidadDiasPrestamo();

    void setDuracion(int iDuracion);
    int getDuracion();

private:

    int iDuracion;
};
//constructor default
Disco :: Disco ()
{
    sTitulo = " ";
    idMaterial = 0;
    iDuracion = 0;
}
//constructor con parametros
Disco :: Disco(string sTitulo, int idMaterial, int iDuracion)
{
    this->sTitulo = sTitulo;
    this->idMaterial = idMaterial;
    this->iDuracion = iDuracion;
}
    void Disco::muestra()
    {
        cout << "Disco\n";
        cout << idMaterial << " " << sTitulo << " " << iDuracion << "mins";

    }

    int Disco::cantidadDiasPrestamo()
    {
        return 3;
    }

    void Disco::setDuracion(int iDuracion)
    {
        this->iDuracion = iDuracion;
    }
    int Disco::getDuracion()
    {
        return iDuracion;
    }
#endif
