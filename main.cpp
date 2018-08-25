#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
#include "Libro.h"
#include "Disco.h"
#include "Software.h"
#include "Fecha.h"
#include "Reserva.h"
//Natalia Gonzalez Herrera A01382007
//Programacion Orientada a Objetos
//Tercer Proyecto Parcial
char menu()
{
    char cOpcion;
    cout << "a. Consultar la lista de Materiales\n";
    cout << "b. Consultar la lista de reservaciones\n";
    cout << "c. Consultar las reservaciones de un material dado\n";
    cout << "d. Consular las reservaciones de una fecha dada\n";
    cout << "e. Hacer una reservación\n";
    cout << "f. Terminar\n";
    cout << "Elige una opcion: ";
    cin >> cOpcion;
    return cOpcion;
}

int validarMaterial(Material *arrMaterial[20],int idMaterial, int contM)
{
    for (int i = 0 ; i <= contM -2 ; i++)
    {
        if (arrMaterial[i] -> getID() == idMaterial)
            return i;
    }
    return -1;
}
int buscarReserva(Reserva arrReserva[50], int idMaterial, int contR)
{
    for (int i = 0 ; i <= contR -1 ; i++)
    {
        if (arrReserva[i].getIdMaterial() == idMaterial)
            return i;
    }
    return -1;
}
int main()
{
    //Arreglos base
    Material *arrMaterial[20];
    Reserva arrReserva[50], rEjemplo;
    char cOpcion;
    Fecha fInicio, fDada, fFin, f1, f2, f3;
    int indiceArr, cantidadDias, contador;

    //Datos de Material
    string sTitulo, sAutor, sistemaOper;
    char cTipoMat;
    int idMaterial, numPag, iDuracion, iContM, iContR;

    //Datos de REserva
    int dd, mm, aa, idCliente;

    //Archivos
    string archEntNombre = "Material.txt";
    string archEntNombre2 = "Reservaciones.txt";
    ifstream archMaterial, archReserv;




    //Abrir archivos
    archMaterial.open("Material.txt");
    archReserv.open("Reservaciones.txt");



    //Leer datos del archivo Material
    iContM = 0;
    if (archMaterial.is_open())
    {
        while (!archMaterial.eof())
        {
            archMaterial >> idMaterial >> sTitulo >> cTipoMat;

            switch(cTipoMat)
            {
            case 'L':
                //Libro
                //Numero de Paginas
                archMaterial>> numPag >> sAutor;
                arrMaterial[iContM] = new Libro(sTitulo, idMaterial, sAutor, numPag);

                break;
            case 'D':
                //Disco
                archMaterial >> iDuracion;
                arrMaterial[iContM] = new Disco(sTitulo, idMaterial, iDuracion);

                break;
            case 'S':
                //Software
                archMaterial >> sistemaOper;
                arrMaterial[iContM] = new Software(sTitulo,idMaterial, sistemaOper);

                break;
            }


            iContM ++;
        }


    }

    //Leer datos del archivo Resevaciones
    iContR = 0;
    if (archReserv.is_open())
    {
        while (!archReserv.eof())
        {
            archReserv >> dd >> mm >> aa >> idMaterial >> idCliente;
            Fecha f1(dd, mm, aa);


            arrReserva[iContR].setFecha(f1);
            arrReserva[iContR].setIdCliente(idCliente);
            arrReserva[iContR].setIdMaterial(idMaterial);
            iContR++;
        }
    }
//Menu
    ofstream archSal ("Reservaciones.txt");
    do
    {

        cOpcion = menu();
        cout << endl;

        switch (cOpcion)
        {

        case 'a':
            //a. Consultar la lista de Materiales
            cout << "          MATERIAL\n";
            cout << "---------------------------------\n";
            for (int i = 0; i<= iContM -2 ; i++)
            {
                arrMaterial[i] -> muestra();
                cout << endl << endl;
            }
            break;
        case 'b':
            //b. Consultar la lista de reservaciones
            cout << "      RESERVACIONES\n";
            cout << "-------------------------\n";
            for (int i= 0; i <= iContR -1; i++)
            {
                idMaterial = arrReserva[i].getIdMaterial();
                indiceArr = validarMaterial(arrMaterial, idMaterial, iContM);
                cantidadDias = arrMaterial[indiceArr] -> cantidadDiasPrestamo();
                fFin = arrReserva[i].calculaFechaFinReserva(cantidadDias);

                f1 = arrReserva[i].getFecha();
                cout << arrReserva[i].getIdMaterial() << " " << arrReserva[i].getIdCliente() << " ";
                cout << f1;
                cout << " a " << fFin;
                cout << endl << endl;
            }
            break;
        case 'c':
            //c. Consultar las reservaciones de un material dado
            do
            {
                cout << "Igresa el ID del material: ";
                cin >> idMaterial;

                if (validarMaterial(arrMaterial, idMaterial, iContM)== -1)
                {
                    cout << "ID inexistente\n";
                }

            }
            while (validarMaterial(arrMaterial, idMaterial, iContM)== -1);
            for (int i = 0; i <= iContR -1; i++)
            {
                if (arrReserva[i].getIdMaterial() == idMaterial)
                {
                    indiceArr = validarMaterial(arrMaterial, idMaterial, iContM);
                    cantidadDias = arrMaterial[indiceArr] ->cantidadDiasPrestamo();

                    f1 = arrReserva[i].getFecha();
                    f2 = arrReserva[i].calculaFechaFinReserva(cantidadDias);
                    cout << arrReserva[i].getIdMaterial()<< " " ;
                    cout << "Reservado del ";
                    cout << f1;
                    cout << " hasta " << f2;
                    cout << " " << arrReserva[i].getIdCliente()<< endl << endl;


                }
            }
            break;
        case 'd':
            //d. Consular las reservaciones de una fecha dada
            cout << "Ingresar fecha\n";
            cin >> fDada;
            contador = iContR;
            for (int i = 0; i <= iContR -1 ; i++)
            {


                fInicio = arrReserva[i].getFecha();

                //Calcular fin de reserva
                idMaterial = arrReserva[i].getIdMaterial();
                indiceArr = validarMaterial(arrMaterial, idMaterial, iContM);
                cantidadDias = arrMaterial[indiceArr] -> cantidadDiasPrestamo();
                fFin = arrReserva[i].calculaFechaFinReserva(cantidadDias);

                if(fInicio <= fDada && fDada <= fFin )
                {
                    arrMaterial[indiceArr] -> muestra();
                    cout << endl;
                    contador--;
                }

            }
            if(contador == iContR)
            {
                cout << "No hay reservaciones en esta fecha\n";
            }
            cout << endl;

            break;
        case 'e':
            //e. Hacer una reservación
            cout << "Ingresar ID del Cliente: ";
            cin >> idCliente;
            do
            {
                cout << "Igresa el ID del material: ";
                cin >> idMaterial;
//Validar material
                if (validarMaterial(arrMaterial, idMaterial, iContM)== -1)
                {
                    cout << "ID inexistente\n";
                }

            }
            while (validarMaterial(arrMaterial, idMaterial, iContM)== -1);

            cout << "Ingresar fecha de reservacion\n";
            cin >> fDada;
            //Chechar si el material tiene alguna reserva registrada
            if( (buscarReserva(arrReserva, idMaterial, iContR)) != -1)
            {
                //clacular la fecha de inicio y final de la reserva ya registrada
                contador = buscarReserva(arrReserva, idMaterial, iContR);
                fInicio = arrReserva[contador].getFecha();
                indiceArr = validarMaterial(arrMaterial, idMaterial, iContM);

                 //Calcular la fecha final de la reservacion introducida
                cantidadDias = arrMaterial[indiceArr] -> cantidadDiasPrestamo();
                fFin = fInicio + cantidadDias;
                f3 = fDada + cantidadDias;

            //Checar que no se emplamen las reservaciones ya existentes con la introducida
                while (f3 >= fInicio)
                {
                    cout << "La reservacion deseada se empalma con una reservacion existente, intente de nuevo\n";
                    cout << "Ingresar fecha de reservacion\n";
                    cin >> fDada;
                    f3 = fDada + cantidadDias;
                }

                while(fInicio <= fDada && fDada <= fFin )
                {
                    cout << "El material esta reservado en esa fecha\n";
                    cout << "Ingresar fecha de reservacion\n";
                    cin >> fDada;
                    f3 = fDada + cantidadDias;
                }
            }

            cout << "Reserva registrada\n";

            //Reserva nueva
            rEjemplo.setIdCliente(idCliente);
            rEjemplo.setIdMaterial(idMaterial);
            rEjemplo.setFecha(fDada);

            arrReserva[iContR] = rEjemplo;
            iContR++;

            break;
        case 'f':
            //f. Terminar

            //Actualizar archivo de reservas
            for (int i = 0; i < iContR ; i++)
            {
                f1 = arrReserva[i].getFecha();
                archSal << f1.getDia() << " " << f1.getMes() << " " << f1.getAno()<< " " <<  arrReserva[i].getIdMaterial() << " " << arrReserva[i].getIdCliente() << endl ;
            }
            archSal.close();

            cout << "FIN\n";

            break;
        default:
            cout << "Opcion incorrecta\n";
            cout << endl;
            break;


        }
    }
    while (cOpcion != 'f');


    //Cerrar Archivos
    archMaterial.close();
    archReserv.close();




    return 0;
}
