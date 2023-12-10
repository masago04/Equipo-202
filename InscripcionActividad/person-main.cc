#include "person.h"

int main(){
    std::string nombreactividad;
    Usuario u1;
    GestorDeUsuarios g1;
    std::string dni, nombre, apellidos, carrera, facultad;
    int curso;
    /*std::cout<<"Introduzca el nombre de la actividad a la que inscribirse: ";
    std::cin>>nombreactividad;

    u1.PreInscripcion(nombreactividad);*/

    u1.SetNombre("Mario");
    u1.SetApellidos("Sanchez");
    u1.SetDni("94561945G");
    u1.SetCarrera("Informatica");
    u1.SetCurso(2);
    u1.SetFacultad("EPS");

    std::cout<<"Introduce el nombre de la Actividad a realizar el pago: ";
    std::cin>>nombreactividad;
    if(u1.pagarActividad(nombreactividad, u1)==true){
        std::cout<<"Pago realizado con exito"<<std::endl;
    }
    else{
        std::cout<<"Pago rechazado"<<std::endl;
    }
}