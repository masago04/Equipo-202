#include "person.h"
#include <fstream>
#include <string.h>
#define MAX 264
/*void Usuario::PreInscripcion(std::string nombreActividad){
    Usuario u;
    std::string nombre, dni, carrera, apellidos, facultad;
    int curso;
    std::ofstream fichero(nombreActividad);
    std::cout<<"Introduzca sus datos: "<<std::endl;
    std::cout<<"DNI: ";
    std::cin>>dni;
    std::cout<<"Nombre:";
    std::cin>>nombre;
    std::cout<<"Apellidos: ";
    std::cin>>apellidos;
    std::cout<<"Carrera: ";
    std::cin>>carrera;
    std::cout<<"Facultad: ";
    std::cin>>facultad;
    std::cout<<"Curso: ";
    std::cin>>curso;

    u.SetNombre(nombre);
    u.SetApellidos(apellidos);
    u.SetDni(dni);
    u.SetCarrera(carrera);
    u.SetCurso(curso);
    u.SetFacultad(facultad);

    fichero<<u.GetDataUser(u);
    std::cout<<"Usuario con dni "<<u.GetDni()<<" preinscrito con exito"<<std::endl;
    fichero.close();
}*/



bool Usuario::PreInscripcion(std::string nombreActividad){
    Usuario u;
    std::string nombre, dni, carrera, apellidos, facultad;
    char dniFichero[MAX], nombreAlumnoActividad[MAX], apellidosAlumnoActividad[MAX], carreraAlumnoActividad[MAX], facultadAlumnoActividad[MAX];
    int cursoAlumnoActividad;
        char nombreActividadLocal[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];

    int curso;
    FILE * ficheroActividades;
    ficheroActividades=fopen("Actividades.txt", "r");
    if(ficheroActividades==NULL){
        printf("\nError al abrir el fichero");
        exit(EXIT_FAILURE);
    }
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombreActividadLocal, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        if(strcmp(nombreActividadLocal, nombreActividad.c_str())==0){
                FILE* ficheroPreinscritos;
            std::cout<<"Introduzca sus datos: "<<std::endl;
            std::cout<<"DNI: ";
            std::cin>>dni;
            std::cout<<"Nombre:";
            std::cin>>nombre;
            std::cout<<"Apellidos: ";
            std::cin>>apellidos;
            std::cout<<"Carrera: ";
            std::cin>>carrera;
            std::cout<<"Facultad: ";
            std::cin>>facultad;
            std::cout<<"Curso: ";
            std::cin>>curso;
            u.SetNombre(nombre);
            u.SetApellidos(apellidos);
            u.SetDni(dni);
            u.SetCarrera(carrera);
            u.SetCurso(curso);
            u.SetFacultad(facultad);

            ficheroPreinscritos=fopen(strcat((char*)nombreActividad.c_str(), "Preinscritos.txt"), "a+");
            if(ficheroPreinscritos==NULL){
                printf("\nError al abrir el fichero");
                exit(EXIT_FAILURE);
            }
            while(fscanf(ficheroPreinscritos, "%s %s %s %s %s %d", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, &cursoAlumnoActividad)==6){
                if(strcmp(dniFichero, u.GetDni().c_str())==0){
                    printf("\nEL alumno con dni %s ya esta preinscrito en dicha actividad", u.GetDni().c_str());
                    fclose(ficheroActividades);
                    fclose(ficheroPreinscritos);
                    return false;
                }
            }
            fprintf(ficheroPreinscritos, "%s %s %s %s %s %d\n", (u.GetDni()).c_str(), (u.GetNombre()).c_str(), (u.GetApellidos()).c_str(), (u.GetCarrera()).c_str(), (u.GetFacultad()).c_str(), u.GetCurso());

        

            std::cout<<"Usuario con dni "<<u.GetDni()<<" preinscrito con exito"<<std::endl;
            fclose(ficheroActividades);
            fclose(ficheroPreinscritos);
            return true;

        }
    }
    printf("\nLa actividad no existe");
    fclose(ficheroActividades);
    return false;
    

}

