#include <iostream>
#ifndef Material_H_
#define Material_H_

using namespace std;


class Material
{
public:

    Material();
    Material(string sTitulo, int idMaterial);

    virtual void muestra() = 0;
    virtual int cantidadDiasPrestamo () = 0;

    void setTitulo(string sTitulo);
    string getTitulo();

    void setId (int idMaterial);
    int getID();

protected:
    string sTitulo;
    int idMaterial;


};
//constructor default
Material :: Material ()
{
    sTitulo = " ";
    idMaterial = 0;
}
//constructor
Material :: Material(string sTitulo, int idMaterial)
{
    this->sTitulo = sTitulo;
    this->idMaterial = idMaterial;
}

void Material::setTitulo(string sTitulo)
{
    this ->sTitulo = sTitulo;
}

string Material :: getTitulo()
{
    return sTitulo;
}
void Material::setId (int idMaterial)
{
    this ->idMaterial = idMaterial;
}
int Material::getID()
{
    return idMaterial;
}

#endif
