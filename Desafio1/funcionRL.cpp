#include <iostream>
#include <Header.h>

using namespace std;

unsigned char * funcionRL(unsigned char *pixelData, unsigned char* pixelImMascara, size_t dataSize, uint8_t n)
{/*
 * @brief Realiza una rotación de bits a la izquierda sobre cada byte de una imagen distorsionada.
 *
 * Esta función aplica una rotación circular a la izquierda (rotate left) sobre cada byte del arreglo
 * que representa una imagen distorsionada ('pixelData'). La rotación se realiza 'n' posiciones a la izquierda,
 * de forma que los bits que salen por el extremo izquierdo se reinsertan por el extremo derecho.
 * La imagen máscara ('pixelImMascara') no se utiliza en esta operación.
 *
 * @param pixelData Puntero al arreglo de bytes que representa la imagen distorsionada.
 * @param pixelImMascara Puntero al arreglo de bytes que representa la imagen máscara (no se utiliza).
 * @param dataSize Cantidad total de bytes en el arreglo de la imagen.
 * @param n Cantidad de bits por los que se debe rotar cada byte hacia la izquierda.
 *
 * @return Puntero a un nuevo arreglo dinámico de bytes que contiene los resultados de la rotación.
 *         Cada byte es el resultado de rotar el byte correspondiente de 'pixelData' 'n' posiciones a la izquierda.
 */

    unsigned char *trRotacionL = new unsigned char [dataSize];

    for (size_t i = 0; i < dataSize; ++i)
    {
        trRotacionL[i]= (pixelData[i] << n) | (pixelData[i] >> (8-n));
    }
    return trRotacionL;
}