std::string Usuario::GetDataUser(Usuario u){
    std::string cad;
    cad+="Dni: " + u.GetDni() + "\n" + "Nombre: " + u.GetNombre() + "\n"+ "Apellidos: " + u.GetApellidos() + "\n" + "Carrera: " + carrera_ + "\n"+ "Facultad: " + facultad_ + "\n" + "Curso: " + std::to_string(curso_);
    return cad;
}


bool Usuario::pagarActividad(std::string nombreActividad, Usuario u1){
    Usuario usuarioEncontrado=u1;
    FILE *ficheroActividades;
    char nombre[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    std::string nombreActividadaux;



    ficheroActividades=fopen("Actividades.txt", "r");
    if(ficheroActividades==NULL){
        printf("\nError al abrir el fichero Actividades");
        exit(EXIT_FAILURE);
    }
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){

        if(nombreActividad==nombre){//Si la actividad existe
            FILE *ficheroActividadEncontrada;
            char dniFichero[MAX], nombreAlumnoActividad[MAX], apellidosAlumnoActividad[MAX], carreraAlumnoActividad[MAX], facultadAlumnoActividad[MAX];
            int cursoAlumnoActividad;

            ficheroActividadEncontrada=fopen(strcat(nombre, "Preinscritos.txt"), "r");//Abrimos fichero de preinscritos para buscar si el alumno esta preinscrito
            if(ficheroActividadEncontrada==NULL){
                printf("\nError al abrir el fichero de PreInscritos");
                exit(EXIT_FAILURE);
            }
                while(fscanf(ficheroActividadEncontrada, "%s %s %s %s %s %d", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, &cursoAlumnoActividad)==6){
                    if(strcmp(dniFichero, (u1.GetDni()).c_str())==0){//Compara con cada alumno preinscrito si coincide su dni
                        std::string titularTarjeta, fechacaducidadTarjeta;
                        int numeroTarjeta, cvvTarjeta;
                        std::cout<<"\nComenzando el pago para asistir a la actividad "<<nombreActividad<<" del alumno con dni "<<u1.GetDni()<<std::endl;
                        std::cout<<"\nCantidad a pagar: "<<precio;
                        std::cout<<"\n\tNumero de tarjeta: ";
                        std::cin>>numeroTarjeta;
                        std::cout<<"\n\tTitular de la tarjeta: ";
                        std::cin>>titularTarjeta;
                        std::cout<<"\n\tFecha de caducidad de la tarjeta: ";
                        std::cin>>fechacaducidadTarjeta;
                        std::cout<<"\n\tCVV: ";
                        std::cin>>cvvTarjeta;

                        std::cout<<"Pago realizado con exito"<<std::endl;
                        std::cout<<"Realizando la inscripcion del alumno "<<u1.GetDni()<<" en la actividad "<<nombreActividad<<"..."<<std::endl;


                        FILE *ficheroInscripcion;
                        char nombreActividadaux[264];
                        strcpy(nombreActividadaux, nombreActividad.c_str());
                        ficheroInscripcion=fopen(strcat(nombreActividadaux, "Inscritos.txt"), "a+");//TODO: cambiar nombre por nombreActividad del inicio convertida a cadena de tipo C
                        if(ficheroInscripcion==NULL){
                            printf("\nError al abrir el fichero");
                            exit(EXIT_FAILURE);
                        }
                        fprintf(ficheroInscripcion, "%s %s %s %s %s %d\n", (u1.GetDni()).c_str(), (u1.GetNombre()).c_str(), (u1.GetApellidos()).c_str(), (u1.GetCarrera()).c_str(), (u1.GetFacultad()).c_str(), u1.GetCurso());
                        std::cout<<"\nAlumno "<<u1.GetDni()<<" inscrito en la actividad "<<nombreActividad<<" con éxito"<<std::endl;

                        fclose(ficheroActividadEncontrada);






                        //Borramos el alumno del fichero de preinscritos
                        FILE *ficherotemporal;
                        char nombreActividadPreinscritosaux[264];
                        strcpy(nombreActividadPreinscritosaux, nombreActividad.c_str());
                        ficheroActividadEncontrada=fopen(strcat(nombreActividadPreinscritosaux, "Preinscritos.txt"), "r");
                        if(ficheroActividadEncontrada==NULL){
                            printf("\nError al abrir Preisncritos para borrar al alumno");
                            exit(EXIT_FAILURE);
                        }
                        ficherotemporal=fopen("ficherotemporal.txt", "w");
                        if(ficherotemporal==NULL){
                            printf("\nError al abrir Preisncritos para borrar al alumno");
                            exit(EXIT_FAILURE);
                        }

                        while(fscanf(ficheroActividadEncontrada, "%s %s %s %s %s %d", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, &cursoAlumnoActividad)==6){
                            if(strcmp(dniFichero, (u1.GetDni()).c_str())!=0){
                                fprintf(ficherotemporal, "%s %s %s %s %s %d\n", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, cursoAlumnoActividad);
                            }
                        }
                        fclose(ficheroActividadEncontrada);
                        fclose(ficherotemporal);
                        remove(nombreActividadPreinscritosaux);
                        rename("ficherotemporal.txt", nombreActividadPreinscritosaux);


                        fclose(ficheroInscripcion);
                        fclose(ficheroActividades);
                        return true;
                    }
                    else{
                        std::cout<<"El alumno no esta preinscrito en la actividad "<<nombreActividad<<std::endl;
                        return false;
                    }
                }
           
        }
        else{
             std::cout<<"La actividad "<<nombreActividad<<" no existe"<<std::endl;
            return false;
        }
    }
    return false;
}

























