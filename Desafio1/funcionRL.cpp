#include <Header.h>

using namespace std;

unsigned char * funcionRL(unsigned char *pixelData, unsigned char* pixelImMascara, int dataSize, int n)
{
    unsigned char *trRotacionL = new unsigned char [dataSize];

    cout << "Operacion RL" << endl;

    for (int i = 0; i < dataSize; ++i)
    {
        trRotacionL[i]= (pixelData[i] << n) | (pixelData[i] >> (8-n));
    }
    return trRotacionL;
}
