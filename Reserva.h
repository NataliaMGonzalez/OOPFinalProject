
#include <iostream>
#ifndef Reserva_H_
#define Reserve_H_
#include "Fecha.h"
using namespace std;


class Reserva
{
public:

    Reserva();
    Reserva(int idMaterial, int idCliente, Fecha fechaReservacion);

    void setIdCliente(int idCliente);
    int getIdCliente();

    void setIdMaterial (int idMaterial);
    int getIdMaterial();

    void setFecha(Fecha fechaReservacion);
    Fecha getFecha();

    Fecha calculaFechaFinReserva(int cantidadDias);

private:

    int idMaterial;
    int idCliente;
    Fecha fechaReservacion;


};
Reserva::Reserva()
{
    idMaterial = 0;
    idCliente = 0;
    Fecha fechaReservacion (0,0,0);
}

Reserva::Reserva(int idMaterial, int idCliente, Fecha fechaReservacion)
{
    this-> idMaterial = idMaterial;
    this-> idCliente = idCliente;
    this -> fechaReservacion = fechaReservacion;
}

void Reserva::setIdCliente(int idCliente)
{
    this-> idCliente = idCliente;
}
int Reserva::getIdCliente()
{
    return idCliente;
}

void Reserva::setIdMaterial (int idMaterial)
{
    this -> idMaterial = idMaterial;
}
int Reserva::getIdMaterial()
{
    return idMaterial;
}
void Reserva::setFecha(Fecha fechaReservacion)
{
    this->fechaReservacion = fechaReservacion;
}
Fecha Reserva::getFecha()
{
    return fechaReservacion;
}
Fecha Reserva::calculaFechaFinReserva(int cantidadDias)
{
    Fecha finReserva = fechaReservacion + cantidadDias;
    return finReserva;
}

#endif
