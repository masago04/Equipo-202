#include "person.h"
#include <fstream>
#include <string.h>
#define MAX 264


/*FUNCION: IscripcionyPago
Esta funcion perteneciente a la clase Usuario sirve para que el usuario se inscriba en una actividad y realice el pago para 
poder asistir. Lo primero que hace la funcion es ver si la actividad introducida existe entre las actividades registradas en el 
fichero Actividades.txt. En el momento que encuentre la actividad en el fichero de Actividades.txt abre el fichero de Preinscritos
de dicha actividad, ya que para poder inscribirse hay que estar preinscrito. Si el usuario está preinscrito abre el fichero
de inscritos y escribe los datos del usuario en dicho fichero y borra al usuario del fichero de preinscritos para que un mismo
usuario no se pueda inscribir mas de una vez. Si la actividad no existe devolvera false y dira que la actividad no existe;
y si el usuario no esta preinscrito devolvera false y dira que el usuario no esta preinscrito.
La funcion genera automaticamente un fichero como Justuificante de pago que tiene el siguiente formato: 
JustificantePago+nombreActividad+dniUsuario.txt
Formato del fichero de los inscritos a una actividad: nombreActividad+Inscritos.txt*/
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

    //Bucle while para buscar la actividad en el fichero Actividades.txt
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        //Caso en el que la actividad si existe
        if(nombreActividad==nombre){//Si la actividad existe
            FILE *ficheroActividadEncontrada;
            char dniFichero[MAX], nombreAlumnoActividad[MAX], apellidosAlumnoActividad[MAX], carreraAlumnoActividad[MAX], facultadAlumnoActividad[MAX], correoAlumnoActividad[MAX];
            int cursoAlumnoActividad;
            //Abrimos fichero de preinscritos a dicha actividad
            ficheroActividadEncontrada=fopen(strcat(nombre, "Preinscritos.txt"), "r");//Abrimos fichero de preinscritos para buscar si el alumno esta preinscrito
            if(ficheroActividadEncontrada==NULL){
                printf("\nError al abrir el fichero de PreInscritos");
                exit(EXIT_FAILURE);
            }
                //Bucle while para buscar al usuario y ver si esta preinscrito en la actividad
                while(fscanf(ficheroActividadEncontrada, "%s %s %s %s %s %d %s\n", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, &cursoAlumnoActividad, correoAlumnoActividad)==7){
                    strcpy(nombreFicheroComprobarAforo,nombreActividad.c_str());
                    strcat(nombreFicheroComprobarAforo, "Inscritos.txt");
                    aforoComprobarAforo=atoi(aforo);
                    comprobaraforo=ContarLineasFichero(nombreFicheroComprobarAforo, aforoComprobarAforo);
                    //Si el usuario esta preinscrito y no se supera el aforo, 
                    if(strcmp(dniFichero, (u1.GetDni()).c_str())==0 && comprobaraforo==true){//Compara con cada alumno preinscrito si coincide su dni
                        std::string titularTarjeta, fechacaducidadTarjeta;
                        int numeroTarjeta, cvvTarjeta;
                        //Realizar el pago
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

                        //Apertura del fichero de inscritos para inscribir al usuario
                        FILE *ficheroInscripcion;
                        char nombreActividadaux[264];
                        strcpy(nombreActividadaux, nombreActividad.c_str());
                        ficheroInscripcion=fopen(strcat(nombreActividadaux, "Inscritos.txt"), "a+");//TODO: cambiar nombre por nombreActividad del inicio convertida a cadena de tipo C
                        if(ficheroInscripcion==NULL){
                            printf("\nError al abrir el fichero");
                            exit(EXIT_FAILURE);
                        }
                        //Se inscribe al usuario
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




/*FUNCION: anadirUsuario
Esta funcion perteneciente a la clase GestorDeUsuarios sirve para añadir a un usuario a nuestra base de datos para que pueda 
hacer uso de nuestros servicios. La funcion abre el fichero de Usuarios.txt y busca que el dni que queremos agregar no 
exista ya en la base de datos. Si existe devuelve false y si no existe lo agrega al fichero y devolvera true
Formato del fichero que almacena los usuarios registrados: Usuarios.txt*/
bool GestorDeUsuarios::anadirUsuario(Usuario u1){
    FILE *fichero;
    char dniFichero[MAX], nombre[MAX], apellidos[MAX], carrera[MAX], facultad[MAX], correo[MAX];
    int curso;
    fichero=fopen("Usuarios.txt", "a+");
    if(fichero==NULL){
        printf("\nError al abrir el fichero");
        exit(EXIT_FAILURE);
    }
    //Comprobar que el dni no coincida con los dni del fichero
    while(fscanf(fichero, "%s %s %s %s %s %d %s\n", dniFichero, nombre, apellidos, carrera, facultad, &curso, correo)==7){
        if(strcmp((u1.GetDni()).c_str(), dniFichero)==0){
            return false;
        }
    }
    //Agregamos al usuario al fichero
    fprintf(fichero, "%s %s %s %s %s %d %s\n", (u1.GetDni()).c_str(), (u1.GetNombre()).c_str(), (u1.GetApellidos()).c_str(), (u1.GetCarrera()).c_str(), (u1.GetFacultad()).c_str(), u1.GetCurso(), (u1.GetCorreo()).c_str());
    
    fclose(fichero);
        return true;

}



/*FUNCION: lanzarIdea
Esta funcion perteneciente a la clase Organizador sirve para que el organizador lance una idea sobre una posible actividad a realizar
que le llegara al DirectorAcademico, que sera quien la cree y active
Formato del fichero que almacena la idea: Ideas.txt*/
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
    //Escribe en el fichero Ideas.txt la idea introducida por teclado por el Organizador
    fprintf(ficheroIdeas, "%s\n", idea.c_str());
    fclose(ficheroIdeas);
    return true;
}



/*FUNCION: activarActividad
Esta funcion pertenence a la clase DirectorAcademico y lo que hace es mostrarle al DirectorAcademico la idea lanzada por el
Orgwanizador y le pide al DirectorAcademico que introduzca los datos. Si el nombre de la actividad ya existe devolvera false
y si no existe la agrega. Para ello hace uso de una funcion de la clase Actividad, que es la que comprueba si el nombre de 
la actividad existe y si no existe la agrega al fichero Actividades.txt. Si el Organizador no ha lanzado ninguna idea se le 
comunicara al DirectorAcademico por pantalla
Formato del fichero que almacena las actividades activas: Actividades.txt*/
bool DirectorAcademico::activarActividad(){
    FILE* ficheroIdeas;
    Actividad a;
    bool comprobarCrearActividad;
    char idea[500];
    std::string nombre, lugar, fecha, publico, ponentes, tipoActividad;
    int aforo,hora;
    float precio;

    //Abrimos fichero Ideas.txt para comprobar si el Organizador ha lanzado alguna actividad
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
        //Imprimimos la idea
        printf("\nIdea: ");
        printf("%s", idea);
        //Pedimos los datos de la actividad
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
        //Llamamosa la funcion crearActividad para comprobar si la actividad existe ya, y si no existe la agrega al fichero "Actividades.txt"            
        comprobarCrearActividad=a.crearActividad(a);
        return comprobarCrearActividad;
    }
    printf("\nError en la creacion de la actividad");
    return false;
}





/*FUNCION: accederWeb
Esta funcion pertenece a la clase Usuario y se ejecuta al introducir un dni distinto al de DirectorAcademico, Gestor, Organizador
o Visitante. Lo que hace esta funcion es buscar si el dni introducido existe en nuestra base de datos. Si dicho dni 
no existe devolvera false y mostrara por pantalla un mensaje pidiendo que para poder acceder debes estar previamente 
registrado. Si encuentra el dni se trae los datos de dicho Usuario a una variable del main mediante un paso por referencia*/
bool Usuario::accederWeb(std::string dni, Usuario &u){
    FILE* ficheroUsuarios;
    char dniFichero[MAX], nombre[MAX], apellidos[MAX], carrera[MAX], facultad[MAX], correo[MAX];
    int curso;
    ficheroUsuarios=fopen("Usuarios.txt", "r");
    if(ficheroUsuarios==NULL){
        printf("\nError al abrir el fichero de Usuarios");
        exit(EXIT_FAILURE);
    }
    //Bucle while para buscar el dni del usuario en el fichero Usuarios.txt
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



/*FUNCION: PreInscripcion
Esta funcion perteneciente a la clase Usuario realiza la Preinscripcion de un alumno en una actividad. Lo primero
que hace es buscar en el fochero Actividades.txt si la actividad existe. Si esta existe abre el fichero de Preinscritos de dicha 
actividad y busca que el usuario no este ya preinscrito. Si no esta preinscrito lo escribe en dicho fichero y devuelve true; y si ya 
esta preinscrito o la actividad no existe devuelve false junto con un mensaje por pantalla avisando del error.
Formato del fichero de los preinscritos a una actividad: nombreActividad+Preinscritos.txt*/
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
    //Bucle para buscar la actividad en el fichero de Actividades.txt
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombreActividadLocal, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        if(strcmp(nombreActividadLocal, nombreActividad.c_str())==0){
            FILE* ficheroPreinscritos;
            ficheroPreinscritos = fopen((nombreActividad + "Preinscritos.txt").c_str(), "a+");
            if(ficheroPreinscritos==NULL){
                printf("\nError al abrir el fichero");
                exit(EXIT_FAILURE);
            }
            //Bucle para comprobar que el usuario no este ya preinscrito
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


/*FUNCION: eliminarActividad
Esta funcion que pertenece a la clase DirectorAcademico se utiliza para eliminar una actividad. Si encuentra la actividad la
elimina y devuelve true y si no la encuentra devuelve false*/
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

    //Bucle para buscar la actividad a eliminar
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



//Esta funcion la usamos en la funcion InscripcionyPago para controlar que no excedamos el aforo de una actividad
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


/*FUNCION: cancelarInscripcion
Esta funcion pertenenciente a la clase Usuario sirve para cancelar la inscripcion en una actividad. Si encuentra al usuario devuelve
true y si no devolvera false*/
bool Usuario::cancelarInscripcion(std::string nombreActividad, Usuario u){
    FILE* ficheroInscripcion;
    FILE* ficheroTemporal;
    int encontrado=0;
    char nombreFicheroInscripcion[MAX];//Almacena el nombre del fichero de inscritos a la actividad
    char dniFichero[MAX], nombreAlumnoActividad[MAX], apellidosAlumnoActividad[MAX], carreraAlumnoActividad[MAX], facultadAlumnoActividad[MAX], correoAlumnoActividad[MAX];
    int cursoAlumnoActividad;
    
    strcpy(nombreFicheroInscripcion, nombreActividad.c_str());
    strcat(nombreFicheroInscripcion, "Inscritos.txt");

    //Apertura de ficheros
    ficheroInscripcion=fopen(nombreFicheroInscripcion, "r");
    if(ficheroInscripcion==NULL){
        return false;
    }

    ficheroTemporal=fopen("temporal.txt", "w");
    if(ficheroTemporal==NULL){
        printf("\nError al abrir el fichero de inscritos");
        exit(EXIT_FAILURE);
    }
    //Bucle para buscar al usuario entre los inscritos
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

/*FUNCION: imprimirJustificantedePago
Esta funcion pertenece a la clase Usuario y sirve para generar un fichero con el justicante de pago del usuario tras inscribirse
en la actividad. 
La funcion genera automaticamente un fichero como Justificante de pago que tiene el siguiente formato: 
JustificantePago+nombreActividad+dniUsuario.txt*/
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


/*FUNCION: escribirAgradecimiento
Esta funcion se ejecuta al activar una actividad y lo que hace es generar un fichero con el agradecimiento al ponente por
asistir a nuestra actividad
Formato del fichero de agradecimientos: Agradecimiento+nombrePonente+nombreActividad*/
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


/*FUNCION: comprobarDniVisitante
Esta funcion comprueba que el dni introducido en el menu de Login no exista entre los vistantes que se hayan registrado para
inscribirse a alguna charla*/
bool comprobarDniVisitante(std::string dniLogin, Usuario &u){
    FILE* ficheroVisitantes;
    char nombre[MAX], dni[MAX], apellido[MAX], carrera[MAX], facultad[MAX], correo[MAX];
    int curso;
    ficheroVisitantes=fopen("Visitantes.txt", "a+");
    if(ficheroVisitantes==NULL){
        printf("\nError al abrir el fichero de Visitantes");
        exit(EXIT_FAILURE);
    }
    //Busca el dni entre el dni de los visitantes registrados
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

/*FUNCION: anadirVisitante
Esta funcion perteneciente a la clase Usuario sirve para agregar los datos del visitante a nuestra base de datos.
Formato del fichero que guarda los visitantes registrados: Visitantes.txt*/
void Usuario::anadirVisitante(Usuario u){
    FILE* ficheroVisitantes;
    ficheroVisitantes=fopen("Visitantes.txt", "a+");
    if(ficheroVisitantes==NULL){
        printf("\nError al abrir el fichero de visitantes para anadir al nuevo visitante");
        exit(EXIT_FAILURE);
    }
    //Escribe los datos del visitante en el fichero
    fprintf(ficheroVisitantes, "%s %s %s %s %s %d %s\n", (u.GetDni()).c_str(), (u.GetNombre()).c_str(), (u.GetApellidos()).c_str(), (u.GetCarrera()).c_str(), (u.GetFacultad()).c_str(), u.GetCurso(), (u.GetCorreo()).c_str());

    fclose(ficheroVisitantes);
}



/*FUNCION: publicitarActividad
Esta funcion perteneciente a la clase DirectorAcademico se utiliza para publicitar las actividades generadas por correo, es decir,
el mailing. Para publicitarlas se introduce el publico al que van dirigidos, es decir, a quien mandarlas, y la actividad a publicitar*/
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
    /*BUSCAMOS LA ACTIVIDAD PARA PUBLICITARLA*/
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publicoFicheroActividades, aforo, ponentes, precio, hora, actividad)==9){
        if(strcmp(nombreActividad.c_str(), nombre)==0){
            ficheroUsuarios=fopen("Usuarios.txt", "r");
                if(ficheroUsuarios==NULL){
                    printf("\nError al abrir el fichero de usuarios");
                    fclose(ficheroActividades);
                    return false;
                }
                /*BUSCAMOS LOS USUARIOS QUE PERTENEZCAN A CIERTA CARRERA*/
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
                //Si el Director Academico ha decicido enviar el correo a todos, se le enviara la cantidad a todos los 
                //usuarios de la base de datos
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

/*FUNCION: enviarCorreo
Esta funcion la utilizamos para mnadar el correo a cada persona. Se crea un fichero con el formato BandejaEntrada+dni.txt donde se 
escribiran todos los correos de dicho usuario. El cuerpo del correo es uno de los parametros que le pasamos*/
bool enviarCorreo(std::string dni, std::string mensaje){
    FILE* ficheroBandejeEntrada;
    char nombreFicheroBandejaEntrada[MAX];
    strcpy(nombreFicheroBandejaEntrada, "BandejaEntrada");
    strcat(nombreFicheroBandejaEntrada, dni.c_str());
    strcat(nombreFicheroBandejaEntrada, ".txt");
    ficheroBandejeEntrada=fopen(nombreFicheroBandejaEntrada, "a+");
    if(ficheroBandejeEntrada==NULL){
        printf("\nError al abrir el fichero de bandeja de entrada de %s", dni.c_str());
        return false;
    }
    fprintf(ficheroBandejeEntrada, "%s\n", mensaje.c_str());
    fclose(ficheroBandejeEntrada);
    return true;
}




/*FUNCION: cuerpoCorreo
Esta funcion sirve para escribir el cuerpo del mensaje y pasarselo a la funcion de enviarCorreo*/
std::string cuerpoCorreo(std::string Emisor, std::string Destinatario, Actividad a){
    std::string cuerpo, mensaje;
    cuerpo+="Hola a todos, os enviamos una actividad en la que se van a tratar temas interesantes y dirigidos a vosotros. ";
    cuerpo+="\n\tNombre: " + a.GetNombre() + "\n\tLugar: " + a.GetLugar() + "\n\tFecha: " + a.GetFecha() + "\n\tPublico: " + a.GetPublico() + "\n\tAforo: " + std::to_string(a.GetAforo()) + "\n\tPonentes: " +a.GetPonentes() + "\n\tPrecio: " + std::to_string(a.GetPrecio()) + "\n\tHora: " + std::to_string(a.GetHora()) + "\n\tTipo de actividad: " + a.GetTipoActividad();
    cuerpo+="\nAgradecemos su participacion.\nUn cordial saludo, el Director Academico";
    mensaje+="De: " + Emisor + "\nPara: " + Destinatario + "\nMensaje: "  + cuerpo;
    return mensaje;
}


/*FUNCION: leerCorreos
Esta funcion pertenenciente a la clase Usuario sirve para leer los correos de la bandeja de entrada del usuario. Lo que hace es 
leer todas las lineas del fichero de Bandeja de Entrada e imprimirlos por pantalla*/
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
    //Imprimimos los correos del usuario
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




/*FUNCION: limpiarlinea
Funcion para eliminnar el \n y \r del final de las cadenas del tipo char* */
void limpiarlinea(char *linea){
if(linea[strlen(linea)-1]=='\n'){
	linea[strlen(linea)-1]='\0';
}
if(linea[strlen(linea)-1]=='\r'){
	linea[strlen(linea)-1]='\0';
}
}


/*FUNCION: pasarActividadHistorico
Esta funcion pertenece a la clase DirectorAcademico y sirve para pasar una actividad de las actividades activas al historico. 
EL Director Academico es el responsable de una vez realizada la actividad pasarla al fichero de historico
Formato del fichero historico: Historico.txt*/
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
    //Bucle para buscar la actividad a pasar al historico
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


/*FUNCION: listarActividadesHistorico
Esta funcion sirve para imprimir todas las actividades que pertenecen al historico. El funcionamiento en si es abrir el fichero
Historico.txt e imprimir todas sus lineas*/
void listarActividadesHistorico(){
    FILE *ficheroHistorico;
    char nombre[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    ficheroHistorico=fopen("Historico.txt", "r");
    if(ficheroHistorico==NULL){
        printf("\nError al abrir el fichero de actividades");
        exit(EXIT_FAILURE);
    }
    printf("\nACTIVIDADES DEL HISTORICO:\n");
    //Bucle para imprimir todas las lineas del fichero Historico.txt
    while(fscanf(ficheroHistorico, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        printf("\nNombre: %s\nLugar: %s\nFecha: %s\nPublico: %s\nAforo: %s\nPonente: %s\nPrecio: %s\nHora: %s\nActividad: %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad);
    }
    fclose(ficheroHistorico);
}