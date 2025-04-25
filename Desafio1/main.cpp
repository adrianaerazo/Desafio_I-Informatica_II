#include <iostream>
#include <Header.h>

/*
 * @brief Programa para realizar transformaciones sobre una imagen distorsionada utilizando técnicas de enmascarado y transformaciones bit a bit.
 *
 * Este programa carga una imagen BMP distorsionada, realiza una serie de transformaciones en ella (XOR, RL, RR), y verifica si la transformación es correcta utilizando una máscara de referencia. Si una transformación es válida, se actualiza la imagen con el resultado. Las transformaciones realizadas se almacenan y se muestran al final del proceso.
 *
 * El proceso sigue los siguientes pasos:
 * 1. Cargar la imagen BMP distorsionada y sus dimensiones.
 * 2. Definir un conjunto de funciones de transformación.
 * 3. Iterar sobre un conjunto de pasos de transformación, donde se prueban las funciones XOR, RL, y RR, verificando si la transformación resulta válida con respecto a una máscara de referencia.
 * 4. En cada iteración, si una transformación es válida, se reemplaza la imagen con el resultado de la transformación correcta.
 * 5. Finalmente, se exporta la imagen transformada y se imprime un resumen de las transformaciones realizadas.
 *
 * @param N Número total de pasos de transformación.
 * @param c Número de transformaciones aplicadas.
 * @param archivoEntrada Ruta del archivo BMP de entrada (imagen distorsionada).
 * @param archivoImMascara Ruta del archivo BMP de la máscara de imagen.
 * @param Mascara Ruta del archivo BMP de la máscara a usar en cada paso de transformación.
 * @param textFile Ruta del archivo de texto con los datos de enmascarado (usado para verificar la transformación).
 * @param archivoSalida Ruta del archivo BMP de salida para exportar la imagen transformada.
 *
 * @return int Código de salida del programa.
 *
 * Detalles de las funciones:
 * - La función 'loadPixels' se encarga de cargar los datos de píxeles de la imagen desde el archivo BMP.
 * - Las funciones 'funcionXOR', 'funcionRL' y 'funcionRR' son las funciones de transformación que se aplican a la imagen.
 * - La función 'verificationTransformation' verifica si la transformación aplicada es correcta usando la máscara de referencia.
 * - La función 'exportImage' exporta la imagen transformada a un archivo BMP.
 *
 * Notas:
 * - Se usa memoria dinámica para almacenar y manipular los datos de los píxeles de las imágenes.
 * - Se utiliza una estructura de punteros a funciones para realizar las transformaciones de manera modular.
 */

//se define antes de usar porque en C++ el compilador necesita conocer todos los tipos antes de compilar las funciones
typedef unsigned char* (*Function)(unsigned char*, unsigned char*, size_t, uint8_t); //Cambiar a arreglo dinamico

int main(){

    int c = 0, N = 0;
    c = countTxt();
    N = c-1;

    //Imprimir mensaje en pantalla de la cantidad de transformaciones
    cout << "Para este caso se realizaron " << c << " transformaciones.\n" << endl;

    // Variables para almacenar las dimensiones de la imagen
    int height = 0, width = 0, originalHeight = 0, originalWidth = 0;

    // Definición de ruta de archivo de entrada (imagen distorsionada)
    QString archivoEntrada = "I_D.bmp";

    // Cargar imagen BMP en memoria dinámica y obtiene ancho y alto
    unsigned char *pixelData = loadPixels(archivoEntrada, originalWidth, originalHeight);

    //Tamaño del arreglo de datos RGB de la I_D.bmp
    size_t dataSize = originalWidth * originalHeight * 3;

    //Arreglo de puntero a funciones
    Function functions[] = {funcionXOR, funcionRL, funcionRR};

    //Imprimir en pantalla las transformaciones realizadas
    string* trAplicadas = new string[c];


    //Arreglo de nombres de funciones para imprimir en pantalla las transformaciones realizadas
    string nameTransformations[5] = {"XOR" , "RL" , "RR"};

    //Posible solucion mas eficiente
    for (int i = 0; i <= N; i++) {

        bool found = false;

        QString archivoImMascara = "I_M.bmp";
        unsigned char *pixelImMascara = loadPixels(archivoImMascara, originalWidth, originalHeight);

        QString Mascara = "M.bmp";
        unsigned char *pixelMascara = loadPixels(Mascara, width, height);

        QString textFile = "M" + QString::number(N - i) + ".txt";
        int seed = 0, n_pixels = 0;
        uint16_t *maskingData = loadSeedMasking(textFile.toStdString().c_str(), seed, n_pixels);

        // Probar XOR
        unsigned char *transformation = functions[0](pixelData, pixelImMascara, dataSize, 0);

        if (verificationTransformation(maskingData, pixelMascara, transformation, seed, n_pixels)) {
            string mensaje = "Paso " + to_string(i + 1) + ": " + nameTransformations[0] + " es la transformacion correcta.";
            trAplicadas[i] = mensaje;
            delete[] pixelData;
            pixelData = transformation;
            found = true;
        } else {
            delete[] transformation;
        }

        // Probar RL y RR solo si las anteriores fallaron
        for (uint8_t bits = 1; bits <= 8 && !found; bits++) {

            for (uint8_t j = 1; j <= 2 && !found; j++) {

                unsigned char *transformation = functions[j](pixelData, nullptr, dataSize, bits);

                if (verificationTransformation(maskingData, pixelMascara, transformation, seed, n_pixels)) {
                    string mensaje = "Paso " + to_string(i + 1) + ": " + nameTransformations[j] + " es la transformacion correcta con " + to_string(bits) + " bits.";
                    trAplicadas[i] = mensaje;
                    delete[] pixelData;
                    pixelData = transformation;
                    found = true;
                } else {
                    delete[] transformation;
                    transformation = nullptr;
                }
            }
        }

        // Liberar memoria cargada para cada paso i
        delete[] pixelImMascara;
        pixelImMascara = nullptr;
        delete[] pixelMascara;
        pixelMascara = nullptr;
        delete[] maskingData;
        maskingData = nullptr;
    }


    QString archivoSalida = "I_O.bmp";
    exportImage(pixelData, originalWidth, originalHeight, archivoSalida);
    delete[] pixelData;
    pixelData = nullptr;

    // Al final mostramos todas las transformaciones aplicadas
    cout << "\nRESUMEN DE LAS TRANSFORMACIONES REALIZADAS:\n";
    for (int i = 0; i <= N; i++){
        cout << trAplicadas[i] << endl;
    }
    delete[] trAplicadas;
    trAplicadas = nullptr;

    return 0;
}











