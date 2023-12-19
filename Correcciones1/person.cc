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



/*bool Usuario::PreInscripcion(std::string nombreActividad){
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
    

}*/

/*std::string Usuario::GetDataUser(Usuario u){
    std::string cad;
    cad+="Dni: " + u.GetDni() + "\n" + "Nombre: " + u.GetNombre() + "\n"+ "Apellidos: " + u.GetApellidos() + "\n" + "Carrera: " + carrera_ + "\n"+ "Facultad: " + facultad_ + "\n" + "Curso: " + std::to_string(curso_);
    return cad;
}*/


bool Usuario::InscripcionyPago(std::string nombreActividad, Usuario u1){
    Usuario usuarioEncontrado=u1;
    FILE *ficheroActividades;
    char nombre[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    std::string nombreActividadaux;
    bool comprobaraforo;
    char nombreFicheroComprobarAforo[MAX];
    int aforoComprobarAforo;
    ficheroActividades=fopen("Actividades.txt", "r");
    if(ficheroActividades==NULL){
        printf("\nError al abrir el fichero Actividades");
        exit(EXIT_FAILURE);
    }


    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){

        if(nombreActividad==nombre){//Si la actividad existe
            FILE *ficheroActividadEncontrada;
            char dniFichero[MAX], nombreAlumnoActividad[MAX], apellidosAlumnoActividad[MAX], carreraAlumnoActividad[MAX], facultadAlumnoActividad[MAX], correoAlumnoActividad[MAX];
            int cursoAlumnoActividad;

            ficheroActividadEncontrada=fopen(strcat(nombre, "Preinscritos.txt"), "r");//Abrimos fichero de preinscritos para buscar si el alumno esta preinscrito
            if(ficheroActividadEncontrada==NULL){
                printf("\nError al abrir el fichero de PreInscritos");
                exit(EXIT_FAILURE);
            }
                while(fscanf(ficheroActividadEncontrada, "%s %s %s %s %s %d %s\n", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, &cursoAlumnoActividad, correoAlumnoActividad)==7){
                    strcpy(nombreFicheroComprobarAforo,nombreActividad.c_str());
                    strcat(nombreFicheroComprobarAforo, "Inscritos.txt");
                    aforoComprobarAforo=atoi(aforo);
                    comprobaraforo=ContarLineasFichero(nombreFicheroComprobarAforo, aforoComprobarAforo);
                    if(strcmp(dniFichero, (u1.GetDni()).c_str())==0 && comprobaraforo==true){//Compara con cada alumno preinscrito si coincide su dni
                        std::string titularTarjeta, fechacaducidadTarjeta;
                        int numeroTarjeta, cvvTarjeta;
                        std::cout<<"\nComenzando el pago para asistir a la actividad "<<nombreActividad<<" del alumno con dni "<<u1.GetDni()<<std::endl;
                        std::cout<<"\nCantidad a pagar: "<<precio;
                        std::cout<<"\n\tNumero de tarjeta: ";
                        std::cin>>numeroTarjeta;
                        std::cin.ignore();
                        std::cout<<"\n\tTitular de la tarjeta: ";
                        std::cin>>titularTarjeta;
                        std::cout<<"\n\tFecha de caducidad de la tarjeta: ";
                        std::cin>>fechacaducidadTarjeta;
                        std::cout<<"\n\tCVV: ";
                        std::cin>>cvvTarjeta;
                        std::cin.ignore();

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
                        fprintf(ficheroInscripcion, "%s %s %s %s %s %d %s\n", (u1.GetDni()).c_str(), (u1.GetNombre()).c_str(), (u1.GetApellidos()).c_str(), (u1.GetCarrera()).c_str(), (u1.GetFacultad()).c_str(), u1.GetCurso(), (u1.GetCorreo()).c_str());
                        std::cout<<"\nAlumno "<<u1.GetDni()<<" inscrito en la actividad "<<nombreActividad<<" con éxito"<<std::endl;
                        u1.imprimirJustificantedePago(nombreActividad.c_str(), atof(precio), u1);
                        getchar();
                        fclose(ficheroActividadEncontrada);






                        //Borramos el alumno del fichero de preinscritos
                        FILE *ficherotemporal;
                        char nombreActividadPreinscritosaux[264];
                        strcpy(nombreActividadPreinscritosaux, nombreActividad.c_str());
                        ficheroActividadEncontrada=fopen(strcat(nombreActividadPreinscritosaux, "Preinscritos.txt"), "r");
                        if(ficheroActividadEncontrada==NULL){
                            printf("\nError al abrir Preisncritos para borrar al alumno");
                            getchar();
                            exit(EXIT_FAILURE);
                        }
                        ficherotemporal=fopen("ficherotemporal.txt", "w");
                        if(ficherotemporal==NULL){
                            
                            printf("\nError al abrir Preisncritos para borrar al alumno");
                            getchar();
                            exit(EXIT_FAILURE);
                        }

                        while(fscanf(ficheroActividadEncontrada, "%s %s %s %s %s %d %s\n", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, &cursoAlumnoActividad, correoAlumnoActividad)==7){
                            if(strcmp(dniFichero, (u1.GetDni()).c_str())!=0){
                                fprintf(ficherotemporal, "%s %s %s %s %s %d %s\n", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, cursoAlumnoActividad, correoAlumnoActividad);
                            }
                        }//while para esccribir a los alumnos que no coinciden con el alumno a borrar en un fichero temporal
                        fclose(ficheroActividadEncontrada);
                        fclose(ficherotemporal);
                        remove(nombreActividadPreinscritosaux);
                        rename("ficherotemporal.txt", nombreActividadPreinscritosaux);


                        fclose(ficheroInscripcion);
                        fclose(ficheroActividades);
                        return true;
                    }//Si encuentra al alumno preinscrito en dicha actividad
                    
                }//while para buscar al alumno en el fichero de preinscritos
                    std::cout<<"El alumno no esta preinscrito en la actividad "<<nombreActividad<<std::endl;
                    getchar();
                    return false;
           
        }//Si encuentra la actividad en el fichero

        
    }//while para buscar la actividad dentro del fichero Actividades.txt, es decir, ver si existe dicha actividad
            std::cout<<"La actividad "<<nombreActividad<<" no existe"<<std::endl;
            getchar();

            return false;
        
}

























