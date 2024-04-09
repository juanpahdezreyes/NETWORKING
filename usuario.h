#ifndef usuario_h
#define usuario_h
#include "Publicacion.h"
#include "RedSocial.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;



class Usuario_ {
private:
    int id;
    static int idCounter;
public:
    string nombre;
   int edad;
   string nacionalidad;
   vector <Usuario_*> amigos;
   vector <Publicacion_*> publicaciones;


    int getId(){
      return id;
    }
    void mostrar(){
      cout<<nombre<<endl;
      cout<<edad<<endl;
      cout<<nacionalidad<<endl;
      cout<<id<<endl;
    }
  void mostrarAmigos(){
    cout << "Los amigos de " << nombre << " son:" << endl;

    for (int i = 0; i < amigos.size(); i++)
    {
        Usuario_* amigo = amigos[i];
        cout << "Nombre: " << amigo->nombre << endl;
        cout << "Edad: " << amigo->edad << endl;
        cout << "Nacionalidad: " << amigo->nacionalidad << endl;
    }
  }
    void mostrarPublicaciones(){
      for (int i=0;i<publicaciones.size();i++){
          for (int i = 0; i < publicaciones.size(); i++)
          {
              Publicacion_* publicacion = publicaciones[i];
              cout << "Fecha: " << publicacion->fecha << endl;
              cout << "Post: " << publicacion->contenido << endl;
              cout << "Usuario: " << publicacion->usuario->nombre << endl;
          }
      }
    }
    void agregarAmigo(Usuario_* nuevoAmigo){
      this->amigos.push_back(nuevoAmigo);
      nuevoAmigo->amigos.push_back(this);
    }
    void crearPublicacion(){
      string fecha,contenido;
      cout<<"escriba la fecha de la publicacion"<<endl;
      cin>>fecha;
      cout<<"escriba el contenidod e la publicacion"<<endl;
      cin>>contenido;
      cout<<endl;
      Publicacion_ (this,fecha,contenido);
      publicaciones.push_back(&new); //<-- mandar al profe
    }
    /*void agregarPublicacion(string fech,string cont){
    Publicacion_ (this,fech,conten);
    publicaciones.push_back(&new); //<-- mandar al profe
    }*/

    Usuario_* getAmigo(int id){
      bool encontrado=0;
      for (int i=0;i<amigos.size();i++){
          if (id==amigos[i]->getId()){
              return amigos[i];
              encontrado=1;
              i=amigos.size();
          }
      }
      if (encontrado==0){
      cout<<"No existe un amigo con ese id"<<endl;
      return nullptr;
      }
    }
    Usuario_(string nombre){
      this->nombre=nombre;
    }
    Usuario_(string nombre,int edad){
      this->nombre=nombre;
      this->edad=edad;
    }
    Usuario_(string nombre,int edad,string nacionalidad){
      this->nombre=nombre;
      this->edad=edad;
      this->nacionalidad=nacionalidad;
    }
};

#endif