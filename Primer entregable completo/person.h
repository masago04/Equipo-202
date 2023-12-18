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
        std::string correo_;

    public:
        Usuario(std::string dni, std::string nombre="", std::string apellidos="", std::string carrera="", std::string facultad="", int curso=0, std::string correo=""):Persona(dni, nombre, apellidos){
            carrera_=carrera;
            facultad_=facultad;
            curso_=curso;
            correo_=correo;
        }
        /*SETTERS O MODIFICADORES*/
        void SetCarrera(std::string carrera){carrera_=carrera;}
        void SetCurso(int curso){curso_=curso;}
        void SetFacultad(std::string facultad){facultad_=facultad;}
        void SetCorreo(std::string correo){correo_=correo;}
        /*GETTERS*/
        std::string GetCarrera(){return carrera_;}
        std::string GetFacultad(){return facultad_;}
        int GetCurso(){return curso_;}
        std::string GetCorreo(){return correo_;}

        
        bool InscripcionyPago(std::string nombreActividad, Usuario u1);
        void accederWebModoUsuario(std::string username);
        bool PreInscripcion(std::string nombreActividad, Usuario u);
        bool accederWeb(std::string dni, Usuario &u);
        bool cancelarInscripcion(std::string nombreActividad, Usuario u);
        void imprimirJustificantedePago(std::string nombreActividad, float precio, Usuario u);
        void anadirVisitante(Usuario u);
        bool leerCorreos(std::string dni);


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
        void escribirAgradecimientos(std::string nombreActividad, std::string ponente);
        bool publicitarActividad(std::string nombreActividad, std::string publico);
        bool pasarActividadHistorico(std::string nombreActividad);

};

class GestorDeUsuarios: public Persona{
    public:
    GestorDeUsuarios(std::string dni, std::string nombre="", std::string apellidos=""):Persona(dni, nombre, apellidos){}
        bool anadirUsuario(Usuario u1);
};


bool ContarLineasFichero(char *nombreFichero, int n);
bool comprobarDniVisitante(std::string dniLogin, Usuario &u);
std::string cuerpoCorreo(std::string Emisor, std::string Destinatario, Actividad a);
bool enviarCorreo(std::string dni, std::string mensaje);
void limpiarlinea(char *linea);
void listarActividadesHistorico();