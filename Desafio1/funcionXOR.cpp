#include <Header.h>

using namespace std;

unsigned char* funcionXOR(unsigned char* pixelData, unsigned char* pixelImMascara, int dataSize)
{
    unsigned char *trXOR = new unsigned char[dataSize];

    cout << "Resultados XOR: "<<endl;
    for (int i = 0; i < dataSize; ++i)
    {
        //cout << bitset<8> (pixelData[i]) << "     " << bitset<8> (pixelImMascara[i]) <<endl;
        trXOR[i] = (pixelData)[i] ^ (pixelImMascara)[i];
        //cout << bitset<8> (trXOR[i])<<endl;
    }
    return trXOR;
}
