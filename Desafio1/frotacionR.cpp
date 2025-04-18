#include <Header.h>

using namespace std;

unsigned char * frotacionR(unsigned char *pixelData, int dataSize, int n)
{
    unsigned char *trRotacionR = new unsigned char [dataSize];

    cout << "Resultados funcion de Rotacion Derecha: "<<endl;
    for (int i = 0; i < dataSize; ++i)
    {
        trRotacionR[i]= (pixelData[i] << n) | (pixelData[i] >> (8-n));
    }
    cout << "Rotaciones Derecha: " << n <<endl;
    return trRotacionR;
}
