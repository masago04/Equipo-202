#include "correoH.h"
#include <iomanip>
#include <sstream>
// Implementación de la función EnviarCorreo
std::string Email::EnviarCorreo(std::string usernname, std::string dominio){
    std::string correo = usernname + "@" + dominio;
    correos[correo] = correo;
    return "Correo enviado a " + correo;
}
// Implementación de la función LeerCorreo
void Email::LeerCorreo() {
    std::ifstream archivo("datos_correos.txt");
    std::string correo;

    if(archivo.is_open()){
        while(std::getline(archivo, correo)){
            std::cout << correo << std::endl;
        }
        archivo.close();
    } else {
        std::cout << "No se pudo abrir el archivo para leer los correos" << std::endl;
    }
    // Limpieza del buffer
    std::fflush(stdout);
}

// Implementación de la función ProgramarEnvio
void Email::ProgramarEnvio(std::string fecha, int hora){
    std::cout << "Correo programado para enviar el " << fecha << " a las " << hora << " horas" << std::endl;
}

// Implementación de la función SeleccionarDestinatarios
void Email::SeleccionarDestinatarios(std::string fichero_destinatarios){
    std::ifstream archivo(fichero_destinatarios);
    std::string destinatario;

    if(archivo.is_open()){
        while(std::getline(archivo, destinatario)){
            correos[destinatario] = destinatario;
        }
        archivo.close();
    } else {
        std::cout << "No se pudo abrir el archivo " << fichero_destinatarios << std::endl;
    }
}
void Email::VolcarDatos() {
    FILE *archivo = fopen("datos_correos.txt", "a");
    if(archivo){
        for(auto & correo : correos){
            fprintf(archivo, "%s\n", correo.first.c_str());
        }
        fclose(archivo);
    } else {
        std::cout << "No se pudo abrir el archivo para volcar los datos" << std::endl;
    }
    // Limpieza del buffer
    std::fflush(stdout);
}

void Email::redactarCorreo(std::string nombre,std::string lugar,std::string fecha, std::string publico,int aforo,std::string ponentes,float precio,int hora,std::string tipoActividad)
{
    std::ofstream archivo("correo.txt"); 
    std::cout<<"Tipo Actividad"<<std::endl;
    std::cin>>tipoActividad;
    archivo << "Asunto: Invitación a " << tipoActividad << std::endl;
    std::cout<<"Nombre"<<std::endl;
    std::cin>>nombre;
    archivo << "Nombre del evento: " << nombre << std::endl;
    std::cout<<"Lugar"<<std::endl;
    std::cin>>lugar;
    archivo << "Lugar: " << lugar << std::endl;
    std::cout<<"Fecha"<<std::endl;
    std::cin>>fecha;
    archivo << "Fecha: " << fecha << std::endl;
    std::cout<<"Publico"<<std::endl;
    std::cin>>publico;
    archivo << "Público: " << publico << std::endl;
    std::cout<<"Aforo"<<std::endl;
    std::cin>>aforo;
    archivo << "Aforo: " << aforo << std::endl;
    std::cout<<"Ponentes"<<std::endl;
    std::cin>>ponentes;
    archivo << "Ponentes: " << ponentes << std::endl;
    std::cout<<"Precio"<<std::endl;
    std::cin>>precio;
    archivo << "Precio: " << precio << std::endl;
    std::cout<<"Hora"<<std::endl;
    std::cin>>hora;
    archivo << "Hora: " << hora << std::endl;
    archivo.close();
}
void Email::mostrarMenu() {
    int opcion;
    std::cout << "Menu de opciones:\n";
    std::cout << "1. Registra correos electronicos.\n";
    std::cout << "2. Redactar Correo.\n";
    std::cout << "3. Programar envio de correo electronico.\n";
    std::cout << "4. Seleccionar destinatarios.\n";
    std::cout << "5. Leer correos.\n";
    std::cout << "6. Salir\n";


    Email correo;
    std::string username, dominio, fecha;
    std::string fichero_destinatarios;
    std::string nombre, lugar, publico, ponentes, tipoActividad;
    int aforo=0,hora=0;
    float precio=0.0;
do{
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;
    switch (opcion) {
        case 1:
            std::cout << "Introduzca su nombre de usuario: ";
            std::cin >> username;
            std::cout << "Introduzca el dominio: ";
            std::cin >> dominio;
            std::cout<<correo.EnviarCorreo(username, dominio)<<std::endl;
            correo.VolcarDatos();
            break;
        case 2:
        
            correo.redactarCorreo(nombre,lugar,fecha,publico,aforo,ponentes,precio,hora,tipoActividad);
            break;
        case 3:
            std::cout << "Introduzca la fecha: ";
            std::cin >> fecha;
            std::cout << "Introduzca la hora: ";
            std::cin >> hora;
            correo.ProgramarEnvio(fecha, hora);
            break;
        case 4:
            std::cout << "Introduzca el nombre del archivo de destinatarios: ";
            std::cin >> fichero_destinatarios;
            correo.SeleccionarDestinatarios(fichero_destinatarios);
            break;
        case 5:
            std::cout<<"Leer correos"<<std::endl;
            correo.LeerCorreo();
            break;
        case 6:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opción no válida.\n";
            break;
    }
    }while (opcion!=6);
}
