#include <iostream>
#include <cstdlib>
#include <string>
#include "person.h"
void menuDirectorAcademico(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user);
void menuGestor(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user);
void menuOrganizador(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user);
void menuUsuario(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user, std::string dniLogin);
void menuVisitante(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user, std::string dniLogin);
void inicioVisitante(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user, std::string dniLogin);


void menuLogin(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user){
    system("clear");

    std::string dniLogin;
    std::cout<<"BIENVENIDO AL GESTOR DE ACTIVIDADES DE LA UCO"<<std::endl;
    std::cout << "Ingrese su DNI: ";
    std::getline(std::cin, dniLogin);
    if(dniLogin==da.GetDni()){
        menuDirectorAcademico(da, gestor, organizador, user);
    }
    else if(dniLogin==gestor.GetDni()){
        menuGestor(da, gestor, organizador, user);
    }
    else if(dniLogin==organizador.GetDni()){
        menuOrganizador(da, gestor, organizador, user);
    }
    else if(dniLogin=="Visitante"){
        inicioVisitante(da, gestor, organizador, user, dniLogin);
    }
    else{
        menuUsuario(da, gestor, organizador, user, dniLogin);
    }
}
void menuDirectorAcademico(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user){

    int opcion;
    std::string nombre_actividad, publico;
    bool comprobarPublicitarCorreo;
    std::cout<<"\nBIENVENIDO ESTAS EN MODO DIRECTOR ACADÉMICO"<<std::endl;
        std::cout << "Menu de opciones:"<<std::endl;
        std::cout << "1. Activar nueva actividad."<<std::endl;
        std::cout << "2. Eliminar actividad."<<std::endl;
        std::cout << "3. Listar asistentes a una actividad."<<std::endl;
        std::cout << "4. Listar actividades."<<std::endl;
        std::cout << "5. Publicitar actividad"<<std::endl;
        std::cout << "6. Pasar actividad al historico"<<std::endl;
        std::cout << "7. Listar actividades del historico."<<std::endl;
        std::cout << "8. Volver al menu de inicio de sesion." <<std::endl;
        std::cout << "0. Salir del programa."<<std::endl;
        do{
            std::cout << "\nSeleccione una opcion: ";
            std::cin >> opcion;
            std::cin.ignore();
            switch (opcion) {
                case 1:
                    if(da.activarActividad()==false){
                        std::cout<<"\nError en la creacion de la actividad"<<std::endl;
                    }
                    else{
                        std::cout<<"\nActividad creada con exito"<<std::endl;
                    }
                    std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                    getchar();
                    system("clear");
                    menuDirectorAcademico(da, gestor, organizador, user);
                    break;
                case 2:
                    std::cout<<"Introduzca el nombre de la actividad a eliminar: ";
                    std::getline(std::cin, nombre_actividad);
                    da.eliminarActividad(nombre_actividad);
                    std::cout<<"Actividad borrada con exito"<<std::endl;
                    std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                    getchar();
                    system("clear");
                    menuDirectorAcademico(da, gestor, organizador, user);
                    break;
                
                case 3:
                    std::cout<<"Introduzca el nombre de la actividad: ";
                    std::getline(std::cin, nombre_actividad);
                    std::cout<<"Asistentes:"<<std::endl;
                    consultarAsistentes(nombre_actividad);
                    std::cout<<"\n";
                    std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                    getchar();
                    system("clear");
                    menuDirectorAcademico(da, gestor, organizador, user);

                    break;

                case 4: 
                    listarActividades();
                    std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                    getchar();
                    system("clear");
                    menuDirectorAcademico(da, gestor, organizador, user);

                    break;

                case 5:
                    std::cout<<"Introduzca el nombre de la actividad a publicitar: ";
                    std::getline(std::cin, nombre_actividad);
                    std::cout<<"Introduzca el publico al que esta dirigido: ";
                    std::getline(std::cin, publico);
                    comprobarPublicitarCorreo=da.publicitarActividad(nombre_actividad, publico);
                    if(comprobarPublicitarCorreo==true){
                        std::cout<<"Actividad "<<nombre_actividad<<" publicitado por correo con exito"<<std::endl;
                    }
                    else{
                        std::cout<<"Actividad no publicitada"<<std::endl;
                    }
                    std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                    getchar();
                    system("clear");
                    menuDirectorAcademico(da, gestor, organizador, user);
                    break;

                case 6:
                    std::cout<<"Introduzca el nombre de la actividad a pasar al historico: ";
                    std::getline(std::cin, nombre_actividad);
                    da.pasarActividadHistorico(nombre_actividad);
                    std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                    getchar();
                    system("clear");
                    menuDirectorAcademico(da, gestor, organizador, user);
                    break;
                
                case 7:
                    listarActividadesHistorico();
                    std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                    getchar();
                    system("clear");
                    menuDirectorAcademico(da, gestor, organizador, user);
                    break;

                case 8:
                    menuLogin(da, gestor, organizador, user);
                    break;

                case 0:
                    printf("\nCerrando sesión");
                    printf("\nApagando el sistema\n");
                    exit(EXIT_SUCCESS);

                default:
                    std::cout << "Opción no válida.\n";
                    break;
                }
        }while (opcion>=0);
}