bool GestorDeUsuarios::anadirUsuario(Usuario u1){
    FILE *fichero;
    char dniFichero[MAX], nombre[MAX], apellidos[MAX], carrera[MAX], facultad[MAX];
    int curso;
    fichero=fopen("Usuarios.txt", "a+");
    if(fichero==NULL){
        printf("\nError al abrir el fichero");
        exit(EXIT_FAILURE);
    }

    while(fscanf(fichero, "%s %s %s %s %s %d\n", dniFichero, nombre, apellidos, carrera, facultad, &curso)==6){
        if(strcmp((u1.GetDni()).c_str(), dniFichero)==0){
            return false;
        }
    }
    fprintf(fichero, "%s %s %s %s %s %d\n", (u1.GetDni()).c_str(), (u1.GetNombre()).c_str(), (u1.GetApellidos()).c_str(), (u1.GetCarrera()).c_str(), (u1.GetFacultad()).c_str(), u1.GetCurso());
    
    fclose(fichero);
        return true;

}



bool Organizador::lanzarIdea(){
    std::string idea;
    printf("\nIntroduzca en menos de 500 caracteres la idea de la Actividad : ");
    std::getline(std::cin, idea);

    FILE* ficheroIdeas;
    ficheroIdeas=fopen("Ideas.txt", "w");
    if(ficheroIdeas==NULL){
        printf("\nError al abrir el fichero de ideas");
        exit(EXIT_FAILURE);
    }

    fprintf(ficheroIdeas, "%s\n", idea.c_str());
    return true;
}




bool DirectorAcademico::activarActividad(){
    FILE* ficheroIdeas;
    Actividad a;
    bool comprobarCrearActividad;
    char idea[500];
    std::string nombre, lugar, fecha, publico, ponentes, tipoActividad;
    int aforo,hora;
    float precio;


    ficheroIdeas=fopen("Ideas.txt", "r");
    if(ficheroIdeas==NULL){
        printf("\nError al abrir el fichero de ideas");
        exit(EXIT_FAILURE);
    }
    if(fgets(idea, 500, ficheroIdeas)!=NULL){
        printf("\nNo hay ideas lanzadas por el Organizador");
        return false;
    }
    else{
        printf("\nIdea: ");
        printf("%s", idea);
        printf("\nIntroduzca los datos de la actividad:");

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
                     a.SetNombre(nombre);
                    a.SetLugar(lugar);
                    a.SetFecha(fecha);
                    a.SetPublico(publico);
                    a.SetAforo(aforo);
                    a.SetPonentes(ponentes);
                    a.SetPrecio(precio);
                    a.SetHora(hora);
                    a.SetTipoActividad(tipoActividad);
        comprobarCrearActividad=a.crearActividad(a);
        return comprobarCrearActividad;
    }
    printf("\nError en la creacion de la actividad");
    return false;
}

