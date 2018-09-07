#include 'GestorEtiquetas.h'

GestorEtiquetas:GestorEtiquetas(){

}

bool GestorEtiquetas:addEtiqueta(string etiqueta){
    bool agregado = false;
    int cont = 0;
    map<std::string, int>::iterator it = diccionarioEtiquetas.find(etiqueta);
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
void GestorEtiquetas:imprimirEtiquetas(){
    cout << "Etiqueta\tContador" << endl;
    map<string, int>::iterator it = diccionarioEtiquetas.begin();
    for(itr = diccionarioEtiquetas.begin(); itr != diccionarioEtiquetas.end(); ++itr){
        cout << itr->first << "\t" << itr->second << endl;
    }
}

void extraerContenido(string linea){

}
