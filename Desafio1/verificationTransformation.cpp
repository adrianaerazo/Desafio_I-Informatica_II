#include <Header.h>

using namespace std;

bool verificationTransformation(unsigned int* dataRGB , unsigned char* mascara, unsigned char* transformation, int &seed, int &n_pixels)
{/*
 * @brief Verifica si la transformación aplicada sobre una imagen distorsionada es correcta mediante un enmascaramiento.
 *
 * Esta función valida si la transformación aplicada a una imagen distorsionada es correcta. Lo hace al aplicar
 * un enmascaramiento a los datos de la imagen transformada, utilizando la máscara ('mascara'), y comparando los
 * resultados con los valores esperados almacenados en el arreglo 'dataRGB'. Si todos los valores coinciden, la
 * transformación es válida.
 *
 * @param dataRGB Puntero al arreglo de enteros que contiene los valores RGB resultantes del enmascaramiento
 *                aplicado sobre la imagen distorsionada después de cada transformación.
 * @param mascara Puntero al arreglo de bytes que representa la máscara aplicada durante la distorsión original.
 * @param transformation Puntero al arreglo de bytes que contiene los datos de la transformación realizada sobre la imagen distorsionada.
 * @param seed Variable de referencia que se utiliza como índice de inicio para acceder a la transformación en el arreglo 'transformation'.
 * @param n_pixels Variable de referencia que contiene la cantidad de píxeles a verificar (en términos de tripletes RGB).
 *
 * @return Retorna 'true' si la transformación es válida, es decir, si la imagen enmascarada coincide con los datos de la imagen distorsionada
 *         después de la transformación. Retorna 'false' si la transformación no es válida y se detecta una discrepancia.
 */

    uint16_t resultado = 0;

    for (int k = 0; k < n_pixels*3; k++)
    {
        resultado = uint16_t(mascara[k]+transformation[seed + k]);
        if(resultado != dataRGB[k])
        {
            return false;
        }
    }
    return true;
}
