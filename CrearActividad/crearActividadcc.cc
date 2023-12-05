#include "crearActividadH.h"
#include <fstream>
void Actividad::crearActividad(std::string nombre,std::string lugar,std::string fecha, std::string publico,int aforo,std::string ponentes,float precio,int hora,std::string tipoActividad){
    SetNombre(nombre);
    SetLugar(lugar);
    SetFecha(fecha);
    SetPublico(publico);
    SetAforo(aforo);
    SetPonentes(ponentes);
    SetPrecio(precio);
    SetHora(hora);
    SetTipoActividad(tipoActividad);
    listaActividades.push_back(*this);
}



void Actividad::modificarActividad(std::string nombre){
    
    for(long unsigned int i=0; i<listaActividades.size(); i++){
        if(listaActividades[i].GetNombre() == nombre){
            std::cout << "Ingrese el nuevo nombre de la actividad: ";
            std::string nuevoNombre;
            std::cin >> nuevoNombre;
            listaActividades[i].SetNombre(nuevoNombre);
        }
    }
}
void Actividad::copiarVector(std::vector<Actividad> listaActividades, std::string archivo){
    std::ofstream archivoSalida(archivo);
    if(archivoSalida.is_open()){
        for(long unsigned int i=0; i<listaActividades.size(); i++){
            archivoSalida <<"Nombre:"<< listaActividades[i].GetNombre() << ","<<"Lugar:"<< listaActividades[i].GetLugar() << ","<<"Fecha:"<< listaActividades[i].GetFecha() << ","<<"Publico:"<< listaActividades[i].GetPublico() << ","<<"Aforo:" << listaActividades[i].GetAforo() << ","<<"Ponentes:"<< listaActividades[i].GetPonentes() << ","<<"Precio:" << listaActividades[i].GetPrecio() << ","<<"Hora:" << listaActividades[i].GetHora() << ","<<"Actividad"<< listaActividades[i].GetTipoActividad() << std::endl;
        }
        archivoSalida.close();
    }else{
        std::cout << "Error al abrir el archivo" << std::endl;
    }
}
void Actividad::eliminarActividad(const std::string &archivo, const std::string &nombreActividad) {
    std::string line;
    std::fstream readFile(archivo);
    std::fstream writeFile("temp.txt");

    if (readFile.is_open()) {
        while (std::getline(readFile, line)) {
            if (line != nombreActividad) {
                writeFile << line << std::endl;
            }
        }
        readFile.close();
        writeFile.close();
        remove(archivo.c_str());
        rename("temp.txt", archivo.c_str());
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}
void Actividad::busquedaActividad(std::string &archivo,std::string actividad){
    std::string line;
    std::ifstream readFile(archivo);
    if(readFile.is_open()){
        while(std::getline(readFile,line)){
            std::cout<<line<<std::endl;
            std::cout<<"\n"<<std::endl;
        }
    }
    else{
        std::cout<<"No se puede abrir"<<std::endl;
    }
}