#include <Header.h>

using namespace std;

unsigned char * funcionRR (unsigned char *pixelData, unsigned char* pixelImMascara, size_t dataSize, uint8_t n)
{/*
 * @brief Realiza una rotación de bits a la derecha sobre cada byte de una imagen distorsionada.
 *
 * Esta función aplica una rotación circular a la derecha (rotate right) sobre cada byte del arreglo
 * que representa una imagen distorsionada ('pixelData'). La rotación se realiza 'n' posiciones a la derecha,
 * de forma que los bits que salen por el extremo derecho se reinsertan por el extremo izquierdo.
 * La imagen máscara ('pixelImMascara') no se utiliza en esta operación.
 *
 * @param pixelData Puntero al arreglo de bytes que representa la imagen distorsionada.
 * @param pixelImMascara Puntero al arreglo de bytes que representa la imagen máscara (no se utiliza).
 * @param dataSize Cantidad total de bytes en el arreglo de la imagen.
 * @param n Cantidad de bits por los que se debe rotar cada byte hacia la derecha.
 *
 * @return Puntero a un nuevo arreglo dinámico de bytes que contiene los resultados de la rotación.
 *         Cada byte es el resultado de rotar el byte correspondiente de 'pixelData' 'n' posiciones a la derecha.
 */

    unsigned char *trRotacionR = new unsigned char [dataSize];

    for (size_t i = 0; i < dataSize; ++i)
    {
        trRotacionR[i]= (pixelData[i] >> n) | (pixelData[i] << (8-n));
    }
    return trRotacionR;
}