bool GestorDeUsuarios::anadirUsuario(Usuario u1){
    FILE *fichero;
    char dniFichero[MAX], nombre[MAX], apellidos[MAX], carrera[MAX], facultad[MAX], correo[MAX];
    int curso;
    fichero=fopen("Usuarios.txt", "a+");
    if(fichero==NULL){
        printf("\nError al abrir el fichero");
        exit(EXIT_FAILURE);
    }

    while(fscanf(fichero, "%s %s %s %s %s %d %s\n", dniFichero, nombre, apellidos, carrera, facultad, &curso, correo)==7){
        if(strcmp((u1.GetDni()).c_str(), dniFichero)==0){
            return false;
        }
    }
    fprintf(fichero, "%s %s %s %s %s %d %s\n", (u1.GetDni()).c_str(), (u1.GetNombre()).c_str(), (u1.GetApellidos()).c_str(), (u1.GetCarrera()).c_str(), (u1.GetFacultad()).c_str(), u1.GetCurso(), (u1.GetCorreo()).c_str());
    
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
    fclose(ficheroIdeas);
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
        printf("\nNo hay ideas lanzadas por el Organizador");
        return false;
    }
    if(fgets(idea, 500, ficheroIdeas)==NULL){
        printf("\nNo hay ideas lanzadas por el Organizador");
        return false;
    }
    else{
        printf("\nIdea: ");
        printf("%s", idea);
        printf("\nIntroduzca los datos de la actividad:");

                    std::cout << "\nIngrese el nombre de la actividad: ";
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












bool Usuario::accederWeb(std::string dni, Usuario &u){
    FILE* ficheroUsuarios;
    char dniFichero[MAX], nombre[MAX], apellidos[MAX], carrera[MAX], facultad[MAX], correo[MAX];
    int curso;
    ficheroUsuarios=fopen("Usuarios.txt", "r");
    if(ficheroUsuarios==NULL){
        printf("\nError al abrir el fichero de Usuarios");
        exit(EXIT_FAILURE);
    }
    while(fscanf(ficheroUsuarios, "%s %s %s %s %s %d %s\n", dniFichero, nombre, apellidos, carrera, facultad, &curso, correo)==7){
        if(strcmp(dni.c_str(), dniFichero)==0){
            u.SetDni(dni);
            u.SetNombre(nombre);
            u.SetApellidos(apellidos);
            u.SetCarrera(carrera);
            u.SetFacultad(facultad);
            u.SetCurso(curso);
            u.SetCorreo(correo);
            return true; 
        }
}
    return false;

}




bool Usuario::PreInscripcion(std::string nombreActividad, Usuario u){
    std::string nombre, dni, carrera, apellidos, facultad;
    char dniFichero[MAX], nombreAlumnoActividad[MAX], apellidosAlumnoActividad[MAX], carreraAlumnoActividad[MAX], facultadAlumnoActividad[MAX], correoAlumnoActividad[MAX];
    int cursoAlumnoActividad;
    char nombreActividadLocal[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];

    //int curso;
    FILE * ficheroActividades;
    ficheroActividades=fopen("Actividades.txt", "r");
    if(ficheroActividades==NULL){
        printf("\nError al abrir el fichero");
        exit(EXIT_FAILURE);
    }
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombreActividadLocal, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        if(strcmp(nombreActividadLocal, nombreActividad.c_str())==0){
            FILE* ficheroPreinscritos;
            ficheroPreinscritos=fopen(strcat((char*)nombreActividad.c_str(), "Preinscritos.txt"), "a+");
            if(ficheroPreinscritos==NULL){
                printf("\nError al abrir el fichero");
                exit(EXIT_FAILURE);
            }
            while(fscanf(ficheroPreinscritos, "%s %s %s %s %s %d %s\n", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, &cursoAlumnoActividad, correoAlumnoActividad)==7){
                if(strcmp(dniFichero, u.GetDni().c_str())==0){
                    printf("\nEL alumno con dni %s ya esta preinscrito en dicha actividad", u.GetDni().c_str());
                    fclose(ficheroActividades);
                    fclose(ficheroPreinscritos);
                    return false;
                }
            }
            fprintf(ficheroPreinscritos, "%s %s %s %s %s %d %s\n", (u.GetDni()).c_str(), (u.GetNombre()).c_str(), (u.GetApellidos()).c_str(), (u.GetCarrera()).c_str(), (u.GetFacultad()).c_str(), u.GetCurso(), (u.GetCorreo()).c_str());

        

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



bool DirectorAcademico::eliminarActividad(std::string nombreActividad){
    FILE *ficheroActividades;
    int encontrado=0;
    char nombreFicheroInscritos[MAX];
    strcpy(nombreFicheroInscritos, nombreActividad.c_str());
    strcat(nombreFicheroInscritos, "Inscritos.txt");
    char nombreFicheroPreinscritos[MAX];
    strcpy(nombreFicheroPreinscritos, nombreActividad.c_str());
    strcat(nombreFicheroPreinscritos, "Preinscritos.txt");
    char nombre[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    ficheroActividades=fopen("Actividades.txt", "r");
    if(ficheroActividades==NULL){
        printf("\nError al abrir el fichero de actividades");
        exit(EXIT_FAILURE);
    }
    FILE *ficheroTemporal;
    ficheroTemporal=fopen("temporal.txt", "w");
    if(ficheroActividades==NULL){
        printf("\nError al abrir el fichero de actividades");
        exit(EXIT_FAILURE);
    }
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        if(strcmp(nombre, nombreActividad.c_str())!=0){
               fprintf(ficheroTemporal, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad); 
        }
        else{
            encontrado=1;
        }
    }
    fclose(ficheroActividades);
    fclose(ficheroTemporal);
    remove("Actividades.txt");
    rename("temporal.txt", "Actividades.txt");
    remove(nombreFicheroInscritos);
    remove(nombreFicheroPreinscritos);
    if(encontrado==0){
        return false;
    }
    return true;
}




bool ContarLineasFichero(char *nombreFichero, int n){
    int contador=0;
    FILE* fichero;
    char linea[500];
    fichero=fopen(nombreFichero, "r");
    if(fichero==NULL){
        return true;
    }

    while(fgets(linea, 500, fichero)!=NULL){
        contador++;
    }
    if(contador>=n){
        return false;
    }
    else{
        return true;
    }
    fclose(fichero);
}



bool Usuario::cancelarInscripcion(std::string nombreActividad, Usuario u){
    FILE* ficheroInscripcion;
    FILE* ficheroTemporal;
    int encontrado=0;
    char nombreFicheroInscripcion[MAX];
    char dniFichero[MAX], nombreAlumnoActividad[MAX], apellidosAlumnoActividad[MAX], carreraAlumnoActividad[MAX], facultadAlumnoActividad[MAX], correoAlumnoActividad[MAX];
    int cursoAlumnoActividad;
    strcpy(nombreFicheroInscripcion, nombreActividad.c_str());
    strcat(nombreFicheroInscripcion, "Inscritos.txt");

    ficheroInscripcion=fopen(nombreFicheroInscripcion, "r");
    if(ficheroInscripcion==NULL){
        return false;
    }

    ficheroTemporal=fopen("temporal.txt", "w");
    if(ficheroTemporal==NULL){
        printf("\nError al abrir el fichero de inscritos");
        exit(EXIT_FAILURE);
    }

    while(fscanf(ficheroInscripcion, "%s %s %s %s %s %d %s\n", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, &cursoAlumnoActividad, correoAlumnoActividad)==7){
        if(strcmp(dniFichero, (u.GetDni()).c_str())!=0){
            fprintf(ficheroTemporal, "%s %s %s %s %s %d %s\n", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, cursoAlumnoActividad, correoAlumnoActividad);
        }
        else{
            encontrado=1;
        }
    }
    fclose(ficheroInscripcion);
    fclose(ficheroTemporal);
    remove(nombreFicheroInscripcion);
    rename("temporal.txt", nombreFicheroInscripcion);
    if(encontrado==1){
        return true;
    }
    return false;
}


void Usuario::imprimirJustificantedePago(std::string nombreActividad, float precio, Usuario u){
    char nombreFichero[MAX];
    strcpy(nombreFichero, "JustificantePago");
    strcat(nombreFichero, nombreActividad.c_str());
    strcat(nombreFichero, (u.GetDni()).c_str());
    strcat(nombreFichero, ".txt");  
    FILE* ficheroJustificantePago;
    ficheroJustificantePago=fopen(nombreFichero, "w");
    if(ficheroJustificantePago==NULL){
        printf("\nError al crear el fichero de justificante de pago");
        exit(EXIT_FAILURE);
    }
    fprintf(ficheroJustificantePago, "******JUSTIFICANTE DE PAGO******\nUsted %s %s con DNI %s ha realizado el pago de %.2f para asistir a la actividad %s\n\n\tIMPORTE:\t##%.2f##", (u.GetNombre()).c_str(), (u.GetApellidos()).c_str(), (u.GetDni()).c_str(), precio, nombreActividad.c_str(), precio);
    fclose(ficheroJustificantePago);
}



void DirectorAcademico::escribirAgradecimientos(std::string nombreActividad, std::string ponente){
    char nombreFichero[MAX];
    strcpy(nombreFichero, "Agradecimiento");
    strcat(nombreFichero, ponente.c_str());
    strcat(nombreFichero, nombreActividad.c_str());
    strcat(nombreFichero, ".txt");

    FILE* ficheroAgradecimiento;
    ficheroAgradecimiento=fopen(nombreFichero, "w");
    if(ficheroAgradecimiento==NULL){
        printf("\nError al crear el fichero de agradecimientos");
        exit(EXIT_FAILURE);
    }


    fprintf(ficheroAgradecimiento, "*******AGRADECIMIENTOS*********\nAgradecemos al ponente %s por su asistencia a la actividad %s. Gracias por dedicarnos su tiempo y compartir su conocimiento con nosotros.\nGracias y un cordial saludo.\n\tFdo: Director Academico", ponente.c_str(), nombreActividad.c_str());
    fclose(ficheroAgradecimiento);
}



bool comprobarDniVisitante(std::string dniLogin, Usuario &u){
    FILE* ficheroVisitantes;
    char nombre[MAX], dni[MAX], apellido[MAX], carrera[MAX], facultad[MAX], correo[MAX];
    int curso;
    ficheroVisitantes=fopen("Visitantes.txt", "a+");
    if(ficheroVisitantes==NULL){
        printf("\nError al abrir el fichero de Visitantes");
        exit(EXIT_FAILURE);
    }
    while(fscanf(ficheroVisitantes, "%s %s %s %s %s %d %s\n", dni, nombre, apellido, carrera, facultad, &curso, correo)==7){
        if(strcmp(dni, dniLogin.c_str())==0){
            u.SetDni(dniLogin);
            u.SetNombre(nombre);
            u.SetApellidos(apellido);
            u.SetCarrera(carrera);
            u.SetFacultad(facultad);
            u.SetCurso(curso);
            u.SetCorreo(correo);
            fclose(ficheroVisitantes);
            return true;
        }
    }
    fclose(ficheroVisitantes);
    return false;

}

void Usuario::anadirVisitante(Usuario u){
    FILE* ficheroVisitantes;
    ficheroVisitantes=fopen("Visitantes.txt", "a+");
    if(ficheroVisitantes==NULL){
        printf("\nError al abrir el fichero de visitantes para anadir al nuevo visitante");
        exit(EXIT_FAILURE);
    }
    fprintf(ficheroVisitantes, "%s %s %s %s %s %d %s\n", (u.GetDni()).c_str(), (u.GetNombre()).c_str(), (u.GetApellidos()).c_str(), (u.GetCarrera()).c_str(), (u.GetFacultad()).c_str(), u.GetCurso(), (u.GetCorreo()).c_str());

    fclose(ficheroVisitantes);
}


bool DirectorAcademico::publicitarActividad(std::string nombreActividad, std::string publico){
    FILE* ficheroUsuarios;
    FILE* ficheroActividades;
    char dniFichero[MAX], nombreUsuario[MAX], apellidos[MAX], carrera[MAX], facultad[MAX], correo[MAX];
    char nombre[MAX], lugar[MAX], fecha[MAX], publicoFicheroActividades[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    int curso;
    bool comprobarEnvio;
    std::string correoAEnviar;
    Actividad a;

    ficheroActividades=fopen("Actividades.txt", "r");
    if(ficheroActividades==NULL){
        printf("\nNo hay actividades registradas");
        return false;
    }
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publicoFicheroActividades, aforo, ponentes, precio, hora, actividad)==9){
        if(strcmp(nombreActividad.c_str(), nombre)==0){
            ficheroUsuarios=fopen("Usuarios.txt", "r");
                if(ficheroUsuarios==NULL){
                    printf("\nError al abrir el fichero de usuarios");
                    fclose(ficheroActividades);
                    return false;
                }
            while(fscanf(ficheroUsuarios, "%s %s %s %s %s %d %s\n", dniFichero, nombreUsuario, apellidos, carrera, facultad, &curso, correo)==7){
                if(strcmp(carrera, publico.c_str())==0){
                    a.SetNombre(nombre);
                    a.SetLugar(lugar);
                    a.SetFecha(fecha);
                    a.SetPublico(publicoFicheroActividades);
                    a.SetAforo(atoi(aforo));
                    a.SetPonentes(ponentes);
                    a.SetPrecio(atof(precio));
                    a.SetHora(atoi(hora));
                    a.SetTipoActividad(actividad);
                    correoAEnviar=cuerpoCorreo("Director Academico", correo, a);
                    comprobarEnvio=enviarCorreo(dniFichero, correoAEnviar);
                    if(comprobarEnvio==true){
                        std::cout<<"Correo enviado a "<<correo<<std::endl;
                    }
                    else{
                        std::cout<<"Error al enviar el correo a "<<correo<<std::endl;
                    }
                }
                else if(strcmp(publico.c_str(), "Todos")==0){
                            a.SetNombre(nombre);
                            a.SetLugar(lugar);
                            a.SetFecha(fecha);
                            a.SetPublico(publicoFicheroActividades);
                            a.SetAforo(atoi(aforo));
                            a.SetPonentes(ponentes);
                            a.SetPrecio(atof(precio));
                            a.SetHora(atoi(hora));
                            a.SetTipoActividad(actividad);
                            correoAEnviar=cuerpoCorreo("Director Academico", correo, a);
                            comprobarEnvio=enviarCorreo(dniFichero, correoAEnviar);
                            if(comprobarEnvio==true){
                                std::cout<<"Correo enviado a "<<correo<<std::endl;
                            }
                            else{
                                std::cout<<"Error al enviar el correo a "<<correo<<std::endl;
                            } 
                    }      
                }
            fclose(ficheroUsuarios);
            fclose(ficheroActividades);
            return true;

        }
    }
    std::cout<<"La actividad introducida no existe"<<std::endl;
    fclose(ficheroActividades);
    return false;
}

bool enviarCorreo(std::string dni, std::string mensaje){
    FILE* ficheroBandajeEntrada;
    char nombreFicheroBandejaEntrada[MAX];
    strcpy(nombreFicheroBandejaEntrada, "BandejaEntrada");
    strcat(nombreFicheroBandejaEntrada, dni.c_str());
    strcat(nombreFicheroBandejaEntrada, ".txt");
    ficheroBandajeEntrada=fopen(nombreFicheroBandejaEntrada, "a+");
    if(ficheroBandajeEntrada==NULL){
        printf("\nError al abrir el fichero de bandeja de entrada de %s", dni.c_str());
        return false;
    }
    fprintf(ficheroBandajeEntrada, "%s\n", mensaje.c_str());
    fclose(ficheroBandajeEntrada);
    return true;
}





std::string cuerpoCorreo(std::string Emisor, std::string Destinatario, Actividad a){
    std::string cuerpo, mensaje;
    cuerpo+="Hola a todos, os enviamos una actividad en la que se van a tratar temas interesantes y dirigidos a vosotros. ";
    cuerpo+="\n\tNombre: " + a.GetNombre() + "\n\tLugar: " + a.GetLugar() + "\n\tFecha: " + a.GetFecha() + "\n\tPublico: " + a.GetPublico() + "\n\tAforo: " + std::to_string(a.GetAforo()) + "\n\tPonentes: " +a.GetPonentes() + "\n\tPrecio: " + std::to_string(a.GetPrecio()) + "\n\tHora: " + std::to_string(a.GetHora()) + "\n\tTipo de actividad: " + a.GetTipoActividad();
    cuerpo+="\nAgradecemos su participacion.\nUn cordial saludo, el Director Academico";
    mensaje+="De: " + Emisor + "\nPara: " + Destinatario + "\nMensaje: "  + cuerpo;
    return mensaje;
}



bool Usuario::leerCorreos(std::string dni){
    char nombreFichero[MAX];
    char emisor[MAX], destinatario[MAX], cuerpo[MAX];
    strcpy(nombreFichero,"BandejaEntrada");
    strcat(nombreFichero, dni.c_str());
    strcat(nombreFichero, ".txt");
    FILE* ficheroBandejaEntrada;
    ficheroBandejaEntrada=fopen(nombreFichero, "r");
    if(ficheroBandejaEntrada==NULL){
        printf("\nNo hay correos en su bandeja de entrada");
        return false;
    }
    while(fgets(emisor, MAX, ficheroBandejaEntrada)!=NULL && fgets(destinatario, MAX, ficheroBandejaEntrada)!=NULL && fgets(cuerpo, MAX, ficheroBandejaEntrada)!=NULL){
        
        limpiarlinea(emisor);
        limpiarlinea(destinatario);
        limpiarlinea(cuerpo);
        /*IMPRIMIMOS EL MENSAJE*/
        printf("\n\n%s\n%s\n%s", emisor, destinatario, cuerpo);
    }
    fclose(ficheroBandejaEntrada);
    return true;
}





void limpiarlinea(char *linea){
if(linea[strlen(linea)-1]=='\n'){
	linea[strlen(linea)-1]='\0';
}
if(linea[strlen(linea)-1]=='\r'){
	linea[strlen(linea)-1]='\0';
}
}



bool DirectorAcademico::pasarActividadHistorico(std::string nombreActividad){
    FILE* ficheroActividades;
    FILE* ficherotemporal;

    char nombre[MAX], lugar[MAX], fecha[MAX], publicoFicheroActividades[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    ficheroActividades=fopen("Actividades.txt", "r");
    if(ficheroActividades==NULL){
        printf("\nNo hay actividades activadas");
        return false;
    }
    ficherotemporal=fopen("temporal.txt", "w");
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publicoFicheroActividades, aforo, ponentes, precio, hora, actividad)==9){
        if(strcmp(nombreActividad.c_str(), nombre)==0){
            FILE* ficheroHistorico;
            ficheroHistorico=fopen("Historico.txt", "a+");
            fprintf(ficheroHistorico, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publicoFicheroActividades, aforo, ponentes, precio, hora, actividad); 
            fclose(ficheroHistorico);
        }
        else{
            
            fprintf(ficherotemporal, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publicoFicheroActividades, aforo, ponentes, precio, hora, actividad); 
        }
    }
    fclose(ficheroActividades);
    fclose(ficherotemporal);
    remove("Actividades.txt");
    rename("temporal.txt", "Actividades.txt");
    return true;
}


void listarActividadesHistorico(){
    FILE *ficheroHistorico;
    char nombre[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    ficheroHistorico=fopen("Historico.txt", "r");
    if(ficheroHistorico==NULL){
        printf("\nError al abrir el fichero de actividades");
        exit(EXIT_FAILURE);
    }
    printf("\nACTIVIDADES DEL HISTORICO:\n");
    while(fscanf(ficheroHistorico, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        printf("\nNombre: %s\nLugar: %s\nFecha: %s\nPublico: %s\nAforo: %s\nPonente: %s\nPrecio: %s\nHora: %s\nActividad: %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad);
    }
    fclose(ficheroHistorico);
}