bool Actividad::crearActividad(Actividad a){
    FILE* ficheroActividades;
    char nombre[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];

    ficheroActividades=fopen("Actividades.txt", "a+");
    if(ficheroActividades==NULL){
        printf("\nError al abrir el fichero de actividades");
        exit(EXIT_FAILURE);
    }

    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        if(strcmp(nombre, (a.GetNombre()).c_str())==0){
            printf("\nLa actividad %d ya esta registrada", (a.GetNombre()).c_str());
            return false;
        }
    }
    fprintf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad);
    return true;
}






void Actividad::listarActividades(){
    FILE *ficheroActividades;
    char nombre[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    ficheroActividades=fopen("Actividades.txt", "r");
    if(ficheroActividades==NULL){
        printf("\nError al abrir el fichero de actividades");
        exit(EXIT_FAILURE);
    }
    printf("\nACTIVIDADES:\n");
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        printf("\nNombre: %s\nLugar: %s\nFecha: %s\nPublico: %s\nAforo: \nPonente: %s\nPrecio: %s\nHora: %s\nActividad: %s", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad);
    }
    fclose(ficheroActividades);
}



void Actividad::eliminarActividad(std::string nombreActividad){
    FILE *ficheroActividades;
    char nombre[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    ficheroActividades=fopen("Actividades.txt", "r");
    if(ficheroActividades==NULL){
        printf("\nError al abrir el fichero de actividades");
        exit(EXIT_FAILURE);
    }
    FILE *ficheroTemporal;
    ficheroTemporal=fopen("temporal.txt", "r");
    if(ficheroActividades==NULL){
        printf("\nError al abrir el fichero de actividades");
        exit(EXIT_FAILURE);
    }
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        if(strcmp(nombre, nombreActividad.c_str())!=0){
               fprintf(ficheroTemporal, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad); 
        }
    }
    fclose(ficheroActividades);
    fclose(ficheroTemporal);
    remove("Actividades.txt");
    rename("temporal.txt", "Actividades.txt");
}






void Actividad::consultarAsistentes(std::string nombreActividad){
    FILE *ficheroActividades;
    char nombre[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    char dniFichero[MAX], nombreAsistente[MAX], apellidos[MAX], carrera[MAX], facultad[MAX];
    int curso;
    int encontrado=0;
    ficheroActividades=fopen("Actividades.txt", "r");
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        if(strcmp(nombreActividad.c_str(), nombre)==0){
            encontrado=1;
            FILE *ficheroAsistentes;
            ficheroAsistentes=fopen(strcat(nombre, "Inscritos.txt"), "r");
            if(ficheroAsistentes==NULL){
                printf("\nError al abrir el fichero de los inscritos a la charla");
                exit(EXIT_FAILURE);
            }
            while(fscanf(ficheroAsistentes, "%s %s %s %s %s %d\n", dniFichero, nombreAsistente, apellidos, carrera, facultad, &curso)==6){
                printf("\nDni: %s\nNombre: %s\nApellidos: %s\nCarrera: %s\nFacultad: %s\nCurso: %d", dniFichero, nombreAsistente, apellidos, carrera, facultad, curso);
            }
            fclose(ficheroAsistentes);
        }
    }
    if(encontrado==0){
        printf("\nLa actividad introducida no existe");
    }
    fclose(ficheroActividades);
}




Usuario Usuario::obtenerDatos(std::string dni){
    FILE* ficheroUsuarios;

    ficheroUsuarios=fopen("Usuarios.txt", "r");
    if(ficheroUsuarios==NULL){
        printf("\nError al abrir el fichero de Usuarios");
        
    }
}