#include "RedSocial.h"
#include "Usuario.h"
#include "Publicacion.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Publicacion::idCounter = 1; // idCounter variable estatica de la clase Publicacion.
// :: se utilizan para decir qie IdCounter es una variable estatica de la clase Publicacion.
// cuando se crea un objeto de la clase Usuario se asigna el valor actual de idCounter a ese usuario y despues aumenta +1 el counter
int Usuario::idCounter = 1;

int main() {
    RedSocial_ redSocial("Networking");

     // Crear usuarios
    // Crear un nuevo objeto de la clase Usuario y asignarle memoria en el heap.
   // Es como pedir prestada una cajita especial al sistema operativo en lugar de guardarla
  // directamente en la memoria interna del programa.
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
        cout << "1 Mostrar usuarios" << endl;
        cout << "2. Mostrar publicaciones" << endl;
        cout << "3. Agregar publicación" << endl;
        cout << "4. Quitar publicación" << endl;
        cout << "5. Entrar al perfil de usuario" << endl;
        cout << "6. Agregar un nuevo usuario" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> input;


        if (isdigit(input[0])) {    // Esta línea verifica si el primer carácter de la entrada (input) es un dígito utilizando la función
                                   // isdigit(). Si es un dígito, se ejecuta el bloque de código dentro del if.

            opcion = stoi(input);  // Convierte la cadena de entrada (input) en un número entero utilizando la función stoi()
            // y lo asigna a la variable opcion.
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
                    //redSocial.getUsuario(id)->agregarPublicacion(fecha, contenido);
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
                    amigo_check:
                    cout << "Ingrese el ID de usuario: ";
                    cin >> id;

                    if (redSocial.entrarPerfilUsuario(id)==1){
                        goto amigo_check;
                    }
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
