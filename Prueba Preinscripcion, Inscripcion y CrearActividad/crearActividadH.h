#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Actividad{
    private:
        std::string nombre_;
        std::string lugar_;
        std::string fecha_;
        std::string publico_;
        int aforo_;
        std::string ponentes_;
        float precio_;
        int hora_;
        std::string tipoActividad_;
        std::vector<Actividad> listaActividades;
    public:
        /*GETTERS*/
        std::string GetNombre(){return nombre_;}
        std::string GetLugar(){return lugar_;}
        std::string GetFecha(){return fecha_;}
        std::string GetPublico(){return publico_;}
        int GetAforo(){return aforo_;}
        std::string GetPonentes(){return ponentes_;}
        float GetPrecio(){return precio_;}
        int GetHora(){return hora_;}
        std::string GetTipoActividad(){return tipoActividad_;}

        /*SETTERS*/
        void SetNombre(std::string nombre){nombre_=nombre;}
        void SetLugar(std::string lugar){lugar_=lugar;}
        void SetFecha(std::string fecha){fecha_=fecha;}
        void SetPublico(std::string publico){publico_=publico;}
        void SetAforo(int aforo){aforo_=aforo;}
        void SetPonentes(std::string ponentes){ponentes_=ponentes;}
        void SetPrecio(float precio){precio_=precio;}
        void SetHora(int hora){hora_=hora;}
        void SetTipoActividad(std::string tipoActividad){tipoActividad_=tipoActividad;}

        /*FUNCIONES*/
        bool crearActividad(std::string nombre,std::string lugar,std::string fecha, std::string publico,int aforo,std::string ponentes,float precio,int hora,std::string tipoActividad);
        void eliminarActividad(const std::string &archivo, const std::string &nombreActividad);
        //void modificarActividad(std::string nombre);
        //void busquedaActividad(std::string &archivo,std::string actividad);
        int consultarAsistentes(std::string nombre);
        //void guardarActividad();
        //void copiarVector(std::vector<Actividad> listaActividades, std::string archivo);
        void listarActividades();

};