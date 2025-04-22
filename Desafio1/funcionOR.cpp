#include <iostream>
#include <Header.h>

using namespace std;

unsigned char* funcionOR(unsigned char* pixelData, unsigned char* pixelImMascara, size_t dataSize, uint8_t n)
{/*
 * @brief Aplica una operación OR bit a bit entre una imagen distorsionada y una imagen máscara.
 *
 * Esta función realiza una operación lógica OR bit a bit entre cada byte de dos arreglos:
 * uno que representa una imagen distorsionada ('pixelData') y otro que contiene la imagen máscara
 * ('pixelImMascara'). El resultado es una nueva imagen en la que se combinan los valores de ambos arreglos,
 * destacando cualquier información presente en cualquiera de las dos imágenes.
 *
 * @param pixelData Puntero al arreglo de bytes que representa la imagen distorsionada.
 * @param pixelImMascara Puntero al arreglo de bytes que representa la imagen máscara.
 * @param dataSize Cantidad total de bytes en los arreglos de imagen (tamaño de la imagen en bytes).
 * @param n Parámetro actualmente no utilizado.
 *
 * @return Puntero a un nuevo arreglo dinámico de bytes que contiene el resultado de la operación OR.
 *         Cada byte del arreglo resultante es el resultado de aplicar el operador | entre los bytes
 *         correspondientes de 'pixelData' y 'pixelImMascara'.
 */

    unsigned char *trOR = new unsigned char[dataSize];

    for (size_t i = 0; i < dataSize; ++i)
    {
        trOR[i] = pixelData[i] | pixelImMascara[i];
    }
    return trOR;
}
