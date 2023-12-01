#include <iostream>
#include <vector>
#include "ej.h"

void mostrarMenu(){
    std::cout << "1. Crear Actividad" << std::endl;
    std::cout << "2. Copiar Vector a archivo" << std::endl;
    std::cout << "3. Eliminar" << std::endl;
    std::cout<< " 0.out"<<std::endl;
}

int main(){
    std::vector<Actividad> listaActividades;
    int opcion;
    Actividad actividad;
    do{
        mostrarMenu();
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch(opcion){
            case 1:
                {
                    std::string nombre, lugar, fecha, publico, ponentes, tipoActividad;
                    int aforo,hora;
                    float precio;
                    std::cout << "Ingrese el nombre de la actividad: ";
                    std::cin >> nombre;

                    std::cout << "Ingrese el lugar de la actividad: ";
                    std::cin >> lugar;

                    std::cout << "Ingrese la fecha de la actividad: ";
                    std::cin >> fecha;

                    std::cout << "Ingrese el publico de la actividad: ";
                    std::cin >> publico;

                    std::cout << "Ingrese el aforo de la actividad: ";
                    std::cin >> aforo;

                    std::cout << "Ingrese los ponentes de la actividad: ";
                    std::cin >> ponentes;

                    std::cout << "Ingrese el precio de la actividad: ";
                    std::cin >> precio;

                    std::cout << "Ingrese la hora de la actividad: ";
                    std::cin >> hora;

                    std::cout << "Ingrese el tipo de actividad: ";
                    std::cin >> tipoActividad;

                    actividad.SetNombre(nombre);
                    actividad.SetLugar(lugar);
                    actividad.SetFecha(fecha);
                    actividad.SetPublico(publico);
                    actividad.SetAforo(aforo);
                    actividad.SetPonentes(ponentes);
                    actividad.SetPrecio(precio);
                    actividad.SetHora(hora);
                    actividad.SetTipoActividad(tipoActividad);

                    listaActividades.push_back(actividad);
                    break;
                }
            case 2:
                {
                    std::string archivo;
                    std::cout << "Ingrese el nombre del archivo en el que se guardaran las actividades: ";
                    std::cin >> archivo;
                    actividad.copiarVector(listaActividades, archivo);
                    break;
                }
            case 3:
                {
                    std::string nombre;
                    std::cout<<"Introduzca el nombre del archivo a borrar";
                    std::cin>>nombre;
                    std::string nombre1;
                    std::cout<<"Introduzca el nombre de la actividad a borrar";
                    std::cin>>nombre1;
                    actividad.eliminarActividad(nombre,nombre1);
                    break;
                }
            default:
                std::cout << "Opcion invalida, intente nuevamente." << std::endl;
                break;
            
        }
    }while(opcion > 0);

    return 0;
}