void menuGestor(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user){
    int opcion, curso;
    std::string dni, nombre, apellido, carrera, facultad, correo;
 std::cout<<"\nBIENVENIDO ESTAS EN MODO GESTOR DE USUARIOS"<<std::endl;
        std::cout << "Menu de opciones:"<<std::endl;
        std::cout << "1. Anadir usuario."<<std::endl;
        std::cout << "2. Volver al menu de inicio de sesion." <<std::endl;
        std::cout << "0. Salir del programa."<<std::endl;        
        do{
            std::cout << "Seleccione una opcion: ";
            std::cin >> opcion;
            std::cin.ignore();
                switch (opcion) {
                    case 1:
                        std::cout<<"Introduzca el dni del nuevo usuario"<<std::endl;
                        std::cin>>dni;
                        std::cout<<"Introduzca el nombre del nuevo usuario"<<std::endl;
                        std::cin>>nombre;
                        std::cout<<"Introduzca el apellido del nuevo usuario"<<std::endl;
                        std::cin>>apellido;
                        std::cout<<"Introduzca la carrera del nuevo usuario"<<std::endl;
                        std::cin>>carrera;
                        std::cout<<"Introduzca el curso del nuevo usuario"<<std::endl;
                        std::cin>>curso;
                        std::cin.ignore();
                        std::cout<<"Introduzca la facultad del nuevo usuario"<<std::endl;
                        std::cin>>facultad;
                        std::cout<<"Introduzca el correo del nuevo usuario"<<std::endl;
                        std::cin>>correo;
                        std::cout<<"\n";
                        //user(dniMain,nombre,apellidos,carrera,curso,facultad);
                        user.SetDni(dni);
                        user.SetNombre(nombre);
                        user.SetApellidos(apellido);
                        user.SetCarrera(carrera);
                        user.SetFacultad(facultad);
                        user.SetCurso(curso);
                        user.SetCorreo(correo);
                        gestor.anadirUsuario(user);
                        std::cout<<"Usuario introducido con exito"<<std::endl;
                        std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                        getchar();
                        getchar();
                        system("clear");
                        menuGestor(da, gestor, organizador, user);
                        break;

                    case 2:
                        menuLogin(da, gestor, organizador, user);

                        break;

                    case 0:
                        printf("\nCerrando sesión");
                        printf("\nApagando el sistema\n");
                        exit(EXIT_SUCCESS);
                    default:
                        std::cout << "Opción no válida.\n";
                        break;
                }
        }while (opcion>0);
}


void menuOrganizador(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user){
    int opcion;
        std::cout<<"\nBIENVENIDO ESTAS EN MODO ORGANIZADOR"<<std::endl;
        std::cout << "Menu de opciones:"<<std::endl;
        std::cout << "1. Lanzar idea."<<std::endl;
        std::cout << "2. Volver al menu de inicio de sesion." <<std::endl;
        std::cout << "0. Salir del programa."<<std::endl; 

        do{
            std::cout << "Seleccione una opcion: ";
            std::cin >> opcion;
            std::cin.ignore();
            switch (opcion) {
                case 1:
                    organizador.lanzarIdea();
                    std::cout<<"Idea lanzada con exito"<<std::endl;
                    std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                    getchar();
                    system("clear");
                    menuOrganizador(da, gestor, organizador, user);
                    break;
                case 2:
                    menuLogin(da, gestor, organizador, user);

                    break;

                case 0:
                    printf("\nCerrando sesión");
                    printf("\nApagando el sistema\n");
                    exit(EXIT_SUCCESS);
                default:
                    std::cout << "Opción no válida.\n";
                    break;
            }
        }while (opcion>0);
}

