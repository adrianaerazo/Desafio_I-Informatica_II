#include <Header.h>

using namespace std;

unsigned char * funcionRR (unsigned char *pixelData, unsigned char* pixelImMascara, int dataSize, int n)
{
    unsigned char *trRotacionR = new unsigned char [dataSize];

    cout << "Operacion RR" << endl;

    for (int i = 0; i < dataSize; ++i)
    {
        trRotacionR[i]= (pixelData[i] >> n) | (pixelData[i] << (8-n));
    }
    return trRotacionR;
}
