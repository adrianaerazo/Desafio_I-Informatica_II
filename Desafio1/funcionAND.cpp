#include <Header.h>

using namespace std;

unsigned char* funcionAND(unsigned char* pixelData, unsigned char* pixelImMascara, int dataSize)
{
    unsigned char *trAND = new unsigned char[dataSize];

    cout << "Operacion AND: "<<endl;
    for (int i = 0; i < dataSize; ++i)
    {
        //cout << bitset<8> (pixelData[i]) << "     " << bitset<8> (pixelImMascara[i]) <<endl;
        trAND[i] = (pixelData)[i] & (pixelImMascara)[i];
        //cout << bitset<8> (trAND[i])<<endl;
    }
    return trAND;
}
