#include <Header.h>

using namespace std;

unsigned char* funcionOR(unsigned char* pixelData, unsigned char* pixelImMascara, int dataSize, int n)
{
    unsigned char *trOR = new unsigned char[dataSize];

    cout << "Operacion OR" << endl;

    for (int i = 0; i < dataSize; ++i)
    {
        trOR[i] = pixelData[i] | pixelImMascara[i];
    }
    return trOR;
}
