#include "crearActividadH.h"
#include <fstream>
#include <string.h>
#define MAX 264




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
            printf("\nLa actividad %s ya esta registrada", (a.GetNombre()).c_str());
            return false;
        }
    }
    fprintf(ficheroActividades, "%s %s %s %s %d %s %f %d %s\n", (a.GetNombre()).c_str(), (a.GetLugar()).c_str(), (a.GetFecha()).c_str(), (a.GetPublico()).c_str(), a.GetAforo(), (a.GetPonentes()).c_str(), a.GetPrecio(), a.GetHora(), (a.GetTipoActividad()).c_str());
    fclose(ficheroActividades);
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
        printf("\nNombre: %s\nLugar: %s\nFecha: %s\nPublico: %s\nAforo: %s\nPonente: %s\nPrecio: %s\nHora: %s\nActividad: %s", nombre, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad);
    }
    fclose(ficheroActividades);
}



/*void Actividad::eliminarActividad(std::string nombreActividad){
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
}*/


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