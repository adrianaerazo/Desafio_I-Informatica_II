#include <iostream>
#include <Header.h>

void validation(int &Ntr, int &c){
    while (true) {
        cout << "Ingrese la cantidad de transformaciones realizadas a la imagen original (Io):" << endl;
        cin >> c;

        if (cin.fail() || c <= 0) {
            cout << "Error: Ingrese un numero entero positivo mayor que 0" << endl;

            // Limpiar error y descartar entrada incorrecta
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            Ntr = c - 1;
            break;
        }
    }
}
