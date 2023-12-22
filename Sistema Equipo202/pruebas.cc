#include <iostream>
#include "person.h"
#include <string.h>
#define MAX 264
int prueba1(Usuario &u);
int contarLineasFicheroInscritos(std::string nombreActividad);
int prueba2(Usuario u, GestorDeUsuarios gestor);
int contarLineasPrueba2();
int prueba3();
int contarLineasPrueba3();
int prueba4(DirectorAcademico da);
int prueba5(int& retornoActividades, DirectorAcademico da);
int contarLineasHistorico();
int prueba6(Usuario &u);
int main(){
    DirectorAcademico directorAc("Director"); 
    Organizador organizador("Organizador"); 
    GestorDeUsuarios gestor("Gestor");
    Usuario user("1A", "Ricardo", "Diaz", "Enfermeria", "US", 1, "i23ricdi@uco.es");
    Actividad a;

    remove("Actividades.txt");
    remove("Actividad1Preinscritos.txt");
    remove("Actividad1Inscritos.txt");
    remove("Usuarios.txt");
    a.SetNombre("Actividad1");
    a.SetLugar("Aulario");
    a.SetFecha("16/01/23");
    a.SetPublico("Todos");
    a.SetAforo(50);
    a.SetPonentes("D.Gomez");
    a.SetPrecio(15);
    a.SetHora(18);
    a.SetTipoActividad("Ponencia");
    a.crearActividad(a);
    std::cout<<"Actividad 1 creada"<<std::endl;

    /*PRUEBA 1*/
    printf("\n\n\nREALIZANDO LA PRUEBA 1...");
    int retornoPrueba1;
    retornoPrueba1=prueba1(user);
    if(retornoPrueba1!=1){
        printf("\n\tError en la prueba 1, valor esperado 1 y el valor devuelto ha sido %d", retornoPrueba1);
    }
    else{
        printf("\n\tPrueba 1 CORRECTA, valor esperado 1 y el valor devuelto ha sido %d", retornoPrueba1);

    }

    /*PRUEBA 2*/
    printf("\n\n\nREALIZANDO LA PRUEBA 2...");
    int retornoPrueba2;
    retornoPrueba2=prueba2(user, gestor);
    if(retornoPrueba2!=1){
        printf("\n\tError en la prueba 2, valor esperado 1 y el valor devuelto ha sido %d", retornoPrueba2);
    }
    else{
        printf("\n\tPrueba 2 CORRECTA, valor esperado 1 y el valor devuelto ha sido %d", retornoPrueba2);

    }


    /*PRUEBA 3*/
    printf("\n\n\nREALIZANDO LA PRUEBA 3...");
    int retornoPrueba3;
    retornoPrueba3=prueba3();
    if(retornoPrueba3!=2){
        printf("\n\tError en la prueba 3, valor esperado 2 y el valor devuelto ha sido %d", retornoPrueba3);
    }
    else{
        printf("\n\tPrueba 3 CORRECTA, valor esperado 2 y el valor devuelto ha sido %d", retornoPrueba3);
    }


    /*PRUEBA 4*/
    printf("\n\n\nREALIZANDO LA PRUEBA 4...");
    int retornoPrueba4;
    retornoPrueba4=prueba4(directorAc);
    if(retornoPrueba4!=1){
        printf("\n\tError en la prueba 4, valor esperado 1 y el valor devuelto ha sido %d", retornoPrueba4);
    }
    else{
        printf("\n\tPrueba 4 CORRECTA, valor esperado 1 y el valor devuelto ha sido %d", retornoPrueba4);
    }

    /*PRUEBA 5*/
    printf("\n\n\nREALIZANDO LA PRUEBA 5...");
    int retornoActividadesPrueba5, retornoHistoricoPrueba5;
    retornoHistoricoPrueba5=prueba5(retornoActividadesPrueba5, directorAc);
    if(retornoHistoricoPrueba5!=1 && retornoActividadesPrueba5!=1){
        printf("\n\tError en la prueba 5, valor esperado en el fichero Historico.txt es 1 y el valor devuelto ha sido %d, y el valor esperado en el fichero Actividades.txt es 1 y el valor davuelto ha sido %d", retornoHistoricoPrueba5, retornoActividadesPrueba5);
    }
    else{
        printf("\n\tPrueba 5 CORRECTA, valor esperado en el fichero Historico.txt es 1 y el valor devuelto ha sido %d, y el valor esperado en el fichero Actividades.txt es 1 y el valor davuelto ha sido %d", retornoHistoricoPrueba5, retornoActividadesPrueba5);

    }

    /*PRUEBA 6*/
    printf("\n\n\nREALIZANDO LA PRUEBA 6...");
    int retornoPrueba6;
    retornoPrueba6=prueba6(user);
    if(retornoPrueba6!=0){
        printf("\n\tError en la prueba 6, valor esperado es 0 y el valor devuelto ha sido %d", retornoPrueba6);
    }
    else{
        printf("\n\tPrueba 6 CORRECTA, valor esperado es 0 y el valor devuelto ha sido %d\n", retornoPrueba6);
    }

}

