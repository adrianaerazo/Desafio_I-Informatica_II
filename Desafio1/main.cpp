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
    //Cantidad de transformaciones aplicada a Io
    uint8_t N = 6;
    /* cout << "Ingrese la cantidad de transformaciones realizadas a la imagen original (Io): " << endl;
    cin >> N ; */

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

    //Posible solucion mas eficiente
    for (uint8_t i = 0; i <= N; i++){

        bool found = false;

        QString archivoImMascara = "I_M.bmp";
        unsigned char *pixelImMascara = loadPixels(archivoImMascara, originalWidth, originalHeight);

        QString Mascara = "M.bmp";
        unsigned char *pixelMascara = loadPixels(Mascara, width, height);

        QString textFile = "M" + QString::number(N-i) + ".txt"; //Se lee el archivo M_(N-1).bmp;
        int seed = 0, n_pixels = 0;
        unsigned int *maskingData = loadSeedMasking(textFile.toStdString().c_str(), seed, n_pixels);

        //Probar XOR, OR, AND
        for (uint8_t j = 0; j < 3 && !found; j++){

            unsigned char *transformation = functions[j](pixelData, pixelImMascara, dataSize, 0);

            if (verificationTransformation(maskingData, pixelMascara, transformation, seed, n_pixels)){
                delete [] pixelData;
                pixelData = transformation;
                found = true;
            }
            else delete[] transformation;
        }

        //Probar RL y RR
        for (uint8_t j = 3; j <= 4 && !found; j++) {

            for (uint8_t n = 1; n <= 8; n++){

                unsigned char *transformation = functions[j](pixelData, nullptr, dataSize, n);

                if (verificationTransformation(maskingData, pixelMascara, transformation, seed, n_pixels)){
                    delete [] pixelData;
                    pixelData = transformation;
                    found = true;
                }
                else delete[] transformation;
            }
        }
        delete[] pixelImMascara;
        delete[] pixelMascara;
        delete[] maskingData;
    }


    QString archivoSalida = "I_O.bmp";
    exportImage(pixelData, originalWidth, originalHeight, archivoSalida);
    delete[] pixelData;
}


/*
    //Implementacion de posible solucion lineal
    for (int8_t i = 0; i <= N; i++)
    {
        bool encontrada = false;

        // Intentar primero XOR
        unsigned char* pixelImMascara = loadPixels("I_M.bmp", originalWidth, originalHeight);
        unsigned char* resultadoXOR = funcionXOR(pixelData, pixelImMascara, dataSize);
        unsigned char* resultadoOR = funcionOR(pixelData, pixelImMascara, dataSize);
        unsigned char* resultadoAND = funcionAND(pixelData, pixelImMascara, dataSize);

        QString archivoTxt = "M" + QString::number(N - i) + ".txt";
        int seed = 0, n_pixels = 0;
        unsigned int* maskingData = loadSeedMasking(archivoTxt.toStdString().c_str(), seed, n_pixels);
        unsigned char* pixelMascara = loadPixels("M.bmp", width, height);

        if (verificationTransformation(maskingData, pixelMascara, resultadoXOR, seed, n_pixels))
        {
            string mensaje = "Paso " + to_string(i + 1) + ": XOR es la transformacion correcta.";
            cout << mensaje << endl;
            trAplicadas[i] = mensaje;
            delete[] pixelData;
            pixelData = resultadoXOR;
            encontrada = true;
        }
        else
        {
            delete[] resultadoXOR;
        }

        if(verificationTransformation(maskingData, pixelMascara, resultadoOR, seed, n_pixels))
        {
            string mensaje = "Paso " + to_string(i + 1) + ": OR es la transformacion correcta.";
            cout << mensaje << endl;
            trAplicadas[i] = mensaje;
            delete[] pixelData;
            pixelData = resultadoOR;
            encontrada = true;
        }
        else
        {
            delete[] resultadoOR;
        }

        if(verificationTransformation(maskingData, pixelMascara, resultadoAND, seed, n_pixels))
        {
            string mensaje = "Paso " + to_string(i + 1) + ": AND es la transformacion correcta.";
            cout << mensaje << endl;
            trAplicadas[i] = mensaje;
            delete[] pixelData;
            pixelData = resultadoAND;
            encontrada = true;
        }
        else
        {
            delete[] resultadoAND;
        }

        delete[] pixelImMascara;
        delete[] pixelMascara;
        delete[] maskingData;

        // Si no fue ninguna de las anteriores, probar rotaciones DERECHA e IZQUIERDA
        for (int n = 1; n <= 8 && !encontrada; n++)
        {
            // Si tampoco fue rotacion derecha, probar rotaciones DERECHA
            unsigned char* resultadoRR = funcionRR(pixelData, dataSize, n);
            QString archivoTxt = "M" + QString::number(N - i) + ".txt";
            int seed = 0, n_pixels = 0;
            unsigned int* maskingData = loadSeedMasking(archivoTxt.toStdString().c_str(), seed, n_pixels);
            unsigned char* pixelMascara = loadPixels("M.bmp", width, height);

            if (verificationTransformation(maskingData, pixelMascara, resultadoRR, seed, n_pixels))
            {
                string mensaje = "Paso " + to_string(i + 1) + ": Rotacion DERECHA de " + to_string(n) + " bits es la transformacion correcta.";
                cout << mensaje << endl;
                trAplicadas[i] = mensaje;
                delete[] pixelData;
                pixelData = resultadoRR;
                encontrada = true;
            }
            else delete[] resultadoRR;


            // Si tampoco fue rotacion derecha, probar rotaciones IZQUIERDA
            unsigned char* resultadoRL = funcionRL(pixelData, dataSize, n);

            if (verificationTransformation(maskingData, pixelMascara, resultadoRL, seed, n_pixels))
            {
                string mensaje = "Paso " + to_string(i + 1) + ": Rotacion IZQUIERDA de " + to_string(n) + " bits es la transformacion correcta.";
                cout << mensaje << endl;
                trAplicadas[i] = mensaje;
                pixelData = resultadoRL;
                encontrada = true;
            }
            else delete[] resultadoRL;

            delete[] pixelMascara;
            delete[] maskingData;
        }

        if (!encontrada)
        {
            string mensaje = "No se encontro una transformacion valida para el paso " + to_string(i + 1);
            cout << mensaje << endl;
            trAplicadas[i] = mensaje;
            break;
        }
    }


    // Al final mostramos todas las transformaciones aplicadas
    cout << "\nRESUMEN DE LAS TRANSFORMACIONES REALIZADAS:\n";
    for (int8_t i = 0; i <= N; i++)
    {
        cout << trAplicadas[i] << endl;
    }

    return 0; // Fin del programa
}

*/











