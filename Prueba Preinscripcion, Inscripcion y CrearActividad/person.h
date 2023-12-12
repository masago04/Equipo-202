#include <string>
#include <iostream>
#include "crearActividadH.h"
class Persona{
    private:
        std::string dni_;
        std::string nombre_;
        std::string apellidos_;

    public:
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
        int curso_;
        std::string facultad_;

    public:
        /*SETTERS O MODIFICADORES*/
        void SetCarrera(std::string carrera){carrera_=carrera;}
        void SetCurso(int curso){curso_=curso;}
        void SetFacultad(std::string facultad){facultad_=facultad;}

        /*GETTERS*/
        std::string GetCarrera(){return carrera_;}
        std::string GetFacultad(){return facultad_;}
        int GetCurso(){return curso_;}

        
        bool pagarActividad(std::string nombreActividad, Usuario u1);
        void accederWebModoUsuario(std::string username);
        //std::string GetDataUser(Usuario u);
        bool PreInscripcion(std::string nombreActividad);

};


class Organizador: public Persona{
    public:
        bool lanzarIdea();
};


class DirectorAcademico: public Persona{
    public:
        //void introducirDatosActividad(Actividad a);
        //void modificarDatosActividad(std::string nombreActividad);
        bool eliminarActividad(std::string nombreActividad);
        //Actividad búsquedaDeActividad(std::string nombre);
        //void consultarAsistencia();
        //void consultarEncuestas();
        //void accederWebModoUsuario(std::string username);
        //void accederWebModoDirectorAcademico(std::string username);
        //void enviarCorreo(std::string destinatario);
        //void hacerArticuloActividad();


        bool activarActividad();

};

class GestorDeUsuarios: public Persona{
    public:
        bool anadirUsuario(Usuario u1);
};