/*PRUEBA1: Prueba para comprobar que no podamos inscribir dos veces a una misma persona
Tras ejecutarla vemos que inscribia dos veces al alumno ya que este no se borraba de los preinscritos. tras ello le hemos añadido
a la funcion de InscripcionyPago una parte donde al realizar la inscripcion elimina al usuario del fichero de preinscritos, 
permitiendo que solo se inscriba una vez*/
int prueba1(Usuario &u){
    int retorno;
    bool comprobarPreinscripcion;
    
    comprobarPreinscripcion= u.PreInscripcion("Actividad1", u);
    if(comprobarPreinscripcion==true){
        printf("\nAlumno preinscrito");
    }
    else{
        printf("\nPreinscripcion no realizada");
    }
    u.InscripcionyPago("Actividad1", u);
    printf("\nAlumno inscrito (primera vez)\n");
    u.InscripcionyPago("Actividad1", u);
    
    retorno=contarLineasFicheroInscritos("Actividad1");
    return retorno;

}



int contarLineasFicheroInscritos(std::string nombreActividad){
    FILE* ficheroInscritos;
    char nombreFicheroInscritos[264];
    char dniFichero[MAX], nombre[MAX], apellidos[MAX], carrera[MAX], facultad[MAX], correo[MAX];
    int curso, cont=0;

    strcpy(nombreFicheroInscritos, nombreActividad.c_str());
    strcat(nombreFicheroInscritos, "Inscritos.txt");
    ficheroInscritos=fopen(nombreFicheroInscritos, "r");
    if(ficheroInscritos==NULL){
        return 0;
    }
    while(fscanf(ficheroInscritos, "%s %s %s %s %s %d %s\n", dniFichero, nombre, apellidos, carrera, facultad, &curso, correo)==7){
    cont++;
    }
    return cont;

}

/*PRUEBA 2: Comprueba que el gestor no pueda agregar dos veces a una persona con el mismo DNI. Para ello intenta agregar dos 
veces al mismo usuario y luego cuenta el numero de lineas del fichero*/
int prueba2(Usuario u, GestorDeUsuarios gestor){
    int retorno;

    gestor.anadirUsuario(u);
    gestor.anadirUsuario(u);


    retorno=contarLineasPrueba2();
    return retorno;
}


int contarLineasPrueba2(){
    FILE* ficheroUsuarios;
    char dniFichero[MAX], nombre[MAX], apellidos[MAX], carrera[MAX], facultad[MAX], correo[MAX];
    int curso, cont=0;

    
    ficheroUsuarios=fopen("Usuarios.txt", "r");
    if(ficheroUsuarios==NULL){
        return 0;
    }
    while(fscanf(ficheroUsuarios, "%s %s %s %s %s %d %s\n", dniFichero, nombre, apellidos, carrera, facultad, &curso, correo)==7){
    cont++;
    }
    return cont;

}

/*PRUEBA 3: Comprueba que no podemos anadir dos actividades con el mismo nombre porque si esto llega a ocurrir podemos tener
bastantes problemas al llamar a las demas funciones, ya que muchas de ellas se les pasa como parametros el nombre de la actividad
y si hay dos con el mismo nombre podemos hacer que alguien se inscriba en una actividad que no es por ejemplo. Tras ejecutarla
vimoss que si que la anadia, por lo que agregamos un bucle antes de agregar la actividad para leer activididad por actividad
del fichero Actividades.txt y si el nombre introducido existia devuelve false y no lo agrega*/

int prueba3(){
    int retorno;
    //Declaramos e inicializamos la actividad
    Actividad a1;
    a1.SetNombre("ActividadPrueba3");
    a1.SetLugar("P3");
    a1.SetFecha("26/01/23");
    a1.SetPublico("Informatica");
    a1.SetAforo(10);
    a1.SetPonentes("Pr.Hidalgo");
    a1.SetPrecio(5);
    a1.SetHora(11);
    a1.SetTipoActividad("Charla");

    //Agregamos la actividad por primera vez
    a1.crearActividad(a1);

    //Agregamos la misma actividad otra vez
    a1.crearActividad(a1);
    
    retorno=contarLineasPrueba3();
    return retorno;
}

