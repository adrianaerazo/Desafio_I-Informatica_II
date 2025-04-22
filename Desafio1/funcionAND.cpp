#include <iostream>
#include <Header.h>

using namespace std;

unsigned char* funcionAND(unsigned char* pixelData, unsigned char* pixelImMascara, size_t dataSize, uint8_t n)
{/*
 * @brief Aplica una operación AND bit a bit entre una imagen distorsionada y una imagen máscara.
 *
 * Esta función realiza una operación lógica AND bit a bit entre cada byte de dos arreglos:
 * uno que representa una imagen distorsionada ('pixelData') y otro que contiene la imagen máscara
 * ('pixelImMascara'). El resultado es una nueva imagen en la que se conserva solo la información
 * permitida por la máscara.
 *
 * @param pixelData Puntero al arreglo de bytes que representa la imagen distorsionada.
 * @param pixelImMascara Puntero al arreglo de bytes que representa la imagen máscara.
 * @param dataSize Cantidad total de bytes en los arreglos de imagen (tamaño de la imagen en bytes).
 * @param n Parámetro actualmente no utilizado.
 *
 * @return Puntero a un nuevo arreglo dinámico de bytes que contiene el resultado de la operación AND.
 *         Cada byte del arreglo resultante es el resultado de aplicar el operador & entre los bytes
 *         correspondientes de 'pixelData' y 'pixelImMascara'.
 */

    unsigned char *trAND = new unsigned char[dataSize];

    for (size_t i = 0; i < dataSize; ++i)
    {
        trAND[i] = (pixelData)[i] & (pixelImMascara)[i];
    }
    return trAND;
}
