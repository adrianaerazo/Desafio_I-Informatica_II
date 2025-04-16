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

int main()
{
    //Para conocer el directorio:
    //QDir dir;
    //cout << "Directorio actual: " << dir.absolutePath().toStdString() << endl;

    //Cantidad de transformaciones aplicada a Io
    int8_t N = 7;
    /*cout << "Ingrese la cantidad de transformaciones realizadas a la imagen original (Io): " << endl;
    cin >> N ; */

    // Variables para almacenar las dimensiones de la imagen
    int height = 0;
    int width = 0;

    // Definición de ruta de archivo de entrada (imagen distorsionada)
    QString archivoEntrada = "I_D.bmp"; //(Imagen distorsionada final)

    // Cargar imagen BMP en memoria dinámica y obtiene ancho y alto
    unsigned char *pixelData = loadPixels(archivoEntrada, width, height);

    typedef unsigned char* (*Function3Param)(unsigned char*, unsigned char*, int); //Cambiar a arreglo dinamico

    for (int8_t i = 0; i < N; i++){

        QString archivoImMascara = "I_M.bmp";
        unsigned char *pixelImMascara = loadPixels(archivoImMascara, width, height);

        int8_t different = 0;

        //Arreglo de puntero a funciones
        Function3Param functions[] = {funcionXOR, funcionOR, funcionAND};

        for (size_t j = 0; j < sizeof(functions)/sizeof(functions[0]); j++){

            unsigned char *transformation = functions[j](pixelData, pixelImMascara, width*height*3);

            int dSizeTransf = width * height * 3;

            delete[] pixelData;
            delete[] pixelImMascara;

            QString Mascara = "M.bmp";
            unsigned char *pixelMascara = loadPixels(Mascara, width, height);
            int dSizeM = width * height * 3;

            int seed = 0, n_pixels = 0;
            QString textFile = "M" + QString::number(N-i) + ".txt"; //Se lee el archivo M_(N-1).bmp;
            unsigned int *maskingData = loadSeedMasking(textFile.toStdString().c_str(), seed, n_pixels);


            //Revisar los siguientes ciclos for
            for (int k = 0; k < dSizeTransf; k++){

                for (int r = 0; r < dSizeM; r++){

                    int16_t sumaT = int(transformation [r + seed]) + int (pixelMascara[r]);
                    //cout << sumaT << endl;

                }
            }
        }




    }


    QString archivoSalida = "I_PN.bmp";


/*
 // Cargar imagenes BMP en memoria dinámica y obtiene ancho y alto
    unsigned char *pixelData = loadPixels(archivoEntrada, width, height);

    //unsigned char *pixelMascara = loadPixels(archivoMascara, width, height);

    unsigned char *trXOR =  funcionXOR(pixelData, pixelImMascara, (width*height*3));
    //Verificar si las sumas son iguales

    unsigned char *trOR =  funcionOR(pixelData, pixelImMascara, (width*height*3));
    //Verificar sumas

    unsigned char *trAND =  funcionAND(pixelData, pixelImMascara, (width*height*3));


    cout << "Contenido del arreglo de pixeles: " << endl;
    cout << "Imagen de " << width << " de ancho y " << height << " de alto." << endl;


    //cout << "Con una cantidad de  " << dataSize << " bytes."<< endl;

    for (int i=0; i < 40; i++){
        cout << int(pixelData[i]) << endl; //permite ver pixeles en tipo entero
        // cout << (pixelData[i]) << endl; //permite ver pixeles en tipo char (ASCII)
        //cout << bitset<8> (pixelData[i]) << endl; //permite ver pixeles en tipo binario
    }


    // Exporta la imagen modificada a un nuevo archivo BMP
    //bool exportI = exportImage(pixelData, width, height, archivoSalida);

    // Muestra si la exportación fue exitosa (true o false)
    //cout << exportI << endl;

    // Libera la memoria usada para los píxeles
    delete[] pixelData;
    pixelData = nullptr;

    // Variables para almacenar la semilla y el número de píxeles leídos del archivo de enmascaramiento
    int seed = 0;
    int n_pixels = 0;

    // Carga los datos de enmascaramiento desde un archivo .txt (semilla + valores RGB)
    //unsigned int *maskingData = loadSeedMasking("M1.txt", seed, n_pixels);

    // Muestra en consola los primeros valores RGB leídos desde el archivo de enmascaramiento
    for (int i = 0; i < n_pixels * 3; i += 3) {
        cout << "Pixel " << i / 3 << ": ("
             << maskingData[i] << ", "
             << maskingData[i + 1] << ", "
             << maskingData[i + 2] << ")" << endl;
    }

    // Libera la memoria usada para los datos de enmascaramiento
    if (maskingData != nullptr){
        delete[] maskingData;
        maskingData = nullptr;
    }
*/

    return 0; // Fin del programa
}















