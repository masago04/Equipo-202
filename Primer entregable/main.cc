#include <iostream>
#include <string>
#include "person.h"


int main() {
    std::string dniMain;
    std::string nombre;
    std::string apellidos;
    std::string carrera;
    int curso;
    std::string facultad;
    int opcion;
    std::string nombre_actividad;
    DirectorAcademico directorAc("Director"); //clase ya creada
    Organizador organizador("Organizador"); //clase ya creada
    GestorDeUsuarios gestor("Gestor");
    Usuario user("usuario");

    std::cout<<"BIENVENIDO AL GESTOR DE ACTIVIDADES DE LA UCO"<<std::endl;
    std::cout << "Ingrese su DNI: ";
    std::getline(std::cin, dniMain);


    if(dniMain==directorAc.GetDni()){
        std::cout<<"BIENVENIDO ESTAS EN MODO DIRECTOR ACADÉMICO"<<std::endl;
        std::cout << "Menu de opciones:"<<std::endl;
        std::cout << "1. Activar nueva actividad."<<std::endl;
        std::cout << "2. Eliminar actividad."<<std::endl;

        do{
            std::cout << "Seleccione una opcion: ";
            std::cin >> opcion;
            std::cin.ignore();
            switch (opcion) {
                case 1:
                    directorAc.activarActividad();
                    std::cout<<"Actividad creada con exito"<<std::endl;
                    break;
                case 2:
                    std::cout<<"INtroduzca el nombre de la actividad a eliminar: ";
                    std::getline(std::cin, nombre_actividad);
                    directorAc.eliminarActividad(nombre_actividad);
                    std::cout<<"Actividad borrada con exito"<<std::endl;
                    break;
                default:
                    std::cout << "Opción no válida.\n";
                    break;
                }
        }while (opcion>0);

    } 

    else if(dniMain == organizador.GetDni()){
        std::cout<<"BIENVENIDO ESTAS EN MODO ORGANIZADOR"<<std::endl;
        std::cout << "Menu de opciones:"<<std::endl;
        std::cout << "1. Lanzar idea."<<std::endl;

        do{
            std::cout << "Seleccione una opcion: ";
            std::cin >> opcion;
            std::cin.ignore();
            switch (opcion) {
                case 1:
                    organizador.lanzarIdea();
                    std::cout<<"Idea lanzada con exito"<<std::endl;
                    break;
                default:
                    std::cout << "Opción no válida.\n";
                    break;
            }
        }while (opcion>0);
    }


    else if (dniMain == gestor.GetDni()) {


        std::cout<<"BIENVENIDO ESTAS EN MODO GESTOR DE USUARIOS"<<std::endl;
        std::cout << "Menu de opciones:"<<std::endl;
        std::cout << "1. Anadir usuario."<<std::endl;

        do{
            std::cout << "Seleccione una opcion: ";
            std::cin >> opcion;
            std::cin.ignore();
                switch (opcion) {
                    case 1:
                        std::cout<<"Introduzca el dni del nuevo usuario"<<std::endl;
                        std::cin>>dniMain;
                        std::cout<<"Introduzca el nombre del nuevo usuario"<<std::endl;
                        std::cin>>nombre;
                        std::cout<<"Introduzca el apellido del nuevo usuario"<<std::endl;
                        std::cin>>apellidos;
                        std::cout<<"Introduzca la carrera del nuevo usuario"<<std::endl;
                        std::cin>>carrera;
                        std::cout<<"Introduzca el curso del nuevo usuario"<<std::endl;
                        std::cin>>curso;
                        std::cin.ignore();
                        std::cout<<"Introduzca la facultad del nuevo usuario"<<std::endl;
                        std::cin>>facultad;
                        std::cout<<"\n";
                        //user(dniMain,nombre,apellidos,carrera,curso,facultad);
                        user.SetDni(dniMain);
                        user.SetNombre(nombre);
                        user.SetApellidos(apellidos);
                        user.SetCarrera(carrera);
                        user.SetFacultad(facultad);
                        user.SetCurso(curso);

                        gestor.anadirUsuario(user);
                        std::cout<<"Usuario introducido con exito"<<std::endl;
                        break;
                    default:
                        std::cout << "Opción no válida.\n";
                        break;
                }
        }while (opcion>0);

    }




    else {
        
        bool comprobarAcceso;
        comprobarAcceso=user.accederWeb(dniMain, user);
        if(comprobarAcceso==true){

            std::cout<<"BIENVENIDO ESTAS EN MODO USUARIO"<<std::endl;
            std::cout << "Menu de opciones:"<<std::endl;
            std::cout << "1. Preinscripcion actividad."<<std::endl;
            std::cout << "2. Inscripcion y pago."<<std::endl;

            do{
                std::cout << "Seleccione una opcion: ";
                std::cin >> opcion;
                std::cin.ignore();
                switch (opcion){
                    case 1:
                        std::cout << "Introduzca el nombre de la actividad: ";
                        std::getline (std::cin, nombre_actividad);
                        user.PreInscripcion(nombre_actividad, user);
                        break;
                    case 2:
                        std::cout << "Introduzca el nombre de la actividad: ";
                        std::getline (std::cin, nombre_actividad);
                        user.InscripcionyPago(nombre_actividad, user);
                        break;
                    default:
                        std::cout << "Opción no válida.\n";
                        break;
                    }
            }while (opcion>0);
        }
        else{
            printf("\nUsted no está registrado en el sistema");
        }
    }

    return 0;
}