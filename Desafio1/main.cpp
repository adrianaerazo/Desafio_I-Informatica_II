#include <iostream>
#include <Header.h>

/*
 * Programa demostrativo de manipulaciónprocesamiento de imágenes BMP en C++ usando Qt.
 *
 * Descripción:
 * Este programa realiza las siguientes tareas:
 * 1. Carga una imagen BMP desde un archivo (formato RGB sin usar estructuras ni STL).
 * 2. Modifica los valores RGB de los píxeles asignando un degradado artificial basado en su posición.
 * 3. Exporta la imagen modificada a un nuevo archivo BMP.
 * 4. Carga un archivo de texto que contiene una semilla (offset) y los resultados del enmascaramiento
 *    aplicados a una versión transformada de la imagen, en forma de tripletas RGB.
 * 5. Muestra en consola los valores cargados desde el archivo de enmascaramiento.
 * 6. Gestiona la memoria dinámicamente, liberando los recursos utilizados.
 *
 * Entradas:
 * - Archivo de imagen BMP de entrada ("I_O.bmp").
 * - Archivo de salida para guardar la imagen modificada ("I_D.bmp").
 * - Archivo de texto ("M1.txt") que contiene:
 *     • Una línea con la semilla inicial (offset).
 *     • Varias líneas con tripletas RGB resultantes del enmascaramiento.
 *
 * Salidas:
 * - Imagen BMP modificada ("I_D.bmp").
 * - Datos RGB leídos desde el archivo de enmascaramiento impresos por consola.
 *
 * Requiere:
 * - Librerías Qt para manejo de imágenes (QImage, QString).
 * - No utiliza estructuras ni STL. Solo arreglos dinámicos y memoria básica de C++.
 *
 * Autores: Augusto Salazar Y Aníbal Guerra
 * Fecha: 06/04/2025
 * Asistencia de ChatGPT para mejorar la forma y presentación del código fuente
 */

//se define antes de usar porque en C++ el compilador necesita conocer todos los tipos antes de compilar las funciones
typedef unsigned char* (*Function)(unsigned char*, unsigned char*, size_t, uint8_t); //Cambiar a arreglo dinamico

int main(){

    int c = 0, N = 0;
    validation(N, c);

    // Variables para almacenar las dimensiones de la imagen
    int height = 0, width = 0, originalHeight = 0, originalWidth = 0;

    // Definición de ruta de archivo de entrada (imagen distorsionada)
    QString archivoEntrada = "I_D.bmp";

    // Cargar imagen BMP en memoria dinámica y obtiene ancho y alto
    unsigned char *pixelData = loadPixels(archivoEntrada, originalWidth, originalHeight);

    //Tamaño del arreglo de datos RGB de la I_D.bmp
    size_t dataSize = originalWidth * originalHeight * 3;

    //Arreglo de puntero a funciones
    Function functions[] = {funcionXOR, funcionOR, funcionAND, funcionRL, funcionRR};

    //Imprimir en pantalla las transformaciones realizadas
    string* trAplicadas = new string[c];


    //Arreglo de nombres de funciones para imprimir en pantalla las transformaciones realizadas
    string nameTransformations[5] = {"XOR" , "OR" , "AND" , "RL" , "RR"};

    //Posible solucion mas eficiente
    for (int i = 0; i <= N; i++) {

        bool found = false;

        QString archivoImMascara = "I_M.bmp";
        unsigned char *pixelImMascara = loadPixels(archivoImMascara, originalWidth, originalHeight);

        QString Mascara = "M.bmp";
        unsigned char *pixelMascara = loadPixels(Mascara, width, height);

        QString textFile = "M" + QString::number(N - i) + ".txt";
        int seed = 0, n_pixels = 0;
        unsigned int *maskingData = loadSeedMasking(textFile.toStdString().c_str(), seed, n_pixels);

        // Probar XOR, OR, AND
        for (uint8_t j = 0; j < 3 && !found; j++) {

            unsigned char *transformation = functions[j](pixelData, pixelImMascara, dataSize, 0);

            if (verificationTransformation(maskingData, pixelMascara, transformation, seed, n_pixels)) {
                string mensaje = "Paso " + to_string(i + 1) + ": " + nameTransformations[j] + " es la transformacion correcta.";
                trAplicadas[i] = mensaje;
                delete[] pixelData;
                pixelData = transformation;
                found = true;
            } else {
                delete[] transformation;
            }
        }

        // Probar RL y RR solo si las anteriores fallaron
        for (uint8_t bits = 1; bits <= 8 && !found; bits++) {

            for (uint8_t j = 3; j <= 4 && !found; j++) {

                unsigned char *transformation = functions[j](pixelData, nullptr, dataSize, bits);

                if (verificationTransformation(maskingData, pixelMascara, transformation, seed, n_pixels)) {
                    string mensaje = "Paso " + to_string(i + 1) + ": " + nameTransformations[j] + " es la transformacion correcta con " + to_string(bits) + " bits.";
                    trAplicadas[i] = mensaje;
                    delete[] pixelData;
                    pixelData = transformation;
                    found = true;
                } else {
                    delete[] transformation;
                }
            }
        }

        // Liberar memoria cargada para cada paso i
        delete[] pixelImMascara;
        delete[] pixelMascara;
        delete[] maskingData;
    }


    QString archivoSalida = "I_O.bmp";
    exportImage(pixelData, originalWidth, originalHeight, archivoSalida);
    delete[] pixelData;

    // Al final mostramos todas las transformaciones aplicadas
    cout << "\nRESUMEN DE LAS TRANSFORMACIONES REALIZADAS:\n";
    for (int i = 0; i <= N; i++){
        cout << trAplicadas[i] << endl;
    }
    delete[] trAplicadas;

    return 0;
}











