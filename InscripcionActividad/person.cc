#include "person.h"
#include <fstream>
#include <string.h>
#define MAX 264
void Usuario::PreInscripcion(std::string nombreActividad){
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
}

std::string Usuario::GetDataUser(Usuario u){
    std::string cad;
    cad+="Dni: " + u.GetDni() + "\n" + "Nombre: " + u.GetNombre() + "\n"+ "Apellidos: " + u.GetApellidos() + "\n" + "Carrera: " + carrera_ + "\n"+ "Facultad: " + facultad_ + "\n" + "Curso: " + std::to_string(curso_);
    return cad;
}


bool Usuario::pagarActividad(std::string nombreActividad, Usuario u1){
    FILE *ficheroActividades;
    int encontradoActividad=0, encontradoUsuario=0;
    char nombre[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    ficheroActividades=fopen("Actividades.txt", "r");
    if(ficheroActividades==NULL){
        printf("\nError al abrir el fichero Actividades");
        exit(EXIT_FAILURE);
    }
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        if(nombreActividad==nombre){
            encontradoActividad=1;
        }
    }
    if(encontradoActividad==1){
        FILE *ficheroActividadEncontrada;
        char dniFichero[MAX], nombreAlumnoActividad[MAX], apellidosAlumnoActividad[MAX], carreraAlumnoActividad[MAX], facultadAlumnoActividad[MAX];
        int cursoAlumnoActividad;

        ficheroActividadEncontrada=fopen(strcat(nombre, "Preinscritos.txt"), "r");
        if(ficheroActividadEncontrada==NULL){
            printf("\nError al abrir el fichero de PreInscritos");
            exit(EXIT_FAILURE);
        }
        while(fscanf(ficheroActividadEncontrada, "%s %s %s %s %s %d", dniFichero, nombreAlumnoActividad, apellidosAlumnoActividad, carreraAlumnoActividad, facultadAlumnoActividad, &cursoAlumnoActividad)==6){
            if(strcmp(dniFichero, (u1.GetDni()).c_str())==0){
                encontradoUsuario=1;
            }
        }
        if(encontradoUsuario==1){
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
            ficheroInscripcion=fopen(strcat(nombre, "Inscritos.txt"), "a+");//TODO: cambiar nombre por nombreActividad del inicio convertida a cadena de tipo C
            if(ficheroInscripcion==NULL){
                printf("\nError al abrir el fichero");
                exit(EXIT_FAILURE);
            }
            fprintf(ficheroInscripcion, "%s %s %s %s %s %d\n", (u1.GetDni()).c_str(), (u1.GetNombre()).c_str(), (u1.GetApellidos()).c_str(), (u1.GetCarrera()).c_str(), (u1.GetFacultad()).c_str(), u1.GetCurso());
            std::cout<<"\nAlumno "<<u1.GetDni()<<" inscrito en la actividad "<<nombreActividad<<" con éxito"<<std::endl;
            return true;
        }
        else{
            std::cout<<"El alumno no esta preinscrito en la actividad "<<nombreActividad<<std::endl;
            return false;
        }
    }
    else{
        std::cout<<"La actividad "<<nombreActividad<<" no existe"<<std::endl;
        return false;
        //TODO: PONER QUE NO ESTA LA ACTIVIDAD
    }
}

bool GestorDeUsuarios::anadirUsuario(Usuario u1){
    FILE *fichero;
    char dniFichero[MAX], nombre[MAX], apellidos[MAX], carrera[MAX], facultad[MAX];
    int curso;
    char nombreaBuscar[MAX]="Pepe";
    fichero=fopen("pruebaEscribirFichero.txt", "a+");
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
