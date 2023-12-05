#include <iostream>
#include <vector>
#include "crearActividadH.h"
void mostrarMenu(){
    std::cout << "1. Crear Actividad" << std::endl;
    std::cout << "2. Eliminar" << std::endl;
    std::cout << "3. Buscar" << std::endl;
    std::cout<< " 0. Salir"<<std::endl;
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

                    std::cout<<"Nombre:"<<actividad.GetNombre()<<std::endl;
                    std::cout<<"Lugar:"<<actividad.GetLugar()<<std::endl;
                    std::cout<<"Fecha:"<<actividad.GetFecha()<<std::endl;
                    std::cout<<"Publico:"<<actividad.GetPublico()<<std::endl;
                    std::cout<<"Aforo:"<<actividad.GetAforo()<<std::endl;
                    std::cout<<"Ponentes:"<<actividad.GetPonentes()<<std::endl;
                    std::cout<<"Precio:"<<actividad.GetPrecio()<<std::endl;
                    std::cout<<"Hora:"<<actividad.GetHora()<<std::endl;
                    std::cout<<"Tipo actividad:"<<actividad.GetTipoActividad()<<std::endl;

                    listaActividades.push_back(actividad);                    
                    actividad.copiarVector(listaActividades,"Actividades.txt");
                    std::cout<<"Fichero creado con el nombre Actividades.txt"<<std::endl;
                    break;
                }
            case 2:
                {
                    std::string nombre;
                    std::cout<<"Introduzca el nombre del archivo a borrar "<<std::endl;
                    std::cin>>nombre;
                    std::string nombre1;
                    std::cout<<"Introduzca el nombre de la actividad a borrar "<<std::endl;
                    std::cin>>nombre1;
                    actividad.eliminarActividad(nombre,nombre1);
                    break; 
                }
            case 3:
                {
                    std::string nombre;
                    std::cout<<"Introduzca el nombre del archivo a buscar "<<std::endl;
                    std::cin>>nombre;
                    std::string nombre1;
                    std::cout<<"Introduzca el nombre de la actividad a buscar"<<std::endl;
                    std::cin>>nombre1;
                    actividad.busquedaActividad(nombre,nombre1);

                    break;
                }
            default:
                std::cout << "Opcion invalida, intente nuevamente." << std::endl;
                break;
            
        }
    }while(opcion > 0);

    return 0;
}