int contarLineasPrueba3(){
    FILE* ficheroActividades;
    int cont=0;
    char nombreActividadLocal[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    
    ficheroActividades=fopen("Actividades.txt", "r");
    if(ficheroActividades==NULL){
        return 0;
    }
    while(fscanf(ficheroActividades, "%s %s %s %s %s %s %s %s %s\n", nombreActividadLocal, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        cont++;
    }
    return cont;
}


/*PRUEBA 4: Esta prueba comprueba que se elimina bien una actividad, en concreto va a eliminar la actividad agregada en la 
prueba anterior y luego va a contar el numero de actividades registradas en el fichero de Actividades.txt . Como en el main agregamos
una actividad y luego agregamos otra , tras eliminar una de las dos el resultado a de ser 1*/

int prueba4(DirectorAcademico da){
    int retorno;
    //Declaramos e inicializamos la actividad
    Actividad a1;
    a1.SetNombre("ActividadPrueba3");
    a1.SetLugar("P3");
    a1.SetFecha("26/01/23");
    a1.SetPublico("Informatica");
    a1.SetAforo(10);
    a1.SetPonentes("Pr.Hidalgo");
    a1.SetPrecio(5);
    a1.SetHora(11);
    a1.SetTipoActividad("Charla");

    //Agregamos la actividad por primera vez
    a1.crearActividad(a1);

    //Agregamos la misma actividad otra vez
    da.eliminarActividad(a1.GetNombre());

    //Contamos las actividaes registradas en el fichero Actividades.txt    
    retorno=contarLineasPrueba3();
    return retorno;
}



/*PRUEBA 5; Esta prueba comprueba que al pasar una actividad al historico, en el fichero Actividades.txt haya una ctividad menos y
en el fichero de Historico.txt haya una actividad mas*/
int prueba5(int& retornoActividades, DirectorAcademico da){
    int retornoHistorico;
    
    //Declaramos e inicializamos la actividad
    Actividad a1;
    a1.SetNombre("ActividadPrueba5");
    a1.SetLugar("P3");
    a1.SetFecha("26/01/23");
    a1.SetPublico("Informatica");
    a1.SetAforo(10);
    a1.SetPonentes("Pr.Hidalgo");
    a1.SetPrecio(5);
    a1.SetHora(11);
    a1.SetTipoActividad("Charla");

    //Agregamos la actividad por primera vez
    a1.crearActividad(a1);

    //Pasamos la actividad al historico
    da.pasarActividadHistorico(a1.GetNombre());

    //Contamos el numero de actividades en Actividades.txt
    retornoActividades=contarLineasPrueba3();

    //Contamos el numero de actividades en el historico
    retornoHistorico=contarLineasHistorico();
    return retornoHistorico;
}


int contarLineasHistorico(){
    FILE* ficheroHistorico;
    int cont=0;
    char nombreActividadLocal[MAX], lugar[MAX], fecha[MAX], publico[MAX], aforo[MAX], ponentes[MAX], precio[MAX], hora[MAX], actividad[MAX];
    
    ficheroHistorico=fopen("Historico.txt", "r");
    if(ficheroHistorico==NULL){
        return 0;
    }
    while(fscanf(ficheroHistorico, "%s %s %s %s %s %s %s %s %s\n", nombreActividadLocal, lugar, fecha, publico, aforo, ponentes, precio, hora, actividad)==9){
        cont++;
    }
    return cont;
}


/*PRUEBA 6: La prueba consiste en inscribir un alumno a una actividad y cancelar su inscripcion, contando el numero de alumnos
inscritos en la actividad. En nuestro caso va a haber 0 inscritos tras su cancelacion ya que vamos a inscribir a un alumno y justo 
despues lo vamos a sacar de dicho fichero*/

int prueba6(Usuario &u){
    int retorno;
    bool comprobarPreinscripcion;
    
    //Preinscribimos al alumno
    comprobarPreinscripcion= u.PreInscripcion("Actividad1", u);
    if(comprobarPreinscripcion==true){
        printf("\nAlumno preinscrito");
    }
    else{
        printf("\nPreinscripcion no realizada");
    }
    //Inscribimos al alumno
    u.InscripcionyPago("Actividad1", u);
    printf("\nAlumno inscrito (primera vez)\n");

    //Cancelamos su inscripcion
    u.cancelarInscripcion("Actividad1", u);    
    retorno=contarLineasFicheroInscritos("Actividad1");
    return retorno;
}