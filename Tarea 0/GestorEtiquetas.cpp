/**
 * Implementación de la clase GestorEtiquetas
 * Tarea 0 - CI1310
 * Valeria Zamora - B37743
 * 
 * Clase encargada del manejo de las etiquetas
 * */

#include "GestorEtiquetas.h"
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

/* Constructor de GestorEtiquetas
*/
GestorEtiquetas::GestorEtiquetas(){}

GestorEtiquetas::~GestorEtiquetas(){}

/* Agrega una etiqueta a la estructura de datos que las contiene.
*/
bool GestorEtiquetas::addEtiqueta(string etiqueta){
    bool agregado = false;
    int cont = 0;
    map<string, int>::iterator it = diccionarioEtiquetas.find(etiqueta);
    if (it != diccionarioEtiquetas.end()){ //ya esta la etiqueta en el diccionario
        cont = ++it->second;
        diccionarioEtiquetas[etiqueta] = cont;
        agregado = true;
    }else{
        diccionarioEtiquetas.insert(make_pair(etiqueta, 1));
        agregado = true;
    }
    return agregado;
}

/* Metodo que se encarga de imprimir todas las etiquetas y su contador en la línea de comandos
*/
void GestorEtiquetas::imprimirEtiquetas(){
    cout << "Etiquetas:" << endl;
    map<string, int>::iterator itr = diccionarioEtiquetas.begin();
    for(itr = diccionarioEtiquetas.begin(); itr != diccionarioEtiquetas.end(); ++itr){
        cout << itr->first << ": " << itr->second << endl;
    }
}

/* Extrae las etiquetas de un string
*  
*/
string GestorEtiquetas::extraerContenido(string linea){
    string salida;
    bool contenido = false;
    if(!linea.empty()){
        contenido = true;
        int cont = 0;
        char c = linea.at(cont);    //primer caracter de la linea
        string temp;
        while(cont < linea.length()){   //no se haya acabado la linea
	    c = linea.at(cont);
            if(c == '<'){   // si encuentra una etiqueta inicio etiqueta
                ++cont;     //primer caracter de la etiqueta
		        c = linea.at(cont);
                while(c != ' ' && c != '>'){    // busca final de etiqueta
                    temp += c ;
                    ++cont;
                    c = linea.at(cont);
                }
                this->addEtiqueta(temp);
                temp.clear();
            }else{
                salida += c;
            }
            ++cont;
        }
    }
    return salida;  
}

