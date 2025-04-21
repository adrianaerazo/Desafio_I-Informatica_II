#include <Header.h>

using namespace std;

unsigned char* funcionXOR(unsigned char* pixelData, unsigned char* pixelImMascara, int dataSize, int n)
{
    unsigned char *trXOR = new unsigned char[dataSize];

    cout << "Operacion XOR" << endl;

    for (int i = 0; i < dataSize; ++i)
    {
        trXOR[i] = (pixelData)[i] ^ (pixelImMascara)[i];
    }
    return trXOR;
}