void menuUsuario(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user, std::string dniLogin){
    int opcion;
    std::string nombre_actividad;
    bool comprobarAcceso;

        comprobarAcceso=user.accederWeb(dniLogin, user);
        if(comprobarAcceso==true){

            std::cout<<"\nBIENVENIDO ESTAS EN MODO USUARIO"<<std::endl;
            std::cout << "Menu de opciones:"<<std::endl;
            std::cout << "1. Preinscripcion actividad."<<std::endl;
            std::cout << "2. Inscripcion y pago."<<std::endl;
            std::cout << "3. Listar actividades."<<std::endl;
            std::cout << "4. Cancelar inscripcion."<<std::endl;
            std::cout << "5. Leer correos."<<std::endl;
            std::cout << "6. Listar actividades del historico."<<std::endl;
            std::cout << "7. Volver al menu de inicio de sesion." <<std::endl;
            std::cout << "0. Salir del programa."<<std::endl; 
            do{
                std::cout << "Seleccione una opcion: ";
                std::cin >> opcion;
                std::cin.ignore();
                switch (opcion){
                    case 1:
                        std::cout << "Introduzca el nombre de la actividad: ";
                        std::getline (std::cin, nombre_actividad);
                        user.PreInscripcion(nombre_actividad, user);
                        std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                        getchar();
                        system("clear");
                        menuUsuario(da, gestor, organizador, user,dniLogin);
                        break;
                    case 2:
                        std::cout << "Introduzca el nombre de la actividad: ";
                        std::getline (std::cin, nombre_actividad);
                        user.InscripcionyPago(nombre_actividad, user);
                        std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                        getchar();
                        system("clear");
                        menuUsuario(da, gestor, organizador, user,dniLogin);
                        break;
                    case 3: 
                        listarActividades();
                        std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                        getchar();
                        system("clear");
                        menuUsuario(da, gestor, organizador, user,dniLogin);
                        break;
                    case 4:
                        bool comprobarCancelacion;
                        std::cout << "Introduzca el nombre de la actividad: ";
                        std::getline (std::cin, nombre_actividad);
                        comprobarCancelacion=user.cancelarInscripcion(nombre_actividad, user);
                        if(comprobarCancelacion==true){
                            std::cout<<"Cancelacion realizada con exito"<<std::endl;
                        }
                        else{
                            std::cout<<"Usted no esta inscrito en dicha actividad"<<std::endl;
                        }
                        std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                        getchar();
                        system("clear");
                        menuUsuario(da, gestor, organizador, user,dniLogin);
                        break;

                    case 5:
                        std::cout<<"Bandeja de entrada de "<< user.GetDni()<<std::endl;
                        user.leerCorreos(user.GetDni());
                        std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                        getchar();
                        system("clear");
                        menuUsuario(da, gestor, organizador, user,dniLogin);
                        break;


                    case 6:
                        listarActividadesHistorico();
                        std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                        getchar();
                        system("clear");
                        menuUsuario(da, gestor, organizador, user,dniLogin);
                        break;

                    case 7:
                        menuLogin(da, gestor, organizador, user);
                        break;

                    case 0:
                        printf("\nCerrando sesión");
                        printf("\nApagando el sistema\n");
                        exit(EXIT_SUCCESS);
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

void inicioVisitante(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user, std::string dniLogin){
    std::string dni, nombre, apellido, carrera, facultad, nombre_actividad, correo;
    int curso, opcion;
    bool comprobarAccesoVisitante;
    std::cout<<"Bienvenido al menu Visitante"<<std::endl;
    std::cout<<"En primer lugar introduzca sus datos para poder hacer uso de nuestros servicios:"<<std::endl;
    std::cout<<"Dni: ";
    std::getline(std::cin, dni);
    comprobarAccesoVisitante=comprobarDniVisitante(dni, user);
    if(comprobarAccesoVisitante==false){
        std::cout<<"Nombre: ";
        std::getline(std::cin, nombre);
        std::cout<<"Apellido: ";
        std::getline(std::cin, apellido);
        std::cout<<"Carrera: ";
        std::getline(std::cin, carrera);
        std::cout<<"Facultad: ";
        std::getline(std::cin, facultad);
        std::cout<<"Curso: ";
        std::cin>>curso;
        std::cin.ignore();
        std::cout<<"Correo: ";
        std::getline(std::cin, correo);
        std::cin.ignore();
        user.SetDni(dni);
        user.SetNombre(nombre);
        user.SetApellidos(apellido);
        user.SetCarrera(carrera);
        user.SetFacultad(facultad);
        user.SetCurso(curso);
        user.SetCorreo(correo);
        user.anadirVisitante(user);

    }
    else{
        std::cout<<"Usted ya esta registrado en nuestra base de datos"<<std::endl;
    }
    std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
    getchar();
    system("clear");
    menuVisitante(da, gestor, organizador, user, dni);
}



void menuVisitante(DirectorAcademico da, GestorDeUsuarios gestor, Organizador organizador, Usuario user, std::string dniLogin){
    std::string nombre_actividad;
    int opcion;
    
    std::cout<<"BIENVENIDO ESTAS EN MODO VISITANTE"<<std::endl;
    std::cout << "Menu de opciones:"<<std::endl;
    std::cout << "1. Preinscripcion actividad."<<std::endl;
    std::cout << "2. Inscripcion y pago."<<std::endl;
    std::cout << "3. Listar actividades."<<std::endl;
    std::cout << "4. Cancelar inscripcion."<<std::endl;
    std::cout << "5. Volver al menu de inicio de sesion." <<std::endl;
    std::cout << "0. Salir del programa."<<std::endl;
    do{
                std::cout << "Seleccione una opcion: ";
                std::cin >> opcion;
                std::cin.ignore();
                switch (opcion){
                    case 1:
                        std::cout << "Introduzca el nombre de la actividad: ";
                        std::getline (std::cin, nombre_actividad);
                        user.PreInscripcion(nombre_actividad, user);
                        std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                        getchar();
                        system("clear");
                        menuVisitante(da, gestor, organizador, user,dniLogin);
                        break;
                    case 2:
                        std::cout << "Introduzca el nombre de la actividad: ";
                        std::getline (std::cin, nombre_actividad);
                        user.InscripcionyPago(nombre_actividad, user);
                        std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                        getchar();
                        system("clear");
                        menuVisitante(da, gestor, organizador, user,dniLogin);
                        break;
                    case 3: 
                        listarActividades();
                        std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                        getchar();
                        system("clear");
                        menuVisitante(da, gestor, organizador, user,dniLogin);
                        break;
                    case 4:
                        bool comprobarCancelacion;
                        std::cout << "Introduzca el nombre de la actividad: ";
                        std::getline (std::cin, nombre_actividad);
                        comprobarCancelacion=user.cancelarInscripcion(nombre_actividad, user);
                        if(comprobarCancelacion==true){
                            std::cout<<"Cancelacion realizada con exito"<<std::endl;
                        }
                        else{
                            std::cout<<"Usted no esta inscrito en dicha actividad"<<std::endl;
                        }
                        std::cout << "\n\nPresiona cualquier tecla para continuar..." << std::endl;
                        getchar();
                        system("clear");
                        menuVisitante(da, gestor, organizador, user,dniLogin);
                        break;
                    
                    case 5:
                        menuLogin(da, gestor, organizador, user);
                        break;

                    case 0:
                        printf("\nCerrando sesión");
                        printf("\nApagando el sistema\n");
                        exit(EXIT_SUCCESS);
                    default:
                        std::cout << "Opción no válida.\n";
                        break;
                    }
            }while (opcion>0);
        }







int main() {
    /*std::string dniMain;
    std::string nombre;
    std::string apellidos;
    std::string carrera;
    int curso;
    std::string facultad;
    int opcion;
    std::string nombre_actividad;*/
    DirectorAcademico directorAc("Director"); //clase ya creada
    Organizador organizador("Organizador"); //clase ya creada
    GestorDeUsuarios gestor("Gestor");
    Usuario user("usuario");

    menuLogin(directorAc, gestor, organizador, user);

    return 0;
}