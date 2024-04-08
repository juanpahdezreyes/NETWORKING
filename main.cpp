#include "RedSocial.h"
#include "Usuario.h"
#include "Publicacion.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Publicacion::idCounter = 1;
int Usuario::idCounter = 1;

int main() {
    RedSocial_ redSocial("MiRedSocial");

    // Crear usuarios
    Usuario* usuario1 = new Usuario("Carslos", 25, "Mexicano");
    Usuario* usuario2 = new Usuario("Panchito", 30, "Africano");
    Usuario* usuario3 = new Usuario("Enrique", 20, "EstadoUnidese");//*

    // Agregar usuarios a la red social
    redSocial.agregarUsuario(usuario1);
    redSocial.agregarUsuario(usuario2);
    redSocial.agregarUsuario(usuario3);

    // Interacción con usuarios
    int opcion;
    int id;
    string fecha, contenido;
    string input;
    do {
        cout << "======= Menú Principal =======" << endl;
        cout << "1. Mostrar usuarios" << endl;
        cout << "2. Mostrar publicaciones" << endl;
        cout << "3. Agregar publicación" << endl;
        cout << "4. Quitar publicación" << endl;
        cout << "5. Entrar al perfil de usuario" << endl;
        cout << "6. Agregar un nuevo usuario" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> input;


        if (isdigit(input[0])) {    // isdigit se utiliza para determinar si un carácter es un dígito 
            opcion = stoi(input);  // stoi es para convertir una cadena que representa un número en formato de texto a su equivalente entero.

            switch (opcion) {
                case 1:
                    redSocial.mostrarUsuarios();
                    break;
                case 2:
                    redSocial.mostrarPublicaciones();
                    break;
                case 3:
                    cout << "Ingrese su ID de usuario: ";
                    cin >> id;
                    cout << "Ingrese la fecha de la publicación (YYYY-MM-DD): ";
                    cin >> fecha;
                    cout << "Ingrese el contenido de la publicación: ";
                    cin >> contenido;
                    redSocial.getUsuario(id)->agregarPublicacion(fecha, contenido);
                    break;
                case 4:
                    cout << "Ingrese el ID de la publicación que desea eliminar: ";
                    cin >> id;
                    for (Publicacion* publicacion : redSocial.getPublicaciones()) {
                        if (publicacion->getId() == id) {
                            for (Usuario* usuario : redSocial.getUsuarios()) {
                                usuario->quitarPublicacion(id);
                            }
                            break;
                        }
                    }
                    break;
                case 5:
                    cout << "Ingrese su ID de usuario: ";
                    cin >> id;
                    redSocial.entrarPerfilUsuario(id);
                    break;
                case 6:
                    cout << "Ingrese el nombre del nuevo usuario: ";
                    string nombre;
                    cin >> nombre;
                    cout << "Ingrese la edad del nuevo usuario: ";
                    int edad;
                    cin >> edad;
                    cout << "Ingrese la nacionalidad del nuevo usuario: ";
                    string nacionalidad;
                    cin >> nacionalidad;
                    Usuario* nuevoUsuario = new Usuario(nombre, edad, nacionalidad);
                    redSocial.agregarUsuario(nuevoUsuario);
                    break;
                case 7:
                    cout << "¡Hasta luego!" << endl;
                    break;
                default:
                    cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
                    break;
            }
        } else {
            cout << "Entrada inválida. Por favor, seleccione una opción válida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (opcion != 7);

    // Liberar memoriajj
    for (Usuario* usuario : redSocial.getUsuarios()) {
        delete usuario;
    }

    return 0;
}
