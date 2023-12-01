#include "ej.h"
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

/*void Actividad::eliminarActividad(std::string nombre){
    for(long unsigned int i=0; i<listaActividades.size(); i++){
        if(listaActividades[i].GetNombre() == nombre){
            listaActividades.erase(listaActividades.begin()+i);
            break;
        }
    }
}*/

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
            archivoSalida << listaActividades[i].GetNombre() << "," << listaActividades[i].GetLugar() << "," << listaActividades[i].GetFecha() << "," << listaActividades[i].GetPublico() << "," << listaActividades[i].GetAforo() << "," << listaActividades[i].GetPonentes() << "," << listaActividades[i].GetPrecio() << "," << listaActividades[i].GetHora() << "," << listaActividades[i].GetTipoActividad() << std::endl;
        }
        archivoSalida.close();
    }else{
        std::cout << "Error al abrir el archivo" << std::endl;
    }
}
void Actividad::eliminarActividad(const std::string &archivo, const std::string &nombreActividad) {
    std::string line;
    std::ifstream readFile(archivo);
    std::ofstream writeFile("temp.txt");

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
