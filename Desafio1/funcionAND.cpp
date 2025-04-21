#include <Header.h>

using namespace std;

unsigned char* funcionAND(unsigned char* pixelData, unsigned char* pixelImMascara, int dataSize, int n)
{
    unsigned char *trAND = new unsigned char[dataSize];

    cout << "Operacion AND" << endl;

    for (int i = 0; i < dataSize; ++i)
    {
        trAND[i] = (pixelData)[i] & (pixelImMascara)[i];
    }
    return trAND;
}
