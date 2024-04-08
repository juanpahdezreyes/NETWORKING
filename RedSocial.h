#ifndef RedSocial_h
#define RedSocial_h

#include "usuario.h"

#include "Publicacion.h"

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class RedSocial_ {
private:
    string nombre;
    vector<Usuario_*> usuarios;
    vector<Publicacion_*> publicaciones;
public:

   int numeroDeUsuarios;
   int numeroDePublicaciones;



    void agregarUsuario(Usuario_* nuevoUsuario) {
        usuarios.push_back(nuevoUsuario);
    }

   void mostrarUsuarios() {
      for (int i=0;i<usuarios.size();i++){
         usuarios[i]->mostrar();
         cout << endl;
      }
    }


    void mostrarPublicaciones() {
      for (int i=0;i<publicaciones.size();i++){
          publicaciones[i]->mostrarPublicacion();
      }
    }

    Usuario_* getUsuario(int id) {
      int encontrado=0;
      for (int i=0;i<usuarios.size();i++){
          if (id==usuarios[i].getId){ //<-- morstrar al profe
              return usuarios[i];
              encontrado=1;
              i=usuarios.size();
          }
      }
      if (encontrado==0){
        cout<<"No se encontro ningun usuario con este id";
        return nullptr;
      }
    }

    RedSocial_(string nombre){
        this->nombre=nombre;
    }

    RedSocial_(string nombre, vector <Usuario_*> usuario){//<-- mandar al profe ningun Usuario_* sirve
        this->nombre=nombre;
        this->usuarios=usuario;
    }

    RedSocial_(string nombre, vector <Usuario_*> usuario, vector <Publicacion_*>publicacion){
        this->nombre=nombre;
        this->usuarios=usuario;
        this->publicaciones=publicacion;
    }
};

#endif
