#include <Header.h>

using namespace std;

unsigned char * funcionRL(unsigned char *pixelData, int dataSize, int n)
{
    unsigned char *trRotacionL = new unsigned char [dataSize];

    cout << "Resultados funcion de Rotacion izq: "<<endl;
    for (int i = 0; i < dataSize; ++i)
    {
        trRotacionL[i]= (pixelData[i] << n) | (pixelData[i] >> (8-n));
    }
    cout << "Rotaciones izq: " << n <<endl;
    return trRotacionL;
}
