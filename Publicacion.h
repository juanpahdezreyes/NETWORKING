#ifndef Publicacion_h
#define Publicacion_h

#include "usuario.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Publicacion_ {
private:
    static int idCounter;
    int id;

public:
  string fecha;
  string contenido;
  Usuario_* usuario;

    Publicacion_(Usuario_* _usuario, string _fecha, string _contenido) {
      this->usuario=_usuario;
      this->fecha=_fecha;
      this->contenido=_contenido;
    }

    void mostrarPublicacion() {
        cout << "Fecha: " << fecha << endl;
        cout << "Contenido: " << contenido << endl;
        cout << "Usuario: " << usuario->nombre() << endl;
    }

    int getId() {
        return id;
    }
};

#endif