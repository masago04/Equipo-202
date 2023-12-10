#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include "crearActividadH.h"
class Email{

    private:
        std::string username_;
        std::string dominio_;
        std::map<std::string, std::string> correos;
    public:
        std::string EnviarCorreo(std::string usernname, std::string dominio);
        void LeerCorreo();
        void ProgramarEnvio(std::string fecha, int hora);
        void SeleccionarDestinatarios(std::string fichero_destinatarios);
        std::string GetUsername(){return username_;}
        void SetUsername(std::string username){username_=username;}
        void VolcarDatos();
        void redactarCorreo(std::string nombre,std::string lugar,std::string fecha, std::string publico,int aforo,std::string ponentes,float precio,int hora,std::string tipoActividad);
        void mostrarMenu();
};