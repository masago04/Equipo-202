#include <string>
#include <iostream>
#include "crearActividadH.h"
class Persona{
    private:
        std::string dni_;
        std::string nombre_;
        std::string apellidos_;

    public:
        Persona(std::string dni, std::string nombre="", std::string apellidos=""){
            dni_=dni;
            nombre_=nombre;
            apellidos_=apellidos;
        }
        /*SETTERS*/
        void SetDni(std::string dni){dni_=dni;}
        void SetNombre(std::string nombre){nombre_=nombre;}
        void SetApellidos(std::string apellidos){apellidos_=apellidos;}

        /*GETTERS*/
        std::string GetDni(){return dni_;}
        std::string GetNombre(){return nombre_;}
        std::string GetApellidos(){return apellidos_;}
};



class Usuario: public Persona{
    private:
        std::string carrera_;
        std::string facultad_;
        int curso_;


    public:
        Usuario(std::string dni, std::string nombre="", std::string apellidos="", std::string carrera="", std::string facultad="", int curso=0):Persona(dni, nombre, apellidos){
            carrera_=carrera;
            facultad_=facultad;
            curso_=curso;
        }
        /*SETTERS O MODIFICADORES*/
        void SetCarrera(std::string carrera){carrera_=carrera;}
        void SetCurso(int curso){curso_=curso;}
        void SetFacultad(std::string facultad){facultad_=facultad;}

        /*GETTERS*/
        std::string GetCarrera(){return carrera_;}
        std::string GetFacultad(){return facultad_;}
        int GetCurso(){return curso_;}

        
        bool InscripcionyPago(std::string nombreActividad, Usuario u1);
        void accederWebModoUsuario(std::string username);
        bool PreInscripcion(std::string nombreActividad, Usuario u);
        bool accederWeb(std::string dni, Usuario &u);

};


class Organizador: public Persona{
    public:
        Organizador(std::string dni, std::string nombre="", std::string apellidos=""):Persona(dni, nombre, apellidos){}
        bool lanzarIdea();
};


class DirectorAcademico: public Persona{
    public:
        DirectorAcademico(std::string dni, std::string nombre="", std::string apellidos=""):Persona(dni, nombre, apellidos){}
        void eliminarActividad(std::string nombreActividad);
        bool activarActividad();

};

class GestorDeUsuarios: public Persona{
    public:
    GestorDeUsuarios(std::string dni, std::string nombre="", std::string apellidos=""):Persona(dni, nombre, apellidos){}
        bool anadirUsuario(Usuario u1);
};