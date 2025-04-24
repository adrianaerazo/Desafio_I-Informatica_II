#include <Header.h>

using namespace std;

unsigned char* funcionXOR(unsigned char* pixelData, unsigned char* pixelImMascara, size_t dataSize, uint8_t n)
{/*
 * @brief Realiza una operación XOR bit a bit entre cada byte de una imagen distorsionada y una imagen máscara.
 *
 * Esta función aplica una operación lógica XOR (exclusive OR) bit a bit entre los bytes de dos arreglos:
 * uno que representa una imagen distorsionada ('pixelData') y otro que contiene la imagen máscara
 * ('pixelImMascara').El resultado es una nueva imagen en la que se combinan los valores de ambos arreglos,
 * destacando las diferencias entre ellos, ya que un bit resultante es 1 solo si los bits correspondientes
 * en los dos arreglos son diferentes.
 *
 * @param pixelData Puntero al arreglo de bytes que representa la imagen distorsionada.
 * @param pixelImMascara Puntero al arreglo de bytes que representa la imagen máscara.
 * @param dataSize Cantidad total de bytes en los arreglos de imagen (tamaño de la imagen en bytes).
 * @param n Parámetro actualmente no utilizado.
 *
 * @return Puntero a un nuevo arreglo dinámico de bytes que contiene el resultado de la operación XOR.
 *         Cada byte del arreglo resultante es el resultado de aplicar el operador ^ entre los bytes
 *         correspondientes de 'pixelData' y 'pixelImMascara'.
 */

    unsigned char *trXOR = new unsigned char[dataSize];

    for (size_t i = 0; i < dataSize; ++i)
    {
        trXOR[i] = (pixelData)[i] ^ (pixelImMascara)[i];
    }
    return trXOR;
}
